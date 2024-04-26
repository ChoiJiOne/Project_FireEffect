#pragma once

#include <cstdint>

#include "IResource.h"


/**
 * @brief 파이프라인 참조 및 렌더링 가능한 컬러 프레임 버퍼입니다.
 */
class ColorFrameBuffer : public IResource
{
public:
	/**
	 * @brief 컬러 프레임 버퍼의 디폴트 생성자입니다.
	 *
	 * @param bufferWidth 프레임 버퍼의 가로 크기입니다.
	 * @param bufferHeight 프레임 버퍼의 세로 크기입니다.
	 */
	ColorFrameBuffer(int32_t bufferWidth, int32_t bufferHeight);


	/**
	 * @brief 컬러 프레임 버퍼의 가상 소멸자입니다.
	 */
	virtual ~ColorFrameBuffer();


	/**
	 * @brief 컬러 프레임 버퍼의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(ColorFrameBuffer);


	/**
	 * @brief 컬러 프레임 버퍼 내부의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 컬러 프레임 버퍼를 초기화합니다.
	 *
	 * @param red 색상 버퍼의 R 값입니다.
	 * @param green 색상 버퍼의 G 값입니다.
	 * @param blue 색상 버퍼의 B 값입니다.
	 * @param alpha 색상 버퍼의 A 값입니다.
	 */
	void Clear(float red, float green, float blue, float alpha);


	/**
	 * @brief 컬러 프레임 버퍼를 바인딩합니다.
	 */
	void Bind();


	/**
	 * @brief 컬러 프레임 버퍼의 바인딩을 해제합니다.
	 */
	void Unbind();


	/**
	 * @brief 컬러 프레임 버퍼의 컬러 버퍼 텍스처를 활성화합니다.
	 * 
	 * @param unit 활성화 할 텍스처 유닛입니다.
	 */
	void Active(uint32_t unit) const;


	/**
	 * @brief 컬러 버퍼의 크기를 얻습니다.
	 * 
	 * @param outWidth 컬러 버퍼의 가로 크기입니다.
	 * @param outHeight 컬러 버퍼의 세로 크기입니다.
	 */
	void GetSize(uint32_t& outWidth, uint32_t& outHeight)
	{
		outWidth = width_;
		outHeight = height_;
	}


	/**
	 * @brief 컬러 버퍼 오브젝트의 ID를 얻습니다.
	 * 
	 * @return 컬러 버퍼 오브젝트의 ID를 반환합니다.
	 */
	uint32_t GetColorBufferID() const { return colorBufferID_; }


private:
	/**
	 * @brief 프레임 버퍼의 가로 크기입니다.
	 */
	uint32_t width_ = 0;


	/**
	 * @brief 프레임 버퍼의 세로 크기입니다.
	 */
	uint32_t height_ = 0;


	/**
	 * @brief 프레임 버퍼 오브젝트의 ID입니다.
	 */
	uint32_t framebufferID_ = 0;


	/**
	 * @brief 컬러 버퍼 오브젝트의 ID입니다.
	 */
	uint32_t colorBufferID_;
};