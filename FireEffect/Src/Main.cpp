#include <cstdint>
#include <Windows.h>

#include <glad/glad.h>
#include <imgui.h>

#include "CrashModule.h"
#include "MathModule.h"
#include "PlatformModule.h"
#include "RenderModule.h"
#include "Shader.h"

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
	PlatformModule::WindowConstructParams windowParam { L"FireEffect", 100, 100, 1000, 800, false, false };

	CrashModule::Init();
	PlatformModule::Init(windowParam);
	PlatformModule::SetEndLoopCallback([&]() { RenderModule::Uninit(); });
	RenderModule::Init(PlatformModule::GetWindowHandle());

	RenderModule::SetDepthMode(false);
	RenderModule::SetPointSizeMode(true);

	PlatformModule::RunLoop(
		[&](float deltaSeconds)
		{
			ImGui::Begin("Effect", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
			{
				ImGui::SetWindowPos(ImVec2(0.0f, 0.0f));
				ImGui::SetWindowSize(ImVec2(700.0f, 800.0f));
			}
			ImGui::End();

			ImGui::Begin("Properties", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
			{
				ImGui::SetWindowPos(ImVec2(700.0f, 0.0f));
				ImGui::SetWindowSize(ImVec2(300.0f, 800.0f));
			}
			ImGui::End();

			RenderModule::BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
			RenderModule::EndFrame();
		}
	);
	
	PlatformModule::Uninit();
	CrashModule::Uninit();
	return 0;
}