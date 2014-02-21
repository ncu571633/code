use strict;
use warnings;

my %name = (
	"fred" => "filestone",
	"dino" => "rubble",
	"barney" => "flint",
);

my $in = <STDIN>;
chomp($in);
print $in . " " . $name{$in} . "\n";
