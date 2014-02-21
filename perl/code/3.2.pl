@name = qw(fred betty barney dino wilma pebbles bamm);
chomp(@number = <STDIN>);
foreach(@number)
{
	print @name[$_] . "\n" 
}
