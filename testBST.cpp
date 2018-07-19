#include "BSTInt.h"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2016
 * Author: Christine Alvarado and YOU
 * TODO: Add more tests
 */
int main() {

    /* Create an STL vector of some ints */
    /*test*/
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(100);
    v.push_back(-33);
    v.push_back(77);
    v.push_back(20);
    v.push_back(0);
    v.push_back(-56);
    v.push_back(-5);
    v.push_back(-4);    
    v.push_back(-3);
    v.push_back(-6);
    v.push_back(-7);


/*
    v.push_back(-33);
    v.push_back(4);
    v.push_back(77);
*/


    /* Create an instance of BST holding int */
    BSTInt b;
    BSTInt emptyTree;
//    BST oneTree;
    unsigned int dup = 0;


    // Could use: for(auto item : v) { instead of the line below
    for(int item : v) {
        
	bool pr = b.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
	    dup++;
            return -1;
        }

    }



    /* Test size. */
    cout << "Size is: " << b.size() << endl;

     if((v.size() - dup )== b.size()){

      cout << "The size is correct." << endl;
    }
    else{
      cout << "The size is incorrect." << endl;
      return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : v) {
        if(!b.find(item)) {
            cout << "Return false value when finding " << item << endl;
            return -1;
        }
    }

    //test false case of function find
    if(!emptyTree.find(33)){
         cout << "find function for a empty tree is correct" << endl;

    }
    else{
       cout << "find function for empty tree is incorrect" << endl;

       return -1;
   }

    //test empty()
    if(!b.empty()){
         cout << "empty function is correct" << endl;

    }
    else{
       cout << "empty function is incorrect" << endl;

       return -1;
   }


    if(emptyTree.empty()){
         cout << "empty function for a empty tree is correct" << endl;

    }
    else{
       cout << "empty function for empty tree is incorrect" << endl;

       return -1;
   }


/*
    //test height()
    if(b.height() ==6){
         cout << "height function is correct" << endl;

    }
    else{
       cout << "height function is incorrect" << endl;
       return -1;
   }
*/

    if(emptyTree.height()==-1){
         cout << "height function for a empty tree is correct" << endl;

    }
    else{
       cout << "height function for empty tree is incorrect" << endl;

       return -1;
   }




    /* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */

    
    // Test the template version of the BST  with ints 
    BST<int> btemp;
    for (int item : v) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }

    // Now test finding the elements we just put in
    for (int item: v) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }


    //test element that is not in tree
    cout << endl;
    cout << "test element that is not in tree" << endl;
    BSTIterator<int> foundNon = btemp.find(60);
    auto en2 = btemp.end();
//    cout << *foundNon==en2 << endl;
    if(foundNon==en2){
	cout << "60 is not in tree. Success!" << endl;
    }
    else{
	cout << "Fail to test element not in tree." << endl;

    }
    cout << endl;


    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(v.begin(),v.end());

    cout << "traversal using iterator..." << endl;
    auto vit = v.begin();
    auto ven = v.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en = btemp.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp.begin();
    for(; vit != ven; ++vit) {
        if(! (it != en) ) {
            cout << *it << "," << *vit 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
    }

    cout << "success!" << endl;





    cout << "Testing empty tree" << endl;
    // Test empty tree
    BST<int> eTree;

    // Now test finding the elements we just put in
    for (int item: v) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = eTree.find(item);
        if (foundIt != NULL) {
            cout << "incorrect value returned"
                 << endl;
            //return -1;
        }
        cout << item << " is not in empty tree. Success!" << endl;
    }



    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    //sort(eTree.begin(),eTree.end());

    cout << endl;
    if (eTree.begin() != NULL){
	cout << "Fail to test empty tree." << endl;
    }
    else{
	cout << "Success to test empty tree." << endl;

    }




/*
    cout << "traversal using iterator..." << endl;
    auto vit2 = eTree.begin();
    auto ven2 = eTree.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en2 = eTree.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it2 = eTree.begin();


*/





/*
    for(; vit2 != ven2; ++vit2) {
        if(! (it2 != en2) ) {
            cout << *it2 << "," << *vit2 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it2 << endl;gdb
        if(*it2 != *vit2) {
            cout << *it2 << "," << *vit2 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it2;
    }

    cout << "success!" << endl;


*/


    // ADD MORE TESTS HERE.  You might also want to change what is input
    // into the vector v.

//    cout << "All tests passed!" << endl;
    return 0;
}
