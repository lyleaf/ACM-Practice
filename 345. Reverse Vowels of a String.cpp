class Solution {
public:
    string reverseVowels(string s) {
        set<char> a = {'a','o','e','i','u','A','O','E','I','U'};
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if (a.find(s[i]) != a.end()){
                if (a.find(s[j]) != a.end()){
                    swap(s[i],s[j]);
                    i++;
                    j--;
                }
                else{
                    j--;
                }
            }
            else i++;
        }
        return s;
    }
};

//Other people's solution
//Use a dict to track if it's a vowel or not.

class Solution {
public:
    string reverseVowels(string s) {
        int dict[256] = {0};
        dict['a'] = 1, dict['A'] = 1;
        dict['e'] = 1, dict['E'] = 1;
        dict['i'] = 1, dict['I'] = 1;
        dict['o'] = 1, dict['O'] = 1;
        dict['u'] = 1, dict['U'] = 1;
        int start = 0, end = (int)s.size() - 1;
        while(start < end){
            while(start < end && dict[s[start]] == 0) start++;
            while(start < end && dict[s[end]] == 0) end--;
            swap(s[start],s[end]);
            start++;end--;
        }
        return s;
    }
};
