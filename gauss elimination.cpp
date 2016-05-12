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
#include <string.h>

using std::string;
using namespace std;
#define vi vector<int>
#define ii pair<int,int>
#define ull unsigned long long int
#define ll  long long int


#define MAXN 107
#define MAXLG 16


void show(vector<vector<double> > a) {

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) { cout << a[i][j] << " "; }
        cout << "\n";
    }
    cout << endl;


}

int gauss(vector<vector<double> > a, vector<double> &ans) {
    int totRows = a.size(), totCols = a[0].size() - 1;
    vector<int> rowWhenColMax(totCols, -1);
    for (int row = 0, col = 0; col < totCols && row < totRows; col++)
    {
        int sel = row;
        for (int i = row; i < totRows; i++)
            if (a[i][col] > a[sel][col])
                sel = i;

        if (abs(a[sel][col]) < 0.0001)
            continue;

        for (int i = col; i <= totCols; i++)
            swap(a[row][i], a[sel][i]);

        show(a);
        rowWhenColMax[col] = row;
        for (int i = 0; i < totRows; i++) {
            if (i != row) {
                double c = a[i][col] / a[row][col];

                for (int j = col; j <= totCols; j++)
                    a[i][j] -= c * a[row][j];
            }
        }

row++;
    }
    ans.assign(totCols,0);
    for(int i =0 ; i<totCols;i++)
        if(rowWhenColMax[i]!=-1)
        ans[i] =a[rowWhenColMax[i]][totCols] /a[rowWhenColMax[i]][i];

    for(int i =0 ; i<totRows;i++){
        double temp=0;
        for(int j = 0;j<totCols;j++)
            temp+= a[i][j]*ans[j];

        if(abs(temp-a[i][totCols])>.00001){
            return 0;
        }
    }
    return 1;


}

int main() {
    freopen("cube.txt", "r", stdin);
    vector<vector<double>> A(4, vector<double>(5, 0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++)
            cin >> A[i][j];
    }
    vector<double> ans(4, 0);
    int a = gauss(A, ans);
    return 0;
}
