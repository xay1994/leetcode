class Solution {
public:
    vector<string> generateParenthesis(int num) {
        string dp="";
        //int left=0, right=num;
        vector<string> res;
        helper(res, "", num, num);
        //helper2(res, "", num, 0)
        return res;
    }
    void helper(vector<string> &res, string s, int left, int right) {
        if (left < 0 || right < 0 || left > right) {
            return;
        }
        else if (left == 0 && right == 0) {
            res.push_back(s);
            return;
        }
        else {
            helper(res, s + "(", left - 1, right);
            helper(res, s + ")", left, right - 1);
        }
    }
    void helper2(vector<string> &res, string s, int leftpare_need, int moreleft){
        if(leftpare_need == 0 && moreleft == 0){
            res.push_back(s);
            return;
        }
	    if(leftpare_need > 0){
            s.push_back('(');
            helper2(res, s, leftpare_need - 1, moreleft+1);
            s.pop_back();
        }
	    if(moreleft > 0){
            s.push_back(')');
            helper2(res, s, leftpare_need, moreleft - 1);
            s.pop_back();
        }
    }
};
