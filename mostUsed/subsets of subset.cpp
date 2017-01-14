 vi subSets;
    void findSets(int curr,int superSet,int mask=0){
        int lastBitSet = (( curr & ~(curr - 1))&superSet);
        if(lastBitSet==0)return;
        //keep it turned off
        int currOff = (curr)&(~lastBitSet);
        int maskOff= (mask);
        //keepit on
        int currOn = curr;
        int maskOn = mask|lastBitSet;
        subSets.pb(currOff|maskOff);
        subSets.pb(currOn|maskOn);
        findSets(currOff,superSet,maskOff);
        findSets(currOn,superSet,maskOn);

    }
