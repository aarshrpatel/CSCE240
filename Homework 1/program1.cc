// Copyright 2024 Aarsh Patel
#include<iostream>
#include<iomanip>
using std::cout;
using std::cin;
using std::endl;

int main() {
  // m/d/yyyy numeric_balance
  int initial_month, initial_day, initial_year;
  double initial_balance, current_balance, average_balance = 0, sum_total = 0;
  char indicator, slash, current_indicator;
  int current_month, current_day, current_year, current_total_days;
  double amount;

  // Array full of days in each month
  const int days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  cin >> initial_month >> slash >> initial_day
  >> slash >> initial_year >> initial_balance;

  current_month = initial_month;
  current_day = initial_day;
  current_year = initial_year;
  current_total_days = 0;
  current_balance = initial_balance;

  int month, day, year;
  int loop_count = 0, total_days = 0;
  while (true) {
    cin >> indicator;

    if (indicator == 'q') {
      if (current_indicator == 'd')
        sum_total += (current_balance);
      else if (current_indicator == 'c')
        sum_total += (current_balance);
      break;
    }

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

    if (total_days > 30) {
      sum_total += (current_balance * (31 - current_total_days));
      break;
    }

    if (loop_count == 0) {
      sum_total = current_balance * (total_days - 1);
    } else {
      sum_total += current_balance * (total_days - current_total_days);
    }

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

    current_month = month;
    current_day = day;
    current_year = year;
    current_total_days = total_days;
    current_indicator = indicator;
    loop_count++;
  }

  if (indicator == 'q') {
    average_balance = sum_total / total_days;
    cout << total_days << "-day average balance (" << initial_month
    << slash << initial_day << slash << initial_year << "-"
    << month << slash << day << slash << year << "): $"
    << std::fixed << std::setprecision(2) << average_balance << endl;
  }

  if (total_days > 30) {
    average_balance = sum_total / 30;

    if (current_month == initial_month && current_year == initial_year) {
      cout << "30-day average balance (" << initial_month << slash
      << initial_day << slash << initial_year << "-"
      << month << slash << (initial_day + 29) << slash
      << year << "): $" << std::fixed << std::setprecision(2)
      << average_balance << endl;

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
