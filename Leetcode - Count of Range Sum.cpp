class Solution {
public:
    int r = 0;
    void mergeSort(vector<long>& sum, int left, int right,long lower, long upper){
        
        if (left >= right) return;
        long mid = (left+right)/2;
        //cout << left << mid << right << endl;
        mergeSort(sum,left,mid,lower,upper);
        mergeSort(sum,mid+1,right,lower,upper);
       // cout << sum[0] << sum[1] << sum[2] << sum[3] << sum[4] ;
        
        int i = left;
        int j = mid+1;
        int a = 0;
        int b = 0;
        while (i<=mid && j<=right){
            if (sum[j]-sum[i]>=lower) { a += (right-j+1); i++;}
            else {j++;}
        }
        i = left; j = mid+1;
        while (i<=mid && j<=right){
            if (sum[j]-sum[i]>upper) { b += (right-j+1); i++;}
            else {j++;}
        }
        r += (a-b);
 
        vector<int> newv;
        i = left;
        j = mid+1;
        while (i<=mid && j<=right){
            if (sum[j]<sum[i]) { newv.push_back(sum[j]); j++;}
            else {newv.push_back(sum[i]); i++;}
        }
        if (i>mid){
            while (j<=right) {
                newv.push_back(sum[j]);
                j++;
            }
        }
        else {
            while (i<=mid){ 
                newv.push_back(sum[i]);
                i++;
            }
        } 
        

        for (int k=left;k<=right;k++){
            sum[k] = newv[k-left];
        }
        //sum = newv;

    }
    int countRangeSum(vector<int>& nums, long lower, long upper) {
        vector<long> sum;
        sum.push_back(0);
        long s=0;
        for (int i=0;i<nums.size();i++){
            s+=nums[i];
            sum.push_back(s);
            //cout << "s" << s;
        }
        //cout << endl;
        mergeSort(sum,0,sum.size()-1,lower,upper);
        return r;
    }
};
