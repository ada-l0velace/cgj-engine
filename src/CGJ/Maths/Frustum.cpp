#include <CGJ/Maths/Frustum.h>
namespace cgj {
enum Planes {
    Near,
    Far,
    Left,
    Right,
    Top,
    Bottom,
};

float Plane::distanceToPoint(const Vector3& point) const {
    return point.dot(normal) + distanceToOrigin;
}

void ViewFrustum::update(const Matrix4& mat) noexcept {
    // left
    m_planes[Planes::Left].normal.x = mat[3] + mat[0];
    m_planes[Planes::Left].normal.y = mat[7] + mat[4];
    m_planes[Planes::Left].normal.z = mat[11] + mat[8];
    m_planes[Planes::Left].distanceToOrigin = mat[15] + mat[12];

    // right
    m_planes[Planes::Right].normal.x = mat[3] - mat[0];
    m_planes[Planes::Right].normal.y = mat[7] - mat[4];
    m_planes[Planes::Right].normal.z = mat[11] - mat[8];
    m_planes[Planes::Right].distanceToOrigin = mat[15] - mat[12];

    // bottom
    m_planes[Planes::Bottom].normal.x = mat[3] + mat[1];
    m_planes[Planes::Bottom].normal.y = mat[7] + mat[5];
    m_planes[Planes::Bottom].normal.z = mat[11] + mat[9];
    m_planes[Planes::Bottom].distanceToOrigin = mat[15] + mat[13];

    // top
    m_planes[Planes::Top].normal.x = mat[3] - mat[1];
    m_planes[Planes::Top].normal.y = mat[7] - mat[5];
    m_planes[Planes::Top].normal.z = mat[11] - mat[9];
    m_planes[Planes::Top].distanceToOrigin = mat[15] - mat[13];

    // near
    m_planes[Planes::Near].normal.x = mat[12] + mat[8];
    m_planes[Planes::Near].normal.y = mat[13] + mat[9];
    m_planes[Planes::Near].normal.z = mat[14] + mat[10];
    m_planes[Planes::Near].distanceToOrigin = mat[15] + mat[14];

    // far
    m_planes[Planes::Far].normal.x = mat[2];//mat[3 ] - mat[2];
    m_planes[Planes::Far].normal.y = mat[6];//mat[7 ] - mat[6];
    m_planes[Planes::Far].normal.z = mat[10];//mat[11] - mat[10];
    m_planes[Planes::Far].distanceToOrigin = mat[14];//mat[15] - mat[11];

    for (auto &plane : m_planes) {
        float length = plane.normal.magnitude();
        plane.normal /= length;
        plane.distanceToOrigin /= length;
    }
}

bool ViewFrustum::isBoxInFrustum(const AABB& box) const noexcept {
    bool result = true;
    for (auto &plane : m_planes) {
        //std::cout << plane.normal << "\n";
        if (plane.distanceToPoint(box.getVP(plane.normal)) < 0) {
            return false;
        }
        else if (plane.distanceToPoint(box.getVN(plane.normal)) < 0) {
            result = true;
        }
    }
    //std::cout << "---------------------\n";
    return result;
}
}