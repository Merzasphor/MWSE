all: mxsc.exe 

mxsc.exe : lang.e mxsc.d compiler.d Bytefield.d SCPT.d
        enki lang.e
        dmd mxsc.d compiler.d Bytefield.d SymbolTable.d SCPT.d parser.d c:\microcomp\enki\BaseParser.d c:\microcomp\enki\IParser.d c:\microcomp\enki\types.d
        


