void dfs(int curr,int par=-1,int maxUp=0,int depth=0) {
    if (par!=-1) {
        merge(curr, par);
    }
     
    maxDepth[curr] = 0;

    int other = 0;
    for (int nxt : adj[curr]) {
        if (nxt!=par) {
            dfs(nxt,curr,max(other,maxUp)+1,depth+1);
            maxDepth[curr] = max(maxDepth[curr],maxDepth[nxt]+1);
            other = max(other,maxDepth[nxt] +1);
        }
    }
    
    diameter  = max(diameter  , other+maxUp);


}
