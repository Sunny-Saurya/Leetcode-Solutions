class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int l = 0, r = n-1;
        int boats = 0;

        while(l <= r){
            int sum = people[l] + people[r];
            if(sum <= limit) l++;
            r--;
            boats++;
        }
        return boats;
    }
};