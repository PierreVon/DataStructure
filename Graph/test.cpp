//
//  main.cpp
//  DataStruct
//
//  Created by PierreVon on 2019/5/2.
//  Copyright © 2019年 PierreVon. All rights reserved.


#include <iostream>
#include "graph.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int v[]={1,2,3,4};
    int a[][4] = {0,1,0,1,1,0,1,0,0,1,0,0,1,0,0,0};
    int l = sizeof(v)/sizeof(v[0]);
    int k = 0;
    graph g(v,a,l,k);
    g.get();
    
    int v2[]={1,2,3,4};
    int a2[][4] = {0,1,1,1,0,0,0,0,0,1,0,0,1,0,0,0};
    int l2 = sizeof(v)/sizeof(v[0]);
    int k2 = 1;
    graph g2(v2,a2,l2,k2);
    g2.get();
    return 0;
}
