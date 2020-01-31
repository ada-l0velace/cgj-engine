#include <gtest/gtest.h>
#include <CGJ/Maths.h>
using namespace cgj;

// ANGLE
TEST(Vec2AngleTest, PositiveNos) {
    ASSERT_FLOAT_EQ(acos(8.0f/sqrtf(65)),Vector2(1,2).angle(Vector2(2,3)));
}

// SUM VECTORS
TEST(Vec2VectorSumTest, PositiveNos) { 
    ASSERT_EQ(Vector2(6,6), Vector2(3,3)+Vector2(3,3));
    ASSERT_EQ(Vector2(0,0), Vector2(0,0)+Vector2(0,0));
}

TEST(Vec2VectorSumTest, NegativeNos) { 
    ASSERT_EQ(Vector2(0,0), Vector2(-3,-3)+Vector2(3,3));
    ASSERT_EQ(Vector2(0,0), Vector2(0,0)-Vector2(0,0));
}

// SUB VECTORS
TEST(Vec2VectorSubmTest, PositiveNos) { 
    ASSERT_EQ(Vector2(0,0), Vector2(3,3)-Vector2(3,3));
    ASSERT_EQ(Vector2(0,0), Vector2(0,0)-Vector2(0,0));
}

TEST(Vec2VectorSubTest, NegativeNos) { 
    ASSERT_EQ(Vector2(0,0), Vector2(-3,-3)-Vector2(-3,-3));
    ASSERT_EQ(Vector2(0,0), Vector2(0,0)-Vector2(0,0));
    ASSERT_EQ(Vector2(6,6), Vector2(3,3)-Vector2(-3,-3));
}

// MUL VECTORS
TEST(Vec2VectorMulTest, PositiveNos) { 
    ASSERT_EQ(Vector2(9,6), Vector2(3,2)*Vector2(3,3));
    ASSERT_EQ(Vector2(0,0), Vector2(0,0)*Vector2(0,0));
}

TEST(Vec2VectorMulTest, NegativeNos) { 
    ASSERT_EQ(Vector2(9,9), Vector2(-3,-3)*Vector2(-3,-3));
    ASSERT_EQ(Vector2(0,0), Vector2(0,0)*Vector2(0,0));
    ASSERT_EQ(Vector2(-9,-9), Vector2(3,3)*Vector2(-3,-3));
}

// DIV VECTORS NEED TO CHECK DIVISION BY ZERO LATER
TEST(Vec2VectorDivTest, PositiveNos) { 
    ASSERT_EQ(Vector2(1,2.0f/3), Vector2(3,2)/Vector2(3,3));
    ASSERT_EQ(Vector2(0,0), Vector2(0,0)/Vector2(1,1));
}

TEST(Vec2VectorDivTest, NegativeNos) { 
    ASSERT_EQ(Vector2(1,1), Vector2(-3,-3)/Vector2(-3,-3));
    ASSERT_EQ(Vector2(0,0), Vector2(0,0)/Vector2(1,1));
    ASSERT_EQ(Vector2(-1,-1), Vector2(3,3)/Vector2(-3,-3));
}

// SUM SCALAR
TEST(Vec2ScalarSumTest, PositiveNos) { 
    ASSERT_EQ(Vector2(1+3,2+3), Vector2(1,2)+3);
    ASSERT_EQ(Vector2(1+3,2+3), Vector2(1,2)+3);
    ASSERT_EQ(Vector2(3,3), Vector2(0,0)+3);
    ASSERT_EQ(Vector2(28+3,22+3), Vector2(28,22)+3);
}

TEST(Vec2ScalarSumTest, NegativeNos) { 
    ASSERT_EQ(Vector2(-1+3,-2+3), Vector2(-1,-2)+3);
    ASSERT_EQ(Vector2(-1+3,-2+3), Vector2(-1,-2)+3);
    ASSERT_EQ(Vector2(-5+3,-3+3), Vector2(-5,-3)+3);
    ASSERT_EQ(Vector2(-28+3,-22+3), Vector2(-28,-22)+3);
}

// SUB SCALAR
TEST(Vec2ScalarSubTest, PositiveNos) { 
    ASSERT_EQ(Vector2(1-3,2-3), Vector2(1,2)-3);
    ASSERT_EQ(Vector2(1-3,2-3), Vector2(1,2)-3);
    ASSERT_EQ(Vector2(-3,-3), Vector2(0,0)-3);
    ASSERT_EQ(Vector2(28-3,22-3), Vector2(28,22)-3);
}

TEST(Vec2ScalarSubTest, NegativeNos) { 
    ASSERT_EQ(Vector2(-1-3,-2-3), Vector2(-1,-2)-3);
    ASSERT_EQ(Vector2(-1-3,-2-3), Vector2(-1,-2)-3);
    ASSERT_EQ(Vector2(-5-3,-3-3), Vector2(-5,-3)-3);
    ASSERT_EQ(Vector2(-28-3,-22-3), Vector2(-28,-22)-3);
}

// MUL SCALAR
TEST(Vec2ScalarMulTest, PositiveNos) { 
    ASSERT_EQ(Vector2(1*3,2*3), Vector2(1,2)*3);
    ASSERT_EQ(Vector2(1*3,2*3), Vector2(1,2)*3);
    ASSERT_EQ(Vector2(0,0), Vector2(0,0)*3);
    ASSERT_EQ(Vector2(28*3,22*3), Vector2(28,22)*3);
}

TEST(Vec2ScalarMulTest, NegativeNos) { 
    ASSERT_EQ(Vector2(-1*3,-2*3), Vector2(-1,-2)*3);
    ASSERT_EQ(Vector2(-1*3,-2*3), Vector2(-1,-2)*3);
    ASSERT_EQ(Vector2(-5*3,-3*3), Vector2(-5,-3)*3);
    ASSERT_EQ(Vector2(-28*3,-22*3), Vector2(-28,-22)*3);
}

// DIV SCALAR
TEST(Vec2ScalarDivTest, PositiveNos) { 
    ASSERT_EQ(Vector2(1.0f/3,2.0f/3), Vector2(1,2)/3);
    ASSERT_EQ(Vector2(1.0f/3,2.0f/3), Vector2(1,2)/3);
    ASSERT_EQ(Vector2(0,0), Vector2(0,0)/3);
    ASSERT_EQ(Vector2(28.0f/3,22.0f/3), Vector2(28,22)/3);
}

TEST(Vec2ScalarDivTest, NegativeNos) { 
    ASSERT_EQ(Vector2(-1.0f/3,-2.0f/3.0f), Vector2(-1,-2)/3);
    ASSERT_EQ(Vector2(-1.0f/3,-2.0f/3.0f), Vector2(-1,-2)/3);
    ASSERT_EQ(Vector2(-5.0f/3,-3/3), Vector2(-5,-3)/3);
    ASSERT_EQ(Vector2(-28.0f/3,-22.0f/3), Vector2(-28,-22)/3);
}

// DOT PRODUCT
TEST(Vec2DotProductTest, PositiveNos) { 
    ASSERT_FLOAT_EQ(34, Vector2(3,5).dot(Vector2(3,5)));
    ASSERT_FLOAT_EQ(25, Vector2(0,5).dot(Vector2(1,5)));
    ASSERT_FLOAT_EQ(34, Vector2(6,5).dot(Vector2(4,2)));
    ASSERT_FLOAT_EQ(25.0f/72, Vector2(1.0f/3,1.0f/4).dot(Vector2(2.0f/3,2.0f/4)));
}

TEST(Vec2DotProductTest, NegativeNos) { 
    ASSERT_FLOAT_EQ(34, Vector2(-3,-5).dot(Vector2(-3,-5)));
    ASSERT_FLOAT_EQ(-25, Vector2(0,-5).dot(Vector2(1,5)));
    ASSERT_FLOAT_EQ(-14, Vector2(-6,5).dot(Vector2(4,2)));
    ASSERT_FLOAT_EQ(-7.0f/72, Vector2(-1.0f/3,1.0f/4).dot(Vector2(2.0f/3,2.0f/4)));
}

// MAGNITUDE
TEST(Vec2MagnitudeTest, PositiveNos) { 
    ASSERT_FLOAT_EQ(sqrtf(5), Vector2(1,2).magnitude());
    ASSERT_FLOAT_EQ(0, Vector2(0,0).magnitude());
    ASSERT_FLOAT_EQ(2*sqrtf(317), Vector2(28,22).magnitude());
}

TEST(Vec2MagnitudeTest, NegativeNos) { 
    ASSERT_FLOAT_EQ(sqrtf(5), Vector2(-1,-2).magnitude());
    ASSERT_FLOAT_EQ(2*sqrtf(317), Vector2(28,-22).magnitude());
    ASSERT_FLOAT_EQ(2*sqrtf(317), Vector2(-28,-22).magnitude());
    ASSERT_FLOAT_EQ(2*sqrtf(317), Vector2(28,22).magnitude());
    ASSERT_FLOAT_EQ(2*sqrtf(317), Vector2(28,-22).magnitude());
    ASSERT_FLOAT_EQ(2*sqrtf(317), Vector2(-28,22).magnitude());
       
}

// NORMALIZATION
TEST(Vec2NormalizationTest, PositiveNos) {
    ASSERT_EQ(Vector2(14.0f/sqrtf(317.0f),11.0f/sqrt(317.0f)), Vector2(28,22).normalize());
    ASSERT_EQ(Vector2(1.0f/sqrtf(2.0f),1.0f/sqrt(2.0f)), Vector2(2,2).normalize());
}
TEST(Vec2NormalizationTest, NegativeNos) {
    ASSERT_EQ(Vector2(-2.0f/sqrt(5.0f),-1.0f/sqrt(5.0f)), Vector2(-4,-2).normalize());
    ASSERT_EQ(Vector2(-3.0f/sqrt(34.0f),-5.0f/(sqrt(34.0f))), Vector2(-3,-5).normalize());
}
TEST(Vec2NormalizationTest, ZeroNos) {
    ASSERT_EQ(Vector2(0, 0), Vector2(0, 0).normalize());
}

// 2D ROTATION
TEST(Vec2RotationTest, PositiveNos) {
    ASSERT_EQ(Vector2(0,2),Vector2(2,0).rotate(90.0f));
    ASSERT_EQ(Vector2(-3,0),Vector2(0,3).rotate(90.0f));
}