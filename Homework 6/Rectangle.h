// Copyright 2024 Aarsh Patel
#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "PixelShape.h"

namespace CSCE240_Program6 {

class Rectangle : public PixelShape {
 private:
  int length_;
  int width_;

 public:
  // Constructor with default values
  explicit Rectangle(int length = 2, int width = 1, char pixel = '*');

  // Virtual destructor
  virtual ~Rectangle();

  // Mutators and Accessors
  void SetLength(int newLength);
  void SetWidth(int newWidth);
  int GetLength() const;
  int GetWidth() const;

  // Pure virtual operator*=
  Rectangle& operator*=(double factor) override;

  // Print function
  void Print(bool fill = true) const override;
};

}  // namespace CSCE240_Program6

#endif  // RECTANGLE_H_
