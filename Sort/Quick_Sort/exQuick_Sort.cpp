// // 引入背景
// # include <iostream>
// # include <algorithm>
// # define Log(a) std::cout << a << std::endl;

// class ex_Quick_Sort
// {
// public:
//     // 给定一个数组和一个数，把小于等于这个数的放在数组的左边，大于的放在数组的右边(时间复杂度为O（N）,空间复杂度为O（1）);
//     static void double_sort_1(int *arr, int arr_size, int num)   // 二分：一份为小于等于某个数，一份为大于某个数
//     {
//         // 双指针（头尾指针）
//         int start = 0, end = arr_size - 1;
//         while (start != end)
//         {
//             if (arr[start] <= num)
//             {start++;}
//             else
//             {std::swap(arr[start], arr[end--]);}
//         }
//         // 以下是第一次写的时候的错误版本，该版本忽略了交换之后重新到达i位置上的数值没有比较
//         // for (int i = 0; start != end; i++)
//         // {
//         //     if (i == 0 && arr[i] <= num) 
//         //     {continue;}
//         //     else if (arr[i] <= num && i != 0)
//         //     {std::swap(arr[i], arr[start++]);}
//         //     else 
//         //     {std::swap(arr[i], arr[end--]);}
//         // }
//     }

//         static void double_sort_2(int *arr, int arr_size, int num)   // 二分：一份为小于等于某个数，一份为大于某个数
//     {
//         // 双指针（快慢指针）
//         int p_slow = 0, p_quick = 0;   // 慢指针指向有序区的右侧的第一个数
//         while (p_quick < arr_size)    // 快指针未越界  
//         {
//             if (arr[p_quick] <= num)
//             {std::swap(arr[p_quick++], arr[p_slow++]);}
//             else
//             {p_quick++;}
//         }

//     }
// };


// static void PrintArray(int* array, int length) {
//     for (int i = 0; i < length; i++) {Log(array[i]);}
// }

// int main() {  // 测试
//     int length = 6;
//     int array[length] = {6,3,9,2,7,1};
//     PrintArray(array, length);
//     Log("================");
//     ex_Quick_Sort::double_sort_2(array, length, 5);
//     PrintArray(array, length);
    
// }
