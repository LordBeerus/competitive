#define DEBUG

#include <bits/stdc++.h>

using namespace std;
#define all(b) b.begin() , b.end()
#define rep(i, a, b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define turnOff(k, i) (k&(~(1<<(i-1))))
#define pll pair<long long int , long long int>
#define ull unsigned long long int
#define ll  long long int
#ifdef DEBUG
#define maxn 14
#else
#define maxn 300020
#endif
#define maxlg 20
#define endl '\n'
//#define pi 3.141592653589793238
#define mod 1000000007
#define inf 1000000007
#define eps 0.00000001
const int SUM = 20;
int n, k;
vii adj[maxn];
int size[maxn];
bool exist[maxn];
int cheapest[SUM];
int global[SUM];
set<int> used;
set<int> gUsed;
int K = inf;

void makeSum(int curr, int par, int sum, int depth) {
    if (sum > k)return;
    cheapest[sum] = min(cheapest[sum], depth);
    used.insert(sum);
    gUsed.insert(sum);
    if (cheapest[sum] + global[k - sum] < K)
        K = cheapest[sum] + global[k - sum];
    for (auto nxt : adj[curr])
        if (exist[nxt.first] && nxt.first != par)
            makeSum(nxt.first, curr, sum + nxt.second, depth + 1);


}

void dfs(int curr, int par) {
    size[curr] = 1;
    for (auto nxt :adj[curr])
        if (nxt.first != par && exist[nxt.first]) {
            dfs(nxt.first, curr);
            size[curr] += size[nxt.first];
        }

}


int findCentral(int curr, int par, int src,int &cent) {
    int mega = size[src];
    bool central = true;
    int sz = 1;
    for (auto nxt :adj[curr]) {
        if (nxt.first != par && exist[nxt.first]) {
            if (size[nxt.first] > (mega / 2)) {
                central = false;
                break;
            }
            else
                sz += size[nxt.first];
        }
    }
    if (mega - sz > (mega / 2))
        central = false;
    if (central == true)
    { cent = curr;  return curr;}
    else if(cent==-1)
        for (auto nxt :adj[curr]) {
            if (nxt.first != par && exist[nxt.first]) {
                findCentral(nxt.first, curr, src,cent);
            }

        }}

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
#ifdef DEBUG
        freopen("cube.txt", "r", stdin);
#endif
        fill(exist,exist+maxn,true);
        fill(cheapest, cheapest + SUM, inf);
        fill(global, global + SUM, inf);
        cin >> n >> k;
        for (int i = 0; i < n - 1; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});

        }
        queue<int> roots;
        roots.push(8);
        while (!roots.empty()) {
            int r = roots.front();
            roots.pop();
            dfs(r, -1);
            int c =-1;
            findCentral(r, -1, r,c);
            exist[c]=false;
            int t = 0;
            for (ii nxt : adj[c]) {
                if (exist[nxt.first]) {
                    cheapest[nxt.second]=1;
                    makeSum(nxt.first, c, nxt.second, 1);

                    for (auto i : used) {
                        global[i] = min(cheapest[i], global[i]);
                        cheapest[i] = inf;
                    }

                    roots.push(nxt.first);
                    used.erase(all(used));
                }
            }
            K = min(global[k], K);

            for (auto i : gUsed)
                global[i] =inf;
            gUsed.erase(all(gUsed));
        }




    
    return 0;
};
