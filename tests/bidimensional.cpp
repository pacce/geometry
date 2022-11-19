#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>

#include "geometry-arbitrary.hpp"

namespace f32 {
    using Point = geometry::d2::Point<float>;
    RC_GTEST_PROP(Add, Associative, (const Point& xs, const Point& ys, const Point& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Point& xs, const Point& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutralf32, (const Point& xs)) {
        Point ys(0.0f, 0.0f);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successorf32, (const Point& xs)) {
        Point ys(1.0f, 1.0f);
        RC_ASSERT((xs + ys) != xs);
    }
} // namespace f32

namespace f64 {
    using Point = geometry::d2::Point<double>;
    RC_GTEST_PROP(Add, Associative, (const Point& xs, const Point& ys, const Point& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Point& xs, const Point& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutralf32, (const Point& xs)) {
        Point ys(0.0, 0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successorf32, (const Point& xs)) {
        Point ys(1.0, 1.0);
        RC_ASSERT((xs + ys) != xs);
    }
} // namespace f64

namespace f128 {
    using Point = geometry::d2::Point<long double>;
    RC_GTEST_PROP(Add, Associative, (const Point& xs, const Point& ys, const Point& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Point& xs, const Point& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutralf32, (const Point& xs)) {
        Point ys(0.0, 0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successorf32, (const Point& xs)) {
        Point ys(1.0, 1.0);
        RC_ASSERT((xs + ys) != xs);
    }
} // namespace f128

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
