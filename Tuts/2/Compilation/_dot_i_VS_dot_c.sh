gcc -E hello.c -o ./outputs/hello.i
gcc -E hello.c -o ./outputs/Hello.c
printf "Difference in .i and .c\n"
diff ./outputs/hello.i ./outputs/Hello.c

# Assembly files
gcc -S ./outputs/hello.i -o ./outputs/hello.s
gcc -S ./outputs/Hello.c -o ./outputs/Hello.s
printf "Difference in .s\n"
diff ./outputs/hello.s ./outputs/Hello.s

# object files
gcc -c ./outputs/hello.s -o ./outputs/hello.o
gcc -c ./outputs/Hello.s -o ./outputs/Hello.o

#-----------------------------------------------

# compilation till object of includes.c
gcc -E includes.c -o ./outputs/includes.i
gcc -S ./outputs/includes.i -o ./outputs/includes.s
gcc -c ./outputs/includes.s -o ./outputs/includes.o

#-----------------------------------------------

# Linking, gcc automatically links object files if only object files are passed to them

gcc ./outputs/includes.o ./outputs/hello.o -o _1.out
gcc ./outputs/includes.o ./outputs/Hello.o -o _2.out

 