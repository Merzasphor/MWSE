
# Introduction to Lua
This guide will introduce the Lua scripting language, which is used when developing mods for *The Elder Scrolls III: Morrowind* using MWSE 2.1 Lua.

MWSE uses LuaJIT 2.1.0-beta3, which contains functionality from up to version 5.3 of the Lua scripting language.

## Lua In Context
The following information is based on information from the [Lua 5.1 Reference Manual](https://www.lua.org/manual/5.1/manual.html).

Lua is an extension programming language. It can be executed by other, traditional languages, such as C, C++, and C#. In the context of MWSE, this means that the MWSE executable can load Lua code and execute it. This ability allows modders to use Lua to create powerful mods for Morrowind, accomplishing things that were previously impossible.

One important detail of Lua is that, unlike other languages, it does not have a *Main* method. This means that it has no mechanism through which to execute itself. In other words, it can only be executed if embedded in another program, called a *host client*. In the context of MWSE, MWSE is the host client.
However, MWSE *does* require a files named *main.lua* to execute your code. The MWSE executable will load any file named *main.lua* and execute the code within. 

In practice, this means that the *main.lua* file performs the same role as a traditional *main* method in C or C++: it provides an entry point into your code. Specifically, it is used to register and initialize your mod. Unlike traditional *main* methods in C or C++, there are no required functions for *main.lua*. The file can consist of anything or nothing. However, registering an event is usually required to develop a mod.

## Conclusion
This article introduced the Lua scripting language and explained it in the context of MWSE.

For in-depth documentation of the Lua scripting language, please refer to the [Lua 5.1 Reference Manual](https://www.lua.org/manual/5.1/manual.html).
