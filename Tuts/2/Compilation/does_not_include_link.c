#include <stdio.h>

int main() {
    sad("World"); // This will not work due to implict defination assumption and not finding the function during the linking process
    printf("\nThis will not compile\n");
}