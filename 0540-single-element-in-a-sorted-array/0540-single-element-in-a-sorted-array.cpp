class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
      int lp=0;
    int n= arr.size();
    int rp=n-1;
    if(n==1){return arr[0];}

    while(lp<=rp){
        int mid = lp+(rp-lp)/2;
        
    if (mid == 0 && arr[mid] != arr[mid + 1]){
        return arr[mid];
        }
    if(mid==n-1 && arr[mid] != arr[n-1]) {
        return arr[mid];
        }
    if (arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1]) {
        return arr[mid];
        }
        
        if(mid%2==0){
            if(arr[mid]==arr[mid-1]){
                rp= mid-1;
            }else{
                lp=mid+1;
            }
        }else{
            if(arr[mid]==arr[mid-1]){
                lp=mid+1;
            }else{
                rp=mid-1;
            }
        }
    }
    return -1;
}
    
};