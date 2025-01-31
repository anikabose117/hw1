/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;

// prototypes
void printList(Node* head);
void deleteList(Node* head);

int main(int argc, char* argv[])
{
    // test case: no values in "in"
    Node* odds = NULL;
    Node* evens = NULL;
    Node* list1 = NULL;
    cout << "Before: ";
    printList(list1);
    split(list1, odds, evens);
    cout << "Odds test 1: ";
    printList(odds);
    cout << "Evens test 1: ";
    printList(evens);
    cout << "Ins test 1: ";
    printList(list1);
    deleteList(odds);
    deleteList(evens);
    deleteList(list1);  
    list1 = NULL;
    
    // test case: only evens
    odds = NULL;
    evens = NULL;
    Node* list2 = new Node(2, new Node(4, new Node(6, NULL)));;
    cout << "Before: ";
    printList(list2);
    split(list2, odds, evens);
    cout << "Odds test 2: ";
    printList(odds);
    cout << "Evens test 2: ";
    printList(evens);
    cout << "Ins test 2: ";
    printList(list2);
    deleteList(odds);
    deleteList(evens);
    deleteList(list2);
    list2 = NULL;

    // test case: single element, odd
    odds = NULL;
    evens = NULL;
    Node* list3 = new Node(5, NULL);
    cout << "Before: ";
    printList(list3);
    split(list3, odds, evens);
    cout << "Odds test 3: ";
    printList(odds);
    cout << "Evens test 3: ";
    printList(evens);
    cout << "Ins test 3: ";
    printList(list3);
    deleteList(odds);
    deleteList(evens);
    deleteList(list3);
    list3 = NULL;

    // test case: single element, even
    odds = NULL;
    evens = NULL;
    Node* list4 = new Node(8, NULL);
    cout << "Before: ";
    printList(list4);
    split(list4, odds, evens);
    cout << "Odds test 4: ";
    printList(odds);
    cout << "Evens test 4: ";
    printList(evens);
    cout << "Ins test 4: ";
    printList(list4);
    deleteList(odds);
    deleteList(evens);
    deleteList(list4);
    list4 = NULL;
}


// print list for testing
void printList(Node* head) {
    while (head != NULL) {
        cout << head -> value << " ";
        head = head -> next;
    }
    cout << endl;
}

// allocated lists for testing, this now deletes from memory
void deleteList(Node* head) {
	Node* current = head;
	while(current != NULL){
		Node* next = current -> next;
		delete current;
		current = next;
	}
}