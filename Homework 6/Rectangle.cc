// Copyright 2024 Aarsh Patel
#include "Rectangle.h"
#include <iostream>

namespace CSCE240_Program6 {

Rectangle::Rectangle(int length, int width, char pixel)
  : PixelShape("rectangle", pixel),
  length_(length > 0 ? length : 2), width_(width > 0 ? width : 1) {}

Rectangle::~Rectangle() {}

void Rectangle::SetLength(int new_length) {
  if (new_length > 0) {
    length_ = new_length;
  }
}

void Rectangle::SetWidth(int new_width) {
  if (new_width > 0) {
    width_ = new_width;
  }
}

int Rectangle::GetLength() const {
  return length_;
}

int Rectangle::GetWidth() const {
  return width_;
}

Rectangle& Rectangle::operator*=(double factor) {
  int new_length = static_cast<int>(length_ * factor);
  int new_width = static_cast<int>(width_ * factor);
  if (new_length > 0 && new_width > 0) {
    length_ = new_length;
    width_ = new_width;
  }
  return *this;
}

void Rectangle::Print(bool fill) const {
  std::cout << GetName() << std::endl;
  for (int i = 0; i < length_; i++) {
    for (int j = 0; j < width_; j++) {
      if (!fill && (i != 0 && i != length_ - 1 && j != 0 && j != width_ - 1)) {
        std::cout << "  ";
        continue;
      }
      std::cout << GetPixel() << " ";
    }
    std::cout << std::endl;
  }
}

}  // namespace CSCE240_Program6
