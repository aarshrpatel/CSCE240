// Copyright 2024 Aarsh Patel
#include"./program2functions.h"
#include<iostream>
#include<cstdlib>
#include<iomanip>
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
      std::string new_string_num = number_string.substr(i, j - i);
      int num = std::stoi(new_string_num);

      if (isPrime(num) && num > largest_number) {
        largest_number = num;
      }
    }
  }
  return largest_number;
}

void PrintAsDollarsAndCents(int cents) {
  if (cents > 99) {
    std::string cents_string = std::to_string(cents);
    std::string dollar_string = cents_string.substr(0, cents_string.length() - 2);
    cout << "$" << dollar_string << "." << cents_string.substr(cents_string.length() - 2, 2);
  } else {
    cout << "$0." << std::fixed << std::setprecision(2) << cents;
  }
}

bool MakePurchase(int purchase_cost, int &twenty, int &ten,
int &five, int &one, int &quarters, int &dimes, int &nickels, int &pennies) {
  double purchase_cost_dollars = purchase_cost / 100.00;
  int wallet[] = {pennies, nickels, dimes,
  quarters, one, five, ten, twenty};
  double value[] = {0.01, 0.05, 0.10, 0.25, 1.00, 5.00, 10.00, 20.00};
  double wallet_total = 0;
  for (int i = 0; i < 8; i++) {
    wallet_total += (wallet[i] * value[i]);
  }
  cout << wallet_total << std::endl;
  cout << purchase_cost_dollars << std::endl;
  
  if (wallet_total < purchase_cost_dollars) {
    return false;
  } else {  // Problem because did not consider multiple bills in the equation of same denomination
    int i = 0;
    while (i < 8) {
      double change = 0.00;
      if (purchase_cost_dollars <= value[i] && wallet[i] != 0) {
        wallet[i] -= 1;
        change = value[i] - purchase_cost_dollars;
        for (int j = i; j >= 0; j--) {
          while (value[j] <= change) {
            
            wallet[j] += 1;
            change -= value[j];
            cout << "wallet at " << j << ": " << wallet[j] << std::endl;
          }
        }
        cout << change << std::endl;
        return true;
      }
      i++;
        twenty = wallet[7];
        ten = wallet[6];
        five = wallet[5];
        one = wallet[4];
        quarters = wallet[3];
        dimes = wallet[2];
        nickels = wallet[1];
        pennies = wallet[0];
        
    }
    return true;
  }

}
