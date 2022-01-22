
local optionalModule = include("optionalModule.file")

if optionalModule then
	-- do stuff with the optinalModule
	optionalModule.foo("bar")
else
	mwse.log("[MyMod] To enjoy all of this mod's features, please install optionalModule.")
	-- do some other stuff
end