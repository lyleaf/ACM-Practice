/*
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.

以下是我的思路：
相当于2个状态机，一个状态是面边只有一个数，也就是one = true,状态可以用first_one来表示
一个状态是面边有2个数，也就是two = true，状态可以用first_two, second_two来标识这个状态


*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size()<3){
            return false;
        }
        int first_one = nums[0];
        int MAX = numeric_limits<int>::max();
        int second_two = MAX;
        int first_two = MAX;
        bool one = true;
        bool two = false;

        for (int i=1;i<nums.size();i++){
            //cout << one << two << first_one << first_two << second_two << endl;
            int temp_first = first_one;
            if (two){
                if (nums[i]<=second_two){
                    one = true;
                    first_one = nums[i];
                    if (nums[i] > first_two){
                        second_two = nums[i];
                    }
                }
                else{
                    return true;
                }
            }
            if (one){
                if (nums[i]<=temp_first){
                    first_one = nums[i];
                }
                else{
                    two = true;
                    one = false;
                    second_two = (nums[i] < second_two) ? nums[i] : second_two ;
                    first_two = (first_one < first_two) ? first_one : first_two;
                }
            }
        }
        return false;
    }
};


//Second solution:

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size()<3){
            return false;
        }
        int first = nums[0];
        int MAX = numeric_limits<int>::max();
        int second = MAX;


        for (int i=1;i<nums.size();i++){
            if (nums[i]>second) return true;
            else if (nums[i]<=second && nums[i]>first) {
                second = nums[i];
            }
            else if (nums[i]<=first){
                first = nums[i];
                //second = MAX;
            }
        }
        return false;
    }
};

//Other's solution
class Solution {
    public:
        bool increasingTriplet(const vector<int>& nums) {
            int min = INT_MAX;
            int mid = INT_MAX;
            for(auto n : nums)
            {
                if(n < min)
                {
                    min = n;
                }
                else if(n > min)
                {
                    if(mid < n)
                        return true;
                    mid = n;
                }
            }
            return false;
        }
    };
