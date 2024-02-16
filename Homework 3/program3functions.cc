// Copyright 2024 Aarsh Patel
#include"./program3functions.h"
#include<iostream>
#include<iomanip>
#include"./p3compares.h"


// Removes all instances of a value from an array
void RemoveValues(int array[], int size, int value) {
  int count = 0;
  for ( int i = 0; i < size; i++ ) {
    if ( array[i] == value ) {
      count++;
      continue;
    }
    array[i - count] = array[i];
    
  }
  for ( int j = (size - count); j < size; j++ ) {
    array[j] = -999;
  }
}

void ShiftArray(int array[], int size, int shift) {
  
}
