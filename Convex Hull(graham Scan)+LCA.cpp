#include <bits/stdc++.h>
using namespace std;
#define all(b) b.begin() , b.end()
template<class T>
int size(const T &x) { return x.size(); }
#define rep(i, a, b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define turnOff(k, i) (k&(~(1<<(i-1))))
#define pll pair<long long int , long long int>
#define ull unsigned long long int
#define ll  long long int
#define MAXN 100006
#define MOD 1000000007
#define INF 1000000007
#define MAXLG 18
#define EPS 0.00000001
vii teams;
vector<pll> hill;
int n , m;
vi adj[MAXN];
bool visited[MAXN];
int A[MAXN][MAXLG],level[MAXN];
ll ccw(pll p1,pll  p2,pll p3){return
            (p2.first - p1.first)*(p3.second - p1.second) - (p2.second - p1.second)*(p3.first - p1.first);}
int dfs(int curr = 0, int par = -1, int lvl = 0) {
    A[curr][0] = par;
    visited[curr]=true;
    level[curr] = lvl;
    for(auto nxt : adj[curr])
        if(!visited[nxt])
            dfs(nxt,curr,lvl+1);

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
int main() {
     scanf("%d",&n);
    for(int i=0;i<n;i++){
        pll t;
        scanf("%I64D%I64D",&t.first,&t.second);
        hill.push_back(t);
    }
    reverse(all(hill));
    hill.push_back(hill[0]);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        ii t;
        scanf("%d%d",&t.first,&t.second);
       t.first = n-t.first ;
        t.second = n-t.second ;
        teams.push_back(t);
    }

    stack<pair<pll,int>> stk;

        stk.push({hill[0],0});
        stk.push({hill[1],1});
        for(int i=2;i<hill.size(); ){
            pair<pll,int> sec= stk.top();
            stk.pop();
            pair<pll,int> first =stk.top()  ;
            stk.pop();
            stk.push( first );
            stk.push(sec);
            while(ccw(first.first,sec.first,hill[i])< 0){
                if(stk.size()<=2)
                {   int x = first.second;
                    int y = sec.second;
                    adj[x].push_back(y);
                    adj[y].push_back(x);
                    stk.pop();
                    stk.push({hill[i],i});
                    sec = stk.top();

                    i++;

                }
                else if(i+1==hill.size()){
                    int x = first.second;
                    int y = sec.second;
                    adj[x].push_back(y);
                    adj[y].push_back(x);
                    break;
                }else{
                    int x = first.second;
                    int y = sec.second;
                    adj[x].push_back(y);
                    adj[y].push_back(x);

                    stk.pop();

                    sec= stk.top();
                    stk.pop();
                     first =stk.top()  ;
                    stk.pop();
                    stk.push( first );
                    stk.push(sec);


                }

            }int x = first.second;
            int y = sec.second;
            adj[x].push_back(y);
            adj[y].push_back(x);
            stk.push({hill[i],i});
            i++;

        }
dfs();
     for (int j = 1; j <= ceil(log2(n)); j++)
        for (int i = 0; i < n; i++)
            if (A[i][j - 1] != -1)
                A[i][j] = A[A[i][j - 1]][j - 1];
            else
                A[i][j] = -1;


    for(int i=0;i<m;i++){
        printf("%d\n",n-lca(teams[i].first, teams[i].second));
    }
    return 0;
};
