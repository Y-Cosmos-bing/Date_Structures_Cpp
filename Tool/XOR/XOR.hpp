/*
异或运算：(无进位相加)
    相同为0，不同为1(非0)
*/

/*
1. o ^ N = N     N ^ N = 0
2.满足交换律和结合律
*/

// 利用信息差来交换数据的值

void XOR_operation(int (&a), int (&b)) {  // 前提为a, b 的变量映射的内存地址不一样，否则该操作会使值变为0;
    a = a ^ b;
    b = a ^ b;    // b = a;
    a = a ^ b;    // a = b;
}

void sum_XOR_operation(int (&a), int(&b)) {
    a = a - b;
    b = a + b;
    a = b - a;
}