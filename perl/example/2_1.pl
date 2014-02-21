$pi = 3.1415926535;
#$radius = 12.5;
$radius = <STDIN>;
chomp($radius);
print ( ($radius>0)? 2*$pi*$radius . "\n": "0\n" );
