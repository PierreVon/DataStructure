//
//  main.cpp
//  Data
//
//  Created by PierreVon on 2019/5/4.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#include <iostream>

using namespace std;

//template <typename T>
//bool cmp(T a, T b){
//    return a<b;
//}

int main(int argc, const char * argv[]) {
    
    int v[]={4,6,2,8,12,0,-1};
    int l = sizeof(v)/sizeof(v[0]);
    sort(v, v+l, greater<int>());
    for(int i=0;i<l;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
