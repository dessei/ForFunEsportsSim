#include <stdlib.h>
enum tournament_type {
    rr, single_elim, double_elim
};
struct match {
    int team_a;
    int team_b;
} typedef match;

struct tournament {
    int* teams;
    int no_of_teams;
    int format;
    match* matches;
    int no_of_matches;
} typedef tournament;

tournament create_tournament(int* teams, int no_of_teams, int format) {
    tournament t;
    t.format = format;
    t.no_of_teams = no_of_teams;
    t.teams = malloc(sizeof(teams)*no_of_teams);
    for(int i = 0; i < no_of_teams; i++) {
        t.teams[i] = teams[i];
    }
    if(format == rr) {
        t.no_of_matches = (no_of_teams-1) * no_of_teams/2;
        t.matches = malloc(sizeof(match)*(no_of_teams - 1)*(no_of_teams/2));
        for(int i = 0; i < no_of_teams-1; i++) { //jeden Spieltag
            for(int j = 0; j < no_of_teams/2; j++) { //gibt es teams/2 matches
                // i ist gleich der bereits eingetragenen Spieltage
                // Beispiel für 10 Teams
                // Also bei i = 0 -> 1. Spieltag / Match 1 bis 5 (array #0 - 4) 
                //          i = 1 -> 2. Spieltag / Match 6 bis 10 (array #5 - 9) etc...
                //j ist die nummer des matches an einem Spieltag:
                //Also  i = 0, j = 0 -> Spieltag 1 Match 1. Match #1
                //      i = 1, j = 4 -> Spieltag 2 Match 5. Match #10
                //Das heißt das aktuelle Spielt ist nummer i * Spiele pro Spieltag + j
                t.matches[i*(no_of_teams/2)+j].team_a = teams[2*j];
                t.matches[i*(no_of_teams/2)+j].team_b = teams[2*j+1];
            }
            //nach jedem Spieltag werden alle teams rotiert, außer Team 1 -> erzeugt jede mögliche Paarung von n Teams in n-1 matches, wenn man Heim- und Auswärtsspiele als das Gleiche Match betrachtet
            //Das Team an erster Stelle wird vorgemerkt, danach werden alle anderen teams einen Platz nach vorn rotiert.
            //genau im letzten Schritt wird das vorgemerkte Team hinten neu angestellt
            int tmp = teams[1];
            for(int i = 1; i < no_of_teams; i++) {
                if((i+1) == no_of_teams) {
                    teams[i] = tmp;
                    break;
                }
                teams[i] = teams[i+1]; 
            }
        }
    }
    return t;
};