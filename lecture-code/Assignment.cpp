#include "../object.h"
#include "../integer.h"
#include "../person.h"

#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
#include "../linkedlist.h"
int main(){



    Object** myObjects = nullptr;
    size_t size = 4;
    myObjects = new Object*[size];

    myObjects[0] = new Person("Jake",2);
    myObjects[1] = new Person("aly", 5);
    myObjects[2] = new Person("jeuy", 10);
    myObjects[3] = new Person("Blanca", 44);
    myObjects[4] = new Person("Blanca", 44);

    cout<<"Printing linked list ";
    LinkedList *lst= new LinkedList();


    lst->Insert(myObjects[0], 0);
    lst->Insert(myObjects[1], lst->IndexOf(myObjects[0]));
    lst->Insert( myObjects[2], lst->IndexOf(myObjects[1]));
    lst->Insert( myObjects[3], lst->IndexOf(myObjects[2]));


    cout<<"\nBefore reverse\n"<<lst->ToString()<<endl;
    LinkedList *secondList= lst->reverse(lst);
    cout<<"After reverse \n"<<secondList->ToString()<<endl;

    lst->Insert( myObjects[4], lst->IndexOf(myObjects[3]));

    cout<<"\nBefore eleminating\n"<<lst->ToString()<<endl;
    LinkedList *thirdList= lst->EliminateDuplicates(lst);
    cout<<"After Elemination \n"<<thirdList->ToString()<<endl;




    for (int i = 0; i < size; ++i) {
        delete myObjects[i];
    }
    delete[] myObjects;



    return 0;
}



/*

LinkedList *GetReversedLinkedList(LinkedList *lst){

    Node *current = lst->_head;

    Node *prev = NULL, *next = NULL;

    while (current != NULL) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    _head = prev;
}

  */