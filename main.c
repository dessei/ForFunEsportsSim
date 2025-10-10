#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "tournament.c"
#define NUMBER_OF_TEAMS 4

int main() {
    srand(time(NULL));
    team* my_arr = malloc(sizeof(team)*NUMBER_OF_TEAMS);
    for (int i = 0; i < NUMBER_OF_TEAMS; i++) {
        my_arr[i].team_id = i+1;
    }
    my_arr[0].name = "G2 Esports";
    my_arr[0].short_name = "G2";
    my_arr[1].name = "Fnatic"; my_arr[1].short_name = "FNC"; 
    my_arr[2].name = "Movistor KOI"; my_arr[2].short_name = "MKOI";
    my_arr[3].name = "Karmine Corp"; my_arr[3].short_name = "KC";
    printf("test\n");
    tournament t = create_tournament(my_arr, NUMBER_OF_TEAMS, rr);
    printf("%d \n",t.teams[3].team_id);
    printf("test\n");
    for(int i = 0; i < t.no_of_matches; i++) {
        int team_eins = t.matches[i].team_a.team_id;
        int team_swei = t.matches[i].team_b.team_id;
        char* team_name_eins = t.matches[i].team_a.name;
        char* team_name_swei = t.matches[i].team_b.name;
        printf("Match %d: %d vs. %d aka %s : %s\n", i+1, team_eins, team_swei, team_name_eins, team_name_swei);
    }
    printf("%s: %s\n", my_arr[0].name, my_arr[0].short_name);
    return 0;
}