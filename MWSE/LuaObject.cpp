#include "LuaObject.h"

namespace mwse::lua
{

ObjectCreatorBase *ObjectCreatorFactory::getObjectCreator( TES3::ObjectType::ObjectType objectType )
{
	switch( objectType )
	{
	case TES3::ObjectType::Activator:
		objectCreator_.reset( new ObjectCreator< TES3::Activator >() );
		break;
	case TES3::ObjectType::Misc:
		objectCreator_.reset( new ObjectCreator< TES3::Activator >() );
		break;
	case TES3::ObjectType::Static:
		objectCreator_.reset( new ObjectCreator< TES3::Activator >() );
		break;
	default:
		objectCreator_.reset( new ObjectCreator<> );
		break;
	}

	return objectCreator_.get();
}

}