namespace math {
    struct Vector2 {
        double x;
        double y;

        Vector2 operator+(const Vector2& other) const {
            return Vector2{
                x + other.x,
                y + other.y
            };
        }

        Vector2 operator-(const Vector2& other) const {
            return Vector2{
                x - other.x,
                y - other.y
            };
        }

        Vector2 operator*(double scalar) const {
            return Vector2{
                x * scalar,
                y * scalar
            };
        }

        double dotProduct(const Vector2& other) const {
            return (
                x * other.x + 
                y * other.y
            );
        }
        
    };
}
