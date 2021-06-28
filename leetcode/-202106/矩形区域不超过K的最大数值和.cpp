class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        //第一步，统计全部每一行以第i位为开头的可能和（一维，从后往前统计，利用已有信息）
        vector<vector<vector<int>>> row_answers;
        for(int i=0;i<matrix.size();i++){
            vector<int> row = matrix[i];
            vector<vector<int>> row_answer;
            vector<int> row_dp;

            for(int j=row.size()-1;j>=0;j--){
                int l = row_dp.size();
                int n = row[j];
                row_dp.push_back(n);
                if(n == k) return k;
                if(l>0){
                    for(int u=0;u<l;u++){
                        row_dp[u] = row_dp[u]+n;
                        if(row_dp[u] == k) return k;
                    }
                }
                row_answer.push_back(row_dp);
            }
            row_answers.push_back(row_answer);

        }

        //第二步，统计以第i行,j列为左上角的可能和（二维，从后往前统计，利用已有信息）
        int ans = -100000;
        for(int y=0;y<row_answers[0].size();y++){
            vector<int> dp;
            for(int i=row_answers.size()-1;i>=0;i--){
                vector<int> get = row_answers[i][y];

                int l = get.size();
                int count = row_answers.size()-1-i;
                for(int j=0;j<get.size();j++){
                    if(get[j]==k) return k;
                    else{
                        dp.push_back(get[j]);
                        if(get[j]<k && get[j]>ans) ans = get[j];
                    }
                }
                
                if(count>0){
                    for(int u=0;u<count;u++){
                        for(int g=0;g<l;g++){
                            int num = u*l+g;
                            dp[num] = dp[num]+get[g];
                            if(dp[num]==k) return k;
                            else if(dp[num]<k && dp[num]>ans) ans = dp[num];
                        }
                    }
                }
            }
        }
        return ans;
    }
};


//另一种解法：对每一行求解时使用前n项和，前n项和可以计算出任意连续n项和，然后用有序列表和二分查找来寻找最接近的