class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<1)
            return res;
        sort(nums.begin(),nums.end());
        vector<int> temp, res_part;
        dfs(nums, res, temp, res_part, 0, nums.size());
        return res;
    }
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, vector<int>& res_part, int count, int size){
        if(count==size){
            res.push_back(res_part);
            return;
        }
        for(int i=1;i>=0;i--){
            if(count>0 && nums[count]==nums[count-1]&&temp.back()==0)
                i=0;
            temp.push_back(i);
            if(i==1)
                res_part.push_back(nums[count]);
            dfs(nums, res, temp, res_part, count+1, size);
            temp.pop_back();
            if(i==1)
                res_part.pop_back();
        }
        
    }
};


or

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> ret = {{}};
        int size = 0, startIndex = 0;
        for (int i = 0; i < S.size(); i++) {
            startIndex = i >= 1 && S[i] == S[i - 1] ? size : 0;
            size = ret.size();
            for (int j = startIndex; j < size; j++) {
                vector<int> temp = ret[j];
                temp.push_back(S[i]);
                ret.push_back(temp);
            }
        }
        return ret;
    }

};
