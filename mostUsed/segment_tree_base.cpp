int vert[4*maxn],n;
//point update
void add (int val,int pos,  int node=1, int l=1 ,int r=n) {

    if (l == r) {
        vert[node] = val;
        return  ;
    }
    int mid = (l + r)>>1;
    
    if (pos<= mid)  add (val, pos, node<<1 , l , mid);
    else  add (val, pos, (node<<1) + 1, mid + 1 , r);

    vert[node] =  // ;
 }
//range query
int query(int qL,int qR, int num = 1, int l = 1, int r = n ) {
    if (qL <=l && qR>= r ) return vert[num];
    int mid = (l + r)>>1;
    int ans = INF;
    if (qL <= mid) ans =  query(qL, qR, num<<1 , l , mid) ;
    if (qR >= mid + 1) ans = query(qL, qR, (num<<1)+ 1, mid + 1 , r) ;

    return ans;

}
//range update 
void add (int val,int L,int R,  int node=1, int l=1 ,int r=n) {
    if (l>=L && r<=R) {
        lazy[node] += val;
        vert[node] += val;
        return;
    }
    push(node);
    int mid = (l + r)>>1;

    if (L<= mid)  add (val, L,R, node<<1 , l , mid);
     if (R>mid) add (val, L,R, (node<<1) + 1, mid + 1 , r);

    vert[node] = vert[left(node)]+vert[right(node)];

}
