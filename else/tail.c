//test platform: Linux
//gcc -O3 -o tail tail.c


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define LINE 10				//print last 10 lines defaultly
#define LARGEFILE  32		//a file is defined as a large file if it is more than 32 bytes
#define LARGELINE  32		
#define BUFFERSIZE 1024		//buffer size

void bufferTail(char *fileName, int n)
{
	FILE *fp = fopen(fileName, "r");
    if(!fp)
    {
        printf("Can't open file.\n");
        exit(0);
    }

    char Buffer[n][BUFFERSIZE];
    int lines = 0, start, count;
    while( fgets(Buffer[lines%n], BUFFERSIZE, fp) != NULL)
        lines++;
    if(lines<n)
        start = 0, count = lines;
    else
        start = lines%n, count = n;

    int i = 0;
    for(i=0; i<count; i++)
        printf("%s", Buffer[(start+i)%n]);
    
	fclose(fp);
}

void nobufferTail(char *fileName, int n)
{
	FILE *fp = fopen(fileName, "r"), *fp1 = fopen(fileName, "r");
    if(!fp || !fp1)
    {
        printf("Can't open file.\n");
        exit(0);
    }
	int lines = 0;
	char Buffer[BUFFERSIZE];
    while( fgets(Buffer, BUFFERSIZE, fp) != NULL)
	{
		lines++;
		if(lines>=n)
			break;
	}

	//there are ``lines" lines in the file, which is smaller than n
	if(lines<n)
	{
		while( fgets(Buffer, BUFFERSIZE, fp1) != NULL)
			printf("%s", Buffer);
		return ;
	}

	//the file has more than n lines.
	//fp points to n+1 line from the beginning, fp1 points to the beginning 
    while( fgets(Buffer, BUFFERSIZE, fp) != NULL)
	{
		fgets(Buffer, BUFFERSIZE, fp1);
	}
	//now fp points to the end, fp1 points to the n line from the end
    while( fgets(Buffer, BUFFERSIZE, fp1) != NULL)
	{
		printf("%s", Buffer);
	}
    
	fclose(fp);
    fclose(fp1);
}

int main(int argc, char **argv)
{
    if(argc <= 1)
    {
        printf("Please follow the format: tail [-n n] [-f] filename\n");
        exit(0);
    }

	int c;
	int nflag = 0, fflag = 0, nline = 0;
	opterr = 0;
    while ((c = getopt (argc, argv, "fn:")) != -1)
	{
		switch (c)
        {
        case 'n':
            nflag = 1;
			nline = atoi(optarg);
			if(nline<=0)
				return 1;
            break;
        case 'f':
            fflag = 1;
            break;
        default:
			printf("tail: invalid option -- 'a'");
            exit(0);
        }
	}

	struct stat sb;
	if (stat(argv[argc-1], &sb) == -1) 
	{
		perror("stat");
		exit(0);
	}
	//sb.st_mtime:	last file modification
	//sb.st_size:	total size, in bytes


	if(nflag)
	{
		//if(sb.st_size > LARGEFILE)
		if(nline > LARGELINE)
			nobufferTail(argv[argc-1], nline);		//if the line number is specified
		else
			bufferTail(argv[argc-1], nline);
	}
	else											//if the line number is not specified, print the last 10 lines
			bufferTail(argv[argc-1], LINE);

	if(!fflag)
		return ;


	while(fflag)
	{
		sleep(2);
		struct stat sb1;
		if (stat(argv[argc-1], &sb1) == -1) 
		{
			perror("stat");
			exit(0);
		}
		if(sb.st_mtime != sb1.st_mtime)
		{
			if(nflag)
				nobufferTail(argv[argc-1], nline);		//if the line number is specified
			else
			    nobufferTail(argv[argc-1], LINE);		//if not, print last 10 lines
			sb = sb1;
		}	

	}

    return 0;
}



/*
 Tail

 We would like you to implement "tail" unix command. You can google "unix tail" or do "man tail" on unix/linux operating system to read more about this command.

 For this assignment we will focus only on "-n" and "-f" options.

 Your program and desing should consider following:

 (1) Input file size can vary from few MBs to tens of GB.
 (2) Two cases for value of N (A) N is small to fit in memory (B) N is large to fit in memory



Idea: 
There are two ways to handle the problem. Method one only parses the file once, but it needs a buffer array to store the last n lines.
Method two parses the file twice, but it doesn't store the last n lines. 

1. Method one: 
A size n circular array buffer is used to store each set of n lines. At first the buffer stores lines 0~9. Then, the oldest line is removed from the buffer. When the file pointer moves to the end of the file, this buffer stores the last n lines.

2. Method two: 
Suppose there are two pointers point to the beginning of the file: fp and fp1.
For the first step fp moves to the line n from the beginning of the file by using a loop. The distance between fp and fp1 is n lines.
Then, both fp and fp1 move until fp hit the end of file. Since the distance of both pointers are the same, fp1 points to line n from the end of the file.
At last, by using fp1, all lines after line n from the end of file could be printed.

For both two methods, the line number of the file is checked. If there are k lines in the file(k<n), the whole file is printed.

Suppose we need to print 2^20 lines, the memory can't store so many lines. We need to parse file twice for the memory reasons and use method two. A constant is defined as "LARGELINE", if last n lines are printed where n > LARGELINE, method two is used. 

Implementation:
-f option: stat() function is used to check the file's last modification time. If the file is modified, the last n lines of the modified file are printed.

getopt funtion is used to parse the options of the command.


Test:
The program could be compiled by using:
gcc -O3 -o tail tail.c

The program accept the following command:
./tail: prints the usage
./tail file: prints last 10 lines, 10 is a default value
./tail -n file: do nothing 
./tail -n N file: print last N lines. if N<=0, do nothing.
./tail -f file: by using an infinity loop, check the file to see whether it is modified.
./tail -f -n file
./tail -f -n N file
*/
