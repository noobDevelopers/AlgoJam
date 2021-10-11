// https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1/
// Get minimum element from stack

#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }

}

stack<int> min_stack;
/*returns min element from stack*/
int _stack :: getMin()
{
   if(!s.empty())
   {
       return min_stack.top();
   }
   return -1;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   if( !s.empty())
   {
       int e= s.top();
       s.pop();
       min_stack.pop();
       return e;
   }
   return -1;
   
}

/*push element x into the stack*/
void _stack::push(int x)
{
   if(s.empty())
   {
       s.push(x);
       min_stack.push(x);
       return;
   }
if(x>= min_stack.top()) {
    min_stack.push(min_stack.top());
}
else{
    min_stack.push(x);
}
   s.push(x);
}
