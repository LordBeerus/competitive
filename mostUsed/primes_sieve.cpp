//find primes less than limit


 vi sieve(int limit){
     vi primes;
     bool in[limit+1];
      memset(in,true,sizeof(in));
     for(int i=2;i<=limit;i++){
         if(in[i]){
             primes.push_back(i);
             for(int j=i;j<=limit;j+=i)
                 in[j]=false;
         }
     }



     return primes;
 }
