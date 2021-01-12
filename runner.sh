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

read -p  "Specify the number of cores to use in running the MPIc program $1 : " user_core

while [ $user_core -gt $no_of_cores ];
do
    echo "the number of cores you chosed is larger than the number of cores in your processor, please entre a lower number"
    read -p  "Specify the number of cores to use in running the MPIc program $1 : " user_core
done

mpic++ -O -o $1 $2 

mpirun -n $user_core ./$1

rm $1