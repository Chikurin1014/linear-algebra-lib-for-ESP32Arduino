#include "Arduino.h"

#include "linear_algebra.hpp"

using Mat3 = linear_algebra::Matrix3x3;
using Vec3 = linear_algebra::Vector3;

std::array<std::array<float, 3>, 3> data({ { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } } });
std::array<std::array<float, 3>, 3> data2({ { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } } });
Mat3 A(data);
Mat3 B(data2);
Vec3 u({ 1, 2, 3 });
Vec3 v({ 4, 5, 6 });

void setup() {
    Serial.begin(9600);
    Serial.println("setup!");
    Serial.printf("A.det() = %f\n", A.det());
    Serial.printf("A.trace() = %f\n", A.trace());
    Serial.printf("A.norm() = %f\n", A.norm());
    Serial.printf("(2 * A)[0][0] = %f\n", (2 * A)[0][0]);
    Serial.printf("(A + B)[0][0] = %f\n", (A + B)[0][0]);
    Serial.printf("(A - B)[0][0] = %f\n", (A - B)[0][0]);
    Serial.printf("(A * B)[0][0] = %f\n", (A * B)[0][0]);
    Serial.printf("u.norm() = %f\n", u.norm());
    Serial.printf("v.dot(v) = %f\n", u.dot(v));
    Serial.printf("u.angle_with(v) = %f\n", u.angle_with(v));
}

void loop() { }