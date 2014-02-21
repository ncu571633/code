$i = 3;
$n = 100;

while($i<$n)
{
	$j = 2;
	$check = 0;
	while($j < $i)
	{
		if($i % $j == 0 )
		{
			$check = 1;
		}
		$j++;
	}
	if($check == 0)
	{
		printf("i = %d\n", $i);
	}
	$i++;
}
