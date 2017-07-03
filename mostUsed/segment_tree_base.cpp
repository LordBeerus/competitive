int vert[4*MAXN];
multimap<int , ii > byCost;vii byDays[MAXN];
int add (int val,int pos,  int vertNum, int l ,int r, bool cleanse = false) {

    if (l == r) {
        vert[vertNum] = val;
        if (cleanse) vert[vertNum] = INF;
        return vert[vertNum];
    }
    int mid = (l + r)>>1;
    int m = INF;
    if (pos<= mid) m = add (val, pos, vertNum<<1 , l , mid);
    else m = add (val, pos, (vertNum<<1) + 1, mid + 1 , r);

    vert[vertNum] = min (vert[vertNum] , m);
    if (cleanse) vert[vertNum] = INF;
    return vert[vertNum];
}

int query(int qL,int qR, int num = 1, int l = 0, int r = MAXN -1 ) {
    if (qL <=l && qR>= r ) return vert[num];
    int mid = (l + r)>>1;
    int ans = INF;
    if (qL <= mid) ans = min (query(qL, qR, num<<1 , l , mid), ans);
    if (qR >= mid + 1) ans = min (query(qL, qR, (num<<1)+ 1, mid + 1 , r), ans);

    return ans;

}
