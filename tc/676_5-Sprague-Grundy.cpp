#define DEBUG
#define PROB Treestrat

#include <bits/stdc++.h>
#include<unordered_map>
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

    const int MAX= 4;
    int nimber[4][50][50];
    void filln(vector<string> s , int K){
        if(K>MAX)
            K = MAX- K%2;

        memset(nimber,0,sizeof( nimber));
        for(int k=1;k<=K;k++){
            for(int i=0;i<s.size();i++){
                for(int j=0;j<s[0].length();j++){
                    int & res = nimber[k][i][j];
                    set<int> avail;
                    avail.insert(0);
                    avail.insert(1);
                    avail.insert(2);
                    avail.insert(3);
                    if(s[i][j]=='E')
                    {
                        nimber[k][i][j]=0;
                        continue;
                    }

                    if(i-1>=0){
                        if(s[i-1][j]!='#'){
                            avail.erase(nimber[k-1][i-1][j]);
                        }
                    }
                    if(j-1>=0){
                        if(s[i ][j-1]!='#'){
                            avail.erase(nimber[k-1][i][j-1]);
                        }
                    }
                    if(j+1<s[0].length()){
                        if(s[i ][j+1]!='#'){
                            avail.erase(nimber[k-1][i][j+1]);
                        }
                    }
                    if(i+1<s.size()){
                        if(s[i+1 ][j ]!='#'){
                            avail.erase(nimber[k-1][i+1][j ]);
                        }
                    }
                    int  put = *avail.begin();
                    nimber[k][i][j] = put;


                }
            }
        }
    }
    string findWinner(vector<string> s, int k){


        filln(s,k);
        if(k>MAX)
            k = MAX- k%2;
        int sum = 0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s[0].length();j++){
                if(s[i][j]=='T'){
                    sum = sum^nimber[k][i][j];
                }
            }
        }
        if(sum==0)return  "Bob";
        else return "Alice";

    }




};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef DEBUG
    freopen("cube.txt", "r", stdin);
#endif
    PROB temp;
    vector<string> t=

            {"T.T.T.",
             ".E.E.E"};

    cout<<temp.findWinner(t ,1);


    return 0;
};
