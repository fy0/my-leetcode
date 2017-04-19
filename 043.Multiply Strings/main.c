
#include <math.h>
#include <stdint.h>

#define max(a,b) (((a)>(b)) ? (a):(b))
#define min(a,b) (((a)<(b)) ? (a):(b))
#define lex_isnumber(c) (c >= '0' && c <= '9')

typedef uint32_t dig_t;
typedef uint64_t ddig_t;

typedef struct {
	char neg;
	uint32_t *vals;
	int len;
	int allocated;
} BigInt;

BigInt* bigint_new_zero(int len) {
	BigInt *ret = (BigInt*)malloc(sizeof(BigInt));
	ret->neg = 0;
	ret->vals = (dig_t*)malloc(len * sizeof(dig_t));
	ret->allocated = len;
	ret->len = 1;
	*ret->vals = 0;
	return ret;
}

void bigint_free(BigInt *bi) {
	free(bi->vals);
	free(bi);
}

BigInt* bigint_dup_with_len(BigInt *bi, int len) {
	BigInt *ret = (BigInt*)malloc(sizeof(BigInt));
	ret->neg = bi->neg;
	ret->vals = (dig_t*)malloc(len * sizeof(dig_t));
	ret->allocated = len;
	ret->len = bi->len;
	memcpy(ret->vals, bi->vals, sizeof(dig_t) * bi->len);
	return ret;
}

BigInt* bigint_dup(BigInt *bi) {
	return bigint_dup_with_len(bi, bi->len);
}

/** 获取第N个数字，如果 */
dig_t bigint_getdigit(BigInt *bi, int n) {
	if (n >= bi->len) return 0;
	return bi->vals[n];
}

BigInt* bigint_add(BigInt *a, BigInt *b) {
	int minlen = min(a->len, b->len);
	int maxlen = max(a->len, b->len);
	BigInt *ret = bigint_new_zero(maxlen + 1);
	uint64_t num = 0;

	for (int i = 0; i < maxlen; ++i) {
		num += (ddig_t)bigint_getdigit(a, i) + (ddig_t)bigint_getdigit(b, i);
		ret->vals[i] = (dig_t)num;
		num >>= 32;
	}

	if (num) {
		ret->vals[maxlen] = (dig_t)num;
		ret->len = maxlen + 1;
	} else {
		ret->len = maxlen;
	}

	return ret;
}

int len_calc(int base, int len) {
	int n = 1;
	while ((1 << n) < base) n++;
	return (int)ceil(n * len / 8);
}

ddig_t bigint_internal_divmod(BigInt *bi, dig_t dividend) {
	ddig_t reminder = 0;
	for (int i = bi->len - 1; i >= 0; --i) {
		ddig_t divisor = (reminder << 32) | bi->vals[i];
		reminder = divisor % dividend;
		bi->vals[i] = (dig_t)(divisor / dividend);
	}

	for (int i = bi->len - 1; i > 0; --i) {
		if (bi->vals[i]) break;
		else bi->len--;
	}

	return reminder;
}

void bigint_print(BigInt *bi) {
	uint8_t out[300];
	int num = 0;
	bi = bigint_dup(bi);
	if (bi->neg) putchar('-');

	while ((bi->len > 1) || ((bi->len == 1) && (bi->vals[0] != 0))) {
		out[num++] = (uint8_t)bigint_internal_divmod(bi, 10);
	}

	for (int i = num - 1; i >= 0; i--) {
		printf("%d", out[i]);
	}
	putchar('\n');
	bigint_free(bi);
}

void bigint_internal_mul(BigInt *bi, dig_t dmul, dig_t dadd) {
	dig_t carry = dadd;

	for (int i = 0; i < bi->len; ++i) {
		ddig_t ret = bi->vals[i] * (ddig_t)dmul;
		ret += carry;
		bi->vals[i] = (dig_t)ret;
		carry = ret >> 32;
	}

	if (carry) {
		bi->vals[bi->len++] = carry;
	}
}

BigInt* bigint_mul(BigInt *a, BigInt *b) {
	// 确保 a 的长度大于 b 的长度
	if (a->len < b->len) {
		BigInt *tmp = b;
		b = a;
		a = tmp;
	}

	BigInt *ret = bigint_new_zero(a->len * 2);
	uint64_t num = 0;

	for (int i = 0; i < b->len; ++i) {
		BigInt *bi = bigint_dup_with_len(a, a->len + 1 + i);
		bigint_internal_mul(bi, b->vals[i], 0);
		if (i > 0) {
			memmove(bi->vals + i, bi->vals, bi->len * sizeof(dig_t));
			memset(bi->vals, 0, i * sizeof(dig_t));
			bi->len += i;
		}
		ret = bigint_add(ret, bi);
	}

	ret->neg = a->neg | b->neg;
	return ret;
}

BigInt* bigint_new_from_str(char *s, int len, int base) {
	char *p = s;
	char *end = s + len;
	int negative = 0;

	if (*p == '-') {
		negative = 1;
		p++;
	} else if (*p == '+') p++;

	char *start = p;
	for (; p != end; p++) {
		if (!lex_isnumber(*p)) {
			goto _invalid;
		}
	}

	int input_num = end - start;
	int dig_num = (int)ceil(len_calc(base, input_num) / (float)sizeof(dig_t));

	BigInt *ret = (BigInt*)malloc(sizeof(BigInt));
	ret->neg = negative;
	ret->vals = (dig_t*)malloc(dig_num * sizeof(dig_t));
	ret->allocated = dig_num;
	ret->len = 1;
	*ret->vals = 0;

	for (p = start; p < end; ++p) {
		bigint_internal_mul(ret, 10, *p - '0');
	}

	return ret;
_invalid:
	return NULL;
}

