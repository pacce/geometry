#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>

#include "geometry-arbitrary.hpp"

namespace f32 {
    using Point = geometry::d3::Point<float>;
    RC_GTEST_PROP(Add, Associative, (const Point& xs, const Point& ys, const Point& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Point& xs, const Point& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Point& xs)) {
        Point ys(0.0f, 0.0f, 0.0f);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Point& xs)) {
        Point ys(1.0f, 1.0f, 1.0f);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Commutative, (const Point& xs)) {
        float scalar = *rc::gen::inRange(-100, 100);
        RC_ASSERT((xs * scalar) == (scalar * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Point& xs)) {
        float scalar = 1.0f;
        RC_ASSERT((xs * scalar) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Point& xs)) {
        float scalar = 0.0f;
        RC_ASSERT((xs * scalar) == Point(0.0f, 0.0f, 0.0f));
    }

    TEST(Dot, Zero) {
        Point xs(0.0f, 0.0f, 0.0f);
        EXPECT_FLOAT_EQ(0.0f, xs.dot(xs));
    }

    RC_GTEST_PROP(Dot, Commutative, (const Point& xs, const Point& ys)) {
        RC_ASSERT(xs.dot(ys) == ys.dot(xs));
    }

    RC_GTEST_PROP(Dot, Scalar, (const Point& xs, const Point& ys)) {
        float scalar = *rc::gen::inRange(-100, 100);
        RC_ASSERT(scalar * xs.dot(ys) == ys.dot(scalar * xs));
    }

    TEST(Norm, Zero) {
        EXPECT_FLOAT_EQ(0.0f, Point(0.0f, 0.0f, 0.0f).norm());
    }

    RC_GTEST_PROP(Norm, Square, ()) {
        float scalar = *rc::gen::inRange(-100, 100);
        EXPECT_FLOAT_EQ(
                  std::sqrt(3.0f) * std::abs(scalar)
                , Point(scalar, scalar, scalar).norm()
                );
    }

    RC_GTEST_PROP(Norm, Scale, (const Point& xs)) {
        float scalar = *rc::gen::inRange(0, 100);
        EXPECT_FLOAT_EQ(
                  xs.norm() * scalar
                , (scalar * xs).norm()
                );
    }
} // namespace f32

namespace f64 {
    using Point = geometry::d3::Point<double>;
    RC_GTEST_PROP(Add, Associative, (const Point& xs, const Point& ys, const Point& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Point& xs, const Point& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Point& xs)) {
        Point ys(0.0, 0.0, 0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Point& xs)) {
        Point ys(1.0, 1.0, 1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Commutative, (const Point& xs)) {
        double scalar = *rc::gen::inRange(-100, 100);
        RC_ASSERT((xs * scalar) == (scalar * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Point& xs)) {
        double scalar = 1.0;
        RC_ASSERT((xs * scalar) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Point& xs)) {
        double scalar = 0.0;
        RC_ASSERT((xs * scalar) == Point(0.0, 0.0, 0.0));
    }

    TEST(Dot, Zero) {
        Point xs(0.0, 0.0, 0.0);
        EXPECT_FLOAT_EQ(0.0, xs.dot(xs));
    }

    RC_GTEST_PROP(Dot, Commutative, (const Point& xs, const Point& ys)) {
        RC_ASSERT(xs.dot(ys) == ys.dot(xs));
    }

    RC_GTEST_PROP(Dot, Scalar, (const Point& xs, const Point& ys)) {
        double scalar = *rc::gen::inRange(-100, 100);
        RC_ASSERT(scalar * xs.dot(ys) == ys.dot(scalar * xs));
    }

    TEST(Norm, Zero) {
        EXPECT_FLOAT_EQ(0.0, Point(0.0, 0.0, 0.0).norm());
    }

    RC_GTEST_PROP(Norm, Square, ()) {
        double scalar = *rc::gen::inRange(-100, 100);
        EXPECT_FLOAT_EQ(
                  std::sqrt(3.0) * std::abs(scalar)
                , Point(scalar, scalar, scalar).norm()
                );
    }

    RC_GTEST_PROP(Norm, Scale, (const Point& xs)) {
        double scalar = *rc::gen::inRange(0, 100);
        EXPECT_FLOAT_EQ(
                  xs.norm() * scalar
                , (scalar * xs).norm()
                );
    }
} // namespace f64

namespace f128 {
    using Point = geometry::d3::Point<long double>;
    RC_GTEST_PROP(Add, Associative, (const Point& xs, const Point& ys, const Point& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Point& xs, const Point& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Point& xs)) {
        Point ys(0.0, 0.0, 0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Point& xs)) {
        Point ys(1.0, 1.0, 1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Commutative, (const Point& xs)) {
        long double scalar = *rc::gen::inRange(-100, 100);
        RC_ASSERT((xs * scalar) == (scalar * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Point& xs)) {
        long double scalar = 1.0;
        RC_ASSERT((xs * scalar) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Point& xs)) {
        long double scalar = 0.0;
        RC_ASSERT((xs * scalar) == Point(0.0, 0.0, 0.0));
    }

    TEST(Dot, Zero) {
        Point xs(0.0, 0.0, 0.0);
        EXPECT_FLOAT_EQ(0.0, xs.dot(xs));
    }

    RC_GTEST_PROP(Dot, Commutative, (const Point& xs, const Point& ys)) {
        RC_ASSERT(xs.dot(ys) == ys.dot(xs));
    }

    RC_GTEST_PROP(Dot, Scalar, (const Point& xs, const Point& ys)) {
        long double scalar = *rc::gen::inRange(-100, 100);
        RC_ASSERT(scalar * xs.dot(ys) == ys.dot(scalar * xs));
    }

    TEST(Norm, Zero) {
        EXPECT_FLOAT_EQ(0.0, Point(0.0, 0.0, 0.0).norm());
    }

    RC_GTEST_PROP(Norm, Square, ()) {
        long double scalar = *rc::gen::inRange(-100, 100);
        EXPECT_FLOAT_EQ(
                  std::sqrt(3.0) * std::abs(scalar)
                , Point(scalar, scalar, scalar).norm()
                );
    }

    RC_GTEST_PROP(Norm, Scale, (const Point& xs)) {
        long double scalar = *rc::gen::inRange(0, 100);
        EXPECT_FLOAT_EQ(
                  xs.norm() * scalar
                , (scalar * xs).norm()
                );
    }
} // namespace f128

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
