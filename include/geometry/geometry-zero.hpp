#ifndef GEOMETRY_ZERO_HPP__
#define GEOMETRY_ZERO_HPP__

namespace geometry {
    template <typename Precision> struct zero {};

    template <> struct zero<float>          { static constexpr float value          = 0.0f; };
    template <> struct zero<double>         { static constexpr double value         = 0.0; };
    template <> struct zero<long double>    { static constexpr long double value    = 0.0; };
}

#endif // GEOMETRY_ZERO_HPP__
