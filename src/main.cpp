#include "Arduino.h"

#include "linear_algebra.hpp"

using Mat3 = linear_algebra::Matrix3x3;
using Vec3 = linear_algebra::Vector3;

std::array<std::array<float, 3>, 3> data({ { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } } });
Mat3 A(data);
Vec3 v({ 1, 2, 3 });

void setup() {
    Serial.begin(9600);
    Serial.println(A.det());
    Serial.println(A.trace());
    Serial.println(A.norm());
    Serial.println(v.norm());
    Serial.println(v.dot(v));
    Serial.println(v.angle_with(v));
}

void loop() { }