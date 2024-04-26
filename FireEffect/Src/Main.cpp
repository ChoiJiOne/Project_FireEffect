#include <cstdint>
#include <Windows.h>

#include <glad/glad.h>
#include <imgui.h>

#include "CrashModule.h"
#include "MathModule.h"
#include "PlatformModule.h"
#include "RenderModule.h"
#include "Shader.h"
#include "ColorFrameBuffer.h"
#include "GameTimer.h"
#include "FireEffect.h"
#include "EntityManager.h"

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
	PlatformModule::WindowConstructParams windowParam { L"FireEffect", 100, 100, 1000, 800, false, false };

	CrashModule::Init();
	PlatformModule::Init(windowParam);
	PlatformModule::SetEndLoopCallback([&]() { RenderModule::Uninit(); });
	RenderModule::Init(PlatformModule::GetWindowHandle());

	RenderModule::SetDepthMode(false);
	RenderModule::SetPointSizeMode(true);

	EntityManager::Get().Startup();

	Shader* fireEffect = RenderModule::CreateResource<Shader>("Shader/FireEffect.comp");

	int32_t width = 900;
	int32_t height = 900;
	ColorFrameBuffer* colorFrameBuffer = RenderModule::CreateResource<ColorFrameBuffer>(width, height);
	
	Vec2f fireMovement = Vec2f(-0.01f, -0.5f);
	Vec2f distortionMovement = Vec2f(-0.01f, -0.3f);
	float normalStrength = 40.0f;

	FireEffect* effect = EntityManager::Get().CreateEntity<FireEffect>(colorFrameBuffer);

	GameTimer timer;
	timer.Reset();

	PlatformModule::RunLoop(
		[&](float deltaSeconds)
		{
			timer.Tick();

			effect->Tick(deltaSeconds);

			ImGui::Begin("Properties", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
			{
				ImGui::SetWindowPos(ImVec2(700.0f, 0.0f));
				ImGui::SetWindowSize(ImVec2(300.0f, 800.0f));
				ImGui::SliderFloat2("fireMovement", fireMovement.data, -1.0f, 1.0f);
				ImGui::SliderFloat2("distortionMovement", distortionMovement.data, -1.0f, 1.0f);
				ImGui::SliderFloat("normalStrength", &normalStrength, 0.0f, 100.0f);
			}
			ImGui::End();
			
			RenderModule::BeginFrame(1.0f, 1.0f, 1.0f, 1.0f);

			fireEffect->Bind();
			{
				fireEffect->SetUniform("time", timer.GetTotalSeconds());
				fireEffect->SetUniform("fireMovement", fireMovement);
				fireEffect->SetUniform("distortionMovement", distortionMovement);
				fireEffect->SetUniform("normalStrength", normalStrength);

				colorFrameBuffer->Bind();
				colorFrameBuffer->Clear(0.0f, 0.0f, 0.0f, 0.0f);
				glBindImageTexture(0, colorFrameBuffer->GetColorBufferID(), 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);
				glDispatchCompute(width, height, 1);
				glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
				colorFrameBuffer->Unbind();
			}
			fireEffect->Unbind();

			RenderModule::EndFrame();
		}
	);

	EntityManager::Get().Shutdown();

	PlatformModule::Uninit();
	CrashModule::Uninit();
	return 0;
}