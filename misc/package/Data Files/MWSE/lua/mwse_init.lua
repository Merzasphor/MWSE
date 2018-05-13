-- Require lua files from the right folder, instead of just the root Morrowind directory.
package.path = "./Data Files/MWSE/lua/?.lua;"

-------------------------------------------------
-- Extend base API: math
-------------------------------------------------

function math.clamp(value, low, high)
	if (low > high) then
		low, high = high, low
	end
	return math.max(low, math.min(high, value))
end

-------------------------------------------------
-- Extend base API: table
-------------------------------------------------

-- The # operator only really makes sense for continuous arrays. Get the real value.
function table.size(t)
	local count = 0
	for _ in pairs(t) do
		count = count + 1
	end
	return count
end

function table.choice(t)
	-- We need to get a list of all of our keys first.
	local keys = {}
	for k in pairs(t) do
		table.insert(keys, k)
	end

	-- Now we want to get a random key, and return the value for that key.
	local key = keys[math.random(#keys)]
	return t[key], key
end

function table.find(t, n)
	for i, v in pairs(t) do
		if (v == n) then
			return i
		end
	end
end

function table.removevalue(t, v)
	local i = table.find(t, v)
	if (i ~= nil) then
		table.remove(t, i)
		return true
	end
	return false
end

function table.copy(t, d)
	if (d == nil) then
		d = {}
	elseif (type(t) ~= "table" or type(d) ~= "table") then
		error("Arguments for table.copy must be tables.")
	end

	for k, v in pairs(t) do
		d[k] = v
	end

	return d
end

function table.deepcopy(t)
	local copy = nil
	if type(t) == "table" then
		copy = {}
		for k, v in next, t, nil do
			copy[table.deepcopy(k)] = table.deepcopy(v)
		end
		setmetatable(copy, table.deepcopy(getmetatable(t)))
	else -- number, string, boolean, etc
		copy = t
	end
	return copy
end

-------------------------------------------------
-- Extend base table: Add binary search/insert
-------------------------------------------------

--[[
	table.binsearch( table, value [, compval [, reversed] ] )
	
	Searches the table through BinarySearch for the given value.
	If the  value is found:
		it returns a table holding all the mathing indices (e.g. { startindice,endindice } )
		endindice may be the same as startindice if only one matching indice was found
	If compval is given:
		then it must be a function that takes one value and returns a second value2,
		to be compared with the input value, e.g.:
		compvalue = function( value ) return value[1] end
	If reversed is set to true:
		then the search assumes that the table is sorted in reverse order (largest value at position 1)
		note when reversed is given compval must be given as well, it can be nil/_ in this case
	Return value:
		on success: a table holding matching indices (e.g. { startindice,endindice } )
		on failure: nil
]]--
local default_fcompval = function( value ) return value end
local fcompf = function( a,b ) return a < b end
local fcompr = function( a,b ) return a > b end
function table.binsearch( t,value,fcompval,reversed )
	-- Initialise functions
	local fcompval = fcompval or default_fcompval
	local fcomp = reversed and fcompr or fcompf
	--  Initialise numbers
	local iStart,iEnd,iMid = 1,#t,0
	-- Binary Search
	while iStart <= iEnd do
		-- calculate middle
		iMid = math.floor( (iStart+iEnd)/2 )
		-- get compare value
		local value2 = fcompval( t[iMid] )
		-- get all values that match
		if value == value2 then
			local tfound,num = { iMid,iMid },iMid - 1
			while value == fcompval( t[num] ) do
				tfound[1],num = num,num - 1
			end
			num = iMid + 1
			while value == fcompval( t[num] ) do
				tfound[2],num = num,num + 1
			end
			return tfound
		-- keep searching
		elseif fcomp( value,value2 ) then
			iEnd = iMid - 1
		else
			iStart = iMid + 1
		end
	end
end

--[[
	table.bininsert( table, value [, comp] )
	
	Inserts a given value through BinaryInsert into the table sorted by [, comp].
	
	If 'comp' is given, then it must be a function that receives
	two table elements, and returns true when the first is less
	than the second, e.g. comp = function(a, b) return a > b end,
	will give a sorted table, with the biggest value on position 1.
	[, comp] behaves as in table.sort(table, value [, comp])
	returns the index where 'value' was inserted
]]--
local fcomp_default = function( a,b ) return a < b end
function table.bininsert(t, value, fcomp)
	-- Initialise compare function
	local fcomp = fcomp or fcomp_default
	--  Initialise numbers
	local iStart,iEnd,iMid,iState = 1,#t,1,0
	-- Get insert position
	while iStart <= iEnd do
		-- calculate middle
		iMid = math.floor( (iStart+iEnd)/2 )
		-- compare
		if fcomp( value,t[iMid] ) then
			iEnd,iState = iMid - 1,0
		else
			iStart,iState = iMid + 1,1
		end
	end
	table.insert( t,(iMid+iState),value )
	return (iMid+iState)
end

-------------------------------------------------
-- Extend base API: string
-------------------------------------------------

function string.startswith(haystack, needle)
	return string.sub(haystack, 1, string.len(needle)) == needle
end

function string.endswith(haystack, needle)
	return needle=='' or string.sub(haystack, -string.len(needle)) == needle
end

-------------------------------------------------
-- Global includes
-------------------------------------------------

_G.tes3 = require("mwse.tes3.init")
_G.event = require("mwse.event")
_G.timer = require("mwse.timer")
_G.json = require("dkjson")

-------------------------------------------------
-- Extend our base API: json
-------------------------------------------------

function json.loadfile(fileName)
	-- Load the contents of the file.
	local f = io.open("Data Files/MWSE/" .. fileName .. ".json", "r")
	if (f == nil) then
		return nil
	end
	local fileContents = f:read("*all")
	f:close()

	-- Return decoded json.
	return json.decode(fileContents)
end

function json.savefile(fileName, object, config)
	local f = assert(io.open("Data Files/MWSE/" .. fileName .. ".json", "w"))
	f:write(json.encode(object, config))
	f:close()
end

-- Report that we're initialized.
print("MWSE Lua interface initialized.")
