class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mpp;

        for (char c : text) {
            if (c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n') {
                mpp[c]++;
            }
        }

        return min({
            mpp['b'],
            mpp['a'],
            mpp['l'] / 2,
            mpp['o'] / 2,
            mpp['n']
        });
    }
};