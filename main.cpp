#include <iostream>
#include "DataStructure/SeqList.h"
#include "DataStructure/LinkList.h"
#include "DataStructure/StaList.h"

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


void staListTest(){
    cout << "���ڽ��� StaList ����..." << endl;
    int r[5] = {1,2,3,4,5}, i ,x;
    StaList<int> L{ r, 5 };
    L.printList();
}

int main() {
    return 0;
}
