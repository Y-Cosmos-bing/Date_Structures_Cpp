# include <iostream>
# include <algorithm>
# define Log(a) std::cout << a << std::endl;

class Insertion
{
public:
    void straight_sort(int* arr, int arr_size)
    {
        for (int i = 0; i < arr_size; i++)
        {
            for (int j = i - 1; arr[i] ; j--)
            {
                if (arr[i] < arr[j]) {std::swap(arr[j], arr[j + 1]);}
            }
        }
    }
};