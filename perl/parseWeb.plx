#!/usr/bin/perl -w
use strict;
use warnings;
use diagnostics;

my $linkname = "http://www.metropcs.com/metro/category/PhonesandMore/Phones/cat170019";
my $filename = "cat170019";
my $cellname = "TOUCH Evolve";
#my $cellname = "LG Optimus F6";
my $onStock = "addItemToCart";

sub downloadWebPage()
{
	#download the file
	system("wget", "$linkname");
	if ($?!= 0) {
		printf "command exited with value %d.\n", $? >> 8;
		exit;
	}
}

sub parseWeb() 
{
	#open and parse the file
	open(FILE1, $filename);
	while (<FILE1>) {
		if (index($_, $cellname)!=-1 && index($_, $onStock) != -1) {
			close(FILE1);
			unlink $filename;
			return 1;
		}
	}

	printf ("Woops! Cell phone out of stock.\n");
	close(FILE1);
	#remove file
	unlink $filename;
	return 0;
}


downloadWebPage();
if(parseWeb()) {
	printf ("Congrations! Cell phone on stock.\n");
}
