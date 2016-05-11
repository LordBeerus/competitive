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
int link ,len,pos=INT_FAST32_MAX;
    map<char,int> next;
};
state node[MAXN*2];
int last = 0,size=0;
int d[MAXN*2],ans[MAXN*2],cnt[2*MAXN];
bool done[2*MAXN],clone[2*MAXN];
int POS;

void add(char c){
    int curr = ++size;
    node[curr].len = node[last].len+1;
    node[curr].pos = min(node[curr].pos,POS);
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
            node[cl].pos = 9999;
             ::clone[cl]=true;
            int nodeC = check;
            for(;nodeC!=-1 && (node[nodeC].next[c]==p.next[c]) ; nodeC= node[nodeC].link){
               node[nodeC].next[c] = cl;
            }
            node[p.next[c]].link=node[curr].link=cl;

        }
    }
last = curr;
}

bool verify(string q){
    int matched =0, curr=0,pos;
    while(1){
        if(node[curr].next.count(q[matched])>0){


            pos=node[curr].next[q[matched]];
            POS = pos;
            curr = node[curr].next[q[matched]];
            matched++;

        }else{
            return false;
        }

        if(matched==q.length())return true;

    }

}

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

int subStringsLen(int curr){
    if(node[curr].next.size()==0){
        d[curr]=0;
        ans[curr]=0;
    }else{

        for(auto nxt : node[curr].next)
        {
            if(!done[nxt.second])
                subStringsLen(nxt.second);

            d[curr]+=1+d[nxt.second];
            ans[curr]+=ans[nxt.second];

        }
        ans[curr]+=d[curr];
    }      done[curr]=true;





};

string KTHLexoGraphicSubString(int kth){
    int curr=0,count=0,down=0;
    string ans;
    while(true){
        for(auto nxt:node[curr].next){
            if(kth>(count+1+d[nxt.second])){
                count+=1+d[nxt.second];
            }
            else{
                count+=1;
                down = nxt.second;
                ans.push_back(nxt.first);
                break;
            }


        }

        if(count==kth){
            return ans;
        }
        else{
            curr = down;
        }
    }
}

void countOcc(int curr=0){

    for(auto nxt : node[curr].next){
        if(!done[nxt.second])
        {countOcc(nxt.second);
        done[nxt.second]=true;}

    }
if(curr!=0)
    cnt[node[curr].link]+=cnt[curr];

}

void first(int curr=0){

    for(auto nxt : node[curr].next){
        if(!done[nxt.second])
        {first(nxt.second);
            done[nxt.second]=true;}

    }
    if(curr!=0 )
      node[node[curr].link].pos = min ( node[node[curr].link].pos,node[curr].pos);

}
int numOfOccurrences(string s){
    for(int i = 0 ; i<MAXN*2;i++)
    {     if(!clone[i])
            cnt[i]+=1;
        else
            cnt[i]+=0;
    }
  countOcc();
    verify(s);

    return cnt[POS];
}
string smallestCycle(string S){
    int curr=0;
    string ans;
    while(true){
        if(node[curr].next.size()==0){
            break;
        }
        else{
            for(auto nxt : node[curr].next){
            ans.push_back(nxt.first);

            curr = nxt.second;
                break;
            }
        }
        if(ans.length()==(S.length()/2))
            break;
    }
    return ans;
}

int main() {
 freopen("cube.txt", "r", stdin);
    string let;
    cin>>let;

node[0].link=-1;
    node[0].len=0;
POS=0;
fill(done,done+MAXN*2,false);
    for (int i = 0; i <let.length() ; ++i) {

        add(let[i]);
        POS++;
    }
    string src = "abc";
    verify(src);
 first();
cout<<node[POS].pos - src.length()+1;
return 0;


}
