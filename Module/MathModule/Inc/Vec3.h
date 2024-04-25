#pragma once

#include <cstdint>

#include "MathModule.h"


/**
 * @brief 원소의 데이터 타입이 정수인 3차원 벡터입니다.
 */
struct Vec3i
{
	/**
	 * @brief 3차원 벡터의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Vec3i() noexcept : x(0), y(0), z(0) {}


	/**
	 * @brief 3차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 */
	Vec3i(int32_t&& xx, int32_t&& yy, int32_t&& zz) noexcept : x(xx), y(yy), z(zz) {}


	/**
	 * @brief 3차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 */
	Vec3i(const int32_t& xx, const int32_t& yy, const int32_t& zz) noexcept : x(xx), y(yy), z(zz) {}


	/**
	 * @brief 3차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Vec3i(int32_t&& e) noexcept : x(e), y(e), z(e) {}


	/**
	 * @brief 3차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Vec3i(const int32_t& e) noexcept : x(e), y(e), z(e) {}


	/**
	 * @brief 3차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vec3i(Vec3i&& v) noexcept : x(v.x), y(v.y), z(v.z) {}


	/**
	 * @brief 3차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vec3i(const Vec3i& v) noexcept : x(v.x), y(v.y), z(v.z) {}


	/**
	 * @brief 3차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vec3i& operator=(Vec3i&& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}


	/**
	 * @brief 3차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vec3i& operator=(const Vec3i& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}


	/**
	 * @brief 3차원 벡터의 원소에 -부호를 취합니다.
	 *
	 * @return 3차원 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vec3i operator-() const
	{
		return Vec3i(-x, -y, -z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vec3i operator+(Vec3i&& v) const
	{
		return Vec3i(x + v.x, y + v.y, z + v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vec3i operator+(const Vec3i& v) const
	{
		return Vec3i(x + v.x, y + v.y, z + v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vec3i operator-(Vec3i&& v) const
	{
		return Vec3i(x - v.x, y - v.y, z - v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vec3i operator-(const Vec3i& v) const
	{
		return Vec3i(x - v.x, y - v.y, z - v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vec3i operator*(Vec3i&& v) const
	{
		return Vec3i(x * v.x, y * v.y, z * v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vec3i operator*(const Vec3i& v) const
	{
		return Vec3i(x * v.x, y * v.y, z * v.z);
	}

	
	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vec3i& operator+=(Vec3i&& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vec3i& operator+=(const Vec3i& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vec3i& operator-=(Vec3i&& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vec3i& operator-=(const Vec3i& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}


	/**
	 * @brief 두 3차원 벡터가 동일한지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(Vec3i&& v) const
	{
		return (x == v.x) && (y == v.y) && (z == v.z);
	}


	/**
	 * @brief 두 3차원 벡터가 동일한지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(const Vec3i& v) const
	{
		return (x == v.x) && (y == v.y) && (z == v.z);
	}


	/**
	 * @brief 두 3차원 벡터가 동일하지 않은지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하지 않다면 true, 그렇다면 false를 반환합니다.
	 */
	bool operator!=(Vec3i&& v) const
	{
		return (x != v.x) || (y != v.y) || (z != v.z);
	}


	/**
	 * @brief 두 3차원 벡터가 동일하지 않은지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하지 않다면 true, 그렇다면 false를 반환합니다.
	 */
	bool operator!=(const Vec3i& v) const
	{
		return (x != v.x) || (y != v.y) || (z != v.z);
	}


	/**
	 * @brief 3차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 3차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	const int32_t* GetPtr() const { return &data[0]; }


	/**
	 * @brief 3차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 3차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	int32_t* GetPtr() { return &data[0]; }


	/**
	 * @brief 3차원 백터의 내적 연산을 수행합니다.
	 *
	 * @param lhs 백터의 내적 연산을 수행할 좌측 피연산자입니다.
	 * @param rhs 백터의 내적 연산을 수행할 우측 피연산자입니다.
	 *
	 * @return 내적 연산 결과를 반환합니다.
	 */
	static inline int32_t Dot(const Vec3i& lhs, const Vec3i& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}


	/**
	 * @brief 3차원 벡터의 외적 연산을 수행합니다.
	 *
	 * @param lhs 백터의 외적 연산을 수행할 좌측 피연산자입니다.
	 * @param rhs 백터의 외적 연산을 수행할 우측 피연산자입니다.
	 *
	 * @return 외적 연산 결과를 반환합니다.
	 */
	static inline Vec3i Cross(const Vec3i& lhs, const Vec3i& rhs)
	{
		return Vec3i(
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x
		);
	}


	/**
	 * @brief 3차원 백터의 크기 제곱 값을 계산합니다.
	 *
	 * @param v 크기 제곱을 계산할 벡터입니다.
	 *
	 * @return 계산된 크기 제곱 값을 반환합니다.
	 */
	static inline int32_t LengthSq(const Vec3i& v)
	{
		return v.x * v.x + v.y * v.y + v.z * v.z;
	}


	/**
	 * @brief 3차원 벡터의 크기를 얻습니다.
	 *
	 * @param v 크기를 계산할 벡터입니다.
	 *
	 * @return 계산된 크기 값을 반환합니다.
	 */
	static inline float Length(const Vec3i& v)
	{
		float lengthSq = static_cast<float>(LengthSq(v));
		return MathModule::Sqrt(lengthSq);
	}


	/**
	 * @brief 두 3차원 벡터 사이의 각을 계산합니다.
	 *
	 * @param lhs 벡터 사이의 각을 계산할 왼쪽 피연산자 벡터입니다.
	 * @param rhs 벡터 사이의 각을 계산할 오른쪽 피연산자 벡터입니다.
	 *
	 * @return 두 3차원 벡터 사이의 라디안 각도를 반환합니다.
	 */
	static inline float Radian(const Vec3i& lhs, const Vec3i& rhs)
	{
		float lengthL = Length(lhs);
		float lengthR = Length(rhs);
		float dot = Dot(lhs, rhs);

		return MathModule::ACos(dot / (lengthL * lengthR));
	}


	/**
	 * @brief 두 3차원 벡터 사이의 각을 계산합니다.
	 *
	 * @param lhs 벡터 사이의 각을 계산할 왼쪽 피연산자 벡터입니다.
	 * @param rhs 벡터 사이의 각을 계산할 오른쪽 피연산자 벡터입니다.
	 *
	 * @return 두 3차원 벡터 사이의 육십분법 각도를 반환합니다.
	 */
	static inline float Degree(const Vec3i& lhs, const Vec3i& rhs)
	{
		float radian = Radian(lhs, rhs);
		return MathModule::ToDegree(radian);
	}


	/**
	 * @brief 3차원 벡터의 다양한 원소 형식입니다.
	 */
	union
	{
		struct
		{
			int32_t x;
			int32_t y;
			int32_t z;
		};
		int32_t data[3];
	};
};


/**
 * @brief 원소의 데이터 타입이 부동 소수점인 3차원 벡터입니다.
 */
struct Vec3f
{
	/**
	 * @brief 3차원 벡터의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Vec3f() noexcept : x(0.0f), y(0.0f), z(0.0f) {}


	/**
	 * @brief 3차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 */
	Vec3f(float&& xx, float&& yy, float&& zz) noexcept : x(xx), y(yy), z(zz) {}


	/**
	 * @brief 3차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 */
	Vec3f(const float& xx, const float& yy, const float& zz) noexcept : x(xx), y(yy), z(zz) {}


	/**
	 * @brief 3차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Vec3f(float&& e) noexcept : x(e), y(e), z(e) {}


	/**
	 * @brief 3차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Vec3f(const float& e) noexcept : x(e), y(e), z(e) {}


	/**
	 * @brief 3차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vec3f(Vec3f&& v) noexcept : x(v.x), y(v.y), z(v.z) {}


	/**
	 * @brief 3차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vec3f(const Vec3f& v) noexcept : x(v.x), y(v.y), z(v.z) {}


	/**
	 * @brief 3차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vec3f& operator=(Vec3f&& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}


	/**
	 * @brief 3차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vec3f& operator=(const Vec3f& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}


	/**
	 * @brief 3차원 벡터의 원소에 -부호를 취합니다.
	 *
	 * @return 3차원 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vec3f operator-() const
	{
		return Vec3f(-x, -y, -z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vec3f operator+(Vec3f&& v) const
	{
		return Vec3f(x + v.x, y + v.y, z + v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vec3f operator+(const Vec3f& v) const
	{
		return Vec3f(x + v.x, y + v.y, z + v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vec3f operator-(Vec3f&& v) const
	{
		return Vec3f(x - v.x, y - v.y, z - v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vec3f operator-(const Vec3f& v) const
	{
		return Vec3f(x - v.x, y - v.y, z - v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vec3f operator*(Vec3f&& v) const
	{
		return Vec3f(x * v.x, y * v.y, z * v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vec3f operator*(const Vec3f& v) const
	{
		return Vec3f(x * v.x, y * v.y, z * v.z);
	}

	
	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vec3f& operator+=(Vec3f&& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vec3f& operator+=(const Vec3f& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vec3f& operator-=(Vec3f&& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vec3f& operator-=(const Vec3f& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}


	/**
	 * @brief 두 3차원 벡터가 동일한지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(Vec3f&& v) const
	{
		return MathModule::Abs(x - v.x) <= Epsilon
			&& MathModule::Abs(y - v.y) <= Epsilon
			&& MathModule::Abs(z - v.z) <= Epsilon;
	}


	/**
	 * @brief 두 3차원 벡터가 동일한지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(const Vec3f& v) const
	{
		return MathModule::Abs(x - v.x) <= Epsilon
			&& MathModule::Abs(y - v.y) <= Epsilon
			&& MathModule::Abs(z - v.z) <= Epsilon;
	}


	/**
	 * @brief 두 3차원 벡터가 동일하지 않은지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하지 않다면 true, 그렇다면 false를 반환합니다.
	 */
	bool operator!=(Vec3f&& v) const
	{
		return MathModule::Abs(x - v.x) > Epsilon
			|| MathModule::Abs(y - v.y) > Epsilon
			|| MathModule::Abs(z - v.z) > Epsilon;
	}


	/**
	 * @brief 두 3차원 벡터가 동일하지 않은지 검사합니다.
	 *
	 * @param v 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 벡터가 동일하지 않다면 true, 그렇다면 false를 반환합니다.
	 */
	bool operator!=(const Vec3f& v) const
	{
		return MathModule::Abs(x - v.x) > Epsilon
			|| MathModule::Abs(y - v.y) > Epsilon
			|| MathModule::Abs(z - v.z) > Epsilon;
	}


	/**
	 * @brief 3차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 3차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	const float* GetPtr() const { return &data[0]; }


	/**
	 * @brief 3차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 3차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	float* GetPtr() { return &data[0]; }


	/**
	 * @brief 3차원 백터의 내적 연산을 수행합니다.
	 *
	 * @param lhs 백터의 내적 연산을 수행할 좌측 피연산자입니다.
	 * @param rhs 백터의 내적 연산을 수행할 우측 피연산자입니다.
	 *
	 * @return 내적 연산 결과를 반환합니다.
	 */
	static inline float Dot(const Vec3f& lhs, const Vec3f& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}


	/**
	 * @brief 3차원 벡터의 외적 연산을 수행합니다.
	 *
	 * @param lhs 백터의 외적 연산을 수행할 좌측 피연산자입니다.
	 * @param rhs 백터의 외적 연산을 수행할 우측 피연산자입니다.
	 *
	 * @return 외적 연산 결과를 반환합니다.
	 */
	static inline Vec3f Cross(const Vec3f& lhs, const Vec3f& rhs)
	{
		return Vec3f(
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x
		);
	}


	/**
	 * @brief 3차원 백터의 크기 제곱 값을 계산합니다.
	 *
	 * @param v 크기 제곱을 계산할 벡터입니다.
	 *
	 * @return 계산된 크기 제곱 값을 반환합니다.
	 */
	static inline float LengthSq(const Vec3f& v)
	{
		return v.x * v.x + v.y * v.y + v.z * v.z;
	}


	/**
	 * @brief 3차원 벡터의 크기를 얻습니다.
	 *
	 * @param v 크기를 계산할 벡터입니다.
	 *
	 * @return 계산된 크기 값을 반환합니다.
	 */
	static inline float Length(const Vec3f& v)
	{
		float lengthSq = LengthSq(v);
		return MathModule::Sqrt(lengthSq);
	}


	/**
	 * @brief 3차원 벡터를 정규화합니다.
	 *
	 * @param v 정규화 할 벡터입니다.
	 *
	 * @return 정규화된 벡터를 반환합니다.
	 */
	static inline Vec3f Normalize(const Vec3f& v)
	{
		float invLength = 1.0f / Length(v);
		return Vec3f(v.x * invLength, v.y * invLength, v.z * invLength);
	}


	/**
	 * @brief 두 3차원 벡터 사이의 각을 계산합니다.
	 *
	 * @param lhs 벡터 사이의 각을 계산할 왼쪽 피연산자 벡터입니다.
	 * @param rhs 벡터 사이의 각을 계산할 오른쪽 피연산자 벡터입니다.
	 *
	 * @return 두 3차원 벡터 사이의 라디안 각도를 반환합니다.
	 */
	static inline float Radian(const Vec3f& lhs, const Vec3f& rhs)
	{
		float lengthL = Length(lhs);
		float lengthR = Length(rhs);
		float dot = Dot(lhs, rhs);

		return MathModule::ACos(dot / (lengthL * lengthR));
	}


	/**
	 * @brief 두 3차원 벡터 사이의 각을 계산합니다.
	 *
	 * @param lhs 벡터 사이의 각을 계산할 왼쪽 피연산자 벡터입니다.
	 * @param rhs 벡터 사이의 각을 계산할 오른쪽 피연산자 벡터입니다.
	 *
	 * @return 두 3차원 벡터 사이의 육십분법 각도를 반환합니다.
	 */
	static inline float Degree(const Vec3f& lhs, const Vec3f& rhs)
	{
		float radian = Radian(lhs, rhs);
		return MathModule::ToDegree(radian);
	}


	/**
	 * @brief Base 3차원 벡터에 Target 3차원 벡터를 투영합니다.
	 *
	 * @param target 투영 대상에 투영할 벡터입니다.
	 * @param base 투영 대상이 되는 벡터입니다.
	 *
	 * @return base에 투영된 target 벡터를 반환합니다.
	 */
	static inline Vec3f Project(const Vec3f& target, const Vec3f& base)
	{
		float dot = Dot(target, base);
		float lengthSq = LengthSq(base);
		float scale = dot / lengthSq;

		return Vec3f(base.x * scale, base.y * scale, base.z * scale);
	}


	/**
	 * @brief Base 3차원 벡터에 Target 3차원 벡터를 투영한 벡터에 수직인 벡터를 계산합니다.
	 *
	 * @param target 투영 대상에 투영할 벡터입니다.
	 * @param base 투영 대상이 되는 벡터입니다.
	 *
	 * @return 투영된 벡터의 수직인 벡터를 반환합니다.
	 */
	static inline Vec3f Reject(const Vec3f& target, const Vec3f& base)
	{
		Vec3f project = Project(target, base);
		return target - project;
	}


	/**
	 * @brief 두 벡터를 선형 보간한 벡터를 계산합니다.
	 *
	 * @param s 보간의 시작 벡터입니다.
	 * @param e 보간의 끝 벡터입니다.
	 * @param t 두 벡터의 보간 비율입니다.
	 *
	 * @return 보간된 벡터를 반환합니다.
	 */
	static inline Vec3f Lerp(const Vec3f& s, const Vec3f& e, const float& t)
	{
		return s * (1.0f - t) + e * t;
	}


	/**
	 * @brief 두 벡터를 구면 선형 보간한 벡터를 계산합니다.
	 *
	 * @param s 보간의 시작 벡터입니다.
	 * @param e 보간의 끝 벡터입니다.
	 * @param t 두 벡터의 보간 비율입니다.
	 *
	 * @return 보간된 벡터를 반환합니다.
	 */
	static inline Vec3f Slerp(const Vec3f& s, const Vec3f& e, const float& t)
	{
		Vec3f start = Normalize(s);
		Vec3f end = Normalize(e);

		float theta = Radian(start, end);
		float sinTheta = MathModule::Sin(theta);

		float a = MathModule::Sin((1.0f - t) * theta) / sinTheta;
		float b = MathModule::Sin(t * theta) / sinTheta;

		return s * a + e * b;
	}


	/**
	 * @brief 3차원 벡터의 다양한 원소 형식입니다.
	 */
	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};
		float data[3];
	};
};