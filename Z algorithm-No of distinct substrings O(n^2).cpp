#include<iomanip>
#include<iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include<map>
#include<cmath>
#include<stdio.h>
#include<queue>
#include <set>
#include <stack>

using std::string;
using namespace std;
#define vi vector<int>
#define ii pair<int,int>
#define ull unsigned long long int
#define ll  long long int


#define MAXN 107
#define MAXLG 16

int ipow(int base, int exp) {
    if (exp < 0)
        return INT_FAST32_MIN;
    int result = 1;
    while (exp) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}
int missAt[MAXN];
string patt="ABA",S="aaaa";
   vi zFunction(string s,int start = 0 ){
       int n = s.length() ;
       vi z(n);
       for(int i=start+1 , l= start, r =start;i<n;i++){
           if(i<=r ){
               z[i]=min(z[i-l+start],r-i+1);
           }
           while(i+z[i]<n && s[z[i]+start]==s[i+z[i] ])
               z[i]++;
           if(i+z[i]-1 >r){
               l=i;r=i+z[i]-1;

           }
       }
return z;
   }
int main() {
    int N = S.length(),subs=0;
    freopen("cube.txt", "r", stdin);
    vi mainz(S.length()),tempz(S.length());
    for(int len = N ; len>0;len--){
        tempz = zFunction(S,N-len);
        for(int i = N  - len;i <N;i++){
            mainz[i] = max(mainz[i],tempz[i]);
        }
        if(mainz[N-len]<len){
            subs+=len- mainz[N-len];
        }

    }
    printf("%d",subs);

return 0;


}
