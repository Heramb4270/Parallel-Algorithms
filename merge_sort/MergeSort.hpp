#ifndef MERGESORT_H
#define MERGESORT_HI
#include <vector>


class MergeSort{
    private:
        std::vector<int> *nums;
    public:
        MergeSort(std::vector<int> *nums);
        ~MergeSort();
        void sort();
        void mergeSortAlgo(int left,int right);
};


#endif