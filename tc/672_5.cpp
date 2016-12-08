#define DEBUG
#define PROB Treestrat

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define all(b) b.begin() , b.end()
#define mp(a, b) make_pair(a,b)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define turnOff(k, i) (k&(~(1<<(i-1))))
#define pll pair<long long int , long long int>
#define ull unsigned long long int
#define ll  long long int
#ifdef DEBUG
#define maxn 4
#else
#define maxn 300020
#endif
#define maxlg 20
#define endl '\n'
//#define pi 3.141592653589793238
#define MOD 1000000007
#define inf 1000000007
#define eps 0.00000001




class PROB {
public:
    long mod_pow(long x, int y)
    {
        // exponentiation by squaring
        long r = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                r = (r*x) % MOD;
            }
            x = (x*x) % MOD;
            y /= 2;
        }
        return r;
    }
    int calculateGraphs(int n) {
        // Pascal's triangle
        vector<vector<long>> C(n + 1, vector<long>(n + 1));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
        int en = mod_pow(2,((n-1)*(n-2))/2);
        int d[n];
        d[0]=0;
        d[1]=0;
        for(int i=2;i<=n;i++){
            d[i]=0;
            for(int k=1;k<i;k++){
                int ek =  mod_pow(2,((k-1)*(k-2))/2);
                int nk =  mod_pow(2,(((n-k)-1)*((n-k)-2))/2);
                d[i]=(d[i]+C[i-1][k-1]*((ek-d[k]+MOD)%MOD)*nk)%MOD;
            }
        }
        ll res = (((en-d[n]+MOD)%MOD)*(((n*(n-1))/2) +1 ))%MOD;
        return res;















    }


};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef DEBUG
    freopen("cube.txt", "r", stdin);
#endif
    PROB temp;
    vi a = {1,2,3,4,5,6,5,4,3,2,1};

    cout<<temp.a(a );

    return 0;
};
