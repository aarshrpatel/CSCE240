// Copyright 2024 Aarsh Patel
#include "./program3functions.h"
#include <iostream>
#include <iomanip>
#include "./p3compares.h"

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
  int temp[size];
  for ( int i = 0; i < size; i++ ) {
    temp[i] = array[i];
  }
  for ( int i = 0; i < size; i++ ) {
    while ( shift > size) {
      shift = shift - size;
    } 
    while ( -shift > size ) {
      shift = shift + size;
    } 
    if ( i - shift < 0 ) {
      array[i - shift + size] = temp[i];
    } else if ( i - shift >= size ) {
      array[i - shift - size] = temp[i];
    } else {
      array[i - shift] = temp[i];
    }
  }
}

bool IsAnagram(const char str_one[], const char str_two[], bool case_sensitive) {

  int count_one[52] = {0};
  int count_two[52] = {0};
  
  for ( int i = 0; str_one[i] != '\0'; i++ ) {
    if ( str_one[i] >= 'A' && str_one[i] <= 'Z' ) {
      count_one[str_one[i] - 'A']++;
    } else if ( str_one[i] >= 'a' && str_one[i] <= 'z' ) {
      count_one[str_one[i] - 'a' + 26]++;
    }
  }

  for ( int i = 0; str_two[i] != '\0'; i++ ) {
    if ( str_two[i] >= 'A' && str_two[i] <= 'Z' ) {
      count_two[str_two[i] - 'A']++;
    } else if ( str_two[i] >= 'a' && str_two[i] <= 'z' ) {
      count_two[str_two[i] - 'a' + 26]++;
    } 
  }
  
  for ( int i = 0; i < 52 && case_sensitive; i++ ) {
    if ( count_one[i] != count_two[i] ) {
      return false;
    } 
  }
  for ( int i = 0; i < 26 && !case_sensitive; i++ ) {
    if ( (count_one[i] + count_one[26 + i]) != (count_two[i] + count_two[26 + i]) ) {
      return false;
    }
  }

  return true;
}

bool Replace1With2(char array[], int size, char replace_this, char with_this_one, char with_this_two) {
  // Counts the empty spaces and occurrence of the character to replace
  int empty_count = 0, replace_count = 0;
  for ( int i = 0; i < size; i++ ) {
    if ( array[i] == '\0' ) {
      empty_count++;
    } else if ( array[i] == replace_this ) {
      replace_count++;
    }
  }

  // Check to see if there is enough space to return
  if ( empty_count < (replace_count + 1) ) {
    return false;
  }

  for ( int i = 0; i < size; i++ ) {
    if ( array[i] == replace_this ) {
      array[i] = with_this_one;
      
      for ( int j = size - 1; j > i + 1; j-- ) {
        array[j] = array[j - 1];
      }

      array[i + 1] = with_this_two;
      i++;
    }
  }

  return true;
}

void SwapRowsAndColumns(int array[kSquareSize][kSquareSize]) {
  int temp[10][10];
  for ( int column = 0; column < 10; column++ ) {
    for ( int row = 0; row < 10; row++ ) {
      temp[column][row] = array[row][column];
    }
  }

  for ( int column = 0; column < 10; column++ ) {
    for ( int row = 0; row < 10; row++ ) {
      array[column][row] = temp[column][row];
    }
  }
}