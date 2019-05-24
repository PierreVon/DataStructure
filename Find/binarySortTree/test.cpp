//
//  main.cpp
//  Data
//
//  Created by PierreVon on 2019/5/4.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#include <iostream>
#include "btree.h"
#include "biSortTree.h"

using namespace std;

//template <typename T>
//bool cmp(T a, T b){
//    return a<b;
//}

int main(int argc, const char * argv[]) {

    int c[] = {54,23,8,12,124,67,3,199};
    int l = sizeof(c)/sizeof(c[0]);
    biSortTree t(c,l);
    t.travel();
    t.del(8);
    t.travel();
    t.del(124);
    t.travel();
    return 0;
}
