@rocks =  qw("bedrock", "slate", "lava");
foreach $rock (@rocks)
{
	$rock = "\t$rock";
	$rock .= "\n";
}
print "the rocks are :\n", @rocks;
