 vi primes;

 vi sieve(int limit){
     vi primes;
     bool in[limit+1];
     fill(in,in+limit+1,true);
     for(int i=2;i*i<=limit;i++){
         if(in[i]){

             for(int j=1;j<=limit;j*=i)
                 in[j]=false;
         }
     }

     for(int i=2;i<=limit;i++)
         if(in[i])primes.push_back(i);

     return primes;
 }
