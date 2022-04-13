#include "tournament.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void print_match(Match *m) {
  printf("Match between %d and %d, winner is %d\n", m->p1, m->p2, m->winner);
}

void create_tournament(int n, Tournament *t) {
  t->num_matches = n - 1;
  t->num_stages = log2(n);
  t->matches = calloc(t->num_matches, sizeof(Match));

  Match default_match;
  default_match.p1 = -1;
  default_match.p2 = -1;
  default_match.winner = -1;
  default_match.stage = -1;
  default_match.prev1 = NULL;
  default_match.prev2 = NULL;
  default_match.next = NULL;

  for (int i = 0; i < t->num_matches; ++i) {
    t->matches[i] = default_match;
    // Filling with a dummy value to indicate that it is unfilled
  }
}

Match *get_last_match(int p, Tournament *t) {
  for (int i = 0; i < t->num_matches; ++i) {
    if ((t->matches[i].p1 == p || (t->matches[i].p2 == p)) &&
        t->matches[i].next == NULL) {
      return &(t->matches[i]);
    }
    if (t->matches[i].winner == -1) {
      return NULL;
    }
  }
}

void add_match(int p1, int p2, int w, Tournament *t) {
  Match *prev1 = get_last_match(p1, t);
  Match *prev2 = get_last_match(p2, t);

  Match new_match;
  new_match.p1 = p1;
  new_match.p2 = p2;
  new_match.winner = w;
  new_match.prev1 = prev1;
  new_match.prev2 = prev2;

  if (prev1 == NULL || prev2 == NULL) {
    new_match.stage = 0;
  } else {
    new_match.stage = prev1->stage + 1;
  }

  for (int i = 0; i < t->num_matches; ++i) {
    if (t->matches[i].winner == -1) {
      t->matches[i] = new_match;
      if (prev1 != NULL && prev2 != NULL) {
        prev1->next = &(t->matches[i]);
        prev2->next = &(t->matches[i]);
      }
      break;
    }
  }
}

void print_tournament(Tournament *t) {
  for (int i = 0; i < t->num_matches; ++i) {
    print_match(&(t->matches[i]));
  }
}

void print_stages(Tournament *t) {
  for (int i = 0; i < t->num_stages; ++i) {
    for (int j = 0; j < t->num_matches; ++j) {
      if (t->matches[j].stage == i) {
        print_match(&(t->matches[j]));
      }
    }
  }
}

void print_history(int p, Tournament *t) {
  Match *last_match;
  for (int i = 0; i < t->num_matches; ++i) {
    if (t->matches[i].p1 == p || t->matches[i].p2 == p) {
      if (t->matches[i].winner != p) { // Will not be true for overall winner
        last_match = &(t->matches[i]);
        break;
      }
      if (t->matches[i].next == NULL) { // Will only be true for overall winner
        last_match = &(t->matches[i]);
        break;
      }
    }
  }
  Match *curr_match = last_match;
  while (curr_match->prev1 != NULL || curr_match->prev2 != NULL) {
    if (curr_match->p1 == p) {
      curr_match = curr_match->prev1;
    } else {
      curr_match = curr_match->prev2;
    }
  }
  while (curr_match != NULL) {
    print_match(curr_match);
    if (curr_match->winner == p) {
      curr_match = curr_match->next;
    } else {
      break;
    }
  }
}