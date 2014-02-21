@name = qw(fred betty barney dino wilma pebbles bamm);
chomp(@line = <STDIN>);
foreach(@line)
{
	print @name[$_ -1];
	print "\n";
}
