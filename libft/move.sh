list=*_bonus.c
# echo $list
for file in $list
do
    mv $file "${file//_bonus.c/.c}"
done