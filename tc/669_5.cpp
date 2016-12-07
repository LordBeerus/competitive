#define DEBUG
#define PROB AquaParks

#include <bits/stdc++.h>

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

struct matrix {
    int row, col;
    ll mat[100][100];
    int mod;

    matrix(int r, int c, bool identity = false, int mod = MOD) {//identity matrix
        row = r;
        col = c;
        this->mod = mod;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (i == j && identity)mat[i][j] = 1;
                else mat[i][j] = 0;

            }
    }

    matrix  operator*(matrix &o) {
        matrix ans = matrix(this->row, o.col);
        for (int i = 0; i < this->row; i++)
            for (int j = 0; j < o.col; j++) {
                ans.mat[i][j] = 0;
                for (int z = 0; z < this->col; z++)
                    ans.mat[i][j] = (ans.mat[i][j] + 1ll * mat[i][z] * o.mat[z][j]) % mod;
            }

        return ans;
    }

    matrix  operator+(matrix &o) {
        matrix ans = matrix(this->row, this->col);
        for (int i = 0; i < this->row; i++)
            for (int j = 0; j < o.col; j++) {
                ans.mat[i][j] = (this->mat[i][j] + o.mat[i][j]) % mod;
            }

        return ans;
    }


    void show() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                printf("%lld ", mat[i][j]);
            printf("\n");
        }
        cout << "\n";
    }

    void operator=(const matrix &o) {

        for (int i = 0; i < o.row; i++)
            for (int j = 0; j < col; j++)
                this->mat[i][j] = o.mat[i][j];
    }
};


matrix power(matrix mat, int n) {
    if (n == 0) {
        int row = mat.row;
        int col = mat.col;
        matrix temp(row, col, true);
        return temp;
    }
    if (n % 2 == 0) {
        matrix temp = power(mat, n / 2);
        return temp * temp;
    }
    else {
        matrix ans = power(mat, n - 1);
        return mat * ans;
    }

}

class PROB {
public:
    long mod_pow(long x, long y)
    {
        long res = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                res = (res * x) % MOD;
            }
            x = (x * x) % MOD;
            y /= 2;
        }
        return res;
    }
    long dp[201][201];
    int maxcost;
    int f(int N, int L) {
        long &res = dp[N][L];
        if (res == -1) {
            if (N <=1) {
                res= 1;

            }
            else if (N <= 2) {
                res= L;
            }
            else if(L==0){
                res= 0;
            }
            else{
            res=f(N,L-1);
                for(int i=0;i+1<N;i++){
                    long p = f(i+1,L-1)%MOD;
                    long q = f(N-i-1,L)%MOD;
                    long r = mod_pow( maxcost - L + 1, (i+1) * (N - i - 1) - 1 );
                    res += ( ( (p*q) % MOD ) * r) % MOD;
                }
            }
        }
        res= res%MOD;
        return res;
    }

    int count(int N, int L) {
        maxcost=L;
        memset(dp,-1,sizeof(dp));
        long res = f(N,L);
        for(int i=3;i<=N;i++){
            res = (res*i)%MOD;
        }
    return (int)res;
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef DEBUG
    freopen("cube.txt", "r", stdin);
#endif
    PROB temp;
    cout << temp.count(
            8,
    41
    );

    return 0;
};
