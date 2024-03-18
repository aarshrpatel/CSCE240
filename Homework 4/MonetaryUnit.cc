// Copyright 2024 Aarsh Patel
#include<iostream>
using std::cout;
using std::endl;
using std::ostream;
#include<string>
using std::string;
#include"MonetaryUnit.h"

// Constructor with default values
MonetaryUnit::MonetaryUnit(string name, string symbol, double amount) :
    _unit_name("US dollars"), _unit_symbol("$"), _unit_amount(1) {
  SetName(name);
  SetSymbol(symbol);
  SetAmountEquivalentTo1Dollar(amount);
}

// Setters
bool MonetaryUnit::SetName(string name) {
  // Check if the name is not empty
  if ( name.length() >= 1 ) {
    _unit_name = name;
  }
  return _unit_name == name;
}

bool MonetaryUnit::SetSymbol(string symbol) {
  // Check if the symbol is not empty
  if ( symbol.length() >= 1 ) {
    _unit_symbol = symbol;
  }
  return _unit_symbol == symbol;
}

bool MonetaryUnit::SetAmountEquivalentTo1Dollar(double amount) {
  // Check if the amount is positive
  if ( amount > 0 ) {
    _unit_amount = amount;
  }
  return _unit_amount == amount;
}

// Overloaded equal operator
bool MonetaryUnit::operator==(const MonetaryUnit& anObject) const {
  return (_unit_name == anObject._unit_name
          && _unit_symbol == anObject._unit_symbol
          && _unit_amount == anObject._unit_amount);
}

