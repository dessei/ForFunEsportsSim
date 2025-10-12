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
    my_arr[2].name = "Movistar KOI"; my_arr[2].short_name = "MKOI";
    my_arr[3].name = "Karmine Corp"; my_arr[3].short_name = "KC";
    printf("test\n");
    tournament t = create_tournament(my_arr, NUMBER_OF_TEAMS, rr, bo3);
    printf("test\n");
    play_tournament(t);
    print_table(t);
    free_tournament(t);
    return 0;
}