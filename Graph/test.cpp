//
//  main.cpp
//  Data
//
//  Created by PierreVon on 2019/5/4.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#include <iostream>
#include "graph.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int v[]={1,2,3,4,5};
    int a[][5] = {
        0,1,0,1,1,
        1,0,1,0,0,
        0,1,0,0,0,
        1,0,0,0,1,
        1,0,0,1,0
    };
    int l = sizeof(v)/sizeof(v[0]);
    
    int **o = new int* [l];
    for(int i=0; i<l; i++)
        o[i] = new int[l];
    for(int i=0; i<l; i++)
        for(int j=0; j<l; j++)
            o[i][j] = a[i][j];
    
    int k = 0;
    graph g(v,o,l,k);
    g.getinfo();
    g.BFS();
    g.DFS();
    
    for(int i=0; i<l; i++)
        delete[] o[i];
    
    //    int v2[]={1,2,3,4};
    //    int a2[][4] = {0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0};
    //    int l2 = sizeof(v)/sizeof(v[0]);
    //    int k2 = 1;
    //    graph g2(v2,a2,l2,k2);
    //    g2.get();
    //    g2.BFS();
    //    g2.DFS();
    //    return 0;
}
