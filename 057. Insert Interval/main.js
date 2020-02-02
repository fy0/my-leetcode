/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    let left = 0;
    let right = 0;

    for (let i = 0; i < intervals.length; i++) {
        let item = intervals[i];
        if (newInterval[0] >= item[0]) {
            // 如果在线段右侧，落点为当前索引+1，否则为当前索引
            if (newInterval[0] > item[1]) {
                left = i+1;
                right = left;
            } else {
                left = i;
                right = left + 1;
            }
        }
    }

    for (let i = right; i < intervals.length; i++) {
        let item = intervals[i];
        if (newInterval[1] >= item[0]) {
            right = i + 1;
        }
    }

    if (left != right) {
        newInterval[0] = Math.min(newInterval[0], intervals[left][0]);
        newInterval[1] = Math.max(newInterval[1], intervals[right-1][1]);
    }
    intervals.splice(left, right - left, newInterval);
    return intervals;
};
