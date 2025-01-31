#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

// prototypes
void printList(ULListStr& list);

int main(int argc, char* argv[])
{
    ULListStr list;

    // test case: push_back
    list.push_back("one");
    list.push_back("two");
    printList(list);

    // test case: push_front
    list.push_front("three");
    list.push_front("four");
    printList(list);

    // test case: pop_back
    list.pop_back();
    printList(list); 

    // test case: pop_front
    list.pop_front();
    printList(list);

    // test case: pop_front until empty
    list.pop_front();
    list.pop_front();
    printList(list); 


}

// print list for testing
void printList(ULListStr& list) {
    cout << "Size: " << list.size() << endl;
    if (!list.empty()) {
        cout << "Front: " << list.front() << endl;
        cout << "Back: " << list.back() << endl;
    }
    cout << "Elements: ";
    for (size_t i = 0; i < list.size(); i++) {
        cout << list.get(i) << " ";
    }
    cout << endl;
}
