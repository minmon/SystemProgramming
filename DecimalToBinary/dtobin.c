#include <stdio.h>

int basec(int arg,int base),
dtobin(int arg,int base);

int main(void)
{
	dtobin(12,2);
	return 0;
}

int dtobin(int arg,int base)
{
	return basec(arg<<1,base);
}

int basec(int arg,int base)
{	
	int quotient = arg/base,
	remainder = arg%base;
		
	if(quotient)
	{
		printf("%d",basec(quotient,base));
	}
	
	return remainder;
}
