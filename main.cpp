#include <iostream>
#include <fstream>
#include "Sphere.h"
#include "Hittable_List.h"
#include "float.h"
#include "Ray.h"
#include "Vec3.h"

// float hit_sphere(const Vec3& center, float radius, const Ray& r){
//     Vec3 oc = r.origin() - center;
//     float a = dot(r.direction(), r.direction());
//     float b = 2.0 * dot(oc, r.direction());
//     float c = dot(oc, oc) - radius * radius;
//     float discriminant = b*b - 4*a*c;

//     if(discriminant < 0){
//         return -1.0;
//     }else{
//         return (-b -sqrt(discriminant)) / (2.0*a);
//     }
    
// }

Vec3 colour(const Ray& r, Hittable *world){

    hit_record rec;

    if(world->hit(r, 0.0, MAXFLOAT, rec)){
        return 0.5*Vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() +1);
    }
    else{
        Vec3 unit_direction = unit_vector(r.direction());
        float t = 0.5*(unit_direction.y() +  1.0);
        return lerp(Vec3(1.0, 1.0, 1.0), Vec3(0.5, 0.7, 1.0), t);
    }
}

int main() {
    std::ofstream myfile;
    myfile.open("test.ppm");

    // int nx = 200;
    // int ny = 100;

    int nx = 1920;
    int ny = 1080;

    myfile << "P3\n" << nx << " " << ny << "\n255\n";

    Vec3 lower_left_corner(-2.0, -1.0, -1.0);
    Vec3 horizontal(4.0, 0.0, 0.0);
    Vec3 vertical(0.0, 2.0, 0.0);
    Vec3 origin(0.0, 0.0, 0.0);

    Hittable *list[3];
    list[0] = new Sphere(Vec3(0,0,-1), 0.5);
    list[1] = new Sphere(Vec3(0,-100.5,-1), 100);
    list[2] = new Sphere(Vec3(-50, 47,-100), 25);
    Hittable *world = new Hittable_List(list, 3);

    for(int j = ny - 1; j>=0; j--){
        for(int i = 0; i<nx; i++){
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);
            Ray r(origin, lower_left_corner + u*horizontal + v*vertical);

           // Vec3 p = r.point_at_parameter(2.0);
        
            Vec3 col = colour(r, world);
            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);

            myfile << ir << " " << ig << " " << ib << "\n";
        }
    }

    myfile.close();

    // Vec3 myVec = Vec3(3,5,6.7);

    // std::cout << myVec << std::endl;

    // Vec3 myVec2 = Vec3(1,5.7, 9.6);

    // std::cout << (myVec + myVec2) << std::endl;

    // std::cout << (myVec * myVec2) << std::endl;

    // std::cout << (myVec / myVec2) << std::endl;

    // std::cout << (4.6 * myVec2) << std::endl;

    // Vec3 myVec3 = (myVec * myVec2);
    // myVec3.make_unit_vector();

    // std::cout << myVec3 << std::endl;
    return 0;

}