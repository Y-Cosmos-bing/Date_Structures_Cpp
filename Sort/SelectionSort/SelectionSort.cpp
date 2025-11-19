/*在未排序的部分中，不断选择最小(或最大)的元素，将其放到已经排序部分的末尾*/
// 选择排序
# include <algorithm>
# include <iostream>
# define Log(a) std::cout << a << std::endl;

class SelectionSort
{
public:
    static void sort(int* array, int length)
    {
        for (int i = 0; i < length; i++)   // 实现 i ~ lenght-1
        {
            int minIndex = i;
            for (int j = i + 1; j < length; j++)   // 在 i ~ length-1 上寻找最小值
            { 
                minIndex = (array[minIndex] <= array[j]) ? minIndex : j;
            }
            if (minIndex != i)
            {
                std::swap(array[i], array[minIndex]);
            }
        }
    }
};

void PrintArray(int *array, int length)
{
    for (int i = 0; i < length; i++) {Log(array[i]);}
    Log("==============================================")
}

int main()   // 测试
{
    int length = 6;
    int array[length] = {67,3,98,24,7,1};
    PrintArray(array, length);
    SelectionSort::sort(array, length);
    PrintArray(array, length);
    
}