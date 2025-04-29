#include <vector>
#include <algorithm>

/**************************************************************************************************************************
 * Execution Time : 14 ms (leetcode test)
 **************************************************************************************************************************/

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int bestResult = 0;

        // sort the nums input
        std::sort(nums.begin(), nums.end());

        // Iterate the string
        for(int index = 0 ; index < nums.size() - 2 ; index++){
            int start = index + 1, end = nums.size() - 1;

            while(start < end){
                int sum = nums[index] + nums[start] + nums[end];
                if(sum == target) return sum;
                else {
                    if(abs(target - sum) < abs(target - bestResult)) bestResult = sum;
                    if (sum < target) ++start;
                    else --end;
                }
            }
        }

        return bestResult;
    }
};