#ifndef PARALLEL_MERGESORT_H
#define PARALLEL_MERGESORT_H
#include <vector>

class Parallel_MergeSort{
    private:
        std::vector<int> *nums;
    public:
        Parallel_MergeSort(std::vector<int> *nums);
        ~Parallel_MergeSort();
        void sort();
        void Parallel_mergeSortAlgo(int left,int right);
};


#endif