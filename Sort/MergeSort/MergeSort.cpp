# include <iostream>
# include <algorithm>
# define Log(a) std::cout << a << std::endl;

template<size_t N>

class MergeSort
{
public:
    int* sort(int* arr1, int size1, int* arr2, int size2)
    {
        int p1 = 0, p2 = 0;
        int p0 = 0;
        // 先处理异常情况
        if (size1 == 0) {return arr1;}
        if (size2 == 0) {return arr2;}
        
        int* ans = new int[size1+size2];
        while (p1 < size1 && p2 < size2)
        {   
            if (arr1[p1] <= arr2[p2]) {ans[p0++] = arr1[p1++];}
            else {ans[p0++] = arr2[p2++];}
        }
        while (p1 < size1) {ans[p0++] = arr1[p1++];}
        while (p2 < size2) {ans[p0++] = arr2[p2++];}
        return ans;
    }
};