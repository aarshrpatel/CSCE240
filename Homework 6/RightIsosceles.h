// Copyright 2024 Aarsh Patel
#ifndef RIGHTISOSCELES_H_
#define RIGHTISOSCELES_H_

#include "PixelShape.h"

namespace CSCE240_Program6 {

class RightIsosceles : public PixelShape {
 private:
  int leg_;

 public:
  // Constructor with default values
  explicit RightIsosceles(int leg = 2, char pixel = '*');

  // Virtual destructor
  virtual ~RightIsosceles();

  // Mutators and Accessors
  void SetLeg(int newLeg);
  int GetLeg() const;

  // Pure virtual operator*=
  RightIsosceles& operator*=(double factor) override;

  // Print function
  void Print(bool fill = true) const override;
};

}  // namespace CSCE240_Program6

#endif  // RIGHTISOSCELES_H_
