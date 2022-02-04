#pragma once

//
// Version information. Must be manually updated.
//

constexpr auto MWSE_VERSION_MAJOR = 2;
constexpr auto MWSE_VERSION_MINOR = 1;
constexpr auto MWSE_VERSION_PATCH = 0;

constexpr auto MWSE_VERSION_INTEGER = MWSE_VERSION_MAJOR * 1000000 + MWSE_VERSION_MINOR * 1000 + MWSE_VERSION_PATCH;

static_assert(MWSE_VERSION_MAJOR >= 0, "Major version number must be greater than 0.");
static_assert(MWSE_VERSION_MINOR < 1000 && MWSE_VERSION_MINOR >= 0, "Minor version number must be between 0 and 999.");
static_assert(MWSE_VERSION_PATCH < 1000 && MWSE_VERSION_PATCH >= 0, "Patch version number must be between 0 and 999.");
