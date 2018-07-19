#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP
#include "BSTNode.hpp"
#include <list>
#include <iterator>

using namespace std;
// Notice this class extends the std::iterator class.
template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:

  BSTNode<Data>* curr;

public:

  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */ 
  BSTIterator(BSTNode<Data>* curr);

  /** Dereference operator. */
  Data operator*() const;
  
  /** Pre-increment operator. */
  BSTIterator<Data>& operator++();

  /** Post-increment operator. */
  BSTIterator<Data> operator++(int);

  /** Equality test operator. */
  bool operator==(BSTIterator<Data> const & other) const;

  /** Inequality test operator. */ 
  bool operator!=(BSTIterator<Data> const & other) const;

};

  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */ 
template<typename Data>
BSTIterator<Data>::BSTIterator(BSTNode<Data>* curr) {
  this->curr = curr;
  // Remember the keyword "this" which stores a pointer to the calling object.
  // It will be helpful to distinguish between the parameter "curr" and the 
  // member variable "curr"
}

/** Dereference operator. */
template<typename Data>
Data BSTIterator<Data>::operator*() const {
  return curr->data;
}
  
/** Pre-increment operator. */
template<typename Data>
BSTIterator<Data>& BSTIterator<Data>::operator++() {
  // Call the successor method of the BSTNode pointed to by curr.
  curr = curr->successor();
  return *this;
}

/** Post-increment operator. */
template<typename Data>
BSTIterator<Data> BSTIterator<Data>::operator++(int) {
  BSTIterator before = BSTIterator(curr);
  ++(*this);
  return before;
}

/** Equality test operator. */ // TOD
template<typename Data>
bool BSTIterator<Data>::operator==(BSTIterator<Data> const & other) const {

    return this->curr == other.curr;
  

  // Notice that other is a reference and not a pointer, thus it cannot be null
  // Return true if other is equal to the calling object
  // Two iterators are equal if they point to the same BSTNode in the same BST  

//  return false;

}

/** Inequality test operator. */ 
template<typename Data>
bool BSTIterator<Data>::operator!=(BSTIterator<Data> const & other) const {

     return this->curr != other.curr;
  
  
  // Notice that other is a reference and not a pointer, thus it cannot be null
  // Return true if other is NOT equal to the calling object
  // Two iterators are equal if they point to the same BSTNode in the same BST

//  return false;

}


#endif //BSTITERATOR_HPP
