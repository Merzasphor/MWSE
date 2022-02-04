#pragma once

namespace mwse {
	/*
		A string implementation for mwse. Derived from std::string; however, the strings
		can also be identified by a value stored as a long. This value is an ID;
		invalid IDs will cause exceptions.

		Because strings are exclusively referenced by this ID, this class shouldn't
		be instantiated frequently. Instead, the lookup() and get() functions should
		be used to get a mutable reference to the string.
	*/
	class mwseString : public std::string {
	public:
		// Constructor for an invalid string.
		mwseString();

		// Constructs a new mwseString 
		mwseString(long id);

		// 
		mwseString(long id, const char* value);

		// 
		mwseString(long id, const char* value, size_t length);

		// 
		mwseString(long id, const std::string& value);

		// Get only the id of the string.
		operator long() const;

		// Determines if the string has a valid ID.
		bool isValid();

		// Get the ID of the string.
		long getId();

	private:
		// Unique identifier for the string, used to identify strings back to mwscript.
		long m_ID;
	};
};
