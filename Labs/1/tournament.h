#ifndef TOURNAMENT_H
#define TOURNAMENT_H

typedef struct Match {
  int p1;
  int p2;
  int winner;
  int stage;
  struct Match *prev1;
  struct Match *prev2;
  struct Match *next;
} Match;

typedef struct Tournament {
  int num_matches;
  int num_stages;
  struct Match *matches;
} Tournament;

// typedef is useful now since we do not have to write  struct Tournament everytime

void print_match(Match *m);
void create_tournament(int n, Tournament *t);
Match *get_last_match(int p, Tournament *t);
void add_match(int p1, int p2, int w, Tournament *t);
void print_tournament(Tournament *t);
void print_stages(Tournament *t);
void print_history(int p, Tournament *t);

#endif