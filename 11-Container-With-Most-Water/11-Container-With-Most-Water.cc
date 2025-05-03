#include <vector>
#include <algorithm>

/**************************************************************************************************************************
 * Execution Time : 0 ms (leetcode test)
 **************************************************************************************************************************/

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        long int maxSpace = 0;

        int start = 0, end = height.size() - 1;
        while(start < end){
            long int space = (end - start) * (long int)(std::min(height[start], height[end]));
            if(space > maxSpace) maxSpace = space;
            if(height[start] < height[end]) ++start;
            else --end;
        }

        return maxSpace;
    }
};