#include "TES3MiscLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Misc.h"
#include "TES3Script.h"
#include "TES3SoulGemData.h"

constexpr auto TES3_MiscItem_ctor = []()
{
	auto miscItem = mwse::tes3::malloc< TES3::Misc >();
	reinterpret_cast< void( __thiscall * )( TES3::Misc * ) >( 0x4A6320 )( miscItem );
	return miscItem;
};

namespace mwse {
	namespace lua {
		auto createMiscItem( sol::table params )
		{
			std::string id = getOptionalParam< std::string >( params, "id", {} );

			if( id.empty() || id.size() > 31 )
				throw std::invalid_argument( "tes3misc.create: 'id' parameter must be provided and less than 32 character long." );

			if( TES3::DataHandler::get()->nonDynamicData->resolveObject( id.c_str() ) != nullptr )
				throw std::invalid_argument( "tes3misc.create: 'id' parameter already assigned to an existing misc item." );

			std::string name = getOptionalParam< std::string >( params, "name", "Miscellaneous item" );
			if( name.size() > 31 )
				throw std::invalid_argument( "tes3misc.create: 'name' parameter must be less than 32 character long." );

			auto miscItem = TES3_MiscItem_ctor();

			miscItem->setID( id.c_str() );
			miscItem->setName( name.c_str() );

			auto script = getOptionalParamScript( params, "script" );

			if( script != nullptr )
				miscItem->script = script;

			auto mesh = getOptionalParam< std::string >( params, "mesh", {} );

			if( !mesh.empty() && mesh.size() < 31 )
				miscItem->setModelPath( mesh.c_str() );

			std::string icon = getOptionalParam< std::string >( params, "icon", {} );

			if( !icon.empty() && icon.size() < 31 )
				tes3::setDataString( &miscItem->icon, icon.c_str() );

			miscItem->objectFlags = getOptionalParam< double >( params, "objectFlags", 0.0 );
			miscItem->weight = getOptionalParam< double >( params, "weight", 0.0 );
			miscItem->value = getOptionalParam< double >( params, "value", 0.0 );
			miscItem->flags = getOptionalParam< double >( params, "flags", 0.0 );

			miscItem->objectFlags |= TES3::ObjectFlag::Modified;

			if( !TES3::DataHandler::get()->nonDynamicData->addNewObject( miscItem ) )
				throw std::runtime_error( "tes3misc.create: could not add the newly created misc item in its proper collection." );

			return makeLuaObject( miscItem );
		}

		void bindTES3Misc() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::SoulGemData>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Allow object to be converted to strings using their object ID.
				usertypeDefinition.set(sol::meta_function::to_string, [](TES3::SoulGemData& self) { self.id; });

				// Allow object to be serialized to json.
				usertypeDefinition.set("__tojson", [](TES3::SoulGemData& self, sol::table state) {
					std::ostringstream ss;
					ss << "\"tes3soulGemData:" << self.id << "\"";
					return ss.str();
				});

				// Basic property binding.
				usertypeDefinition.set("id", sol::readonly_property(&TES3::SoulGemData::id));
				usertypeDefinition.set("mesh", sol::readonly_property(&TES3::SoulGemData::mesh));
				usertypeDefinition.set("name", sol::readonly_property(&TES3::SoulGemData::name));
				usertypeDefinition.set("texture", sol::readonly_property(&TES3::SoulGemData::texture));
				usertypeDefinition.set("value", &TES3::SoulGemData::value);
				usertypeDefinition.set("weight", &TES3::SoulGemData::weight);

				// Data that needs to be packaged.
				usertypeDefinition.set("item", sol::readonly_property([](TES3::SoulGemData& self) { makeLuaObject(self.item); }));

				// TODO: Deprecated. Remove before 2.1-stable.
				usertypeDefinition.set("model", sol::readonly_property(&TES3::SoulGemData::mesh));

				// Finish up our usertype.
				state.set_usertype("tes3soulGemData", usertypeDefinition);
			}

			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Misc>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Item, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
				setUserdataForPhysicalObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("value", &TES3::Misc::value);
				usertypeDefinition.set("weight", &TES3::Misc::weight);

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("script", sol::readonly_property([](TES3::Misc& self) { return makeLuaObject(self.getScript()); }));

				// Functions exposed as properties.
				usertypeDefinition.set("icon", sol::property(
					&TES3::Misc::getIconPath,
					[](TES3::Misc& self, const char* value) { if (strlen(value) < 32) tes3::setDataString(&self.icon, value); }
				));
				usertypeDefinition.set("isKey", sol::property(
					[](TES3::Misc& self) { return bool(self.flags & 1); },
					[](TES3::Misc& self, bool value) {
					if (value) {
						self.flags |= 1;
					}
					else {
						self.flags &= ~1;
					}
				}
				));
				usertypeDefinition.set("isSoulGem", sol::readonly_property(&TES3::Misc::isSoulGem));
				usertypeDefinition.set("soulGemData", sol::readonly_property(&TES3::Misc::getSoulGemData));

				usertypeDefinition.set("mesh", sol::property(&TES3::Misc::getModelPath, &TES3::Misc::setModelPath));
				usertypeDefinition.set("name", sol::property(&TES3::Misc::getName, &TES3::Misc::setName));

				// TODO: Deprecated. Remove before 2.1-stable.
				usertypeDefinition.set("model", sol::property(&TES3::Misc::getModelPath, &TES3::Misc::setModelPath));

				// utility function bindings
				usertypeDefinition.set( "create", &createMiscItem );

				// Finish up our usertype.
				state.set_usertype("tes3misc", usertypeDefinition);
			}
		}
	}
}
