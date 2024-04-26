#include <glad/glad.h>

#include "Assertion.h"
#include "ColorFrameBuffer.h"

ColorFrameBuffer::ColorFrameBuffer(int32_t bufferWidth, int32_t bufferHeight)
	: width_(bufferWidth)
	, height_(bufferHeight)
{
	GL_FAILED(glGenFramebuffers(1, &framebufferID_));
	GL_FAILED(glBindFramebuffer(GL_FRAMEBUFFER, framebufferID_));

	GL_FAILED(glGenTextures(1, &colorBufferID_));
	GL_FAILED(glBindTexture(GL_TEXTURE_2D, colorBufferID_));
	GL_FAILED(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, bufferWidth, bufferHeight, 0, GL_RGBA, GL_FLOAT, nullptr));
	GL_FAILED(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GL_FAILED(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	GL_FAILED(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GL_FAILED(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GL_FAILED(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorBufferID_, 0));

	uint32_t attachment = GL_COLOR_ATTACHMENT0;
	GL_FAILED(glDrawBuffers(1, &attachment));

	GLenum state = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	CHECK(state == GL_FRAMEBUFFER_COMPLETE);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	bIsInitialized_ = true;
}

ColorFrameBuffer::~ColorFrameBuffer()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void ColorFrameBuffer::Release()
{
	CHECK(bIsInitialized_);

	GL_FAILED(glDeleteTextures(1, &colorBufferID_));
	GL_FAILED(glDeleteFramebuffers(1, &framebufferID_));

	bIsInitialized_ = false;
}

void ColorFrameBuffer::Clear(float red, float green, float blue, float alpha)
{
	glClearColor(red, green, blue, alpha);
	GL_FAILED(glClear(GL_COLOR_BUFFER_BIT));
}

void ColorFrameBuffer::Bind()
{
	GL_FAILED(glBindFramebuffer(GL_FRAMEBUFFER, framebufferID_));
}

void ColorFrameBuffer::Unbind()
{
	GL_FAILED(glBindFramebuffer(GL_FRAMEBUFFER, 0));
}

void ColorFrameBuffer::Active(uint32_t unit) const
{
	GL_FAILED(glActiveTexture(GL_TEXTURE0 + unit));
	GL_FAILED(glBindTexture(GL_TEXTURE_2D, colorBufferID_));
}