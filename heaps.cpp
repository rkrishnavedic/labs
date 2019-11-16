//
//  heaps.cpp
//  Labs
//
//  Created by Rahul Krishna on 13/11/19.
//  Copyright © 2019 Rahul Krishna. All rights reserved.
//

#include "total.h"
using namespace std;

void heapify(int arr[],int n, int i){
    int g=i,l=2*i+1,r=2*i+2;
    if(l<n && arr[l]>arr[g]){
        g=l;
    }
    if(r<n && arr[r]>arr[g]){
        g=r;
    }
    if(g!=i){
        swap(arr[i], arr[g]);
        heapify(arr, n, g);
    }
}

void heapsort(int arr[], int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr, n, i);
        
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
       }
}

int main(){
    cout<<"OM\n";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    heapify(arr, n, 0);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapsort(arr, n);
    for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
