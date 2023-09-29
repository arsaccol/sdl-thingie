#include "./Vector2.h"
#include <cmath>

namespace math {
    struct Mat2x2 {
        double 
            a11, a12,
            a21, a22
        ;

        Mat2x2 operator+(Mat2x2);

        // matrix multiplication
        Mat2x2 operator*(const Mat2x2& other) const {
            return Mat2x2 {
                a11 * other.a11 + a12 * other.a21,      a11 * other.a12 + a12 * other.a22,
                a21 * other.a11 + a22 * other.a21,      a21 * other.a12 + a22 * other.a22,
            };

        }

        static Mat2x2 identity() {
            return Mat2x2 {
                1.0, 0.0,
                0.0, 1.0
            };
        }

        Vector2 operator*(const Vector2& vector) const {
            return Vector2 {
                a11 * vector.x + a12 * vector.x,
                a21 * vector.y + a22 * vector.y,
            };

        }

        static Mat2x2 rotationMatrix(const double angleRads) {
            return Mat2x2{
                std::cos(angleRads), -std::sin(angleRads),
                std::sin(angleRads), std::cos(angleRads),
            };
        }


    };
}
