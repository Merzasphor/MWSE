
xStringMatch
========================================================

**Parameters:**

- ``string`` **string**: The string to search for **pattern** in.
- ``string`` **pattern**: The regex pattern to use.

**Returned:**

- ``string`` (many) **matches**: Results of the pattern matching for **pattern** on **string**. The function always return **desiredMatches** results.

This function performs a `regular expression`_ check on **string**, allowing for very flexible and powerful **pattern** and string matching/identification. For example, you can check if a string contains certain words, or a certain set of characters, in it and in a specific position and order, if you want, and much more.

.. note:: To return the tokenized regex result, use `xStringCapture`_.

MWSE uses the Regex library from the `Boost`_ C++ library. The regular expression style is the Perl syntax; please see the `Boost Regex`_ documentation for full details. However, here is a partial quick summary:

=============== ==========================================================
Pattern         Description
=============== ==========================================================
.               Matches any one character.
^               Matches the beginning of the string.
$               Matches then end of the string.
( and )         Groups a sub-expression (see below).
\*              Makes the preceeding item or group match zero or more times.
?               Makes the preceeding item or group match zero or once.
\+              Makes the preceeding item or group match one or more times.
{integer}       Makes the preceeding item or group match exactly integer times.
{int1,int2}     Makes the preceeding item or group match from int1 to int2 times.
\|              Alternation; makes the pattern match either the item on the left of the | or the item on the right.
[character set] Matches a single character from the set character set. The set can contain individual characters, or ranges of the form a-b, which matches all characters between a and b, including a and b. (For example, [A-Z] will match upper case letters.) If the character set begins with ^, then it will match any character except those in the character set.
[[:name:]]      Matches a single character from the pre-defined set name.
\\character     Matches the character; that is, removes the special meaning, if any, from character. (For example, "." matches any single character, but "\." matches the period character.)
\\d             Match a digit (0-9).
\\l             Match a lower case letter (a-z).
\\s             Match whitespace (space, tab).
\\u             Match an upper case letter (A-Z).
\\w             Match a word (a string of letters, digits, and underscores)
\\D             Match anything but a digit.
\\L             Match anything but a lower case letter (a-z).
\\S             Match anything but whitespace (space, tab).
\\U             Match anything but an upper case letter (A-Z).
\\W             Match anything but a word.
\\<             Match the start of a word.
\\>             Match the end of a word.
\\b             Match the end or start of a word.
\\B             Match anything but the end or start of a word.
(?i)            Turns on the i modifier (case insensitive match) for the rest of the pattern or until an enclosing ).
(?i:pattern)    Turns on the i modifier for the enclosed pattern only.
=============== ==========================================================

.. _`xStringCapture`: xStringCapture.html
.. _`regular expression`: https://en.wikipedia.org/wiki/Regular_expression
.. _`Boost`: http://www.boost.org/
.. _`Boost Regex`: http://www.boost.org/doc/libs/1_66_0/libs/regex/doc/html/boost_regex/syntax/perl_syntax.html
