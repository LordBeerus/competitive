int A[MAXN][MAXLG] , level[MAXN];
 
int dfs(int curr = 0, int par = -1, int lvl = 0) {
    A[curr][0] = par;

    level[curr] = lvl;
    for (int i = 0; i < adj[curr].size(); i++)
        if (adj[curr][i] != par) {
            dfs(adj[curr][i], curr, lvl + 1);
             

        }

    dpnode[curr] += 1;
}
 

int lca(int p, int q) {
    if (level[p] < level[q])
        swap(p, q);
    for (int i = ceil(log2(n)); i >= 0; i--)
        if (level[p] - (1 << i) >= level[q])
            p = A[p][i];

    if (p == q)
        return p;
    for (int i = ceil(log2(n)); i >= 0; i--)
        if (A[p][i] != -1 && A[p][i] != A[q][i]) {
            p = A[p][i];
            q = A[q][i];
        }
    return A[p][0];

}
int patl(int lvl,int node){//parent at level lvl
    int ans=node;
    for(int i=lognodes;i>=0;i--){
        if(level[node]-(1<<i) >= lvl )
        {
            ans=A[node][i];
            node=ans;

        }
    }
    return ans;
}

int main() {
   

    dfs();
  
    for (int j = 1; j <= ceil(log2(n)); j++)
        for (int i = 0; i < n; i++)//0 indexed...replace by i=1 till n for 1 indexed
            if (A[i][j - 1] != -1)
                A[i][j] = A[A[i][j - 1]][j - 1];
            else
                A[i][j] = -1;

 
}
