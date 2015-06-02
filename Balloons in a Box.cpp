//
//  main.cpp
//  Balloons in a Box
//
//  Created by LIUYiling on 31/05/15.
//  Copyright (c) 2015 LIUYiling. All rights reserved.
//把气球放到盒子里，想让气球占的体积最大
//1.枚举法· 如果半径为0就相当于没有放进去
//2.输出为四舍五入的整数
//如何定义PI


#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const double pi=acos(-1.0);

struct Point{
    double x,y,z;
    Point (double x=0,double y=0,double z=0): x(x),y(y),z(z) {}
    double dist(Point p) { return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)+(z-p.z)*(z-p.z)); }
    //double k(Point p) { return double(p.y-y)/(p.x-x);}
};

Point pArray[10];
Point O,Z;

double r[10]; //半径
int Nballoon;
double maximumV;
int permutation[10];



int main(int argc, const char * argv[]) {
    // insert code here...
    int CNT=0;
    while (scanf("%d",&Nballoon)==1 && Nballoon){
        CNT++;
        
        scanf("%lf%lf%lf", &O.x, &O.y, &O.z);
        scanf("%lf%lf%lf", &Z.x, &Z.y, &Z.z);

        
        for (int i=0;i<Nballoon;i++){
            scanf("%lf%lf%lf", &pArray[i].x, &pArray[i].y, &pArray[i].z);
            permutation[i]=i;
        }
        
        maximumV = 0;
        
        do {
            double V = 0;
            for (int i = 0; i < Nballoon; i++) {
                double pr = 1e+30;
                pr = min(pr, fabs(pArray[permutation[i]].x - O.x));
                pr = min(pr, fabs(pArray[permutation[i]].x - Z.x));
                pr = min(pr, fabs(pArray[permutation[i]].y - O.y));
                pr = min(pr, fabs(pArray[permutation[i]].y - Z.y));
                pr = min(pr, fabs(pArray[permutation[i]].z - O.z));
                pr = min(pr, fabs(pArray[permutation[i]].z - Z.z));

                for (int j = 0; j < i; j++) {
                    double t = pArray[permutation[i]].dist(pArray[permutation[j]]);
                    pr = min(pr, t - r[permutation[j]]);
                }
                r[permutation[i]] = pr < 0 ? 0 : pr;
                V += 4/3.0 * pi * pow(r[permutation[i]], 3);
            }
            maximumV = max(maximumV, V);
        } while (next_permutation(permutation, permutation+Nballoon));

        double totV = fabs((O.x - Z.x) * (O.y - Z.y) * (O.z - Z.z));
        printf("Box %d: %.0lf\n\n", CNT, totV - maximumV);
        
    }
    return 0;
}
