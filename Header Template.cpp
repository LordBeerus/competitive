#define DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(b) b.begin() , b.end()
int sig(double x) { return abs(x) < 1e-9 ? 0 : (x > 0 ? 1 : -1); }
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
#ifdef DEBUG
#define maxn 17
#else
#define maxn 100000
#endif
#define maxlg 20
#define pi 3.141592653589793238
#define mod 1000000007
#define inf 1000000007
#define eps 0.00000001
int n,m,k,q;


int main() {
#ifdef DEBUG
 freopen("cube.txt", "r", stdin);
#endif

#ifdef DEBUG
    printf("Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
};
