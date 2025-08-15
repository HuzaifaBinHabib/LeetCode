class Solution {
public:
    int reverse(int x) {
       int digit=0;
       while(x!=0){
           int num = x % 10;

           digit = digit * 10 + num;
           x = x / 10;
       }
       return digit;
    }
};