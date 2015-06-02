//
//  main.cpp
//  WiFi
//
//  Created by LIUYiling on 02/06/15.
//  Copyright (c) 2015 LIUYiling. All rights reserved.
// 二分法
/*一条大街，大家想建立WIFI，可是资金有限，问有限的WIFI下每家离自己最近热点的最大距离。
 以最大距离为本，假设已知最大距离为x,check一下x行不行的通。
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int nWifi,nHouse;
int house[100010];

int cmp (const void * a, const void * b)
{
    return *(int*)a - *(int*)b;
}

bool check(int d){
    int CNT = 1;
    int flag = house[0];
    for (int i=0;i<nHouse;i++){
        if (house[i]<=flag+d) continue;
        else {
            flag = house[i];
            CNT++;
            if (CNT>nWifi) return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int Ncase;
    scanf("%d",&Ncase);
    while (Ncase--){
        scanf("%d%d", &nWifi, &nHouse);
        for (int i=0;i<nHouse;i++){
            scanf("%d",house+i);
        }
        qsort(house, nHouse, sizeof(house[0]), cmp);
        int l = 0, r = house[nHouse-1], mid;
        //cout << l << r<< endl;
        while (l<r){
            mid = (l+r) >> 1;
            if (check(mid)) r = mid;
            else l = mid+1;
        }

        printf("%.1lf\n", r/2.);

    }
    return 0;
}
