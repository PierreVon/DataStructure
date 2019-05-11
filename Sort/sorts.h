//
//  sorts.h
//  Data
//
//  Created by PierreVon on 2019/5/10.
//  Copyright © 2019年 PierreVon. All rights reserved.
//

#include <vector>
#include <cmath>
#ifndef sorts_h
#define sorts_h

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

//insert
void insertsort(int a[], int len){
    int tmp,j;
    for(int i=1;i<len;i++){
        tmp = a[i];
        for(j=i;j>0&&tmp<a[j-1];j--)
            a[j] = a[j-1];
        a[j] = tmp;
    }
}

//bubble
void bubblesort(int a[],int len){
    for(int i = len-1; i>0; i--){
        for(int j=0;j<i;j++)
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
    }
}

//quick
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

//select
void selectsort(int a[],int len){
    for(int i=0;i<len;i++){
        int min = 100000;
        int index=i;
        for(int j=i;j<len;j++)
            if(a[j]<min){
                min=a[j];
                index=j;
            }
        if(i!=index)
            swap(a[i], a[index]);
    }
}

//heap
void heapsort(int a[],int len){
    for(int i=len-1;i>0;i--){
        int mid = i/2;
        while (mid>-1) {
            int left = 2*mid+1;
            int right = 2*mid+2;
            if(left<=i)
                if(a[mid]<a[left])
                    swap(a[mid],a[left]);
            if(right<=i)
                if(a[mid]<a[right])
                    swap(a[mid],a[right]);
            mid--;
        }
        swap(a[0], a[i]);
    }
}

//radix
void radixsort(int a[],int len){
    std::vector<std::vector<int>> buckets(10);
    for(int i=0;i<3;i++){
        int devider = static_cast<int>(pow(10,i));
        for(int j=0;j<len;j++)
            buckets[(a[j]/devider)%10].push_back(a[j]);
        int index=0;
        for (auto & theBucket : buckets){
            for (int & k : theBucket)
                a[index++] = k;
            theBucket.clear();
        }

    }
}

#endif /* sorts_h */
