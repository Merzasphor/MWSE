-- Ensure we have the features we need.
if (mwse.buildDate == nil or mwse.buildDate < 20210817) then
	mwse.log("[Example] Build date of %s does not meet minimum build date of 20210817.", mwse.buildDate)
	return
end