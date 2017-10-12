int node[MAXN][2];
int NODE=1;
void add(int curr,int bit,int val) {
    freq[curr]++;
    if (bit==-1)return;

    if (node[curr][val&(1<<bit)?1:0]==-1) {
        node[curr][val&(1<<bit)?1:0] =NODE++;
        add(NODE-1,bit-1,val);
    } else {
        add(node[curr][val&(1<<bit)?1:0],bit-1,val);
    }
}


void del(int curr,int bit,int val) {
    freq[curr]--;
    if (bit==-1)return;

    del(node[curr][val&(1<<bit)?1:0],bit-1,val);

}
