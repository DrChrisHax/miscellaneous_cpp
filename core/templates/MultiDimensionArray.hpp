#ifndef TEMPLATES_MULTI_DIMENSION_ARRAY_H_
#define TEMPLATES_MULTI_DIMENSION_ARRAY_H_

#include <array>

// 2-D Array
template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

template <typename T, std::size_t Row, std::size_t Col>
constexpr std::size_t rowLength(const Array2d<T, Row, Col>&) {
    return Row;
}

template <typename T, std::size_t Row, std::size_t Col>
constexpr std::size_t coLength(const Array2d<T, Row, Col>&) {
    return Col;
}

// 3-D Array
template <typename T, std::size_t Row, std::size_t Col, std::size_t Depth> 
using Array3d = std::array<std::array<std::array<T, Depth>, Col>, Row>;

template <typename T, std::size_t Row, std::size_t Col, std::size_t Depth>
constexpr std::size_t rowLength(const Array3d<T, Row, Col, Depth>&) {
    return Row;
}

template <typename T, std::size_t Row, std::size_t Col, std::size_t Depth>
constexpr std::size_t colLength(const Array3d<T, Row, Col, Depth>&) {
    return Col;
}

template <typename T, std::size_t Row, std::size_t Col, std::size_t Depth>
constexpr std::size_t depthLength(const Array3d<T, Row, Col, Depth>&) {
    return Depth;
}



#endif // TEMPLATES_MULTI_DIMENSION_ARRAY_H_