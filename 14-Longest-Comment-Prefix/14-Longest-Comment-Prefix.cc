#include <string>
#include <vector>

/**************************************************************************************************************************
 * Execution Time : 0 ms (leetcode test)
 **************************************************************************************************************************/

class Solution {
    public:
        std::string longestCommonPrefix(std::vector<std::string>& strs) {
            std::string result = "";

            for(int index = 0 ; index < strs[0].length() ; index++)
                if(existInAll(strs, index)) result.push_back(strs[0].at(index));
                else break;

            return result;
        }

        bool existInAll(std::vector<std::string>& strs, int index){
            for(int index2 = 1 ; index2 < strs.size() ; index2++){
                if(index >= strs[index2].length()) return false;
                if(strs[0].at(index) != strs[index2].at(index))
                    return false;
            }
            return true;
        }
    };