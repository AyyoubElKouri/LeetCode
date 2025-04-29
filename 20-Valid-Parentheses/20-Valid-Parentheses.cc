#include <stack>
#include <vector>
#include <string>

/**************************************************************************************************************************
 * Execution Time : 0 ms (leetcode test)
 **************************************************************************************************************************/


class Solution {
public:
    bool isValid(std::string s) {
        // Create The main stack
        std::stack<char, std::vector<char>> stack;
        for(int index = 0 ; index < s.length() ; ++index){
            char temp = s.at(index);
            if(temp == '(' || temp == '{' || temp == '[') stack.push(temp);
            else{
                if(stack.empty()) return false;
                char opening = stack.top();
                if(temp == ')' && opening != '(') return false;
                if(temp == '}' && opening != '{') return false;
                if(temp == ']' && opening != '[') return false;
                stack.pop();
            }
        }

        return stack.empty();
    }
};