namespace math {
    struct Vector3 {
        double x;
        double y;
        double z;

        Vector3 operator+(const Vector3& other) const {
            return Vector3{
                x + other.x,
                y + other.y,
                z + other.z
            };
        }

        Vector3 operator-(const Vector3& other) const {
            return Vector3{
                x - other.x,
                y - other.y,
                z - other.z
            };
        }

        Vector3 operator*(double scalar) const {
            return Vector3{
                x * scalar,
                y * scalar,
                z * scalar
            };
        }

        double dotProduct(const Vector3& other) const {
            return (
                x * other.x + 
                y * other.y +
                z * other.z
            );
        }

    };

}
