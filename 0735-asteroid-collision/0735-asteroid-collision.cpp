#include <cstdlib>
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        int push = 1;
        for(auto it : asteroids){
            if(st.empty() || (st.top()*it > 0)){
                st.push(it);
            }
            else{
                while(!st.empty() && (st.top() > 0)){
                    if(abs(st.top()) > abs(it)){
                        push = 0;
                        break;
                    }
                    else if(abs(st.top()) == abs(it)){
                        st.pop();
                        push = 0;
                        break;
                    }
                    else{
                        st.pop();
                    }
                }

                if(push){
                    st.push(it);
                }

                push = 1;

            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};