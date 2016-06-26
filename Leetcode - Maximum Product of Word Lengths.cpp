class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.size()<=1) return 0;
        vector<vector<int>> x(words.size(),vector<int>(26,0));
        
        
        for (int in=0;in<words.size();in++){
            string i = words[in];
            for (auto c:i){
                x[in][c-'a'] = 1;
            }
        }
        
        int r = 0;
        for (int i=0;i<words.size()-1;i++){
            for (int j=i+1;j<words.size();j++){
                bool flag = true;
                for (int k=0;k<26;k++){
                    if (x[i][k] && x[j][k] == 1){
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    int temp = words[i].size()*words[j].size();
                        if (temp > r)
                            r = temp;
                }
            }
        }
        
        return r;
    }
};
