//
//  main.cpp
//  TopFreqency
//
//  Created by yiling on 5/29/16.
//  Copyright © 2016 yiling. All rights reserved.
//  给一个数组，求数组里边频率最大的K个数。
//  有一个方法是有2个数组来保存
//  还有一个方法是用堆排序 #TODO

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unsigned long n = nums.size();
        unordered_map<int,int> freq;
        unordered_map<int,int> index;
        vector<int> result;
        vector<int> first(n+1,0);
        
        for (int i=0;i<n;i++){
            int current = nums[i];
            int position = index[current];
            if (freq[current]==0){
                result.push_back(current);
                index[current]=result.size()-1;
            }
            else{
                //the new read number in result's position
        
                position = index[current];
                //cout << "first" << first[freq[current]] << endl;
                index[current] = first[freq[current]];
                //cout << "freq current" << freq[current] << endl;
                //cout << "...";
                //cout <<result[first[freq[current]]];
                //cout << position << endl;
                index[result[first[freq[current]]]]=position;
                swap(result[first[freq[current]]],result[position]);
                first[freq[current]]++;
                
            }
     
            freq[current]++;
            //cout << result[0];
        }
        return vector<int> (result.begin(),result.begin()+k);
    }
};

int main(){
    Solution s = Solution();
    int a[] = {5,2,5,3,5,3,1,1,3};
    vector<int> nums (begin(a), end(a));
    int k = 2;
    vector<int> r = s.topKFrequent(nums,k);
    for (int i:r){
    	cout << i << "\t";
    }
    return 0;
}
