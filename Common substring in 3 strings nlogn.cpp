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

#define MAXN 107
#define MAXLG 16
using std::string;
using namespace std;
#define vi vector<int>
#define ii pair<int,int>
#define ull unsigned long long int
#define ll  long long int

int n, step, cnt, t;
int P[MAXLG][MAXN], A[MAXN], LCP[MAXN], r[MAXN], posOfRank[MAXN], LCPI[MAXN][MAXLG];
struct entry {
    int one, two, pos;
} L[MAXN];
string S ;

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

void preProcess() {
    for (int i = 0; i < n; i++) {
        LCPI[i][0] = LCP[i];
    }
    for (int sweep = 1; sweep < MAXLG; sweep++) {
        for (int idx = 0; idx + (1 << sweep) < n; idx++) {
            LCPI[idx][sweep] = min(LCPI[idx][sweep - 1], LCPI[idx + (1 << (sweep - 1))][sweep - 1]);

        }
    }
}

int lcp(int x, int y) {
    x = x + 1;//normalize
    int k = log2(y - x + 1);
    return min(LCPI[x][k], LCPI[y - ipow(2, k) + 1][k]);

}

void countSort(int start, int end, int exp, int opt) {
    int freq[10];
    fill(freq, freq + 10, 0);

    entry temp[n];
    for (int i = start; i <= end; i++) {
        if (opt == 1) {
            freq[(L[i].one / exp) % (10)]++;
        } else {
            freq[(L[i].two / exp) % (10)]++;
        };
    }
    for (int i = 1; i < 10; i++) {
        freq[i] = freq[i] + freq[i - 1];
    }
    for (int i = end; i >= start; i--) {
        if (opt == 1)
            temp[(freq[(L[i].one / exp) % (10)]--) - 1] = L[i];
        else
            temp[(freq[(L[i].two / exp) % (10)]--) - 1] = L[i];


    }
    for (int i = 0; i <= (end - start); i++)
        L[start + i] = temp[i];


}

void radixSort(int start = 0, int end = n - 1, int type = 1) {
    int maximum = -1;
    for (int i = start; i <= end; i++) {
        maximum = max(max(maximum, L[i].one), L[i].two);
    }
    for (int exp = 1; maximum / exp > 0; exp *= 10) {
        countSort(start, end, exp, type);

    }


}

void sortByyTwo() {
    int st = 0, end = 0;
    for (int i = 1; i < n; i++) {
        if (L[i].one == L[st].one) {
            end++;
        }
        else {
            if (end - st > 0)
                radixSort(st, end, 2);
            st = end + 1;
            end = st;
        }

    }
    if (end - st > 0)
        radixSort(st, end, 2);
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
        sort(L, L + n, cmpSuff);


        for (int i = 0; i < n; ++i) {
            P[step][L[i].pos] = ((i > 0) && (L[i].one == L[i - 1].one) && (L[i].two == L[i - 1].two)) ?
                                P[step][L[i - 1].pos]
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
    int start[MAXN], c1 = 0, c2 = 0, c3 = 0, count = 0, st = 3, en = 3;
    string s1 = "abababa$";//8
    string s2 = "aababc#", s3 = "aaababca@";//15,23
    S = s1 + s2 + s3;
    suffix(S);
    LCParr();
    preProcess();
    for (en = 3; en < n; en++) {
        int cRank = posOfRank[en];
        if (cRank <=7) {
            c1++;
            if (c1 == 1) { count++; }
        } else if (cRank >= 9 && cRank <=  14) {
            c2++;
            if (c2 == 1) { count++; }
        }
        else {
            c3++;
            if (c3 == 1) { count++; }

        }

        while (count == 3) {
            start[st] = en;
            int sRank = posOfRank[st];
            if (sRank <= 7) {
                c1--;
                if (c1 == 0) {
                    count--;
                    st++;
                    break;
                }
            }
            else if (sRank >= 9 && sRank <=14) {
                c2--;
                if (c2 == 0) {
                    count--;
                    st++;
                    break;
                }


            }
            else {

                c3--;
                if (c3 == 0) {
                    count--;
                    st++;
                    break;
                }

            }

            st++;
        }


    }

int ans = -1;
for(int i =3;i<st;i++){
    ans = max(ans , lcp(i,start[i]));
}

return 0;


}
