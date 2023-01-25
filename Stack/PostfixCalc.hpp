#include <stack>


class PostfixCalc 
{
    public: 
        explicit PostfixCalc()
        {
            s = std::stack<int>{};
        }

        void push(int value)
        {
            s.push(value);
        }

        int pop()
        {
            int value = s.top();
            s.pop();
            return value;
        }

        int top()
        {
            return s.top();
        }

        void add()
        {
            int op1 =  s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            s.push(op1+op2);
        }

        void subtract()
        {
            int op1 =  s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            s.push(op2-op1);
        }

        void multiply()
        {
            int op1 =  s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            s.push(op1*op2);
        }
    private:
        std::stack<int> s;

};

