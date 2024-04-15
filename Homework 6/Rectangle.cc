// Copyright 2024 Aarsh Patel
#include "Rectangle.h"
#include <iostream>

namespace CSCE240_Program6 {

Rectangle::Rectangle(int length, int width, char pixel)
  : PixelShape("rectangle", pixel),
  length(length > 0 ? length : 2), width(width > 0 ? width : 1) {}

Rectangle::~Rectangle() {}

void Rectangle::SetLength(int newLength) {
  if (newLength > 0) {
    length = newLength;
  }
}

void Rectangle::SetWidth(int newWidth) {
  if (newWidth > 0) {
    width = newWidth;
  }
}

int Rectangle::GetLength() const {
  return length;
}

int Rectangle::GetWidth() const {
  return width;
}

Rectangle& Rectangle::operator*=(double factor) {
  int newLength = static_cast<int>(length * factor);
  int newWidth = static_cast<int>(width * factor);
  if (newLength > 0 && newWidth > 0) {
    length = newLength;
    width = newWidth;
  }
  return *this;
}

void Rectangle::Print(bool fill) const {
  std::cout << GetName() << std::endl;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < width; j++) {
      if (!fill && (i != 0 && i != length - 1 && j != 0 && j != width - 1)) {
        std::cout << "  ";
        continue;
      }
      std::cout << GetPixel() << " ";
    }
    std::cout << std::endl;
  }
}

}  // namespace CSCE240_Program6
