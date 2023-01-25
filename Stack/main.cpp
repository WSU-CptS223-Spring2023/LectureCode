// Standard libraries
#include <stack>
#include <iterator>

#include <string>
#include <sstream>
#include <iostream> 

using namespace std;

bool check_paranthesis(string str)
{
    stack<char> s;
    bool mismatch = false;

    for (auto c : str) // for each char in str
    {
        if ( c=='(' )
            s.push(c);
        else if ( c==')' ){
            if (s.empty()) {  // check if the stack is empty
                cout << "Missing closing paranthesis!" << endl;
                mismatch = true;
                break;
            }
            else
                s.pop();
        }
    }
    if (!s.empty()) {
        cout << "Missing opening paranthesis!" << endl;
        mismatch = true;
    }
    
    return mismatch; 

}

int main()
{

    // Test "check_paranthesis" function
    

}