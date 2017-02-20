#define DEBUG
#define PROB Treestrat

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define all(b) b.begin() , b.end()
#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define vi vector<int>
#define vd vector<double>
#define vs vector<string>
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define turnOff(k, i) (k&(~(1<<(i-1))))
#define isOn(k, i) (k&&(1<<i-1)?true:false)
#define pll pair<long long int , long long int>
#define ull unsigned long long int
#define ll  long long int
#ifdef  DEBUG
#define MAXN 4
#else
#define MAXN 300020
#endif
#define MAXLG 20
#define endl '\n'
#define PI 3.141592653589793238
#define MOD 1000000007l
#define INF 1000000007l
#define EPS 0.00000001
int N = 6;
int S,H,W;
class PROB {

public :
    

};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef DEBUG
    freopen("cube.txt", "r", stdin);
#endif
    PROB temp;
    vs a =
            {"X.....XXX.XX..XXXXXXXXX...X.XX.XX....X",
             ".XXXX..X..XXXXXXXX....XX.X.X.X.....XXX",
             "....XX....X.XX..X.X...XX.X..XXXXXXX..X",
             "XX.XXXXX.X.X..X..XX.XXX..XX...XXX.X..."};
    cout << temp.find(a);


    return 0;


};
