chomp (@lines = <STDIN>);
@lines = sort(@lines);
foreach(@lines)
{
	print $_;
	print "\n"
}
