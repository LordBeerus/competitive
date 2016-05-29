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
#define MAXN 2005
#define  MOD 1000000007
#define MAXLG 18
#define EPS 1e-8
#define endl '\n'

int segf[4*MAXN],segb[4*MAXN],Lf[4*MAXN],Rf[4*MAXN],Rb[4*MAXN],Lb[4*MAXN];
struct node{int id,h,idf,idr;};
vector<node> b;
vi forw,bck;
vector<pii> query;
int n,m;
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

bool cmp(node a , node b){return a.h<b.h;}

int Frf =0,Rfr=0;
int update(int &FREE,int * tree,int * L ,int * R,int val,int pos,int id , int l=1,int r=n){
    int ID = FREE++;
    if(l==r){
        tree[ID]=val;
        return ID;
    }
    L[ID]=L[id],R[ID]=R[id];
    int mid=(l+r)>>1;
    if(pos<=mid)L[ID]=update(FREE,tree,L,R,val,pos,L[ID],l,mid);
    if(pos>mid)L[ID]=update(FREE,tree,L,R,val,pos,R[ID],mid+1,r);

    tree[ID] = max(tree[L[ID]],tree[R[ID]]);
    return ID;
}
int q(int * tree,int *L ,int * R,int lft,int rt ,int node,int l=1,int r=n){
    if(l==r)return tree[node];
    int mid = (l+r)>>1;
    int mx = 0;
    if(lft<=mid)mx=max(mx,q(tree,L,R,lft,rt,L[node],l,mid));
    if(rt>mid)mx=max(mx,q(tree,L,R,lft,rt,R[node],mid+1,r));

    return mx;
}
int main() {
    freopen("cube.txt", "r", stdin);
    n=readint();
    m=readint();
    for(int i=0;i<n;i++)
        b.push_back({i+1,readint()});
    for(int i=0;i<m;i++)
        query.push_back({readint(),readint()});


    vector<vi> best;//h,pos,size
    for(int j=0;j<n;j++){
   vi item ={b[j].h,0,0};
        auto i = lower_bound(best.begin(),best.end(),item);
        item[1]=j;
        if(i==best.end()){

            item[2]= best.size()==0?1:(best.back()[2]+1);
            best.push_back(item);
        }else{
            item[2] = (*i)[2];//parent change
            *i = item;

        }
        forw.push_back(item[2]);

    }

    best.erase(best.begin(),best.end());
    vi rev;
    for(int j=n-1;j>=0;j--){
        vi item ={-b[j].h,0,0};// adding minus turns inc seq to deq seq
        auto i =lower_bound(best.begin(),best.end(),item);
        item[1]=j;

        if(i==best.end()){

            item[2]= best.size()==0?1:(best.back()[2]+1);
            best.push_back(item);
        }else{

            item[2] = (*i)[2];
            *i = item;

        }
       rev.push_back(item[2]);


    }
    for(int i = rev.size()-1;i>=0;i--)
        bck.push_back(rev[i]);
////////////////////////////////////////////////////////////////////////////
    sort(b.begin(),b.end(),cmp);
for(int i=0;i<n;i++){
    b[i].idf=update(Frf,segf,Lf,Rf,forw[i],b[i].id,i==0?0:b[i-1].idf);
    b[n-i-1].idr = update(Rfr,segb,Lb,Rb,rev[n-i-1],b[i].id,i==(n-i)?0:b[n-1].idf);
}
    for(int i=0;i<query.size();i++){
        int pos = query[i].first;
        int ans=0;

            auto lower = lower_bound(b.begin(), b.end(), query[i].second, cmp);
            if(lower!=b.begin())
                ans+=q(segf,Lf,Rf,1,query[i].second,*(--lower).second,)


    }

    return 0;
};

