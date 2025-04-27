#include <string>
#include <algorithm>
#include <unordered_set>

/**************************************************************************************************************************
 * Execution Time : 23 ms (leetcode test)
 **************************************************************************************************************************/


class Solution
{
public:
    int lengthOfLongestSubstring(std::string s) {
        int start = 0;
        int bestResult = 0;

        std::unordered_set<char> set;
        for(int end = 0 ; end < s.length() ; end++){
            while(set.find(s.at(end)) != set.end()){
                set.erase(s.at(start));
                ++start;
            }

            set.insert(s.at(end));
            bestResult = std::max(bestResult, end - start + 1);
        }

        return bestResult;
    }
};