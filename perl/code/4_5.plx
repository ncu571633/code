use 5.010;

greet("Fred");
greet("Barney");
greet("Wilma");
greet("Betty");

sub greet
{
	state @last;
	my $name = $_[0]; 
	print "Hi $name, ";
	if(defined $last)
	{
		foreach(@last)
		{
			print $_ . " "; 
		}
		print "is also here!\n";
	}
	else
	{
		print "You are the first one here\n";
	}
	push(@last, $_[0]);
	$last = $name;
}
