// Copyright 2024 Aarsh Patel
#include "RightIsosceles.h"
#include <iostream>

namespace CSCE240_Program6 {

RightIsosceles::RightIsosceles(int leg, char pixel) : PixelShape("right isosceles triangle", pixel), leg(leg) {}

RightIsosceles::~RightIsosceles() {}

void RightIsosceles::SetLeg(int newLeg) {
    if (newLeg >= 2) {
        leg = newLeg;
    }
}

int RightIsosceles::GetLeg() const {
    return leg;
}

RightIsosceles& RightIsosceles::operator*=(double factor) {
    int newLeg = static_cast<int>(leg * factor);
    if (newLeg >= 2) {
        leg = newLeg;
    }
    return *this;
}

void RightIsosceles::Print(bool fill) const {
    std::cout << GetName() << std::endl;
    for (int i = 1; i <= leg; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << GetPixel() << ' ';
        }
        std::cout << std::endl;
    }
}

} // namespace CSCE240_Program6
