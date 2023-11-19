#include "rendererapi.h"

#include "platform/metal/metalrendererapi.h"

void RendererApi::init()
{
    MetalRendererApi::init();
}

void RendererApi::shutdown()
{
    MetalRendererApi::shutdown();
}

void RendererApi::clear(const glm::vec4& color)
{
    MetalRendererApi::clear(color);
}

void RendererApi::updateViewport(int width, int height)
{
    MetalRendererApi::updateViewport(width, height);
}
