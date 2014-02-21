i=0
n=$((`ls -l | grep -c "^-.*"`))
totalTime1=$(date +"%s")

allname=`ls IMG**`
for name in $allname
do
	partialTime1=$(date +"%s")
	
	convert -resize 50%  $name COPY_$name
	
	partialTime2=$(date +"%s")
	diff=$(($partialTime2-$partialTime1))
	
	#no new line for echo
	i=$(($i+1))
	echo -n "$i($diff s): \t $name \t->\t"
	echo $i/$n | bc -l
done

totalTime2=$(date +"%s")
diff=$(($totalTime2-$totalTime1))
echo "Convert $n photos in $(($diff / 60)) minutes and $(($diff % 60)) seconds"
