export module thebasics;

import <compare>;
import <iostream>;
import <format>;

/**
 * @brief The spaceship is also known as the Three Way Conditional
 * It looks like <=>
 * @param i 
*/
export template <typename T>
void SpaceShipOperator(T i, T compareWith);



template <typename T>
void SpaceShipOperator(T i, T compareWith) {
    auto result{ i <=> compareWith };

    if (std::is_lt(result)) {
        std::cout << std::format("{} is less than {}", i, compareWith) << std::endl;
    }

    if (std::is_lteq(result)) {
        std::cout << std::format("{} is less than or equal to {}", i, compareWith) << std::endl;
    }

    if (std::is_gt(result)) {
        std::cout << std::format("{} is greater than {}", i, compareWith) << std::endl;
    }

    if (std::is_gteq(result)) {
        std::cout << std::format("{} is greater than or equal to {}", i, compareWith) << std::endl;
    }

    if (std::is_eq(result)) {
        std::cout << std::format("{} is equivalent to {}", i, compareWith) << std::endl;
    }

    if (std::is_neq(result)) {
        std::cout << std::format("{} is not equal to {}", i, compareWith) << std::endl;
    }
}
