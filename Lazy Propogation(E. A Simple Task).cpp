#include <bits/stdc++.h>

template<class T>
int size(const T &x) { return x.size(); }
#define rep(i, a, b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define pll pair<long long int , long long int>
#define ull unsigned long long int
#define ll  long long int
#define MAXN 12
#define MOD 1000000007
#define MAXLG 18
#define EPS 0.00000001
#define endl '\n'
int node[4*MAXN][26],n;
int ans[26];
int readint() {
    register char cc = getchar();
    while (cc < '0' || cc > '9') {
        cc = getchar();
    }

    int ans = 0;
    while (cc >= '0' && cc <= '9') {
        ans = ans * 10 + cc - '0';
        cc = getchar();
    }

    return ans;
};
void add(int pos,char c , int nd = 1 , int l= 1 ,int r = n){
    if(l==r){
        node[nd][c-'a']=1;return ;
    }
    int mid = (l+r)>>1;
    if(pos<=mid)add(pos,c,nd<<1,l,mid);
    else add(pos,c,(nd<<1)+1,mid+1,r);
    for(int i=0;i<25;i++)
        node[nd][i]=node[(nd<<1)][i]+node[(nd<<1)+1][i];
}
void query(int L ,int R , int nd =1,int l=1,int r=n){
    if(l>=L && r<=R)
    {
        for(int i=0;i<25;i++)ans[i]+=node[nd][i];
    }
    int mid = (l+r)>>1;
    if(L<=mid)query(L,R,nd<<1,l,mid);
    if(R>mid)query(L,R,(nd<<1)+1,mid+1,r);

 }
int main() {
    freopen("cube.txt", "r", stdin);
    int q;
    n=readint(),q=readint();
    string s;
    for(int i=0;i<n;i++)
       s.push_back(getchar()),add(i+1,s[i]);

    while(q--){
        for(int i=0;i<26;i++)ans[i]=0;
        int l = readint();
        int r = readint();
        int type = readint();
        for(int i=1;i<l;i++)
           putchar(s[i-1]);
        query(l,r);
        if(type==1){
        for(int i = 0;i<26;i++){
            char c = 'a'+i;
            for(int j=0;j<ans[i];j++)
                putchar(c);
        }
        }else{
            for(int i = 25;i>=0;i--){
                char c = 'a'+i;
                for(int j=0;j<ans[i];j++)
                    putchar(c);
            }
        }
        for(int i=r+1;i<n+1;i++)
            putchar(s[i-1]);

    putchar('\n');
    }
    return 0;
};

