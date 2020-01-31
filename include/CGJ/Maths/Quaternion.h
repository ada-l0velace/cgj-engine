#ifndef QUATERNION_H
#define QUATERNION_H

#include <array>
#include "vector4.h"
#include "matrix4.h"
namespace cgj {
class Quaternion {
    private:
        const float qThreshold = 1.0e-6f;
    public:
        float t, x, y, z;

        Quaternion(float _t = 1.0f, float _x = 0.0f, float _y = 0.0f, float _z = 0.0f);
        Quaternion(float theta, Vector4 _axis);
        ~Quaternion();

        Quaternion& operator=(const Quaternion&);

        Quaternion operator+ (const Quaternion&) const;
        Quaternion operator- (const Quaternion&) const;

        Quaternion operator* (float k) const;
        const friend Quaternion operator* (float k, const Quaternion &q);
        Quaternion& operator*=(float s);
        Quaternion& operator*=(const Quaternion& other);
        Quaternion operator* (const Quaternion& q) const;
        bool operator== (const Quaternion& q) const;

        void toAngleAxis(float&, Vector4&);
        const float quadrance() const;
        const float norm() const;
        Quaternion& normalize();
        Quaternion conjugate();
        Quaternion inverse();
        Matrix4 toMatrix();
        friend Quaternion lerp(const Quaternion& q0, const Quaternion& q1, float k);
        friend Quaternion slerp(const Quaternion& q0, const Quaternion& q1, float k);

        friend std::ostream& operator << (std::ostream& os, const Quaternion& q);
        friend std::istream& operator >> (std::istream& os, const Quaternion& q);
        void clean();
        
};
};
#endif