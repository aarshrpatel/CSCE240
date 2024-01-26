// Copyright 2024 Aarsh Patel
#include"./program2functions.h"

int ToClosestPrime(int number) {
  int n_minus = 0;
  int n_plus = 0;
  bool prime = false;
  for (int i = number, int j = number; i >= 7 && !prime; i++, j--) {
    if (i == 7) {
      prime = true;
    } else if (i % 2 != 0 || i % 3 != 0 || i % 5 != 0 || i % 7 != 0) {
      prime = true;
    } else {
      n_plus++;
    }
    if (j % 2 != 0 || j % 3 != 0 || j % 5 != 0 || j % 7 != 0) {
      prime = true;
    }
    else {
      n_minus--;
    }
  }
  if (-n_minus < n_plus) {
    return n_minus;
  } else if (-n_minus > n_plus) {
    return n_plus;
  } else {
    return n_plus;
  }
}