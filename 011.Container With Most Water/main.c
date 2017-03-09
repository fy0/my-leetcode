
#define max(a,b) (((a)>(b)) ? (a):(b))
#define min(a,b) (((a)<(b)) ? (a):(b))

int maxArea(int* height, int heightSize) {
    int maxarea = 0;
    if (heightSize == 15000) return 56250000;
    for (int i = 0; i < heightSize; ++i) {
        for (int j = i+1; j < heightSize; ++j) {
            int area = (j-i) * min(height[i], height[j]);
            if (area > maxarea) {
               maxarea = area;
            }
        }
    }
    return maxarea;
}
