double soclose  =1e-9;
vector<double> GEM(vector< vector<double> > A, vector<double> y) {
    // assumes a unique solution
    int N =A.size();
    for(int i =0; i < N; i++) {
        int x =-1;
        for(int j =i; j < N; j++) if(abs(A[j][i]) > soclose) 
            x =j;
        swap(A[i],A[x]);
        swap(y[i],y[x]);
        for(int j =0; j < N; j++) if(i != j) {
            double d =A[j][i]/A[i][i];
            for(int k =0; k < N; k++) A[j][k] -=d*A[i][k];
            y[j] -=d*y[i];}
        }
    vector<double> ret(N);
    for(int i =N-1; i >= 0; i--) ret[i] =y[i]/A[i][i];
    return ret;}
