
#include "BSTInt.h"

/* Function definitions for a int-based BST class */


/** Default destructor.
    Delete every node in this BST.
*/
BSTInt::~BSTInt() {
  deleteAll(root);
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item)
{
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    return true;
  }

  BSTNodeInt* curr = root;
  BSTNodeInt* temp = root;
//Bug- Condition is too narrow -- while (curr->left && curr->right) {
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
  return true;

}


/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{
  //if there is no root
  if(!root){
    return false;
  }

  
  BSTNodeInt* curr = root;
  while (curr != nullptr) {
    if (curr -> data < item) {
      if(!curr->right){
	return false;
      }
      else{
        curr = curr->right;
      }
    }

    else if (item < curr->data) {
      if(!curr->left){
	return false;
      }
      else{
        curr = curr->left;
      }
    }
    else {
      return true;
    }
  }
  return false;
}



/** the helper function to traversal the tree with
 * postorder to find the height of tree
 */

int BSTInt::heightHelper(BSTNodeInt* curr) const{
 
  if(root == NULL){
    return -1;
  }

  if(isize == 1){
    return 0;
  }

  if(curr == NULL){ return 0;}


  int height_left = heightHelper(curr->left);
  int height_right = heightHelper(curr->right);


  

  if(height_left >= height_right){
     if(curr == root){
       return height_left;
     }
     return height_left+1;
   }
   else{
     if(curr == root){
       return height_right;
     }
     return height_right+1;
   }



}
  
/** Return the number of items currently in the BST.
 */
unsigned int BSTInt::size() const 
{
  return isize;
}

  
/** Return the height of the BST.
    Height of tree with just root node is 0
    height of an empty tree is -1
 */
int BSTInt::height() const
{
 
  return heightHelper(root);
}


/** Return true if the BST is empty, else false. 
 */
bool BSTInt::empty() const 
{
  if(isize == 0){
  return true;
  }
  else{
  return false;
  }
}




/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{

  if(n == NULL){
    return;
  }

  deleteAll(n->left);
  deleteAll(n->right);

  delete n;

}

