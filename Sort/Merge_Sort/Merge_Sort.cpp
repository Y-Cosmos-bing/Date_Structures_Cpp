# include <iostream>
# include <algorithm>
# define Log(a) std::cout << a << std::endl;

template<size_t N>
int Arr_Length(int (&a)[N]) {return N;}

class MergeSort
{
public:
    // 传统的merge归并排序
    int* merge_sort_1(int* arr_1, int size_1, int* arr_2, int size_2)
    {
        int p1 = 0, p2 = 0;
        int p0 = 0;
        // 先处理异常情况
        if (size_1 == 0) {return arr_1;}
        if (size_2 == 0) {return arr_2;}
        
        int* ans = new int[size_1 + size_2];
        while (p1 < size_1 && p2 < size_2)
        {   
            if (arr_1[p1] <= arr_2[p2]) {ans[p0++] = arr_1[p1++];}
            else {ans[p0++] = arr_2[p2++];}
        }
        while (p1 < size_1) {ans[p0++] = arr_1[p1++];}
        while (p2 < size_2) {ans[p0++] = arr_2[p2++];}
        return ans;
    }

    // 递归版本的归并算法
    void merge_sort_2(int* arr, int L, int R)  // 实现在某一个无序数组的一个区间上变为有序
    {
        int M = R + ((L - R) >> 1);        
        merge_sort_2(arr, L, M);
        merge_sort_2(arr, M + 1, R);    // 本质上属于递归过程:当递归到无法递归，即分组到最小后，单个数有序，返回上一级和其右侧数merge，然后再返回，直至无法返回；
        merge(arr, L, M, R);
    }

    void merge(int* arr, int L, int M, int R)
    {
        int size = R - L + 1;
        int *help = new int[size];   // 创建一个辅助空间来存储merge后的(子)数组
        int phelp = 0, p1 = L, p2 = M + 1;
        
        if (L == M || M + 1 == R) {return;}   // 处理错误
        
        while (p1 <= M && p2 <= R )  // 都不越界时循环
        {
            help[phelp++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
        }

        while (p1 > M)  // p1 越界时循环
        {
            help[phelp++] = arr[p2++];
        }
        while (p2 > R) // p2 越界时循环
        {
            help[phelp++] = arr[p1++];
        }

        for (int i = 0; i < size; i++)   // 返回原数组
        {
            arr[L + i] = help[i];
        }
        delete(help);
    }

    // 递归版本的小和问题的merge解法
        int minSum_MergeSort(int* arr, int L, int R)  // 实现在某一个无序数组的一个区间上变为有序
    {
        int M = R + ((L - R) >> 1);           
        return minSum_Merge(arr, L, M, R) + minSum_MergeSort(arr, L, M) + minSum_MergeSort(arr, M + 1, R);
    }

    int minSum_Merge(int* arr, int L, int M, int R)
    {
        int s = 0;
        int size = R - L + 1;
        int *help = new int[size];   
        int phelp = 0, p1 = L, p2 = M + 1;
        
        if (L == M || M + 1 == R) {return;}   
        
        while (p1 <= M && p2 <= R )  
        {
            s += arr[p1] < arr[p2] ? (R - p2 + 1) * arr[p1] : 0 ;
            help[phelp++] = arr[p1] < arr[p2] ? arr[p2++] : arr[p1++];
        }

        while (p1 > M)  // p1 越界时循环
        {
            help[phelp++] = arr[p2++];
        }
        while (p2 > R) // p2 越界时循环
        {
            help[phelp++] = arr[p1++];
        }

        // 返回原数组
        for (int i = 0; i < size; i++)
        {
            arr[L + i] = help[i];
        }
        delete(help);
    }
};