class Solution {
public:
    vector<vector<int>> res;
    void helper(int num,int tot,int k,vector<int>&ans){
        if(num==tot+1){
            //filter the size of subsequence of size k.
            if(ans.size()==k)
            res.push_back(ans);
            return;
        }

        ans.push_back(num);
        helper(num+1,tot,k,ans);//take current number
        ans.pop_back();
        helper(num+1,tot,k,ans);//not take current number
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        helper(1, n, k, ans);
        return res;
    }
};