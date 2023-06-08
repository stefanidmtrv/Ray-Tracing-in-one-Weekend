#include <iostream>
#include <fstream>
#include "vec3.h"

int main() {
    std::ofstream myfile;
    myfile.open("test.ppm");

    int nx = 200;
    int ny = 100;
    myfile << "P3\n" << nx << " " << ny << "\n255\n";

    for(int j = ny - 1; j>=0; j--){
        for(int i = 0; i<nx; i++){
            // float r = float(i) / float(nx);
            // float g = float(j) / float(ny);
            // float b = 0.2;

            vec3 col( float(i) / float(nx), float(j) / float(ny), 0.2);

            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);

            myfile << ir << " " << ig << " " << ib << "\n";
        }
    }

    myfile.close();

    // vec3 myVec = vec3(3,5,6.7);

    // std::cout << myVec << std::endl;

    // vec3 myVec2 = vec3(1,5.7, 9.6);

    // std::cout << (myVec + myVec2) << std::endl;

    // std::cout << (myVec * myVec2) << std::endl;

    // std::cout << (myVec / myVec2) << std::endl;

    // std::cout << (4.6 * myVec2) << std::endl;

    // vec3 myVec3 = (myVec * myVec2);
    // myVec3.make_unit_vector();

    // std::cout << myVec3 << std::endl;
    return 0;

}