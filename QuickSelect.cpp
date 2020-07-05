#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    
int part_(vector<int>& arr, int low, int high) {
    int pivot = arr[(low+high)/2];
    
    int i = low, j = high;
    while(true) {
        while(i<high  && arr[i]<pivot  )
            i++;
     
        while(j>low && arr[j]>pivot)
            j--;
        
        
        if(i>=j)
            return j;
        
        
        swap(arr[i],arr[j]);
        
        if (arr[i]==arr[j])
            j--;
    }
    
    
    
    
}
int quickSelect(vector<int>& nums, int low, int high, int pos) {
    int p  = part_(nums,low,high);
    
    if (p > pos)
        return quickSelect(nums,low,p-1,pos);
    else if (p<pos)
        return quickSelect(nums,p+1, high,pos);
    else
        return pos;
    
    
}

    int findKthLargest(vector<int>& nums, int k) {
      return nums[quickSelect(nums,0,nums.size()-1,nums.size()-k )];
   //return part_(nums, 0,nums.size()-1);
    }
};
