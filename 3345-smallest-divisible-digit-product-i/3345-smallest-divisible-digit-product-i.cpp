class Solution {
public:
    int smallestNumber(int n, int t) {
        int temp = n;
        int mul = 1;
        while(temp > 0){
            int digit = temp % 10;
            mul *= digit;
            if(mul % t == 0){
                return n;
            }
            temp /= 10;
        }
        return smallestNumber(++n, t);
    }
};