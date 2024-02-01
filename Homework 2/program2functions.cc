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
  int wallet_total =  twenty * 2000 + ten * 1000 + five * 500 + one * 100 +
  quarters * 25 + dimes * 10 + nickels * 5 + pennies * 1;

  // Checks to see if enough money is available to make the purchase
  if (wallet_total >= purchase_cost) {
    int change_value = 0;
    int cost = purchase_cost;
    while (cost > 0) {
      if (cost > 1000 && twenty != 0) {
        twenty--;
        change_value = 2000;
        cost -= 2000;
      } else if (cost > 500 && ten)
      
    }

    while (purchase_cost >)
  } else {
  return false;
  }



  // int change = 0;
  // if (wallet[7] >= 1 && purchase_cost >= value[7]) {
  //   int num_bills = purchase_cost / value[7];
  //   if (wallet[7] >= num_bills && num_bills != 0) {
  //     wallet[7] -= num_bills;
  //     return true;
  //   } else {

  //   }
  // }
  // for (int i = 0; i < wallet.length(); i++) {
  //   if (purchase_cost <= value[i] && wallet[i] != 0)
  // }  




  // // Problem because did not consider multiple bills in the equation of same denomination
  // int i = 0;
  // int k = 1;
  // //Goes through the arrays
  // while (i < 8) {
  //   double change = 0.00;
  //   //Checks to see if cost is less than the value at the index i
  //   if (purchase_cost_dollars <= (value[i] * k) && wallet[i] >= k) {
  //     wallet[i] -= k;
  //     change += (value[i] * k) - purchase_cost_dollars;
  //     for (int j = i; j >= 0; j--) {
  //       while (value[j] <= change) {
  //         cout << change << std::endl;
  //         wallet[j] += 1;
  //         change -= value[j];
  //       }
  //     }
  //   }
  //   i++;
  //   twenty = wallet[7];
  //   ten = wallet[6];
  //   five = wallet[5];
  //   one = wallet[4];
  //   quarters = wallet[3];
  //   dimes = wallet[2];
  //   nickels = wallet[1];
  //   pennies = wallet[0];
  //   return true;
  // }

}