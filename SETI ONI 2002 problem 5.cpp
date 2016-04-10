/*Problem 5: seti (ONI 2002 – abridged)
Given a string of length N (1≤N≤131072) 
and M strings of length at most 64, count
the number of matchings of every small string in the big one.*/
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

#define MAXN 50007
#define MAXLG 16
using std::string;
using namespace std;
#define vi vector<int>
#define ii pair<int,int>
#define ull unsigned long long int
#define ll  long long int

int n, step, cnt,t;
int P[MAXLG][MAXN], A[MAXN], LCP[MAXN], r[MAXN], posOfRank[MAXN],LCPI[MAXN][MAXLG];
struct entry {
    int one, two, pos;
} L[MAXN];
string S ="aaaabbbbbcccc$";
int ipow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}
void LCParr() {
    int L = 0;
    for (int i = 0; i < n; i++) {
        int k = r[i];



        if (k > 0) {
            int j = posOfRank[k - 1];
            while (S[i + L] == S[j + L]) { L++; }
            LCP[k] = L;

        }
        else {
            LCP[0] = INT32_MAX;
        }
        if (L > 0)
            L -= 1;

    }
}
void preProcess(){
    for(int i = 0 ; i<n;i++){
        LCPI[0][i] = LCP[i];
    }
    for(int sweep = 1; sweep  <MAXLG;sweep++){
        for(int idx = 0;idx+1<<sweep < n;idx++){
            LCPI[idx][sweep] = min(LCPI[idx][ sweep-1],LCPI[idx+1<<(sweep-1)][sweep-1]);

        }
    }
}
int lcp(int x ,int y){
    x = x-1;//normalize
    int k = log(y-x+1);
    return min(LCPI[x][k],LCPI[y-ipow(2,k)+1][k]);

}
void countSort(int start, int end, int exp, int opt) {
    int freq[10];
    fill(freq, freq + 10, 0);

    entry temp[n];
    for (int i = start; i <= end; i++) {
        if (opt == 1) {
            freq[(L[i].one/ exp) % (10)]++;
        } else {
            freq[(L[i].two / exp) % (10)]++;
        };
    }
    for (int i = 1; i <10; i++) {
        freq[i] = freq[i] + freq[i - 1];
    }
    for (int i = end ; i >=start; i--) {
        if (opt == 1)
            temp[(freq[(L[i].one/ exp) % (10)]--) - 1] = L[i];
        else
            temp[(freq[(L[i].two / exp) % (10)]--) - 1] = L[i];


    }
    for(int i = 0;i<=(end-start);i++)
        L[start+i]=temp[i];


}
void radixSort(int start = 0 ,int end = n-1,int type=1){
    int maximum=-1;
    for(int i =start; i<=end;i++){
        maximum = max(max(maximum,L[i].one),L[i].two);
    }
    for(int exp=1; maximum/exp > 0 ; exp*=10){
        countSort(start,end, exp,type);

    }




}
void sortByyTwo(){
    int st=0,end=0;
    for(int i =1;i<n;i++){
        if(L[i].one==L[st].one){
            end++;
        }
        else{
            if(end-st>0)
                radixSort(st,end,2);
            st = end+1;
            end = st;
        }

    }
    if(end-st>0)
        radixSort(st,end,2);
}




void show() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", P[i][j]);
        }
        printf("\n");
    }
}

bool cmpSuff(entry a, entry b) {
    return (a.one == b.one) ? a.two < b.two : a.one < b.one;
}

void suffix(string c) {
    n = c.length();
    for (int i = 0; i < n; i++)
        P[0][i] = c[i] - ' ';

    for (step = 1, cnt = 1; (cnt >> 1) < n; step++, cnt <<= 1) {
        for (int i = 0; i < n; i++) {
            L[i].one = P[step - 1][i];
            L[i].two = ((i + cnt) < n) ? P[step - 1][i + cnt] : -1;
            L[i].pos = i;
        }
sort(L,L+n,cmpSuff);


        for (int i = 0; i < n; ++i) {
            P[step][L[i].pos] = ((i > 0) && (L[i].one == L[i - 1].one) && (L[i].two == L[i - 1].two)) ?
                                P[step][L[i-1].pos]
                                                                                                      : i;
        }
    }
    for (int i = 0; i < n; i++) {
        r[i] = P[step - 1][i];
    }
    for (int j = 0; j < n; ++j) {
        posOfRank[r[j]] = j;

    }
}

int main() {
    freopen("cube.txt", "r", stdin);
 int prelo,prehi;
    suffix(S);
    LCParr();
   string pat="bbb";
    int len = pat.length();
    int curr = 0,lo1=0,hi1 = n-1;
    int lower , higher;
    prelo=0,prehi=n-1;
    while(curr<len){
        //finf upper bound
        while(hi1-lo1>1){
            int mid = (hi1+lo1)>>1;
            if(S[posOfRank[mid]+curr]< pat[curr])
             lo1 = mid+1;
            else if(S[posOfRank[mid]+curr]>pat[curr])
                hi1 = mid-1;
            else
                lo1 = mid+1;

        }

        if(S[posOfRank[hi1]+curr]==pat[curr])
            higher = hi1;
        else
            higher = lo1;


        //find lower bound
        lo1=prelo,hi1 = prehi;
        while(hi1-lo1>1){
            int mid = (hi1+lo1)>>1;
            if(S[posOfRank[mid]+curr]< pat[curr])
               lo1 = mid+1;
            else if(S[posOfRank[mid]+curr]>pat[curr])
                hi1 = mid-1;
            else
                hi1 = mid-1;
        }

        if(S[posOfRank[lo1]+curr]==pat[curr])
            lower = lo1;
        else
            lower = hi1;


        curr++;
        lo1=prelo=lower;
        hi1=prehi=higher;
    }

    return 0;


}
