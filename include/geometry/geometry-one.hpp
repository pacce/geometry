#ifndef GEOMETRY_ONE_HPP__
#define GEOMETRY_ONE_HPP__

namespace geometry {
    template <typename Precision> struct one {};

    template <> struct one<float>          { static constexpr float value          = 1.0f; };
    template <> struct one<double>         { static constexpr double value         = 1.0; };
    template <> struct one<long double>    { static constexpr long double value    = 1.0; };
}

#endif // GEOMETRY_ONE_HPP__
