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
int node[4 * MAXN][26], n;
bool lazy[4 * MAXN][29];
int ans[26];
int nodeOf[MAXN];
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

void update(int id ,int c, bool cl , int freq){
    if(cl){
        node[id][c]=0;
    }else{
        node[id][c]=freq;
    }
    lazy[id][c]=true;
}

void shift(int id ,int c,bool cl, int l , int r ){


    lazy[id][c]=false;
    int mid = (l+r)>>1;
    if(node[id][c]!=0)
    { update(id<<1,c,cl,mid-l+1);
    update((id<<1)+1,c,cl,r-(mid));}
    else{
        update(id<<1,c,cl,0);
        update((id<<1)+1,c,cl,0);
    }
}

void change(int L,int R  , int c,bool cl,int id=1,int l=1,int r = n){
    if(l>=L && r<=R)
    {
        update(id,c,cl,r-l+1);return;

    }
    int mid = (l+r)>>1;
    if(lazy[id][c])
        shift(id,c,cl,l,r);
    if(L<=mid)change(L,R,c,cl,id<<1,l,mid);
    if(R>mid)change(L,R,c,cl,(id<<1)+1,mid+1,r);
    node[id][c]= node[(id<<1)][c]+ node[(id<<1)+1][c];


}
void add(int pos, char c, int nd = 1, int l = 1, int r = n) {
    if (l == r) {
        node[nd][c - 'a'] = 1;
        nodeOf[l]=nd;
        return;
    }

    int mid = (l + r) >> 1;
    if (pos <= mid)add(pos, c, nd << 1, l, mid);
    else add(pos, c, (nd << 1) + 1, mid + 1, r);
    for (int i = 0; i < 26; i++)
        node[nd][i] = node[(nd << 1)][i] + node[(nd << 1) + 1][i];
}

void query(int L, int R, int c,int nd = 1, int l = 1, int r = n) {
    if (l >= L && r <= R) {
       ans[c] += node[nd][c];
        return;
    }
    if(lazy[nd][c])
        shift(nd,c,false,l,r);
    int mid = (l + r) >> 1;
    if (L <= mid)query(L, R, c,nd << 1, l, mid);
    if (R > mid)query(L, R,c, (nd << 1) + 1, mid + 1, r);

}

int main() {
    freopen("cube.txt", "r", stdin);
    int q;
    n = readint(), q = readint();
    string s;
    for (int i = 0; i < n; i++)
        s.push_back(getchar()), add(i + 1, s[i]);

    while (q--) {
        for (int i = 0; i < 26; i++)ans[i] = 0;
        int l = readint();
        int r = readint();
        int type = readint();

        for(int i=0;i<26;i++)
            query(l,r,i);


        for(int i=0;i<26;i++)
            if(ans[i]>0)
                change(l,r,i,true);

            if (type == 1) {
            int done = l;
            for (int i = 0; i < 26; i++) {
                if(ans[i]>0)
                change(done,done+ans[i]-1,i,false),done = done+ans[i];

            }
        } else {
            int done = l;
            for (int i = 25; i >= 0; i--) {
                if(ans[i]>0)
                change(done,done+ans[i]-1,i,false),done = done+ans[i];

            }
        }


    }
    for(int i=1;i<=n;i++)
    {
        for (int k = 0; k < 26; k++)ans[k] = 0;

        for(int j=0;j<26;j++)
            query(i,i,j);
        for(int j=0;j<26;j++)
            if(ans[j]==1)
                putchar(j+'a');

    }

    putchar(endl);

    return 0;
};
