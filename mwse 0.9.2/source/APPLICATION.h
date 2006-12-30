//Application.h
#pragma once

struct application
{
	virtual int main(int argc, char* argv[])= 0;
	virtual ~application(void){};
};