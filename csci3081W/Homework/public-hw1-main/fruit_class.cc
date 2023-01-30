#include <iostream>

using namespace std;

// The following are the topics included in the zybook, please refer to corresponding chapters if you have questions

// 7.2 Using a class
// 7.3 Defining a class
// 7.6 Initialization and constructors
// 7.11 Constructor overloading
// 7.12 Constructor initializer lists
// 8.7 Destructors

// Define a class Fruit

// It has 2 private variables:
// name: string
// number: int

// It has 5 public methods:

// default constructor with name to be "NA" and number to be 0 using constructor initializer list

// a user-defined constructor so user can set the name and the number

// getName() which returns the name of the Fruit

// getNumber() which returns the number of the Fruit

// destructor which prints "Deallocating fruit" followed by the name of the Fruit


int main() {

  // 1. For the following 2 objects, make sure their destructors are called automatically at the end of main()

  // initialize a Fruit object f1 using default constructor

  // initialize another Fruit object f2 using user-defined constructor (choose whatever name and number)



  // 2. For the following 2 objects, make sure their destructors are not called automatically at the end of main()

  // initialize a Fruit object f3 using default constructor

  // initialize another Fruit object f4 using user-defined constructor (choose whatever name and number)



  // write down the output here
  /*


  */

  return 0;
} 
