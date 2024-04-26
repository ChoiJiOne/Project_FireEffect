#pragma once

#include <imgui.h>

#include "Vec2.h"

#include "IEntity.h"

class Shader;
class ColorFrameBuffer;


/**
 * @brief 불 효과의 속성입니다.
 */
class Properties : public IEntity
{
public:
	/**
	 * @brief 불 효과의 속성을 나타내는 엔티티의 생성자입니다.
	 *
	 * @param colorFrameBuffer 불 효과가 렌더링된 텍스처입니다.
	 */
	Properties(ColorFrameBuffer* colorFrameBuffer);


	/**
	 * @brief 불 효과의 속성을 나타내는 엔티티의 가상 소멸자입니다.
	 */
	virtual ~Properties();


	/**
	 * @brief 불 효과의 속성을 나타내는 엔티티의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Properties);


	/**
	 * @brief 불 효과의 속성을 나타내는 엔티티를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Tick(float deltaSeconds);


	/**
	 * @brief 불 효과의 속성을 나타내는 엔티티를 화면에 그립니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 불 효과의 속성을 나타내는 엔티티 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief 불 효과를 적용하기 위한 컴퓨트 셰이더입니다.
	 */
	Shader* fireEffect_ = nullptr;


	/**
	 * @brief 불 효과를 적용할 컬러 프레임 버퍼입니다.
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
	 * @brief 불의 움직임 방향입니다.
	 */
	Vec2f fireMovement_ = Vec2f(-0.01f, -0.5f);


	/**
	 * @brief 텍스처 왜곡 방향입니다.
	 */
	Vec2f distortionMovement_ = Vec2f(-0.01f, -0.3f);


	/**
	 * @brief 노말 맵의 크기입니다.
	 */
	float normalStrength_ = 40.0f;


	/**
	 * @brief 누적 시간값입니다.
	 */
	float time_ = 0.0f;
};