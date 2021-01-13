x=$(lscpu)
no_of_cores=0
trial=0
for i in $x
do
    if [ $trial = "4" ]; then
        ((trial=0))
        no_of_cores=$i
    fi
    
    if [ $i = "Core(s)" ]; then
        ((trial+=1))
    fi
    if [ $i = "per" ]; then
        ((trial+=1))
    fi
    if [ $i = "socket:" ]; then
        ((trial+=1))
    fi
    
done

echo "your cpu contains $no_of_cores cores"
mpic++ -O -o a.out $1 
for (( c=1; c<=$no_of_cores; c++ ))
do  
    echo "running program on $c CPUs"
   mpirun -n $c ./a.out
   echo "finished running program on $c CPU"

done