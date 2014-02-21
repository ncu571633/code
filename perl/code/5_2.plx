use warnings;

my @lines = <STDIN>;


#print ((join("", (1..9)) . "0") x 2 . "\n");

@numbers = 1..9;
push(@numbers, 0);
print (join("", @numbers) x 2 . "\n");

=comment
$i=1;
while($i<=9)
{
	$numbers[$i] = $i;
	$i++;
}
$numbers[10] = 0;
print join("", @numbers) x 2 . "\n";
=cut

foreach(@lines)
{
	printf ("%20s", $_);
}
