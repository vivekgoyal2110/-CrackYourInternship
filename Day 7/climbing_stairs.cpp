class Solution {
public:
    int solve(int n){
        if(n <= 2) return n;
        return solve(n-1)+solve(n-2);
    }

    int climbStairs(int n) {
        return solveTD();
    }
};