#include"nLogger.h"

bool nLogger::cTxt::mOpen(char filename[])
{
	sprintf(vFormatted,"%s.txt",filename);

	vTxtFile=fopen(vFormatted,"a+");
	if(vTxtFile!=0)
		return true;
	else
		return false;
}

void nLogger::cTxt::mWrite(char contents[])
{
	fprintf(vTxtFile,
		"\n\n"
		"-------------------------------------------------\n\n"
		"%s\n\n"
		"-------------------------------------------------\n\n",contents);
}

bool nLogger::cTxt::mClose()
{
	fprintf(vTxtFile,"[Closed Logging Stream]");

	if(fclose(vTxtFile)==0)
		return true;
	else
		return false;
}

nLogger::cTxt::cTxt()
{
}

nLogger::cTxt::~cTxt()
{
}

//---------------------------------------------------------------------------------

bool nLogger::cHtml::mOpen(char filename[])
{
	sprintf(vFormatted,"%s.html",filename);

	vHtmlFile=fopen(vFormatted,"w+");
	if(vHtmlFile!=0)
	{
		fprintf(vHtmlFile,
			"<html>\n"
			"<head>\n"
			"<title>MWSE Log</title>\n"
			"</head>\n"
			"<body style='background-color: #000000'>\n"
			"<table border='0' align='center' cellpadding='0' cellspacing='0'>\n"
			);

		return true;
	}
	else
		return false;
}

void nLogger::cHtml::mAddSuccess(char contents[])
{
	fprintf(vHtmlFile,
		"<tr style='background-color: #00FF00'>\n"
		"<td>%s</td>\n"
		"</tr>\n",
		contents);
}

void nLogger::cHtml::mAddWarning(char contents[])
{
	fprintf(vHtmlFile,
		"<tr style='background-color: #FFFF00'>\n"
		"<td>%s</td>\n"
		"</tr>\n",
		contents);
}

void nLogger::cHtml::mAddFailure(char contents[])
{
	fprintf(vHtmlFile,
		"<tr style='background-color: #FF0000'>\n"
		"<td>%s</td>\n"
		"</tr>\n",
		contents);
}

void nLogger::cHtml::mAddCustom(char contents[], char hex[])
{
	fprintf(vHtmlFile,
		"<tr style='background-color: %s'>\n"
		"<td>%s</td>\n"
		"</tr>\n",
		hex,contents);
}

bool nLogger::cHtml::mClose()
{
	fprintf(vHtmlFile,
		"</table>\n"
		"</body>\n"
		"</html>\n"
		);

	if(fclose(vHtmlFile)==0)
		return true;
	else
		return false;
}

nLogger::cHtml::cHtml()
{
}

nLogger::cHtml::~cHtml()
{
}

//-------------------------------------------------------------------------------------

bool nLogger::cXml::mOpen(char filename[])
{
	sprintf(vFormatted,"%s.xml",filename);

	vXmlFile=fopen(vFormatted,"w+");
	if(vXmlFile!=0)
	{
		fprintf(vXmlFile,
			"<MorrowindScriptExtender>\n"
			);
		return true;
	}
	else 
		return false;
}

void nLogger::cXml::mAddSuccess(char contents[])
{
	fprintf(vXmlFile,
		"<Chunk type='success'>\n"
		"%s\n"
		"</Chunk>\n",contents);
}

void nLogger::cXml::mAddWarning(char contents[])
{
	fprintf(vXmlFile,
		"<Chunk type='warning'>\n"
		"%s\n"
		"</Chunk>\n",contents);
}

void nLogger::cXml::mAddFailure(char contents[])
{
	fprintf(vXmlFile,
		"<Chunk type='failure'>\n"
		"%s\n"
		"</Chunk>\n",contents);
}

bool nLogger::cXml::mClose()
{
	fprintf(vXmlFile,
		"</MorrowindScriptExtender>\n"
		);

	if(fclose(vXmlFile)==0)
		return true;
	else 
		return false;
}

nLogger::cXml::cXml()
{
}

nLogger::cXml::~cXml()
{
}

//-----------------------------------------------------------------------------------

bool nLogger::cBBCode::mOpen(char filename[])
{
	sprintf(vFormatted,"%s.txt",filename);

	vBbFile=fopen(vFormatted,"a+");
	if(vBbFile!=0)
	{
		fprintf(vBbFile,
			"[code]\n"
			);

		return true;
	}
	else
		return false;
}

void nLogger::cBBCode::mWrite(char contents[])
{
	fprintf(vBbFile,
		"------------------------------------------------------------------------------\n\n"
		"%s\n\n"
		"------------------------------------------------------------------------------\n\n"
		,contents);
}

bool nLogger::cBBCode::mClose()
{
	fprintf(vBbFile,
		"[/code]\n"
		);

	if(fclose(vBbFile)==0)
		return true;
	else
		return false;
}

nLogger::cBBCode::cBBCode()
{
}

nLogger::cBBCode::~cBBCode()
{
}