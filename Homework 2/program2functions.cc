// Copyright 2024 Aarsh Patel
#include"./program2functions.h"
#include<iostream>
#include<cstdlib>
using std::abs;
using std::cout;

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int ToClosestPrime(int number) {
    int distance_up = 0;
    int distance_down = 0;
    int i = number;
    int j = number;
    // Find the closest prime greater than or equal to the given number
    while (!isPrime(i)) {
        i++;
    }

    while (!isPrime(j)) {
      j--;
    }
    distance_up = i - number;
    distance_down = j - number;

    // Choose the smaller absolute distance
    if (abs(distance_down) < abs(distance_up)) {
        return distance_down;
    } else {
      return distance_up;
    }
}

void PrintPrimesBetween(int lower_bound, int upper_bound,
bool include_bounds) {
  int j = (include_bounds) ? (upper_bound) : (upper_bound - 1);
  int k = (include_bounds) ? (lower_bound) : (lower_bound + 1);
  while (!isPrime(j) && j >= k) {
    j--;
  }
  for (int i = k; i <= j; i++) {
    if (isPrime(i)) {
      cout << i;

      if (i != j) {
        cout << ", ";
      }
    }
  }
}

int LargestPrimeSequence(int number) {
  int largest_number = -1;
  std::string number_string = std::to_string(number);
  for (int i = 0; i < number_string.length(); i++) {
    for (int j = i + 1; j <= number_string.length(); j++) {
      std::string substring = number_string.substr(i, j - i);
      int num = std::stoi(substring);

      if (isPrime(num) && num > largest_number) {
        largest_number = num;
      }
    }
  }
  return largest_number;
}
