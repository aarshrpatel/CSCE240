// Copyright 2024 Aarsh Patel
#include<iostream>
#include<iomanip>
using std::cout;
using std::cin;
using std::endl;

int main() {
  // Variables for program
  int initial_month, initial_day, initial_year;
  double initial_balance, current_balance, average_balance = 0, sum_total = 0;
  char indicator, slash, current_indicator;
  int current_month, current_day, current_year, current_total_days;
  double amount;

  // Array full of days in each month (0-11)
  const int days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // Take in the initial date and balance
  cin >> initial_month >> slash >> initial_day
  >> slash >> initial_year >> initial_balance;

  // Set the current variables to the initial variables
  current_month = initial_month;
  current_day = initial_day;
  current_year = initial_year;
  current_total_days = 0;
  current_balance = initial_balance;

  // Make variables for loop
  int month, day, year;
  int loop_count = 0, total_days = 0;
  while (true) {
    // Take in the indicator as the first input (All inputs separated by space)
    cin >> indicator;

    // Checks indicator if it is q and adds the current balance and quits.
    if (indicator == 'q') {
      if (current_indicator == 'd')
        sum_total += (current_balance);
      else if (current_indicator == 'c')
        sum_total += (current_balance);
      break;
    }

    // Takes in the date and amount for all the additional transactions
    cin >> month >> slash >> day >> slash >> year >> amount;

    // Finds if it is leap year and what the total days are;
    bool leap_year = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));

    if (month == initial_month) {
      total_days = day - initial_day + 1;
    } else if (month == initial_month + 1
    || (initial_month == 12 && month == 1)) {
      if (leap_year && initial_month == 2) {
        total_days = ((29 - initial_day) + day + 1);
      } else {
        total_days = days_per_month[initial_month - 1] - initial_day + day + 1;
      }
    } else if (month == initial_month + 2) {
      if (current_total_days <= 30) {
        total_days = ((days_per_month[initial_month - 1] - initial_day)
        + days_per_month[initial_month] + day + 1);
      } else {
        sum_total = initial_balance * 30;
        break;
      }
    } else {
      break;
    }

    // Checks to see if the transaction goes over 30 days
    if (total_days > 30) {
      sum_total += (current_balance * (31 - current_total_days));
      break;
    }

    // Checks if it is the first iteration of loop or not to get the sum_total
    if (loop_count == 0) {
      sum_total = current_balance * (total_days - 1);
    } else {
      sum_total += current_balance * (total_days - current_total_days);
    }

    // Checks to see if the neew entry is out-of-order from the previous one
    if ((month < current_month && year < current_year)
    || (day < current_day && month == current_month) || year < current_year) {
      cout << "Entries must be provided in chronological order." << endl;
      cout << month << slash << day << slash << year
      << " entered after " << current_month << slash << current_day
      << slash << current_year << endl;
      break;
    }

    // Credit and debit
    switch (indicator) {
      case 'd':
        current_balance -= amount;
        if (current_balance < 0) {
          current_balance -= 15;
          cout << "Overdraft on " << month << slash << day
          << ". $15 overdraft fee assessed." << endl;
        }
        break;
      case 'c':
        current_balance += amount;
        break;
    }

    // Prepares variables for the next iteration of the loop
    current_month = month;
    current_day = day;
    current_year = year;
    current_total_days = total_days;
    current_indicator = indicator;
    loop_count++;
  }

  /*
  * Checks to see if indicator was q and gives the average balance for that period
  * of time.
  */
  if (indicator == 'q') {
    average_balance = sum_total / total_days;
    cout << total_days << "-day average balance (" << initial_month
    << slash << initial_day << slash << initial_year << "-"
    << month << slash << day << slash << year << "): $"
    << std::fixed << std::setprecision(2) << average_balance << endl;
  }

  // Checks to see if the reason the loop quit is due to being over 30 days
  if (total_days > 30) {
    average_balance = sum_total / 30;

    // Checks if it was within the same month of initial date and outputs
    if (current_month == initial_month && current_year == initial_year) {
      cout << "30-day average balance (" << initial_month << slash
      << initial_day << slash << initial_year << "-"
      << month << slash << (initial_day + 29) << slash
      << year << "): $" << std::fixed << std::setprecision(2)
      << average_balance << endl;

    // Checks if it was in the next month of initial date and outputs
    } else if (current_month == initial_month + 1
    && current_year == initial_year) {
      int new_day;
      if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
      && initial_month == 2) {
        new_day = 30 - (30 - initial_day);
      } else {
        new_day = 30 - ((days_per_month[initial_month - 1] + 1) - initial_day);
      }

      cout << "30-day average balance (" << initial_month << slash
      << initial_day << slash << initial_year << "-" << current_month
      << slash << new_day << slash << current_year << "): $"
      << std::fixed << std::setprecision(2) << average_balance << endl;
    }
  }
  return 0;
}
