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


/**
 * Main menu for user interaction
 *
 * @pre 
 * @return int returns user choice
 * @post 
 * 
 */
int UIMenu();

int main() {
  ifstream inFile;
  string filename;
  deque d; //Cutsom deque class
  int choice = 11; //User choice for the menu
  int fob;//Front or back choice for user
  
  while(choice != 0){
    choice = UIMenu(); //Printing menu while also getting choice from the user
    
    if(choice == 1){
      char con = 'z';
      while(con != 'n'){
	int num = 0;
	cout << "What integer would you like to enter?" << endl; //Prompting user
	cin >> num; //Getting user input
	cout << "Would you like to push it to the front or back of the deque?(Enter 1 or 2)" << endl; //Prompting user
	cin >> fob; //Getting user input
	if(fob == 1){
	  d.push_front(num); //Pushing front a number
	}
	if(fob == 2){
	  d.push_back(num); //Pushing back a number
	}
	cout << "Would you like to enter more? y or n" << endl; //Prompting user
	cin >> con; //Getting user input
      }
    }
    
    if(choice == 2){
      int num = 0; 
      cout << "Enter file name: " << endl; //Prompting user
      cin >> filename; //Getting user input
      inFile.open(filename); //Opening file
      inFile >> num; //Priming read
      while(inFile){
	d.push_front(num); //Pushing front a number
	inFile >> num; //Reading next number in the file
      }
      inFile.close(); //Closing file
    }

    if(choice == 3){
      int num = 0;
      cout << "Enter file name: " << endl; //Prompting user
      cin >> filename; //Getting user input
      inFile.open(filename); //Opening file
      inFile >> num; //Priming read
      while(inFile){
	d.push_back(num); //Pushing back a number
	inFile >> num; //Reading next number in the file
      }
      inFile.close(); //Closing file
       
    }
    if(choice == 4){
      int num = 0;
      cout << "How many elements would you like to pop off the front?" << endl; //Prompting user
      cin >> num; //Getting user input
      for (int i = 0; i < num; i++){
	d.pop_front(); //Popping front
      }
    }
    
    if(choice == 5){
      int num = 0;
      cout << "How many elements would you like to pop off the back?" << endl; //Prompting user
      cin >> num; //Getting user input
      for (int i = 0; i < num; i++){
	d.pop_back(); //Popping back
      }
    }
    
    if(choice == 6){
      if(d.empty() == true){
	cout << "Deque is empty" << endl << endl; //Letting user know the deque is empty
      }
      if(d.empty() == false){
	cout << "Deque is not empty" << endl << endl; //Letting user know the deque is not empty
      }
    }
    
    if(choice == 7){
      cout << "Deque size is " << d.size() << endl << endl; //Displaying the deque size
    }
    
    if(choice == 8){
      cout << "Front element is " << d.front() << endl << endl; //Printing front-most element
    }
    
    if(choice == 9){
      cout << "Back element is " << d.back() << endl << endl; //Printing back-most element
    }

    if(choice == 10) {
      if (d.empty() == true) {
	cout << "Nothing to print. Deque is currently empty." << endl << endl; //Letting user know that the deque cannot be printed because it is empty
      }
      else {
	for (int i = 0; i < d.size(); i++){
	  cout << d[i] << " "; //Printing each value in the deque
	}
	cout << endl << endl; //Starting a new line twice for readability
      }
    }
  }
  
  return 0;
  
}

int UIMenu(){
  int choice; //The user's choice
  //Menu
  cout << "Hello! Which of the following would you like to do?" << endl;
  cout << "0. Exit Program" << endl;
  cout << "1. Enter data manually" << endl;
  cout << "2. Read in and push front data from a file" << endl;
  cout << "3. Read in and push back data from a file" << endl;
  cout << "4. Remove x amount of data from front" << endl;
  cout << "5. Remove x amount of data from back" << endl;
  cout << "6. Check if deque is empty" << endl;
  cout << "7. Check size of deque" << endl;
  cout << "8. Peek at front-most element" << endl;
  cout << "9. Peek at back-most element" << endl;
  cout << "10. Print deque" << endl;
  cin >> choice; //Getting input from user
  cout << endl; 
  return choice; 
}
