/**
 * @file deque.cpp
 * @author Kevin Austin
 * @date 2023-12-01
 * @brief Class Defintion file
 * 
 * Defines all objects in the custom deque class
 */
#include "deque.h"
#include <iostream>

using namespace std;

void deque::resize(){
  int ** temp; //Initializing new blockmap
  mapsize+=2; //Increasing mapsize by 2 so that a block can be added on to each end
  temp = new int* [mapsize]; //Allocating memory for the new blockmap

  temp[0] = new int[blocksize]; //Allocating a new block to go at the beginning of the new blockmap

  for (int i = 0; i < mapsize; i++){
    temp[i+1] = blockmap[i]; //Copying the data from the old blockmap over to the new blockmap
  }
  temp[mapsize-1] = new int[blocksize]; //Allocating a new block to go at the end of the new blockmap

  delete[] blockmap; //Deleting old blockmap
  blockmap = temp; //Setting the contents of the recently deleted blockmap to the contents of the new blockmap
}

deque::deque(){
  firstblock = 2; //Initializing firstblock as 2 (chosen somewhat arbitrarily; sets aside two blocks of space before we have to start resizing from the front) 
  firstelement = 0; //Initializing firstelement
  blockmap = new int* [mapsize]; //Allocating memory for the blockmap
  for (int i = 0; i < mapsize; i++){
    blockmap[i] = new int[blocksize]; //Allocating memory for the elements in each block
  }
}


deque::~deque(){
  for (int i = 0; i < mapsize; i++){
    delete[] blockmap[i]; //Deleting the contents of the blockmap
  }

  delete[] blockmap; //Deleting the blockmap
}

void deque::push_front(int num){
  if (firstelement == 0 && firstblock == 0){
    resize(); //Resizing the deque
    firstblock = 0; //Setting firstblock equal to 0, ensuring that the number will be inserted in the new block we put at the beginning 
    firstelement=blocksize-1; //Setting the firstelement to the last element in the new block
    blockmap[firstblock][firstelement] = num; //Inserting the number
  }
  else if (firstelement == 0){
    firstblock = firstblock-1; //Decrementing first block so that the previous block is used
    firstelement = blocksize-1; //Setting firstelement equal to the last element in the previous block
    blockmap[firstblock][firstelement] = num; //Inserting the number
  }
  else {
    firstelement = firstelement-1; //Decrementing first element
    blockmap[firstblock][firstelement] = num; //Inserting the number
  }
  amount++; //Increasing the amount
}

void deque::push_back(int num){
  int row;
  int col;
  //Formula to find the back of the deque
  row = firstblock + ((firstelement + amount)/blocksize);
  col = (firstelement + amount) % blocksize;
  if (amount == 0) { 
    blockmap[firstblock][firstelement] = num; //Inserting at firstblock, firstelement if deque is empty
  }
  else if (row == mapsize){ 
    resize(); //Resizing the deque
    firstblock+=1; //Incrementing firstblock
    blockmap[row+1][0] = num; //Inserting the number at beginning of the new block 
  }
  else {
    blockmap[row][col] = num; //Inserting the number
  }
  amount++; //Increasing the amount
}

void deque::pop_front(){
  if(empty()){
    return; //Returning if the deque is empty
  }
  blockmap[firstblock][firstelement]=0; //Popping off the front by setting it equal to 0
  if(firstelement+1 == blocksize){
    firstblock++; //Incrementing firstblock
    firstelement = 0; //Setting firstelement equal to 0 so it'll be at the start of the next block
  }
  else{
    firstelement++; //Incrementing firstelement
  }
  amount--; //Decreasing the amount
}

void deque::pop_back(){
  int row;
  int col;
  //Formula to find the back of the deque
  row = firstblock + ((firstelement + amount) / blocksize);
  col = (firstelement + amount) % blocksize;
  if(empty()){
    return; //Returning if the deque is empty
  }
  else if(col == 0) {
    blockmap[row-1][blocksize-1] = 0; //Popping off the back by setting it equal to 0 
  }
  else {
    blockmap[row][col-1] = 0; //Popping off the back
  }
  amount--; //Decreasing the amount
}

int deque::front(){
  return blockmap[firstblock][firstelement]; //Returning front-most element
}

int deque::back(){
  int row;
  int col;
  //Formula to find the back of the deque
  row = firstblock + ((firstelement + amount)/blocksize);
  col = (firstelement + amount) % blocksize;
  if (col == 0) {
    return blockmap[row-1][blocksize-1]; //Returning back-most element
  }
  else {
    return blockmap[row][col-1]; //Returning back-most element
  }
}

bool deque::empty(){
  if(amount==0){
    return 1; //Returning true if amount is 0
  }
  else{
    return 0; //Returning false if else
  }
}

int deque::size(){
  return amount; //Returning the amount of elements in the deque (size of deque)
}

int& deque::operator[](unsigned int index){
  int row;
  int col;
  //Formula to find the desired element
  row = firstblock + ((firstelement + index)/blocksize);
  col = (firstelement + index) % blocksize;
  return blockmap[row][col]; //Returning the desired element
}
