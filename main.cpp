#include <iostream>
#include "SeqList.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    // 线性表测试
    int r[5] = {1,2,3,4,5}, i, x;
    SeqList<int> L{r, 5};
    // 打印测试
    L.printList();
    // 插入测试
    L.insert(6,6);
    L.printList();
    // 删除测试
    L.del(3);
    L.printList();
    // 按位查找
    x = L.get(3);
    cout << "第三个位置的值为：" << x << endl;
    // 按值查找
    i = L.locate(5);
    cout << "5所在的位置是：" << i << endl;
    return 0;
}
