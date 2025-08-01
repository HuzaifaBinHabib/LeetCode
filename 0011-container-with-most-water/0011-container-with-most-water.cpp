class Solution {
public:
    int maxArea(vector<int>& height) {
             int n = height.size();
        int lp= 0;
        int rp =n-1;
        int ans =0;
        int maxwater = 0;
        
        while(lp<rp){
        int w= rp-lp;
        int ht= min(height[lp],height[rp]);
        ans= w*ht;
        maxwater =max(ans,maxwater);
        if(height[lp]<height[rp]){
            lp++;
        }
        else{
           rp--; 
        }
        }
        return maxwater;
           
    }
};