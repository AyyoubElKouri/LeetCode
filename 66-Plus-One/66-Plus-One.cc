#include <vector>
#include <algorithm>

/**************************************************************************************************************************
 * Execution Time : 0 ms (leetcode test)
 **************************************************************************************************************************/

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int lastDigit = digits.size() - 1;
        while(lastDigit >= 0 && digits[lastDigit] == 9) --lastDigit;
        if(lastDigit < 0) {
            digits.insert(digits.begin(), 1);
            std::fill(digits.begin() + 1, digits.end(), 0);
        } else {
            digits[lastDigit] = digits[lastDigit] + 1;
            std::fill(digits.begin() + lastDigit + 1, digits.end(), 0);
        }

        return digits;
    }
};