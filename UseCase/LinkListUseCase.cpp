//
// Created by Fiber-Doctor-2020 on 2021/4/20.
//
#include <iostream>
#include "../DataStructure/LinkList.h"

using namespace std;
void linkListTest () {
    cout << "���ڽ��� LinkList ����..." << endl;
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
    cout << "��ǰ����Ϊ��" << L.len() << endl;
    cout << "��5��Ԫ�ص�ֵΪ��" << L.get(5) << endl;
    cout << "Ԫ��5���ڵ�λ��Ϊ��" << L.locate(5) << endl;
}
int main(){
    linkListTest();
}
