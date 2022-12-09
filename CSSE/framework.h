#pragma once

// Standard template libraries.
#include <algorithm>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <sstream>
#include <stddef.h>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <future>

// Required C includes.
#include <cmath>
#include <cstdint>
#include <cstring>
#include <ctime>

// Required Windows APIs.
#include <windows.h>
#include <wtypes.h>
#include <psapi.h>
#include <dbghelp.h>
#include <d3d.h>

// Undefine anything we don't care about otherwise.
#undef far
#undef near
#undef PlaySound
#undef max
