/*
时间复杂度是 O(N)
实现逻辑，两个for循环，每一次将0~i个范围内的最大值确定放在最右端
*/
# include <iostream>
# include <algorithm>
# define Log(a) std::cout << a << std::endl;

class BubbleSort
{
public:
    static void sort(int* array, int length)
    {
        for (int i = length - 1; i > 0; i--)  // 从 0 ~ i   （i从length-1 ~ 1）
        {
            for (int j = 0; j < i; j++)   // 从 0 ~ i比较两个数的大小，较大的数被推到右侧（大的气泡先冒出）
            {
                if (array[j] > array[j + 1]) {std::swap(array[j], array[j + 1]);}
            }
        }
    }
};


void PrintArray(int* array, int length)
{
    for (int i = 0; i < length; i++) {Log(array[i]);}
}

int main()   // 测试
{
    int length = 6;
    int array[length] = {67,3,98,24,7,1};
    PrintArray(array, length);
    BubbleSort::sort(array, length);
    PrintArray(array, length);
    
}