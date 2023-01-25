#include <stack>
#include <string>
#include <iostream>

#include "PostfixCalc.hpp"

using namespace std;

bool check_paranthesis (string str)
{
    stack<char> s;
    bool result = true;
    for (auto c : str){
        if (c == '(')
            s.push(c);
        else if (c == ')') {
            if (s.empty())  //extra ')'
                result = false;
            else 
                s.pop();
        }
    }
    if (!s.empty())
        result = false;
    return result;
}

int main()
{
    // Test check_paranthesis function
    string test_str1 = "((()())(()))";
    string test_str2 = "((()()))(()))";
    string test_str3 = "((()(()))((()))";
    cout <<  test_str1 << " : " << check_paranthesis(test_str1) << endl;
    cout <<  test_str2 << " : " << check_paranthesis(test_str2) << endl;
    cout <<  test_str3 << " : " << check_paranthesis(test_str3) << endl;

    // Test PostfixCalc methods
    PostfixCalc calc = PostfixCalc {};
    // "10 + 5 * 3 - 6 * 2 (infix) - 10 5 3 * 6 2 * - + (prefix) :"  
    calc.push(10);
    calc.push(5);
    calc.push(3);
    calc.multiply();
    calc.push(6);
    calc.push(2);
    calc.multiply();
    calc.subtract();
    calc.add();
    cout <<  "10 + 5 * 3 - 6 * 2 (infix) - 10 5 3 * 6 2 * - + (prefix)  evaluates to  "  << calc.top() <<  endl;





}