import thebasics;

import <limits>;
import <compare>;
int main() {

    SpaceShipOperator<float>(12.f, 10.f);
    SpaceShipOperator<float>(10.f, 11.f);
    SpaceShipOperator<float>(10.f, 10.f);
    SpaceShipOperator<float>(std::numeric_limits<float>::quiet_NaN(), 0.f);
    return 0;
}