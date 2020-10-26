#ifndef Queue_h
#define Queue_h
#include <String>
#include <vector>
#include <iostream>

#include "Node.h"

using namespace std;

template<class T>
class Queue
{
private:
    Node<T>* head;
    Node<T>* rear;
    Node<T>* aux;
    int size = 0;

public:
    Queue();
    T dequeue();
    void enqueue(T data);
    T front();
    T back();
    int getSize();
    void clear();
    void print();
    bool isEmpty()
};

template<class T>
Queue<T>::Queue() {
    head = NULL;
    rear = NULL;
    aux = NULL;
    size = 0;
}

template<class T>
void Queue<T>::enqueue(T data) {
    if (isEmpty()) {
        head = new Node<T>(data);
        rear = head;
    }
    else {
        rear = new Node<T>(data);
        rear->next = rear;
    }
    size++;
}


template<class T>
T Queue<T>::front() {
    if (isEmpty()) {
        throw runtime_error("Queue is empty");
    }
    return head->data;
}

template<class T>
T Queue<T>::back() {
    if (isEmpty()) {
        throw runtime_error("Queue is empty");
    }
    return rear->data;
}


template<class T>
T Queue<T>::dequeue() {
    T output;
    if (isEmpty()) {
        throw runtime_error("Queue is empty");
    }
    else {
        aux = head;
        output = aux->data;
        head = aux->next;
        delete aux;
        size--;
    }
    cout << endl;
    return output;
}

template<class T>
void Queue<T>::print() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    aux = head;
    cout << "queue element : ";
    while (aux != NULL) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

#endif