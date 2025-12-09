// ----------------------Leet Code problem 88 - (Merge Sorted Array)-------------------

#include<stdio.h>

int main(){
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 2, 2};
    int m = 3, n = 3;
    int ptr1 = m-1, ptr2 = n-1, ptr3 = (m+n) - 1;
    while(ptr2 >= 0){
        if(ptr1 >= 0 && nums1[ptr1] > nums2[ptr2]){
            nums1[ptr3] = nums1[ptr1];
            ptr1--;
        }else{
            nums1[ptr3] = nums2[ptr2];
            ptr2--;
        }
        ptr3--;
    }
    for(int i = 0; i < (m+n); i++){
        printf("%d ", nums1[i]);
    }
    return 0;
}