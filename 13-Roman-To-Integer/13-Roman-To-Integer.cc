#include <string>
#include <unordered_map>

/**************************************************************************************************************************
 * Execution Time : 2 ms (leetcode test)
 **************************************************************************************************************************/

class Solution {
public:
    int romanToInt(std::string s) {
        int result = 0;

        // Fill the hashmap
        std::unordered_map<char, int> map;
        map['I'] = 1;   map['V'] = 5;   map['X'] = 10;
        map['L'] = 50;  map['C'] = 100; map['D'] = 500;
        map['M'] = 1000;

        // Iterate the string
        int index = 0;
        while(index < s.length()){
            if((index + 1 == s.length()) || map[s.at(index)] >= map[s.at(index + 1)])
                result += map[s.at(index)];
            else
                result -= map[s.at(index)];
            ++index;
        }

        return result;
    }
};