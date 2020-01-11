#include <stack>

class Solution {
public:
    bool isValid(string s) {
        
        /** IDEA:
        * Keep a stack to trace every bracket
        * if open bracket, push
        * if closing bracket, check if already in stack
        * NOTE: opening and closing brackets got together,
        * meaning, stack.top() should return the open bracket of the current closing bracket
        **/
        
        if(s.size()<1){
            return true;
        }
        
        //Given the string only contains brackets
        if(s.size()%2!=0){
            return false;
        }
        
        stack<char> stack;
        for(int i=0;i<s.size();i++){
            switch(s[i]){
                case '(': stack.push(s[i]);
                          break;
                case ')': if(!stack.empty() && stack.top()=='('){
                            stack.pop();
                          }
                          else{
                              return false;
                          }
                          break;
                case '{': stack.push(s[i]);
                          break;
                case '}': if(!stack.empty() && stack.top()=='{'){
                            stack.pop();
                          }
                          else{
                              return false;
                          }
                          break;
                case '[': stack.push(s[i]);
                          break;
                case ']': if(!stack.empty() && stack.top()=='['){
                            stack.pop();
                          }
                          else{
                              return false;
                          }
                          break;
                    
            }
        }
        if(stack.size()==0){
            return true;
        }
        else return false;
    }
};
