//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    void dfs(int s,vector<int> adj[],int vis[]){
        vis[s]=1;
        for(auto x : adj[s]){
            if(!vis[x]){
                dfs(x,adj,vis);
            }
        }
    }

  public:
    int numProvinces(vector<vector<int>> ad, int v) {
        // code here
    
        vector<int> adj[v];
        for(int i=0;i<v;i++){
          for(int j=0;j<v;j++){
              if(ad[i][j]==1 and i!=j){
                  adj[i].push_back(j);
                  adj[j].push_back(i);
              }
          }
        }
        int vis[v];
        for(int i=0;i<v;i++){
            vis[i]=0;
        }
        int cnt=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends