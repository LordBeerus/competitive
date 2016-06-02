#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <set>
#include <stack>
#include <string.h>

using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<long long int , long long int>
#define ull unsigned long long int
#define ll  long long int
#define MAXN 30
#define  MOD 1000000007
#define MAXLG 18
#define EPS 1e-8
#define endl '\n'
vi adj[MAXN];
int A[MAXN][MAXLG], level[MAXN];
ll dpnode[MAXN], dpdist[MAXN];
ll dprnode[MAXN],dprdist[MAXN];
int ans, lognodes;

int readint() {
    char cc = getchar();
    while (cc < '0' || cc > '9') {
        cc = getchar();
    }

    int ans = 0;
    while (cc >= '0' && cc <= '9') {
        ans = ans * 10 + cc - '0';
        cc = getchar();
    }

    return ans;
}

int lb(unsigned int n) {
    if (n == 0)
        return -1;
    int p = 0;
    if (n >= 1 << 16) {
        n >>= 16;
        p += 16;
    }
    if (n >= 1 << 8) {
        n >>= 8;
        p += 8;
    }
    if (n >= 1 << 4) {
        n >>= 4;
        p += 4;
    }
    if (n >= 1 << 2) {
        n >>= 2;
        p += 2;
    }
    if (n >= 1 << 1) { p += 1; }
    return p;
}

int dfs(int curr = 0, int par = -1, int lvl = 0) {
    A[curr][0] = par;

    level[curr] = lvl;
    for (int i = 0; i < adj[curr].size(); i++)
        if (adj[curr][i] != par) {
            dfs(adj[curr][i], curr, lvl + 1);
            dpnode[curr]+=dpnode[adj[curr][i]];
            dpdist[curr]+=dpnode[adj[curr][i]]+dpdist[adj[curr][i]];

        }

    dpnode[curr] += 1;
}

int dfs2(int curr = 0,int par = -1) {



    for (int i = 0; i < adj[curr].size(); i++)
        if (adj[curr][i] != par) {
            int n = adj[curr][i];
            dprnode[n]=dprnode[curr]+dpnode[curr]-dpnode[n];
            dprdist[n]= dprnode[curr]+dprdist[curr]+dpdist[curr]-dpdist[n]-dpnode[n]+(dpnode[curr]-dpnode[n]);

        }

    for (int i = 0; i < adj[curr].size(); i++){
        if (adj[curr][i] != par) { dfs2(adj[curr][i] ,curr);}
    }
}


int lca(int p, int q) {
    if (level[p] < level[q])
        swap(p, q);
    for (int i = lognodes; i >= 0; i--)
        if (level[p] - (1 << i) >= level[q])
            p = A[p][i];

    if (p == q)
        return p;
    for (int i = lognodes; i >= 0; i--)
        if (A[p][i] != -1 && A[p][i] != A[q][i]) {
            p = A[p][i];
            q = A[q][i];
        }
    return A[p][0];

}
int patl(int lvl,int node){
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
    freopen("cube.txt", "r", stdin);
    int nodes = readint();
    int m = readint();
    vector<pii > query;
    for (int i = 0; i < nodes - 1; i++) {
        int x = readint(), y = readint();
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    for (int i = 0; i < m; i++) {
        int x = readint(), y = readint();
        query.push_back({x - 1, y - 1});
    }

    dfs();
   dfs2();
    lognodes = lb(nodes);
    for (int j = 1; j <= lognodes; j++)
        for (int i = 0; i < nodes; i++)
            if (A[i][j - 1] != -1)
                A[i][j] = A[A[i][j - 1]][j - 1];
            else
                A[i][j] = -1;

    double prob =0;
    for(int i=0;i<m;i++){
     int n1 = query[i].first,n2 = query[i].second;
        int lc = lca(n1,n2);
        ll sum1=0,sum2=0,node1=0,node2=0;
        int distab = abs(level[lc]-level[n1])+abs(level[lc]-level[n2]);
        if(lc==n1 || lc==n2){
            int child,par;
            if(level[n1]<level[n2]){
            par = n1,child=n2;
            }else{
                par = n2,child=n1;
            }
            //above parent
            node1+=dprnode[par];
            sum1 +=dprdist[par];
            //below child
            node2=dpnode[child];
            sum2=dpdist[child];
            ////other child of par
            int c = patl(level[par]+1,child);
            node1+=dpnode[par]-dpnode[c];
            sum1+=dpdist[par]-dpdist[c]-dpnode[c];

        }else{
            sum1 = dpdist[n1];
            sum2 = dpdist[n2];
            node1 = dpnode[n1];
            node2=dpnode[n2];
        }
        ll ans = node2*node1;
        ans+=node2*node1*distab;
        ans+=sum1*node2;
        ans+=node1*sum2;
        prob = ans/((1.000)*node2*node1);
        printf("%.9f\n",prob);

    }

    return 0;
}

