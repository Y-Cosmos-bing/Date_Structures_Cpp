# include <iostream>
# include <algorithm>


/*
大根堆：父比子大;  小根堆：子比父大;
堆结构:(用数组实现的完全二叉树结构)
    以数组来模拟完全二叉树时:以heapsize来控制堆结构    
    父节点:   (i - 1) / 2;
    左子节点:  2 * i + 1; 
    右子节点： 2 * i + 2;
堆结构的heapInsret和heapify操作;
堆结构的增大与减少
优先级队列结构，就是堆结构
*/

class Heap    // 大根堆排序的实现逻辑 
{
public:
    int *arr;      // 堆的数组实现 
    int heapsize;  // 堆的元素个数

private:
    static void heapInsert(Heap heap, int index)    
    {
        while (heap.arr[index] > heap.arr[(index - 1) / 2])
        {
            std::swap(heap.arr[index], heap.arr[(index - 1) / 2]);
            index = index - 1;
        }
    }

    static void heapify(Heap heap, int index)
    {
        int left = 2 * index + 1;
        while (left < heap.heapsize)
        {
            int largest = left + 1 < heap.heapsize && heap.arr[left + 1] > heap.arr[left] ? left + 1 : left;  // 找出子节点的最大值
            largest = heap.arr[index] >= heap.arr[largest] ? index : largest;
            if (index == largest) {break;}
            std::swap(heap.arr[index], heap.arr[largest]);
            index = largest;
            left = 2 * index + 1;
        }
        // int index = 0;
        // int son_largest = heap.arr[2 * index + 1] >= heap.arr[2 * index + 2] ? 2 * index + 1 : 2 * index + 2;
        // while (heap.arr[index] < heap.arr[son_largest])
        // {
        //     std::swap(heap.arr[index], heap.arr[son_largest]);
        //     index = son_largest;
        //     son_largest = heap.arr[2 * index + 1] >= heap.arr[2 * index + 2] ? 2 * index + 1 : 2 * index + 2;   
        // }
    }

    static void heap_sort(Heap heap)
    {
        for (int heapsize = 1; heapsize <= heap.heapsize; heapsize++)   // 先排出大根堆
        {
            heapInsert(heap, heapsize);
        }

        for (int heapsize = heap.heapsize; heapsize > 0; heapsize--)   // 每次只有根节点可以确定最大，取出最大值放至最后得到最大值，然后切断其与堆的联系，堆化后再次循环
        {
            std::swap(heap.arr[heapsize], heap.arr[0]);
            heapify(heap, 0);
        }
    }
};