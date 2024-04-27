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
	fireEffect_ = RenderModule::CreateResource<Shader>("Resource/Shader/FireEffect.comp");
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

	ImGui::Text("Fire Movement");
	ImGui::SliderFloat2("Fire", fireMovement_.data, -1.0f, 1.0f);
	
	ImGui::Text("Distortion Movement");
	ImGui::SliderFloat2("Distortion", distortionMovement_.data, -1.0f, 1.0f);

	ImGui::Text("Normal Strength");
	ImGui::SliderFloat("Normal", &normalStrength_, 0.0f, 100.0f);

	if (ImGui::Button("Reset"))
	{
		fireMovement_ = Vec2f(-0.01f, -0.5f);
		distortionMovement_ = Vec2f(-0.01f, -0.3f);
		normalStrength_ = 40.0f;
	}

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
	glDispatchCompute(width / 9, height / 9, 1);
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
