#include "linear_algebra.hpp"

using Mat3 = linear_algebra::Matrix3x3;
using Vec3 = linear_algebra::Vector3;

std::array<std::array<float, 3>, 3> Mat3::calculate_rref(std::array<std::array<float, 3>, 3> data) {
    determinant = 0;
    std::array<std::array<float, 3>, 3> rref = data;
    for (uint8_t rank = 0; rank < 3; rank++) {
        if (rref.at(rank).at(rank) == 0) {
            for (uint8_t i = rank + 1; i < 3; i++) {
                if (rref.at(i).at(rank) != 0) {
                    std::swap(rref.at(rank), rref.at(i));
                    break;
                }
            }
        }
        if (rref.at(rank).at(rank) == 0) {
            determinant = 0;
            return rref;
        }
        for (uint8_t i = rank + 1; i < 3; i++) {
            float factor = rref.at(i).at(rank) / rref.at(rank).at(rank);
            for (uint8_t j = 0; j < 3; j++) {
                rref.at(i).at(j) -= factor * rref.at(rank).at(j);
            }
        }
    }
    return rref;
}

Mat3::Matrix3x3(std::array<std::array<float, 3>, 3> data)
    : data(data)
    , rref(calculate_rref(data)) { }

Vec3 Mat3::at(uint8_t row) const { return Vec3(data.at(row)); }
Vec3 Mat3::operator[](uint8_t row) const { return at(row); }

float Mat3::det() const { return determinant; }
float Mat3::trace() const { return data[0][0] + data[1][1] + data[2][2]; }
float Mat3::norm() const { return sqrt(data[0][0] * data[0][0] + data[1][1] * data[1][1] + data[2][2] * data[2][2]); }

Vec3::Vector3(std::array<float, 3> data)
    : data(data) { }

float Vec3::at(uint8_t index) { return data.at(index); }
float Vec3::operator[](uint8_t index) { return at(index); }

float Vec3::norm() const { return sqrt(dot(*this)); }
float Vec3::dot(const Vec3& other) const {
    return data[0] * other.data[0] + data[1] * other.data[1] + data[2] * other.data[2];
}
float Vec3::angle_with(const Vec3& other) const { return acos(dot(other) / (norm() * other.norm())); }
