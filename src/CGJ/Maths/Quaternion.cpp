#include <CGJ/Maths/Quaternion.h>
#include <CGJ/Maths/mathf.h>

namespace cgj {
Quaternion::Quaternion(float _t, float _x, float _y, float _z) {
    t = _t;
    x = _x;
    y = _y;
    z = _z;
}

Quaternion::Quaternion(float theta, Vector4 _axis) {
    const float fHalfAngle = 0.5f*math::toRadians(theta);
    const float fSin = sinf(fHalfAngle);
    t = cosf(fHalfAngle);
    x = fSin*_axis.x;
    y = fSin*_axis.y;
    z = fSin*_axis.z;
    normalize();
}

Quaternion::~Quaternion() {}

Quaternion& Quaternion::operator=(const Quaternion& q) {
    t = q.t;
    x = q.x;
    y = q.y;
    z = q.z;
    return *this;
}

// OPERATORS
Quaternion Quaternion::operator+ (const Quaternion& q) const {
    return Quaternion(t + q.t,
                      x + q.x,
                      y + q.y,
                      z + q.z);
}

Quaternion Quaternion::operator- (const Quaternion& q) const {
    return Quaternion(t - q.t,
                      x - q.x,
                      y - q.y,
                      z - q.z);
}

Quaternion Quaternion::operator* (float k) const {
    return Quaternion(t * k,
                      x * k,
                      y * k,
                      z * k);
}

const Quaternion operator* (float k, const Quaternion &q) {
    return Quaternion(q.t * k,
                      q.x * k,
                      q.y * k,
                      q.z * k);
}
Quaternion Quaternion::operator* (const Quaternion& q) const {    
    return Quaternion(t * q.t - x * q.x - y * q.y - z * q.z,
                      t * q.x + x * q.t + y * q.z - z * q.y,
                      t * q.y + y * q.t + z * q.x - x * q.z,
                      t * q.z + z * q.t + x * q.y - y * q.x);
}

Quaternion& Quaternion::operator*=(float s) {
    x*=s;
    y*=s;
    z*=s;
    t*=s;
    return *this;
}

Quaternion& Quaternion::operator*=(const Quaternion& other) {
    return (*this = other * (*this));
}

bool Quaternion::operator== (const Quaternion& q) const {
    return (fabs(t - q.t) < qThreshold &&
            fabs(x - q.x) < qThreshold &&
            fabs(y - q.y) < qThreshold &&
            fabs(z - q.z) < qThreshold);
}
//

void Quaternion::toAngleAxis(float& theta, Vector4& axis) {
    normalize();
    
    theta = math::toDegrees(2.0f * acosf(t));//2.0f * acos(qn.t) * (float)RADIANS_TO_DEGREES;
    float s = sqrtf(1.0f - t*t);
    if (s < qThreshold) {
        axis.x = 1.0f;
        axis.y = 0.0f;
        axis.z = 0.0f;
        axis.w = 1.0f;
    }
    else {
        axis.x = x / s;
        axis.y = y / s;
        axis.z = z / s;
        axis.w = 1.0f;
    }
}

Quaternion Quaternion::conjugate() {
    return Quaternion(t, -x, -y, -z);
}

Quaternion Quaternion::inverse() { return conjugate() * (1.0f / quadrance()); }

const float Quaternion::quadrance() const {
    return t*t + x*x + y*y + z*z;
}

const float Quaternion::norm() const {
    return sqrtf(quadrance());
}

Quaternion& Quaternion::normalize() {
    float n = x*x + y*y + z*z + t*t;
 
     if (n == 1)
         return *this;
 
    n = 1.0f / sqrtf(n);
    return (*this *= n);
}

Matrix4 Quaternion::toMatrix() {
    Matrix4 m4 = Matrix4();
    Quaternion& q = normalize();

    float xx = q.x * q.x;
    float xy = q.x * q.y;
    float xz = q.x * q.z;
    float xt = q.x * q.t;
    float yy = q.y * q.y;
    float yz = q.y * q.z;
    float yt = q.y * q.t;
    float zz = q.z * q.z;
    float zt = q.z * q.t;

    m4[0] = 1.0f - 2.0f * ( yy + zz );
    m4[1] = 2.0f * ( xy + zt );
    m4[2] = 2.0f * ( xz - yt );
    m4[3] = 0.0f;

    m4[4] = 2.0f * ( xy - zt );
    m4[5] = 1.0f - 2.0f * ( xx + zz );
    m4[6] = 2.0f * ( yz + xt );
    m4[7] = 0.0f;

    m4[8] = 2.0f * ( xz + yt );
    m4[9] = 2.0f * ( yz - xt );
    m4[10] = 1.0f - 2.0f * ( xx + yy );
    m4[11] = 0.0f;

    m4[12] = 0.0f;
    m4[13] = 0.0f;
    m4[14] = 0.0f;
    m4[15] = 1.0f;

    m4.clean();
    return m4;
}

Quaternion lerp(const Quaternion& q0, const Quaternion& q1, float k) {
    float cos_angle = q0.x*q1.x + q0.y*q1.y + q0.z*q1.z + q0.t*q1.t;
    float k0 = 1.0f - k;
    float k1 = (cos_angle > 0) ? k : -k;
    Quaternion qi = (q0 * k0) + (q1 * k1);
    return qi.normalize();
}

Quaternion slerp(const Quaternion& q0, const Quaternion& q1, float k){
    float angle = acosf(q0.x*q1.x + q0.y*q1.y + q0.z*q1.z + q0.t*q1.t);
    float k0 = sinf((1-k)*angle) / sinf(angle);
    float k1 = sinf(k*angle) / sinf(angle);
    Quaternion qi = (q0 * k0) + (q1 * k1);
    return qi.normalize();
}


std::ostream& operator << (std::ostream& os, const Quaternion& q) {
    os << "(" << q.t << ", " << q.x << ", " << q.y << ", " << q.z << ")";
    return os;
}

void Quaternion::clean() {
    if(fabs(t) < qThreshold)
        t = 0.0f;
    if(fabs(x) < qThreshold)
        x = 0.0f;
    if(fabs(y) < qThreshold)
        y = 0.0f;
    if(fabs(z) < qThreshold)
        z = 0.0f;
}
}