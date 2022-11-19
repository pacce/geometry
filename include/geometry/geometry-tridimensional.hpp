#ifndef GEOMETRY_TRIDIMENSIONAL_HPP__
#define GEOMETRY_TRIDIMENSIONAL_HPP__

#include <Eigen/Core>
#include <fstream>
#include <type_traits>

namespace geometry {
namespace d3 {
    template <typename Precision>
    class Point {
        static_assert(std::is_floating_point<Precision>::value);
        public:
            Point() : Point(Precision(), Precision(), Precision()) {}
            Point(Precision x, Precision y, Precision z) : value_(x, y, z) {}
            ~Point() {}

            const Precision& x() const { return value_(0); }
            const Precision& y() const { return value_(1); }
            const Precision& z() const { return value_(2); }

            friend std::ostream&
            operator<<(std::ostream& os, const Point<Precision>& p) {
                os << "(" << p.x() << ", " << p.y() << ", " << p.z() << ")";
                return os;
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

            friend bool
            operator==(const Point<Precision>& lhs, const Point<Precision>& rhs) {
                const Precision TOL = 0.01;
                if (std::abs(lhs.x() - rhs.x()) > TOL) { return false; }
                if (std::abs(lhs.y() - rhs.y()) > TOL) { return false; }
                if (std::abs(lhs.z() - rhs.z()) > TOL) { return false; }
                return true;
            }

            friend bool
            operator!=(const Point<Precision>& lhs, const Point<Precision>& rhs) {
                return !(lhs == rhs);
            }

            Precision
            dot(const Point<Precision>& other) const {
                return value_.dot(other.value_);
            }

            Precision
            norm() const {
                return value_.norm();
            }
        private:
            Eigen::Vector<Precision, 3> value_;
    };
} // namespace d3
} // namespace geometry

#endif // GEOMETRY_TRIDIMENSIONAL_HPP__
