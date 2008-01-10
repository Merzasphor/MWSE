#pragma once

#include <ostream>;

namespace mwse
{
	namespace log
	{
		void OpenLog(const char *path);
		void CloseLog();

		std::ostream& getLog();
		std::ostream& getDebug(); //outputs to OutputDebugString
		
		std::ostream& dump(std::ostream& output, const void *data, size_t length);
		template<class T> std::ostream& dump(std::ostream& output, const T &data)
		{
			return dump(output, reinterpret_cast<const void *>(&data), sizeof(data));
		};
	}
};