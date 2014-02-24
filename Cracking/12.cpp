/*
Write code to reverse a C-Style String. (C-String means that “abcd” is represented as
five characters, including the null character.)
   */

#include <stdio.h>

void reverse(char *str)
{
	char *p = str, *q = str;
	while(*p)
		p++;
	p--;
	while(q<=p)
	{
		char t = *p;
		*p = *q;
		*q = t;
		p--, q++;
	}
}

int main()
{
	char str[] = "";
	printf("%s\n", str);
	reverse(str);
	printf("%s\n", str);
	return 1;
}
