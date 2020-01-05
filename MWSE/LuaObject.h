#pragma once

#include "sol.hpp"

#include "LuaUtil.h"
#include "TES3Util.h"

#include "TES3Activator.h"
#include "TES3Misc.h"
#include "TES3Static.h"

namespace mwse::lua
{

class ObjectCreatorBase
{
public:
	virtual sol::object create( sol::table, bool ) const = 0;

protected:
	template< typename ObjectType >
	static auto constructObjectFromConstructorAddress( int ctorAddress )
	{
		auto instance = mwse::tes3::malloc< ObjectType >();

		auto ctor = reinterpret_cast< void( __thiscall * )( ObjectType * ) >( ctorAddress );
		ctor( instance );

		return instance;
	}
};

template< typename ObjectType = void >
class ObjectCreator : public ObjectCreatorBase
{
public:
	using ObjectCreatorBase::ObjectCreatorBase;

	sol::object create( sol::table, bool ) const override
	{
		throw std::runtime_error{ "Cannot create an object of that type." };
	}
};

template<>
class ObjectCreator< TES3::Activator > : public ObjectCreatorBase
{
public:
	using ObjectCreatorBase::ObjectCreatorBase;

	sol::object create( sol::table params, bool getIfExists ) const override
	{
		std::string id = getOptionalParam< std::string >( params, "id", {} );

		if( id.empty() || id.size() > 31 )
			throw std::invalid_argument( "tes3activator.create: 'id' parameter must be provided and less than 32 character long." );


		if( auto existingObject = TES3::DataHandler::get()->nonDynamicData->resolveObject( id.c_str() ); existingObject != nullptr )
			return getIfExists ? makeLuaObject( existingObject ) : throw std::invalid_argument( "tes3activator.create: 'id' parameter already assigned to an existing activator." );

		std::string name = getOptionalParam< std::string >( params, "name", "Activator" );
		if( name.size() > 31 )
			throw std::invalid_argument( "tes3activator.create: 'name' parameter must be less than 32 character long." );

		auto activator = constructObjectFromConstructorAddress< TES3::Activator >( TES3_Activator_ctor );

		activator->setID( id.c_str() );
		activator->setName( name.c_str() );

		auto script = getOptionalParamScript( params, "script" );

		if( script != nullptr )
			activator->script = script;

		auto mesh = getOptionalParam< std::string >( params, "mesh", {} );

		if( !mesh.empty() && mesh.size() < 31 )
			activator->setModelPath( mesh.c_str() );

		activator->objectFlags = getOptionalParam< double >( params, "objectFlags", 0.0 );

		activator->objectFlags |= TES3::ObjectFlag::Modified;

		if( !TES3::DataHandler::get()->nonDynamicData->addNewObject( activator ) )
			throw std::runtime_error( "tes3activator.create: could not add the newly created activator in its proper collection." );

		return makeLuaObject( activator );
	}

private:
	static constexpr auto TES3_Activator_ctor = 0x49F990;
};

template<>
class ObjectCreator< TES3::Misc > : public ObjectCreatorBase
{
public:
	using ObjectCreatorBase::ObjectCreatorBase;

	sol::object create( sol::table params, bool getIfExists ) const override
	{
		std::string id = getOptionalParam< std::string >( params, "id", {} );

		if( id.empty() || id.size() > 31 )
			throw std::invalid_argument( "tes3misc.create: 'id' parameter must be provided and less than 32 character long." );

		if( auto existingObject = TES3::DataHandler::get()->nonDynamicData->resolveObject( id.c_str() ); existingObject != nullptr )
			return getIfExists ? makeLuaObject( existingObject ) : throw std::invalid_argument( "tes3misc.create: 'id' parameter already assigned to an existing misc item." );

		std::string name = getOptionalParam< std::string >( params, "name", "Miscellaneous item" );
		if( name.size() > 31 )
			throw std::invalid_argument( "tes3misc.create: 'name' parameter must be less than 32 character long." );

		auto miscItem = constructObjectFromConstructorAddress< TES3::Misc >( TES3_MiscItem_ctor );

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

private:
	static constexpr auto TES3_MiscItem_ctor = 0x4A6320;
};

template<>
class ObjectCreator< TES3::Static > : public ObjectCreatorBase
{
public:
	using ObjectCreatorBase::ObjectCreatorBase;

	sol::object create( sol::table params, bool getIfExists ) const override
	{
		std::string id = getOptionalParam< std::string >( params, "id", {} );

		if( id.empty() || id.size() > 31 )
			throw std::invalid_argument( "tes3static.create: 'id' parameter must be provided and less than 32 character long." );

		if( auto existingObject = TES3::DataHandler::get()->nonDynamicData->resolveObject( id.c_str() ); existingObject != nullptr )
			return getIfExists ? makeLuaObject( existingObject ) : throw std::invalid_argument( "tes3static.create: 'id' parameter already assigned to an existing static." );

		auto staticObject = constructObjectFromConstructorAddress< TES3::Static >( TES3_Static_ctor );

		staticObject->setID( id.c_str() );

		auto mesh = getOptionalParam< std::string >( params, "mesh", {} );

		if( !mesh.empty() && mesh.size() < 31 )
			staticObject->setModelPath( mesh.c_str() );

		staticObject->objectFlags = getOptionalParam< double >( params, "objectFlags", 0.0 );

		staticObject->objectFlags |= TES3::ObjectFlag::Modified;

		if( !TES3::DataHandler::get()->nonDynamicData->addNewObject( staticObject ) )
			throw std::runtime_error( "tes3static.create: could not add the newly created static in its proper collection." );

		return makeLuaObject( staticObject );
	}

private:
	static constexpr auto TES3_Static_ctor = 0x4A72D0;
};

class ObjectCreatorFactory
{
public:

	ObjectCreatorBase *getObjectCreator( TES3::ObjectType::ObjectType objectType );

private:
	std::unique_ptr< ObjectCreatorBase > objectCreator_;
};

}
