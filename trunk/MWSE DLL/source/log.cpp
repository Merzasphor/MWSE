#include "log.h"
#include <fstream>
#include <ostream>
#include <sstream>
#include <iostream>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace  mwse;
using namespace  log;
using namespace  std;

#ifndef _WIN32
static void OutputDebugStringA(const char *s)
{
    cerr << s << endl;
}
static void OutputDebugStringW(const char *s)
{
    cerr << s << endl;
}
#endif

// debug output stream
template <class CharT, class TraitsT = std::char_traits<CharT> >
class basic_debugbuf : 
    public std::basic_stringbuf<CharT, TraitsT>
{
public:

    virtual ~basic_debugbuf()
    {
        sync();
    }

protected:
    int sync() {}
    void output_debug_string(const CharT *text) {}
};

template<>
int basic_debugbuf<char>::sync()
{
    OutputDebugStringA(str().c_str());
    return 0;
}

template<class CharT, class TraitsT = std::char_traits<CharT> >
class basic_dostream : 
    public std::basic_ostream<CharT, TraitsT>
{
public:

    basic_dostream() : std::basic_ostream<CharT, TraitsT>
                (new basic_debugbuf<CharT, TraitsT>()) {}
    ~basic_dostream() 
    {
//        delete rdbuf(); 
    }
};

typedef basic_dostream<char>    odstream;

namespace mwse {
namespace log {
// the streams
static ofstream logstream;
static odstream debugstream;

// open the log file on specified path.
void openLog(const char *path)
{
    logstream.open(path);
}

// get the log file.
std::ostream& getLog()
{
    return logstream;
}

std::ostream& getDebug()
{
    return debugstream;
}

// dump bytes to output, formatted as hex bytes, 16 per line. Address not shown.
std::ostream& dump(std::ostream &output, void *data, size_t size)
{
    unsigned char *cp = reinterpret_cast<unsigned char *>(data);
    for (size_t i = 0; i < size; i++) {
        if (i % 16 == 0 && i != 0) output << endl;
        output << hex << setw(2) << setfill('0') << *cp++;
    }
    output << endl;
}

} // namespace log
} // namespace mwse
