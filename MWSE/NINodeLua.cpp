#include "NINodeLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NIBillboardNode.h"
#include "NINode.h"

namespace mwse {
	namespace lua {
		void bindNINode() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for NI::Node.
			{
				// Start our usertype.
				auto usertypeDefinition = state.new_usertype<NI::Node>("niNode");
				usertypeDefinition["new"] = &NI::Node::create;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::AVObject, NI::ObjectNET, NI::Object>();
				setUserdataForNINode(usertypeDefinition);
			}

			// Binding for NI::BillboardNode.
			{
				// Start our usertype.
				auto usertypeDefinition = state.new_usertype<NI::BillboardNode>("niBillboardNode");
				usertypeDefinition["new"] = &NI::BillboardNode::create;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::Node, NI::AVObject, NI::ObjectNET, NI::Object>();
				setUserdataForNINode(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["mode"] = sol::property(&NI::BillboardNode::getMode, &NI::BillboardNode::setMode);

				// Basic function binding.
				usertypeDefinition["rotateToCamera"] = &NI::BillboardNode::rotateToCamera;
			}
		}
	}
}
