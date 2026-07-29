class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;

        for (char c : t) {
            hash[c]++;
        }

        int need = t.size(); 
        int start = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        for (int end = 0; end < s.size(); end++) {

            if (hash[s[end]] > 0)
                need--;

            // Decrease frequency regardless
            hash[s[end]]--;

            while (need == 0) {

                // Update answer
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }

                // Remove leftmost character
                hash[s[start]]++;

                // If it becomes positive, we're missing this character again
                if (hash[s[start]] > 0)
                    need++;

                start++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(minStart, minLen);
    }
};