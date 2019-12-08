#include "Node.h"

template <class T>

node<T>::~node()
{
    delete data;
}
