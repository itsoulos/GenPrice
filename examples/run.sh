PROBLEM=$1.cc
/home/sheridan/Desktop/ERGASIES/GenPrice/bin/make_genprice -p $PROBLEM -o $1
rm -f $1.out
for x in $(seq 30)
do
	./$1 -r $x >> $1.out
done
cat $1.out | grep FUNCTION | awk '{print $4}' | awk -v N=1 '{ sum += $N } END { if (NR > 0) print sum / NR }'
