//dfs
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // vector<vector<string>> res({{"Q"}});
        // int i=1;
        // while(i<n){
        //     i++;
        //     vector<vector<string>> temp;
        //     for(int j=0;j<i;j++){
        //         string s(i,'.');
        //         s.replace(j,1,"Q");
        //         for(int m=0;m<res.size();m++){
        //             vector<string> ss;
        //             ss.push_back(s);
        //             for(string t:res[m]){
        //                 string tt=t;
        //                 tt.insert(j, 1, '.');
        //                 ss.push_back(tt);
        //             }
        //             temp.push_back(ss);
        //         }
        //     }
        //     res=temp;
        // }
        // return res;
        vector<vector<string>> res;
        if(n==1){
            res.push_back({"Q"});
            return res;
        }
        if(n<4)
            return res;
        vector<int> judge;
        vector<string> temp;
        helper(res, temp, judge, 0, n);
        return res;
    }
    void helper(vector<vector<string>>& res, vector<string>& temp, vector<int>& judge, int cur, int size){
        if(cur==size){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<size;i++){
            // if(cur==0){
            //     judge.push_back(i);
            //     string s(size,'.');
            //     s.replace(i,1,"Q");
            //     temp.push_back(s);
            //     helper(res, temp, judge, cur+1, size);
            // }
            bool ishave=true;
            for(int j=0;j<judge.size();j++){
                if(i==judge[j] || abs(cur-j)==abs(i-judge[j])){
                    ishave=false;
                    break;
                }
            }
            if(!ishave)
                continue;
            judge.push_back(i);
            string ss(size,'.');
            ss.replace(i,1,"Q");
            temp.push_back(ss);
            helper(res, temp, judge, cur+1, size);
            judge.pop_back();
            temp.pop_back();
            
        }
        
    }
};

//iterative
class Solution {

public: vector<vector<string> > solveNQueens(int n) {
        
        vector<vector<string> > Sol;
        int X[n+1] = {0}, k=1, i, t=0;
	    
	    while(k > 0) {

		    X[k]++;

		    while(X[k] <= n && !(place(k, X))) X[k]++;

		    if(X[k] <= n) {
			    
                if(k == n) {
				
                    vector<string> board (n, string(n,'.'));
                
                    for(i=1; i<=n; i++) board[i-1][X[i]-1] = 'Q';
                
                    Sol.push_back(board);               
			    }
			    else { k++; X[k] = 0; }
		    }
		    else k--;
	    }
        return Sol;
    }

        
    int place(int k, int Xx[])
    {
	    int i;

	    for(i=1; i<k; i++)
		    if((Xx[i] == Xx[k]) || (abs(Xx[i]-Xx[k]) == abs(i-k))) return 0;
			    
	    return 1;
    }        

};
