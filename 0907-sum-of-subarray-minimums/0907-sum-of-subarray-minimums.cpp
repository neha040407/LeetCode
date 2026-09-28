class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long MOD = 1e9 + 7;
        int n = arr.size();
        long long ans = 0;
        long long toadd;
        int prev , next;

        vector<int> pse(n);
        vector<int> nse(n);

        stack<int> lse;    //stack for left smaller element
        stack<int> rse;    //stack for right smaller element

        for(int i = 0 ; i < n ; i++){

            while(!lse.empty() && arr[lse.top()] >= arr[i]){
                lse.pop();
            }

            pse[i] = lse.empty() ? -1 : lse.top();
            lse.push(i);
            //left smallest elements

            while(!rse.empty() && arr[rse.top()] > arr[n-1-i]){
                rse.pop();
            }

            nse[n-1-i] = rse.empty() ? n : rse.top();
            rse.push(n-1-i);
            //right smallest elements
        }

        for(int i = 0 ; i < n ; i++){
            prev = i - pse[i];
            next = nse[i] - i;

            toadd = (((arr[i] * prev) % MOD) * next) % MOD;

            ans = (ans + toadd) % MOD;
        }

        return ans;
    }
};