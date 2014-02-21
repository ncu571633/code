name=xxx-xxx
link=http://www.xxx.com/xxx/
count=0

for i in $(seq 66); do
        for j in $(seq 12); do
                path=${link}/${name}/${i}/${name}-${j}.jpg
                wget ${path} -O ${name}-${count}.jpg
        echo "count" $count
        count=$(($count+1))
        done;
done;
