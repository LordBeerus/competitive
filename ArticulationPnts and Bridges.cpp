bool visited[MAXN];
int pos[MAXN]={INF},low[MAXN]={INF};
unordered_set<int> artPoints;
vi adj[MAXN];
int NUM = 1;
void dfs(int curr,int par) {
    visited[curr] = true;
    pos[curr] = low[curr]= NUM++;
    int c=0;

    for (int child : adj[curr]) {
        if (!visited[child]) {
            c++;
            dfs(child,curr);
            low[curr] = min(low[curr],low[child]);
            if (curr==0 && c>1)//not nesscary fof bridge
                artPoints.insert(curr);
            else if (curr!=0 && low[child]>= pos[curr]) // remove >=(keep >) for bridge add curr->child as bridge
                artPoints.insert(curr);
        } else if (child!=par) {
            low[curr] = min(low[curr],pos[child]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    int n,m;
    cin>>n>>m;
    rep (i,0,m) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0,-1);



    return 0;
}
