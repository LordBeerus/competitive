
int vert[4 * MAXN][4 * MAXN];
 
void addy(  int nodeX,ll yL, ll yR, ll val, int node, int l=0, int r=m-1) {

    if (yL <= l && r  <= yR) {
        vert[nodeX][node] = (vert[nodeX][node] + val + MOD)%MOD;
        return;
    }
    int mid = (l + r) >> 1;

    if (yL <= mid) addy(nodeX,  yL, yR, val, node << 1, l, mid);
    if (yR > mid) addy(nodeX,yL, yR, val, (node << 1) + 1, mid + 1, r);
}

void add(  ll xL, ll xR,ll yL, ll yR, ll val, int node, int l, int r) {

    if (xL <= l && r  <= xR) {
        addy( node, yL,   yR,val,1);
        return;
    }
    int mid = (l + r) >> 1;

    if (xL <= mid) add(xL,xR,  yL, yR, val, node << 1, l, mid);
    if (xR > mid) add(xL,xR,yL, yR, val, (node << 1) + 1, mid + 1, r);
}

ll queryY(int nodeX, ll posy ,int node = 1  , int l  = 0 , int r = m-1  ) {
    if (l == r)
        return vert[nodeX][node];
    int mid = (l + r) >> 1;
    ll ans = vert[nodeX][node];
    if (posy <= mid) ans += queryY(nodeX, posy, node << 1, l, mid);
    else ans += queryY(nodeX, posy, (node << 1) + 1, mid + 1, r);
    return ans;
}
ll query( ll posx,ll posy,int node  =1, int l=0  , int r = n-1  ) {
    if (l == r)
        return queryY(node,posy);
    int mid = (l + r) >> 1;
    ll ans = queryY(node,posy);
    if (posx <= mid) ans += query(posx, posy, node << 1, l, mid);
    else ans += query(posx, posy, (node << 1) + 1, mid + 1, r);
    return ans;
}
