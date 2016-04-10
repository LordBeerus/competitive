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
int missTable(){
    int pos = 2 , cnd = 0;
    missAt[0]=-1,missAt[1]=0;
    while(pos<patt.length()){
        if(patt[pos-1]==patt[cnd]){
            missAt[pos]=cnd+1;
            cnd++;pos++;
        }
        else if (cnd >0){
            cnd = missAt[cnd];
        }
        else{
            missAt[pos]=0;
            pos++;
        }
    }
}

void KMP(){
    int m =0 , i = 0;
    while(m+i<S.length()){
        if(S[m+i]==patt[i])
        {
            if(i==patt.length()-1)
            { cout<<"MATCH\n";
                cout<<m<<endl;
                m = m+i-missAt[i];i=missAt[i];
        }else
            {i++;}

        }
      else{
            if(missAt[i]>-1)
            { m = m+i-missAt[i];i=missAt[i];}
            else{
                i=0;m=m+1;
            }



        }
    }
}
int main() {
    freopen("cube.txt", "r", stdin);
 
missTable();
    KMP();
return 0;


}
