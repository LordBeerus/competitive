int trie[MAXN][26],sufflink[MAXN],output[MAXN],sum[MAXN];
int N=0,ALPHA = 26;
void add(string s,int num) {
    int v = 0;
    rep (i,0,s.length()){
        if (trie[v][s[i]-'a']==-1) {
            trie[v][s[i]-'a'] = ++N;
        }
        v = trie[v][s[i]-'a'];
    }
    sum[v]  +=a[num];
}

void createLinks() {
    sufflink[0] = 0;
    queue<int> q;
    rep (i,0,26)
        if (trie[0][i]!=-1) {
            sufflink[trie[0][i]] = 0;
            q.push(trie[0][i]);
        } else {
            trie[0][i] = 0;
        }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        rep (i,0,ALPHA) if (trie[node][i]!=-1) {
                q.push(trie[node][i]);
                int suffParent = sufflink[node];
                while (trie[suffParent][i]==-1)
                    suffParent = sufflink[suffParent];
                sufflink[trie[node][i]] = trie[suffParent][i];
                /////
                sum[trie[node][i]] += sum[sufflink[trie[node][i]] ];
                //this could be anything..usually its the output function
                //as mentioned in https://www.cs.uku.fi/~kilpelai/BSA05/lectures/slides04.pdf
            }
    }
}
