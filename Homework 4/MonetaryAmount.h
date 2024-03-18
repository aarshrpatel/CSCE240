// Copyright 2024 Aarsh Patel
#ifndef _MONETARY_AMOUNT_H_
#define _MONETARY_AMOUNT_H_
#include"MonetaryUnit.h"
#include<iostream>
using std::ostream;

class MonetaryAmount {
 public:
  // Constructor with default values
  explicit MonetaryAmount(double value = 0,
    const MonetaryUnit& object = MonetaryUnit("US dollars", "$", 1));

  // Destructor
  ~MonetaryAmount() {}

  // Getters for private data members
  double GetValue() const { return _value; }
  MonetaryUnit GetUnit() const { return _object; }

  // Convert the value to the given unit
  void ConvertToUnit(const MonetaryUnit& object);

  // static data members
  static bool display_unit_name;

  // Overloaded operators
  bool operator==(const MonetaryAmount& anObject) const;
  bool operator<(const MonetaryAmount& anObject) const;
  bool operator>(const MonetaryAmount& anObject) const;

  // Overloaded friend operators
  friend ostream& operator<<(ostream& os, const MonetaryAmount& mu);
  friend MonetaryAmount operator+(const MonetaryAmount& one,
    const MonetaryAmount& two);


 private:
  double _value;  // Value of the amount
  MonetaryUnit _object;  // Unit of the amount
};

#endif  // _MONETARY_AMOUNT_H_
