#ifndef slib
#define slib
#include <stdlib.h>
#endif
#ifndef tim
#include <time.h>
#define tim
#endif
#ifndef io
#define io
#include <stdio.h>
#endif 
#ifndef tournament_c
#define tournament_c
#include "tournament.c"
#endif
#define NUMBER_OF_TEAMS 8

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
    my_arr[4].name = "SK Gaming"; my_arr[4].short_name = "SK";
    my_arr[5].name = "Natus Vincere"; my_arr[5].short_name = "NAVI";
    my_arr[6].name = "BDS esports"; my_arr[6].short_name = "BDS";
    my_arr[7].name = "Team Heretics"; my_arr[7].short_name = "TH";
    //my_arr[8].name = "GiantX"; my_arr[8].short_name = "GX";
    //my_arr[9].name = "Team Vitality"; my_arr[9].short_name = "VIT";
    printf("test\n");
    tournament t = create_tournament(my_arr, NUMBER_OF_TEAMS, single_elim, bo3);
    play_tournament(t);
    //print_table(t);
    free_tournament(t);
    return 0;
}