ll tree[MAXN][MAXN];
  

void update(int x,int y ,ll val) {
    while (x<MAXN) {
        int Y = y;
        while (Y<MAXN) {
            tree[x][Y] += val;
            Y +=(Y&(-Y));
        }
        x +=(x&(-x));
    }
}
vvi rects;
vii query;
//get from top left (x,y)->(1,1)
ll get(int x,int y ) {
    ll sum = 0;
    while (x>0) {
        int Y = y;
        while (Y>0) {
           sum+= tree[x][Y]  ;
            Y -=(Y&(-Y));
        }
        x -=(x&(-x));
    }
    return sum;
}

//top left...bottom right
ll getRectangleSum(int x1,int y1,int x2,int y2) {
    return get(x2,y2) - get(x1-1,y2 ) + get(x1-1,y1-1) - get(x2 ,y1-1);
}
