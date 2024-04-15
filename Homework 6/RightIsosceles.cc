// Copyright 2024 Aarsh Patel
#include "RightIsosceles.h"
#include <iostream>

namespace CSCE240_Program6 {

RightIsosceles::RightIsosceles(int leg, char pixel)
  : PixelShape("right isosceles triangle", pixel),
  leg_(leg >= 2 ? leg : 2) {}

RightIsosceles::~RightIsosceles() {}

void RightIsosceles::SetLeg(int new_leg) {
  if (new_leg > 2) {
    this->leg_ = new_leg;
  }
}

int RightIsosceles::GetLeg() const {
  return this->leg_;
}

RightIsosceles& RightIsosceles::operator*=(double factor) {
  int new_leg = static_cast<int>(leg_ * factor);
  if (new_leg >= 2) {
    this->leg_ = new_leg;
  }
  return *this;
}

void RightIsosceles::Print(bool fill) const {
  std::cout << GetName() << std::endl;
  for (int i = 1; i <= leg_; ++i) {
    for (int j = 1; j <= i; ++j) {
      if (fill || i == leg_ || j == 1 || j == i) {
        std::cout << GetPixel() << ' ';
        continue;
      } else {
        std::cout << "  ";
      }
    }
    std::cout << std::endl;
  }
}

}  // namespace CSCE240_Program6
