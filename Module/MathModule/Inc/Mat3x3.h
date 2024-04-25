#pragma once

#include <cstdint>

#include "MathModule.h"


/**
 * @brief 3x3 행렬입니다.
 */
struct Mat3x3
{
	/**
	 * @brief 3x3 행렬의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Mat3x3() noexcept
	{
		e00 = 0.0f; e01 = 0.0f; e02 = 0.0f;
		e10 = 0.0f; e11 = 0.0f; e12 = 0.0f;
		e20 = 0.0f; e21 = 0.0f; e22 = 0.0f;
	}


	/**
	 * @brief 3x3 행렬의 생성자입니다.
	 *
	 * @param ee00 행렬의 (0, 0) 성분입니다.
	 * @param ee01 행렬의 (0, 1) 성분입니다.
	 * @param ee02 행렬의 (0, 2) 성분입니다.
	 * @param ee10 행렬의 (1, 0) 성분입니다.
	 * @param ee11 행렬의 (1, 1) 성분입니다.
	 * @param ee12 행렬의 (1, 2) 성분입니다.
	 * @param ee20 행렬의 (2, 0) 성분입니다.
	 * @param ee21 행렬의 (2, 1) 성분입니다.
	 * @param ee22 행렬의 (2, 2) 성분입니다.
	 */
	Mat3x3(
		float&& ee00, float&& ee01, float&& ee02,
		float&& ee10, float&& ee11, float&& ee12,
		float&& ee20, float&& ee21, float&& ee22
	) noexcept
	{
		e00 = ee00; e01 = ee01; e02 = ee02;
		e10 = ee10; e11 = ee11; e12 = ee12;
		e20 = ee20; e21 = ee21; e22 = ee22;
	}


	/**
	 * @brief 3x3 행렬의 생성자입니다.
	 *
	 * @param ee00 행렬의 (0, 0) 성분입니다.
	 * @param ee01 행렬의 (0, 1) 성분입니다.
	 * @param ee02 행렬의 (0, 2) 성분입니다.
	 * @param ee10 행렬의 (1, 0) 성분입니다.
	 * @param ee11 행렬의 (1, 1) 성분입니다.
	 * @param ee12 행렬의 (1, 2) 성분입니다.
	 * @param ee20 행렬의 (2, 0) 성분입니다.
	 * @param ee21 행렬의 (2, 1) 성분입니다.
	 * @param ee22 행렬의 (2, 2) 성분입니다.
	 */
	Mat3x3(
		const float& ee00, const float& ee01, const float& ee02,
		const float& ee10, const float& ee11, const float& ee12,
		const float& ee20, const float& ee21, const float& ee22
	) noexcept
	{
		e00 = ee00; e01 = ee01; e02 = ee02;
		e10 = ee10; e11 = ee11; e12 = ee12;
		e20 = ee20; e21 = ee21; e22 = ee22;
	}


	/**
	 * @brief 3x3 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Mat3x3(float&& e) noexcept
	{
		e00 = e; e01 = e; e02 = e;
		e10 = e; e11 = e; e12 = e;
		e20 = e; e21 = e; e22 = e;
	}


	/**
	 * @brief 3x3 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Mat3x3(const float& e) noexcept
	{
		e00 = e; e01 = e; e02 = e;
		e10 = e; e11 = e; e12 = e;
		e20 = e; e21 = e; e22 = e;
	}


	/**
	 * @brief 3x3 행렬의 복사 생성자입니다.
	 *
	 * @param m 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Mat3x3(Mat3x3&& m) noexcept
	{
		e00 = m.e00; e01 = m.e01; e02 = m.e02;
		e10 = m.e10; e11 = m.e11; e12 = m.e12;
		e20 = m.e20; e21 = m.e21; e22 = m.e22;
	}


	/**
	 * @brief 3x3 행렬의 복사 생성자입니다.
	 *
	 * @param m 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Mat3x3(const Mat3x3& m) noexcept
	{
		e00 = m.e00; e01 = m.e01; e02 = m.e02;
		e10 = m.e10; e11 = m.e11; e12 = m.e12;
		e20 = m.e20; e21 = m.e21; e22 = m.e22;
	}


	/**
	 * @brief 3x3 행렬의 대입 연산자입니다.
	 *
	 * @param m 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
	 */
	Mat3x3& operator=(Mat3x3&& m) noexcept
	{
		if (this == &m) return *this;

		e00 = m.e00; e01 = m.e01; e02 = m.e02;
		e10 = m.e10; e11 = m.e11; e12 = m.e12;
		e20 = m.e20; e21 = m.e21; e22 = m.e22;

		return *this;
	}


	/**
	 * @brief 3x3 행렬의 대입 연산자입니다.
	 *
	 * @param m 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
	 */
	Mat3x3& operator=(const Mat3x3& m) noexcept
	{
		if (this == &m) return *this;

		e00 = m.e00; e01 = m.e01; e02 = m.e02;
		e10 = m.e10; e11 = m.e11; e12 = m.e12;
		e20 = m.e20; e21 = m.e21; e22 = m.e22;

		return *this;
	}


	/**
	 * @brief 3x3 행렬의 모든 원소에 -부호를 취합니다.
	 *
	 * @return 모든 원소에 -부호를 취한 새로운 행렬을 반환합니다.
	 */
	Mat3x3 operator-() const
	{
		return Mat3x3(
			-e00, -e01, -e02,
			-e10, -e11, -e12,
			-e20, -e21, -e22
		);
	}


	/**
	 * @brief 두 3x3 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param m 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Mat3x3 operator+(Mat3x3&& m) const
	{
		return Mat3x3(
			e00 + m.e00, e01 + m.e01, e02 + m.e02,
			e10 + m.e10, e11 + m.e11, e12 + m.e12,
			e20 + m.e20, e21 + m.e21, e22 + m.e22
		);
	}


	/**
	 * @brief 두 3x3 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param m 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Mat3x3 operator+(const Mat3x3& m) const
	{
		return Mat3x3(
			e00 + m.e00, e01 + m.e01, e02 + m.e02,
			e10 + m.e10, e11 + m.e11, e12 + m.e12,
			e20 + m.e20, e21 + m.e21, e22 + m.e22
		);
	}


	/**
	 * @brief 두 3x3 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param m 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Mat3x3 operator-(Mat3x3&& m) const
	{
		return Mat3x3(
			e00 - m.e00, e01 - m.e01, e02 - m.e02,
			e10 - m.e10, e11 - m.e11, e12 - m.e12,
			e20 - m.e20, e21 - m.e21, e22 - m.e22
		);
	}


	/**
	 * @brief 두 3x3 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param m 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Mat3x3 operator-(const Mat3x3& m) const
	{
		return Mat3x3(
			e00 - m.e00, e01 - m.e01, e02 - m.e02,
			e10 - m.e10, e11 - m.e11, e12 - m.e12,
			e20 - m.e20, e21 - m.e21, e22 - m.e22
		);
	}


	/**
	 * @brief 3x3 행렬에 부동소수점을 곱합니다.
	 *
	 * @param scalar 3x3 행렬에 부동수소점 수를 곱할 스칼라 값입니다.
	 *
	 * @return 3x3 행렬에 부동소수점을 곱합 결과를 반환합니다.
	 */
	Mat3x3 operator*(float&& scalar) const
	{
		return Mat3x3(
			scalar * e00, scalar * e01, scalar * e02,
			scalar * e10, scalar * e11, scalar * e12,
			scalar * e20, scalar * e21, scalar * e22
		);
	}


	/**
	 * @brief 3x3 행렬에 부동소수점을 곱합니다.
	 *
	 * @param scalar 3x3 행렬에 부동수소점 수를 곱할 스칼라 값입니다.
	 *
	 * @return 3x3 행렬에 부동소수점을 곱합 결과를 반환합니다.
	 */
	Mat3x3 operator*(const float& scalar) const
	{
		return Mat3x3(
			scalar * e00, scalar * e01, scalar * e02,
			scalar * e10, scalar * e11, scalar * e12,
			scalar * e20, scalar * e21, scalar * e22
		);
	}


	/**
	 * @brief 두 3x3 행렬을 곱합니다.
	 *
	 * @param m 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
	 */
	Mat3x3 operator*(Mat3x3&& m) const
	{
		return Mat3x3(
			e00 * m.e00 + e01 * m.e10 + e02 * m.e20,
			e00 * m.e01 + e01 * m.e11 + e02 * m.e21,
			e00 * m.e02 + e01 * m.e12 + e02 * m.e22,
			e10 * m.e00 + e11 * m.e10 + e12 * m.e20,
			e10 * m.e01 + e11 * m.e11 + e12 * m.e21,
			e10 * m.e02 + e11 * m.e12 + e12 * m.e22,
			e20 * m.e00 + e21 * m.e10 + e22 * m.e20,
			e20 * m.e01 + e21 * m.e11 + e22 * m.e21,
			e20 * m.e02 + e21 * m.e12 + e22 * m.e22
		);
	}


	/**
	 * @brief 두 3x3 행렬을 곱합니다.
	 *
	 * @param m 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
	 */
	Mat3x3 operator*(const Mat3x3& m) const
	{
		return Mat3x3(
			e00 * m.e00 + e01 * m.e10 + e02 * m.e20,
			e00 * m.e01 + e01 * m.e11 + e02 * m.e21,
			e00 * m.e02 + e01 * m.e12 + e02 * m.e22,
			e10 * m.e00 + e11 * m.e10 + e12 * m.e20,
			e10 * m.e01 + e11 * m.e11 + e12 * m.e21,
			e10 * m.e02 + e11 * m.e12 + e12 * m.e22,
			e20 * m.e00 + e21 * m.e10 + e22 * m.e20,
			e20 * m.e01 + e21 * m.e11 + e22 * m.e21,
			e20 * m.e02 + e21 * m.e12 + e22 * m.e22
		);
	}


	/**
	 * @brief 두 3x3 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param m 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Mat3x3& operator+=(Mat3x3&& m) noexcept
	{
		e00 += m.e00; e01 += m.e01; e02 += m.e02;
		e10 += m.e10; e11 += m.e11; e12 += m.e12;
		e20 += m.e20; e21 += m.e21; e22 += m.e22;

		return *this;
	}


	/**
	 * @brief 두 3x3 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param m 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Mat3x3& operator+=(const Mat3x3& m) noexcept
	{
		e00 += m.e00; e01 += m.e01; e02 += m.e02;
		e10 += m.e10; e11 += m.e11; e12 += m.e12;
		e20 += m.e20; e21 += m.e21; e22 += m.e22;

		return *this;
	}


	/**
	 * @brief 두 3x3 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param m 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Mat3x3& operator-=(Mat3x3&& m) noexcept
	{
		e00 -= m.e00; e01 -= m.e01; e02 -= m.e02;
		e10 -= m.e10; e11 -= m.e11; e12 -= m.e12;
		e20 -= m.e20; e21 -= m.e21; e22 -= m.e22;

		return *this;
	}


	/**
	 * @brief 두 3x3 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param m 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Mat3x3& operator-=(const Mat3x3& m) noexcept
	{
		e00 -= m.e00; e01 -= m.e01; e02 -= m.e02;
		e10 -= m.e10; e11 -= m.e11; e12 -= m.e12;
		e20 -= m.e20; e21 -= m.e21; e22 -= m.e22;

		return *this;
	}


	/**
	 * @brief 두 3x3행렬이 동일한지 검사합니다.
	 *
	 * @param m 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 행렬이 동일하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(Mat3x3&& m) const
	{
		return MathModule::Abs(e00 - m.e00) <= Epsilon
			&& MathModule::Abs(e01 - m.e01) <= Epsilon
			&& MathModule::Abs(e02 - m.e02) <= Epsilon
			&& MathModule::Abs(e10 - m.e10) <= Epsilon
			&& MathModule::Abs(e11 - m.e11) <= Epsilon
			&& MathModule::Abs(e12 - m.e12) <= Epsilon
			&& MathModule::Abs(e20 - m.e20) <= Epsilon
			&& MathModule::Abs(e21 - m.e21) <= Epsilon
			&& MathModule::Abs(e22 - m.e22) <= Epsilon;
	}


	/**
	 * @brief 두 3x3행렬이 동일한지 검사합니다.
	 *
	 * @param m 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 행렬이 동일하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(const Mat3x3& m) const
	{
		return MathModule::Abs(e00 - m.e00) <= Epsilon
			&& MathModule::Abs(e01 - m.e01) <= Epsilon
			&& MathModule::Abs(e02 - m.e02) <= Epsilon
			&& MathModule::Abs(e10 - m.e10) <= Epsilon
			&& MathModule::Abs(e11 - m.e11) <= Epsilon
			&& MathModule::Abs(e12 - m.e12) <= Epsilon
			&& MathModule::Abs(e20 - m.e20) <= Epsilon
			&& MathModule::Abs(e21 - m.e21) <= Epsilon
			&& MathModule::Abs(e22 - m.e22) <= Epsilon;
	}


	/**
	 * @brief 두 3x3행렬이 동일하지 않은지 검사합니다.
	 *
	 * @param m 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 행렬이 동일하지 않다면 true, 그렇다면 false를 반환합니다.
	 */
	bool operator!=(Mat3x3&& m) const
	{
		return MathModule::Abs(e00 - m.e00) > Epsilon
			|| MathModule::Abs(e01 - m.e01) > Epsilon
			|| MathModule::Abs(e02 - m.e02) > Epsilon
			|| MathModule::Abs(e10 - m.e10) > Epsilon
			|| MathModule::Abs(e11 - m.e11) > Epsilon
			|| MathModule::Abs(e12 - m.e12) > Epsilon
			|| MathModule::Abs(e20 - m.e20) > Epsilon
			|| MathModule::Abs(e21 - m.e21) > Epsilon
			|| MathModule::Abs(e22 - m.e22) > Epsilon;
	}


	/**
	 * @brief 두 3x3행렬이 동일하지 않은지 검사합니다.
	 *
	 * @param m 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 행렬이 동일하지 않다면 true, 그렇다면 false를 반환합니다.
	 */
	bool operator!=(const Mat3x3& m) const
	{
		return MathModule::Abs(e00 - m.e00) > Epsilon
			|| MathModule::Abs(e01 - m.e01) > Epsilon
			|| MathModule::Abs(e02 - m.e02) > Epsilon
			|| MathModule::Abs(e10 - m.e10) > Epsilon
			|| MathModule::Abs(e11 - m.e11) > Epsilon
			|| MathModule::Abs(e12 - m.e12) > Epsilon
			|| MathModule::Abs(e20 - m.e20) > Epsilon
			|| MathModule::Abs(e21 - m.e21) > Epsilon
			|| MathModule::Abs(e22 - m.e22) > Epsilon;
	}


	/**
	 * @brief 3x3 행렬 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 3x3 행렬 원소 배열의 포인터를 반환합니다.
	 */
	const float* GetPtr() const { return &data[0]; }


	/**
	 * @brief 3x3 행렬 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 3x3 행렬 원소 배열의 포인터를 반환합니다.
	 */
	float* GetPtr() { return &data[0]; }


	/**
	 * @brief 3x3 행렬의 모든 원소가 0인 행렬을 얻습니다.
	 *
	 * @return 모든 원소가 0인 3x3 행렬을 반환합니다.
	 */
	static inline Mat3x3 Zero()
	{
		return Mat3x3(
			0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f
		);
	}


	/**
	 * @brief 3x3 행렬의 단위 행렬을 얻습니다.
	 *
	 * @return 3x3 행렬의 단위 행렬를 반환합니다.
	 */
	static inline Mat3x3 Identity()
	{
		return Mat3x3(
			1.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 1.0f
		);
	}


	/**
	 * @brief 3x3 행렬의 전치 행렬을 얻습니다.
	 *
	 * @param m 원소들을 전치할 3x3 행렬입니다.
	 *
	 * @return 원소가 전치된 3x3 행렬을 반환합니다.
	 */
	static inline Mat3x3 Transpose(const Mat3x3& m)
	{
		return Mat3x3(
			m.e00, m.e10, m.e20,
			m.e01, m.e11, m.e21,
			m.e02, m.e12, m.e22
		);
	}


	/**
	 * @brief 3x3 행렬의 행렬식 값을 얻습니다.
	 *
	 * @param m 행렬식 값을 계산할 3x3 행렬입니다.
	 *
	 * @return 3x3 행렬의 행렬식 값을 반환합니다.
	 */
	static inline float Determinant(const Mat3x3& m)
	{
		return m.e00 * (m.e11 * m.e22 - m.e21 * m.e12) - m.e10 * (m.e01 * m.e22 - m.e21 * m.e02) + m.e20 * (m.e01 * m.e12 - m.e11 * m.e02);
	}


	/**
	 * @brief 3x3 행렬의 역행렬을 얻습니다.
	 *
	 * @param m 역행렬을 계산할 3x3 행렬입니다.
	 *
	 * @return 3x3 행렬의 역행렬을 반환합니다.
	 */
	static inline Mat3x3 Inverse(const Mat3x3& m)
	{
		float oneOverDeterminant = 1.0f / Determinant(m);

		return Mat3x3(
			+(m.e11 * m.e22 - m.e21 * m.e12) * oneOverDeterminant,
			-(m.e10 * m.e22 - m.e20 * m.e12) * oneOverDeterminant,
			+(m.e10 * m.e21 - m.e20 * m.e11) * oneOverDeterminant,
			-(m.e01 * m.e22 - m.e21 * m.e02) * oneOverDeterminant,
			+(m.e00 * m.e22 - m.e20 * m.e02) * oneOverDeterminant,
			-(m.e00 * m.e21 - m.e20 * m.e01) * oneOverDeterminant,
			+(m.e01 * m.e12 - m.e11 * m.e02) * oneOverDeterminant,
			-(m.e00 * m.e12 - m.e10 * m.e02) * oneOverDeterminant,
			+(m.e00 * m.e11 - m.e10 * m.e01) * oneOverDeterminant
		);
	}


	/**
	 * @brief 3x3 행렬의 원소입니다.
	 */
	union
	{
		struct
		{
			float e00; float e01; float e02;
			float e10; float e11; float e12;
			float e20; float e21; float e22;
		};
		float data[9];
	};
};