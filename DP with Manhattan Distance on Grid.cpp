//http://codeforces.com/contest/348/problem/D
#include <bits/stdc++.h>
#include <complex>
using namespace std;
#define all(b) b.begin() , b.end()
int sig(double x) { return abs(x) < 1e-9 ? 0 : (x > 0 ? 1 : -1); }
typedef long double DOUBLE;
typedef vector<DOUBLE> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
typedef pair<int, int> PII;
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
#define MAXN 100
#define PI 3.141592653589793238
#define MOD 1000000007
#define INF 1000000007
#define MAXLG 20
#define EPS 0.00000001
int n,m,k,q;
ll ab1[MAXN][MAXN],ab2[MAXN][MAXN];
char matrix [MAXN][MAXN];
int main() {
    freopen("cube.txt", "r", stdin);
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=0;i<n;i++)
    {for(int j=0;j<m;j++)
        {matrix[i][j]=getchar();}getchar();}

    ab1[n-2][m-1]=1;
    ab2[n-1][m-2]=1;
    for(int man=1;man<=(n+m-3);man++){
        int bcol = (m-1-man),brow=(n-2);

        while(brow>=0 && bcol<=m-1){
            if(bcol>=0 && matrix[brow][bcol]!='#')
           {
               if(brow+1<=n-1 &&  matrix[brow+1 ][bcol]=='.')
                ab1[brow][bcol]=(ab1[brow][bcol]+ab1[brow+1][bcol])%MOD;

            if(bcol+1<=m+1 &&  matrix[brow ][bcol+1]=='.')
                ab1[brow][bcol]=(ab1[brow][bcol]+ab1[brow][bcol+1])%MOD;}
            brow--,bcol++;
        }
    }
    for(int man=1;man<=(n+m-3);man++){
        int bcol = (m-2-man),brow=(n-1);

            while(brow>=0 && bcol<=m-1){
                if(bcol>=0 && matrix[brow][bcol]!='#')
                {if(brow+1<=n-1 && matrix[brow+1][bcol]=='.')
                    ab2[brow][bcol]=(ab2[brow][bcol]+ab2[brow+1][bcol])%MOD;
                if(bcol+1<=m+1 &&  matrix[brow ][bcol+1]=='.')
                    ab2[brow][bcol]=(ab2[brow][bcol]+ab2[brow][bcol+1])%MOD;}
                brow--,bcol++;
            }
    }
    ll ans =(ab1[0][1]*ab2[1][0]-ab1[1][0]*ab2[0][1])%MOD;
    if(ans < 0)ans+=MOD;

    cout<<(ans)%MOD;
    return 0;
};
