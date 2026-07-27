class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int start = 0;
        unordered_map<int,int> hash;
        int maxlen = 0;

        for(int end = 0 ; end < n ; end++){
            hash[fruits[end]]++;

            while(hash.size() > 2){
                hash[fruits[start]]--;
                if(hash[fruits[start]]==0){
                    hash.erase(fruits[start]);
                }
                start++;
            }

            maxlen = max(maxlen, end - start + 1);
        }

        return maxlen;
    }
};