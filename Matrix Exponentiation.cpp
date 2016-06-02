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
#define MAXN 1000010
#define  MOD 1000000007
#define MAXLG 18
#define EPS 0.00000001
#define endl '\n'

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

struct matrix{
    int row,col;
   ll mat[100][100];
int mod;
    matrix(int r,int c,int mod=MOD){
        row= r;
        col = c;
        this->mod = mod;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                mat[i][j]=0;
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


    void show(){
        for(int i=0;i<row;i++) {
            for (int j = 0; j < col; j++)
              printf("%lld ", mat[i][j]);
        printf("\n");
        }
    }

    void operator=(const matrix &o){

        for(int i=0;i<o.row;i++)
            for(int j=0;j<col;j++)
                this->mat[i][j]=o.mat[i][j];
    }
};
int cnt[10];

int main() {
    freopen("cube.txt", "r", stdin);
    int n=readint(),b=readint(),k=readint(),x=readint();
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=readint(),cnt[arr[i]]++;
    matrix f(x,1);
    f.mat[0][0]=1;
     matrix X(x,x);
    for(int i=0;i<x;i++)
        for(int j=0;j<10;j++ )
        {  X.mat[ (i*10 +j)%x][i]+=cnt[j];
                X.mat[ (i*10 +j)%x][i]%=MOD;
        }

int ad;

    while (b) {
        if (b % 2 == 1) f=(X*f);

        X =X*X;
        b /= 2;
    }

cout<<f.mat[k][0];
    return 0;
};

