#include <glad/glad.h>

#include "ColorFrameBuffer.h"
#include "RenderModule.h"
#include "Shader.h"

#include "Properties.h"

Properties::Properties(ColorFrameBuffer* colorFrameBuffer)
	: colorFrameBuffer_(colorFrameBuffer)
	, windowFlags_(static_cast<ImGuiWindowFlags_>(ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse))
{
	location_ = ImVec2(700.0f, 0.0f);
	size_ = ImVec2(300.0f, 800.0f);
	fireEffect_ = RenderModule::CreateResource<Shader>("Shader/FireEffect.comp");
}

Properties::~Properties()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Properties::Tick(float deltaSeconds)
{
	time_ += deltaSeconds;

	ImGui::Begin("Properties", nullptr, windowFlags_);
	ImGui::SetWindowPos(location_);
	ImGui::SetWindowSize(size_);
	ImGui::SliderFloat2("fireMovement", fireMovement_.data, -1.0f, 1.0f);
	ImGui::SliderFloat2("distortionMovement", distortionMovement_.data, -1.0f, 1.0f);
	ImGui::SliderFloat("normalStrength", &normalStrength_, 0.0f, 100.0f);
	ImGui::End();
}

void Properties::Render()
{
	fireEffect_->Bind();
	fireEffect_->SetUniform("time", time_);
	fireEffect_->SetUniform("fireMovement", fireMovement_);
	fireEffect_->SetUniform("distortionMovement", distortionMovement_);
	fireEffect_->SetUniform("normalStrength", normalStrength_);

	colorFrameBuffer_->Bind();
	colorFrameBuffer_->Clear(0.0f, 0.0f, 0.0f, 0.0f);
	colorFrameBuffer_->Unbind();

	uint32_t width = 0;
	uint32_t height = 0;
	colorFrameBuffer_->GetSize(width, height);
	glBindImageTexture(0, colorFrameBuffer_->GetColorBufferID(), 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);
	glDispatchCompute(width, height, 1);
	glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);

	fireEffect_->Unbind();
}

void Properties::Release()
{
	if (bIsInitialized_)
	{
		if (fireEffect_)
		{
			RenderModule::DestroyResource(fireEffect_);
		}

		bIsInitialized_ = false;
	}
}