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

deque::deque(){
  firstblock=2;
  firstelement=0;
  blockmap=new int* [mapsize];

  for(int i=2; i<mapsize-2; i++){
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
  mapsize=mapsize*2;
  temp=new int* [mapsize];

  temp[0]=new int[blocksize];

  for(int i=0; i<mapsize/2; i++){
    temp[i+2]=blockmap[i];
  }

  for(int i=0; i<mapsize/2; i++){
    delete[] blockmap[i];
  }
  delete[] blockmap;
  deque();
  for(int i=0; i<mapsize; i++){
    blockmap[i]=temp[i+2];
  }
}

void deque::push_front(int num){
  if(firstelement==0 && firstblock==0){
    resize();
  }
  if(firstelement==0){
    firstelement=blocksize-1;
    firstblock=firstblock-1;
    blockmap[firstblock][firstelement]=num;
  }
  if(firstelement!=0){
    firstelement=firstelement-1;
    blockmap[firstblock][firstelement]=num;
  }
}

void deque::push_back(){

}

void deque::pop_front(){

  
}

void deque::pop_back(){

}

int deque::front(){
  return blockmap[firstblock][firstelement];
}

int deque::back(){

}

bool deque::empty(){

}

int deque::size(){

}


int& deque::operator[](unsigned int index){
  int row;
  int col;
  row=firstblock+((firstelement+index)/blocksize);
  col=(firstelement+index)%blocksize;

  return blockmap[row][col];
}
