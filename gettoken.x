#define PROGRAM_NUMBER 987654321
#define VERSION_NUMBER 1

struct token
{
        int token;
        int aux;
};

program GETTOKEN_PROG 
{ 
	version GETTOKEN_VERSION 
	{ 
    	int GTOKEN (token) = 1;
    	int LIBERTA (token) = 2;
	} 
	= VERSION_NUMBER; 
} 
= PROGRAM_NUMBER;