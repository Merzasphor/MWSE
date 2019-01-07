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
	static_assert(sizeof(Viewport) == 0x2C, "D3D::Viewport failed size validation");

	struct Viewport8 {
		int X;
		int Y;
		int Width;
		int Height;
		int MinZ;
		int MaxZ;
	};
	static_assert(sizeof(Viewport8) == 0x18, "D3D::Viewport8 failed size validation");
}
