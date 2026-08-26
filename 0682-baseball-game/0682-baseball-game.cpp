class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        stack<int> st;
        int first , second , top , val; 

        for(auto it : operations){
            if(it == "C"){
                st.pop();
            }
            else if(it == "D"){
                top = st.top();
                val = top * 2;
                st.push(val);
            }
            else if(it == "+"){
                first = st.top();
                st.pop();
                second = st.top();
                val = first + second;
                st.push(first);
                st.push(val);
            }
            else{
                val = stoi(it);
                st.push(val);
            }
        }

        while(!st.empty()){
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};