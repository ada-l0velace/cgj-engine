#include <gtest/gtest.h>
#include <CGJ/Maths.h>
using namespace cgj;
// VECTOR CONVERTION 
TEST(Vec4Convertion, PositiveNos) { 
    //ASSERT_EQ(Vector4(Vector2(1,2)), Vector4(1,2,0,0));
    ASSERT_EQ(Vector4(Vector3(1,2,3)), Vector4(1,2,3,1));
}

// SUM VECTORS
TEST(Vec4VectorSumTest, PositiveNos) { 
    ASSERT_EQ(Vector4(6,6,6,6), Vector4(3,3,3,3)+Vector4(3,3,3,3));
    ASSERT_EQ(Vector4(0,0,0,0), Vector4(0,0,0,0)+Vector4(0,0,0,0));
}

TEST(Vec4VectorSumTest, NegativeNos) { 
    ASSERT_EQ(Vector4(0,0,0,0), Vector4(-3,-3,-3,-3)+Vector4(3,3,3,3));
    ASSERT_EQ(Vector4(0,0,0,0), Vector4(0,0,0,0)-Vector4(0,0,0,0));
}

// SUB VECTORS
TEST(Vec4VectorSubmTest, PositiveNos) { 
    ASSERT_EQ(Vector4(0,0,0,0), Vector4(3,3,3,3)-Vector4(3,3,3,3));
    ASSERT_EQ(Vector4(0,0,0,0), Vector4(0,0,0,0)-Vector4(0,0,0,0));
}

TEST(Vec4VectorSubTest, NegativeNos) { 
    ASSERT_EQ(Vector4(0,0,0,0), Vector4(-3,-3,-3,-3)-Vector4(-3,-3,-3,-3));
    ASSERT_EQ(Vector4(0,0,0,0), Vector4(0,0,0,0)-Vector4(0,0,0,0));
    ASSERT_EQ(Vector4(6,6,6,6), Vector4(3,3,3,3)-Vector4(-3,-3,-3,-3));
}

// MUL VECTORS
TEST(Vec4VectorMulTest, PositiveNos) { 
    ASSERT_EQ(Vector4(9,6,9,9), Vector4(3,2,3,3)*Vector4(3,3,3,3));
    ASSERT_EQ(Vector4(0,0,0,0), Vector4(0,0,0,0)*Vector4(0,0,0,0));
}

TEST(Vec4VectorMulTest, NegativeNos) { 
    ASSERT_EQ(Vector4(9,9,9,9), Vector4(-3,-3,-3,-3)*Vector4(-3,-3,-3,-3));
    ASSERT_EQ(Vector4(0,0,0,0), Vector4(0,0,0,0)*Vector4(0,0,0,0));
    ASSERT_EQ(Vector4(-9,-9,-9,-9), Vector4(3,3,3,3)*Vector4(-3,-3,-3,-3));
}

// DIV VECTORS NEED TO CHECK DIVISION BY ZERO LATER
TEST(Vec4VectorDivTest, PositiveNos) { 
    ASSERT_EQ(Vector4(1,2.0f/3,1,1), Vector4(3,2,3,3)/Vector4(3,3,3,3));
    ASSERT_EQ(Vector4(0,0,0,0), Vector4(0,0,0,0)/Vector4(1,1,1,1));
}

TEST(Vec4VectorDivTest, NegativeNos) { 
    ASSERT_EQ(Vector4(1,1,1,1), Vector4(-3,-3,-3,-3)/Vector4(-3,-3,-3,-3));
    ASSERT_EQ(Vector4(0,0,0,0), Vector4(0,0,0,0)/Vector4(1,1,1,1));
    ASSERT_EQ(Vector4(-1,-1,-1,-1), Vector4(3,3,3,3)/Vector4(-3,-3,-3,-3));
}


// SUM SCALAR
TEST(Vec4ScalarSumTest, PositiveNos) { 
    ASSERT_EQ(Vector4(1+3,2+3,3+3,4+3), Vector4(1,2,3,4)+3);
    ASSERT_EQ(Vector4(1+3,2+3,2+3,4+3), Vector4(1,2,2,4)+3);
    ASSERT_EQ(Vector4(3,3,3,3), Vector4(0,0,0,0)+3);
    ASSERT_EQ(Vector4(28+3,22+3,22+3,25+3), Vector4(28,22,22,25)+3);
}

TEST(Vec4ScalarSumTest, NegativeNos) { 
    ASSERT_EQ(Vector4(-1+3,-2+3,-3+3,-4+3), Vector4(-1,-2,-3,-4)+3);
    ASSERT_EQ(Vector4(-1+3,-2+3,-2+3,-3+3), Vector4(-1,-2,-2,-3)+3);
    ASSERT_EQ(Vector4(-5+3,-3+3,-7+3,-5+3), Vector4(-5,-3,-7,-5)+3);
    ASSERT_EQ(Vector4(-28+3,-22+3,-22+3,-32+3), Vector4(-28,-22,-22,-32)+3);
}

// SUB SCALAR
TEST(Vec4ScalarSubTest, PositiveNos) { 
    ASSERT_EQ(Vector4(1-3,2-3,3-3,4-3), Vector4(1,2,3,4)-3);
    ASSERT_EQ(Vector4(1-3,2-3,2-3,4-3), Vector4(1,2,2,4)-3);
    ASSERT_EQ(Vector4(-3,-3,-3,-3), Vector4(0,0,0,0)-3);
    ASSERT_EQ(Vector4(28-3,22-3,22-3,25-3), Vector4(28,22,22,25)-3);
}

TEST(Vec4ScalarSubTest, NegativeNos) { 
    ASSERT_EQ(Vector4(-1-3,-2-3,-3-3,-4-3), Vector4(-1,-2,-3,-4)-3);
    ASSERT_EQ(Vector4(-1-3,-2-3,-2-3,-4-3), Vector4(-1,-2,-2,-4)-3);
    ASSERT_EQ(Vector4(-5-3,-3-3,-7-3,-5-3), Vector4(-5,-3,-7,-5)-3);
    ASSERT_EQ(Vector4(-28-3,-22-3,-22-3,-25-3), Vector4(-28,-22,-22,-25)-3);
}

// MUL SCALAR
TEST(Vec4ScalarMulTest, PositiveNos) { 
    ASSERT_EQ(Vector4(1*3,2*3,3*3,4*3), Vector4(1,2,3,4)*3);
    ASSERT_EQ(Vector4(1*3,2*3,2*3,1*3), Vector4(1,2,2,1)*3);
    ASSERT_EQ(Vector4(0,0,0,0), Vector4(0,0,0,0)*3);
    ASSERT_EQ(Vector4(28*3,22*3,22*3,25*3), Vector4(28,22,22,25)*3);
}

TEST(Vec4ScalarMulTest, NegativeNos) { 
    ASSERT_EQ(Vector4(-1*3,-2*3,-3*3,-4*3), Vector4(-1,-2,-3,-4)*3);
    ASSERT_EQ(Vector4(-1*3,-2*3,-2*3,-2*3), Vector4(-1,-2,-2,-2)*3);
    ASSERT_EQ(Vector4(-5*3,-3*3,-7*3,-5*3), Vector4(-5,-3,-7,-5)*3);
    ASSERT_EQ(Vector4(-28*3,-22*3,-22*3,-25*3), Vector4(-28,-22,-22,-25)*3);
}

// DIV SCALAR
TEST(Vec4ScalarDivTest, PositiveNos) { 
    ASSERT_EQ(Vector4(1.0f/3,2.0f/3,3/3,1.0f/3), Vector4(1,2,3,1)/3);
    ASSERT_EQ(Vector4(1.0f/3,2.0f/3,2.0f/3,5.0f/3), Vector4(1,2,2,5)/3);
    ASSERT_EQ(Vector4(0,0,0,0), Vector4(0,0,0,0)/3);
    ASSERT_EQ(Vector4(28.0f/3,22.0f/3,22.0f/3,25.0f/3), Vector4(28,22,22,25)/3);
}

TEST(Vec4ScalarDivTest, NegativeNos) { 
    ASSERT_EQ(Vector4(-1.0f/3,-2.0f/3.0f,-3/3,-4.0f/3), Vector4(-1,-2,-3,-4)/3);
    ASSERT_EQ(Vector4(-1.0f/3,-2.0f/3.0f,-2.0f/3,-7.0f/3), Vector4(-1,-2,-2,-7)/3);
    ASSERT_EQ(Vector4(-5.0f/3,-3/3,-7.0f/3, -5.0f/3), Vector4(-5,-3,-7,-5)/3);
    ASSERT_EQ(Vector4(-28.0f/3,-22.0f/3,-22.0f/3,-25.0f/3), Vector4(-28,-22,-22,-25)/3);
}

// DOT PRODUCT
TEST(Vec4DotProductTest, PositiveNos) { 
    ASSERT_EQ(114, Vector4(3,5,8,4).dot(Vector4(3,5,8,4)));
    ASSERT_EQ(93, Vector4(0,5,8,2).dot(Vector4(1,5,8,2)));
    ASSERT_EQ(57, Vector4(6,5,2,3).dot(Vector4(4,2,7,3)));
    ASSERT_FLOAT_EQ(67.0f/144, Vector4(1.0f/3,1.0f/4,1.0f/6,1.0f/4).dot(Vector4(2.0f/3,2.0f/4,2.0f/6,1.0f/4)));
}

TEST(Vec4DotProductTest, NegativeNos) { 
    ASSERT_EQ(114, Vector4(-3,-5,-8,-4).dot(Vector4(-3,-5,-8,-4)));
    ASSERT_EQ(-93, Vector4(0,-5,8,-2).dot(Vector4(1,5,-8,2)));
    ASSERT_EQ(-10, Vector4(-6,5,-2,5).dot(Vector4(4,2,-7,-2)));
    ASSERT_FLOAT_EQ(-19.0f/36, Vector4(-1.0f/3,1.0f/4,-1.0f/6,-3.0f/4).dot(Vector4(2.0f/3,2.0f/4,2.0f/6,1.0f/2)));
}

// MAGNITUDE
TEST(Vec4MagnitudeTest, PositiveNos) { 
    ASSERT_FLOAT_EQ(sqrtf(30), Vector4(1,2,3,4).magnitude());
    ASSERT_FLOAT_EQ(3*sqrtf(2), Vector4(1,2,2,3).magnitude());
    ASSERT_FLOAT_EQ(0, Vector4(0,0,0,0).magnitude());
    ASSERT_FLOAT_EQ(sqrtf(2281), Vector4(28,22,22,23).magnitude());
}

TEST(Vec4MagnitudeTest, NegativeNos) { 
    ASSERT_FLOAT_EQ(sqrtf(30), Vector4(-1,-2,-3,-4).magnitude());
    ASSERT_FLOAT_EQ(sqrtf(13), Vector4(-1,2,-2,2).magnitude());
    ASSERT_FLOAT_EQ(2*sqrtf(582), Vector4(28,-22,-22,24).magnitude());
    ASSERT_FLOAT_EQ(sqrtf(2193), Vector4(-28,-22,22,21).magnitude());
    ASSERT_FLOAT_EQ(2*sqrtf(538), Vector4(28,22,-22,20).magnitude());
    ASSERT_FLOAT_EQ(2*sqrtf(538), Vector4(28,-22,22,20).magnitude());
    ASSERT_FLOAT_EQ(2*sqrtf(519), Vector4(-28,22,22,18).magnitude());
       
}

// NORMALIZATION
TEST(Vec4NormalizationTest, PositiveNos) {
    ASSERT_EQ(Vector4(28.0f/sqrtf(2377),22.0f/sqrtf(2377),22.0f/sqrtf(2377),25.0f/sqrtf(2377)), Vector4(28,22,22,25).normalize());
    ASSERT_EQ(Vector4(1.0f/2.0f,1.0f/2.0f,1.0f/2.0f,1.0f/2.0f), Vector4(2,2,2,2).normalize());
}
TEST(Vec4NormalizationTest, NegativeNos) {
    ASSERT_EQ(Vector4(-4.0f/sqrtf(21.0f),-2.0f/sqrtf(21.0f),-1.0f/sqrtf(21.0f),0), Vector4(-4,-2,-1,0).normalize());
    ASSERT_EQ(Vector4(-sqrtf(3.0f/34),-5.0f/sqrtf(102),-4.0f*sqrtf(2.0f/51),-sqrtf(2.0f/51)), Vector4(-3,-5,-8,-2).normalize());
}
TEST(Vec4NormalizationTest, ZeroNos) {
    ASSERT_EQ(Vector4(0,0,0,0), Vector4(0,0,0,0).normalize());
}