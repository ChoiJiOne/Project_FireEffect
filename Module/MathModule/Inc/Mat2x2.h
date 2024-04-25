#pragma once

#include <cstdint>

#include "MathModule.h"


/**
 * @brief 2x2 행렬입니다.
 */
struct Mat2x2
{
	/**
	 * @brief 2x2 행렬의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Mat2x2() noexcept
	{
		e00 = 0.0f; e01 = 0.0f;
		e10 = 0.0f; e11 = 0.0f;
	}


	/**
	 * @brief 2x2 행렬의 생성자입니다.
	 *
	 * @param ee00 행렬의 (0, 0) 성분입니다.
	 * @param ee01 행렬의 (0, 1) 성분입니다.
	 * @param ee10 행렬의 (1, 0) 성분입니다.
	 * @param ee11 행렬의 (1, 1) 성분입니다.
	 */
	Mat2x2(
		float&& ee00, float&& ee01,
		float&& ee10, float&& ee11
	) noexcept
	{
		e00 = ee00; e01 = ee01;
		e10 = ee10; e11 = ee11;
	}


	/**
	 * @brief 2x2 행렬의 생성자입니다.
	 *
	 * @param e00 행렬의 (0, 0) 성분입니다.
	 * @param e01 행렬의 (0, 1) 성분입니다.
	 * @param e10 행렬의 (1, 0) 성분입니다.
	 * @param e11 행렬의 (1, 1) 성분입니다.
	 */
	Mat2x2(
		const float& ee00, const float& ee01,
		const float& ee10, const float& ee11
	) noexcept
	{
		e00 = ee00; e01 = ee01;
		e10 = ee10; e11 = ee11;
	}


	/**
	 * @brief 2x2 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Mat2x2(float&& e) noexcept
	{
		e00 = e; e01 = e;
		e10 = e; e11 = e;
	}


	/**
	 * @brief 2x2 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Mat2x2(const float& e) noexcept
	{
		e00 = e; e01 = e;
		e10 = e; e11 = e;
	}


	/**
	 * @brief 2x2 행렬의 복사 생성자입니다.
	 *
	 * @param m 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Mat2x2(Mat2x2&& m) noexcept
	{
		e00 = m.e00; e01 = m.e01;
		e10 = m.e10; e11 = m.e11;
	}


	/**
	 * @brief 2x2 행렬의 복사 생성자입니다.
	 *
	 * @param m 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Mat2x2(const Mat2x2& m) noexcept
	{
		e00 = m.e00; e01 = m.e01;
		e10 = m.e10; e11 = m.e11;
	}


	/**
	 * @brief 2x2 행렬의 대입 연산자입니다.
	 *
	 * @param m 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
	 */
	Mat2x2& operator=(Mat2x2&& m) noexcept
	{
		if (this == &m) return *this;

		e00 = m.e00; e01 = m.e01;
		e10 = m.e10; e11 = m.e11;

		return *this;
	}


	/**
	 * @brief 2x2 행렬의 대입 연산자입니다.
	 *
	 * @param m 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
	 */
	Mat2x2& operator=(const Mat2x2& m) noexcept
	{
		if (this == &m) return *this;

		e00 = m.e00; e01 = m.e01;
		e10 = m.e10; e11 = m.e11;

		return *this;
	}


	/**
	 * @brief 2x2 행렬의 모든 원소에 -부호를 취합니다.
	 *
	 * @return 모든 원소에 -부호를 취한 새로운 행렬을 반환합니다.
	 */
	Mat2x2 operator-() const
	{
		return Mat2x2(
			-e00, -e01,
			-e10, -e11
		);
	}


	/**
	 * @brief 두 2x2 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param m 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Mat2x2 operator+(Mat2x2&& m) const
	{
		return Mat2x2(
			e00 + m.e00, e01 + m.e01,
			e10 + m.e10, e11 + m.e11
		);
	}


	/**
	 * @brief 두 2x2 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param m 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Mat2x2 operator+(const Mat2x2& m) const
	{
		return Mat2x2(
			e00 + m.e00, e01 + m.e01,
			e10 + m.e10, e11 + m.e11
		);
	}


	/**
	 * @brief 두 2x2 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param m 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Mat2x2 operator-(Mat2x2&& m) const
	{
		return Mat2x2(
			e00 - m.e00, e01 - m.e01,
			e10 - m.e10, e11 - m.e11
		);
	}


	/**
	 * @brief 두 2x2 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param m 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Mat2x2 operator-(const Mat2x2& m) const
	{
		return Mat2x2(
			e00 - m.e00, e01 - m.e01,
			e10 - m.e10, e11 - m.e11
		);
	}


	/**
	 * @brief 2x2 행렬에 부동소수점을 곱합니다.
	 *
	 * @param scalar 2x2 행렬에 부동수소점 수를 곱할 스칼라 값입니다.
	 *
	 * @return 2x2 행렬에 부동소수점을 곱합 결과를 반환합니다.
	 */
	Mat2x2 operator*(float&& scalar) const
	{
		return Mat2x2(
			scalar * e00, scalar * e01,
			scalar * e10, scalar * e11
		);
	}


	/**
	 * @brief 2x2 행렬에 부동소수점을 곱합니다.
	 *
	 * @param scalar 2x2 행렬에 부동수소점 수를 곱할 스칼라 값입니다.
	 *
	 * @return 2x2 행렬에 부동소수점을 곱합 결과를 반환합니다.
	 */
	Mat2x2 operator*(const float& scalar) const
	{
		return Mat2x2(
			scalar * e00, scalar * e01,
			scalar * e10, scalar * e11
		);
	}


	/**
	 * @brief 두 2x2 행렬을 곱합니다.
	 *
	 * @param m 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
	 */
	Mat2x2 operator*(Mat2x2&& m) const
	{
		return Mat2x2(
			e00 * m.e00 + e01 * m.e10,
			e00 * m.e01 + e01 * m.e11,
			e10 * m.e00 + e11 * m.e10,
			e10 * m.e01 + e11 * m.e11
		);
	}


	/**
	 * @brief 두 2x2 행렬을 곱합니다.
	 *
	 * @param m 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
	 */
	Mat2x2 operator*(const Mat2x2& m) const
	{
		return Mat2x2(
			e00 * m.e00 + e01 * m.e10,
			e00 * m.e01 + e01 * m.e11,
			e10 * m.e00 + e11 * m.e10,
			e10 * m.e01 + e11 * m.e11
		);
	}


	/**
	 * @brief 두 2x2 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param m 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Mat2x2& operator+=(Mat2x2&& m) noexcept
	{
		e00 += m.e00; e01 += m.e01;
		e10 += m.e10; e11 += m.e11;

		return *this;
	}


	/**
	 * @brief 두 2x2 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param m 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Mat2x2& operator+=(const Mat2x2& m) noexcept
	{
		e00 += m.e00; e01 += m.e01;
		e10 += m.e10; e11 += m.e11;

		return *this;
	}


	/**
	 * @brief 두 2x2 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param m 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Mat2x2& operator-=(Mat2x2&& m) noexcept
	{
		e00 -= m.e00; e01 -= m.e01;
		e10 -= m.e10; e11 -= m.e11;

		return *this;
	}


	/**
	 * @brief 두 2x2 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param m 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Mat2x2& operator-=(const Mat2x2& m) noexcept
	{
		e00 -= m.e00; e01 -= m.e01;
		e10 -= m.e10; e11 -= m.e11;

		return *this;
	}


	/**
	 * @brief 두 2x2행렬이 동일한지 검사합니다.
	 *
	 * @param m 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 행렬이 동일하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(Mat2x2&& m) const
	{
		return MathModule::Abs(e00 - m.e00) <= Epsilon
			&& MathModule::Abs(e01 - m.e01) <= Epsilon
			&& MathModule::Abs(e10 - m.e10) <= Epsilon
			&& MathModule::Abs(e11 - m.e11) <= Epsilon;
	}


	/**
	 * @brief 두 2x2행렬이 동일한지 검사합니다.
	 *
	 * @param m 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 행렬이 동일하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(const Mat2x2& m) const
	{
		return MathModule::Abs(e00 - m.e00) <= Epsilon
			&& MathModule::Abs(e01 - m.e01) <= Epsilon
			&& MathModule::Abs(e10 - m.e10) <= Epsilon
			&& MathModule::Abs(e11 - m.e11) <= Epsilon;
	}


	/**
	 * @brief 두 2x2행렬이 동일하지 않은지 검사합니다.
	 *
	 * @param m 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 행렬이 동일하지 않다면 true, 그렇다면 false를 반환합니다.
	 */
	bool operator!=(Mat2x2&& m) const
	{
		return MathModule::Abs(e00 - m.e00) > Epsilon
			|| MathModule::Abs(e01 - m.e01) > Epsilon
			|| MathModule::Abs(e10 - m.e10) > Epsilon
			|| MathModule::Abs(e11 - m.e11) > Epsilon;
	}


	/**
	 * @brief 두 2x2행렬이 동일하지 않은지 검사합니다.
	 *
	 * @param m 검사를 수행할 피연산자입니다.
	 *
	 * @return 두 행렬이 동일하지 않다면 true, 그렇다면 false를 반환합니다.
	 */
	bool operator!=(const Mat2x2& m) const
	{
		return MathModule::Abs(e00 - m.e00) > Epsilon
			|| MathModule::Abs(e01 - m.e01) > Epsilon
			|| MathModule::Abs(e10 - m.e10) > Epsilon
			|| MathModule::Abs(e11 - m.e11) > Epsilon;
	}


	/**
	 * @brief 2x2 행렬 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 2x2 행렬 원소 배열의 포인터를 반환합니다.
	 */
	const float* GetPtr() const { return &data[0]; }


	/**
	 * @brief 2x2 행렬 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 2x2 행렬 원소 배열의 포인터를 반환합니다.
	 */
	float* GetPtr() { return &data[0]; }


	/**
	 * @brief 2x2 행렬의 모든 원소가 0인 행렬을 얻습니다.
	 * 
	 * @return 모든 원소가 0인 2x2 행렬을 반환합니다.
	 */
	static inline Mat2x2 Zero()
	{
		return Mat2x2(
			0.0f, 0.0f,
			0.0f, 0.0f
		);
	}


	/**
	 * @brief 2x2 행렬의 단위 행렬을 얻습니다.
	 *
	 * @return 2x2 행렬의 단위 행렬를 반환합니다.
	 */
	static inline Mat2x2 Identity()
	{
		return Mat2x2(
			1.0f, 0.0f,
			0.0f, 1.0f
		);
	}


	/**
	 * @brief 2x2 행렬의 전치 행렬을 얻습니다.
	 * 
	 * @param m 원소들을 전치할 2x2 행렬입니다.
	 * 
	 * @return 원소가 전치된 2x2 행렬을 반환합니다.
	 */
	static inline Mat2x2 Transpose(const Mat2x2& m)
	{
		return Mat2x2(
			m.e00, m.e10,
			m.e01, m.e11
		);
	}


	/**
	 * @brief 2x2 행렬의 행렬식 값을 얻습니다.
	 * 
	 * @param m 행렬식 값을 계산할 2x2 행렬입니다.
	 * 
	 * @return 2x2 행렬의 행렬식 값을 반환합니다.
	 */
	static inline float Determinant(const Mat2x2& m)
	{
		return m.e00 * m.e11 - m.e01 * m.e10;
	}


	/**
	 * @brief 2x2 행렬의 역행렬을 얻습니다.
	 * 
	 * @param m 역행렬을 계산할 2x2 행렬입니다.
	 * 
	 * @return 2x2 행렬의 역행렬을 반환합니다.
	 */
	static inline Mat2x2 Inverse(const Mat2x2& m)
	{
		float oneOverDeterminant = 1.0f / Determinant(m);

		return Mat2x2(
			+m.e11 * oneOverDeterminant,
			-m.e01 * oneOverDeterminant,
			-m.e10 * oneOverDeterminant,
			+m.e00 * oneOverDeterminant
		);
	}

	
	/**
	 * @brief 2x2 행렬의 원소입니다.
	 */
	union
	{
		struct
		{
			float e00; float e01;
			float e10; float e11;
		};
		float data[4];
	};
};