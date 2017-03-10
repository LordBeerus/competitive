struct state {
    int len, link;
    map<char,int>next;
};
int cnt[MAXN];

state st[MAXN*2];
int sz, last;
set<ii> base;
void sa_init() {
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    ++sz;}

void sa_extend (char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p;
    for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c] = cur;
    cnt[cur]=1;
    if (p == -1)
        st[cur].link = 0;
    else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else {

            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            base.insert(mp(st[clone].len,clone));
            cnt[cur]=0;
            for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;


        }
    }
    base.insert(mp(st[cur].len,cur));
    last = cur;
}


void repstr()
{   vi num;
    set::reverse_iterator it;
    for(  it=base.rbegin(); it!=base.rend(); it++ )
        cnt[ st[ it -> second ].link ] += cnt[ it->second ];
        
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef DEBUG
    freopen("cube.txt", "r", stdin);
#endif
    PROB temp;
    string big;
    cin>>big;
    for(int i=0;i<big.length();i++){
        sa_extend(big[i]);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        string small;
        cin>>small;
        int ans = 0;

    }







    return 0;


};
