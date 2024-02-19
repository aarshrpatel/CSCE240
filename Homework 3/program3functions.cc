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

bool IsAnagram(char *str1, char *str2, bool case_sensitive) {
  if ( !case_sensitive ) {
    for ( int i = 0; i < sizeof(str1) / sizeof(char); i++ ) {
      str1[i] = tolower(str1[i]);
    }
    for ( int i = 0; i < sizeof(str2) / sizeof(char); i++ ) {
      str2[i] = tolower(str2[i]);
    }
  }

  int count1[52];
  int count2[52];
  for ( int i = 0; i < sizeof(str1) / sizeof(char); i++ ) {
    if ( str1[i] >= 'a' && str1[i] <= 'z' ) {
      count1[str1[i] - 'a']++;
    } else if ( str1[i] >= 'A' && str1[i] <= 'Z' ) {
      count1[str1[i] - 'A' + 26]++;
    }
  }
  for ( int i = 0; i < sizeof(str2) / sizeof(char); i++ ) {
    if ( str2[i] >= 'a' && str2[i] <= 'z' ) {
      count2[str2[i] - 'a']++;
    } else if ( str2[i] >= 'A' && str2[i] <= 'Z' ) {
      count2[str2[i] - 'A' + 26]++;
    }
  }

  for ( int i = 0; i < 52; i++ ) {
    if ( count1[i] != count2[i] ) {
      return false;
    }
  }

  return true;
}