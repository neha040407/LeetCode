class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans = "";

        for(auto it : s){
            if(st.empty() || st.top() != it){
                st.push(it);
            }
            else {
                st.pop();
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return  ans;
    }
};