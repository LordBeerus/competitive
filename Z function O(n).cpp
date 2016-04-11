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
string patt="ABA",S="ABABABABABA";
   vi zFucntion(string s){
       int n = s.length();
       vi z(n);
       for(int i=1 , l= 0, r =0;i<n;i++){
           if(i<=r ){
               z[i]=min(z[i-l],r-i+1);
           }
           while(i+z[i]<n && s[z[i]]==s[i+z[i]])
               z[i]++;
           if(i+z[i]-1 >r){
               l=i;r=i+z[i]-1;

           }
       }
return z;
   }
int main() {
  // freopen("cube.txt", "r", stdin);
    vi z = zFucntion("abacaba");
    for (int i = 0; i <z.size(); ++i) {
       printf("%d\n",z[i]);
    }

return 0;


}
