export module vector3;

import <cmath>;
import <compare>;
import <iostream>;
import <string>;

// let type T = Vector3
export struct Vector3 {
    float x{ 0 };
    float y{ 0 };
    float z{ 0 };

    float magnitude() const {
        return sqrt(x * x + y * y + z * z);
    }

    float relativeMagnitude() const {
        return x * x + y * y + z * z;
    }

    // member overloads
    // Left hand operand is of type T
    
    // Vector addition is a member function
    Vector3 operator+(const Vector3& rhs) {
        return {
            .x = x + rhs.x,
            .y = y + rhs.y,
            .z = z + rhs.z
        };
    }

    // Vector substraction is a member function
    Vector3 operator-(const Vector3& rhs) {
        return {
            .x = x - rhs.x,
            .y = y - rhs.y,
            .z = z - rhs.z
        };
    }

    // Vector * scalar is a member function
    Vector3 operator*(float rhs) const {
        return {
            .x = rhs * x,
            .y = rhs * y,
            .z = rhs * z
        };
    }

    // Vector / scalar is a member function -- You can allow divide by scalar
    Vector3 operator/(float rhs) const {
        return (*this) * (1 / rhs);
    }

    // Comparison operators are always done as a member function
    // Spaceship operator reduces a whole lot of work

    // > < == != >= <= | 6 OVERLOADS!
    // default spaceship operator overload
    std::partial_ordering operator<=>(Vector3 rhs) {
        return this->relativeMagnitude() <=> rhs.relativeMagnitude();
    }

    // if we're not using default spaceship operator,
    // we also need to overload == operator aswell
    bool operator==(Vector3 rhs) {
        return this->relativeMagnitude() == rhs.relativeMagnitude();
    }
};


// global overloads

// scalar * vector is in global scope
export Vector3 operator*(float lhs, const Vector3& rhs) {
    return {
        .x = lhs * rhs.x,
        .y = lhs * rhs.y,
        .z = lhs * rhs.z
    };
}

// Disallow scalar divide by vector

// << 
export std::ostream& operator<<(std::ostream& os, const Vector3& rhs) {
    return os << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
}

export struct BoolWrapper {
    bool value;

    operator bool() const{
        return value;
    }
};

export std::ostream& operator<<(std::ostream& os, const BoolWrapper& rhs) {
    std::string text = rhs ? "true" : "false";
    return os << text;
}

/**

    Vector3 newVector = vec1 + vec2;

    Vector3 scaledVector = vec1 * 2;
    Vector3 scaledVector = 2 * vec1;

    bool equals = (vec1 == 3);

*/