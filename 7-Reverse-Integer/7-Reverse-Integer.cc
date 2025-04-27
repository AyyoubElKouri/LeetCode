#include <math.h>

/**************************************************************************************************************************
 * Execution Time : 1 ms (leetcode test)
 **************************************************************************************************************************/

class Solution {
public:
    int reverse(int x) {
        int sign = (x > 0) ? 1: -1;
        long int value = (long int)x * sign;

        long int a = 10;
        long int newX = 0;
        while((a/10) <= value){
            newX = (newX * 10) + ((value % a)/ (a/10));
            a*=10;
        }
        newX = newX * sign;
        if(newX < -2147483648 || newX > 2147483647) return 0;

        return newX;
    }
};