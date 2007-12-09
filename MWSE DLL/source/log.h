#include <ostream>

namespace mwse {
  namespace log {
    void openLog(const char *path);
    std::ostream& getLog();

    std::ostream& getDebug();    // output to OutputDebugString

    std::ostream &dump(std::ostream& output, const void *data, size_t length);
    template<class T> std::ostream& dump(std::ostream &output, const T &data)
    {
        return dump(output, reinterpret_cast<const void *>(&data), sizeof(data));
    };
    void closeLog();
  }
};
