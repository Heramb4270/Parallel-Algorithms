#include "ParallelSort.hpp"
#include <thread>
Parallel_MergeSort::Parallel_MergeSort(std::vector<int> *nums){
    this->nums = nums;
}
Parallel_MergeSort::~Parallel_MergeSort(){}

void Parallel_MergeSort::Parallel_mergeSortAlgo(int left,int right){
    if(left>=right){
        return;
    }
    int mid = left + (right - left) /2;
    std::thread left_thread([this,left,mid]{Parallel_mergeSortAlgo(left,mid);});
    std::thread right_thread([this,mid,right]{Parallel_mergeSortAlgo(mid+1,right);});
    left_thread.join();
    right_thread.join();

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
void Parallel_MergeSort::sort(){
    if((*nums).size() == 0){
        return ;
    }
    int size = (*nums).size();
    std::thread main_thread([this,size]{Parallel_MergeSort::Parallel_mergeSortAlgo(0,size);});
    main_thread.join();
    
}