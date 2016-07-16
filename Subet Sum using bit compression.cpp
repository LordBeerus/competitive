void ShiftLeftBy(unsigned int *arr, int len, int by) {
    int tot = by % 32;
    int shift = by / 32;
    unsigned i, mask = (unsigned int) ((1 << (32)) - 1);
    mask = mask << (32 - tot);

    for (i = 0; (i + shift + 1)< len ; ++i) {

         arr[i] = (arr[i + shift] << tot) | ((arr[i + shift + 1] & mask) >> (32 - tot));
    }
    for (int j = 0; j < shift; j++)
        arr[len - 1 - j] = 0;
}

vi subset_sum_bit(int n, int s, unsigned int *arr) {
    int achBy[s + 1];
    int size = (s + 1) / 32 + 3;
    unsigned int prev[size], next[size], prev2[size];
    fill(achBy,achBy+s+1,-1);
    fill(prev, prev + size, 0);
    fill(next, next + size, 0);
    prev[(s + 1) / 32] = (1 << (32 - (s + 1) % 32));
    for (int i = 0; i < size; i++)
        prev2[i] = prev[i];
    int skip = 0;

    for (int i = 0; i < n; i++) {
       
        ShiftLeftBy(prev2, size, arr[i]);
        if(i==19999)
            cout<<"G";
        for(int j=0;j<size;j++)
        next[j] = (prev[j] | prev2[j]);
        //
        for (int j = 0; j < size; j++) {
            int t = next[j] ^prev[j];
            if (t) {
                for (int k = 0; k < 32; k++) {
                    if (t & (1 << k))
                    {

                        achBy[s-(j * 32 +  (31 - k))] = i;

                    }
                }

            }
        }

        //
        for (int j = 0; j < size; j++)
        {  prev[j] = next[j];prev2[j]=next[j];}
    }
    vi ans;
    if (!(next[0] &(1<<31)))
        return ans;


    int sum = s;

    while (sum > 0) {
        int get = achBy[sum];

        sum = sum - arr[get];
        ans.push_back(get);

    }
    return ans;

}
