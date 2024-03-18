// Copyright 2024 Aarsh Patel
#ifndef _MONETARYUNIT_H_
#define _MONETARYUNIT_H_
#include<iostream>
#include<string>
using std::string;
class MonetaryUnit {
 public:
  // Constructor with default values
  explicit MonetaryUnit(string name = "US dollars",
  string symbol = "$", double amount = 1);

  // Destructor
  ~MonetaryUnit() {}

  // Setters and Getters
  bool SetName(string name);
  string GetName() const { return _unit_name; }
  bool SetSymbol(string symbol);
  string GetSymbol() const { return _unit_symbol; }
  bool SetAmountEquivalentTo1Dollar(double amount);
  double GetAmountEquivalentTo1Dollar() const { return _unit_amount; }

  // Overloaded equal operator
  bool operator==(const MonetaryUnit& anObject) const;

 private:
  string _unit_name;  // Name of the unit
  string _unit_symbol;  // Symbol of the unit
  double _unit_amount;  // Amount equivalent to 1 dollar
};

#endif  // _MONETARYUNIT_H_
