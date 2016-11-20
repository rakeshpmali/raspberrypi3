gcc -Wall -c ../libsrc/src/gpio.c -I../libsrc/inc -D_GNU_SOURCE
ar rcs libpigpio.a gpio.o

