// Copyright 2024 Aarsh Patel
#include<iostream>
using std::cout;
using std::endl;
using std::ostream;
#include<string>
using std::string;
#include"MonetaryUnit.h"


// ostream& operator << (ostream& whereto, const MonetaryUnit& mu) {
//   whereto << mu._unit_name << " " << mu._unit_symbol << "" << mu._unit_amount;
//   return whereto;
// }
MonetaryUnit::MonetaryUnit(string name, string symbol, double amount) :
    _unit_name("US dollars"), _unit_symbol("$"), _unit_amount(1) {
  SetName(name);
  SetSymbol(symbol);
  SetAmountEquivalentTo1Dollar(amount);
}

bool MonetaryUnit::SetName(string name) {
  if ( name.length() >= 1 ) {
    _unit_name = name;
  }
  return _unit_name == name;
}

bool MonetaryUnit::SetSymbol(string symbol) {
  if ( symbol.length() >= 1 ) {
    _unit_symbol = symbol;
  }
  return _unit_symbol == symbol;
}

bool MonetaryUnit::SetAmountEquivalentTo1Dollar(double amount) {
  if ( amount > 0 ) {
    _unit_amount = amount;
  }
  return _unit_amount == amount;
}

bool MonetaryUnit::operator==(const MonetaryUnit& anObject) const {
  return (_unit_name == anObject._unit_name && _unit_symbol == anObject._unit_symbol
          && _unit_amount == anObject._unit_amount);
}

