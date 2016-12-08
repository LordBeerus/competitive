#define DEBUG
#define PROB Treestrat

#include <bits/stdc++.h>

using namespace std;
#define all(b) b.begin() , b.end()
#define mp(a, b) make_pair(a,b)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define turnOff(k, i) (k&(~(1<<(i-1))))
#define pll pair<long long int , long long int>
#define ull unsigned long long int
#define ll  long long int
#ifdef DEBUG
#define maxn 4
#else
#define maxn 300020
#endif
#define maxlg 20
#define endl '\n'
//#define pi 3.141592653589793238
#define MOD 1000000007
#define inf 1000000007
#define eps 0.00000001




class PROB {
public:
    int dp[50][50];
    int distFromBlue[50];
    vi adj[50];
    int f(int vert , int t , int par = -1){
        int & result = dp[vert][t];

        if(result==-1){
            int fromRed = distFromBlue[vert]-t;
            if(fromRed<=0){
               result= 0;
            }else{
                result =1;
                result = max(result,f(vert,t+1,par)+1);
                for(int nxt:adj[vert]){
                    if(nxt!=par){
                      result = max(f(nxt,t+1,vert)+1,result);
                    }
                }

            }
        }

        return result;
    }



    int roundcnt(vi tree, vi A, vi B){
        for(int i=0;i<tree.size();i++){
            int v1 = i+1;
            int v2 = tree[i];
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        memset(distFromBlue,-1,sizeof(distFromBlue));
        memset(dp,-1,sizeof(dp));

        bool done[50];
        memset(done,false, sizeof(done));
        queue<int> Q;
        for(int i=0;i<B.size();i++){
            distFromBlue[B[i]]=0;
            Q.push(B[i]);
            done[B[i]]=true;

        }
        while(!Q.empty()){
            int v = Q.front();
            Q.pop();
            for(int nxt : adj[v]){
                if(!done[nxt]){
                    distFromBlue[nxt] = distFromBlue[v]+1;
                    Q.push(nxt);
                    done[nxt]=true;
                }
            }

        }
        int res=-1;
        for(int i=0;i<A.size();i++){
            res = max(res,f(A[i],0,-1));

        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef DEBUG
    freopen("cube.txt", "r", stdin);
#endif
    PROB temp;
    vi a = {0,0,0,3,4,2};
    vi b ={1};
    vi c = {6};
    cout<<temp.roundcnt(a,b,c);

    return 0;
};
