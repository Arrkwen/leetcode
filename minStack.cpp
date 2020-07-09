#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/* 

有一个额外是数组来存储最小值
x_stack   [         -2, 1, 0,-3, 4]
min_stack [INT_MAx  -2,-2,-2,-3,-3]

 */
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
        x_size = 0;
        min_stack.emplace_back(INT_MAX);
        min_size = 1;
    }

    void push(int x)
    {
        x_stack.emplace_back(x);
        min_stack.emplace_back(min(min_stack[min_size - 1], x));
        x_size++;
        min_size++;
    }

    void pop()
    {
        try
        {
            if (!x_stack.empty())
            {
                x_stack.pop_back();
                min_stack.pop_back();
                x_size--;
                min_size--;
            }
            else
                throw "no element";
        }
        catch (const char *msg)
        {
            cout << *msg << endl;
            return;
        }
    }

    int top()
    {
        try
        {
            if(!x_stack.empty())
                return x_stack[x_size - 1];
            else
                throw "no element";
        }
        catch (const char *msg)
        {
            cout << *msg << endl;
            return -1;
        }
    }

    int getMin()
    {
        try
        {
            if(!x_stack.empty())
                return min_stack[min_size-1];
            else
                throw "no element";
        }
        catch (const char* msg)
        {
            cout << *msg << endl;
            return INT_MIN;
        }
    }
    vector<int> x_stack;
    vector<int> min_stack;
    int x_size;
    int min_size;
};


/* 
官方解答
class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

 */
int main()
{
    MinStack *p = new MinStack();
    p->push(-2);
    p->push(0);
    p->push(-3);
    cout<<p->getMin()<<endl;
    p->pop();
    cout<<p->top()<<endl;
    cout<<p->getMin()<<endl;
    return 0;
}