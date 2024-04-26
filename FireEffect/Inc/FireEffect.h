#pragma once

#include <imgui.h>

#include "IEntity.h"

class ColorFrameBuffer;


/**
 * @brief UI 내에 불 효과를 나타내는 엔티티입니다.
 */
class FireEffect : public IEntity
{
public:
	/**
	 * @brief 불 효과를 나타내는 엔티티의 생성자입니다.
	 * 
	 * @param colorFrameBuffer 불 효과가 렌더링된 텍스처입니다.
	 */
	FireEffect(ColorFrameBuffer* colorFrameBuffer);


	/**
	 * @brief 불 효과를 나타내는 엔티티의 가상 소멸자입니다.
	 */
	virtual ~FireEffect();


	/**
	 * @brief 불 효과를 나타내는 엔티티의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(FireEffect);


	/**
	 * @brief 불 효과 엔티티를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Tick(float deltaSeconds);


	/**
	 * @brief 불 효과 엔티티를 화면에 그립니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 불 효과 엔티티 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief 불 효과가 렌더링된 텍스처입니다.
	 */
	ColorFrameBuffer* colorFrameBuffer_ = nullptr;


	/**
	 * @brief ImGui 윈도우 속성입니다.
	 */
	ImGuiWindowFlags_ windowFlags_;


	/**
	 * @brief ImGui 내의 위치입니다.
	 */
	ImVec2 location_;


	/**
	 * @brief ImGui 내의 크기입니다.
	 */
	ImVec2 size_;


	/**
	 * @brief ImGui 텍스처의 크기입니다.
	 */
	ImVec2 textureSize_;
};