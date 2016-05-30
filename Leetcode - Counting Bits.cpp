/*给出一个数num，比如说5，return 从0到5这6个数里每一个数的二进制表示里含有1个个数.

我的方法是直接用mod和移位。可是取模让这个算法有一点expensive.
看到的别人的方法有一种非常神奇。他先把这个vector全部初始化为0.
然后的思路是：Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.

SKill Set: 
If I want to toggle between 0 and 1, I can use
int flag = 1;
flag = !flag;

flag ^= 1;

flag = 1-flag;

int arr[] = {1,0};
x = arr[x];


*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> r;
        r.push_back(0);
        for (int i=1;i<=num;i++){
            int x = r[i/2]+ (i%2);
            r.push_back(x);
        }
        return r;
    }
};
