#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#error "not support platform"
#endif

#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"
#include "Mat4x4.h"

#include "IResource.h"


/**
 * @brief ������ ���� ó���� �����ϴ� ����Դϴ�.
 * 
 * @note �� Ŭ������ ��� ��� ������ �޼���� ��� ����(static) Ÿ���Դϴ�.
 */
class RenderModule
{
public:
	/**
	 * @brief ���� ����� ���� ó�� ����Դϴ�.
	 */
	enum class Errors
	{
		OK            = 0x00, // ������ �����ϴ�.
		FAILED        = 0x01, // �Ϲ����� �����Դϴ�.
		ERR_WIN       = 0x02, // Windows �����Դϴ�.
		ERR_WGL       = 0x03, // Windows GL �����Դϴ�.
		ERR_GL        = 0x04, // OpenGL �����Դϴ�.
		ERR_PREV_INIT = 0x05, // ������ �ʱ�ȭ�� �����߽��ϴ�.
		ERR_NOT_INIT  = 0x06, // �ʱ�ȭ�� ������� �ʾҽ��ϴ�.
		ERR_IMGUI     = 0x07, // IMGUI ���� �����Դϴ�.
	};


public:
	/**
	 * @brief ���� ����� �ʱ�ȭ�մϴ�.
	 * 
	 * @param windowHandle ������ ����� �Ǵ� ������ �ڵ��Դϴ�.
	 * 
	 * @return �ʱ�ȭ�� �����ϸ� Errors �������� OK ����, �׷��� ������ �� ���� ���� ��ȯ�մϴ�.
	 */
	static Errors Init(HWND windowHandle);


	/**
	 * @brief ���� ����� �ʱ�ȭ�� �����մϴ�.
	 * 
	 * @return �ʱ�ȭ ������ �����ϸ� Errors �������� OK ����, �׷��� ������ �� ���� ���� ��ȯ�մϴ�.
	 */
	static Errors Uninit();


	/**
	 * @brief ������ �������� �����մϴ�.
	 *
	 * @param red ���� ������ R ���Դϴ�.
	 * @param green ���� ������ G ���Դϴ�.
	 * @param blue ���� ������ B ���Դϴ�.
	 * @param alpha ���� ������ A ���Դϴ�.
	 * @param depth ���� ������ �ʱ�ȭ ���Դϴ�.
	 * @param stencil ���ٽ� ������ �ʱ�ȭ ���Դϴ�.
	 */
	static void BeginFrame(float red, float green, float blue, float alpha, float depth = 1.0f, uint8_t stencil = 0);


	/**
	 * @brief ����ۿ� ����Ʈ ���۸� �����մϴ�.
	 * 
	 * @return ����ۿ� ����Ʈ ������ ���ҿ� �����ϸ� Errors �������� OK ����, �׷��� ������ �� ���� ���� ��ȯ�մϴ�.
	 */
	static void EndFrame();


	/**
	 * @brief �� ��Ʈ�� �����մϴ�.
	 *
	 * @param x ����Ʈ �簢���� ���� �Ʒ� �𼭸�(�ȼ�)�Դϴ�. �⺻���� (0,0)�Դϴ�.
	 * @param y ����Ʈ �簢���� ���� �Ʒ� �𼭸�(�ȼ�)�Դϴ�. �⺻���� (0,0)�Դϴ�.
	 * @param width ����Ʈ�� �ʺ��Դϴ�. OpenGL ���ؽ�Ʈ�� â�� ó�� ����Ǹ� �ʺ� �� ���� �� �ش� â�� ũ��� �����˴ϴ�.
	 * @param height ����Ʈ�� �����Դϴ�. OpenGL ���ؽ�Ʈ�� â�� ó�� ����Ǹ� �ʺ� �� ���� �� �ش� â�� ũ��� �����˴ϴ�.
	 */
	static void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height);


	/**
	 * @brief ������ �� ��Ʈ�� �����մϴ�.
	 */
	static void SetWindowViewport();


	/**
	 * @brief ���� ����ȭ �ɼ��� �����մϴ�.
	 *
	 * @param bIsEnable ���� ����ȭ �ɼ��� Ȱ��ȭ�Ϸ��� true, ��Ȱ��ȭ�Ϸ��� false�Դϴ�.
	 */
	static void SetVsyncMode(bool bIsEnable);


	/**
	 * @brief ���� �׽�Ʈ �ɼ��� �����մϴ�.
	 *
	 * @param bIsEnable ���� �׽�Ʈ �ɼ��� Ȱ��ȭ�Ϸ��� true, ��Ȱ��ȭ�Ϸ��� false�Դϴ�.
	 */
	static void SetDepthMode(bool bIsEnable);


	/**
	 * @brief ���ٽ� �׽�Ʈ �ɼ��� �����մϴ�.
	 *
	 * @param bIsEnable ���ٽ� �׽�Ʈ �ɼ��� Ȱ��ȭ�Ϸ��� true, ��Ȱ��ȭ�Ϸ��� false�Դϴ�.
	 */
	static void SetStencilMode(bool bIsEnable);


	/**
	 * @brief ���� ������ �ɼ��� �����մϴ�.
	 *
	 * @param bIsEnable ���� ������ �ɼ��� Ȱ��ȭ�Ϸ��� true, ��Ȱ��ȭ�Ϸ��� false�Դϴ�.
	 */
	static void SetAlphaBlendMode(bool bIsEnable);


	/**
	 * @brief ��Ƽ ���ø� �ɼ��� �����մϴ�.
	 *
	 * @param bIsEnable ��Ƽ ���ø� �ɼ��� Ȱ��ȭ�Ϸ��� true, ��Ȱ��ȭ�Ϸ��� false�Դϴ�.
	 */
	static void SetMultisampleMode(bool bIsEnable);


	/**
	 * @brief ���̴��� ����Ʈ ũ�� �ɼ��� �����մϴ�.
	 *
	 * @param bIsEnabel ����Ʈ ũ�� �ɼ��� Ȱ��ȭ�Ϸ��� true, �׷��� ������ false�Դϴ�.
	 */
	static void SetPointSizeMode(bool bIsEnable);


	/**
	 * @brief ���ҽ��� �����մϴ�.
	 *
	 * @param args ���ҽ��� �����ڿ� ������ ���ڵ��Դϴ�.
	 *
	 * @return ������ ���ҽ��� �����͸� ��ȯ�մϴ�. ���ҽ� ������ �����ϸ� nullptr�� ��ȯ�մϴ�.
	 */
	template <typename TResource, typename... Args>
	static TResource* CreateResource(Args&&... args)
	{
		if (!(0 <= cacheSize && cacheSize < MAX_RESOURCE_SIZE))
		{
			return nullptr;
		}

		int32_t resourceID = -1;
		for (uint32_t index = 0; index < cacheSize; ++index)
		{
			if (!cache[index])
			{
				resourceID = static_cast<int32_t>(index);
				break;
			}
		}

		if (resourceID == -1)
		{
			resourceID = cacheSize++;
		}

		cache[resourceID] = std::make_unique<TResource>(args...);
		return reinterpret_cast<TResource*>(cache[resourceID].get());
	}


	/**
	 * @brief ���ҽ� �Ŵ����� �����ϴ� ���ҽ��� �����մϴ�.
	 *
	 * @param resourceID ������ ���ҽ� ID�Դϴ�.
	 */
	static void DestroyResource(const IResource* resource)
	{
		int32_t resourceID = -1;
		for (uint32_t index = 0; index < cacheSize; ++index)
		{
			IResource* cacheResource = cache[index].get();
			if (resource == cacheResource)
			{
				resourceID = static_cast<int32_t>(index);
				break;
			}
		}

		if (resourceID != -1)
		{
			if (cache[resourceID] && cache[resourceID]->IsInitialized())
			{
				cache[resourceID]->Release();
				cache[resourceID].reset();
			}
		}
	}


	/**
	 * @brief ��ũ�� ũ�⸦ ����ϴ�.
	 *
	 * @param outWidth ��ũ���� ���� ũ���Դϴ�.
	 * @param outHeight ��ũ���� ���� ũ���Դϴ�.
	 *
	 * @return ��ũ�� ũ�⸦ ��� �� �����ϸ� Errors �������� OK ����, �׷��� ������ �� ���� ���� ��ȯ�մϴ�.
	 */
	static Errors GetScreenSize(int32_t& outWidth, int32_t& outHeight);


	/**
	 * @brief ���� ����� ���� �ֱ� ���� �޽����� ����ϴ�.
	 *
	 * @return ���� ����� ���� �ֱٿ� �߻��� ���� �޽����� ������ ���� ��ȯ�մϴ�.
	 */
	static const wchar_t* GetLastErrorMessage();


private:
	/**
	 * @brief ���� �޽����� �����մϴ�.
	 *
	 * @param message ������ �޽����Դϴ�.
	 */
	static void SetLastErrorMessage(const std::wstring& message);


	/**
	 * @brief Windows���� �޽����� �����մϴ�.
	 *
	 * @note ������ �������� ������ �ƹ� ���۵� �������� �ʽ��ϴ�.
	 */
	static void SetLastWindowsErrorMessage();


	/**
	 * @brief WindowsȮ�� OpenGL�� �ʱ�ȭ�մϴ�.
	 * 
	 * @return WindowsȮ�� OpenGL �ʱ�ȭ�� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static Errors SetupWGLExtensions();


	/**
	 * @brief Windows GL ���ؽ�Ʈ�� �����մϴ�.
	 * 
	 * @return Windows GL ���ؽ�Ʈ ������ �����ϸ� Errors �������� OK ����, �׷��� ������ �� ���� ���� ��ȯ�մϴ�.
	 */
	static Errors CreateWGLContext();


private:
	/**
	 * @brief ���� ����� �ʱ�ȭ�� ���� �ִ��� Ȯ���մϴ�.
	 */
	static bool bIsInit;


	/**
	 * @brief ������ ����� �Ǵ� ������ �ڵ��Դϴ�.
	 */
	static HWND renderTargetHandle;


	/**
	 * @brief �������� ����� ����̽� ���ؽ�Ʈ�� �ڵ��Դϴ�.
	 */
	static HDC deviceContext;


	/**
	 * @brief �������� ����� OpenGL ���ؽ�Ʈ�� �ڵ��Դϴ�.
	 */
	static HGLRC glRenderContext;


	/**
	 * @brief ��ũ���� �����ϴ� ���� ���� ����Դϴ�.
	 */
	static Mat4x4 ortho;


	/**
	 * @brief ���ڿ� ������ �ִ� ũ���Դϴ�.
	 */
	static const uint32_t MAX_BUFFER_SIZE = 1024;


	/**
	 * @brief �ֱ� ���� �޽����Դϴ�.
	 */
	static wchar_t lastErrorMessage[MAX_BUFFER_SIZE];


	/**
	 * @brief ������ �� �ִ� �ִ� ���ҽ� ���Դϴ�.
	 */
	static const uint32_t MAX_RESOURCE_SIZE = 200;


	/**
	 * @brief ĳ�� ũ���Դϴ�.
	 */
	static uint32_t cacheSize;


	/**
	 * @brief ���� ���ҽ��� ĳ���Դϴ�.
	 */
	static std::array<std::unique_ptr<IResource>, MAX_RESOURCE_SIZE> cache;
};