void backtrack(vector<int>& arr, vector<vector<int>>& result, vector<int>& temp, vector<bool>& used) {
        if (temp.size() == arr.size()) {
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (used[i] || (i > 0 && arr[i] == arr[i - 1] && !used[i - 1])) continue;
            used[i] = true;
            temp.push_back(arr[i]);
            backtrack(arr, result, temp, used);
            temp.pop_back();
            used[i] = false;
        }
    }