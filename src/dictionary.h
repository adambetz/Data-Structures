#ifndef DICTIONARY_H
#define DICTIONARY_H

#include<iostream>
using namespace std;

template <typename K, typename T>
class Dictionary {
   public:
      Dictionary();
      ~Dictionary();

      T & lookup(K) throw(string);
      void insert(K, T &) throw(string); //duplicate
      T & remove(K) throw(string); //not found
      K * listKeywords();

      int getSize(){return size;}

   private:
      struct Entry{
         K Key;
         T *obj;
      };

      Entry *data; //array of entries
      int cap;
      int size;

      int search(K);
      void growing();
};
#endif


template<typename K, typename T>
Dictionary<K,T>::Dictionary(){
   cap = 10;
   size = 0;
   data = new Entry[cap];
}

template<typename K, typename T>
Dictionary<K,T>::~Dictionary(){
   for(int i = 0; i < size; i++)
      delete data[i].obj;
   delete [] data;
}

template<typename K, typename T>
int Dictionary<K,T>::search(K key){
   for(int i = 0; i < size; i++){
      if (data[i].Key == key)
         return i; //location
   }
   return -1; //not found
}

template<typename K, typename T>
void Dictionary<K,T>::growing(){
   cap *= 2;
   Entry *ptr = new Entry[cap];
   for (int i = 0; i < size; i++){
      ptr[i].Key = data[i].Key;
      ptr[i].obj = data[i].obj;
   }
   delete [] data;
   data = ptr;
}

template<typename K, typename T>
T & Dictionary<K,T>::lookup(K key) throw(string){
   int index = search(key);
   if (index == -1)
      throw string("key not found");
   else
      return *(data[index].obj);
}


template<typename K, typename T>
void Dictionary<K,T>::insert(K key, T &obj) throw(string){
   if(size >= cap)
      growing();

   int index = search(key);
   if (index != -1)
      throw string("keyword already exist");

   data[size].Key = key;
   data[size].obj = &obj;
   size++;
}

template<typename K, typename T>
T & Dictionary<K,T>::remove(K key) throw(string){
   int index = search(key);
   if (index == -1)
      throw string("keyword not found");

   T &ref = *(data[index].obj);
   size--;
   if(size > 0 && index != size){
      data[index].Key = data[size].Key;
      data[index].obj = data[size].obj;
   }
   return ref;
}

template<typename K, typename T>
K * Dictionary<K,T>::listKeywords(){
   K *keyList = new K[size];
   for (int i = 0; i < size; i++)
       keyList[i] = data[i].Key;
   return keyList;
}
