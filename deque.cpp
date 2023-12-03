/**
 * @file deque.cpp
 * @author Kevin Austin
 * @date 2023-12-01
 * @brief Class Defintion file
 * 
 * Defines all objects in the custom deque class
 */

#include <iostream>
#include <iomanip>
#include "deque.h"

using namespace std;

deque::deque(){
  firstblock=4;
  firstelement=0;
  blockmap=new int* [mapsize];

  for(int i=0; i<mapsize-1; i++){
    blockmap[i]=new int[blocksize];
  }
}

deque::~deque(){
  for(int i=0; i<mapsize; i++){
    delete[] blockmap[i];
  }
  delete[] blockmap;
}

void deque::resize(){
  
  int** temp;
  mapsize=mapsize+4;
  temp=new int* [mapsize];
 
  temp[0]=new int[blocksize];
  temp[1]=new int[blocksize];
  
  for(int i=0; i<mapsize-4; i++){
    temp[i+2]=blockmap[i];
  }
  
  temp[mapsize-1]=new int[blocksize];
  temp[mapsize-2]=new int[blocksize];

  delete[] blockmap;
  
  blockmap=temp;
  firstblock=2;
  if(firstelement==0){
    firstelement=blocksize-1;
  }
}

void deque::push_front(int num){
  if(firstelement==0 && firstblock==0){
    resize();
  }
  if(firstelement==0){
    amount++;
    firstelement=blocksize-1;
    firstblock=firstblock-1;
    blockmap[firstblock][firstelement]=num;
  }
  else{
    amount++;
    firstelement=firstelement-1;
    blockmap[firstblock][firstelement]=num;
  }
}

void deque::push_back(int num){
  int row;
  int col;
  row=firstblock+((firstelement+amount)/blocksize);
  col=(firstelement+amount)%blocksize;
  if(empty()){
    amount++;
    blockmap[row][col]=num;
  }
  else if(row==mapsize-1 && col==blocksize-1){
    resize();
    amount++;
    row=firstblock+((firstelement+amount)/blocksize);
    blockmap[row][0]=num;
  }
  else if(col==blocksize-1){
    amount++;
    blockmap[row+1][0]=num;
  }
  else{
    blockmap[row][col]=num;
    amount++;
  }
}

void deque::pop_front(){
  if(empty()){
    return;
  }
  blockmap[firstblock][firstelement]=0;
  if(firstelement+1 == blocksize){
    firstblock++;
    firstelement=0;
  }
  else{
    firstelement++;
  }
  amount--;
}

void deque::pop_back(){
  int row;
  int col;
  row=firstblock+((firstelement+amount)/blocksize);
  col=(firstelement+amount)%blocksize;
  if(empty()){
    return;
  }
  else{
    blockmap[row][col-1]=0;
  }
  amount--;
}

int deque::front(){
  return blockmap[firstblock][firstelement];
}

int deque::back(){
  int row;
  int col;
  row=firstblock+((firstelement+amount)/blocksize);
  col=(firstelement+amount)%blocksize;
  return blockmap[row][col-1];
}

bool deque::empty(){
  if(amount==0){
    return 1;
  }
  else{
    return 0;
  }
}

int deque::size(){
  return amount;
}

void deque::autoenter(int num){
  for(int i=0; i<num; i++){
    push_front(i);
  }
}

int& deque::operator[](unsigned int index){
  int row;
  int col;
  row=firstblock+((firstelement+index)/blocksize);
  col=(firstelement+index)%blocksize;
  return blockmap[row][col];
}
