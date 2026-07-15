class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int n = s.size();
        int l = 0, r = 0;
        int maxLen = 0;

        while(r < n){
            char ch = s[r];
            while(st.find(ch) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(ch);
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};