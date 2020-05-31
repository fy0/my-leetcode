/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    let checkCross = (a, b, c, d) => {
        if (((a >= c && a <= d) || (b >= c && b <= d)) ||
        ((c >= a && c <= b) || (d >= a && d <= b))) {
            return true;
        }
        return false;
    }

    for (let i = 0; i < intervals.length; i++) {
        let [a, b] = intervals[i];
        for (let j = i+1; j < intervals.length; j++) {
            // console.log(i, j, intervals);
            let [c, d] = intervals[j];
            if (checkCross(a, b, c, d)) {
                a = Math.min(a, c);
                b = Math.max(b, d);
                intervals[i] = [a, b];
                intervals.splice(j, 1);
                // j--;
                j = i; // 下一个循环开始会自动+1
            }
        }
    }

    return intervals;
};


console.log(merge([[254,259],[449,456],[64,64],[262,268],[37,37],[357,361],[170,176],[328,334],[419,427],[106,114],[250,251],[170,171],[149,157],[385,386],[305,311],[448,449],[303,310],[210,218],[370,373],[424,431],[25,28],[203,208],[159,161],[153,161],[120,129],[287,289],[123,132],[313,315],[137,145],[56,61],[246,250],[206,208],[253,262],[270,273],[94,100],[382,391],[179,185],[166,175],[470,479],[269,269],[430,438],[312,317],[217,223],[30,37],[176,182],[2,7],[442,442],[177,182],[329,336],[171,174],[345,348],[394,398],[139,141],[215,224],[83,90],[51,55],[245,251],[271,274],[194,195],[22,22],[239,243],[145,146],[436,440],[229,237],[473,473],[41,49],[453,461],[195,200],[200,200],[406,410],[247,247],[150,155],[26,27],[160,160],[75,77],[442,446],[58,58],[496,500],[114,121],[112,120],[477,483],[406,406],[146,149],[227,233],[364,368],[482,485],[296,300],[308,310],[258,266],[394,397],[150,156],[147,155],[128,133],[55,58],[72,81],[183,192],[25,26],[332,333],[395,396],[370,371],[397,401],[74,77],[189,194],[15,22]]))

// console.log(merge([[1,4],[0,2],[3,5]]))

// console.log(merge([[1,3],[2,6],[8,10],[15,18]]))
// console.log(merge([[2,3],[4,5],[6,7],[8,9],[1,10]]))