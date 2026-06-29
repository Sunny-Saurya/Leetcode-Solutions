class Solution {
    bool isThere(string yoyo, vector<string>&str){
        for(auto &check : str){
            if(yoyo == check) return true; 
        }
        return false;
    }
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        vector<string>str;
        for(int i = 0; i < word.size(); i++){
            string sub = "";
            for(int j = i; j < word.size(); j++){
                sub += word[j];
                str.push_back(sub);
            }
        }

        for(auto check: patterns){
            if(isThere(check, str)){
                count++;
            }
        }
        return count;
    }
};