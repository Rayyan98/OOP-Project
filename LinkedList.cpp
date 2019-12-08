#include "LinkedList.h"
#include "Projectile.h"
#include <iostream>
#include "Collision Detection.h"

using namespace std;

template <class T>

linkedList<T>::linkedList()
{
        this -> head = NULL;
        this -> tail = NULL;
}

template <class T>
linkedList<T>::~linkedList()
{
    node<T>* next = head;
    node<T>* cur = NULL;
    while (next != NULL)
    {
        cur = next;
        next = next -> next;
        delete cur;
    }
   std::cout << "List Deleted";
}

template <class T>
void linkedList<T>::pushAtTail(T* data)
 {
      node<T>* Node = new node<T>();
      Node->data = data;
      Node-> next = NULL;
      if(head == NULL)
      {
        head = Node;
        tail= Node;
        Node = NULL;
      }
      else
      {
        tail -> next = Node;
        tail = Node;
      }
    }

template <class T>
void linkedList<T>::pushAtHead(T* data)
{
    node<T>* Node = new node<T>();
    Node->data = data;
    Node -> next = NULL;
    if (head == NULL)
    {
        head = Node;
    }
    else
    {
        Node->next = this->head;
        this->head = Node;
    }
}

template<class T>

void linkedList<T>::pushAtPosition(T* data, int pos)
  {
    node<T>* pre = new node<T>();
    node<T>* cur = new node<T>();
    node<T>* Node = new node<T>();
    cur = head;
    for(int i = 1; i<pos; i++)
    {
      pre = cur;
      cur = cur -> next;
    }
    Node -> data = data;
    pre -> next = Node;
    Node->next=cur;
  }

template<class T>
T* linkedList<T>::popFromHead()
{
    node<T>* Node = new node<T>();
    Node = head;
//    cout << head -> data <<endl;
    head = head->next;
    delete Node;
}

template<class T>
T* linkedList<T>::popFromTail()
{
    node<T>* cur = new node<T>();
    node<T>* prev = new node<T>();
    cur = head;
    while(cur -> next != NULL)
    {
      prev = cur;
      cur = cur -> next;
    }
//    cout << tail -> data << endl;
    tail = prev;
    prev -> next = NULL;
    delete cur;
    return 0;
}

template<class  T>
T* linkedList<T>::deleteSomeValue(T* data)
{
    node<T>* cur;
    node<T>* prev;
    cur = head;
//        cout << " loop launched" << endl;
    while(cur->data != data && cur != 0)
    {
      prev = cur;
      cur = cur->next;
    }
    if(cur->data == data)
    {
        if(cur == head)
        {
            head = head->next;
            delete cur;
        }
        else
        {
            prev->next = 0;
            delete cur;
        }
    }
    return 0;
}

template<class T>
void linkedList<T>::pushToTail(T* data)
{
   T* temp = data;
   deleteSomeValue(data);
   pushAtTail(temp);
}

template<class T>
void linkedList<T>::bringToFront(T* data)
{
   T* temp = data;
   deleteSomeValue(data);
   pushAtHead(temp);
}

template<class T>
void linkedList<T>::show(SDL_Renderer* gRenderer)
{
    node<T>* Node;
    if (head == NULL)
    {
//        cout<<"\n Sorry list is empty.." << endl;
    }
    else
    {
        Node = head;
        while(Node != NULL)
        {
//            cout << " reached ";
//            cout << " entered loop ";
            Node->data->Render(gRenderer);
//            cout<< Node -> data <<"   ";
            Node = Node -> next;
        }
//        cout << endl;
    }
}

template<class T>
void linkedList<T>::update()
{
    node<T>* Node;
    if (head == NULL)
    {
//        cout<<"\n Sorry list is empty.." << endl;
    }
    else
    {
        Node = head;
        while(Node != NULL)
        {
//            cout << " reached ";
//            cout << " entered loop ";
            Node->data->UpdateSprite();
//            cout<< Node -> data <<"   ";
            Node = Node -> next;
        }
//        cout << endl;
    }
}

template<class T>
void linkedList<T>::clean()
{
    node<T>* temp = head;
    while(temp != 0)
    {
        T* p = temp->data;
        node<T>* n = temp->next;
        Point t = p->GetPosition();
//        cout << t.x << " " << t.y << endl;
        if(t.x > 800 || t.x < -160 || t.y > 600 || t.y < -160 || !p->GetStatus())
        {
            deleteSomeValue(p);
        }
        temp = n;
    }
}

enum{cNone, cHultHult, cHultHigh, cHultLow,
            cHighHult, cHighHigh, cHighLow,
            cLowHult , cLowHigh , cLowLow};

template<class T>
void linkedList<T>::checkCollissions(Character* chr)
{
    node<T>* temp = head;
    while(temp != 0)
    {
        int check = CollisionDetection::Check(temp->data->GetSprite(), chr->GetNextSprite());
        if(check == cHultHult || check == cHultHigh)
        {
//            cout << " sldfsalkdjf ";
            if(!temp->data->HasDamaged())
            {
                bool t = chr->HandleHit(cHultHigh, temp->data->GetDamage(), 16);
                temp->data->HandleHit(t);
            }
        }
        else if(check == cHultLow)
        {
//            cout << " sldkfjaslkdf ";
            if(!temp->data->HasDamaged())
            {
                bool t = chr->HandleHit(cHultLow, temp->data->GetDamage(), 16);
                temp->data->HandleHit(t);
            }
        }
        temp = temp->next;
    }
}

template class linkedList<Projectile>;
