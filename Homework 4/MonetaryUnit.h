// Copyright 2024 Aarsh Patel
#ifndef _MONETARYUNIT_H_
#define _MONETARYUNIT_H_
#include<iostream>
using std::ostream;
#include<string>
using std::string;
class MonetaryUnit {
//   friend ostream& operator << (ostream&, const MonetaryUnit&);
 public:
  explicit MonetaryUnit(string name = "US dollars", string symbol = "$", double amount = 1);
  
  ~MonetaryUnit() { std::cout << "Destroying MonetaryUnit Class" << std::endl; }
  bool SetName(string name);
  string GetName() const { return _unit_name; }
  bool SetSymbol(string symbol);
  string GetSymbol() const { return _unit_symbol; }
  bool SetAmountEquivalentTo1Dollar(double amount);
  double GetAmountEquivalentTo1Dollar() const { return _unit_amount; }

 private:
  string _unit_name;
  string _unit_symbol;
  double _unit_amount;
};
#endif 