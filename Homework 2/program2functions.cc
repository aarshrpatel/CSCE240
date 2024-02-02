// Copyright 2024 Aarsh Patel
#include"./program2functions.h"
#include<iostream>
#include<cstdlib>
#include<iomanip>
using std::abs;
using std::cout;

// Calculates if the argument is a prime number
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

// Finds the closest prime number up and down from the inputted argument
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

// Prints the prime numbers between to bounds
void PrintPrimesBetween(int lower_bound, int upper_bound,
bool include_bounds) {
  // Upper bound check to see if to include
  int j = (include_bounds) ? (upper_bound) : (upper_bound - 1);
  // Lower bound check to see if to include
  int k = (include_bounds) ? (lower_bound) : (lower_bound + 1);
  // Shifts through the values in the range
  while (!isPrime(j) && j >= k) {
    j--;
  }
  /**
  * If the value at i is prime then prints it and checks if a 
  * comma is needed.
  */ 
  for (int i = k; i <= j; i++) {
    if (isPrime(i)) {
      cout << i;

      if (i != j) {
        cout << ", ";
      }
    }
  }
}

// Gets the largest prime sequence from a string of numbers
int LargestPrimeSequence(int number) {
  int largest_number = -1;
  std::string number_string = std::to_string(number);
  for (int i = 0; i < number_string.length(); i++) {
    for (int j = i + 1; j <= number_string.length(); j++) {
      std::string new_string_num = number_string.substr(i, j - i);
      int num = std::stoi(new_string_num);

      if (isPrime(num) && num > largest_number) {
        largest_number = num;
      }
    }
  }
  return largest_number;
}

// Prints the cents value as dollars and cents
void PrintAsDollarsAndCents(int cents) {
  if (cents > 99) {
    std::string cents_string = std::to_string(cents);
    std::string dollar_string =
    cents_string.substr(0, cents_string.length() - 2);
    cout << "$" << dollar_string << "."
    << cents_string.substr(cents_string.length() - 2, 2);
  } else {
    cout << "$0." << std::fixed << std::setprecision(2) << cents;
  }
}

// Makes a purchase with the amount of bills given
bool MakePurchase(int purchase_cost, int& twenty, int& ten,
int& five, int& one, int& quarters, int& dimes, int& nickels, int& pennies) {
  int wallet[] = {pennies, nickels, dimes,
  quarters, one, five, ten, twenty};
  int value[] = {1, 5, 10, 25, 100, 500, 1000, 2000};
  int wallet_total = 0;
  // Adds up the total in the wallet
  for (int i = 0; i < 8; i++) {
    wallet_total += (wallet[i] * value[i]);
  }

  // Checks if the wallet has enough to make the purchase
  if (wallet_total >= purchase_cost) {
    /**
     * Runs through each denomination and checks if it 
     * needs to be removed to make the purchase
     * */ 
    for (int i = 7; i > 1; i--) {
      if (wallet[i] > 0 && purchase_cost > 0) {
        while (abs(value[i] - purchase_cost)
        < abs(value[i - 1] - purchase_cost)) {
          wallet[i] -= 1;
          purchase_cost -= value[i];
        }
      }
    }
    // Special case for nickels and pennies
    while (abs(value[1] - purchase_cost) > 1
    && wallet[1] > 0 && purchase_cost > 0) {
      wallet[1] -= 1;
      purchase_cost -= value[1];
    }
    while (abs(value[0] - purchase_cost) > 0
    && wallet[0] > 0 && purchase_cost > 0) {
      wallet[0] -= 1;
      purchase_cost -= value[0];
    }

    // Puts change back into wallet
    if (purchase_cost < 0) {
      int change = -purchase_cost;
      for (int i = 7; i > 0; i--) {
        while (abs(value[i] - change) <= abs(value[i - 1] - change)
        && change - value[i] >= 0) {
        wallet[i] += 1;
        change -= value[i];
        }
      }
      while (change - 1 >= 0) {
        wallet[0] += 1;
        change--;
      }
    }
    // Set values to new values.
    pennies = wallet[0];
    nickels = wallet[1];
    dimes = wallet[2];
    quarters = wallet[3];
    one = wallet[4];
    five = wallet[5];
    ten = wallet[6];
    twenty = wallet[7];
    return true;
  } else {
    return false;
  }
}
