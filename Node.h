#pragma once
#include "Projectile.h"

template <class T>

class node
{
 public:
     T* data;
     node<T>* next;

     ~node();
};

template class node<Projectile>;
