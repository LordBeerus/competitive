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
#define MAXN 504
#define  MOD 1000000007
#define MAXLG 18
#define EPS 0.00000001
#define endl '\n'
ll dp[MAXN][MAXN];
char grid[MAXN][MAXN];
int n, m;

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
    //freopen("cube.txt", "r", stdin);
    n=readint(),m=readint();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
        cin>>grid[i][j];
        }
    int mid, x1, y1, x2, y2;
    if ((n + m-1) & 1) {//odd
        mid = (n + m - 1) / 2 + 1;
    } else {//even
        mid = (n + m - 1) / 2;
    }
    x1 = (mid <= ::m) ? mid : ::m;
    y1 = (mid <= ::m) ? 1 : (1 + mid - ::m);

    for (int d = 0; x1 - d > 0 && y1 + d < n + 1; d++) {
        if ((n + m-1) & 1)
            dp[x1 - d][x1 - d] = 1;
        else {
            if (x1 - d + 1 <=m && grid[y1 + d][x1 - d] == grid[y1 + d][x1 - d + 1])
                dp[x1 - d][x1 - d + 1] = 1;

            if (y1 + d + 1 <= n && grid[y1 + d][x1 - d] == grid[y1 + d + 1][x1 - d])
                dp[x1 - d][x1 - d ] = 1;
        }
    }
    int t[m+1][m+1];

    for (int m = mid - 1; m > 0; m--) {
        y1 = 1;

      fill(&t[0][0],&t[0][0] + (::m+1)*(::m+1),0);
        for (x1 = m; x1 > 0 && y1 <=n ; x1--, y1++) {
            if (x1 >::m)
                continue;
            else {
                y2 = n;
                for (x2 = ::m - m + 1; x2 <= ::m && y2 >= 0; x2++, y2--) {
                    if (x2 < 1)continue;
                    else {
                        if(x1<=x2 && y1<=y2 && grid[y1][x1]==grid[y2][x2]){


                         int temp=0;
                            if(x1+1<=::m && y2-1>=0)
                            {  temp+=dp[x1+1][x2];if(temp>MOD)temp-=MOD;}
                            if(y1+1<=n && y2-1>=0)
                            { temp +=dp[x1][x2];if(temp>MOD)temp-=MOD;}
                            if(y1+1<=n && x2-1>=0)
                            {temp +=dp[x1][x2-1];if(temp>MOD)temp-=MOD;}
                            if(x1+1<=::m && x2-1>=0)
                            { temp +=dp[x1+1][x2-1];if(temp>MOD)temp-=MOD;}

                            t[x1][x2]=temp;
                        }
                    }

                }

            }


        }
        for(int i=1;i<=::m;i++)
            for(int j=1;j<=::m;j++)
                dp[i][j]=t[i][j];

    }
    cout<<dp[1][m]%MOD;
    return 0;
};
