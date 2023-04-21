#ifndef GEOMETRY_TRIDIMENSIONAL_HPP__
#define GEOMETRY_TRIDIMENSIONAL_HPP__

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <fstream>
#include <type_traits>

#include "geometry-one.hpp"
#include "geometry-zero.hpp"

namespace geometry {
namespace d3 {
    template <typename Precision>
    class Point {
        static_assert(std::is_floating_point<Precision>::value);
        public:
            Point() : Point(Precision(), Precision(), Precision()) {}
            Point(Precision x, Precision y, Precision z) : value_(x, y, z) {}

            static Point<Precision>
            zero() {
                Precision z = geometry::zero<Precision>::value;

                return Point(z, z, z);
            }

            static Point<Precision>
            xaxis() {
                Precision v = geometry::one<Precision>::value;
                Precision z = geometry::zero<Precision>::value;

                return Point(v, z, z);
            }

            static Point<Precision>
            yaxis() {
                Precision v = geometry::one<Precision>::value;
                Precision z = geometry::zero<Precision>::value;

                return Point(z, v, z);
            }

            static Point<Precision>
            zaxis() {
                Precision v = geometry::one<Precision>::value;
                Precision z = geometry::zero<Precision>::value;

                return Point(z, z, v);
            }

            ~Point() {}

            const Precision& x() const { return value_(0); }
            const Precision& y() const { return value_(1); }
            const Precision& z() const { return value_(2); }

            friend std::ostream&
            operator<<(std::ostream& os, const Point<Precision>& p) {
                os << "(" << p.x() << ", " << p.y() << ", " << p.z() << ")";
                return os;
            }

            Point<Precision>
            operator-() const {
                return Point<Precision>(-value_);
            }

            Point<Precision>&
            operator+=(const Point<Precision>& rhs) {
                value_ += rhs.value_;
                return *this;
            }

            Point<Precision>&
            operator-=(const Point<Precision>& rhs) {
                value_ -= rhs.value_;
                return *this;
            }

            Point<Precision>&
            operator*=(const Precision& rhs) {
                value_ *= rhs;
                return *this;
            }

            friend Point<Precision>
            operator+(const Point<Precision>& lhs, const Point<Precision>& rhs) {
                Point<Precision> add = lhs;
                add += rhs;
                return add;
            }

            friend Point<Precision>
            operator-(const Point<Precision>& lhs, const Point<Precision>& rhs) {
                Point<Precision> sub = lhs;
                sub -= rhs;
                return sub;
            }

            friend Point<Precision>
            operator*(const Point<Precision>& p, const Precision& scalar) {
                Point<Precision> mul = p;
                mul *= scalar;
                return mul;
            }

            friend Point<Precision>
            operator*(const Precision& scalar, const Point<Precision>& p) {
                Point<Precision> mul = p;
                mul *= scalar;
                return mul;
            }

            friend std::partial_ordering
            operator<=>(const Point<Precision>& lhs, const Point<Precision>& rhs) {
                auto cmp = [](const Precision& lh, const Precision& rh) {
                    const Precision TOLERANCE = 0.01;
                    if (std::isnan(lh) || std::isnan(rh)) { return std::partial_ordering::unordered; }

                    Precision difference = lh - rh;
                    if ((lh == rh) || (std::abs(difference) <= TOLERANCE)) {
                        return std::partial_ordering::equivalent;
                    } else if (difference < 0) {
                        return std::partial_ordering::less;
                    } else {
                        return std::partial_ordering::greater;
                    }
                };

                std::partial_ordering comparison = std::partial_ordering::equivalent;
                if ((comparison = cmp(lhs.x(), rhs.x())) != std::partial_ordering::equivalent) {
                    return comparison;
                }
                if ((comparison = cmp(lhs.y(), rhs.y())) != std::partial_ordering::equivalent) {
                    return comparison;
                }
                if ((comparison = cmp(lhs.z(), rhs.z())) != std::partial_ordering::equivalent) {
                    return comparison;
                }
                return std::partial_ordering::equivalent;
            }

            friend bool operator==(const Point<Precision>& lhs, const Point<Precision>& rhs) {
                return (lhs <=> rhs) == std::partial_ordering::equivalent;
            }

            friend bool operator!=(const Point<Precision>& lhs, const Point<Precision>& rhs) {
                return (lhs <=> rhs) != std::partial_ordering::equivalent;
            }


            Precision
            dot(const Point<Precision>& other) const {
                return value_.dot(other.value_);
            }

            Point<Precision>
            cross(const Point<Precision>& other) const {
                return Point(value_.cross(other.value_));
            }

            Precision
            norm() const {
                return value_.norm();
            }

            Point<Precision>
            normalized() const {
                return Point(value_.normalized());
            }

            Point<Precision>&
            normalize() {
                this->value_.normalize();
                return *this;
            }

            Point<Precision>&
            rotate(Precision radian, const Point<Precision>& axis) {
                Eigen::AngleAxis<Precision> rotate(radian, axis.value_);
                value_ = rotate * value_;
                return *this;
            }

            Point<Precision>
            rotated(Precision radian, const Point<Precision>& axis) {
                Eigen::AngleAxis<Precision> rotate(radian, axis.value_);
                return Point<Precision>(rotate * value_);
            }
        private:
            Point(const Eigen::Vector<Precision, 3>& value) : value_(value) {}
            Eigen::Vector<Precision, 3> value_;
    };
} // namespace d3
} // namespace geometry

#endif // GEOMETRY_TRIDIMENSIONAL_HPP__
