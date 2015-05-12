//
//  main.cpp
//  Mice and Maze
//
//  Created by LIUYiling on 11/05/15.
//  Copyright (c) 2015 LIUYiling. All rights reserved.
//  cd ./Library/Developer/Xcode/DerivedData/Mice_and_Maze-aibhdrlllnyusyatljfqkimoyuxv/

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;


int main(int argc, const char * argv[]) {
    int number;
    int N;//number of maze
    int E;//exit
    int T;//time
    int M;//connections
    
    cin >> number;

    while (number--){
        
        cin >> N >> E >> T >> M;
        int cells[T+1][N];
        memset(cells,0,sizeof(cells));
        cells[0][E-1] = 1;
        
        
        
        int a[M],b[M],c[M];
        for (int i=0;i<M;i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        
        int max = c[0];
        for(int i = 1; i<M; i++)
        {
            if(c[i] > max)
                max = c[i];
        }

        
        for (int i = 1;i <= T;i++) {
            memcpy(&cells[i],&cells[i-1],N*sizeof(int));
            for (int j=1;j<=max&&i>=j;j++) {
                for (int k=0;k<M;k++) {
                        for (int t=0;t<N;t++){
                            if (cells[i-j][t]==1 && c[k]==j && b[k]==t+1)
                            {   cells[i][a[k]-1] = 1;
                               // cout << "k:"<<k<< endl;
                               // cout << "a[k]:"<<a[k]<<endl;
                            }
                        }
                    
                }
            }
        }
        
        int sum = 0;
        for (int i=0;i<N;i++){
            sum += cells[T][i];
            //cout << " " << cells[T][i] ;
        }
        
        cout << sum << endl;
        if (number) cout << endl;
    
        
    }
    return 0;
}

