//
//  main.cpp
//  MorseCode
//
//  Created by LIUYiling on 07/05/15.
//  Copyright (c) 2015 LIUYiling. All rights reserved.
//

//
//  main.cpp
//  NoChange
//
//  Created by LIUYiling on 05/05/15.
//  Copyright (c) 2015 LIUYiling. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cstring>
#include<string.h>


using namespace std;


string s;
int len;
string morse[] = {".-","-...","-.-.","-..",
    ".","..-.","--.","....",
    "..",".---","-.-",".-..",
    "--","-.","---",".--.",
    "--.-",".-.","...","-",
    "..-","...-",".--","-..-",
    "-.--","--.."};
map<string ,int> mp;
int dp[10002];

string test = ".-";


int main(int argc, char *argv[]){
    int number;
    int nwords;
    
    scanf("%d",&number);
    
    while (number--){
        
        cin >> s;
        scanf("%d",&nwords);
        
        mp.clear();   //Don't forget to reintialize.
        memset(dp,0,sizeof(dp));

        
        for (int i=0;i<nwords;i++){
            string word;
            cin >> word;
            string temp;
            for (int j=0;word[j];j++){
                temp += morse[word[j]-'A'];
            }
            //cout << temp << endl;
            mp[temp]++;
        }
        
        len = s.length();
        dp[0] = 1;
        for (int i = 0;i<len;i++) {

            for (int j=i;j>=0&&j>i-100;j--){
                if (!dp[j]) continue;
                string tmp;
                for (int k=i;k>=j;k--){
                    tmp = s[k]+tmp;
                }
                //cout << "tmp:" << mp[tmp] << endl;
                dp[i+1] += dp[j]*mp[tmp];
            }
        }
        
        cout << dp[len] << endl ;
        if (number) cout << endl;
        
        
    }
    
        
    
    return 0;
    
}
