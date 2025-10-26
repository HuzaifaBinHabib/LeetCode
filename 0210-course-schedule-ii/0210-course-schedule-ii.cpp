class Solution {
public:
   bool iscycledfs(int src,int n,vector<bool>& vis,vector<vector<int>>& edge,vector<bool>& recpath){
      vis[src] = true;
      recpath[src] = true;
     
     for(int i=0; i<edge.size();i++){
        int u = edge[i][0];
        int v = edge[i][1];
        if(src == v){
            if(vis[u] != true){
                if(iscycledfs(u,n ,vis,edge,recpath)){
                    return true;
                }
            }else if(recpath[u] == true){
                return true;
            }
        }
     }
     recpath[src]= false;
     return false; 
   }
   void toporder(int src,int n,vector<bool>& vis,vector<vector<int>>& edge,stack<int>& s){
      vis[src]= true;

      for(int i=0;i<edge.size();i++){
        int u = edge[i][0];
        int v = edge[i][1];
        if(src == v){
            if(vis[u]!= true){
                toporder(u,n,vis,edge,s);
            }
        }
      }
     s.push(src);
   }
   
    vector<int> findOrder(int n, vector<vector<int>>& edge) {
        vector<bool> vis(n,false);
        vector<bool> recpath(n,false);
        stack<int>s;
        vector<int> ans;

        for(int i=0;i<n; i++){
            if(vis[i]!= true){
                if(iscycledfs(i,n,vis,edge,recpath)){
                    return ans;
                }
            }
        }
        
        vis.assign(n,false);
        for(int i=0; i<n; i++){
            if(vis[i]!= true){
              toporder(i,n,vis,edge,s);
            }
        }

        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};