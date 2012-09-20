#!/bin/bash
cd assambler
./compile
./a.out Input.txt
cd ..
cp ./assambler/code.o ./cpu/code.o
cd cpu
./compile
./a.out
cd ..
gedit ./cpu/memdump.txt &
