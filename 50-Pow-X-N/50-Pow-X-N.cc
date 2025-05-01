
/**************************************************************************************************************************
 * Execution Time : 0 ms (leetcode test)
 **************************************************************************************************************************/

class Solution {
public:
    double myPow(double x, int n) {
        long int N = n;
        return (n < 0) ? fastPower(1/x, -N) : fastPower(x, N);
    }

    double fastPower(double x, long int n){
        if(x == 0) return 0;
        if(n == 0) return 1;
        double result = this->fastPower(x, n / 2);
        result *= result;

        if(isPair(n)) return result;
        else          return (x * result);
    }

    bool isPair(int integer){ return (integer % 2) == 0; }
};