#include <iostream>
#include "DataStructure/SeqList.h"
#include "DataStructure/LinkList.h"

void seqListTest () {
    // ���Ա����
    int r[5] = {1,2,3,4,5}, i, x;
    SeqList<int> L{r, 5};
    // ��ӡ����
    L.printList();
    // �������
    try {
        L.insert(6,5);
        L.printList();
    } catch (char *str) {
        cout << str << endl;
    }
    // ɾ������
    L.del(3);
    L.printList();
    // ��λ����
    x = L.get(3);
    cout << "������λ�õ�ֵΪ��" << x << endl;
    // ��ֵ����
    i = L.locate(5);
    cout << "5���ڵ�λ���ǣ�" << i << endl;
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
    cout << "��ǰ����Ϊ��" << L.len() << endl;
    cout << "��5��Ԫ�ص�ֵΪ��" << L.get(5) << endl;
    cout << "Ԫ��5���ڵ�λ��Ϊ��" << L.locate(5) << endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    linkListTest();
    return 0;
}
