// #include <iostream>
// #include <cmath>

// int main() {
//     float a, b, c;
//     std::cin >> a >> b >> c;

//     float d, e, f;
//     std::cin >> d >> e >> f;

//     float n;
//     std::cin >> n;

//     float magnitude = std::sqrt(d*d + e*e + f*f);

//     float unit_d = d / magnitude;
//     float unit_e = e / magnitude;
//     float unit_f = f / magnitude;

//     float g = a + unit_d * n;
//     float h = b + unit_e * n;
//     float i = c + unit_f * n;

//     std::cout << g << " " << h << " " << i << std::endl;

//     return 0;
// }


// #include <iostream>
// #include <iomanip>
// #include <cmath>

// int main() {
//     float a, b, c;
//     std::cin >> a >> b >> c;

//     float d, e, f;
//     std::cin >> d >> e >> f;

//     float n;
//     std::cin >> n;

//     float magnitude = std::sqrt(d*d + e*e + f*f);

//     float unit_d = d / magnitude;
//     float unit_e = e / magnitude;
//     float unit_f = f / magnitude;

//     float g = a + unit_d * n;
//     float h = b + unit_e * n;
//     float i = c + unit_f * n;

//     std::cout << std::fixed << std::setprecision(6) << g << " " << h << " " << i << std::endl;

//     return 0;
// }


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    float ax, ay, aZ;
    float bx, by, bZ;
    float n;
    
    cin >> ax >> ay >> aZ;
    cin >> bx >> by >> bZ;
    cin >> n;

    float direction_vector[3] = {bx - ax, by - ay,  bZ- aZ};

    double length = sqrt(pow(direction_vector[0], 2) + pow(direction_vector[1], 2) + pow(direction_vector[2], 2));

    double unit_vector[3] = {direction_vector[0] / length, direction_vector[1] / length, direction_vector[2] / length};

    double bx = ax + unit_vector[0] * n;
    double by = ay + unit_vector[1] * n;
    double bZ = aZ + unit_vector[2] * n;

    std::cout << std::fixed << std::setprecision(6) << bx << " " << by << " " << bZ << std::endl;
     std::cout << length << std::endl;

    return 0;
}

