//
//  main.cpp
//  Buy or Build
//
//  Created by LIUYiling on 30/05/15.
//  Copyright (c) 2015 LIUYiling. All rights reserved.
//

//Used array of array to store the sub networks.
//compare function overwrite
//How to get a full combination...SO ~~TACKTIVE.

#include <iostream>
#include<algorithm>
#include<bitset>
#include <cstring>

using namespace std;


int network[10][1010];
int Nedges;
int subNetNodes[10];
int father[1010];


struct Point
{
    int x, y;
    //Point(int s,int m) : x(s), y(m) {}
    int dist(Point p)
    {
        return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
    }
};


struct Edge
{
    int src, dst, dist;
    bool operator<(const Edge& b) const{
        return dist < b.dist;}
};

Point p[1010];
Edge e[1010*1010];

void MakeSet (int n){
    for (int i=1;i<=n;i++){
        father[i]=i;
    }
}

int FindSet (int s){ //Why the other 2 doesn't work.
    //if (x != father[x]) father[x] = FindSet(father[x]);
    //return father[x];
    
    //return (father[index] == index) ? index : (father[index] = FindSet(father[index]));
    int t = s;
    while(s != father[s]) s = father[s];
    while(father[t] != s) {          //change p along the path
        int tmp = father[t];
        father[t] = s;
        t = tmp;
    }
    return s;
}

bool UnionSet (int a, int b){ //The other one doesn't work, because we should change all the nodes allong the way.
    //a, b are index , if they belong to the same set, return true.
    /*if (FindSet(a) == FindSet(b))
        return true;
    else {
        father[b] = father[a];
        return false;
    }*/
    
    a = FindSet(a);
    b = FindSet(b);
    if (a != b)
    {
        father[a] = b;
        return false;
    }
    return true;
}

int kurskal(){
    int cost = 0;
    for (int i=0;i<Nedges;i++){
        if (!UnionSet(e[i].src,e[i].dst))
            cost += e[i].dist;
    }
    return cost;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int numberOfCase;
    scanf("%d",&numberOfCase);
    while (numberOfCase--){
        memset(network, 0, sizeof(network));
        memset(subNetNodes, 0, sizeof(subNetNodes));
        
        
        int n,q;//n cities, q subnetworks
        scanf("%d %d",&n,&q);
        for (int i=0;i<q;i++){
            int nNet,moneyNet;
            scanf("%d %d",&nNet,&moneyNet);
            network[i][0]=moneyNet;
            subNetNodes[i]=nNet;
            for (int j=1;j<=nNet;j++){
                scanf("%d",&network[i][j]);
            }
        }
        
        for (int i=1;i<=n;i++)
            scanf("%d %d",&p[i].x,&p[i].y);
        
        Nedges=0;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++){
                e[Nedges].dist = p[i].dist(p[j]);
                e[Nedges].src = i;
                e[Nedges].dst = j;
                Nedges++;
            }
        sort(e,e+Nedges);
        
      //  for (int i=0;i<Nedges;i++){
      //      printf("%d ",e[i].dist);
      //  }
        
        //==============START=============
        MakeSet(n);
        int result = kurskal();
        for (int i=0;i<(1<<q);i++){
            MakeSet(n);
            int cost = 0;
            for (int j=0;j<q;j++){
                if ((1<<j) & i){
                    cost += network[j][0];
                    for (int k=2;k<=subNetNodes[j];k++){
                        UnionSet(network[j][k-1], network[j][k]);
                    }
                }
            }
            result = min(result,cost+kurskal());
        }
        
        cout << result << endl;
        if (numberOfCase) cout << endl;


    }
    return 0;
}

    
