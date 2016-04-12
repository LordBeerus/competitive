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
string patt="ABA",S="abzabzabz";
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
     vi z = zFunction(S);
    int N = S.length();
    int hi = S.length()-1,lo=0;
    int mid;
    int ANS=S.length();
    for(mid = 1 ; mid<=N/2 +1 ;mid++) {
        int cand = mid;
        bool ans = true;
        for (int i = cand; i < N; i += mid) {
            if ((z[i] < cand)) {
                ans = false;
                break;
            }


        }
        if (ans && N % mid == 0) {  ANS = min(ANS, mid); }
    }

    printf("%d",ANS);

return 0;


}
