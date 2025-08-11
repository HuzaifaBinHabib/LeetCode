class Solution {
public:
    void reverseString(vector<char>& s) {
      int lp=0;
      int rp=s.size()-1;
  
  while(lp<=rp){
          char b = s[lp];
          s[lp]  = s[rp];
          s[rp]  = b;
          lp++;
          rp--;
      
    }   
    }
};