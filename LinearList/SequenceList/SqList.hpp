// 首先确定一下线性表结构的宏   
// # define SqList StaticSqList/DynamicSqList
// 此处以动态线性表为例
# include "DynamicSqList.hpp"
# define SqList DynamicSqList
# include <cstdlib>

// 顺序表初始化操作
// InitiList(&L)    // 初始化一个空的线性表(分配必要的资源，并且设置初始状态)
// 构建一个最大容量为MAXSIZE的顺序表L
void InitList_Sq(SqList &L, int maxsize = LIST_INIT_SIZE, int incresize = LISTINCREMENT)
{
    L.elem = (ElemType *)malloc(maxsize * sizeof(ElemType));   // 分配一个最大容量为MAXSIZE的数组空间
    if (!L.elem) exit(1);   // 存储分配失败(非正常运行导致退出程序)
    L.length = 0;          // 顺序表中的当前(初始)元素个数为0；
    L.listsize = maxsize;  // 该顺序表可以容纳maxsize个数据元素；
    L.incrementsize = incresize;  // 需要时可以扩容incresize个元素空间
}   

// 判断顺序表是否为空
bool ListEmpty_Sq(SqList L)
{
    if (L.length == 0) {return true;}
    else {return false;}
}

// 顺序表求表长操作
int ListLength_Sq(SqList L) {return L.length;}

// LocateElem(L, e)   // 在线性表中查找元素a，如果找到返回其位置，未找到返回0或特定值
int LocateElem_Sq(SqList L, ElemType e)
{
    // 查找顺序表的元素是需要遍历的，那如果遇到重复的元素呢？？？
    // 那就暂且定为如果有重复元素那么优先输出最小下标
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e) {return i;}
        else {return -1;}
    }
}

// 检查是否可再插入元素,如果不可再插入就扩容
void CanInsert_Sq(SqList L)
{if (L.length + 1 == L.listsize) // 刚好满了，加不进去了
    {
        L.elem = (ElemType*)realloc(L.elem, (L.listsize + L.incrementsize) * sizeof(ElemType));
        if (!L.elem) {exit(1);}      // 存储更新失败
        L.listsize += L.incrementsize;   // 更新存储容量
    }}

// 顺序表前插:在L的第i个元素之前插入新的元素e，如果表中当前容量不足，则按照预定义的增量扩容
bool ListPreInsert_Sq(SqList L, int i, ElemType e)
{
    // 检查i值是否合法
    if (i <= 0 || i > L.length) {return false;}
    CanInsert_Sq(L);
        // 检查容量是否够，如果不足则扩容
        // if (L.length + 1 == L.listsize) // 刚好满了，加不进去了
        // {
        //     L.elem = (ElemType*)realloc(L.elem, (L.listsize + L.incrementsize) * sizeof(ElemType));
        //     if (!L.elem) {exit(1);}      // 存储更新失败
        //     L.listsize += L.incrementsize;   // 更新存储容量
        // }
    // 被插入的元素及其之后的元素右移
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.elem[j + 1] == L.elem[j];
    }
    L.elem[i - 1] = e;
    L.length++;
    return true;
}

// 顺序表后插:在顺序表的第i个元素之后插入新的元素e，如果表中当前容量不足，则按照预定义的增量扩容;
bool ListBackInsert_Sq(SqList L, int i, ElemType e)
{
    if (i <= 0 || i > L.length) {return false;}
    CanInsert_Sq(L);
        // 检查容量是否够，如果不足则扩容
        // if (L.length + 1 == L.listsize) // 刚好满了，加不进去了
        // {
        //     L.elem = (ElemType*)realloc(L.elem, (L.listsize + L.incrementsize) * sizeof(ElemType));
        //     if (!L.elem) {exit(1);}      // 存储更新失败
        //     L.listsize += L.incrementsize;   // 更新存储容量
        // }
    for (int j = L.length - 1; j >= i; j--)
    {
        L.elem[j + 1] = L.elem[j]; 
    }
    L.elem[i] = e;
    L.length++;
    return true;
}

// 顺序表尾插
bool ListTailInsert_Sq(SqList L, ElemType e)
{
    CanInsert_Sq(L);
        // 检查容量是否够，如果不足则扩容
        // if (L.length + 1 == L.listsize) // 刚好满了，加不进去了
        // {
        //     L.elem = (ElemType*)realloc(L.elem, (L.listsize + L.incrementsize) * sizeof(ElemType));
        //     if (!L.elem) {exit(1);}      // 存储更新失败
        //     L.listsize += L.incrementsize;   // 更新存储容量
        // }
    L.elem[L.length] = e;
    L.length++;
    return true;
}

// 顺序表查插？在递增有序顺序表L中查找插入新的元素e(自动寻找位置，如果有相同值，就插入最后一个相同值之后)
bool ListCheckInsert_Sq(SqList L, ElemType e)
{
   CanInsert_Sq(L);
   int i = 0;
   for ( ; i < L.length - 1 && L.elem[i] <= e; i++);
   for (j = L.) 

}

