//http://codeforces.com/contest/319/problem/C
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

struct line{ull m ;
ull c;};
vector<line> lines;
int height[MAXN],cost[MAXN];ull dp[MAXN];
void add(line l){
    line l1 = l;
    if(lines.size()<2)
        lines.push_back(l1);
    else
    {
        lines.push_back(l1);
        while(lines.size()>=3){
           line l2=lines[lines.size()-2],l3=lines[lines.size()-3];
           if((l1.c-l3.c)*(double)(l3.m-l2.m)   < (l2.c-l3.c)*(double)(l3.m-l1.m) )
               lines.erase(lines.end()-2);
           else break;


        }


    }
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
int q;
ull ans(int X){
    line l1 , l2;
    while(lines.size() >q+1 && ((ull)(X*(lines[q].m - lines[q +1].m)))>((ull)(lines[q+1].c - lines[q].c)) )
    {  q++;


    }
    if(lines.size()<=q )
        q= lines.size()-1;

    ull a =(lines[q].m* X);
    return (ull)(a+ lines[q].c);
}

int main() {
    int N,q=0;
    freopen("cube.txt", "r", stdin);
    N = readint();
    for(int i=0;i<N;i++)height[i]=readint();
    for(int i=0;i<N;i++)cost[i]=readint();
    add({height[N-1],0});
    dp[N-1]=0;
    for(int i =N-2;i>=0;i--){
    dp[i]=ans(cost[i]);
    add({height[i],dp[i]});

    }

    cout<<dp[0];

    return 0;
}
