#include <vector>

/**************************************************************************************************************************
 * Execution Time : 0 ms (leetcode test)
 **************************************************************************************************************************/

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int expectedSize = 0;

        for(int index = 0 ; index < nums.size() ; ++index){
            if(nums[index] != nums[expectedSize]){
                ++expectedSize;
                nums[expectedSize] = nums[index];
            }
        }

        return expectedSize + 1;
    }
};