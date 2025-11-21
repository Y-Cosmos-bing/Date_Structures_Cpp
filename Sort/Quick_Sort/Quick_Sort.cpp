# include <iostream>
# include <algorithm>
# define Log(a) std::cout << a << std::endl;

class Quick_Sort
{
public:
    static void quickSort_1(int *arr, int L, int R)   // 在一个无序混乱数组中，使其某一区间上有序
    {
        if (L >= R) {return;}                 // 添加递归终止条件，当左端点等于右端点，即只剩一个元素时越界，这是一个不断分治的过程
        int partion = partion_1(arr, L, R);     // 每一次partion都排好一个数：此时的时间复杂度是O(N^2)
        quickSort_1(arr, L, partion - 1);    // 基准元素不需要再动，只用递归其两侧的区域
        quickSort_1(arr, partion + 1, R);
    }

private:
    static int partion_1(int *arr, int L, int R)
    {
        int pivot = R;       // 以数组右端点为基准;
        int p_slow = L - 1;  // 有序区初始化为起点的前一位;
        int p_quick = L;     // 初始化遍历比较指针;     
        while (p_quick < R)  // 确定比较指针不越界的情况下循环
        {
            if (arr[p_quick] <= arr[pivot])        // 比较指针指向的元素与基准元素比较
            {std::swap(arr[p_quick++], arr[++p_slow]);}    // 若小于等于，则将比较指针指向的元素与有序区的笑一个元素交换位置
            else                     // 若大于，则该位置比较指针指向的元素不动，指针后移 
            {p_quick++;}                        
        }
        std::swap(arr[p_slow + 1], arr[pivot]);   // 将基准元素放在有序区的下一个位置上，能确保基准之前的元素不大于TA，基准之后的元素都大于TA;
        return p_slow + 1;
    }



public:
    static void quickSort_2(int *arr, int L, int R)   // 在一个无序混乱数组中，使其某一区间上有序
    {
        if (L >= R) {return;}                   // 添加递归终止条件，当左端点等于右端点，即只剩一个元素时越界，这是一个不断分治的过程
        int *partion = partion_2(arr, L, R);    // 每一次partion都排好一类数：此时的时间复杂度是O(N^2)
        quickSort_2(arr, L, partion[0] - 1);    // 基准区域不需要再动，只用递归其两侧的区域
        quickSort_2(arr, partion[1] + 1, R);
        delete[] partion;
    }

private:
    static int *partion_2(int *arr, int L, int R)
    {
        /*此种partion的方法类似于两头向中间挤压，将其依照基准划分为三个区域，小于，等于，大于*/
        int pivot = arr[R];       // 以数组右端点为基准;
        int lp = L - 1;  // 左有序区初始化为起点的前一位;
        int rp = R;      // 右有序区初始化为基准的位置
        int p = L;       // 初始化遍历指针
        while (p < rp)  // 确定比较指针不越界的情况下循环
        {
            if (arr[p] < pivot)        // 比较指针指向的元素与基准元素比较
            {std::swap(arr[p++], arr[++lp]);}    // 若小于，则将遍历指针指向的元素与有序区的后一个元素交换位置,然后比较指针后移下一个元素
            
            else if (arr[p] > pivot)               
            {std::swap(arr[p], arr[--rp]);}      // 若大于，则将遍历指针指向的元素与右有序区的前一个元素交换位置，但比较指针不移动（因为此时的交换过来的元素还未与基准比较）
            
            else 
            {p++;}                        
        } 
        
        /*
        交换之前：                                                       交换之后：
            < 区 【L, lp】                                                   < 区 【L, lp】
            = 区 【lp + 1, rp - 1】          -----------》》》》》            = 区 【lp + 1, rp】 
            > 区 【rp , R】                                                  > 区 【rp + 1, R】
        */ 
                                
        std::swap(arr[rp], arr[R]);   // 将基准元素放在右有序区的第一个位置上，能确保等于区之前的元素小于TA，基准区域之后的元素都大于TA;
 
        int *partion = new int[2];
        partion[0] = lp + 1;
        partion[1] = rp;
        return partion;
    }

};


void PrintArray(int* array, int length) {
    for (int i = 0; i < length; i++) {Log(array[i]);}
}

int main() {  // 测试
    int array[] = {6,3,9,2,7,1,2,5,7,2,6,8};
    int length = sizeof(array) / sizeof(int);
    PrintArray(array, length);
    Log("================");
    Quick_Sort::quickSort_2(array, 0, length - 1);
    PrintArray(array, length);
    
}
