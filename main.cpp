//
//  main.cpp
//  test
//
//  Created by 马敬唐 on 9/3/19.
//  Copyright © 2019 马敬唐. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void QuickSort(vector<int> &nums,int start,int end){
    if(start >= end) return;
    int pivot = nums[(start+end)/2];
    int left = start,right = end;
    while(left<=right){
        while(left<=right and nums[right] > pivot){
            right--;
        }
        while(left<=right and nums[left] < pivot){
            left++;
        }
        if(left <= right){
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
    QuickSort(nums,start,right);
    QuickSort(nums,left,end);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v = {1,5,3,2,7,2,9,10,0};
    QuickSort(v,0,v.size()-1);
    for(auto a : v)
        cout<<a<<endl;
    return 0;
}
