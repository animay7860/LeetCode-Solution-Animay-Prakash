//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void dfs(vector<vector<int>> &img , vector<vector<int>> &ans,int sr,
    int sc,int c,int ic){
        ans[sr][sc]=c;
        vector<int> x = {+1, -1, 0, 0};
        vector<int> y = {0, 0, +1, -1};
        for(int i=0;i<4;i++){
            int nrow=sr+x[i];
            int ncol=sc+y[i];
            if(nrow>=0 and nrow<img.size() and ncol>=0 and ncol<img[0].size()
            and img[nrow][ncol]==ic and ans[nrow][ncol]!=c){
             dfs(img,ans,nrow,ncol,c,ic);
             }
        }
}    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        vector<vector<int>> ans;
        ans=img;
        int ic=img[sr][sc];
        dfs(img,ans,sr,sc,color,ic);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends