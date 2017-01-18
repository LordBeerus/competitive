vi getAllDivisors(int num){
     vector<int> divs;
    int square_root = (int) sqrt(num) + 1;
    for (int i = 1; i < square_root; i++) {
        if (num % i == 0&&i*i!=num)
        {
            divs.pb(i);
            divs.pb(num/i);
        }
        if (num % i == 0&&i*i==num)
        {
            divs.pb(i);
        }
    }
    return divs;
}
