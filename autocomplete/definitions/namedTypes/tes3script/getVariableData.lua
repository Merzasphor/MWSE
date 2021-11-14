return {
	type = "method",
	description = [[A special context to for reading script's variables.]],
	returns = {{ 
        name = "results",
        type = "table",
        description = [[The table with all of script's variable names as keys. 
        
        Each entry has following fields:
            1.) type - 's', 'f' or 'l', which stand for short, float, and long
            2.) index - the order of occurance of the variable in the script, starting from 0
            3.) value - this can have nil value]]
    }},
}