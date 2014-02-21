use warnings;

my %names = (
	"fred" 	=> "flintstone",
	"barney"=> "rubble",
	"wilma"	=> "flintstone",
);

chomp($text = <STDIN>);
print $names{$text};
