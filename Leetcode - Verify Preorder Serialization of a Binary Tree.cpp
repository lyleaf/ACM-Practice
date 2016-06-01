//How to read a string divided by comma.
//The use of stack.
//告诉你一个二叉树的前序遍历，问你这可不可能是一个二叉树。
//难点对我来说是stringstream的读和写。如果能一次性读入可以提升效率。
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        stringstream now;
        vector<int> vect;
        char i;

        while (ss >> i)
        {
            if (i=='#'){
                vect.push_back(-1);
                ss.ignore();
            }
            else if (i==',')
                vect.push_back(1);
        }
        if (i!='#')
            vect.push_back(1);
            
        cout << "begin";
        stack<int> s;
        
        s.push(-1);
        for (vector<int>::iterator it = vect.begin();it != vect.end();it++){
            int x = *it;
            while (x==-1 && s.top()==-1){
                s.pop();
                if (!s.empty()){
                    s.pop();
                    x = -1;
                }
                else {
                    if (it == vect.end()-1)
                        return true;
                    else return false;
                }
            }
            s.push(x);
        }
        if (s.empty()){
            return true;
        }

        else return false;
        
    }
};
