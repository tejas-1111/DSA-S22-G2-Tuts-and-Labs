#include <stdio.h>

int main() {
    hello("World"); // This will work due to implict defination assumption and finding the function during the linking process, still throws a warning
    printf("\nThis will compile with errors\n");
}