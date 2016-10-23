#pragma once
#include <array>
#include <algorithm>

enum Area { X, Y, Z }; //for convenience

template <typename T, size_t N>
class Point
{
private:
	std::array<T, N> m_coordinates;

public:
	Point();
	template <typename ... Args>
	Point(const Args& ... args);
	Point(const std::array<T, N>& coordinates);

	template <typename ... Args>
	bool equals(const Args& ... args) const;
	bool equals(const Point<T, N>& lhs) const;
	bool equals(const std::array<T, N>& coordinates);

	template <typename ... Args>
	double distanceTo(const Args& ... args) const;
	double distanceTo(const Point<T, N>& lhs) const;
	double distanceTo(const std::array<T, N>& coordinates);

	bool operator==(const Point<T, N>& lhs) const;
	bool operator!=(const Point<T, N>& lhs) const;
	T& operator[](const size_t index);
};

typedef Point<int, 1> Point1D;
typedef Point<int, 2> Point2D;
typedef Point<int, 3> Point3D;

template<typename T, size_t N>
template <typename ... Args>
Point<T, N>::Point(const Args& ... args) :
	m_coordinates{ args... }
{
	//static_assert(sizeof...(args) == N, "Point constructor argument length must equal to dimension size (N in template parameter)!");
	// No need for above - lesser amount will result in default initialization
}

template<typename T, size_t N>
inline Point<T, N>::Point() :
	m_coordinates{}
{
}

template<typename T, size_t N>
inline Point<T, N>::Point(const std::array<T, N>& coordinates) :
	m_coordinates(coordinates)
{
}

template<typename T, size_t N>
inline bool Point<T, N>::operator!=(const Point<T, N>& lhs) const
{
	return m_coordinates != lhs.m_coordinates;
}

template<typename T, size_t N>
inline bool Point<T, N>::operator==(const Point<T, N>& lhs) const
{
	return m_coordinates == lhs.m_coordinates;
}

template<typename T, size_t N>
inline T& Point<T, N>::operator[](const size_t index)
{
	if (index >= N) throw std::out_of_range("Point out of range index!");
	return m_coordinates[index];
}

template<typename T, size_t N>
template<typename ...Args>
inline bool Point<T, N>::equals(const Args & ...args) const
{
	return *this == Point(args...);
}

template<typename T, size_t N>
template<typename ...Args>
inline double Point<T, N>::distanceTo(const Args & ...args) const
{
	return distanceTo(Point(args...));
}

template<typename T, size_t N>
inline bool Point<T, N>::equals(const Point<T, N>& lhs) const
{
	return *this == lhs;
}

template<typename T, size_t N>
inline bool Point<T, N>::equals(const std::array<T, N>& coordinates)
{
	return  *this == Point(coordinates);
}

template<typename T, size_t N>
inline double Point<T, N>::distanceTo(const Point<T, N>& lhs) const
{
	double distance = 0.f;

	for (size_t i = 0; i < N; i++)
	{
		distance += pow(m_coordinates[i] - lhs.m_coordinates[i], 2.f);
	}

	return sqrt(distance);
}

template<typename T, size_t N>
inline double Point<T, N>::distanceTo(const std::array<T, N>& coordinates)
{
	return distanceTo(Point(coordinates));
}
