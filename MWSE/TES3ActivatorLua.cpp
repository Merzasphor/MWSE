#include "TES3ActivatorLua.h"

#include "LuaManager.h"

#include "TES3ObjectLua.h"

#include "TES3Activator.h"
#include "TES3Script.h"

constexpr auto TES3_Activator_ctor = []()
{
	auto activator = mwse::tes3::malloc< TES3::Activator >();
	reinterpret_cast< void( __thiscall * )( TES3::Activator * ) >( 0x49F990 )( activator );
	return activator;
};

namespace mwse {
	namespace lua {
		TES3::Activator * createActivator( sol::table params )
		{
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			auto &state = stateHandle.state;

			std::string id = getOptionalParam< std::string >( params, "id", {} );

			if( id.empty() || id.size() > 31 )
				return nullptr;

			if( TES3::DataHandler::get()->nonDynamicData->resolveObject( id.c_str() ) != nullptr )
				return nullptr;

			auto activator = TES3_Activator_ctor();

			std::string name = getOptionalParam< std::string >( params, "name", "Activator" );
			if( name.size() > 31 )
				return nullptr;

			activator->setName( name.c_str() );

			auto script = getOptionalParamScript( params, "script" );

			if( script != nullptr )
				activator->script = script;

			auto model = getOptionalParam< std::string >( params, "model", {} );

			if( !model.empty() && model.size() < 31 )
				activator->setModelPath( model.c_str() );

			activator->objectFlags = getOptionalParam< double >( params, "objectFlags", 0.0 );

			activator->objectFlags |= TES3::ObjectFlag::Modified;

			if( !TES3::DataHandler::get()->nonDynamicData->addNewObject( activator ) )
				return nullptr;

			return activator;
		}

		void bindTES3Activator() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Activator>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
			setUserdataForPhysicalObject(usertypeDefinition);

			// Functions exposed as properties.
			usertypeDefinition.set("mesh", sol::property(&TES3::Activator::getModelPath, &TES3::Activator::setModelPath));
			usertypeDefinition.set("name", sol::property(&TES3::Activator::getName, &TES3::Activator::setName));
			usertypeDefinition.set("script", sol::property(&TES3::Activator::getScript));

			// TODO: Deprecated. Remove before 2.1-stable.
			usertypeDefinition.set("model", sol::property(&TES3::Activator::getModelPath, &TES3::Activator::setModelPath));

			// utility function bindings
			usertypeDefinition.set( "create", &createActivator );

			// Finish up our usertype.
			state.set_usertype("tes3activator", usertypeDefinition);
		}
	}
}
