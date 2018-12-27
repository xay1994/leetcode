static const auto _=[](){ios::sync_with_stdio(false);cin.tie(NULL);return nullptr;}();
class Solution {
public:
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     helper(res, nums, 0);
    //     return res;
    // }
    // void helper(vector<vector<int>> &res, vector<int>& nums, int begin){
    //     if(begin>=nums.size()){
    //         res.push_back(nums);
    //         return;
    //     }
    //     for(int i=begin;i<nums.size();i++){
    //         swap(nums[begin],nums[i]);
    //         helper(res, nums, begin+1);
    //         swap(nums[begin],nums[i]);
    //     }
    // }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        int k = nums.size();
        vector<bool> used(k, false);
        dfs(nums, k, used, cur, res);
        return res;
    }

private:
    void dfs(vector<int>& nums, int& k, vector<bool>& used, vector<int>& cur, vector<vector<int>>& res) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }  
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            cur.push_back(nums[i]);
            dfs(nums, k, used, cur, res);
            cur.pop_back();
            used[i] = false;
        }
    }
};
