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

	Shader* fireEffect = RenderModule::CreateResource<Shader>("Shader/FireEffect.comp");

	uint32_t width = 700;
	uint32_t height = 700;
	uint32_t image[1];
	glGenTextures(1, image);
	for (uint32_t index = 0; index < 1; ++index)
	{
		glBindTexture(GL_TEXTURE_2D, image[index]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_FLOAT, nullptr);
		glTextureParameteri(image[index], GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(image[index], GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTextureParameteri(image[index], GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTextureParameteri(image[index], GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	PlatformModule::RunLoop(
		[&](float deltaSeconds)
		{
			ImGui::Begin("Effect", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
			{
				ImGui::SetWindowPos(ImVec2(0.0f, 0.0f));
				ImGui::SetWindowSize(ImVec2(700.0f, 800.0f));
				ImVec2 uv0 = ImVec2(0.0f, 1.0f); // 텍스처 좌측 상단
				ImVec2 uv1 = ImVec2(1.0f, 0.0f); // 텍스처 우측 하단

				ImGui::Image((void*)(intptr_t)(image[0]), ImVec2(700.0f, 700.0f), uv0, uv1);
			}
			ImGui::End();

			ImGui::Begin("Properties", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
			{
				ImGui::SetWindowPos(ImVec2(700.0f, 0.0f));
				ImGui::SetWindowSize(ImVec2(300.0f, 800.0f));
			}
			ImGui::End();

			fireEffect->Bind();
			{
				glBindImageTexture(0, image[0], 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);
				glDispatchCompute(width, height, 1);
				glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
			}
			fireEffect->Unbind();

			RenderModule::BeginFrame(1.0f, 1.0f, 1.0f, 1.0f);
			RenderModule::EndFrame();
		}
	);

	glDeleteTextures(1, image);

	PlatformModule::Uninit();
	CrashModule::Uninit();
	return 0;
}