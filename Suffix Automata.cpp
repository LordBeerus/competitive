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
struct state{
int link ,len;
    map<char,int> next;
};
state node[MAXN*2];
int last = 0,size=0;

void add(char c){
    int curr = ++size;
    node[curr].len = node[last].len+1;
    state p = node[last];
    int check = last;
    for(; check!=-1 && !node[check].next.count(c) ; check= node[check].link){
       node[check].next[c] = curr;
    }
    if(check==-1)
    node[curr].link=0;
    else{
        p = node[check];
        state q = node[p.next[c]];
        if((p.len+1)==q.len){
            node[curr].link =p.next[c];
        }else{
            int cl = ++size;
            state clone;
            clone = q;
            clone.len = p.len+1;
            node[cl]=clone;
            int nodeC = check;
            for(;nodeC!=-1 && (node[nodeC].next[c]==p.next[c]) ; nodeC= node[nodeC].link){
               node[nodeC].next[c] = cl;
            }
            node[p.next[c]].link=node[curr].link=cl;

        }
    }
last = curr;
}
//if q exists in S
bool verify(string q){
    int matched =0, curr=0;
    while(1){
        if(node[curr].next.count(q[matched])){
            curr = node[curr].next[q[matched]];
            matched++;


        }else{
            return false;
        }

        if(matched==q.length())return true;

    }
}
int d[MAXN*2];
bool done[2*MAXN];
//no of diff substrings
int subStrings(int curr){
   if(node[curr].next.size()==0){
       d[curr]=0;

   }else{
       for(auto nxt : node[curr].next)
       {
           if(!done[nxt.second])
               subStrings(nxt.second);

           d[curr]+=1+d[nxt.second];
       }
   }      done[curr]=true;





};
int main() {
 freopen("cube.txt", "r", stdin);
    string let;
    cin>>let;
node[0].link=-1;
    node[0].len=0;

fill(done,done+MAXN*2,false);
    for (int i = 0; i <let.length() ; ++i) {
        add(let[i]);
    }
subStrings(0);

    cout<<d[0];
return 0;


}
