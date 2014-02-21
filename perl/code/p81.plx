use warnings;

my @items = qw(wilma dino pebbles);
printf "The items are :\n" . ("%10s\n" x @items), @items;
