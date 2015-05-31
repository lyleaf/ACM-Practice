//
//  main.cpp
//  FightingTheHeat
//
//  Created by LIUYiling on 31/05/15.
//  Copyright (c) 2015 LIUYiling. All rights reserved.
//
/*
我想说的是，题目有点搞笑啊- -\ 去实验室享受空调，也是醉了。说的好像我家里没有空调似的。

 https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=1208&mosmsg=Submission+received+with+ID+1706445
 
 Last summer was so hot that it was impossible to do anything but stay in the bathroom and solve puzzles. These games were so boring that you decided to write programs to solve them. This gave you a good reason to go back to the lab and benefit from its air conditioner.
 
 Here is the game you decided to solve automatically. Take a grid with n rows and m columns, with a letter in each cell. From the grid's cells, one can read words horizontally, vertically or diagonally, oriented forwards or backwards. You also have a list of words, and the goal is to highlight all occurrences of these words on the grid. The letters in non-highlighted cells of the grid form a word (called the code word) that can be read from top to bottom and left to right. The goal of the program is to find the code word automatically.
 
 Input
 
 The input file contains several test cases.
 
 Each case begins with the two integers n and m on a line ( 0 < n, m$ \le$40), separated by a blank. The second line contains the number k ( 0 < k$ \le$200) of words in the list. Then follow the k words, one per line. Words do not have more than 22 letters. After these, follows the grid, that is to say n rows filled with m uppercase letters.
 
 Output
 
 For each case, write the code word on a line.
 
 Sample Input
 
 
 6 6
 7
 ALLY
 BARE
 BARED
 FINES
 HIND
 LORD
 WONG
 BBARED
 ACALHF
 RWOEII
 EROSNN
 DARNDE
 ALLYGS
 
 字母拼图游戏，蛮简单的，暴力枚举，但感觉有提升的余地。
 
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <string.h>
using namespace std;

string s;
int m,n,nWords;
string words[200];
char table[40][40];
bool flag[40][40];

void markFlag(string);
int main(int argc, const char * argv[]) {
    while (cin >> n >> m){
        memset(flag,0,sizeof(flag));
        cin >> nWords;
        getline(cin,s);
        for (int i=0;i<nWords;i++){
            getline(cin,s);
            words[i]=s;
            
           // cout << words[i][0]<<endl;
        }
        for (int i=0;i<n;i++){
            getline(cin, s);
            for (int j=0;j<m;j++)
                table[i][j]=s[j];
        }
        
        for (int i=0;i<nWords;i++){
           // cout << words[i] << endl;
            markFlag(words[i]);
        }
        
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++){
                if (!flag[i][j])
                    cout << table[i][j];
            }
        cout << endl;
        
        
    }
    return 0;
    
}

void markFlag(string word){
    vector<int> x;
    vector<int> y;
    int len = word.length();
    
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (table[i][j]==word[0])
            {   //cout << "first letter: "<<table[i][j]<<endl;
                x.push_back(i);
                y.push_back(j);
            }
        }
    }
    
    string tmp("");
    int cx,cy;
    while (!x.empty()){
        cx = x.back();
        cy = y.back();
        x.pop_back();//current x
        y.pop_back();
        
        //cout << "get First Letter"<<table[cx][cy] <<endl;
        
        if (cx + len <= n) { //down compare
            tmp="";
            for (int i=0;i<len;i++)
                tmp += table[cx+i][cy];
            
            if (tmp==word){
                for (int i=0;i<len;i++)
                    flag[cx+i][cy]=1;
            }
        }
        
        if (cx - len >= -1) { //up compare
            tmp="";

            for (int i=0;i<len;i++)
                tmp += table[cx-i][cy];
            if (tmp==word){
                for (int i=0;i<len;i++)
                    flag[cx-i][cy]=1;
            }
        }

        if (cy + len <= m) { //right compare
            tmp="";

            for (int i=0;i<len;i++)
                tmp += table[cx][cy+i];
            //cout << "tmp:" << tmp << endl;
            //cout << "word" << word << endl;
            
            if (tmp==word){
                for (int i=0;i<len;i++)
                    flag[cx][cy+i]=1;
            }
        }

        if (cy - len >= -1) { //left compare
            tmp="";

            for (int i=0;i<len;i++)
                tmp += table[cx][cy-i];
            if (tmp==word){
                for (int i=0;i<len;i++)
                    flag[cx][cy-i]=1;
            }
        }
        
        if (cx+len <=n && cy+len <=m){//right down
            tmp="";

            for (int i=0;i<len;i++)
                tmp += table[cx+i][cy+i];
            if (tmp==word){
                for (int i=0;i<len;i++)
                    flag[cx+i][cy+i]=1;
            }
        }
        
        if (cx+len <=n && cy-len >=-1){//left down
            tmp="";

            for (int i=0;i<len;i++)
                tmp += table[cx+i][cy-i];
            if (tmp==word){
                for (int i=0;i<len;i++)
                    flag[cx+i][cy-i]=1;
            }
        }
        
        if (cx-len >=-1 && cy-len >=-1){//
            tmp="";

            for (int i=0;i<len;i++)
                tmp += table[cx-i][cy-i];
            if (tmp==word){
                for (int i=0;i<len;i++)
                    flag[cx-i][cy-i]=1;
            }
        }
        
        if (cx-len >=-1 && cy+len <=m){//
            tmp="";

            for (int i=0;i<len;i++)
                tmp += table[cx-i][cy+i];
            if (tmp==word){
                for (int i=0;i<len;i++)
                    flag[cx-i][cy+i]=1;
            }
        }

        
    }
}
