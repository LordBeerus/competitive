void dij(int src,int verts) {
    set<ii> pq;
    int dist[verts];
    bool visited[verts];
    fill(dist,dist+verts,mod);
    fill(visited,visited+verts,false);
    pq.insert(mp(0,src));
    dist[src]=0;
    while (!pq.empty()) {
        int src = pq.begin()->second;
        int w =  pq.begin()->first;
        pq.erase(pq.begin());
        if (visited[src])
            continue;
        visited[src] = true;
        //works for adjancency matrix only .. make changes for adjacency list
        rep (i,0,k) {
            if (dist[i]>w+adj[src][i]) {
                dist[i]=w+adj[src][i];
                pq.insert(mp(dist[i],i));
            }
        }
    }
    rep (i,0,k) {
        ans[src][i] = dist[i];
    }

}
