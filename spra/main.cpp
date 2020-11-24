#!/bin/bash
for((i=1;i<=1000;++i));
do
echo Test$i;
    echo $i*$i+1234 | ./gen>in/in$i.in
    ./brut < in/in$i.in > out/bout$i.out
    ./wzor < in/in$i.in > out/wout$i.out
    diff out/bout$i.out out/wout$i.out
done;
