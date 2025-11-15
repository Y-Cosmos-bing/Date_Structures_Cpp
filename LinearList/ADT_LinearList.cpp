/*
ADT list 
{
    Date:
    Operation:
        InitiList(&L)    // 初始化一个空的线性表(分配必要的资源，并且设置初始状态)
        CreateList(&L)   // 创建线性表(根据输入创建一个具体的线性表，用于构建表的内容)
        ListEmpty(L)     // 判断线性表L是否为空并返回布尔值
        ListLength(L)    // 返回线性表的长度，及表中的元素个数
        LocateElem(L, e)   // 在线性表中查找元素a，如果找到返回其位置，未找到返回0或特定值
        PriorElem(L, cur_e, &pre_e)   //获取线性表L中元素cur_e的前驱元素，通过pre_e返回，
                                        如果cur_e是第一个元素，则操作失败
        NextElem(L, cur_e, &next_e)      // 获取线性表L中元素cur_e的后继元素，通过next_e返回，
                                        如果cur_e是最后一个元素，则操作失败
        ListInsert(&L, i, e)   // 在线性表L的第i个位置插入元素e，插入后，原本的第i个元素及其
                                  之后的元素依次后移
        ListDelete(&L, i, &e)  // 输出线性表中的第i个元素，并通过e返回被删除元素的值
        GetElen(L, i, &e)      // 获取线性表中的第i个元素，并通过e返回
        ListTraverse(L)        // 遍历线性表，通常是对每个元素执行某种操作(打印)
        DestoryList(&L)        // 销毁线性表，释放其占用资源

    在参数中，带有&符号的表示该参数是引用传递，即在函数内部修改该参数会影响到外部实参(cpp中由引用或指针实现，C中由指针实现)
    
}
*/