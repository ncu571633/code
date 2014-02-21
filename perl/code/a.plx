@lines = <STDIN>;
chomp(@lines);
@lines = reverse(@lines);
foreach(@lines)
{
	print $_;
	print "\n";
}
