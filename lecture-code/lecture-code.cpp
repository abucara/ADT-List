#include "../object.h"
#include "../integer.h"
#include "../person.h"

#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
#include "../linkedlist.h"
int main(int argc, char* argv[]){

	if (argc != 2){
		cerr << "Not enough parameters, give me the array size!" << endl;
		cerr << "Usage: " << endl;
		cerr << argv[0] << " size" << endl;
		return 1;
	}

	Object** myObjects = nullptr;
	size_t size = atoi(argv[1]);
	myObjects = new Object*[size];

	myObjects[0] = new Person("Jake",2);
	myObjects[1] = new Integer(3);
	myObjects[2] = new Integer(7);
	myObjects[3] = new Person("Blanca", 44);

    Object *firstPerson=new Person("aly", 5);
    Object *secondPerson=new Person("jeuy", 10);
    Object *thirdPerson=new Person("lai", 17);
    cout<<"Printing linked list ";
    LinkedList *lst= new LinkedList();


    lst->Insert(firstPerson, 0);
    lst->Insert(secondPerson, lst->IndexOf(firstPerson));
    lst->Insert(thirdPerson, lst->IndexOf(secondPerson));
    cout<<"\nBefore reverse\n"<<lst->ToString()<<endl;
    LinkedList *secondList= lst->reverse(lst);
    cout<<"After reverse \n"<<secondList->ToString()<<endl;




	for (int i = 0; i < size; ++i) {
		cout << myObjects[i]->ToString() << endl;
	}


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