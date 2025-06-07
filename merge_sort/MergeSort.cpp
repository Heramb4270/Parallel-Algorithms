#include "MergeSort.hpp"

MergeSort::MergeSort(std::vector<int> *nums){
    this->nums = nums;
}
MergeSort::~MergeSort(){}


void MergeSort::mergeSortAlgo(int left,int right){
    if(left>=right){
        return;
    }
    int mid = left + (right - left) /2;
    mergeSortAlgo(left,mid);
    mergeSortAlgo(mid+1,right);

    int n1 = mid-left +1;
    int n2 = right - mid;
    int leftArr[n1];
    int rightArr[n2];
    for(int i=0;i<n1;i++){
        leftArr[i] = (*nums)[i + left];
    }
    for(int i=0;i<n2;i++){
        rightArr[i] = (*nums)[i + mid+1];
    }
    int i=0,j=0;
    int m = left;
    while(i<n1 && j<n2){
        if(leftArr[i] < rightArr[j]){
            (*nums)[m] = leftArr[i];
            i++;
        
            
        }else{
            (*nums)[m] = rightArr[j];

            j++;
        }
        m++;
    }

    while(i<n1){
        (*nums)[m] = leftArr[i];
        i++;
        m++;
    }

    while(j<n2){
        (*nums)[m] = rightArr[j];

        j++;
        m++;
    }


}
void MergeSort::sort(){
    if(nums->size() == 0){
        return ;
    }
    MergeSort::mergeSortAlgo(0,nums->size());
}