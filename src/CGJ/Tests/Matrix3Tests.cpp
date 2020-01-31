#include <gtest/gtest.h>
#include <CGJ/Maths.h>
using namespace cgj;
// INITIATION
TEST(Matrix3ZeroInitTest, Nos) { 
    Matrix3 m = Matrix3();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_FLOAT_EQ(m.get(i,j), 0); 
        }
    }
}

// PARAMETER INIT
TEST(Matrix3ParInitTest, Nos) { 
    Matrix3 m = Matrix3(1,2,3,4,5,6,7,8,9);
    int k = 0;
    int j = 0;
    for (int i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            ASSERT_FLOAT_EQ(m.get(i,j), j+k+1);
        }
        k += j;
    }
}

// MATRIX INIT
TEST(Matrix3MatInitTest, Nos) { 
    Matrix3 m = Matrix3(1,2,3,4,5,6,7,8,9);
    Matrix3 m2 = Matrix3(m);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_FLOAT_EQ(m.get(i,j), m2.get(i,j));
        }
    }
}

// Vector INIT
TEST(Matrix3VetInitTest, Nos) {
    float v[9] = {1,2,3,4,5,6,7,8,9}; 
    Matrix3 m = Matrix3(v);
    int k = 0;
    int j = 0;
    for (int i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            ASSERT_FLOAT_EQ(m.get(i,j), j+k+1);
        }
        k += j;
    }
}

// std::Vector INIT
TEST(Matrix3STDVetInitTest, Nos) {
    std::vector<float> v= {1,2,3,4,5,6,7,8,9}; 
    Matrix3 m = Matrix3(v);
    int k = 0;
    int j = 0;
    for (int i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            ASSERT_FLOAT_EQ(m.get(i,j), j+k+1);
        }
        k += j;
    }
}

// get
TEST(Matrix3GetTest, Nos) {
    Matrix3 m = Matrix3(1,2,3,4,5,6,7,8,9);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            ASSERT_FLOAT_EQ(m.data[i + j * 3],  m.get(i,j));
}

// set
TEST(Matrix3SetTest, Nos) {
    Matrix3 m = Matrix3(1,2,3,4,5,6,7,8,9);
    int k = 0;
    int j = 0;
    for (int i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            m.set(i,j,-1*(j+k+1));
        }
        k += j;
    }
    k = 0;
    j = 0;

    for (int i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            ASSERT_FLOAT_EQ(m.data[i + j * 3], -1*(j+k+1));
        }
        k += j;
    }
}

// MUL ScalarAfter
TEST(Matrix3MulScalarAfterTest, Nos) {
    Matrix3 m = Matrix3(1,2,3,4,5,6,7,8,9)*3;
    ASSERT_EQ(m,Matrix3(3,6,9,12,15,18,21,24,27));
}

// MUL ScalarFist
TEST(Matrix3MulScalarFirstTest, Nos) {
    Matrix3 m = 3*Matrix3(1,2,3,4,5,6,7,8,9);
    ASSERT_EQ(m,Matrix3(3,6,9,12,15,18,21,24,27));
}

// MUL Matrix
TEST(Matrix3MulMatTest, IntegerNos) {
    Matrix3 m = Matrix3(1,2,3,4,5,6,7,8,9)*Matrix3(1,2,3,4,5,6,7,8,9);
    ASSERT_EQ(m,Matrix3(30,36,42,66,81,96,102,126,150));
}

// MUL Matrix
TEST(Matrix3MulMatTest, FloatNos) {
    Matrix3 m = Matrix3(1.1,2.1,3.1,4.1,5.1,6.1,7.1,8.1,9.1)*Matrix3(1.1,2.1,3.1,4.1,5.1,6.1,7.1,8.1,9.1);
    ASSERT_EQ(m,Matrix3(31.83,38.13,44.43,68.73,84.03,99.33,105.63,129.93,154.23));
}

// MUL VectorAfter
TEST(Matrix3MulVecAfterTest, Nos) {
    Vector3 v = Matrix3(1,2,3,4,5,6,7,8,9)*Vector3(1,2,3);
    ASSERT_EQ(Vector3(14,32,50),v);
}

// MUL VectorFirst
TEST(Matrix3MulVecFirstTest, Nos) {
    Vector3 v = Vector3(1,2,3)*Matrix3(1,2,3,4,5,6,7,8,9);
    ASSERT_EQ(Vector3(30,36,42),v);
}

// DIV ScalarAfter
TEST(Matrix3DivScalarAfterTest, Nos) {
    Matrix3 m = Matrix3(2,4,6,8,16,32,64,40,20)/2;
    ASSERT_EQ(m,Matrix3(1,2,3,4,8,16,32,20,10));
}

// SUM ScalarAfter
TEST(Matrix3SumScalarAfterTest, Nos) {
    Matrix3 m = Matrix3(2,4,6,8,16,32,64,40,20)+2;
    ASSERT_EQ(m,Matrix3(4,6,8,10,18,34,66,42,22));
}

// SUM matrix
TEST(Matrix3SumMatScalarAfterTest, Nos) {
    Matrix3 m = Matrix3(2,4,6,8,16,32,64,40,20)+Matrix3(2,4,6,8,16,32,64,40,20);
    ASSERT_EQ(m,Matrix3(4,8,12,16,32,64,128,80,40));
}

// SUB ScalarAfter
TEST(Matrix3SubScalarAfterTest, Nos) {
    Matrix3 m = Matrix3(2,4,6,8,16,32,64,40,20)-2;
    ASSERT_EQ(m,Matrix3(0,2,4,6,14,30,62,38,18));
}

// SUB matrix
TEST(Matrix3SubMatScalarAfterTest, Nos) {
    Matrix3 m = Matrix3(2,4,6,8,16,32,64,40,20)-Matrix3(2,4,6,8,16,32,64,40,20);
    ASSERT_EQ(m,Matrix3());
}

// Different Operator
TEST(Matrix3DiffeTest, Nos) {
    Matrix3 m = Matrix3(2,4,6,8,16,32,64,40,20);
    ASSERT_TRUE(m != Matrix3(2,4,6,8,16,32,64,40,21));
}

// DETERMINANT
TEST(Matrix3DetTest, Nos) {
    Matrix3 m0 = Matrix3(2,4,6,8,4,5,6,4,3);
    Matrix3 m1 = Matrix3(1,2,3,4,5,6,7,8,9);
    Matrix3 m2 = Matrix3(2,4,-2,3,3,-2,3,4,2);
    
    ASSERT_FLOAT_EQ(m0.determinant(), 56);
    ASSERT_FLOAT_EQ(m1.determinant(), 0);
    ASSERT_FLOAT_EQ(m2.determinant(), -26);
}

// ADJACENCY
TEST(Matrix3AdjTest, Nos) {
    Matrix3 m0 = Matrix3(1,2,3,4,5,6,7,8,9);
    ASSERT_EQ(m0.adjugate(), Matrix3(-3,6,-3,6,-12,6,-3,6,-3));
}

// COFACTORS
TEST(Matrix3CofTest, Nos) {
    Matrix3 m0 = Matrix3(5,2,3,4,3,2,2,1,3);
    ASSERT_EQ(m0.cofactors(), Matrix3(7,-8,-2,-3,9,-1,-5,2,7));
}

// INVERT
TEST(Matrix3InvTest, Nos) {
    Matrix3 m0 = Matrix3(5,2,3,4,3,2,2,1,3);
    ASSERT_EQ(m0.inverse(), 1/13.0f*Matrix3(7,-3,-5,-8,9,2,-2,-1,7));
}

// STDIN
TEST(Matrix3InputTest, Nos) {
    Matrix3 m = Matrix3();
    std::streambuf* orig = std::cin.rdbuf();
    std::istringstream input("1 2 3 4 5 6 7 8 9\n");
    std::cin.rdbuf(input.rdbuf());
    std::cin >> m;
    std::cin.rdbuf(orig);
    ASSERT_TRUE(m == Matrix3(1,2,3,4,5,6,7,8,9));
}