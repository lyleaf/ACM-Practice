class Solution {
public:
    int integerBreak(int n) {
        if (n==1 || n==2 || n==3)
            return n-1;
        if (n==4)
            return n;
        if (n%3==0){
            int k = n/3;
            int r = pow(3,k);
            return r;
        }
        if (n%3==1){
            int k = (n-4)/3;
            int r = pow(3,k)*4;
            return r;
        }
        if (n%3==2){
            int k = (n-2)/3;
            int r = pow(3,k)*2;
            return r;
        }
        else return 0;
        
    }
};
