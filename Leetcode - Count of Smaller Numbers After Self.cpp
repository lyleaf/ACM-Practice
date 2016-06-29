class flower{
    public:
        int index;
        int val;
        int count;
        flower(int i,int v,int c=0): index(i),val(v),count(c){}
        
        bool operator < (const flower& f) const
        {
            return (index < f.index);
        }
};
    
class Solution {
public:
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<flower> n;
        for (int i =0;i<nums.size();i++){
            n.push_back(flower(i,nums[i],0));
        }
        mergeSort(0,nums.size()-1,n);
        //for (auto i:n){
          //  cout << i.val << endl;
        //}
        sort(n.begin(),n.end());
        vector<int> r;
        for (auto i: n){
            r.push_back(i.count);
        }
        return r;
    }
    
    void mergeSort(int l,int r,vector<flower>& nums){//remember reference
        if (l>=r) return;
        int mid = (l+r)/2;
        mergeSort(l,mid,nums);
        mergeSort(mid+1,r,nums);
        int i=l,j=mid+1;
        vector<flower> newNums;
        
        for (int i=l;i<=mid;i++){
            for (int j=mid+1;j<=r;j++){
                if (nums[j].val < nums[i].val){
                    nums[i].count++; 
                }
                else break;
            }
        }
        
    
        
        while (i<=mid && j<=r){
            if (nums[j].val>=nums[i].val){
                newNums.push_back(nums[i]);
                //cout << nums[i].val << "->" << nums[i].count << endl;
                i++;
            }
            else {
                //cout << nums[i].val << "before" << nums[i].count << endl;
                //nums[i].count += 1;
                //cout << nums[i].val <<"after <"<< nums[i].count << endl;
                //cout << nums[i].count;
                newNums.push_back(nums[j]);
                j++;
            }
        }
        if (i>mid){
            while(j<=r){
                newNums.push_back(nums[j]);
                j++;
            }
        }
        else {
            while(i<=mid){
                nums[i].count += (r-j+1);
                newNums.push_back(nums[i]);
                i++;
            }
        }
        
        for (int k=l;k<=r;k++){
            //cout << newNums[k-l].val << ":" << newNums[k-l].count << endl;
            //cout << "change" << nums[k].val << " " << newNums[k-l].val << endl;
            nums[k] = newNums[k-l];
        }
    }

};
