#include <gtest/gtest.h>
#include <CGJ/Maths.h>
using namespace cgj;
// HOMOGENEOUS ROTATION
TEST(MatrixFactoryRotationTest, Nos) {
	ASSERT_EQ(Vector4(0,0,-1,1), MatrixFactory::rotate(90, Vector3(0,1,0))* Vector4(1,0,0,1));
	ASSERT_EQ(Vector3(-1, 0, 1), MatrixFactory::rotate(180)* Vector3(1,0,1));
}

// HOMOGENEOUS TRANSLATION
TEST(MatrixFactoryTranslationTest, Nos) {
	ASSERT_EQ(Vector4(4,4,6,1), MatrixFactory::translate(Vector3(3,1,2))*Vector4(1,3,4,1));
	ASSERT_EQ(Vector3(4,4,1), MatrixFactory::translate(Vector2(3,1))*Vector3(1,3,1));
}

// HOMOGENEOUS SCALE
TEST(MatrixFactoryScaleRotationTest, Nos) {
	ASSERT_EQ(Vector4(1,4,1,1), MatrixFactory::scale(Vector3(1,2,1))* Vector4(1,2,1,1));
	ASSERT_EQ(Vector3(1,4,1), MatrixFactory::scale(Vector2(1,2))* Vector3(1,2,1));
}
