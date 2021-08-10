# String Functions

--8<-- "mwse-deprecated.md"


## `xStringBuild`

**Parameters:**

- `string` **format**: The format string to use, given the tokens below.
- `varies` (many) **input**: The variables to use, matching the pattern of special tokens below.

**Returned:**

- `string` **result**: A string build from the combined input.

`xStringBuild` returns a new string that is constructed based on the format string and any other variable values as needed. The format string is similar to those for `MessageBox` with `%` indicating some special character or variable substitution.

Some patterns can be used to place special characters into the string:

Token  | Meaning
------ | -------------------------------------------------------------------
`%%`   | A single % sign is placed in the string.
`%n`   | A new line marker (CR/LF) is placed in the string.
`%q`   | A quotation mark (") is placed in the string.

The rest are used to insert values from the remaining parameters into the output string.

Token  | Meaning
------ | -------------------------------------------------------------------
`%d`   | A short or long value is inserted as a decimal integer.
`%h`   | A short or long value is inserted as a hexadecimal integer.
`%f`   | A float value is inserted as real decimal number.
`%s`   | A string value is inserted.
`%l`   | A long value is inserted as a four character string.

!!! note
	The uppercase forms `%N`, `%Q`, `%D`, `%H`, `%F`, `%S`, and `%L` also work.

The float specifier takes a precision specifier just like the MessageBox command. The format `%.3f` will print a floating point value with three digits after the decimal point.

The string specifier can take two numbers in its specifier:

Token     |  Meaning
--------- | ---------------------------------------------------------------------
`%2s`     | Skips the first two characters of the string, but inserts the rest.
`%.3s`    | Inserts only three characters of the string.
`%4.5s`   | Skips 4 characters, then inserts the next 5 characters of the string.

!!! note
	The compiler doesn't currently support more than 12 parameters at a time.

!!! note
	The format string is limited to 64 characters.

***

## `xStringCapture`

**Parameters:**

- `string` **string**: The string to search for **pattern** in.
- `string` **pattern**: The regex pattern to use.
- `long` **desiredMatches**: The number of results to return.

**Returned:**

- `string` (many) **matches**: Results of the pattern matching for **pattern** on **string**. The function always return **desiredMatches** results.

This function performs much as `xStringMatch`, but returns the result groups of the regex match. The a number of results matching **desiredMatches** is always returned. The **matches** will be 0 if a match isn't made.

***


## `xStringCompare`

**Parameters:**

- `string` **leftString**: The first string in the comparison.
- `string` **rightString**: The second string in the comparison.

**Returned:**

- `string` **result**: 0 if the strings are equal, otherwise a signed number based on sorting.

Compares the two strings based on alphabetical order and returns 0 if they are equal, a negative number if **leftString** would appear first, and a positive number if **rightString** would appear first.

***


## `xStringLength`

**Parameters:**

- `string` **string**: The string to take the length of.

**Returned:**

- `long` **length**: The length of **string**.

Returns the number of characters in the input, **string**.

***


## `xStringMatch`

**Parameters:**

- `string` **string**: The string to search for **pattern** in.
- `string` **pattern**: The regex pattern to use.

**Returned:**

- `string` (many) **matches**: Results of the pattern matching for **pattern** on **string**. The function always return **desiredMatches** results.

This function performs a [regular expression](https://en.wikipedia.org/wiki/Regular_expression) check on **string**, allowing for very flexible and powerful **pattern** and string matching/identification. For example, you can check if a string contains certain words, or a certain set of characters, in it and in a specific position and order, if you want, and much more.

!!! note
	To return the tokenized regex result, use `xStringCapture`.

MWSE uses the Regex library from the [Boost](http://www.boost.org/) C++ library. The regular expression style is the Perl syntax; please see the [Boost Regex](http://www.boost.org/doc/libs/1_66_0/libs/regex/doc/html/boost_regex/syntax/perl_syntax.html) documentation for full details. However, here is a partial quick summary:

Pattern         | Description
--------------- | ----------------------------------------------------------
.               | Matches any one character.
^               | Matches the beginning of the string.
$               | Matches then end of the string.
( and )         | Groups a sub-expression (see below).
\*              | Makes the preceeding item or group match zero or more times.
?               | Makes the preceeding item or group match zero or once.
\+              | Makes the preceeding item or group match one or more times.
{integer}       | Makes the preceeding item or group match exactly integer times.
{int1,int2}     | Makes the preceeding item or group match from int1 to int2 times.
\|              | Alternation; makes the pattern match either the item on the left of the | or the item on the right.
[character set] | Matches a single character from the set character set. The set can contain individual characters, or ranges of the form a-b, which matches all characters between a and b, including a and b. (For example, [A-Z] will match upper case letters.) If the character set begins with ^, then it will match any character except those in the character set.
[[:name:]]      | Matches a single character from the pre-defined set name.
\\character     | Matches the character; that is, removes the special meaning, if any, from character. (For example, "." matches any single character, but "\." matches the period character.)
\\d             | Match a digit (0-9).
\\l             | Match a lower case letter (a-z).
\\s             | Match whitespace (space, tab).
\\u             | Match an upper case letter (A-Z).
\\w             | Match a word (a string of letters, digits, and underscores)
\\D             | Match anything but a digit.
\\L             | Match anything but a lower case letter (a-z).
\\S             | Match anything but whitespace (space, tab).
\\U             | Match anything but an upper case letter (A-Z).
\\W             | Match anything but a word.
\\<             | Match the start of a word.
\\>             | Match the end of a word.
\\b             | Match the end or start of a word.
\\B             | Match anything but the end or start of a word.
(?i)            | Turns on the i modifier (case insensitive match) for the rest of the pattern or until an enclosing ).
(?i:pattern)    | Turns on the i modifier for the enclosed pattern only.

***


## `xStringParse`

**Parameters:**

- `string` **pattern**: The pattern to parse.
- `string` **source**: Indicates how much of the **pattern** matched successfully.

**Returned:**

- `long` **matchCount**: The number of matches returned.
- `varies` (many) **matches**: The values parsed out of the string.

This function identifies and extracts data from the **source** string based on the **pattern** string. The first return value **matchCount** is a long indicating how much of the pattern matched successfully. The **matches** by the pattern will then be returned in order.

In the pattern string, all of the special features begin with a `%` symbol. Some, simply match special characters that can't otherwise be typed in the pattern string.

Token  | Description
------ | ------------------------------------
`%%`   | Matches a single % sign.
`%n`   | Matches the new line marker, CR/LF.
`%q`   | Matches the " quotation mark.

The rest return the values matched so they can be stored in variables with `setx`.

Token  | Description
------ | ------------------------------------
`%d`   | Matches a decimal integer and the value is returned as type long.
`%h`   | Matches a hexadecimal integer and the value is returned as type long.
`%f`   | Matches a real number and the value is returned as type float.
`%s`   | Matches the rest of the string and returns it as type string.
`%l`   | Matches exactly four characters and returns them as type long.

!!! note
	The uppercase forms `%N`, `%Q`, `%D`, `%H`, `%F`, `%S`, and `%L` also work.

### MWSE Version Checking

A special use case of `xStringParse` is to check the version of MWSE. If a value of zero is returned, the version of MWSE is older than version 2.0.

To do this, **pattern** must be `MWSE_VERSION`. **source** is instead a `long`, to compare to the return value. If the version returned is greater than or equal to **source**, the second return value is 1.

```
long version
long versionAbove2p0

setx version versionAbove2p0 to xStringParse "MWSE_VERSION" 2000000
```

The version returned is spaced. Version 2.0.0 is 2000000 while the hypothetical version 2.34.9 would be 2034009.
