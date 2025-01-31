/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>


void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // base case, exit once singly-linked list "in" is empty
  if (in == NULL){
    return;
  }

  // save next node in "in" list so that we do not lose track of list
  Node* nextElement = in -> next;

  // mod % 2 to check if even or odd
  if (in -> value % 2 == 0) {
    // disconnect node from in list by setting next value to null. Set current node of evens to current/ head node of in
    in -> next = NULL;  
    evens = in;

    // recursively call function split(), moving onto next element in list "evens" because 
    // current head of evens now points to current element/ head of ins 
    split(nextElement, odds, evens -> next);
  } else {
    // disconnect node from in list by setting next value to null. Set current node of evens to current/ head node of in
    in -> next = NULL;
    odds = in;

    // recursively call function split(), moving onto next element in list "odds" because 
    // current head of odds now points to current element/ head of ins 
    split(nextElement, odds -> next, evens);
  } 

  // ensures in list is empty and set to null 
  in = NULL;
}



