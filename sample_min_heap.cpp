#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int size,heap[1000000];
    
    
    int getLeftChildIdx(int parentIdx) {return parentIdx*2+1;}
    int getRightChildIdx(int parentIdx) {return parentIdx*2 + 2;}
    int getParentIdx(int childIdx) {return (childIdx-1)/2;}
                                            
     void heapifyDown(int id) {
         int smallId = id;
         
         if (getLeftChildIdx(id)<size && heap[smallId]>heap[getLeftChildIdx(id)]) {
             smallId= getLeftChildIdx(id);
         }
         
         if (getRightChildIdx(id)<size && heap[smallId]>heap[getRightChildIdx(id)]) {
             smallId= getRightChildIdx(id);
         }
         if(heap[id]>heap[smallId]) {
             swap(heap[id],heap[smallId]);
             heapifyDown(smallId);    
          }
             
     } 
                                            
     void heapifyUp(int childId){
         if (childId!=0) {
             if (heap[childId]< heap[getParentIdx(childId)]) {
                 swap(heap[childId], heap[getParentIdx(childId)]);
                 heapifyUp(getParentIdx(childId));
             }
         }
     }                            
    
     void add(int elem) {
         heap[size] = elem;
         size++;
         heapifyUp(size-1);
     }                                       
     int pop() {
         int ans = 0;
         if (size>0) {
             ans  = heap[0];
             heap[0] = heap[size-1];
             size--;
             heapifyDown(0);
         }
         return ans;
     }                                       
                             };
