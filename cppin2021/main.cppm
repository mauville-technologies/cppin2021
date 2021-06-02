#define bool BoolWrapper

import vector3;

import <iostream>;

int main() {
    Vector3 vec1 { 
        .x = 1,
        .y = 2,
        .z = 3
    };

    Vector3 vec2 {
        .x = 3,
        .y = 2,
        .z = 1
    };

    // test output operator
    std::cout << vec1 << std::endl;

    // test addition / subtraction
    std::cout << vec1 + vec2 << std::endl;
    std::cout << vec1 - vec2 << std::endl;

    // test scalar multiplication and division
    std::cout << vec1 * 2 << std::endl;
    std::cout << vec1 / 2 << std::endl;
    std::cout << 3 * vec1 << std::endl;

    // test comparison operators
    std::cout << bool( vec1 == vec2 ) << std::endl;
    std::cout << bool( vec1 > vec2 ) << std::endl;
    std::cout << bool( vec1 <= vec2 ) << std::endl;
    std::cout << bool( vec1 != (2 * vec2) )<< std::endl;

    return 0;
}

#undef bool
