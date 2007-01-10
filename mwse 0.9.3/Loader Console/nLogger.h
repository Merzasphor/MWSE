#ifndef _ERR_CLOGGER
#define _ERR_CLOGGER
#define _CRT_SECURE_NO_DEPRECATE
/************************************\
* AnthonyG 1/5/07                    *
* Multiple format logging classes    *
* Stored in nLogger namespace        *
*                                    *
* Thanks Fliggerty & DarkSecond :)   *
*                                    *
* Don't use full paths or the build  *
* will crash                         *
*                                    *
* Watch the team decide to use cTxt  *
\************************************/
#include<StdIO.h>

namespace nLogger
{
	//Class for text file saving, Relatively simple
	class cTxt
	{
	private:
		char vFormatted[100];
		FILE *vTxtFile;
	public:
		//Open the txt file(Extensions are ignored, Always *.txt)
		bool mOpen(char filename[]);
		//Write a chunk to the log
		void mWrite(char contents[]);
		//Close the log
		bool mClose();

		cTxt();
		~cTxt();
	};

	//HTML saving, Good for most general logging(End-user friendly)
	class cHtml
	{
	private:
		char vFormatted[100];
		FILE *vHtmlFile;
	public:
		//Open the HTML log(Extensions ignored, Always *.html)
		bool mOpen(char filename[]);
		//Add green-light style line
		void mAddSuccess(char contents[]);
		//Add yellow line
		void mAddWarning(char contents[]);
		//Add red, Failure light
		void mAddFailure(char contents[]);
		//Add custom row(hex value needed, I.E. #a9a9a9)
		void mAddCustom(char contents[],char hex[]);
		//Close the log
		bool mClose();

		cHtml();
		~cHtml();
	};

	//XML , A gift for DarkSecond( And his desire to be '1337')
	class cXml
	{
	private:
		char vFormatted[100];
		FILE *vXmlFile;
	public:
		//Open the xml log(extensions ignored, Always *.xml)
		bool mOpen(char filename[]);
		//Add success snippet
		void mAddSuccess(char contents[]);
		//Add warn snippet
		void mAddWarning(char contents[]);
		//Add fail snippet
		void mAddFailure(char contents[]);
		//Add a generic message snippet
		void mAddMessage(char contents[]);
		//Close it
		bool mClose();

		cXml();
		~cXml();
	};

	//Forum BBCode, Easy error reports
	class cBBCode
	{
	private:
		char vFormatted[100];
		FILE *vBbFile;
	public:
		//Open It up(extensions ignored, always *.txt)
		bool mOpen(char filename[]);
		//Write a chunk
		void mWrite(char contents[]);
		//Close it
		bool mClose();

		cBBCode();
		~cBBCode();
	};
}

#endif