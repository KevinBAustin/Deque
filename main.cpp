/**
 * @file main.cpp
 * @author Kevin Austin
 * @date 2023-12-01
 * @brief main file for program, interacts with user
 * 
 * 
 */


#include <iostream>
#include <fstream>
#include "deque.h"

using namespace std;

int main() {
  int num;
  ifstream inFile;
  string filename;
  deque d;

  cout << "Enter file name: " << endl;
  cin >> filename;

  inFile.open(filename);
  inFile >> num;
  int i = 0;
  while(inFile){
    d.push_front(num);
    cout << d[0] << endl;
    inFile >> num;
  }
  cout << endl << d[0] << endl;
  inFile.close();
  
  //d[5] = 7;
  //cout << d[5] << endl;
  /*
  d.push_front(6);
  cout << d[0] << endl;
  d.push_back(7);
  cout << d[0] << endl;
  d.push_front(34);
  cout << d[0] << endl;
  d.push_back(234);
  d.push_front(42);
  d.pop_front();
  d.push_back(9000);
  d.push_back(9001);
  //d.pop_front();
  //d.pop_front();
  cout << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << " " << d[5] << " " << d[6] << " " <<  d[7] << endl << endl;

  cout << d.front() << endl;
  cout << d.back() << endl;
  cout << d.size() << endl;

  
  d.push_front(6);
  cout << d[0] << endl;
  d.pop_front();
  cout << d[0] << endl;
  */
  return 0;
}
