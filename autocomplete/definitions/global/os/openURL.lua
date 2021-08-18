return {
	type = "function",
	description = [[Opens the given `url` in the default browser. This has an advantage over using `os.execute("show https://my.url")` in that it does not create a command prompt window.]],
	arguments = {
		{ name = "url", type = "string", description = "The URL to open." },
	},
}