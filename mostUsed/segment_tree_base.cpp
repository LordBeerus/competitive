int vert[4*MAXN];
int add (int val,int pos,  int node, int l ,int r) {

    if (l == r) {
        vert[node] = val;
        return vert[node];
    }
    int mid = (l + r)>>1;
    int m = INF;
    if (pos<= mid) m = add (val, pos, node<<1 , l , mid);
    else m = add (val, pos, (node<<1) + 1, mid + 1 , r);

    vert[node] = min (vert[node] , m);
    return vert[node];
}

int query(int qL,int qR, int num = 1, int l = 0, int r = MAXN -1 ) {
    if (qL <=l && qR>= r ) return vert[num];
    int mid = (l + r)>>1;
    int ans = INF;
    if (qL <= mid) ans = min (query(qL, qR, num<<1 , l , mid), ans);
    if (qR >= mid + 1) ans = min (query(qL, qR, (num<<1)+ 1, mid + 1 , r), ans);

    return ans;

}
