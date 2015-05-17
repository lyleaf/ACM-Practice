//
//  main.cpp
//  Project File Dependencies
//
//  Created by LIUYiling on 13/05/15.
//  Copyright (c) 2015 LIUYiling. All rights reserved.
//
#include <functional>

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <cstring>
#include <queue>


using namespace std;
list<int> adj[100];


int main(int argc, const char * argv[]) {
    int number;
    
    cin >> number;
    
    while (number--){

 
        int N,M;
        cin >> N >> M; //N: number of tasks, M: number of rules
        //list<int> *adj = new list<int>[N]; 为什么动态分配后delete掉还是出错了？
        for (int i=0;i<100;i++){
            adj[i].clear();
        }



        while (M--){
            int x,y;
            cin >> x >> y;
            while (y--){
                int z;
                cin >> z;
                adj[x-1].push_back(z);
                //cout << z;
            }
        }
        
        
        bool *visited = new bool[N];
        for(int i = 0; i < N; i++)
            visited[i] = false;
        
        
        priority_queue<int,vector<int>,greater<int>> q;
        for (int i=0;i<N;i++){
            if (adj[i].empty())
            {   //cout << "hhhh "<< i+1;
                q.push(i+1);
                visited[i] = true;
            }
        }
        
        
        while (!q.empty()) {
            int num = q.top();
            cout << num;
            
            
            for (int i=0;i<N;i++){ //update adj
                if (!adj[i].empty()){
                    adj[i].remove(num);//为什么用这个就会用Run time error呢？
                    /*list<int>::iterator j;
                    for(j = adj[i].begin(); j != adj[i].end(); ++j){
                        if (*j == q.top())
                            adj[i].erase(j);
                    }*/

                }
            }
             
            
            
            
            q.pop();
            visited[num-1] = true; //update visited

            for (int i=0;i<N;i++){
                if (visited[i] == false){
                    if (adj[i].empty())
                    {q.push(i+1); //update q
                        visited[i]=true;
                       // cout << " q:" << i << endl;
                    }
                    
                }
            }

            if (!q.empty()) cout << " ";
            else cout << endl;
            
            
        }
        
        if (number) cout << endl;

        
        
    }
    return 0;

}

