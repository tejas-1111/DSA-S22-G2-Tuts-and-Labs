#include <stdio.h>
#include <string.h>
#include "tournament.h"

int main() {
    char query[1000];
    int n;
    scanf("%s %d", query, &n);
    Tournament spring2022;
    create_tournament(n, &spring2022);

    while (1) {
        scanf("%s", query);
        if (!strcmp(query, "end_matches")) {
            break;
        }
        int p1, p2, w;
        scanf("%d %d %d", &p1, &p2, &w);
        add_match(p1, p2, w, &spring2022);
    }
    while (1) {
        scanf("%s", query);
        if (!strcmp(query, "end")) {
            break;
        }
        if (!strcmp(query, "print_tournament")) {
            print_tournament(&spring2022);
        }
        if (!strcmp(query, "print_stages")) {
            print_stages(&spring2022);
        }
        if (!strcmp(query, "print_history")) {
            int p;
            scanf("%d", &p);
            print_history(p, &spring2022);
        }
    }
}