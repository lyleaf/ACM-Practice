//
//  main.cpp
//  Crime
//
//  Created by LIUYiling on 19/05/15.
//  Copyright (c) 2015 LIUYiling. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int G[1000][1000];
int colorArr[1000];

int solution(int n,int src);

int main(int argc, const char * argv[]) {
    int n,m;//n:vertex number m:arret number
    int p1,p2;
    while (cin >> n >> m){
        
        memset(G, 0, sizeof(G));
        memset(colorArr,-1,sizeof(colorArr));
        while (m--){
            cin >> p1 >> p2;
            G[p1-1][p2-1] = 1;
        }
        int result = 0;
        
        bool flag = 0;
        for (int i=0;i<n;i++){
            if (colorArr[i]==-1){
                int a = solution(n,i);
                //cout << "a" << a << i << endl;
                if (a == -1){
                    flag = 1;
                    break;
                }
                else result += a;
            }
        }
        
        if (!flag)
            cout << result << endl;
        else cout << "Impossible\n";

    }
    
    return 0;
}



int solution(int n, int src){
    //int temp[n];
    //memset(temp,-1,sizeof(temp));
    //int src = 0;
    int A=0,B=0;
    colorArr[src]=0;
    queue<int> q;
    q.push(src);
    A += 1;//A same color with src,0

    
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int i=0;i<n;i++){
            if (G[u][i] && colorArr[i]==-1){
                colorArr[i]=1-colorArr[u];
                if (colorArr[u]==0) B+=1;
                else A+=1;
                q.push(i);
            }
            else if (G[u][i] && colorArr[i]==colorArr[u]){
                return -1;
            }
        }
    }
    
    //cout << "A" << A << endl;
    //cout << "B" << B << endl;
    return A<B ? A : B;
}

