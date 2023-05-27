//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int fresh=0,cnt=0;
        queue<pair<pair<int,int>,int>> q;
        bool vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                  q.push({{i,j},0});
                  vis[i][j]=true;
                }
                else{
                    vis[i][j]=false;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int tm=0;
        while(q.size()){
            // auto [[row,col],t]=q.front();
            auto row=q.front().first.first;
            auto col=q.front().first.second;
            auto t=q.front().second;
            q.pop();
            tm=max(tm,t);
            vector<int> x = {+1, -1, 0, 0};
            vector<int> y = {0, 0, +1, -1};
            for(int i=0;i<4;i++){
                int nr=row+x[i];
                int nc=col+y[i];
                if(nr>=0 and nc>=0 and nr<n and nc<m and grid[nr][nc]==1 
                and !vis[nr][nc]){
                   q.push({{nr,nc},t+1});
                   vis[nr][nc]=true;
                   cnt++;
                }
            }
        }
        if(fresh!=cnt){
            return -1;
        }
      
        // if(cnt!=fresh){
        //     return -1;
        // }
        return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends