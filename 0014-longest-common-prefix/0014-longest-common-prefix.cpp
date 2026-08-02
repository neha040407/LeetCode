class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int shortestlen = strs[0].size();
        int n = strs.size();
        int issame = 1;
        string ans = "";

        for(int i = 1 ; i < n ; i++){
            shortestlen = min((int)strs[i].size() , shortestlen);
        }

        for(int i = 0 ; i < shortestlen ; i++){
            for(int j = 0 ; j < n-1 ; j++){
                if(strs[j][i] != strs[j+1][i]){
                    issame = 0;
                    break;
                }
            }
            if(issame){
                ans.push_back(strs[0][i]);
            }
            else{
                break;
            }
        }

        return ans;
    }
};