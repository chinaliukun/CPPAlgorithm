#include <iostream>
#include "SeqList.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    // ���Ա����
    int r[5] = {1,2,3,4,5}, i, x;
    SeqList<int> L{r, 5};
    // ��ӡ����
    L.printList();
    // �������
    L.insert(6,6);
    L.printList();
    // ɾ������
    L.del(3);
    L.printList();
    // ��λ����
    x = L.get(3);
    cout << "������λ�õ�ֵΪ��" << x << endl;
    // ��ֵ����
    i = L.locate(5);
    cout << "5���ڵ�λ���ǣ�" << i << endl;
    return 0;
}
