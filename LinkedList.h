#pragma once
#include "Node.h"
#include "SDL.h"
#include "Characters.h"

template <class T>

class linkedList
{
      node<T>* head;
      node<T>* tail;
  public:
      linkedList();
      ~linkedList();
      void pushAtTail(T* data);
      void pushAtHead(T* data);
      void pushAtPosition(T* data, int pos);
      T* popFromTail();
      T* popFromHead();
      T* deleteSomeValue(T* data);
      void pushToTail(T* data);
      void bringToFront(T* data);
      void show(SDL_Renderer*);
      void checkCollissions(Character*);
      void update();
      void clean();
};
