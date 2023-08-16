#pragma once

#include "Arduino.h"

namespace linear_algebra {
class Vector3 {
    std::array<float, 3> data;

public:
    Vector3(std::array<float, 3> data);

    float at(uint8_t index);
    float operator[](uint8_t index);

    float norm() const;
    float dot(const Vector3& other) const;
    float angle_with(const Vector3& other) const;
};

class Matrix3x3 {
    std::array<std::array<float, 3>, 3> calculate_rref(std::array<std::array<float, 3>, 3> data);
    uint8_t determinant;

public:
    const std::array<std::array<float, 3>, 3> data;
    const std::array<std::array<float, 3>, 3> rref;

    Matrix3x3(std::array<std::array<float, 3>, 3> data);

    Vector3 at(uint8_t row) const;
    Vector3 operator[](uint8_t row) const;

    float det() const;
    float trace() const;
    float norm() const;
};

Matrix3x3 operator+(const Matrix3x3& lhs, const Matrix3x3& rhs);
Matrix3x3 operator-(const Matrix3x3& lhs, const Matrix3x3& rhs);
Matrix3x3 operator*(const Matrix3x3& lhs, const Matrix3x3& rhs);
Matrix3x3 operator*(const Matrix3x3& lhs, float rhs);
Matrix3x3 operator*(float lhs, const Matrix3x3& rhs);

} // namespace linear_agebra
