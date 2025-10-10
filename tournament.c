#include <stdlib.h>
#include "teams.c"

enum tournament_type {
    rr, single_elim, double_elim
};
struct match {
    team team_a;
    team team_b;
} typedef match;

struct tournament {
    team* teams;
    int no_of_teams;
    int format;
    match* matches;
    int no_of_matches;
} typedef tournament;

tournament create_tournament(team* teams, int no_of_teams, int format) {
    tournament t;
    t.format = format;
    t.no_of_teams = no_of_teams;
    t.teams = teams;
    int* rotator_tracker = malloc(sizeof(int)*no_of_teams);
    for ( int i = 0; i < no_of_teams; i++) {
        rotator_tracker[i] = i+1;
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

                //Teams 1 und 2 müssen aus dem array mit der Menge an allen Teams herausgesucht werden
                //Der rotator tracker bestimmt den status des "Drehens" des teams für die round robin generation und bestimmt damit welches team an welche stelle gehört und aus dem array muss genau das eine team mit der ID, die der rotator tracker an dieser stelle hat gefunden werden
                //find team 1
                team tmp;
                for(int t = 0; t < no_of_teams; t++) {
                    if(teams[t].team_id == rotator_tracker[2*j]) {
                        tmp = teams[t];
                        break;
                    }
                }
                t.matches[i*(no_of_teams/2)+j].team_a = tmp;
                //find team 2
                for(int t = 0; t < no_of_teams; t++) {
                    if(teams[t].team_id == rotator_tracker[2*j+1]) {
                        tmp = teams[t];
                        break;
                    }
                }
                t.matches[i*(no_of_teams/2)+j].team_b = tmp;
                
                //because of the way the round robin bracket is generated here the team at position 0 in the "teams" array will always be on the left side of the fixture
                //to have the bracket look a bit more natural it will be randomly swapped right in 50% of the matches
                if(j == 0) {
                    int decider = rand() % 100;
                    printf("%d\n", decider);
                    if(decider > 50) {
                        team swapper = t.matches[i * (no_of_teams/2)].team_a;
                        t.matches[i * no_of_teams/2].team_a = t.matches[i * (no_of_teams/2)].team_b;
                        t.matches[i * (no_of_teams/2)].team_b = swapper;
                    }
                }
            }
            //nach jedem Spieltag werden alle teams rotiert, außer Team 1 -> erzeugt jede mögliche Paarung von n Teams in n-1 matches, wenn man Heim- und Auswärtsspiele als das Gleiche Match betrachtet
            //Das Team an erster Stelle wird vorgemerkt, danach werden alle anderen teams einen Platz nach vorn rotiert.
            //genau im letzten Schritt wird das vorgemerkte Team hinten neu angestellt
            int tmp = rotator_tracker[1];
            for(int i = 1; i < no_of_teams; i++) {
                if((i+1) == no_of_teams) {
                    rotator_tracker[i] = tmp;
                    break;
                }
                rotator_tracker[i] = rotator_tracker[i+1]; 
            }
        }
    }
    return t;
};