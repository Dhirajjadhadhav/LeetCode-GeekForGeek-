class Solution {
    long long solve(int i, vector<vector<int>>&questions, vector<long long>&memo){
        if(i>=questions.size())return 0;

        if(memo[i] != 0)return memo[i];
        long long take = questions[i][0] + solve(i+questions[i][1]+1, questions, memo);
        long long notake =  solve(i+1, questions, memo);

        return memo[i] = max(take, notake);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>memo(questions.size(), 0);
        return solve(0, questions, memo);
    }
};