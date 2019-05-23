//
//  find.h
//  Data
//
//  Created by PierreVon on 2019/5/14.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef find_h
#define find_h

int seqentialfind(int a[], int len, int x){
    for(int i=0;i<len;i++)
        if(a[i] == x)
            return i+1;
    return -1;
}

int bfind(int a[], int len, int x){
    int low = 0, high = len-1;
    while (low <= high) {
        int mid = (low + high)/2;
        if(a[mid] == x)
            return mid+1;
        else if(a[mid] < x)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

#endif /* find_h */
