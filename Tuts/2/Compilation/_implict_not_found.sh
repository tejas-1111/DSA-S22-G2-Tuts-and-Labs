printf "Preprocessing\n"
gcc -E does_not_include_link.c -o ./outputs/does_not_include_link.i
printf "Compiling\n________\n"
gcc -S ./outputs/does_not_include_link.i -o ./outputs/does_not_include_link.s # Errors and warnings in code are found here
printf "\n__________\nAssembling"
gcc -c ./outputs/does_not_include_link.s -o ./outputs/does_not_include_link.o
printf "\nLinking\n"
gcc ./outputs/hello.o ./outputs/does_not_include_link.s -o _4.out