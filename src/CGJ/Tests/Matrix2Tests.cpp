#include <gtest/gtest.h>
#include <CGJ/Maths.h>
using namespace cgj;
// INITIATION
TEST(Matrix2ZeroInitTest, Nos) { 
    Matrix2 m = Matrix2();
    ASSERT_FLOAT_EQ(m.get(0,0), 0);
    ASSERT_FLOAT_EQ(m.get(0,1), 0);
    ASSERT_FLOAT_EQ(m.get(1,0), 0);
    ASSERT_FLOAT_EQ(m.get(1,1), 0);
}

// PARAMETER INIT
TEST(Matrix2ParInitTest, Nos) { 
    Matrix2 m = Matrix2(1,2,3,4);
    ASSERT_FLOAT_EQ(m.get(0,0), 1);
    ASSERT_FLOAT_EQ(m.get(0,1), 2);
    ASSERT_FLOAT_EQ(m.get(1,0), 3);
    ASSERT_FLOAT_EQ(m.get(1,1), 4);
}

// MATRIX INIT
TEST(Matrix2MatInitTest, Nos) { 
    Matrix2 m = Matrix2(1,2,3,4);
    Matrix2 m2 = Matrix2(m);
    
    ASSERT_FLOAT_EQ(m.get(0,0), m2.get(0,0));
    ASSERT_FLOAT_EQ(m.get(0,1), m2.get(0,1));
    ASSERT_FLOAT_EQ(m.get(1,0), m2.get(1,0));
    ASSERT_FLOAT_EQ(m.get(1,1), m2.get(1,1));
}

// Vector INIT
TEST(Matrix2VetInitTest, Nos) {
    float v[4] = {1,2,3,4}; 
    Matrix2 m = Matrix2(v);
    ASSERT_FLOAT_EQ(m.get(0,0), 1);
    ASSERT_FLOAT_EQ(m.get(0,1), 2);
    ASSERT_FLOAT_EQ(m.get(1,0), 3);
    ASSERT_FLOAT_EQ(m.get(1,1), 4);
}

// std::Vector INIT
TEST(Matrix2STDVetInitTest, Nos) {
    std::vector<float> v= {1,2,3,4}; 
    Matrix2 m = Matrix2(v);
    ASSERT_FLOAT_EQ(m.get(0,0), 1);
    ASSERT_FLOAT_EQ(m.get(0,1), 2);
    ASSERT_FLOAT_EQ(m.get(1,0), 3);
    ASSERT_FLOAT_EQ(m.get(1,1), 4);
}

// get
TEST(Matrix2GetTest, Nos) {
    Matrix2 m = Matrix2(1,2,3,4);
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            ASSERT_FLOAT_EQ(m.data[i + j * 2],  m.get(i,j));
}

// set
TEST(Matrix2SetTest, Nos) {
    Matrix2 m = Matrix2(1,2,3,4);
    m.set(0,0,-1);
    m.set(0,1,-2);
    m.set(1,0,-3);
    m.set(1,1,-4);
    
    ASSERT_FLOAT_EQ(m.data[0], -1);
    ASSERT_FLOAT_EQ(m.data[2], -2);
    ASSERT_FLOAT_EQ(m.data[1], -3);
    ASSERT_FLOAT_EQ(m.data[3], -4);
}

// MUL ScalarAfter
TEST(Matrix2MulScalarAfterTest, Nos) {
    Matrix2 m = Matrix2(1,2,3,4)*3;
    
    ASSERT_FLOAT_EQ(m.data[0], 3);
    ASSERT_FLOAT_EQ(m.data[2], 6);
    ASSERT_FLOAT_EQ(m.data[1], 9);
    ASSERT_FLOAT_EQ(m.data[3], 12);
}

// MUL ScalarFist
TEST(Matrix2MulScalarFirstTest, Nos) {
    Matrix2 m = 3*Matrix2(1,2,3,4);
    
    ASSERT_FLOAT_EQ(m.data[0], 3);
    ASSERT_FLOAT_EQ(m.data[2], 6);
    ASSERT_FLOAT_EQ(m.data[1], 9);
    ASSERT_FLOAT_EQ(m.data[3], 12);
}

// MUL Matrix
TEST(Matrix2MulMatTest, IntegerNos) {
    Matrix2 m = Matrix2(1,2,3,4)*Matrix2(1,2,3,4);
    
    ASSERT_FLOAT_EQ(m.data[0], 7);
    ASSERT_FLOAT_EQ(m.data[2], 10);
    ASSERT_FLOAT_EQ(m.data[1], 15);
    ASSERT_FLOAT_EQ(m.data[3], 22);
}

// MUL Matrix
TEST(Matrix2MulMatTest, FloatNos) {
    Matrix2 m = Matrix2(1.1,1.1,1.1,2.1)*Matrix2(1.1,1.1,1.1,2.1);
    
    ASSERT_FLOAT_EQ(m.data[0], 2.42);
    ASSERT_FLOAT_EQ(m.data[2], 3.52);
    ASSERT_FLOAT_EQ(m.data[1], 3.52);
    ASSERT_FLOAT_EQ(m.data[3], 5.62);
}

// MUL VectorAfter
TEST(Matrix2MulVecAfterTest, Nos) {
    Vector2 v = Matrix2(1,2,3,4)*Vector2(1,2);
    ASSERT_EQ(Vector2(5,11),v);
}

// MUL VectorFirst
TEST(Matrix2MulVecFirstTest, Nos) {
    Vector2 v = Vector2(1,2)*Matrix2(1,2,3,4);
    ASSERT_EQ(Vector2(7,10),v);
}

// DIV ScalarAfter
TEST(Matrix2DivScalarAfterTest, Nos) {
    Matrix2 m = Matrix2(2,4,6,8)/2;
    
    ASSERT_FLOAT_EQ(m.data[0], 1);
    ASSERT_FLOAT_EQ(m.data[2], 2);
    ASSERT_FLOAT_EQ(m.data[1], 3);
    ASSERT_FLOAT_EQ(m.data[3], 4);
}

// DETERMINANT
TEST(Matrix2DetTest, Nos) {
    Matrix2 m0 = Matrix2(2,4,6,8);
    Matrix2 m1 = Matrix2(1,2,3,4);
    Matrix2 m2 = Matrix2(2,4,-2,3);
    
    ASSERT_FLOAT_EQ(m0.determinant(), -8);
    ASSERT_FLOAT_EQ(m1.determinant(), -2);
    ASSERT_FLOAT_EQ(m2.determinant(), 14);
}

// TRANSPOSE
TEST(Matrix2TranspTest, Nos) {
    Matrix2 m0 = Matrix2(2,4,6,8);
    
    ASSERT_EQ(m0.transpose(), Matrix2(2,6,4,8));
    ASSERT_TRUE(m0.transpose() == Matrix2(2,6,4,8));
}

// COFACTORS
TEST(Matrix2CofTest, Nos) {
    Matrix2 m0 = Matrix2(1,2,3,4);
    ASSERT_EQ(m0.cofactors(), Matrix2(4,-3,-2,1));
}

// ADJACENCY
TEST(Matrix2AdjTest, Nos) {
    Matrix2 m0 = Matrix2(1,2,3,4);
    ASSERT_EQ(m0.adjugate(), Matrix2(4,-2,-3,1));
}

// INVERT
TEST(Matrix2InvTest, Nos) {
    Matrix2 m0 = Matrix2(2,4,6,8);
    ASSERT_EQ(m0.inverse(), Matrix2(-4,2,3,-1)*(1.0f/4));
}

// STDIN
TEST(Matrix2InputTest, Nos) {
    Matrix2 m = Matrix2();
    std::streambuf* orig = std::cin.rdbuf();
    std::istringstream input("1.5 2.2 3.3 4\n");
    std::cin.rdbuf(input.rdbuf());
    std::cin >> m;
    std::cin.rdbuf(orig);
    ASSERT_TRUE(m == Matrix2(1.5f,2.2f,3.3f,4));
}





