static const auto _=[](){ios::sync_with_stdio(false);cin.tie(0);return 0;};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string t=strs[i];
            sort(t.begin(),t.end());
            mp[t].push_back(strs[i]);
        }
        for(auto m:mp){
            res.push_back(m.second);
        }
        return res;
    }
};
