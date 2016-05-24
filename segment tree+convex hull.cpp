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
#define MAXN 100200
#define MAXLG 16
#define EPS 1e-8
#define K 8
struct line{ll m , c , id;};
vector<line> l[(4*MAXN)];
vector<line> arr;
int q[4*MAXN];

pair<ull,ull> ans[MAXN];
struct Q{int l , r , t , i;};
vector<Q> Qs;
void addline(int id ,  ll m , ll c,int i){

    line l1 = {m,c,i},l2,l3;
    while(l[id].size()>=2){
        l2 = l[id][l[id].size()-1];
        l3 = l[id][l[id].size()-2];
        if((l1.c-l2.c)*(l3.m-l2.m)  > (l2.c-l3.c)*(l2.m-l1.m))
            l[id].erase(l[id].end()-1);
        else
            break;

    }
    if(l[id].size()>0 && l[id][l[id].size()-1].m == l1.m  && l[id][l[id].size()-1].c<=l1.c )
        l[id].erase(l[id].end()-1);
    l[id].push_back(l1);


}

pair<ull,int> query(int id,int X){

    try {
        int lastid = l[id].size() - 1;
        while ((q[id] + 1) <= lastid &&
               (X)*l[id][q[id]+1].m+ l[id][q[id]+1].c  >=X*l[id][q[id]].m+ l[id][q[id]].c )
            q[id]++;

        if(q[id] > lastid)
            q[id] = lastid;


    }catch(std::runtime_error& e  ){
        cout<<"Q "<<id<<" "<<X<<e.what()<<"\n";
    }
    return {l[id][q[id]].m*X +l[id][q[id]].c,l[id][q[id]].id};
}

void merge(int l,int m1,int m2,int r){
    int start = l;
    vector<line> aux(r-l+1);
    int ins = 0;
    while(l<=m1 && m2<=r){
        if(arr[l].m < arr[m2].m)
        {
            aux[ins] = arr[l];l++;
        }
        else{
            aux[ins] = arr[m2];m2++;
        }
        ins++;

    }

    if(l>m1){
        while(m2<=r){
            aux[ins] = arr[m2];m2++;ins++;
        }
    }
    if(m2>r){
        while(l<=m1){
            aux[ins] = arr[l];l++;ins++;
        }
    }
    for(int i = 0;i<aux.size();i++)
        arr[start+i] = aux[i];


}
void tree(int node=1,int l= 0 , int r = arr.size()-1){
    if(l==r)
    {
        addline(node, arr[l].m, arr[l].c,arr[l].id);
        return;
    }
    try {
        int mid = ((l + r) >> 1);
        tree(node << 1, l, mid);
        tree((node << 1) + 1, mid + 1, r);

        merge(l, mid, mid + 1, r);
        for (int i = r; i >= l; i--)
            addline(node, arr[i].m, arr[i].c, arr[i].id);
    }catch(exception e){

    }
}
pair<ll,ll> qtree(int L ,int R , int X ,int node=1 , int l = 0,int r=arr.size()-1){

    try{
        if(L<=l && R>=r)
            return query(node,X);

        int mid = (l+r)>>1;
        ull m =0,i=0;
        if(L<=mid) {
            pll ans =  qtree(L, R, X, node << 1, l, mid);
            if (m < ans.first)
            {
                m=ans.first;
                i = ans.second;
            }
        }

        if(R>mid) {
            pll ans = qtree(L, R, X, (node << 1) + 1, mid + 1, r);
            if(m<ans.first){
                m=ans.first;
                i = ans.second;
            }
        }
        return {m,i};
    }catch(std::runtime_error& e){
        cout<<"Q "<<l<<" "<<r<<" "<<X<<e.what()<<"\n";
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



bool comp(Q a , Q b){
    if(a.t>b.t)return true;
    return false;
}

void signalHandler( int signum )
{
    cout << "Interrupt signal (" << signum << ") received.\n";

    // cleanup and close up stuff here
    // terminate program

    exit(signum);

}
int main() {
    try {
        signal(SIGSEGV, signalHandler);

        signal(SIGFPE, signalHandler);
        int n, q = 0, m, c, l, t, r;
        bool check = false;
        freopen("cube.txt", "r", stdin);
        n = readint(), q = readint();

        for (int i = 0; i < n; i++) {
            c = readint(), m = readint();
            arr.push_back({m, c, i + 1});

        }


        for (int i = 0; i < q; i++) {
            l = readint(), r = readint(), t = readint();
            Qs.push_back({l, r, t, i});
        }

        sort(Qs.begin(), Qs.end(), comp);

        tree();
        try{
            for (int i = 0; i < q; i++)
                ans[Qs[i].i] = qtree(Qs[i].l - 1, Qs[i].r - 1, Qs[i].t);

            for (int i = 0; i < q; i++)
                cout << ans[i].second << "\n";}catch (std::runtime_error& e){
            cout<<e.what();}

    }catch (std::runtime_error& e){
        cout<<e.what();
    }
}
