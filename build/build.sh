#Build examples
ARMGCC=gcc
BIN_LOC=../bin
EXAMPLE_LOC=../examples
LIB_SRC=../libsrc/src/gpio.c
LIB_INC=../libsrc/inc

rm -rf $BIN_LOC/$1.o
$ARMGCC -I$LIB_INC -o $BIN_LOC/$1.o $EXAMPLE_LOC/$1.c $LIB_SRC
echo "Done"
