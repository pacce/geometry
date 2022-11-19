#ifndef GEOMETRY_ARBITRARY_HPP__
#define GEOMETRY_ARBITRARY_HPP__

#include <rapidcheck/gtest.h>
#include <geometry/geometry.hpp>

namespace rc {
    template<typename Precision>
    struct Arbitrary<geometry::d2::Point<Precision>> {
        static Gen<geometry::d2::Point<Precision>>
        arbitrary() {
            return gen::construct<geometry::d2::Point<Precision>>(
                      gen::cast<Precision>(gen::inRange(-100, 100))
                    , gen::cast<Precision>(gen::inRange(-100, 100))
                    );
        }
    };
}

#endif // GEOMETRY_ARBITRARY_HPP__
