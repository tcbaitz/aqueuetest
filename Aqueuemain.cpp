// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for the array-based queue class

#include "book.hpp"

#include "aqueue.hpp"

#include "QueueTest.hpp"

//used to run tests
#include <climits>
#include <algorithm>
#include <iostream>
#include <stdexcept>

using namespace std;


// Saves the result of the program (see main).
int exit_code;


// Use this instead of assert to check for failures.
// This will diagnose the failed check and update the
// exit code (see main).
#define check(e)                                    \
  if (!(e)) {                                       \
    std::cerr << "error: "                          \
               << __func__ << ":"                   \
               << __LINE__ << ": "                  \
               << #e << " evaluated to false\n";    \
    exit_code = 1;                                  \
  }



// Check that default initialization creates an empty
// array based queue. The lenght will be 0.
void
test_default_init()
{
  cout << "start test_default_init" << endl;
  AQueue<int> v;
  check(v.length() == 0);
  cout << "end test_default_init\n" << endl;
}

//Check that the default size is set and the array
//based queue can populate all available positions
//in the array.
void
test_default_size()
{
  cout << "start test_default_size" << endl;
  AQueue<int> v;
  for(int count = 0;count < defaultSize; count++){
    v.enqueue(count);
  }
  check(v.length() == defaultSize);
  cout << "end test_default_size\n" << endl;
}

//Check that the size of the array based queue can
//be set to whatever the user desires.
void
test_set_capacity()
{
  cout << "start test_set_capacity" << endl;
  const int TEST_CAPACITY = 128;
  AQueue<int> v(TEST_CAPACITY);
  check(v.length() == 0);
  for(int count = 0;count < TEST_CAPACITY; count++){
    v.enqueue(count);
  }
  check(v.length() == TEST_CAPACITY);
  //add one more past the bounds, should assert that
  //the aqueue is full
  //v.enqueue(TEST_CAPACITY);
  //check(v.length() != TEST_CAPACITY)
  cout << "end test_set_capacity\n" << endl;
}

//Check that the dequeue is working properly.
//When all elements are removed from the aqueue, the
//length will be 0.
void
test_dequeue()
{
  cout << "start test_dequeue" << endl;
  const int TEST_CAPACITY = 128;
  AQueue<int> v(TEST_CAPACITY);
  check(v.length() == 0);
  for(int count = 0;count < TEST_CAPACITY; count++){
    v.enqueue(count);
  }
  check(v.length() == TEST_CAPACITY);
  for(int count = 0;count < TEST_CAPACITY; count++){
    v.dequeue();
  }
  check(v.length() == 0);
  cout << "end test_dequeue\n" << endl;
}

//Test that the front value will change when the
//first element is removed.
void
test_front_value()
{
  cout << "start test_front_value" << endl;
  const int TEST_CAPACITY = 128;
  AQueue<int> v(TEST_CAPACITY);
  check(v.length() == 0);
  for(int count = 0;count < TEST_CAPACITY; count++){
    v.enqueue(count);
  }
  check(v.length() == TEST_CAPACITY);
  v.dequeue();
  check(v.frontValue() == 1);
  check(v.length() == TEST_CAPACITY - 1)
  cout << "end test_front_value\n" << endl;
}

int main()
{

  test_default_init();

  test_default_size();

  test_set_capacity();

  test_dequeue();

  test_front_value();

  return exit_code;
}
