#include <iostream>
#include <chrono>
#include "merge_sort/MergeSort.hpp"
#include "merge_sort/ParallelSort.hpp"

int main(int argc,char* arguments[]){
    const int SIZE = 1000000;
    std::vector<int> nums(SIZE);
    for(int i=0;i<SIZE;i++){
        nums[i] = rand() % 1000000;
    }

    MergeSort *normalSort = new MergeSort(&nums);
    auto startTime = std::chrono::high_resolution_clock::now();
    std::cout<<std::endl;

    // std::cout<<"-------- Before Sort -------- "<<std::endl;
    // for(int i=0;i<SIZE;i++){
    //     std::cout<<nums[i]<<" ";
    // }
    normalSort->sort();
    std::cout<<std::endl;
    // std::cout<<"-------- After Sort -------- "<<std::endl;
    // for(int i=0;i<SIZE;i++){
    //     std::cout<<nums[i]<<" ";
    // }
    auto endTime = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> difference = endTime - startTime;

    std::cout<<std::endl<<"Merger Sort Duration Without Multithreading = "<<difference.count()<<" seconds"<<std::endl;

    delete normalSort;


    Parallel_MergeSort *parallelSort = new Parallel_MergeSort(&nums);

    
    auto startTime2 = std::chrono::high_resolution_clock::now();
    std::cout<<std::endl;
    parallelSort->sort();
    
    auto endTime2 = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> difference2 = endTime2 - startTime2;

    std::cout<<std::endl<<"Merger Sort Duration With Multithreading = "<<difference2.count()<<" seconds"<<std::endl;
    delete parallelSort;


    return 0;
}