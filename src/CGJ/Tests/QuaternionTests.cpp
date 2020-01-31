#include <gtest/gtest.h>
#include <CGJ/Maths.h>
using namespace cgj;
// Rotation of 90 degrees about the y-axis
TEST(Quaternion90DegreesYaxis, Nos) { 
    Vector4 axis = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	Quaternion q = Quaternion(90.0f, axis);
	Quaternion qi = Quaternion(0.0f, 7.0f, 0.0f, 0.0f);
	
	Quaternion qe = Quaternion(0.0f, 0.0f, 0.0f, -7.0f);
	
	Quaternion qinv = q.inverse();
	qinv.clean();
	
	Quaternion qf = q*qi*qinv;
	ASSERT_EQ(qf, qe);
}

// Rotation of 90 degrees about the y-axis with matrix
TEST(Quaternion90DegreesYaxisMatrix, Nos) {

	Vector4 axis = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	Quaternion q = Quaternion(90.0f, axis);
	
	Vector4 vi = Vector4(7.0f, 0.0f, 0.0f, 1.0f);
	
	Vector4 ve = Vector4(0.0f, 0.0f, -7.0f, 1.0f);
	
	Matrix4 m = q.toMatrix();
	
	Vector4 vf = m* vi;
	ASSERT_EQ(vf, ve);
}

// Yaw 900 = Roll 180 + Pitch 180
TEST(QuaternionYaw900Roll180Pitch180, Nos) {
	
	const Vector4 axis_x = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
	const Vector4 axis_y = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	const Vector4 axis_z = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

	Quaternion qyaw900 = Quaternion(900.0f, axis_y);
	Quaternion qroll180 = Quaternion(180.0f, axis_x);
	Quaternion qpitch180 = Quaternion(180.0f, axis_z);
	
	Quaternion qrp = qpitch180 * qroll180;
	Quaternion qpr = qroll180 * qpitch180;
	
	Quaternion qi = Quaternion(0.0f, 1.0f, 0.0f, 0.0f); // x-axis
	Quaternion qe = Quaternion(0.0f, -1.0f, 0.0f, 0.0f);
	
	Quaternion qfy = qyaw900 * qi * qyaw900.inverse();
	ASSERT_EQ(qe,qfy);
	
	Quaternion qfrp = qrp * qi* qrp.inverse();
	ASSERT_EQ(qe, qfrp);
	
	Quaternion qfpr = qpr* qi* qpr.inverse();
	ASSERT_EQ(qe, qfpr);
	
}

//Q <-> (angle, axis)
TEST(QuaternionAngleAxis, Nos) {
	float qThreshold = 1.0e-5f;
	float thetai = 45.0f;
	Vector4 axis_i = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	Quaternion q = Quaternion(thetai, axis_i);
	
	float thetaf;
	Vector4 axis_f;
	q.toAngleAxis(thetaf, axis_f);
	
	ASSERT_TRUE(fabs(thetai - thetaf) < qThreshold && axis_i == axis_f); 
}

TEST(QuaternionLerp, Nos) {
	Vector4 axis = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	Quaternion q0 = Quaternion(0.0f, axis);
	Quaternion q1 = Quaternion(90.0f, axis);
	Quaternion qe = Quaternion(30.0f, axis);
	
	Quaternion qLerp0 = lerp(q0, q1, 0.0f);
	ASSERT_EQ(qLerp0, q0);

	Quaternion qLerp1 = lerp(q0, q1, 1.0f);
	ASSERT_EQ(qLerp1, q1);

	Quaternion qlerp = lerp(q0, q1, 1/3.0f);
	
	ASSERT_FALSE(qlerp == qe);
	
}

//SLERP
TEST(QuaternionSlerp, Nos) {
	
	Vector4 axis = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	Quaternion q0 = Quaternion(0.0f, axis);
	Quaternion q1 = Quaternion(90.0f, axis);
	Quaternion qe = Quaternion(30.0f, axis);
	
	Quaternion qSlerp0 = slerp(q0, q1, 0.0f);
	ASSERT_EQ(qSlerp0, q0);

	Quaternion qSlerp1 = slerp(q0, q1, 1.0f);
	ASSERT_EQ(qSlerp1, q1);

	Quaternion qslerp = slerp(q0, q1, 1/3.0f);
	
	ASSERT_EQ(qslerp, qe);
}

/*
TEST 1 : Rotation of 90 degrees about the y-axis

   q = (0.707107, 0, 0.707107, 0)
  vi = (0, 7, 0, 0)
  qe = (0, 0, 0, -7)
qinv = (0.707107, 0, -0.707107, 0)
  qf = (0, 0, 0, -7)

TEST 2 : Rotation of 90 degrees about the y-axis with matrix

 q = (0.707107, 0, 0.707107, 0)
vi = (7, 0, 0, 1)
ve = (0, 0, -7, 1)
 M =
|  0.000  0.000  1.000  0.000 |
|  0.000  1.000  0.000  0.000 |
| -1.000  0.000  0.000  0.000 |
|  0.000  0.000  0.000  1.000 |
vf = (0.000, 0.000, -7.000, 1.000)

TEST 3 : Yaw 900 = Roll 180 + Pitch 180

  qyaw900 = (0.000, 0.000, 1.000, 0.000)
 qroll180 = (0.000, 1.000, 0.000, 0.000)
qpitch180 = (0.000, 0.000, 0.000, 1.000)
      qrp = (0.000, 0.000, 1.000, 0.000)
      qpr = (0.000, 0.000, -1.000, 0.000)
       qi = (0.000, 1.000, 0.000, 0.000)
       qe = (0.000, -1.000, 0.000, 0.000)
       qy = (0.000, -1.000, 0.000, 0.000)
     qfrp = (0.000, -1.000, 0.000, 0.000)
     qfpr = (0.000, -1.000, 0.000, 0.000)

TEST 4: Q <-> (angle, axis)

45.000 axis_i = (0.000, 1.000, 0.000, 1.000)
45.000 axis_f = (0.000, 1.000, 0.000, 1.000)

TEST 5: LERP

       q0 = (1.000, 0.000, 0.000, 0.000)
       q1 = (0.707, 0.000, 0.707, 0.000)
       qe = (0.966, 0.000, 0.259, 0.000)
  lerp(0) = (1.000, 0.000, 0.000, 0.000)
  lerp(1) = (0.707, 0.000, 0.707, 0.000)
lerp(1/3) = (0.968, 0.000, 0.253, 0.000)
lerp(1/3) = [
  angle = 29.278
  axis = (0.000, 1.000, 0.000, 1.000)
]

TEST 6: SLERP

        q0 = (1.000, 0.000, 0.000, 0.000)
        q1 = (0.707, 0.000, 0.707, 0.000)
        qe = (0.966, 0.000, 0.259, 0.000)
  slerp(0) = (1.000, 0.000, 0.000, 0.000)
  slerp(1) = (0.707, 0.000, 0.707, 0.000)
slerp(1/3) = (0.966, 0.000, 0.259, 0.000)
slerp(1/3) = [
  angle = 30.000
  axis = (0.000, 1.000, 0.000, 1.000)
]
*/