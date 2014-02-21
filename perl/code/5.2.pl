use strict;
use warnings;

my (@words, %count, $word);
@words = <STDIN>;
chomp(@words);
#chomp(@words = <STDIN>);

foreach $word (@words)
{
#	print "$word\n";
	$count{$word} += 1;
}

foreach $word (keys %count)
{
	print $word . "->" . $count{$word} . "\n";
}
