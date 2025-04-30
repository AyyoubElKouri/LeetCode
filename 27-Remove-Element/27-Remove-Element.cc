#include <vector>

/**************************************************************************************************************************
 * Execution Time : 0 ms (leetcode test)
 **************************************************************************************************************************/

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int expectedSize = 0;
        for(int index = 0 ; index < nums.size() ; ++index){
            if(nums[index] != val){
                nums[expectedSize] = nums[index];
                expectedSize++;
            }
        }

        return expectedSize;
    }
};