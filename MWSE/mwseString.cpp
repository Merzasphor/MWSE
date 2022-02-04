#include "mwseString.h"

#include "Log.h"

namespace mwse {
	constexpr auto DEBUG_STRING_CREATION = false;

	mwseString::mwseString() :
		std::string(""),
		m_ID(-1)
	{
		if constexpr (DEBUG_STRING_CREATION) {
			mwse::log::getDebug() << "mwseString: Created invalid string." << std::endl;
		}
	}

	mwseString::mwseString(long id) :
		std::string(""),
		m_ID(id)
	{
		if constexpr (DEBUG_STRING_CREATION) {
			mwse::log::getDebug() << "mwseString: Created new string of id '" << m_ID << "' with empty value." << std::endl;
		}
	}

	mwseString::mwseString(long id, const char* value) :
		std::string(value),
		m_ID(id)
	{
		if constexpr (DEBUG_STRING_CREATION) {
			mwse::log::getDebug() << "mwseString: Created new string of id '" << m_ID << "' value '" << value << "'." << std::endl;
		}
	}

	mwseString::mwseString(long id, const char* value, size_t length) :
		std::string(value, length),
		m_ID(id)
	{
		if constexpr (DEBUG_STRING_CREATION) {
			mwse::log::getDebug() << "mwseString: Created new string of id '" << m_ID << "' value '" << this->c_str() << "' (" << length << ")." << std::endl;
		}
	}

	mwseString::mwseString(long id, const std::string& value) :
		std::string(value),
		m_ID(id)
	{
		if constexpr (DEBUG_STRING_CREATION) {
			mwse::log::getDebug() << "mwseString: Created new string of id '" << m_ID << "' value '" << value << "'." << std::endl;
		}
	}

	mwseString::operator long() const {
		if (m_ID == -1) return 0;
		return m_ID;
	}

	bool mwseString::isValid() {
		return m_ID != -1;
	}

	long mwseString::getId() {
		return m_ID;
	}
}
