
// 315 / 315 test cases passed.
// Status: Accepted
// Runtime: 9 ms
// 21.15% 
// 图很形象 不是太难


#define max(a,b) (((a)>(b)) ? (a):(b))
#define min(a,b) (((a)<(b)) ? (a):(b))

int trap(int* height, int heightSize) {
    if (heightSize < 3) return 0;
    
    int sum = 0;
    
    int a = 0;
    int b = heightSize - 1;
    
    while (!height[a]) a++;
    while (!height[b]) b--;

    int na = height[a];
    int nb = height[b];
    int fixheight = min(na, nb);
    
    a++;
    b--;

    while (a <= b) {
        if (na > nb) {
            int val = height[b];
            if (val < fixheight) sum += fixheight - val;
            else {
                nb = val;
                fixheight = min(na, nb);
            }
            b--;
        } else {
            int val = height[a];
            if (val < fixheight) sum += fixheight - val;
            else {
                na = val;
                fixheight = min(na, nb);
            }
            a++;
        }
    }
    
    return sum;
}

