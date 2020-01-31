#include <gtest/gtest.h>
#include <CGJ/Maths.h>
using namespace cgj;
// VECTOR CONVERTION 
TEST(Vec3Convertion, PositiveNos) { 
    ASSERT_EQ(Vector3(Vector2(1,2)), Vector3(1,2,1));
}

// ANGLE
TEST(Vec3AngleTest, PositiveNos) {
    ASSERT_FLOAT_EQ(0.12186805f,Vector3(1,2,3).angle(Vector3(2,3,4))); // might need to fix this later precision is not right
}

// SUM VECTORS
TEST(Vec3VectorSumTest, PositiveNos) { 
    ASSERT_EQ(Vector3(6,6,6), Vector3(3,3,3)+Vector3(3,3,3));
    ASSERT_EQ(Vector3(0,0,0), Vector3(0,0,0)+Vector3(0,0,0));
}

TEST(Vec3VectorSumTest, NegativeNos) { 
    ASSERT_EQ(Vector3(0,0,0), Vector3(-3,-3,-3)+Vector3(3,3,3));
    ASSERT_EQ(Vector3(0,0,0), Vector3(0,0,0)-Vector3(0,0,0));
}

// SUB VECTORS
TEST(Vec3VectorSubmTest, PositiveNos) { 
    ASSERT_EQ(Vector3(0,0,0), Vector3(3,3,3)-Vector3(3,3,3));
    ASSERT_EQ(Vector3(0,0,0), Vector3(0,0,0)-Vector3(0,0,0));
}

TEST(Vec3VectorSubTest, NegativeNos) { 
    ASSERT_EQ(Vector3(0,0,0), Vector3(-3,-3,-3)-Vector3(-3,-3,-3));
    ASSERT_EQ(Vector3(0,0,0), Vector3(0,0,0)-Vector3(0,0,0));
    ASSERT_EQ(Vector3(6,6,6), Vector3(3,3,3)-Vector3(-3,-3,-3));
}

// MUL VECTORS
TEST(Vec3VectorMulTest, PositiveNos) { 
    ASSERT_EQ(Vector3(9,6,9), Vector3(3,2,3)*Vector3(3,3,3));
    ASSERT_EQ(Vector3(0,0,0), Vector3(0,0,0)*Vector3(0,0,0));
}

TEST(Vec3VectorMulTest, NegativeNos) { 
    ASSERT_EQ(Vector3(9,9,9), Vector3(-3,-3,-3)*Vector3(-3,-3,-3));
    ASSERT_EQ(Vector3(0,0,0), Vector3(0,0,0)*Vector3(0,0,0));
    ASSERT_EQ(Vector3(-9,-9,-9), Vector3(3,3,3)*Vector3(-3,-3,-3));
}

// DIV VECTORS NEED TO CHECK DIVISION BY ZERO LATER
TEST(Vec3VectorDivTest, PositiveNos) { 
    ASSERT_EQ(Vector3(1,2.0f/3,1), Vector3(3,2,3)/Vector3(3,3,3));
    ASSERT_EQ(Vector3(0,0,0), Vector3(0,0,0)/Vector3(1,1,1));
}

TEST(Vec3VectorDivTest, NegativeNos) { 
    ASSERT_EQ(Vector3(1,1,1), Vector3(-3,-3,-3)/Vector3(-3,-3,-3));
    ASSERT_EQ(Vector3(0,0,0), Vector3(0,0,0)/Vector3(1,1,1));
    ASSERT_EQ(Vector3(-1,-1,-1), Vector3(3,3,3)/Vector3(-3,-3,-3));
}

// SUM SCALAR
TEST(Vec3ScalarSumTest, PositiveNos) { 
    ASSERT_EQ(Vector3(1+3,2+3,3+3), Vector3(1,2,3)+3);
    ASSERT_EQ(Vector3(1+3,2+3,2+3), Vector3(1,2,2)+3);
    ASSERT_EQ(Vector3(3,3,3), Vector3(0,0,0)+3);
    ASSERT_EQ(Vector3(28+3,22+3,22+3), Vector3(28,22,22)+3);
}

TEST(Vec3ScalarSumFirstTest, PositiveNos) { 
    ASSERT_EQ(Vector3(1+3,2+3,3+3), 3+Vector3(1,2,3));
    ASSERT_EQ(Vector3(1+3,2+3,2+3), 3+Vector3(1,2,2));
    ASSERT_EQ(Vector3(3,3,3), 3+Vector3(0,0,0));
    ASSERT_EQ(Vector3(28+3,22+3,22+3), 3+Vector3(28,22,22));
}

TEST(Vec3ScalarSumTest, NegativeNos) { 
    ASSERT_EQ(Vector3(-1+3,-2+3,-3+3), Vector3(-1,-2,-3)+3);
    ASSERT_EQ(Vector3(-1+3,-2+3,-2+3), Vector3(-1,-2,-2)+3);
    ASSERT_EQ(Vector3(-5+3,-3+3,-7+3), Vector3(-5,-3,-7)+3);
    ASSERT_EQ(Vector3(-28+3,-22+3,-22+3), Vector3(-28,-22,-22)+3);
}

TEST(Vec3ScalarSumFirstTest, NegativeNos) { 
    ASSERT_EQ(Vector3(-1+3,-2+3,-3+3), 3+Vector3(-1,-2,-3));
    ASSERT_EQ(Vector3(-1+3,-2+3,-2+3), 3+Vector3(-1,-2,-2));
    ASSERT_EQ(Vector3(-5+3,-3+3,-7+3), 3+Vector3(-5,-3,-7));
    ASSERT_EQ(Vector3(-28+3,-22+3,-22+3), 3+Vector3(-28,-22,-22));
}

// SUB SCALAR
TEST(Vec3ScalarSubTest, PositiveNos) { 
    ASSERT_EQ(Vector3(1-3,2-3,3-3), Vector3(1,2,3)-3);
    ASSERT_EQ(Vector3(1-3,2-3,2-3), Vector3(1,2,2)-3);
    ASSERT_EQ(Vector3(-3,-3,-3), Vector3(0,0,0)-3);
    ASSERT_EQ(Vector3(28-3,22-3,22-3), Vector3(28,22,22)-3);
}

TEST(Vec3ScalarSubTest, NegativeNos) { 
    ASSERT_EQ(Vector3(-1-3,-2-3,-3-3), Vector3(-1,-2,-3)-3);
    ASSERT_EQ(Vector3(-1-3,-2-3,-2-3), Vector3(-1,-2,-2)-3);
    ASSERT_EQ(Vector3(-5-3,-3-3,-7-3), Vector3(-5,-3,-7)-3);
    ASSERT_EQ(Vector3(-28-3,-22-3,-22-3), Vector3(-28,-22,-22)-3);
}

TEST(Vec3ScalarSubFirstTest, PositiveNos) { 
    ASSERT_EQ(Vector3(-3-1,-3-2,-3-3), -3-Vector3(1,2,3));
    ASSERT_EQ(Vector3(-3-1,-3-2,-3-2), -3-Vector3(1,2,2));
    ASSERT_EQ(Vector3(-3,-3,-3), -3-Vector3(0,0,0));
    ASSERT_EQ(Vector3(-3-28,-3-22,-3-22), -3-Vector3(28,22,22));
}

TEST(Vec3ScalarSubFirstTest, NegativeNos) { 
    ASSERT_EQ(Vector3(-3+1,-3+2,-3+3), -3-Vector3(-1,-2,-3));
    ASSERT_EQ(Vector3(-3+1,-3+2,-3+2), -3-Vector3(-1,-2,-2));
    ASSERT_EQ(Vector3(-3+5,-3+3,-3+7), -3-Vector3(-5,-3,-7));
    ASSERT_EQ(Vector3(-3+28,-3+22,-3+22), -3-Vector3(-28,-22,-22));
}

// MUL SCALAR
TEST(Vec3ScalarMulTest, PositiveNos) { 
    ASSERT_EQ(Vector3(1*3,2*3,3*3), Vector3(1,2,3)*3);
    ASSERT_EQ(Vector3(1*3,2*3,2*3), Vector3(1,2,2)*3);
    ASSERT_EQ(Vector3(0,0,0), Vector3(0,0,0)*3);
    ASSERT_EQ(Vector3(28*3,22*3,22*3), Vector3(28,22,22)*3);
}

TEST(Vec3ScalarMulTest, NegativeNos) { 
    ASSERT_EQ(Vector3(-1*3,-2*3,-3*3), Vector3(-1,-2,-3)*3);
    ASSERT_EQ(Vector3(-1*3,-2*3,-2*3), Vector3(-1,-2,-2)*3);
    ASSERT_EQ(Vector3(-5*3,-3*3,-7*3), Vector3(-5,-3,-7)*3);
    ASSERT_EQ(Vector3(-28*3,-22*3,-22*3), Vector3(-28,-22,-22)*3);
}

TEST(Vec3ScalarMulFirstTest, PositiveNos) { 
    ASSERT_EQ(Vector3(1*3,2*3,3*3), 3*Vector3(1,2,3));
    ASSERT_EQ(Vector3(1*3,2*3,2*3), 3*Vector3(1,2,2));
    ASSERT_EQ(Vector3(0,0,0), 3*Vector3(0,0,0));
    ASSERT_EQ(Vector3(28*3,22*3,22*3), 3*Vector3(28,22,22));
}

TEST(Vec3ScalarMulFirstTest, NegativeNos) { 
    ASSERT_EQ(Vector3(-1*3,-2*3,-3*3), 3*Vector3(-1,-2,-3));
    ASSERT_EQ(Vector3(-1*3,-2*3,-2*3), 3*Vector3(-1,-2,-2));
    ASSERT_EQ(Vector3(-5*3,-3*3,-7*3), 3*Vector3(-5,-3,-7));
    ASSERT_EQ(Vector3(-28*3,-22*3,-22*3), 3*Vector3(-28,-22,-22));
}

// DIV SCALAR
TEST(Vec3ScalarDivTest, PositiveNos) { 
    ASSERT_EQ(Vector3(1.0f/3,2.0f/3,3/3), Vector3(1,2,3)/3);
    ASSERT_EQ(Vector3(1.0f/3,2.0f/3,2.0f/3), Vector3(1,2,2)/3);
    ASSERT_EQ(Vector3(0,0,0), Vector3(0,0,0)/3);
    ASSERT_EQ(Vector3(28.0f/3,22.0f/3,22.0f/3), Vector3(28,22,22)/3);
}

TEST(Vec3ScalarDivTest, NegativeNos) { 
    ASSERT_EQ(Vector3(-1.0f/3,-2.0f/3.0f,-3/3), Vector3(-1,-2,-3)/3);
    ASSERT_EQ(Vector3(-1.0f/3,-2.0f/3.0f,-2.0f/3), Vector3(-1,-2,-2)/3);
    ASSERT_EQ(Vector3(-5.0f/3,-3/3,-7.0f/3), Vector3(-5,-3,-7)/3);
    ASSERT_EQ(Vector3(-28.0f/3,-22.0f/3,-22.0f/3), Vector3(-28,-22,-22)/3);
}

TEST(Vec3ScalarDivFirstTest, PositiveNos) { 
    ASSERT_EQ(Vector3(3/1.0f,3/2.0f,3/3), 3/Vector3(1,2,3));
}

TEST(Vec3ScalarDivFirstTest, NegativeNos) { 
    ASSERT_EQ(Vector3(3/(-1.0f),3.0f/(-2.0f),3/(-3)), 3/Vector3(-1,-2,-3));
}

// DOT PRODUCT
TEST(DotProductTest, PositiveNos) { 
    ASSERT_FLOAT_EQ(98, Vector3(3,5,8).dot(Vector3(3,5,8)));
    ASSERT_FLOAT_EQ(89, Vector3(0,5,8).dot(Vector3(1,5,8)));
    ASSERT_FLOAT_EQ(48, Vector3(6,5,2).dot(Vector3(4,2,7)));
    ASSERT_FLOAT_EQ(0.40277779f, Vector3(1.0f/3,1.0f/4,1.0f/6).dot(Vector3(2.0f/3,2.0f/4,2.0f/6)));
    ASSERT_FLOAT_EQ(98*3, 3*Vector3(3,5,8).dot(Vector3(3,5,8))); 
}

TEST(DotProductTest, NegativeNos) { 
    ASSERT_FLOAT_EQ(98, Vector3(-3,-5,-8).dot(Vector3(-3,-5,-8)));
    ASSERT_FLOAT_EQ(-89, Vector3(0,-5,8).dot(Vector3(1,5,-8)));
    ASSERT_FLOAT_EQ(0, Vector3(-6,5,-2).dot(Vector3(4,2,-7)));
    ASSERT_FLOAT_EQ(-0.15277779f, Vector3(-1.0f/3,1.0f/4,-1.0f/6).dot(Vector3(2.0f/3,2.0f/4,2.0f/6)));
    ASSERT_FLOAT_EQ(98*3, 3*Vector3(-3,-5,-8).dot(Vector3(-3,-5,-8)));
}

//CROSS PRODUCT
TEST(CrossProductTest, PositiveNos) { 
    ASSERT_EQ(Vector3(0,0,0), Vector3(3,5,8).cross(Vector3(3,5,8)));
    ASSERT_EQ(Vector3(0,8,-5), Vector3(0,5,8).cross(Vector3(1,5,8)));
    ASSERT_EQ(Vector3(31,-34,-8), Vector3(6,5,2).cross(Vector3(4,2,7)));
    ASSERT_EQ(Vector3(1.0f/36,0,-1.0f/18), Vector3(1.0f/3,1.0f/4,1.0f/6).cross(Vector3(2.0f/3,2.0f/6,2.0f/6)));
}

TEST(CrossProductTest, NegativeNos) { 
    ASSERT_EQ(Vector3(0,0,0), Vector3(-3,-5,-8).cross(Vector3(-3,-5,-8)));
    ASSERT_EQ(Vector3(0,8,5), Vector3(0,-5,8).cross(Vector3(1,5,-8)));
    ASSERT_EQ(Vector3(-31,-50,-32), Vector3(-6,5,-2).cross(Vector3(4,2,-7)));
    ASSERT_EQ(Vector3(5.0f/36,0,-5.0f/18), Vector3(-1.0f/3,1.0f/4,-1.0f/6).cross(Vector3(2.0f/3,2.0f/6,2.0f/6)));
}

// MAGNITUDE
TEST(Vec3MagnitudeTest, PositiveNos) { 
    ASSERT_FLOAT_EQ(3.7416575f, Vector3(1,2,3).magnitude());
    ASSERT_FLOAT_EQ(3, Vector3(1,2,2).magnitude());
    ASSERT_FLOAT_EQ(0, Vector3(0,0,0).magnitude());
    ASSERT_FLOAT_EQ(41.8569f, Vector3(28,22,22).magnitude());
}

TEST(Vec3MagnitudeTest, NegativeNos) { 
    ASSERT_FLOAT_EQ(3.7416575f, Vector3(-1,-2,-3).magnitude());
    ASSERT_FLOAT_EQ(3, Vector3(-1,2,-2).magnitude());
    ASSERT_FLOAT_EQ(41.8569f, Vector3(28,-22,-22).magnitude());
    ASSERT_FLOAT_EQ(41.8569f, Vector3(-28,-22,22).magnitude());
    ASSERT_FLOAT_EQ(41.8569f, Vector3(28,22,-22).magnitude());
    ASSERT_FLOAT_EQ(41.8569f, Vector3(28,-22,22).magnitude());
    ASSERT_FLOAT_EQ(41.8569f, Vector3(-28,22,22).magnitude());
       
}

// NORMALIZATION
TEST(Vec3NormalizationTest, PositiveNos) {
    ASSERT_EQ(Vector3(7*sqrtf(2.0f/219.0f),11.0f/sqrtf(438.0f),11.0f/sqrtf(438.0f)), Vector3(28,22,22).normalize());
    ASSERT_EQ(Vector3(sqrtf(1.0f/3.0f),sqrtf(1.0f/3.0f),sqrtf(1.0f/3.0f)), Vector3(2,2,2).normalize());
}
TEST(Vec3NormalizationTest, NegativeNos) {
    ASSERT_EQ(Vector3(-4.0f/sqrtf(21.0f),-2.0f/sqrtf(21.0f),-1.0f/sqrtf(21.0f)), Vector3(-4,-2,-1).normalize());
    ASSERT_EQ(Vector3(-3.0f/(7*sqrtf(2.0f)),-5.0f/(7*sqrtf(2.0f)),-4*sqrtf(2)/7), Vector3(-3,-5,-8).normalize());
}
TEST(Vec3NormalizationTest, ZeroNos) {
    ASSERT_EQ(Vector3(0, 0, 0), Vector3(0, 0 , 0).normalize());
}

// ROTATION 3D
TEST(Vec3RotationTest, PositiveNos) {
    ASSERT_EQ(Vector3(2,0,0),Vector3(2,0,0).rotate(90.0f,Vector3(1,0,0)));
    ASSERT_EQ(Vector3(0,0,3),Vector3(0,3,0).rotate(90.0f,Vector3(1,0,0)));
    ASSERT_EQ(Vector3(0,-4,0),Vector3(0,0,4).rotate(90.0f,Vector3(1,0,0)));

    ASSERT_EQ(Vector3(0,0,-2),Vector3(2,0,0).rotate(90.0f,Vector3(0,1,0)));
    ASSERT_EQ(Vector3(0,3,0),Vector3(0,3,0).rotate(90.0f,Vector3(0,1,0)));
    ASSERT_EQ(Vector3(4,0,0),Vector3(0,0,4).rotate(90.0f,Vector3(0,1,0)));

    ASSERT_EQ(Vector3(0,2,0),Vector3(2,0,0).rotate(90.0f,Vector3(0,0,1)));
    ASSERT_EQ(Vector3(-3,0,0),Vector3(0,3,0).rotate(90.0f,Vector3(0,0,1)));
    ASSERT_EQ(Vector3(0,0,4),Vector3(0,0,4).rotate(90.0f,Vector3(0,0,1)));
}