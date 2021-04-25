//
// Created by Kun on 2021/4/25.
// 循环队列 Circle Queue
//

#ifndef CPPALGORITHM_CIRQUEUE_H
#define CPPALGORITHM_CIRQUEUE_H

const int CirQueueSize = 100;
template <typename DataType>
class CirQueue{
public:
    CirQueue();
    void EnQueue(DataType x);
    DataType DeQueue();
    DataType GetHead();
    int Empty();
private:
    DataType data[CirQueueSize] ;
    int front, rear;
};

template<typename DataType>
int CirQueue<DataType>::Empty() {
    if(rear == front)
        return 1;
    return 0;
}

template<typename DataType>
CirQueue<DataType>::CirQueue() {
    // 一般循环队列都是从数组的高位开始
    front = rear = CirQueueSize - 1;
}

template<typename DataType>
void CirQueue<DataType>::EnQueue(DataType x) {
    if((rear + 1) % CirQueueSize == front) throw "上溢";
    rear = (rear+1) % CirQueueSize;
    data[rear] = x;
}

template<typename DataType>
DataType CirQueue<DataType>::DeQueue() {
    if(front == rear) throw "下溢";
    front = (front + 1) % CirQueueSize;
    return data[front];
}

template<typename DataType>
DataType CirQueue<DataType>::GetHead() {
    if(front == rear) throw "下溢";
    return data[(front + 1) % CirQueueSize];
}

#endif //CPPALGORITHM_CIRQUEUE_H
