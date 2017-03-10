
#include <algorithm>

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        seed ^= hasher(v[0]) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        seed ^= hasher(v[1]) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        seed ^= hasher(v[2]) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        seed ^= hasher(v[3]) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        return seed;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> buf;
        std::unordered_set<vector<int>, VectorHash> tmp_set;
        std::sort(nums.begin(), nums.end());

        if (nums.size() < 4) return buf;

        for (int i = 0; i < nums.size() - 3; ++i) {
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                int final_target = - (nums[i] + nums[j]) + target;

                int a = j + 1;
                int b = nums.size() - 1;
                while (a < b) {
                    int sum = nums[a] + nums[b];
                    if (final_target == sum) {
                        vector<int> data;
                        data.resize(4);
                        data[0] = nums[i];
                        data[1] = nums[j];
                        data[2] = nums[a];
                        data[3] = nums[b];
                        //__int128 key = (_1 << 64) | (_2 << 32) | nums[b];
                        if (tmp_set.find(data) != tmp_set.end()) {
                            a++;b--;
                            continue;
                        }
                        tmp_set.insert(data);
                        buf.push_back(data);
                        //buf[n][0] = nums[i];
                        //buf[n][1] = nums[a];
                        //buf[n++][1] = nums[b];
                        a++;
                        b--;
                    } else if (sum < final_target) a++;
                    else b--;
                }
            }
        }

        return buf;
    }
};
