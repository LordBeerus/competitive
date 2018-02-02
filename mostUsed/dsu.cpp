int dsuPar[MAXN];
int rnk[MAXN];
int find(int x) {
    if (dsuPar[x]==x)return x;
      return find(dsuPar[x]);
}

int merge(int x,int y) {
    int parx =  find(x);
    int pary = find(y);
    if (rnk[parx]==rnk[pary]) {
        dsuPar[pary] = parx;
        rnk[parx]++;
    } else if (rnk[parx]<rnk[pary]) {
        dsuPar[parx] = pary;
    } else {
        dsuPar[pary] = parx;
    }
}
