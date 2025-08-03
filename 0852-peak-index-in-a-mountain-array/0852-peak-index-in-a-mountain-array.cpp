class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int lp=1;
       int rp=arr.size()-2;
       while(lp<=rp){
           int mid= lp+(rp-lp)/2;
           if(arr[mid-1]<arr[mid]&& arr[mid]>arr[mid+1]){
               return mid;
           }
           else if(arr[mid-1]<arr[mid]){
               lp= mid+1;
           }
           else{
               rp = mid-1;
           }
       }
     return -1;
    }
};