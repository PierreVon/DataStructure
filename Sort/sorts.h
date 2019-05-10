//
//  sorts.h
//  Data
//
//  Created by PierreVon on 2019/5/10.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#ifndef sorts_h
#define sorts_h

void insertsort(int a[], int len){
    int tmp,j;
    for(int i=1;i<len;i++){
        tmp = a[i];
        for(j=i;j>0&&tmp<a[j-1];j--)
            a[j] = a[j-1];
        a[j] = tmp;
    }
}

void bubblesort(int a[],int len){
    int tmp;
    for(int i = len-1; i>0; i--){
        for(int j=0;j<i;j++)
            if(a[j]>a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
    }
}

int pivot(int a[],int start,int end){
    int tmp = a[start];
    while (start<end) {
        while(tmp <= a[end] && start<end) --end;
        if(start<end)
            a[start] = a[end];
        while(a[start] <= tmp && start<end) ++start;
        if(start<end)
            a[end] = a[start];
    }
    a[start] = tmp;
    return start;
}

void quicksort(int a[],int start,int end){
    if(start<end){
        int k = pivot(a, start, end);
        quicksort(a, start, k-1);
        quicksort(a, k+1, end);
    }
}

#endif /* sorts_h */
