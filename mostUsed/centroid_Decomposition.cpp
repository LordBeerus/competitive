
vi graph[MAXN];
vii centerAndParentNode;
int szTree[MAXN];
bool centroid[MAXN];


bool findSize(int curr, int par) {
    szTree[curr] = 1;

    for (int nxt: graph[curr]) {
        if (nxt != par &&!centroid[nxt]) {
            findSize(nxt, curr);
            szTree[curr] += szTree[nxt];
        }
    }
}
void findCentroid(int curr, int par, int cntParent) {

    int goTo = -1;
    for (int nxt : graph[curr]) {
        if (nxt != par && !centroid[nxt]) {
            if (szTree[nxt] > (cntParent + szTree[curr]) / 2) {
                goTo = nxt;
            }
        }
    }
    if (goTo == -1) { //this is centroid divide all subtrees
        centerAndParentNode.pb(mp(curr, par));
        centroid[curr] = true;

        // find centroid in parent node
            if (par != -1 && !centroid[par]) {
            findSize(par, curr);
            findCentroid(par, curr, 0);
        }
        for (int nxt : graph[curr]) {
            if (!centroid[nxt]) {
                findSize(nxt, curr);
                findCentroid(nxt, curr, 0);
            }
        }
        //in childre node
    } else {
        //do a dfs ()
        findCentroid(goTo, curr, cntParent + szTree[curr] - szTree[goTo]);
    }

}
