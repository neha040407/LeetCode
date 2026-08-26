class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char top;

        for(auto it:s){
            if(st.empty()){
                top = ' ';
            }
            else{
                top = st.top();
            }

            if(it == '(' || it == '{' || it == '['){
                st.push(it);
            }
            else if((it == ')' && top =='(') || (it == '}' && top =='{') || (it == ']' && top =='[')){
                st.pop();
            }
            else{
                return false;
            }
        }

        return st.empty();
    }
};