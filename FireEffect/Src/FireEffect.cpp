#include "ColorFrameBuffer.h"

#include "FireEffect.h"

FireEffect::FireEffect(ColorFrameBuffer* colorFrameBuffer)
	: colorFrameBuffer_(colorFrameBuffer)
	, windowFlags_(static_cast<ImGuiWindowFlags_>(ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse))
{
	location_ = ImVec2(0.0f, 0.0f);
	size_ = ImVec2(700.0f, 800.0f);
	textureSize_ = ImVec2(700.0f, 700.0f);
}

FireEffect::~FireEffect()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void FireEffect::Tick(float deltaSeconds)
{
	ImGui::Begin("Effect", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
	ImGui::SetWindowPos(location_);
	ImGui::SetWindowSize(size_);
	
	ImVec2 windowSize = ImGui::GetWindowSize();
	windowSize.x -= textureSize_.x;
	windowSize.y -= textureSize_.y;
	windowSize.x *= 0.5f;
	windowSize.y *= 0.5f;

	ImGui::SetCursorPos(windowSize);
	ImGui::Image((void*)(intptr_t)(colorFrameBuffer_->GetColorBufferID()), textureSize_, ImVec2(0.0f, 1.0f), ImVec2(1.0f, 0.0f));
	ImGui::End();
}

void FireEffect::Render()
{
}

void FireEffect::Release()
{
	if (bIsInitialized_)
	{
		bIsInitialized_ = false;
	}
}