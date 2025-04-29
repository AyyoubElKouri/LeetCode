#include <vector>
#include <string>
#include <unordered_map>

/**************************************************************************************************************************
 * Execution Time : 0 ms (leetcode test)
 **************************************************************************************************************************/

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {

        if(digits.size() == 0) return {};

        // fill the map
        std::unordered_map<char, std::vector<std::string>> map;
        map['2'] = {"a", "b", "c"}; map['3'] = {"d", "e", "f"};
        map['4'] = {"g", "h", "i"}; map['5'] = {"j", "k", "l"};
        map['6'] = {"m", "n", "o"}; map['7'] = {"p", "q", "r", "s"};
        map['8'] = {"t", "u", "v"}; map['9'] = {"w", "x", "y", "z"};

        int index = digits.size() - 1;
        std::vector<std::string> result(map[digits.at(index--)]);
        while(index >= 0){
            result = this->combine(result, map[digits.at(index)]);
            --index;
        }

        return result;

    }

    std::vector<std::string> combine(std::vector<std::string> v1, std::vector<std::string> v2){
        std::vector<std::string> result;
        for(int index = 0 ; index < v1.size() ; index++)
            for(int index2 = 0 ; index2 < v2.size() ; index2++)
                result.push_back(v2[index2] + v1[index]);

        return result;
    }
};