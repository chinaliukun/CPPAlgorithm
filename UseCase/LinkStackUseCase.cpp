//
// Created by Fiber-Doctor-2020 on 2021/4/25.
//


#include <iostream>
#include "../DataStructure/LinkStack.h"

using namespace std;
int main(){
    int x;
    LinkStack<int> S{};
    cout << "对15和10进行入栈操作" << endl;
    S.Push(15);
    S.Push(10);
    cout << "当前栈顶元素为：" << S.GetTop() << endl;
    try{
        x = S.Pop();
        cout << "已经执行一次出栈操作，删除元素" << x << endl;
    }catch (char * str)
    {
        cout << str << endl;
    }
    try{
        cout << "请输入待入栈元素：";
        cin >> x;
        S.Push(x);
    }catch (char * str){
        cout << str << endl;
    }
    if(S.Empty() == 1)
        cout << "栈为空" << endl;
    else
        cout << "栈不为空" << endl;
    return 0;
}