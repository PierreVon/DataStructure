//
//  main.cpp
//  Data
//
//  Created by PierreVon on 2019/5/4.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#include <iostream>
#include "btree.h"
#include "hash.h"

using namespace std;

//template <typename T>
//bool cmp(T a, T b){
//    return a<b;
//}

int main(int argc, const char * argv[]) {

    int a[] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
    int l = sizeof(a)/sizeof(a[0]);
    btree b(a,l);
    b.travel();
    return 0;
}
