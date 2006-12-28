#ifndef _WINAPP_H_STHSFBSFG
#define _WINAPP_H_STHSFBSFG

struct application
{
	virtual int main(int argc, char* argv[])= 0;
	virtual ~application(void){};
};

#endif
