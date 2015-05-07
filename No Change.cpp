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
using namespace std;

bool bingo(int low,int up,int n, int m,int x[5],int total){
    if (total == 0) return true;
    else if (n == 1) {
        if (  (total % x[m-1] == 0) && (total / x[m-1]<=up) && (total / x[m-1]>=low) ) 
            return true;
        else return false;
    }
    else if (low > up) return false;
    else {
        bool flag = false;
        int rest = 0;
        for (int i=m-n+1;i<m;i++) {
            rest += x[i];
        }
        for (int i=low;i<=up;i++){
            int new_total = total - i*x[m-n];
            int new_low = ( new_total - 1 )/rest + 1;
            int new_up = new_total / x[m-n+1];
            new_up = (new_up < i) ? new_up : i ;
            flag = bingo(new_low,new_up,n-1,m,x,new_total);
            if (flag) {
                return true;
            }
        }
        return false;
    }
}


int main(int argc, char *argv[]){
    int number;
    int tmp;
    int x[5];
    
    cin >> tmp;
    number = tmp;
    
    for (int i=0;i<number;i++){
        cin >> tmp;
        int total = tmp;
        cin >> tmp;
        int types = tmp;
        
        if (i!=0) cout << endl;

        
        int sum = 0;
        for (int i=0;i<types;i++){
            cin >> tmp;
            x[i] = tmp;
            sum += x[i];
        }
        
        
    int low = (total-1)/sum+1;
    int up  = total / x[0];
                
    bool flag = 0;
        
    flag = bingo(low,up,types,types,x,total);
    if (flag)cout << "YES" << endl;
        else cout << "NO" << endl ;
        
    }
    
    
    
    return 0;
    
}
