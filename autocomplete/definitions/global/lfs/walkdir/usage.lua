for filePath, dir, fileName in lfs.walkdir("data files\\meshes\\") do
	-- Here filePath would look like:
	-- data files\meshes\o\Contain_Trama_Shrub_01.nif"

	-- dir:
	-- data files\meshes\o\

	-- fileName:
	-- Contain_Trama_Shrub_01.nif
	mwse.log(
		"%s, %s, %s",
		filePath,
		dir,
		fileName
	)
end