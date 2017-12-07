 rep (i,0,n) {
        arr[i] = rand()%463636;
    }
    int added = 1;
    int root = 0;
    int act = 0;
    while (added<n) {
        int toAdd = rand()%(n/12);
        rep (i,0,toAdd) {
            if (root < i+added) {
                adj[root].push_back(i + added);
                adj[i + added].push_back(root);
                if (added+i+1==n)break;
                act++;
            }


        }
        root++;
        added+=toAdd;

    }
    rep (i,0,n) {
        if (adj[i].size()==0) {
            int a = rand()%i;
            adj[i].push_back(a);
            adj[a].push_back(i);
        }
    }
