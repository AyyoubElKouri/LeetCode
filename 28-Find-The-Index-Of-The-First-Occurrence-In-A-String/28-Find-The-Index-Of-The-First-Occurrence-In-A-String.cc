#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        // hhhhhhhhhhhhhhhh kayn wla ma kaynch hhhhh
        int index = haystack.find(needle);
        return index != std::string::npos ? index : -1;
    }
};