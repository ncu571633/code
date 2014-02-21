use warnings;

%some_hash = ("foo", 35, "betty", "bye\n");
#$some_hash{"foo"} = 35;
#print $some_hash{"foo"} . "\n";
#print %some_bash . "\n";
@any_array = %some_hash;
print "@any_array\n"
