#define DEBUG
#define PROB Treestrat

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define all(b) b.begin() , b.end()
#define mp(a, b) make_pair(a,b)
#define vi vector<int>
#define vs vector<string>
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
    int sh=0,hs=0,ss=0,hh=0;
    int groups = 0;
    int f[300];
    int getNumber(vector<string> state){
        f[0]=0;
        f[1]=1;
        f[2]=2;
        for(int i=3;i<=state[0].length();i++){
            f[i] = f[i-2]+1;
        }
        string curr="";
        for(int i=0;i<state[0].length();i++){
            string s1 = state[0],s2=state[1];
            string c2 = s1[i]+""+s2[i];
            if(c2=="ss" ){
                ss++;

            }
            else if(c2=="hh"){
                hh++;
            }
            else if(c2=="sh"){
                sh++;
                if(curr=="hs" || curr==""){
                    groups++;
                    curr="sh";
                }

            }else if(c2=="hs"){
                hs++;
                if(curr=="sh" || curr==""){
                    groups++;
                    curr="hs";
                }
            }
        }
        if(ss==state[0].length())
            return -1;
        else return f[groups] + ss;
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef DEBUG
    freopen("cube.txt", "r", stdin);
#endif
    PROB temp;
    vs t =
            {"HSH",
             "SHS"};


    cout<<temp.getNumber(t);


    return 0;
};
