class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>ans(r, vector<int>(c, 0));
        int a = 0, b = 0;

if (n * m != r * c) return mat;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                ans[i][j] = mat[a][b];
                b++;
                if(b == m){
                    a++;
                    b=0;
                }
            }
        }
        return ans;

    }
};