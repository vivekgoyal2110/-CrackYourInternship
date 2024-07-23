class Solution {

public:
    void findSubset(int ind, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        ans.push_back(ds);
        for (int i = ind; i < arr.size(); i++) {
           if (i != ind && arr[i] == arr[i - 1]) continue;
           ds.push_back(arr[i]);
           findSubset(i + 1, arr, ans, ds);
           ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubset(0, nums, ans, ds);
        return ans;
    }
};