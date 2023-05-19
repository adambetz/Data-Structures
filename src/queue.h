#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>

using namespace std;

class FullQueue{
};

class EmptyQueue{
};

template<typename T>
class Queue {
   public:
      Queue();
      ~Queue();

      void enqueue(T &) throw(FullQueue);
      T & dequeue() throw(EmptyQueue);

      bool isEmpty(){return (head == tail);}
      bool isFull(){return ((tail+1)%cap == head);}

      virtual int getCap(){return cap;}

   private:
      static const int cap = 15;
      int head;
      int tail;

      T* data;
};

#endif

template<typename T>
Queue<T>::Queue(){
   head = 0;
   tail = 0;
   data = new T[cap];
}

template<typename T>
Queue<T>::~Queue(){
  delete [] data;
}

template<typename T>
void Queue<T>::enqueue(T &d) throw(FullQueue){
   if(isFull())
      throw FullQueue();
   data[tail] = d;
   tail = (tail+1)%cap; //circular array
}

template<typename T>
T & Queue<T>::dequeue() throw(EmptyQueue){
   if(isEmpty())
      throw EmptyQueue();
   T &d = data[head];
   head = (head+1)%cap;
   return d;
}
