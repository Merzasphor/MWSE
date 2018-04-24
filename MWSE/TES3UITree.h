#pragma once

#include "TES3Object.h"

namespace TES3 {
	namespace UI {
		struct TreeNode {
			TreeNode * branchLess;
			void * data;
			TreeNode * branchGreaterThanOrEqual;
			short key;
		};
		static_assert(sizeof(TreeNode) == 0x10, "TES3::UI::TreeNode failed size validation");

		struct Tree {
			char tag;
			TreeNode * root;
		};
		static_assert(sizeof(Tree) == 0x8, "TES3::UI::Tree failed size validation");
	}
}
