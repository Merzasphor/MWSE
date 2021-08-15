--- @meta

--- This library provides generic functions for string manipulation, such as finding and extracting substrings, and pattern matching. When indexing a string in Lua, the first character is at position 1 (not at 0, as in C). Indices are allowed to be negative and are interpreted as indexing backwards, from the end of the string. Thus, the last character is at position -1, and so on.
--- @class stringlib
string = {}

--- Returns true if a string ends with a given pattern.
--- @param s string No description yet available.
--- @param pattern string No description yet available.
--- @return boolean result No description yet available.
function string.endswith(s, pattern) end

--- This function creates a string, given various values. The first parameter follows the [printf](http://www.cplusplus.com/reference/cstdio/printf) format, with the additional option of `%q` to automatically quote a string.
--- 
--- Specifier | Output                                                  | Example
--- --------- | ------------------------------------------------------- | -------------
--- `%d`      | Signed decimal integer.                                 | -392
--- `%i`      | Same as `%d`.                                           | -392
--- `%u`      | Unsigned decimal integer.                               | 7235
--- `%o`      | Unsigned octal.                                         | 610
--- `%x`      | Unsigned hexadecimal integer.                           | 7fa
--- `%X`      | As `%x`, but uppercase.                                 | 7FA
--- `%f`      | Decimal floating point, lowercase.                      | 392.65
--- `%F`      | Decimal floating point, uppercase.                      | 392.65
--- `%e`      | Scientific notation (mantissa/exponent), lowercase.     | 3.9265e+2
--- `%E`      | Scientific notation (mantissa/exponent), uppercase.     | 3.9265E+2
--- `%g`      | Use the shortest representation: %e or %f.              | 392.65
--- `%G`      | Use the shortest representation: %E or %F.              | 392.65
--- `%a`      | Hexadecimal floating point, lowercase.                  | -0xc.90fep-2
--- `%A`      | Hexadecimal floating point, uppercase.                  | -0XC.90FEP-2
--- `%c`      | Character.                                              | a
--- `%s`      | String of characters.                                   | sample
--- `%q`      | Quoted string of characters.                            | "sample"
--- `%p`      | Pointer address.                                        | b8000000
--- `%%`      | The literal `%` character.                              | %
--- @param format string The format string to use for the output.
--- @param unknown values *Optional*. Values to format into the given string.
--- @return string result No description yet available.
function string.format(format, unknown) end

--- Returns a string where one string has been inserted into another at a given position.
--- @param s1 string The string to insert into.
--- @param s2 string The string to insert.
--- @param position number The position to insert s2 into s1.
--- @return string inserted A copy of s1 with s2 inserted into it.
function string.insert(s1, s2, position) end

--- Performs the logic of find, using a table of patterns.
--- 
--- If any of the available patterns match, the matching pattern is returned followed by the normal results of the find.
--- @param s string The string to perform finds on.
--- @param pattern table An array-style table that contains pattern strings.
--- @param index number *Default*: `1`. Start index of the find.
--- @param plain boolean If true, a normal search instead of a pattern search will be performed.
function string.multifind(s, pattern, index, plain) end

--- Returns an array-style table with `str` split by `sep`. The `sep`erator is not part of the results. By default the `sep`erator is `%s`, splitting the given `str`ing by spaces.
--- @param str string The string to split.
--- @param sep string *Default*: `"%s"`. The token to split the string by.
--- @return table split No description yet available.
function string.split(str, sep) end

--- Returns true if a string begins with a given pattern.
--- @param s string No description yet available.
--- @param pattern string No description yet available.
--- @return boolean result No description yet available.
function string.startswith(s, pattern) end

--- Returns a copy of the string, with whitespace removed from the start and end.
--- @param s string No description yet available.
--- @return string trimmed No description yet available.
function string.trim(s) end

