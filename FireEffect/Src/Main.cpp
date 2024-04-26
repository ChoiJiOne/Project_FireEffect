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

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
	PlatformModule::WindowConstructParams windowParam { L"FireEffect", 100, 100, 1000, 800, false, false };

	CrashModule::Init();
	PlatformModule::Init(windowParam);
	PlatformModule::SetEndLoopCallback([&]() { RenderModule::Uninit(); });
	RenderModule::Init(PlatformModule::GetWindowHandle());

	RenderModule::SetDepthMode(false);
	RenderModule::SetPointSizeMode(true);

	Shader* fireEffect = RenderModule::CreateResource<Shader>("Shader/FireEffect.comp");

	int32_t width = 600;
	int32_t height = 600;
	ColorFrameBuffer* colorFrameBuffer = RenderModule::CreateResource<ColorFrameBuffer>(width, height);

	float a = 0.0f;
	float b = 0.0f;
	float c = 0.0f;
	
	PlatformModule::RunLoop(
		[&](float deltaSeconds)
		{
			ImGui::Begin("Effect", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
			{
				ImGui::SetWindowPos(ImVec2(0.0f, 0.0f));
				ImGui::SetWindowSize(ImVec2(700.0f, 800.0f));
				ImVec2 uv0 = ImVec2(0.0f, 1.0f); // 텍스처 좌측 상단
				ImVec2 uv1 = ImVec2(1.0f, 0.0f); // 텍스처 우측 하단

				ImGui::Image((void*)(intptr_t)(colorFrameBuffer->GetColorBufferID()), ImVec2(600.0f, 600.0f), uv0, uv1);
			}
			ImGui::End();

			ImGui::Begin("Properties", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
			{
				ImGui::SetWindowPos(ImVec2(700.0f, 0.0f));
				ImGui::SetWindowSize(ImVec2(300.0f, 800.0f));

				ImGui::Text("Random");
				ImGui::SliderFloat("a", &a, 0.0f, 25.0f);
				ImGui::SliderFloat("b", &b, 0.0f, 150.0f);
				ImGui::SliderFloat("c", &c, 0.0f, 100000.0f);
			}
			ImGui::End();
			
			RenderModule::BeginFrame(1.0f, 1.0f, 1.0f, 1.0f);

			fireEffect->Bind();
			{
				fireEffect->SetUniform("a", a);
				fireEffect->SetUniform("b", b);
				fireEffect->SetUniform("c", c);

				colorFrameBuffer->Clear(0.0f, 0.0f, 0.0f, 0.0f);
				glBindImageTexture(0, colorFrameBuffer->GetColorBufferID(), 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);
				glDispatchCompute(width, height, 1);
				glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
			}
			fireEffect->Unbind();

			RenderModule::EndFrame();
		}
	);
	
	PlatformModule::Uninit();
	CrashModule::Uninit();
	return 0;
}