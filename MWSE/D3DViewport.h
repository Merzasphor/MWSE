#pragma once

namespace D3D {
	struct Viewport {
		int size;
		int x;
		int y;
		int width;
		int height;
		float scaleX;
		float scaleY;
		float maxX;
		float maxY;
		float minZ;
		float maxZ;
	};
	static_assert(sizeof(Viewport) == 0x2C, "TES3::Viewport failed size validation");

	struct Viewport8 {
		int X;
		int Y;
		int Width;
		int Height;
		int MinZ;
		int MaxZ;
	};
	static_assert(sizeof(Viewport8) == 0x18, "TES3::Viewport8 failed size validation");
}
