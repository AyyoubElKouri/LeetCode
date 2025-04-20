#include <iostream>
#include <vector>
#include <unordered_map>

/**************************************************************************************************************************
 * Execution Time : 1 ms (leetcode test)
 **************************************************************************************************************************/

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for(int index = 0 ; index < nums.size() ; index++) {
            auto exist = map.find(target - nums[index]);
            if (exist != map.end())
                return {index, exist->second};
            else
                map[nums[index]] = index;
        }
    }
};


int main(int argc, char **argv)
{
    Solution solution;
    std::vector<int> v {1, 8, 9, 8};
    std::vector<int> reslut = solution.twoSum(v, 16);
    for(auto value : reslut) std::cout << value << std::endl;
    return 0;
}
