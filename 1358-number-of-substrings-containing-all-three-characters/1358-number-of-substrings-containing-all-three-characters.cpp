class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> hash(3,0);
        int end=0;
        int ans = 0;

        hash[s[0] - 'a']++;

        for(int start = 0 ; start < n-2 ; start++){


            while((hash[0]==0 || hash[1]==0 || hash[2]==0) && end<n-1){
                end++;
                hash[s[end] - 'a']++;
            }

            if(hash[0]==0 || hash[1]==0 || hash[2]==0){
                break;
            }

            ans = ans + (n-end);

            hash[s[start] - 'a']--;            

        }

        return ans;

    }
};