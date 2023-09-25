#include "./Vector2.h"

namespace math {
    struct Mat2x2 {
        double 
            a11, a12,
            a21, a22
        ;

        Mat2x2 operator+(Mat2x2);

        // matrix multiplication
        Mat2x2 operator*(Mat2x2);

        Mat2x2 operator*(const Vector2&);

        static Vector2 Rotation(const Vector2&, const double);
        





    };
}
