printf "Preprocessing\n"
gcc -E does_not_include.c -o ./outputs/does_not_include.i
printf "Compiling\n________\n"
gcc -S ./outputs/does_not_include.i -o ./outputs/does_not_include.s # Errors and warnings in code are found here
printf "\n__________\nAssembling"
gcc -c ./outputs/does_not_include.s -o ./outputs/does_not_include.o
printf "\nLinking\n"
gcc ./outputs/hello.o ./outputs/does_not_include.s -o _3.out