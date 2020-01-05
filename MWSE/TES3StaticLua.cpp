#include "TES3StaticLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Static.h"

constexpr auto TES3_Static_ctor = []()
{
	auto staticObject = mwse::tes3::malloc< TES3::Static >();
	reinterpret_cast< void( __thiscall * )( TES3::Static * ) >( 0x4A72D0 )( staticObject );
	return staticObject;
};

namespace mwse {
	namespace lua {
		TES3::Static * createStatic( sol::table params )
		{
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			auto &state = stateHandle.state;

			std::string id = getOptionalParam< std::string >( params, "id", {} );

			if( id.empty() || id.size() > 31 )
				return nullptr;

			if( TES3::DataHandler::get()->nonDynamicData->resolveObject( id.c_str() ) != nullptr )
				return nullptr;

			auto staticObject = TES3_Static_ctor();

			staticObject->setID( id.c_str() );

			auto mesh = getOptionalParam< std::string >( params, "mesh", {} );

			if( !mesh.empty() && mesh.size() < 31 )
				staticObject->setModelPath( mesh.c_str() );

			staticObject->objectFlags = getOptionalParam< double >( params, "objectFlags", 0.0 );

			staticObject->objectFlags |= TES3::ObjectFlag::Modified;

			if( !TES3::DataHandler::get()->nonDynamicData->addNewObject( staticObject ) )
				return nullptr;

			return staticObject;
		}

		void bindTES3Static() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Static>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
			setUserdataForPhysicalObject(usertypeDefinition);

			// Functions exposed as properties.
			usertypeDefinition.set("mesh", sol::property(&TES3::Static::getModelPath, &TES3::Static::setModelPath));

			// TODO: Deprecated. Remove before 2.1-stable.
			usertypeDefinition.set("model", sol::property(&TES3::Static::getModelPath, &TES3::Static::setModelPath));

			// utility function bindings
			usertypeDefinition.set( "create", &createStatic );

			// Finish up our usertype.
			state.set_usertype("tes3static", usertypeDefinition);
		}
	}
}
