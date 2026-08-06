class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int, int> mpp;
        for (auto c : text) {
            if (c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n') {
                mpp[c]++;
            }

        }

        string key = "balloon";
        int mini = INT_MAX;
        
        for (auto ch : key) {
            if (ch == 'l' || ch == 'o')
                mini = min(mini, mpp[ch] / 2);
            else
                mini = min(mini, mpp[ch]);
        }

        return mini;

    }
};