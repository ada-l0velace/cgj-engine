#include <gtest/gtest.h>
#include <CGJ/Maths.h>
using namespace cgj;
// INITIATION
TEST(Matrix4ZeroInitTest, Nos) { 
    Matrix4 m = Matrix4();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_FLOAT_EQ(m.get(i,j), 0); 
        }
    }
}

// PARAMETER INIT
TEST(Matrix4ParInitTest, Nos) { 
    Matrix4 m = Matrix4(1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16);
    int k = 0;
    int j = 0;
    for (int i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(m.get(i,j), j+k+1);
        }
        k += j;
    }
}

// MATRIX INIT
TEST(Matrix4MatInitTest, Nos) { 
    Matrix4 m = Matrix4(1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16);
    Matrix4 m2 = Matrix4(m);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(m.get(i,j), m2.get(i,j));
        }
    }
}

// Vector INIT
TEST(Matrix4VetInitTest, Nos) {
    float v[16] = {1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16}; 
    Matrix4 m = Matrix4(v);
    int k = 0;
    int j = 0;
    for (int i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(m.get(i,j), j+k+1);
        }
        k += j;
    }
}

// std::Vector INIT
TEST(Matrix4STDVetInitTest, Nos) {
    std::vector<float> v= {1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16}; 
    Matrix4 m = Matrix4(v);
    int k = 0;
    int j = 0;
    for (int i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(m.get(i,j), j+k+1);
        }
        k += j;
    }
}

// get
TEST(Matrix4GetTest, Nos) {
    Matrix4 m = Matrix4(1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            ASSERT_FLOAT_EQ(m.data[i + j * 4],  m.get(i,j));
}

// set
TEST(Matrix4SetTest, Nos) {
    Matrix4 m = Matrix4(1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16);
    int k = 0;
    int j = 0;
    for (int i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            m.set(i,j,-1*(j+k+1));
        }
        k += j;
    }
    k = 0;
    j = 0;

    for (int i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(m.data[i + j * 4], -1*(j+k+1));
        }
        k += j;
    }
}

// MUL ScalarAfter
TEST(Matrix4MulScalarAfterTest, Nos) {
    Matrix4 m = Matrix4(1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16)*3;
    ASSERT_EQ(m,Matrix4(3,6,9,12, 15,18,21,24, 27,30,33,36, 39,42,45,48));
}

// MUL ScalarFist
TEST(Matrix4MulScalarFirstTest, Nos) {
    Matrix4 m = 4*Matrix4(1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16);
    ASSERT_EQ(m,Matrix4(4,8,12,16, 20,24,28,32, 36,40,44,48, 52,56,60,64));
}

// MUL Matrix
TEST(Matrix4MulMatTest, Nos) {
    Matrix4 m = Matrix4(1,2,3,4, 
                        5,6,7,8, 
                        9,10,11,12, 
                        13,14,15,16)*
                Matrix4(1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16);
    ASSERT_EQ(m,Matrix4(90,100,110,120,
                        202,228,254,280,
                        314,356,398,440,
                        426,484,542,600
                        ));
}

// MUL VectorAfter
TEST(Matrix4MulVecAfterTest, Nos) {
    Vector4 v = Matrix4(1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16)*Vector4(1,2,3,4);
    ASSERT_EQ(Vector4(30,70,110,150),v);
}

// MUL VectorFirst
TEST(Matrix4MulVecFirstTest, Nos) {
    Vector4 v = Vector4(1,2,3,4)*Matrix4(1,2,3,4,
                                         5,6,7,8,
                                         9,10,11,12,
                                         13,14,15,16);
    ASSERT_EQ(Vector4(90,100,110,120),v);
}

// DIV ScalarAfter
TEST(Matrix4DivScalarAfterTest, Nos) {
    Matrix4 m = Matrix4(1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16)/2;
    ASSERT_EQ(m,Matrix4(1/2.0f,2/2.0f,3/2.0f,4/2.0f, 5/2.0f,6/2.0f,7/2.0f,8/2.0f, 9/2.0f,10/2.0f,11/2.0f,12/2.0f, 13/2.0f,14/2.0f,15/2.0f,16/2.0f));
}

// SUM ScalarAfter
TEST(Matrix4SumScalarAfterTest, Nos) {
    Matrix4 m = Matrix4(1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16)+2;
    ASSERT_EQ(m,Matrix4(3,4,5,6, 7,8,9,10, 11,12,13,14, 15,16,17,18));
}

// SUM matrix
TEST(Matrix4SumMatScalarAfterTest, Nos) {
    Matrix4 m = Matrix4(1,2,3,4, 
                        5,6,7,8, 
                        9,10,11,12,
                        13,14,15,16) + 
                Matrix4(1,2,3,4,
                        5,6,7,8, 
                        9,10,11,12, 
                        13,14,15,16);
    ASSERT_EQ(m,Matrix4(2,4,6,8, 10,12,14,16, 18,20,22,24, 26,28,30,32));
}

// SUB ScalarAfter
TEST(Matrix4SubScalarAfterTest, Nos) {
    Matrix4 m = Matrix4(1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16)-2;
    ASSERT_EQ(m,Matrix4(-1,0,1,2, 3,4,5,6, 7,8,9,10, 11,12,13,14));
}

// SUB matrix
TEST(Matrix4SubMatScalarAfterTest, Nos) {
    Matrix4 m = Matrix4(1,2,3,4, 
                        5,6,7,8, 
                        9,10,11,12,
                        13,14,15,16) - 
                Matrix4(1,2,3,4,
                        5,6,7,8, 
                        9,10,11,12, 
                        13,14,15,16);
    ASSERT_EQ(m,Matrix4());
}

// Different Operator
TEST(Matrix4DiffeTest, Nos) {
    Matrix4 m = Matrix4(1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16);
    ASSERT_TRUE(m != Matrix4(1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,15));
}

// STDIN
TEST(Matrix4InputTest, Nos) {
    Matrix4 m = Matrix4();
    std::streambuf* orig = std::cin.rdbuf();
    std::istringstream input("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16\n");
    std::cin.rdbuf(input.rdbuf());
    std::cin >> m;
    std::cin.rdbuf(orig);
    ASSERT_TRUE(m == Matrix4(1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16));
}