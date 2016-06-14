#include <bits/stdc++.h>
#include<set>

using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define pll pair<long long int , long long int>
#define ull unsigned long long int
#define ll  long long int
#define MAXN 500
#define MOD 1000000007
#define MAXLG 18
#define EPS 0.00000001
#define endl '\n'
struct num {
    ll val, pos;

 };

bool cmp(num a, num b) {
    return (a.val == b.val) ? a.pos < b.pos : a.val < b.val;
}
struct classcomp {
    bool operator() (const num& a, const num& b) const
    {    return (a.val == b.val) ? a.pos < b.pos : a.val < b.val;
    }
};
int main() {
    freopen("cube.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    int SQRT = sqrt(n);
    int BLKS = ((n * 1.0) / SQRT) + 1;
    ll overlay[BLKS];
    fill(overlay, overlay + BLKS, 0);
    set<num ,classcomp> blocks[BLKS];
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        int b = i / SQRT;
        blocks[b].insert({t, i});

    }

    while (m--) {
        int tp;
        scanf("%d",&tp);

        if (tp == 1) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            l--,r--;
            int start = l / BLKS, end = r / BLKS;
            int at = l, done = 0;
            for (int i = start; i <= end; i++) {
                if (at == SQRT * i && r >= (at+SQRT-1))
                    overlay[i] += x, at += SQRT;
                else {
                    vector<set<num>::iterator>add;
                    if (l >= start * SQRT && i == start) {
                        int lo = l, hi = min(r,  start*SQRT+SQRT-1);
                        for (set<num>::iterator it = blocks[start].begin(); it != blocks[start].end(); it++) {
                            if (it->pos >= lo && it->pos <= hi) {
                              add.push_back(it);
                            }
                        }

                        for(int a=0;a<add.size();i++)
                        {
                            blocks[start].insert({add[i]->val+x,add[i]->pos});
                            blocks[start].erase(add[i]);
                        }


                    }
                    if (i == end && start != end) {//do r
                        int lo = end * SQRT, hi = r;
                        vector<set<num>::iterator>add;
                        for (set<num>::iterator it = blocks[start].begin(); it != blocks[start].end(); it++) {
                            if (it->pos >= lo && it->pos <= hi) {
                                add.push_back(it);
                            }
                        }

                        for(int a=0;a<add.size();i++)
                        {
                            blocks[start].insert({add[i]->val+x,add[i]->pos});
                            blocks[start].erase(add[i]);
                        }

                    }


                }


            }
        } else {


        }

    }
    return 0;
};
