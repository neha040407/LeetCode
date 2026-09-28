class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long MOD = 1e9 + 7;
        int n = arr.size();
        long long ans = 0;
        long long toadd;
        int prev , next;

        vector<int> se(n);   //smallest element

        stack<int> sse;    //stack for smaller element

        for(int i = 0 ; i < n ; i++){

            while(!sse.empty() && arr[sse.top()] >= arr[i]){
                sse.pop();
            }

            se[i] = sse.empty() ? -1 : sse.top();
            sse.push(i);
            //left smallest elements
        }

        while(!sse.empty()) sse.pop();

        for(int i = n-1 ; i >= 0 ; i--){
            while(!sse.empty() && arr[sse.top()] > arr[i]){
                sse.pop();
            }

            prev = i - se[i];
            se[i] = sse.empty() ? n : sse.top();

            next = se[i] - i;
            sse.push(i);
            //right smallest elements

            toadd = (((arr[i] * prev) % MOD) * next) % MOD;
            ans = (ans + toadd) % MOD;
        }

        return ans;
    }
};