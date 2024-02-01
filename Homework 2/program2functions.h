// Copyright 2024 Aarsh Patel
#ifndef _PROGRAM2FUNCTIONS_H_
#define _PROGRAM2FUNCTIONS_H_

int ToClosestPrime(int);
void PrintPrimesBetween(int lower_bound, int upper_bound,
bool include_bounds = false);
int LargestPrimeSequence(int);
void PrintAsDollarsAndCents(int cents);
bool MakePurchase(int cost, int &twenty_dollars, int &ten_dollars, int &five_dollars, int &one_dollar, int &quarters, int &dimes, int &nickels, int &pennies);

#endif