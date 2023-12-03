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

int UIMenu();

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



  int choice=11;
  int data;
  int fob;
  int otto;
  
  while(choice!=0){
    choice=UIMenu();
    if(choice==1){
      char con='z';
      while(con!='n'){
	cout<<"What integer would you like to enter?"<<endl;
	cin>>data;
	cout<<"Put it at the front or back of the deque?(Enter 1 or 2)"<<endl;
	cin>>fob;
	if(fob==1){
	  d.push_front(data);
	}
	if(fob==2){
	  d.push_back(data);
	}
	cout<<"Would you like to enter more? y or n"<<endl;
	cin>>con;
      }
    }
    if(choice==2){
      cout<<"How many integers do you want entered?"<<endl
	  <<"DATA WILL START AT 0 AND STOP AT HOW MANY YOU WANT ENTERED. ALL DATA WILL BE PUT AT FRONT"<<endl;
      cin>>otto;
      d.autoenter(otto);
    }
    if(choice==3){
      d.pop_front();
    }
    if(choice==4){
      d.pop_front();
    }
    if(choice==5){
      bool tmp=d.empty();
      if(tmp==1){
	cout<<"Deque is empty"<<endl;
      }
      if(tmp==0){
	cout<<"Deque is not empty"<<endl;
      }
    }
    if(choice==6){
      cout<<"Deque size is "<<d.size()<<endl;
    }
    if(choice==7){
      cout<<"Front element is "<<d.front()<<endl;
    }
    if(choice==8){
      cout<<"Back element is "<<d.back()<<endl;
    }
  }
  return 0;
}


int UIMenu(){
  int choice;
  cout<<"Hello! Which of the following would you like to do?"<<endl
      <<"0.Exit Program"<<endl
      <<"1.Enter data manually"<<endl
      <<"2.Have data entered automatically"<<endl
      <<"3.Remove data at front"<<endl
      <<"4.Remove data from back"<<endl
      <<"5.Check if deque is empty"<<endl
      <<"6.Check size of deque"<<endl;
  cout<<"7.Find front data"<<endl;
  cout<<"8.Find back data"<<endl;
  //<<"7.Print deque"<<endl;
  
  cin>>choice;
  return choice;
}
