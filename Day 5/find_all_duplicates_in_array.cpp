class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }
        for(int i = 1; i <= n; i++){
            if(mpp[i] == 2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};