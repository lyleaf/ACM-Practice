//
//  main.cpp
//  Page Hopping
//
//  Created by LIUYiling on 12/06/15.
//  Copyright (c) 2015 LIUYiling. All rights reserved.
//  每一次找到它外面的一层，把它记录下来。用currentVector 和nextVector
//  一直通不过的原因数组不够大。 还要考虑只有2个节点的情况
//  找到从一个节点到另一个节点的最短路径。Djkstra.

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int checkList[110];//check if all nodes has been checked.
vector<int> graph[110];
int n;
vector<int> nodeSet;
vector<int> currentVector;
vector<int> nextVector;


int main(int argc, const char * argv[]) {
    // insert code here...
    int a,b;
    int CNT = 0;
    while (cin >> a >> b){
        if (a == 0 && b == 0) break;

        
        nodeSet.clear();
        
        
        graph[a].push_back(b);
        nodeSet.push_back(a);
        nodeSet.push_back(b);
        CNT++;

        while (cin >> a >> b){
            if (a == 0 && b == 0) break;
            graph[a].push_back(b);
            nodeSet.push_back(a);
            nodeSet.push_back(b);
        }
   
        sort( nodeSet.begin(), nodeSet.end() );
        nodeSet.erase(unique(nodeSet.begin(),nodeSet.end()),nodeSet.end());//删除一个数组中重复的数据
        n = int(nodeSet.size());
        int total = 0;

        for (int i=0;i<n;i++){
            memset(checkList, 0, sizeof(checkList));
            int longOfChemin = 0;
            int currentNode = nodeSet[i]; //The current node we are dealing with.
    
            nextVector.clear();
            nextVector.push_back(currentNode);
            
            
            
            while (!nextVector.empty()){
                currentVector = nextVector;
                nextVector.clear();
                for (vector<int>::iterator it = currentVector.begin() ; it != currentVector.end(); ++it){
                    checkList[*it] = longOfChemin;
                }

                
                for (vector<int>::iterator it = currentVector.begin() ; it != currentVector.end(); ++it){
                    int rodo = *it;

                    for (vector<int>::iterator itt = graph[rodo].begin() ; itt != graph[rodo].end(); ++itt){

                        if (checkList[*itt] == 0 && *itt != currentNode){
                            nextVector.push_back(*itt);
                            checkList[*itt] = -1;
                        }
                    }
                    
                }
           
                longOfChemin++;

            }
            for (int i=0;i<n;i++){
                total += checkList[nodeSet[i]];
            }
        }
        for (int i=0;i<n;i++){
            graph[nodeSet[i]].clear();
        }
        
        double rst = double(total) / (n*(n-1));
        

        printf("Case %d: average length between pages = %.3lf clicks\n", CNT, rst);
        
        
    }
    return 0;
}
