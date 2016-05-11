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
struct vertex{
int next[26];
    bool leaf;
    int p , ch , link;
    int go[26];
};
vertex t[MAXN+10];
int sz;
void init(){
    t[0].link=t[0].p=-1;
    fill(t[0].next,t[0].next+26,-1);
    fill(t[0].go,t[0].go+26,-1);
sz=1;
}

void addString(string s){
    int v;
    for(int i=0;i<s.length();i++){
        char c = s[i]-'a';
        if(t[v].next[c]==-1){
            fill(t[sz].next,t[sz].next+26,-1);
            fill(t[sz].go,t[sz].go+26,-1);
            t[sz].link = -1;
            t[sz].p=v;
            t[sz].ch = c;
            t[v].next[c] = sz++;

        }
        v = t[v].next[c];

    }
    t[v].leaf = true;

}
int go (int v, char c);
int get_link(int v){
    if(t[v].link==-1){
        if(v==0 || t[v].p==0){
            t[v].link=0;
        }else{
            t[v].link = go(get_link(t[v].p),t[v].ch);

        }

    }
    return t[v].link;

}

int go (int v, char c){
 if(t[v].go[c]==-1){
     if(t[v].next[c]!=-1){

       t[v].go[c] = t[v].next[c];
     }else{
         t[v].go[c] = v==0 ? 0 : go(get_link(v),c);


     }




 }

return t[v].go[c];


}


int main() {
    freopen("cube.txt", "r", stdin);


    return 0;
}
