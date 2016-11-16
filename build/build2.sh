#Build examples
ARMGCC=arm-linux-gnueabihf-gcc
BIN_LOC=../bin
EXAMPLE_LOC=../examples
LIB_SRC1=../libsrc/src/gpio.c
LIB_SRC2=../libsrc/src/7segled.c
LIB_SRC3=../libsrc/src/lcd.c
LIB_INC=../libsrc/inc

rm -rf $BIN_LOC/$1.o
#echo "$ARMGCC -I$LIB_INC -o $BIN_LOC/$1.o $EXAMPLE_LOC/$1.c $LIB_SRC2 $LIB_SRC1"
$ARMGCC -I$LIB_INC -o $BIN_LOC/$1.o $EXAMPLE_LOC/$1.c $LIB_SRC3 $LIB_SRC2 $LIB_SRC1
echo "Done"
