// Copyright 2024 Aarsh Patel
#ifndef _PROGRAM3FUNCTIONS_H_
#define _PROGRAM3FUNCTIONS_H_
extern const int kSquareSize;

void RemoveValues(int array[], int size, int value);
void ShiftArray(int array[], int size, int shift);
bool IsAnagram(const char str_one[], const char str_two[], bool case_sensitive = false);
bool Replace1With2(char array[], int size, char replace_this, char with_this_one, char with_this_two);
void SwapRowsAndColumns(int array[10][10]);

#endif // _PROGRAM3FUNCTIONS_H_