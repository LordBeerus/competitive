vi adj[MAXN];
int INDEX = 0;
bool onStack[MAXN];
int index_[MAXN], lowLink[MAXN];
stack<int> stk;
vvi components;//0 -> lowest in topological order
void getConnectedComponent(int i);

void getConnectedComponent(int i) {
    index_[i] = INDEX;
    lowLink[i] = INDEX;
    INDEX++;
    stk.push(i);
    onStack[i] = true;
    for(int nxt : adj[i] ) {
        if(index_[nxt] == -1) {
            getConnectedComponent(nxt);
            lowLink[i] = min(lowLink[i] , lowLink[nxt]);
        } else if (onStack[nxt]){
            lowLink[i] = min(lowLink[i] , index_[nxt]);

        }
    }

    if(lowLink[i] == index_[i]) {
        vi comp;
        int poped ;
       do {
            poped = stk.top();
            stk.pop();
            onStack[poped] = false;
            comp.pb(poped);
        } while(poped!=i);
        if (comp.size() > 0) {
            components.push_back(comp);
        }
    }
}

void tarjan(int n) {

    memset(onStack, false, sizeof(onStack));
    fill(index_,index_ + n , -1);

    for(int i=0;i<n;i++) {
        if(index_[i] == -1) {
            getConnectedComponent(i);
        }
    }
}


