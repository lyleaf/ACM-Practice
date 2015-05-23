//
//  main.cpp
//  ConsecutiveOnes
//
//  Created by LIUYiling on 20/05/15.
//  Copyright (c) 2015 LIUYiling. All rights reserved.
//  https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1512

Comment: 使用bit

#include <functional>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <cstring>
#include <queue>
#include <string>
#include <sstream>
#include <stack>

struct Node
{
    int self; //数据
    int mother; //左节点
    Node(int s,int m) : self(s), mother(m) {}
};

using namespace std;
int matrix[400][400];//The last M+1 column act as a flag to see if the meetings has ended or not.
stack<Node> currentState;
int nn;//Determin the value of matrix[N][*]
list<Node> goodLink; //0->17->11->12->...


bool checkTraverser (int M,int N){ //if flag == 1, all travarsed.
    bool flag = 1;
    for (int i=0;i<M;i++) {
        if (matrix[N][i] == -1)
            flag = 0;
    }
    return flag;
}

int main(int argc, const char * argv[]) {
    int number;
    
    cin >> number;
    
    while (number--){
        string digits;
        getline (cin,digits);

        
        int N,M;
        cin >> N >> M; //N: number of people, M: number of meetings to attend
        //cout << N << M << endl;
        memset(matrix,0,sizeof(matrix));
        
        getline (cin,digits);
        cout << digits;
        char digit;

        for (int i=0;i<N;i++)
            for (int j=0;j<M;j++){
                cin >> digit;
                matrix[i][j]= digit - '0';
            }
        
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++)
                matrix[i][M] += matrix[i][j];
        }
        
        for (int i=0;i<M;i++){
            matrix[N][i]= -1;
        }

        currentState.push(Node(0,-1));//initialization
        matrix[N][0]=0;
        nn = 0;
        
        while (!currentState.empty()){
            Node current = currentState.top();
            currentState.pop();
            goodLink.push_back(current);
            
            matrix[N][current.self]=nn;
            //cout << "current"<<current.self <<" "<<current.mother<< endl;

            if (checkTraverser(M,N))
                break;
            
            for (int i =0;i<N;i++){
                if (matrix[i][current.self]==1)
                    matrix[i][M]-=1;
            }
            
            list<Node> l;
            
            for (int i=0;i<M;i++){
                if (matrix[N][i]==-1){
                    int flag = 1;
                    for (int j=0;j<N;j++){
                        if (matrix[j][current.self]==1){
                            if (matrix[j][M]!=0 && matrix[j][i]!=1)
                                flag = 0;
                        }
                    }
                    if (flag == 1) {l.push_back(Node(i,current.self));}//cout << "i" << i << endl;
                }
            }
            
            if (l.empty()){
                //cout << "===END====\n";
                
                Node next = currentState.top();
                while (goodLink.back().self != next.mother){
                    Node tmp = goodLink.back();
                    matrix[N][tmp.self] = -1; //update matrix[N][*]
                    for (int i=0;i<N;i++){   //update matrix[*][M], could be optimised
                        matrix[i][M] += matrix[i][tmp.self];
                    }
                    goodLink.pop_back();
                    nn--;
                }
            }
            
            nn++;
            while (!l.empty()){
                Node i = l.front();
                l.pop_front();
                currentState.push(i);
            }
            
        }
        
        
        
/*
        
        cout << "======Last Line=======" << endl;
        for (int i=0;i<M;i++){
            cout << matrix[N][i] << endl;
        }
        cout << "======Right Line=======" << endl;

        for (int i=0;i<N;i++){
            cout << matrix[i][M] << endl;
        }
        
        cout << "=====result======\n";
        cout << "M" << M << endl;
*/
        for (int i=0;i<M;i++){
            for (int j=0;j<M;j++){
                if (matrix[N][j] == i)
                    cout << j << endl;
            }
        }

        if (number) cout << endl;
    }
    return 0;
    
}
