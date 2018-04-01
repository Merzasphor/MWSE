#include "StackLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "Stack.h"
#include "mwAdapter.h"
#include "VirtualMachine.h"

namespace mwse {
	namespace lua {
		void bindMWSEStack() {
			sol::state& state = LuaManager::getInstance().getState();

			state["mwse"]["stack"] = state.create_table();

			//
			// Functions for pushing values.
			//

			state["mwse"]["stack"]["pushShort"] = [](double value) {
				Stack::getInstance().pushShort(value);
			};

			state["mwse"]["stack"]["pushLong"] = [](double value) {
				Stack::getInstance().pushLong(value);
			};

			state["mwse"]["stack"]["pushFloat"] = [](double value) {
				Stack::getInstance().pushFloat(value);
			};

			state["mwse"]["stack"]["pushString"] = [](std::string& value) {
				Stack::getInstance().pushString(value);
			};

			state["mwse"]["stack"]["pushObject"] = [](sol::object value) {
				Stack::getInstance().pushLong((long)value.as<void*>());
			};

			//
			// Functions for popping values.
			//

			state["mwse"]["stack"]["popShort"] = []() {
				return Stack::getInstance().popShort();
			};

			state["mwse"]["stack"]["popLong"] = []() {
				return Stack::getInstance().popLong();
			};

			state["mwse"]["stack"]["popFloat"] = []() {
				return Stack::getInstance().popFloat();
			};

			state["mwse"]["stack"]["popString"] = []() {
				return mwAdapter::GetVMInstance()->getString(Stack::getInstance().popLong()).c_str();
			};

			state["mwse"]["stack"]["popObject"] = []() {
				return lua::makeLuaObject(reinterpret_cast<TES3::BaseObject*>(Stack::getInstance().popLong()));
			};

			//
			// Other stack functions.
			//

			state["mwse"]["stack"]["empty"] = []() {
				return Stack::getInstance().empty();
			};

			state["mwse"]["stack"]["size"] = []() {
				return Stack::getInstance().size();
			};

			state["mwse"]["stack"]["clear"] = []() {
				Stack::getInstance().clear();
			};

		}
	}
}
