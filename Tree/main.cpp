//
//  main.cpp
//  DataStruct
//
//  Created by PierreVon on 2019/5/2.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#include <iostream>
#include "bitree.h"
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {

    
    int a[] = {0,1,2,3,4,5,6};
    int l = sizeof(a)/sizeof(a[0]);
    
    bitree b(a, l);
    b.travel();
    b.ptravel();
    b.mtravel();
    b.btravel();
    
    int c[] = {0,1,2,-1,4,-1,6,7,8,9};
    int s = sizeof(c)/sizeof(c[0]);
    
    bitree k(c, s);
    k.travel();
    k.ptravel();
    k.mtravel();
    k.btravel();
    
    
    return 0;
}
