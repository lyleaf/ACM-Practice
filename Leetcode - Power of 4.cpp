//Way1: Using bitset. By Yiling :)

class Solution {
public:
    bool isPowerOfFour(int num) {
        bitset<64> b(num);
        if (b.count()!=1)
            return false;
        else{
            int i = 0;
            while(b[i]!=1){
                i++;
            }
            bitset<32> bb(i);
            if (bb[0]!=0) 
                return false;
            else return true;
        }
    }

};

//Way2: From solutions on leetcode
//Attention: & doesn't have a priority.
//Attention: num & (num-1) == 0 to check if it's a power of 2.

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num>0) && ((num & (num-1)) == 0) && ((num & 0x55555555) == num);
    } 
};
