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
