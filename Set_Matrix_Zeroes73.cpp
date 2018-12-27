static const auto _=[](){ios::sync_with_stdio(false);cin.tie(0);return 0;};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row,column;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        for(auto r:row){
            for(int i=0;i<matrix[r].size();i++)
                matrix[r][i]=0;
        }
        for(auto c:column){
            for(int i=0;i<matrix.size();i++)
                matrix[i][c]=0;
        }
    }
    

or
//      void setZeroes(vector<vector<int>>& mx) 
//     {
//         bool row0 = false, col0 = false;
//         int m = mx.size(), n = mx[0].size();

//         //row0 and col0
//         for(int i=0; i<n; i++)
//             if(mx[0][i]==0)  row0 = true; //break;
//         for(int i=0; i<m; i++)
//             if(mx[i][0]==0)  col0 = true; //break;
        
//         //every one(except for 0-row and 0-col)
//         for(int i=1; i<m; i++)
//         {
//             for(int j=1; j<n; j++)
//             {
//                 if(mx[i][j]==0)
//                 {
//                     mx[i][0]=0;
//                     mx[0][j]=0;
//                 }
//             }
//         }
        
//         //set 0
//         for(int i=1; i<m; i++)
//             for(int j=1; j<n; j++)
//                 if(mx[i][0]==0 || mx[0][j]==0)
//                     mx[i][j]=0;

//         if(row0)
//             for(int j=0; j<n; j++)
//                 mx[0][j] = 0;
//         if(col0)
//             for(int j=0; j<m; j++)
//                 mx[j][0] = 0;
//     }
    
};
