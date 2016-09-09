int sum[maxn][maxn];
int matrix[maxn][maxn];

int sumof(int x1,int y1,int x2,int y2){
    int a=0,b=0,c=0;
    if(y1-1>=0)a=sum[x2][y1-1];
    if(x1-1>=0)b=sum[x1-1][y2];
    if(x1-1>=0 && y1-1>=0)c=sum[x1-1][y1-1];
    return sum[x2][y2]-(a+b)+c;
}

for(int i=0;i<row;i++)
        for(int j=0;j<col;j++){

            if(j-1>=0 && i-1>=0)sum[i][j]-=sum[i-1][j-1];
            if( i-1>=0)sum[i][j]+=sum[i-1][j ];
            if( j-1>=0)sum[i][j]+=sum[i][j-1 ];
            sum[i][j]+=matrix[i][j];
        }
