#pragma once

#include <cstdint>

#include "IResource.h"


/**
 * @brief 파이프라인 참조 및 렌더링 가능한 프레임 버퍼입니다.
 */
class FrameBuffer : public IResource
{
public:
	/**
	 * @brief 프레임 버퍼의 생성자입니다.
	 *
	 * @param bufferWidth 프레임 버퍼의 가로 크기입니다.
	 * @param bufferHeight 프레임 버퍼의 세로 크기입니다.
	 */
	FrameBuffer(int32_t bufferWidth, int32_t bufferHeight);


	/**
	 * @brief 프레임 버퍼의 생성자입니다.
	 *
	 * @param bufferWidth 프레임 버퍼의 가로 크기입니다.
	 * @param bufferHeight 프레임 버퍼의 세로 크기입니다.
	 * @param sample 멀티 샘플링 시 사용할 샘플 수입니다.
	 */
	FrameBuffer(int32_t bufferWidth, int32_t bufferHeight, int32_t sample);


	/**
	 * @brief 프레임 버퍼의 가상 소멸자입니다.
	 */
	virtual ~FrameBuffer();


	/**
	 * @brief 프레임 버퍼의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(FrameBuffer);


	/**
	 * @brief 프레임 버퍼 내부의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 프레임 버퍼를 초기화합니다.
	 *
	 * @param red 색상 버퍼의 R 값입니다.
	 * @param green 색상 버퍼의 G 값입니다.
	 * @param blue 색상 버퍼의 B 값입니다.
	 * @param alpha 색상 버퍼의 A 값입니다.
	 * @param depth 깊이 버퍼의 초기화 값입니다.
	 * @param stencil 스텐실 버퍼의 초기화 값입니다.
	 */
	void Clear(float red, float green, float blue, float alpha, float depth = 1.0f, uint8_t stencil = 0);


	/**
	 * @brief 프레임 버퍼를 바인딩합니다.
	 */
	void Bind();


	/**
	 * @brief 프레임 버퍼의 바인딩을 해제합니다.
	 */
	void Unbind();


	/**
	 * @brief 프레임 버퍼의 컬러 버퍼 텍스처를 활성화합니다.
	 *
	 * @param index 활성화 할 컬러 버퍼의 인덱스입니다.
	 * @param unit 활성화 할 텍스처 유닛입니다.
	 */
	void Active(uint32_t index, uint32_t unit) const;


	/**
	 * @brief 한 프레임버에서 다른 프레임 버퍼로 복사를 수행합니다.
	 * 
	 * @param src 원복 프레임 버퍼입니다.
	 * @param dst 복사를 수행할 프레임 버퍼입니다.
	 */
	static void Blit(FrameBuffer* src, FrameBuffer* dst);


private:
	/**
	 * @brief 색상 버퍼의 최대 수입니다.
	 */
	static const uint32_t MAX_COLOR_BUFFER_COUNT = 2;


	/**
	 * @brief 멀티 샘플링이 활성화 되었는지 확인합니다.
	 */
	bool bEnableMultisampling_ = false;


	/**
	 * @brief 버퍼의 가로 크기입니다.
	 */
	uint32_t width_ = 0;


	/**
	 * @brief 버퍼의 세로 크기입니다.
	 */
	uint32_t height_ = 0;


	/**
	 * @brief 프레임 버퍼 오브젝트의 ID입니다.
	 */
	uint32_t framebufferID_ = 0;


	/**
	 * @brief 컬러 버퍼 오브젝트의 ID입니다.
	 */
	uint32_t colorBufferID_[MAX_COLOR_BUFFER_COUNT] = { 0, };


	/**
	 * @brief 깊이 스텐실 버퍼 오브젝트의 ID입니다.
	 */
	uint32_t depthStencilBufferID_ = 0;
};