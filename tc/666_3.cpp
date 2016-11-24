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
    int K;
    vii interval;
    matrix evenMat(int n){
        matrix even(2*(K+1),2*(K+1));
        for(int i=0;i<K+1;i++){
            even.mat[i][0]=1;
            even.mat[i+K+1][K+1]=1;

        }
        for(int i=0;i<K;i++){
            even.mat[i][K+2+i]=1;
            even.mat[i+K+1][i+1]=1;

        }
        even.show();
        even = power(even,n);
        matrix ans(K+1,K+1);
        for(int i=0;i<K+1;i++){
            for(int j=0;j<K+1;j++)
            ans.mat[i][j]=even.mat[i][j];
        }
        ans.show();



        return ans;
    }
    matrix oddMat(int n){
        matrix even(2*(K+1),2*(K+1));
        for(int i=0;i<K+1;i++){
            even.mat[i][0]=1;
            even.mat[i+K+1][K+1]=1;

        }
        for(int i=0;i<K;i++){
            even.mat[i][K+2+i]=1;
            even.mat[i+K+1][i+1]=1;

        }
        even = power(even,n);
        even.show();
        matrix ans(K+1,K+1);
        for(int i=0;i<K+1;i++){
            for(int j=0;j<K+1;j++)
                ans.mat[i][j]=even.mat[i][j+K+1];
        }
        ans.show();


        return ans;
    }
    matrix fx(int i,bool both=  false){
        int l = interval[i].first,r=interval[i].second;
        vector<pair<ii,int>> inter;
        int left = l;
        for(int k=0;k<interval.size();k++){
            if(interval[k].first>=left){
                int useless = interval[k].first-left;
                if(useless!=0){
                    inter.push_back({{left,interval[k].first} ,-1}) ;
                }
                left = interval[k].second;
                inter.push_back({{interval[k].first,interval[k].second} ,k}) ;

            }

        }
        if(left!=interval[i].second){
            inter.push_back({{left,interval[i].second} ,-1}) ;

        }
        matrix old_even(K+1,K+1),old_odd(K+1,K+1);
        matrix new_even(K+1,K+1),new_odd(K+1,K+1);
        for(int i=0;i<inter.size();i++){
            int type = inter[i].second;
            if(type==-1){//dummy
                 int size = inter[i].second-inter[i].first;
                matrix even = evenMat(size);
                matrix odd = oddMat(size);
                new_even = old_odd*odd + old_even*even;
                new_odd = old_odd*even + old_even*odd;
                old_odd = new_odd;
                old_even=new_even;

            }else{//actual
                matrix temp = fx(type);
                new_even =old_even*temp;
                new_odd =old_odd*temp;
                old_odd = new_odd;
                old_even=new_even;

            }

        }
        if(both){
            return old_odd+old_even;
        }else{

            return old_even;
        }


     }
    int countSequences(int n, int k, vi L, vi R){
        K = k;
        for(int i=0;i<L.size();i++){
            interval[i]={L[i],R[i]};
        }
        sort(all(interval));
        matrix ans;
        if(interval[0].first==1 && interval[0].second==n){
            ans = fx(0);
        }else{
            ans=fx(0,true);
        }
        ll  ret = 0;
        for(int i=0;i<k+1;i++){
            ret=(ret+ans.mat[0][i])%MOD;
        }
        return (int)ret%MOD;
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef DEBUG
    freopen("cube.txt", "r", stdin);
#endif
     

    return 0;
};
