#include <iostream>
#include "DataStructure/SeqList.h"
#include "DataStructure/LinkList.h"

void seqListTest () {
    // 线性表测试
    int r[5] = {1,2,3,4,5}, i, x;
    SeqList<int> L{r, 5};
    // 打印测试
    L.printList();
    // 插入测试
    try {
        L.insert(6,5);
        L.printList();
    } catch (char *str) {
        cout << str << endl;
    }
    // 删除测试
    L.del(3);
    L.printList();
    // 按位查找
    x = L.get(3);
    cout << "第三个位置的值为：" << x << endl;
    // 按值查找
    i = L.locate(5);
    cout << "5所在的位置是：" << i << endl;
}

void linkListTest () {
    int r[5] = {1,2,3,4,5}, i ,x;
    LinkList<int> L{ r, 5 };
    L.printList();
    try {
        L.insert(6, 5);
        L.printList();
    } catch (char *str) {
        cout << str << endl;
    }
    L.del(3);
    L.printList();
    cout << "当前长度为：" << L.len() << endl;
    cout << "第5个元素的值为：" << L.get(5) << endl;
    cout << "元素5所在的位置为：" << L.locate(5) << endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    linkListTest();
    return 0;
}
