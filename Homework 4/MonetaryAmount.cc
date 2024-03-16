// Copyright 2024 Aarsh Patel
#include<iostream>
using std::ostream;
#include"MonetaryAmount.h"

// Initialize static data members
bool MonetaryAmount::display_unit_name = false;

// definition and implementation of Constructor
MonetaryAmount::MonetaryAmount(double value, const MonetaryUnit& object) :
    _value(value), _object(object) {
}

void MonetaryAmount::ConvertToUnit(const MonetaryUnit& object) {
  double conversion_factor = object.GetAmountEquivalentTo1Dollar() / _object.GetAmountEquivalentTo1Dollar();
  _value *= conversion_factor;
  _object = object;
}

bool MonetaryAmount::operator==(const MonetaryAmount& anObject) const {
  double object_value = anObject._value;
  if (!(_object == anObject._object)) {
    object_value *= anObject._object.GetAmountEquivalentTo1Dollar() / _object.GetAmountEquivalentTo1Dollar();
  }
  return _value == object_value;
}

bool MonetaryAmount::operator<(const MonetaryAmount& anObject) const {
  double object_value = anObject._value;
  if (!(_object == anObject._object)) {
    object_value *= anObject._object.GetAmountEquivalentTo1Dollar() / _object.GetAmountEquivalentTo1Dollar();
  }
  return _value < object_value;
}

bool MonetaryAmount::operator>(const MonetaryAmount& anObject) const {
  double object_value = anObject._value;
  if (!(_object == anObject._object)) {
    object_value *= anObject._object.GetAmountEquivalentTo1Dollar() / _object.GetAmountEquivalentTo1Dollar();
  }
  return _value > object_value;
}

ostream& operator<<(ostream& os, MonetaryAmount& mu) {
  (MonetaryAmount::display_unit_name) ? os << mu.GetValue() << " " << mu.GetUnit().GetName() : 
    os << mu.GetUnit().GetSymbol() << mu.GetValue();
  
  return os;
}

MonetaryAmount operator+(const MonetaryAmount& mu_one, const MonetaryAmount& mu_two) {
  double object_value = mu_one.GetValue();
  if (!(mu_one == mu_two)) {
    object_value += mu_two.GetValue() * 
      (mu_one.GetUnit().GetAmountEquivalentTo1Dollar() / mu_two.GetUnit().GetAmountEquivalentTo1Dollar()); 
  }
  return MonetaryAmount(object_value, mu_one.GetUnit());
}

