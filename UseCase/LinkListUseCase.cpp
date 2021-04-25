//
// Created by Kun on 2021/4/20.
// 单链表 Single Link List 用例
//
#include <iostream>
#include "../DataStructure/LinkList.h"

using namespace std;
void linkListTest () {
    cout << "正在进行 LinkList 测试..." << endl;
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
int main(){
    linkListTest();
}
