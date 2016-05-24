//http://codeforces.com/contest/631/problem/E
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
#define MAXN 300000
#define  MOD 1000000007
#define MAXLG 16
#define EPS 1e-8
#define endl '\n'
ll sum[MAXN];
ll a[MAXN];
struct line{ll m,c;};
vector<line> store,l ;
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

bool comp(line a,line b){
    return a.m>b.m;
}
void addline(  line l1 ){
    line l2,l3;

    while(l.size()>=2){
        l2 = l[l.size()-1];
        l3 = l[l.size()-2];
        if((l1.c-l2.c)*(l3.m-l2.m)  > (l2.c-l3.c)*(l2.m-l1.m))
            l.erase(l.end()-1);
        else
            break;

    }
    if(l.size()>0 && l[l.size()-1].m == l1.m  && l[l.size()-1].c<=l1.c )
        l.erase(l.end()-1);
    l.push_back(l1);


}
int q;
ll query( ll X){
int lf = -1,rt=l.size()-1;
    int m = 0;
    while(rt-lf>1){
        int m = (rt+lf)>>1;
        if(l[m].m*X + l[m].c <= l[m+1].m*X + l[m+1].c)
            lf=m;
        else
            rt = m;
    }
    return l[rt].m*X + l[rt].c;
}

int main()
{
    freopen("cube.txt", "r", stdin);
    ll base=0;
    int n=readint();
    for(int i=1;i<=n;i++)
       cin>>a[i],sum[i]=sum[i-1]+a[i],base+=a[i]*i;




    ll mx=0;

    for(int i=n;i>0;i--)
    {
        addline({i,-sum[i]});
        mx = max(query(a[i])-a[i]*i+sum[i],mx);


    }


    l.erase(l.begin(),l.end());





    for(int i=1;i<=n;i++)
    {
        addline({-i,-sum[i-1]});
        mx = max(query(-a[i])-a[i]*i+sum[i-1],mx);}


cout<<base+mx;
    return 0;
}
