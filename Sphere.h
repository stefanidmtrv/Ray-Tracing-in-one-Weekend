#ifndef SPHERE_H
#define SPHERE_H

#include "Hittable.h"

class Sphere: public Hittable {
    public:
    Vec3 center;
    float radius;

    Sphere() {}
    Sphere(Vec3 cen, float r) : center(cen), radius(r) {};
    virtual bool hit(const Ray& r, float tmin, float tmax, hit_record& rec) const;
};

bool Sphere::hit(const Ray& r, float tmin, float tmax, hit_record& rec) const {
    Vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = dot(oc, r.direction());
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b*b - a*c;

    if(discriminant > 0){
        float temp = (-b - sqrt(b*b - a*c)) / a;
        if(temp < tmax && temp > tmin) {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }

        temp = (-b + sqrt(b*b - a*c)) /a;
        if(temp < tmax && temp > tmin){
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
    }
    return false;
}

#endif