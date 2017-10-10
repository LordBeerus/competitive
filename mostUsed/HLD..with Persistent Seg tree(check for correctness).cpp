int chainId[MAXN],chainSize[MAXN],chainHead[MAXN],posInSeg[MAXN];
vi adj[MAXN];
int subSize[MAXN];
int n;
int sub(int curr,int par){
    int s = 1;
    for(int nxt: adj[curr])
        if(nxt!=par)
            s+=sub(nxt,curr);
    subSize[curr]=s;
    return s;
}
int CHAIN=0,POS=0;
void hld(int curr=0,int par=-1,int neww=1){
    //check if new chain
    posInSeg[curr]=POS++;
    int currChain = chainId[curr];
    if(neww){//new chain
        chainId[curr]=CHAIN++;
        chainHead[chainId[curr]]=curr;
    }
    chainSize[chainId[curr]]++;
    //find largest
    int m=-1,msize=-1;
    for(int nxt:adj[curr])
        if(nxt!=par)
            if(subSize[nxt]>msize)
                msize = subSize[nxt],m=nxt;

    if(m!=-1)
        hld(m,curr,0);

    for(int nxt:adj[curr])
        if(nxt!=par && nxt!=m)
            hld(nxt,curr,1);
}
int A[MAXN][MAXLG] , level[MAXN];

int dfs(int curr = 0, int par = -1, int lvl = 0) {
    A[curr][0] = par;

    level[curr] = lvl;
    for (int i = 0; i < adj[curr].size(); i++)
        if (adj[curr][i] != par) {
            dfs(adj[curr][i], curr, lvl + 1);


        }


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
int s[2*MAXN],L[2*MAXN],R[2*MAXN];
int NEXT_FREE_INDEX=1;
void build(int id = 0,int l = 0,int r = n-1){
    s[id] = 0;
    if( r == l )
        return ;
    int mid = (l+r)/2;
    L[id] = NEXT_FREE_INDEX ++;
    R[id] = NEXT_FREE_INDEX ++;
    build(L[id], l, mid);
    build(R[id], mid, r);
    s[id] = s[L[id]] + s[R[id]];
}

int upd(int p, int v,int id,int l = 0,int r = n-1){
    int ID =  NEXT_FREE_INDEX ++; // index of the node in new version of segment tree
    s[ID] = s[id] + 1;
    if(r==l)
        return ID;
    int mid = (l+r)/2;
    L[ID] = L[id], R[ID] = R[id]; // in case of not updating the interval of left child or right child
    if(p <= mid)
        L[ID] = upd(p, v, L[ID], l, mid);
    else
        R[ID] = upd(p, v, R[ID], mid, r);
    return ID;
}
int ask(int id  ,int L,int R, int l ,int r){// id is the index of the node after l-1-th update (or ir) and ID will be its index after r-th update
    if(l>=L && r<= R)return s[id];
    int mid = (l+r)/2;
    int sum =0;
    if(L<=mid )// answer is in the left child's interval
        sum += ask(::L[id], L,R, l, mid);
    if(R>mid)
        sum+= ask(::R[id], L,R, mid, r);// there are already s[L[ID]] - s[L[id]] 1s in the left child's interval

    return sum;
}
 
