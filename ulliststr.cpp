#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
  /**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
  // no loops, runs in O(1)
  void ULListStr::push_back(const std::string& val){
    // first check whether node exists
    if(empty()){
      // no item exists in list, so must create new item
      // adjust data members accordingly
      tail_ = new Item();
      head_ = tail_;
      tail_ -> val[0] = val;
      tail_ -> last = 1;
      tail_ -> first = 0;
    }
    // if last element is less than ARRSIZE, then there is unused space within the item's array
    else if (tail_ -> last < ARRSIZE){
      // fill next available unused space and adjust data members accordingly
      tail_ -> val[tail_ -> last] = val;
      tail_ -> last++;
    }
    else {
      // if at this point, then there is exists a full tail_ list, so a new Item must be allocated and 
      // value put at first available position
      Item * temp = new Item();
      // make adjustments to data members accordingly and link to previous nodes
      temp -> prev = tail_;
      temp -> next = NULL;
      tail_ -> next = temp;
      tail_ = temp;
      tail_ -> val[0] = val;
      tail_ -> last = 1;
      tail_ -> first = 0;
    }
    // increase size bc new value added
    size_++;
  }

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  // no loops, runs in O(1)
  void ULListStr::pop_back(){
    // checking if there are any nodes, if not exit out of function
    if (empty()){
      return;
    }

    // check if there is more than one element in the tail_ list, if so just adjust data member last
    if (tail_ -> last - tail_ -> first > 1){
      tail_ -> last--;
    } 
    else {
      // remove last element, which is only element
      // delete item
      Item* temp = tail_;
      tail_ = tail_ -> prev;

      if (tail_ != NULL){
        tail_ -> next = NULL;
      } 
      else {
        head_ = NULL;
      }
      delete temp;
    }

    // decrease size because one less value 
    size_--;
  }
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  // no loops, runs is O(1)
  void ULListStr::push_front(const std::string& val){

    // first check whether node exists
    if(empty()){
      // no item exists in list, so must create new item
      // adjust data members accordingly
      head_ = new Item();
      tail_ = head_;
      head_ -> val[ARRSIZE - 1] = val;
      head_ -> last = ARRSIZE;
      head_ -> first = ARRSIZE - 1;
    }
    // if first element is greater than 0, then there is unused space in the front within the item's array 
    else if (head_ -> first > 0){
      // fill previous available unused space and adjust data members accordingly
      head_ -> first--;
      head_ -> val[head_ -> first] = val;
    }
    else {
      // if at this point, then there is exists a full head_ list, so a new Item must be allocated and 
      // value put at last available position (in new previous node)
      Item * temp = new Item();
      // make adjustments to data members accordingly and link to next nodes
      temp -> next = head_;
      temp -> prev = NULL;
      head_ -> prev = temp;
      head_ = temp;
      head_ -> val[ARRSIZE - 1] = val;
      head_ -> last = ARRSIZE;
      head_ -> first = ARRSIZE - 1;
    }
    // increase size bc new element added
    size_++;
  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  // no loops, runs in O(1)
  void ULListStr::pop_front(){
    // checking if there are any nodes, if not exit out of function
    if (empty()){
      return;
    }

    // check if there is more than one element in the head_ list, if so just adjust data member first
    if (head_ -> last - head_ -> first > 1){
      head_ -> first++;
    } 
    else {
      // remove last element, which is only element
      // delete item
      Item* temp = head_;
      head_ = head_ -> next;
      if (head_ != NULL){
        head_ -> prev = NULL;
      } 
      else {
        tail_ = NULL;
      }
      delete temp;
    }

    // decrease size because one less value 
    size_--;
  }
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  // no loops, runs in O(1)
  std::string const & ULListStr::back() const{
    // last refers to first "unused" space/ index in the back of the list, so one less would equal back element
    return tail_ -> val[tail_ -> last - 1];
  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  // no loops, runs in O(1)
  std::string const & ULListStr::front() const{
    // first refers to first occupied space/ index in the head_/first of the list
    return head_ -> val[head_ -> first];
  }

    /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  // runs in O(n) because of the while loop that iterates linearly
  std::string* ULListStr::getValAtLoc(size_t loc) const{
    // sanity check, checking if location is within the size constraints
    if (loc >= size_ || loc < 0){
      return NULL;
    }  

    // set beginning index to 0 to iterate through entire list
    size_t index = 0;
    // create temp variable that will iterate through nodes, instead of working directly w/ head_
    Item* temp = head_;

    // continues through linked list until runs out of nodes (Items)
    while (temp != NULL){
      // size of array within current node (see how much of list is currently being used)
      size_t arraySize = temp -> last - temp -> first;   

      // checks if location is within the current node and will return reference to it. if not then it will increment to next Item node
      if (loc < index + arraySize){
        return &(temp -> val[temp -> first + (loc - index)]);
      }
      temp = temp -> next;
      index += arraySize;
    }
    return NULL;
  }


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
