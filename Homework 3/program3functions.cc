// Copyright 2024 Aarsh Patel
#include "./program3functions.h"
#include <iostream>
#include <iomanip>
#include "./p3compares.h"

// Removes all instances of a value from an array
void RemoveValues(int array[], int size, int value) {
  // Counts the number of occurrences of the value
  int count = 0;
  for ( int i = 0; i < size; i++ ) {
    if ( array[i] == value ) {
      count++;
      continue;
    }
    // Shifts the array to the left
    array[i - count] = array[i];
  }
  // Fills the rest of the array with -999
  for ( int j = (size - count); j < size; j++ ) {
    array[j] = -999;
  }
}

// Shifts the array by a given amount
void ShiftArray(int array[], int kSize, int shift) {
  // Creates a temporary array to store the original values
  int temp[kSize];
  for ( int i = 0; i < kSize; i++ ) {
    temp[i] = array[i];
  }
  // Shifts all the values to the new position
  for ( int i = 0; i < kSize; i++ ) {
    while ( shift > kSize ) {
      shift = shift - kSize;
    }
    while ( -shift > kSize ) {
      shift = shift + kSize;
    }
    if ( i - shift < 0 ) {
      array[i - shift + kSize] = temp[i];
    } else if ( i - shift >= kSize ) {
      array[i - shift - kSize] = temp[i];
    } else {
      array[i - shift] = temp[i];
    }
  }
}

// Checks if two strings are anagrams
bool IsAnagram(const char str_one[], const char str_two[],
bool case_sensitive) {
  int count_one[52] = {0};
  int count_two[52] = {0};

  // Counts the number of occurrences of each character in the first string
  for ( int i = 0; str_one[i] != '\0'; i++ ) {
    if ( str_one[i] >= 'A' && str_one[i] <= 'Z' ) {
      count_one[str_one[i] - 'A']++;
    } else if ( str_one[i] >= 'a' && str_one[i] <= 'z' ) {
      count_one[str_one[i] - 'a' + 26]++;
    }
  }

  // Counts the number of occurrences of each character in the second string
  for ( int i = 0; str_two[i] != '\0'; i++ ) {
    if ( str_two[i] >= 'A' && str_two[i] <= 'Z' ) {
      count_two[str_two[i] - 'A']++;
    } else if ( str_two[i] >= 'a' && str_two[i] <= 'z' ) {
      count_two[str_two[i] - 'a' + 26]++;
    }
  }

  // Compares the two arrays to see if they are anagrams
  for ( int i = 0; i < 52 && case_sensitive; i++ ) {
    if ( count_one[i] != count_two[i] ) {
      return false;
    }
  }
  for ( int i = 0; i < 26 && !case_sensitive; i++ ) {
    if ( (count_one[i] + count_one[26 + i]) !=
    (count_two[i] + count_two[26 + i]) ) {
      return false;
    }
  }

  return true;
}

// Replaces all instances of a character with two characters
bool Replace1With2(char array[], int size, char replace_this,
char with_this_one, char with_this_two) {
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

  // Replaces the character with the two new characters
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

// Swaps the rows and columns of a 2D array
void SwapRowsAndColumns(int array[kSquareSize][kSquareSize]) {
  // Creates a temporary array to store the changed values
  int temp[kSquareSize][kSquareSize];
  for ( int column = 0; column < kSquareSize; column++ ) {
    for ( int row = 0; row < kSquareSize; row++ ) {
      temp[column][row] = array[row][column];
    }
  }

  // Copies the temporary array to the original array
  for ( int column = 0; column < kSquareSize; column++ ) {
    for ( int row = 0; row < kSquareSize; row++ ) {
      array[column][row] = temp[column][row];
    }
  }
}
