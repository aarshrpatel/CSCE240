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

bool IsAnagram(const char str1[], const char str2[], bool case_sensitive) {

  int count1[52] = {0};
  int count2[52] = {0};
  for ( int i = 0; i < 52; i++ ) {
    if ( str1[i] >= 'A' && str1[i] <= 'Z' ) {
      count1[str1[i] - 'A']++;
    } else if ( str1[i] >= 'a' && str1[i] <= 'z' ) {
      count1[str1[i] - 'a' + 26]++;
    }
  }

  for ( int i = 0; i < 52; i++ ) {
    if ( str2[i] >= 'A' && str2[i] <= 'Z' ) {
      count2[str2[i] - 'A']++;
    } else if ( str2[i] >= 'a' && str2[i] <= 'z' ) {
      count2[str2[i] - 'a' + 26]++;
    } 
  }
  char letter = 'A';

  for ( int i = 0; i < 26; i++ ) {
    std::cout << letter++ << " ";
  }

  letter = 'a';
  for ( int i = 0; i < 26; i++ ) {
    std::cout << letter++ << " ";
  }

  std::cout << std::endl;

  for ( int i = 0; i < 52; i++ ) {
    std::cout << count1[i] << " ";
  }

  std::cout << std::endl;
  
  for ( int i = 0; i < 52; i++ ) {
    std::cout << count2[i] << " ";
  }
  
  for ( int i = 0; i < 52; i++ ) {
    if (case_sensitive && count1[i] != count2[i] ) {
      return false;
    } else if ( !case_sensitive && (count1[i] + count1[26 + i]) != (count2[i] + count2[26 + i]) ) {
      return false;
    }
  }

  return true;
}