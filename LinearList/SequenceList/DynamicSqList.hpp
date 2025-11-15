# define LIST_INIT_SIZE 100
# define LISTINCREMENT 10  // (默认)增补空间量
# define ElemType int 
typedef struct DynamicSqList
{
    ElemType *elem;     // 存储当前元素的一维数组
    int length;         // 线性表的当前长度
    int listsize;       // 当前分配的数组容量(以ElemTyep为单位)
    int incrementsize;  // 增补空间量(以ElemType为单位)
} DynamicSqList;

