class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int>s;

        for(int i = 0; i < op.size(); i++){
            string str = op[i];
            if(str == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.push(a);
                int sum = a + b;
                s.push(sum);
            }
            else if(str == "C"){
                s.pop();
            }

            else if(str == "D"){
                s.push(2*s.top());
            }
            else{
                s.push(stoi(str));
            }


        }
       int total = 0;
        while (!s.empty()) {
            total += s.top();
            s.pop();
        }

        return total;
    }
};