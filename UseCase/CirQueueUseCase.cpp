//
// Created by Kun on 2021/4/25.
// 循环队列 Circle Queue 用例
//

#include <iostream>
#include "../DataStructure/CirQueue.h"

using namespace std;

int main(){
    int x;
    CirQueue<int> Q{};
    cout << "对5和8执行入队操作" << endl;
    Q.EnQueue(5);
    Q.EnQueue(8);
    cout << "当前队头元素为：" << Q.GetHead() << endl;
    try{
        x = Q.DeQueue();
        cout << "执行一次出队操作，出队元素是：" << x << endl;
    }catch (char *str){
        cout << str << endl;
    }
    try{
        cout << "请输入入队元素：" ;
        cin >> x;
        Q.EnQueue(x);
    }catch (char *str){
        cout << str << endl;
    }
    if(Q.Empty() == 1)
        cout << "队列为空" << endl;
    else
        cout << "队列非空" << endl;
    return 0;
 }

