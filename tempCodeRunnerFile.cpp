#include <iostream>
#include "core.h"   // this also pulls in precision.h

int main() {
    cyclone::Vector3 v(1.0f, 2.0f, 3.0f);
    std::cout << v.x << " " << v.y << " " << v.z << "\n";
    v.normalize();
    std::cout << v.x << " " << v.y << " " << v.z << "\n";
    return 0;

}
