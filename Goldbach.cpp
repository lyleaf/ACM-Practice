//
//  main.cpp
//  Goldbach
//
//  Created by LIUYiling on 05/05/15.
//  Copyright (c) 2015 LIUYiling. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


bool isPrime (int a){
    if (a==2) return 1;
    else if (a % 2 == 0) return 0;
    for (int i=3;i<a/2+2;i+=2){
        if (a % i == 0)
            return 0;
    }
    return 1;
}




int main(int argc, char *argv[]){
    int number;
    int tmp;
    while (true){
        cin >> tmp;
        number = tmp;
        
        if (number == 0) break;
        int x=0;
        int y=0;
        for (int a=2;a<number/2+1;a++){
            if (isPrime(a)) {
                x = a;
                int b = number-a;
                if(isPrime(b))
                {
                    cout << number << " = " << a << " + " << b << endl;
                    y = b;
                    break;
                }
            }
        }
        if (x==0) cout << "Goldbach's conjecture is wrong." << endl;
    }
    
    return 0;

}

    
