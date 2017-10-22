struct matrix{
    int row,col;
    ll mat[100][100];
    int mod;
    matrix(int r,int c,bool identity = false,int mod=MOD){//identity matrix
        row= r;
        col = c;
        this->mod = mod;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            {   if(i==j && identity)mat[i][j]=1;
                else mat[i][j]=0;

            }
    }

    matrix  operator*(matrix&o){
        matrix ans = matrix(this->row,o.col);
        for(int i=0;i<this->row;i++)
            for(int j=0;j<o.col;j++)
            {   ans.mat[i][j]=0;
                for(int z=0;z<this->col;z++)
                    ans.mat[i][j] =( ans.mat[i][j]+ 1ll*mat[i][z]*o.mat[z][j])%mod;
            }

        return ans;
    }


    void show(){
        for(int i=0;i<row;i++) {
            for (int j = 0; j < col; j++)
                printf("%lld ", mat[i][j]);
            printf("\n");
        }
        cout<<"\n";
    }

    void operator=(const matrix &o){

        for(int i=0;i<o.row;i++)
            for(int j=0;j<col;j++)
                this->mat[i][j]=o.mat[i][j];
    }
};


matrix power(matrix mat , int n){
    if(n==0){
        int row = mat.row;
        int col = mat.col;
        matrix temp(row,col,true);
        return temp;
    }
    if(n%2==0){
        matrix temp = power(mat,n/2);
        return temp*temp;
    }
    else{
        matrix ans = power(mat,n-1);
        return mat*ans;
    }

}
