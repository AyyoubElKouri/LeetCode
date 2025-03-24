#include <iostream>
#include <vector>
#include <algorithm>

/**************************************************************************************************************************
 * Execution Time : 47 ms (leetcode test)
 **************************************************************************************************************************/

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {

        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());

        for(int index = 0 ; index < nums.size() - 2 ; index++){
            auto start = nums.begin() + index + 1;
            auto end = nums.end() - 1;

            while(start < end){
                int sum = *start + *end + nums[index];
                if(sum == 0){
                    result.push_back({nums[index], *start, *end});
                    while(start < end && *start == *(start + 1)) ++start;
                    while(start < end && *end == *(end - 1)) --end;
                    while(index < nums.size() - 2 && nums[index] == nums[index + 1]) ++index;
                    ++start; --end;
                }
                else if (sum < 0) ++start;
                else --end;
            }
 
        }

        return result;
    }   
};



int main()
{
    Solution S;
    std::vector<int> myVector {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};


    std::sort(myVector.begin(), myVector.end());

    for(auto a : myVector){
        std::cout << a << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> result;

    result = S.threeSum(myVector);

    for (auto r: result)        
    {
        for (auto rr: r)
        {
            std::cout << rr << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}