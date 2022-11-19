#ifndef GEOMETRY_BIDIMENSIONAL_HPP__
#define GEOMETRY_BIDIMENSIONAL_HPP__

#include <Eigen/Core>
#include <fstream>
#include <type_traits>

namespace geometry {
namespace d2 {
    template <typename Precision>
    class Point {
        static_assert(std::is_floating_point<Precision>::value);
        public:
            Point() : Point(Precision(), Precision()) {}
            Point(Precision x, Precision y) : value_(x, y) {}
            ~Point() {}

            const Precision& x() const { return value_(0); }
            const Precision& y() const { return value_(1); }

            friend std::ostream&
            operator<<(std::ostream& os, const Point<Precision>& p) {
                os << "(" << p.x() << ", " << p.y() << ")";
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
                return true;
            }

            friend bool
            operator!=(const Point<Precision>& lhs, const Point<Precision>& rhs) {
                return !(lhs == rhs);
            }
        private:
            Eigen::Vector<Precision, 2> value_;
    };
} // namespace d2
} // namespace geometry

#endif // GEOMETRY_BIDIMENSIONAL_HPP__
