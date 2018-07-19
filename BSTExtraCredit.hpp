#ifndef BSTEXTRACREDIT_HPP
#define BSTEXTRACREDIT_HPP

//#include "BST.hpp"
//#include "BSTInt.h"
#include "BSTNodeInt.h"
#include "BSTNodeInt.cpp"
//#include "BSTNode.hpp"
#include <iostream>


/* Header declaration for BSTEC that holds ints. BSTEC uses BSTNodeInt's
 * Nodes to hold data of type int, and contains its own methods to
 * balance out the tree.*/


class BSTEC{

public:

   BSTNodeInt* root = NULL;

   /** Insert the items into bst. Return true if the item was added
   *  as a result of this call to insert, false if an item equal to 
   *  this one was already in this BST.
   */

  bool insert(int item);

  /** Return the number of items.
   */
  unsigned int size();

  /** Return the height of the BST.
      Height of tree with just root node is 0
      height of an empty tree is -1
   */
  int height();


  /** Return true if the tree is empty, else false. 
   */
  bool empty();


  /** Return the difference of height in left subtree
  * and right subtree.
  */
  int getBalance(BSTNodeInt* node);


private:
  unsigned int isize;
  signed int balance;
  unsigned int height_left;
  unsigned int height_right;


  /** Left rotate the node. Make node2 as a new node and node1 be the left
  *   subtree of node2. Return the new root after rotation.
  */
  BSTNodeInt*  leftRotate (BSTNodeInt* node1, BSTNodeInt* node2);



  /** Right rotate the node. Make node2 as a new node and node1 be the right
  *   subtree of node2. Return the new root after rotation.
  */
  BSTNodeInt*  rightRotate (BSTNodeInt* node1, BSTNodeInt* node2);


  /** the helper function to traversal the tree with
  * postorder to find the height of tree
  */
  int heightH(BSTNodeInt* node);

 };





   /** Insert the items into bst. Return  true if the item was added
   *  as a result of this call to insert, false if an item equal to 
   *  this one was already in this BST. Then, calculate the balance
   *  of each node along the path to root from the inserted node.
   *  Depending on the balance value, we will rotate(or not) the
   *  tree accordingly.
   */

  bool BSTEC::insert(int item){
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    return true;
  }

  BSTNodeInt* curr = root;
  BSTNodeInt* temp = root;
    
  while (curr != NULL){
    if (item < curr->data) {
      temp = curr;
      curr = curr->left;
    }
    else if (curr->data < item) {
      temp = curr;
      curr = curr->right;
    }
    else {
      return false;
    }
  }
  

  // Ready to insert
  BSTNodeInt* newNode = new BSTNodeInt(item);

  if (item < temp->data) {
    temp->left = newNode;
    newNode->parent = temp;
  }
  else {
    temp->right = newNode;
    newNode->parent = temp;
  }
  ++isize;

  //check whether the tree is balance
  while(newNode->parent != NULL){
  //get the balance of the parent node as long as the parent exists
  balance = getBalance(newNode->parent);

  //check if balance is 2 or -2
  if(balance > 1){
    if(item < newNode->parent->left->data){
      //Perform right rotation
      rightRotate(newNode->parent,newNode->parent->left);
      break;
    }
    else if(newNode->parent->left->data < item) {
      //Perform left-right rotation
       newNode->left = leftRotate(newNode->parent->left,
	newNode->parent->left->right);
       rightRotate(newNode->parent,newNode->parent->left);
       break;
    }
  }
  if(balance < -1){
    if(item < newNode->parent->right->data ){
    //Perform right-left rotation
    newNode->right = rightRotate(newNode->parent->right,
	newNode->parent->right->left);
    leftRotate(newNode->parent,newNode->parent->right);
    break;
    }
    else{
    //Perform left rotation
    leftRotate(newNode->parent,newNode->parent->right);
    break;
    }

  }
    newNode = newNode->parent;


  }

  return true;

  }

  /** Left rotate the node. Make node2 as a new node and node1 be the left
  *   subtree of node2. Return the new root after rotation.
  */
  BSTNodeInt* BSTEC::leftRotate (BSTNodeInt* node1, BSTNodeInt* node2){
    //Save the parent of the unbalanced node1, in case we need to link
    //it to a new node.
    BSTNodeInt* temparent = node1->parent;
    BSTNodeInt* t = node2->left;
    node1->right=t;
    if(t!=NULL){
	t->parent = node1;
    }    
    node2->left = node1;
    node1->parent=node2;
    
    node2->parent = temparent;
    if(temparent!=NULL)//if this is NULL, that might meant we need a new root.
      temparent->right= node2;
    else
      root = node2;
    return node2;

  }



  /** Right rotate the node. Make node2 as a new node and node1 be the right
  *   subtree of node2. Return the new root after rotation. This is really
  *   just a reversal of leftRotate.
  */

  BSTNodeInt* BSTEC::rightRotate(BSTNodeInt* node1, BSTNodeInt* node2){
    //Save the parent of the unbalanced node1, in case we need to link
    //it to a new node. 
     BSTNodeInt* temparent = node1->parent;
     BSTNodeInt* t = node2->right;
     node1->left=t;
     if(t!=NULL){
	t->parent = node1;
     }
     node2->right = node1;
     node1->parent = node2;

     node2->parent = temparent;
     if(temparent!=NULL)
       temparent->left = node2;
     else
       root = node2;
     return node2;
  }



  /** Return the number of items.
   */

  unsigned int BSTEC::size(){

    return isize;

  }


  /** Return the difference of height in left subtree
  * and right subtree.
  */
  int BSTEC::getBalance(BSTNodeInt* node){
    return heightH(node->left) - heightH(node->right);
  }


  /** return the height of tree.
 */

  int BSTEC::height(){
    return heightH(root);
  }




/** the helper function to traversal the tree with
 * postorder to find the height of tree
 */

  int BSTEC::heightH(BSTNodeInt* node){
  BSTNodeInt* curr = node;
  if(curr == NULL){
    return -1;
  }

  if(isize == 1){
    return 0;
  }


  int height_left = heightH(curr->left);
  int height_right = heightH(curr->right);

  if(height_left >= height_right){

     return height_left+1;
   }
   else{

     return height_right+1;
   }

  }





  /** Return true if the tree is empty, else false. 
   */
  bool BSTEC::empty(){
    if(isize == 0){
      return true;
    }
    else{
      return false;
    }
  }





#endif //BSTEC_HPP
