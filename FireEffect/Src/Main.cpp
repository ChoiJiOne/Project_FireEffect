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
#include "Properties.h"

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

	int32_t width = 900;
	int32_t height = 900;
	ColorFrameBuffer* colorFrameBuffer = RenderModule::CreateResource<ColorFrameBuffer>(width, height);
	
	FireEffect* effect = EntityManager::Get().CreateEntity<FireEffect>(colorFrameBuffer);
	Properties* properties = EntityManager::Get().CreateEntity<Properties>(colorFrameBuffer);

	PlatformModule::RunLoop(
		[&](float deltaSeconds)
		{
			effect->Tick(deltaSeconds);
			properties->Tick(deltaSeconds);

			RenderModule::BeginFrame(1.0f, 1.0f, 1.0f, 1.0f);

			effect->Render();
			properties->Render();

			RenderModule::EndFrame();
		}
	);

	EntityManager::Get().Shutdown();

	PlatformModule::Uninit();
	CrashModule::Uninit();
	return 0;
}