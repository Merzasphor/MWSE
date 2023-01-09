#include "NIRenderedTexture.h"

#include "NIDX8Renderer.h"
#include "NIDX8TextureData.h"
#include "NIPixelData.h"
#include "TES3WorldController.h"

namespace NI {
	const auto NI_RenderedTexture_create = reinterpret_cast<RenderedTexture* (__cdecl*)(unsigned int, unsigned int, Renderer*, Texture::FormatPrefs*)>(0x6DC090);
	RenderedTexture* RenderedTexture::create(unsigned int width, unsigned int height) {
		auto renderer = TES3::WorldController::get()->renderer;
		auto prefs = Texture::FormatPrefs::DEFAULT_PREFS;
		auto texture = NI_RenderedTexture_create(width, height, renderer, prefs);
		return texture;
	}

	//
	// Copies the render target contents from the GPU into CPU accessible pixelData.
	//
	bool RenderedTexture::readback(NI::PixelData* pixelData) {
		auto renderer = static_cast<NI::DX8Renderer*>(TES3::WorldController::get()->renderer);
		bool success = false;

		if (pixelData == nullptr) {
			return false;
		}

		// Check source and dest sizes match.
		if (pixelData->getWidth() != width && pixelData->getHeight() != height) {
			return false;
		}

		IDirect3DTexture8* rtTexture = static_cast<DX8RenderedTextureData*>(rendererData)->d3dTexture;
		IDirect3DSurface8* rtSurface = nullptr;
		IDirect3DSurface8* readbackSurface = nullptr;

		// Create system memory surface to copy to.
		D3DSURFACE_DESC surfaceDesc;
		rtTexture->GetSurfaceLevel(0, &rtSurface);
		rtSurface->GetDesc(&surfaceDesc);
		renderer->d3dDevice->CreateImageSurface(width, height, surfaceDesc.Format, &readbackSurface);

		if (renderer->d3dDevice->CopyRects(rtSurface, nullptr, 0, readbackSurface, nullptr) == D3D_OK) {
			D3DLOCKED_RECT lock;
			if (readbackSurface->LockRect(&lock, nullptr, D3DLOCK_NOSYSLOCK | D3DLOCK_READONLY) == D3D_OK) {
				// Copy from system memory surface to pixelData.
				memcpy(pixelData->pixels, lock.pBits, pixelData->offsets[1] - pixelData->offsets[0]);
				success = true;
			}
		}

		readbackSurface->Release();
		rtSurface->Release();

		return success;
	}
}
