
// Accepted
// 179 ms
// 33.98%
// ����

/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    return new RegExp(`^${p}$`).test(s);
};
