#define DEBUG
#define PROB CatsOnTheCircle
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
struct matrix{
    int row,col;
    ll mat[100][100];
    int mod;
    matrix(int r,int c,bool identity = false,int mod=MOD){//identity matrix
        row= r;
        col = c;
        this->mod = mod;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            {   if(i==j && identity)mat[i][j]=1;
                else mat[i][j]=0;

            }
    }

    matrix  operator*(matrix&o){
        matrix ans = matrix(this->row,o.col);
        for(int i=0;i<this->row;i++)
            for(int j=0;j<o.col;j++)
            {   ans.mat[i][j]=0;
                for(int z=0;z<this->col;z++)
                    ans.mat[i][j] =( ans.mat[i][j]+ 1ll*mat[i][z]*o.mat[z][j])%mod;
            }

        return ans;
    }
    matrix  operator+(matrix&o){
        matrix ans = matrix(this->row,this->col);
        for(int i=0;i<this->row;i++)
            for(int j=0;j<o.col;j++)
            {
                ans.mat[i][j] = (this->mat[i][j]+o.mat[i][j])%mod;
             }

        return ans;
    }


    void show(){
        for(int i=0;i<row;i++) {
            for (int j = 0; j < col; j++)
                printf("%lld ", mat[i][j]);
            printf("\n");
        }
        cout<<"\n";
    }

    void operator=(const matrix &o){

        for(int i=0;i<o.row;i++)
            for(int j=0;j<col;j++)
                this->mat[i][j]=o.mat[i][j];
    }
};


matrix power(matrix mat , int n){
    if(n==0){
        int row = mat.row;
        int col = mat.col;
        matrix temp(row,col,true);
        return temp;
    }
    if(n%2==0){
        matrix temp = power(mat,n/2);
        return temp*temp;
    }
    else{
        matrix ans = power(mat,n-1);
        return mat*ans;
    }

}
class PROB{
public:
    double ruin(double p , int n1,double q , int n2){//p loses
        if(p==q){
            return n2/(n1+n2*1.000);
        }
        if(p>q){
            return 1.00 - ruin(q,n2,p,n1);
        }
        else{
            double t = p/q;
            return (1-pow(t,n2))/(1-pow(t,n2+n1));
        }
    }
    double getProb(int N, int K, int p){
        double CLK = p/1e9;
        double ANTI = 1 - CLK;
        int R = N - (K+1);
        int L  = K-1;
        return ruin(CLK,R,ANTI,L)*ruin(ANTI,N-2,CLK,1) + ruin(ANTI,L,CLK,R)*ruin(CLK,N-2,ANTI,1);
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef DEBUG
    freopen("cube.txt", "r", stdin);
#endif
    PROB temp;
     
    return 0;
};
