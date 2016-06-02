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
#define MAXN 100
#define  MOD 1000000007
#define MAXLG 18
#define EPS 0.00000001
#define endl '\n'

vi adj[MAXN], preord, asub[MAXN];;
int level[MAXN], tchild[MAXN], A[MAXN][MAXLG], ANS = 0;
int pip[MAXN];
int n, m;
bool part[MAXN];
int dp[MAXN];
ull S=0;
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

void preorder(int curr = 0, int lvl = 0, int par = -1) {
    preord.push_back(curr);
    A[curr][0] = par;

    level[curr] = lvl;
    for (auto i : adj[curr]) {
        S++;
        if (i != par)
            preorder(i, lvl + 1, curr);
    }
    for (auto i : adj[curr]) {
        if (i != par)
            tchild[curr] += 1 + tchild[i];
        S++;
    }
}

int lca(int p, int q) {
    if (level[p] < level[q])
        swap(p, q);

    for (int i = MAXLG - 1; i >= 0; i--)
        if (level[p] - (1 << i) >= level[q])
            p = A[p][i],S++;

    if (p == q)
        return p;
    for (int i = MAXLG - 1; i >= 0; i--)
        if (A[p][i] != -1 && A[p][i] != A[q][i]) {
            p = A[p][i];S++;
            q = A[q][i];
        }
    return A[p][0];

}

void DP(int curr, vi *asub) {
    int att = 0;
    dp[curr]=0;
    for (auto i : asub[curr]) {
        DP(i, asub);
        att += dp[i];
        S+=2;
        dp[i]=0;
    }
    if (part[curr]) {
        dp[curr] = 1;
        ANS += att;

    } else {//not part

        if (att < 2)
            dp[curr] = att;
        else
            ANS += min(att, 1);


    }
part[curr]=false;
asub[curr].erase(asub[curr].begin(),asub[curr].end());
}

int main() {
    freopen("cube.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x = readint(), y = readint();
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    preorder();
    for (int i = 0; i < n; i++)
        pip[preord[i]] = i;

    int lognodes = ceil(log2(n));
    for (int j = 1; j <= lognodes; j++)
        for (int i = 0; i < n; i++)
            if (A[i][j - 1] != -1)
                A[i][j] = A[A[i][j - 1]][j - 1];
            else
                A[i][j] = -1;
    m = readint();
    vi asub[n];
    while (m--) {

        vi verts;
        int num = readint();
        for (int i = 0; i < num; i++)
            verts.push_back(readint() - 1);

        vector<pii > sorted;
        set<pii > fin;
        for (int i = 0; i < verts.size(); i++) {
            sorted.push_back({pip[verts[i]], verts[i]})
                    , fin.insert({pip[verts[i]], verts[i]});
            part[verts[i]] = true;
            S++;
        }

        sort(sorted.begin(), sorted.end());
        bool abort = false;
        for (int i = 0; i < sorted.size(); i++)
            if (part[A[sorted[i].second][0]]) {
                cout << -1 << endl;
                abort = true;
                break;
                S++;
            }

        if (abort){
            for (int i = 0; i < sorted.size(); i++) {
                part[sorted[i].second]=false;
            }

            continue;}


        for (int i = 1; i < sorted.size(); i++) {
            S++;
            int lc = (lca(sorted[i - 1].second, sorted[i].second));

            fin.insert({pip[lc], lc});
        }

        stack<int> stk;
//use this to create tree using only lca of vertices
        for (const pair<int, int> nxt:fin) {
            pii cur = nxt;
            S++;
            while (!stk.empty()) {
                if (pip[stk.top()] + tchild[stk.top()] >= pip[cur.second]) {
                    asub[stk.top()].push_back(cur.second);

                    break;
                } else {
                    stk.pop();
                }
            }
            stk.push(cur.second);


        }

        ANS = 0;


        DP(fin.begin()->second, asub);
         dp[fin.begin()->second]=0;
        printf("%d\n", ANS);


    }


    return 0;
};

