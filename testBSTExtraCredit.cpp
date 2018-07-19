//#include "BSTInt.h"
#include "BSTNodeInt.h"
#include "BSTExtraCredit.hpp"
//#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/** A tester for self-balance tree algorith.*/


int main(){

    int dup = 0; 
    vector<int> v;
    for(int i = 1; i < 101; i++) {
      v.push_back(i);
    }
    BSTEC b;

    for(unsigned int i = 0; i < v.size(); i++) {
        
	bool pr = b.insert(v.at(i));
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << v.at(i) 
                 << endl;
	    dup++;
            return -1;
        }
	else{
	    cout << v.at(i) << " insert correctly." << endl;
        }

    }

    cout << endl;
    cout << "Test height." << endl;
    cout << b.height() << endl;
    

/*
    if(b.height()==3){

	cout << "Success to test height." << endl;
    }
    else{
	cout << "Fail to test height." << endl;
    }
*/

    cout << endl;
    cout << "Test balance." << endl;

    cout << b.getBalance(b.root) << endl;
       return 0;



}
