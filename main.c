#include <stdio.h>
#include "tournament.c"

int main() {
    int my_arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,69,420, 88};
    printf("test\n");
    tournament t = create_tournament(my_arr, 18, rr);
    printf("%d \n",t.teams[3]);
    printf("test\n");
    for(int i = 0; i < t.no_of_matches; i++) {
        int team_eins = t.matches[i].team_a;
        int team_swei = t.matches[i].team_b;
        printf("Match %d: %d vs. %d\n", i+1, team_eins, team_swei);
    }
    return 0;
}