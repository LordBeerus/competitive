//http://codeforces.com/contest/348/problem/C
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
#define MAXN 100032
#define PI 3.141592653589793238
#define MOD 1000000007
#define INF 1000000007
#define MAXLG 20
#define EPS 0.00000001
int n,m,k,q;
ll arr[MAXN];
int ssize[MAXN];
ll sumHeavy[MAXN];
vi sset[MAXN];
vi inHeavy[MAXN];
ll indHeavy[MAXN];
int common[325][325];
bool done[325][325];
int freq[MAXN][325];
vi heavies;
int main() {
    int SQR = 2;
    freopen("cube.txt", "r", stdin);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",arr+i);
    for(int i=0;i<m;i++){
        int sz,idx;scanf("%d",&sz);
        ssize[i]=sz;
         for(int j=0;j<sz;j++){
            scanf("%d",&idx);

            if(ssize[i]>=SQR)
                sumHeavy[i]+=arr[idx],inHeavy[idx].push_back(i),heavies.push_back(i);
            sset[i].push_back(idx);
        }

    }
    for(int i=0;i<heavies.size();i++)
        sort(all(sset[heavies[i]]));

    for(int i=0;i<heavies.size();i++)
        for(int j=0;j<heavies.size();j++)
            if(i!=j && !done[min(heavies[i],heavies[j])][max(heavies[i],heavies[j])]){
                int f = 0 , s = 0;
                int l1 = heavies[i],l2=heavies[j];
                while(f<ssize[l1] && s<ssize[l2]){
                    if(sset[l1][f]==sset[l2][s])
                        common[l1][l2]++,common[l2][l1]++,f++,s++;
                    else if(sset[l1][f]<sset[l2][s])
                        f++;
                    else
                        s++;


                }
                done[min(l1,l2)][max(l2,l1)]=true;

            }
    
    for(int i=1;i<m;i++){
        if(ssize[i]<SQR)
            for(int j=0;j<ssize[i];j++){
                int idx = sset[i][j];
                for(int k=0;k<inHeavy[idx].size();k++)
                    freq[i][inHeavy[idx][k]]++;
            }


    }

while(q--){
    getchar();
    int c=getchar();
    int k , x;
     if(c=='?'){
    scanf("%d",&k);k--;
        if(ssize[k]>=SQR)printf("%lld\n",sumHeavy[k]);
        else{
            ll ans = 0;
            for(int i=0;i<ssize[k];i++)
                ans+=arr[sset[k][i]];

            for(int i=0;i<heavies.size();i++){
                ans+=indHeavy[heavies[i]]*freq[k][heavies[i]];
            }
            printf("%lld\n",ans);
        }
    }else{
        scanf("%d%d",&k,&x);k--;
        if(ssize[k]>=SQR){
            sumHeavy[k]+=ssize[k]*x;indHeavy[k]+=x;
        for(int i=0;i<heavies.size();i++)
         if(k!=i)   sumHeavy[heavies[i]] += common[k][heavies[i]]*x;


        }
        if(ssize[k]<SQR){
            for(int i=0;i<ssize[k];i++)
                arr[sset[k][i]]+=x;
            for(int i=0;i<heavies.size();i++)
                sumHeavy[heavies[i]]+=freq[k][heavies[i]]*x ;
        }


    }
}
    return 0;
};
