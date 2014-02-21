use 5.010;

greet("Fred");
greet("Barney");

sub greet
{
	state $last;
	my $name = $_[0]; 
	print "Hi $name, ";
	if(defined $last)
	{
		print $last . " is also here!\n"
	}
	else
	{
		print "You are the first one here\n";
	}
	$last = $name;
}
