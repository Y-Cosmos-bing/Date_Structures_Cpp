# define LIST_INIT_SIZE 100
# define ElemType int
typedef struct StaticSqList
{
    ElemType elem[LIST_INIT_SIZE];  // 存储数据元素的一维数组
    int length;                     // 线性表的当前长度
} StaticSqList;
