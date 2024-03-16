// Copyright 2024 Aarsh Patel
#ifndef _MONETARY_AMOUNT_H_
#define _MONETARY_AMOUNT_H_
#include"MonetaryUnit.h"
#include<iostream>
using std::ostream;

class MonetaryAmount {
 public:
  explicit MonetaryAmount(double value = 0, const MonetaryUnit& object = MonetaryUnit("US dollars", "$", 1));
  ~MonetaryAmount() {}

  double GetValue() const { return _value; }
  MonetaryUnit GetUnit() const { return _object; }

  void ConvertToUnit(const MonetaryUnit& object);

  static bool display_unit_name;

  bool operator==(const MonetaryAmount& anObject) const;
  bool operator<(const MonetaryAmount& anObject) const;
  bool operator>(const MonetaryAmount& anObject) const;
  
  friend ostream& operator<<(ostream&, const MonetaryUnit&);
  friend MonetaryAmount& operator+(const MonetaryUnit& one, const MonetaryUnit& two);


 private:
  double _value;
  MonetaryUnit _object;
};

#endif