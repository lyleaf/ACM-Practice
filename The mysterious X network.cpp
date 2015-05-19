//
//  main.cpp
//  The mysterious X network
//
//  Created by LIUYiling on 18/05/15.
//  Copyright (c) 2015 LIUYiling. All rights reserved.
//
/*One of the reasons for which École polytechnique (nicknamed ``X" for reasons to be explained during the debriefing talk) is so deeply rooted in French society is its famous network of camarades - former students of the same school. When one camarade wants something (money, job, etc.), he can ask this network for help and support. In practice, this means that when he/she wants to reach some other camarade, not always of the same year, then surely he can find intermediate camarades to get to her/him. Note that the ``camarade" relationship is symmetric. Due to the magic of the X network, there is always a means to reach anybody.

The program you have to write is supposed to help to minimize the number of these intermediate camarades.
*/
#include <iostream>
#include <functional>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <cstring>
#include <queue>

using namespace std;

list<int> adj[100000];
int dist[100000];
const int maxint = 999999;


int main(int argc, const char * argv[]) {
    int numberOfCases;
    scanf("%d", &numberOfCases);
    
    while (numberOfCases--){
        

        
        int N;//number of camarades
        scanf("%d", &N);
        
        
        for (int i=0;i<N;i++){
            adj[i].clear();
        }
        
        int NN = N;
        while (NN--){
            int a;
            int friends;
            scanf("%d %d",&a,&friends);
            while (friends--){
                int z;
                cin >> z;
                adj[a].push_back(z);
            }
        }
        int s,t;
        scanf("%d %d",&s,&t);
        
        
        for(int i = 0; i < N; i++)
            dist[i] = maxint;
        dist[s]=0;

        
        queue<int> q; // Use q to store all the points that has been ordered.
        q.push(s); //Every time take a point out of the q, and update dist[]

        
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            
            
            while (!adj[num].empty()){
                int tmp = adj[num].back();
                adj[num].pop_back();
                if (dist[tmp] == maxint) {
                    q.push(tmp);
                    dist[tmp] = dist[num]+1;
                }
            }
            
            if (dist[t] != maxint)
                break;
        }
        printf ("%d %d %d\n",s,t,dist[t]-1);
        
        if (numberOfCases) cout << endl;

    }
    return 0;
}
