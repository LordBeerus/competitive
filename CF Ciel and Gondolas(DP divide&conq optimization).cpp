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
#define ii pair<int,int>
#define ull unsigned long long int
#define ll  long long int
#define MAXN 4003
#define MAXLG 16
#define EPS 1e-8
#define K 809
int opt[K][MAXN];
int dp[K][MAXN];
int fam[MAXN][MAXN];


int cum(int i ,int j){
    int ans = fam[j][j];
    if((i-1)>=0)
        ans+=fam[i-1][i-1];
    if((i-1)>=0)
        ans-=fam[j][i-1];
    if((i-1)>=0)
        ans-=fam[i-1][j];


    return  ans;}
void options(int k,int L , int R , int optl,int optr){
    if(L>R)
        return;
    int M = (L+R)>>1;

    for(int i = max(M,optl);i<=optr;i++){
        if(dp[k][M]>(dp[k-1][i+1]+cum(M,i))){
            dp[k][M]=(dp[k-1][i+1]+cum(M,i));
            opt[k][M]=i;
        }



    }
    if(L==R)
        return;

    options(k,L,M-1,optl,opt[k][M]);
    options(k,M+1,R,opt[k][M],optr);
}
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
int main() {
    int N,gon;
    freopen("cube.txt", "r", stdin);
   N=readint();
    gon=readint();

    fill(&dp[0][0],&dp[0][0] + MAXN*K,INT32_MAX);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
           (fam[i][j]=readint()) ;


    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){

            if((i-1)>=0)
                fam[i][j]+=fam[i-1][j];
            if((j-1)>=0)
                fam[i][j]+=fam[i][j-1];
            if((j-1)>=0 && (i-1)>=0)
                fam[i][j]-=fam[i-1][j-1];

        }

    for(int i=0;i<=N-1;i++){
        dp[0][i] = cum(i,N-1);
    }

    for(int k=1;k<=gon-1;k++){
        dp[k-1][N]=0;
        options(k,0,N-1,0,N-1);
    }

printf("%d",dp[gon-1][0]/2);


    return 0;
}
