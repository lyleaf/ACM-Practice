class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> idx = vector<int>(primes.size(),0);
        vector<int> ugly;
        vector<int> tmps = vector<int>(primes.size());
        ugly.push_back(1);
        for (int i=0;i<n-1;i++){
            int next = 100000000000;
            for (int j=0;j<primes.size();j++){
                int tmp = ugly[idx[j]] * primes[j];
                tmps[j] = tmp;
                //cout << "tmp:" << tmp;
                if (tmp < next)
                    next = tmp;
            }
            ugly.push_back(next);
            for (int j=0;j<primes.size();j++){  
                if (tmps[j] == next)
                    idx[j]++;
            }
            //cout << endl << "i&next" << i << next << endl;
        }
        return ugly.back();
            
        
    }
};
