#include <stdio.h>

void runElection(int votes[5][4]) {
    char candidates[] = {'A', 'B', 'C', 'D'};
    int total_votes_per_candidate[4] = {0};
    int grand_total_votes = 0;

    // a. Display table
    printf("%-10s %-15s %-15s %-15s %-15s\n", "Precinct", "Candidate A", "Candidate B", "Candidate C", "Candidate D");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < 5; i++) {
        printf("%-10d", i + 1);
        for (int j = 0; j < 4; j++) {
            printf(" %-14d", votes[i][j]);
            total_votes_per_candidate[j] += votes[i][j];
            grand_total_votes += votes[i][j];
        }
        printf("\n");
    }
    printf("\n");

    // b. Compute and display total votes and percentage
    printf("Results:\n");
    int max_votes = -1, second_max_votes = -1;
    int winner_index = -1, second_index = -1;

    for (int j = 0; j < 4; j++) {
        double percentage = ((double)total_votes_per_candidate[j] / grand_total_votes) * 100.0;
        printf("Candidate %c: %d votes (%.2f%%)\n", candidates[j], total_votes_per_candidate[j], percentage);

        // Track top two candidates for potential runoff
        if (total_votes_per_candidate[j] > max_votes) {
            second_max_votes = max_votes;
            second_index = winner_index;
            max_votes = total_votes_per_candidate[j];
            winner_index = j;
        } else if (total_votes_per_candidate[j] > second_max_votes) {
            second_max_votes = total_votes_per_candidate[j];
            second_index = j;
        }
    }

    // c & d. Determine winner or runoff
    double winning_percentage = ((double)max_votes / grand_total_votes) * 100.0;
    printf("\nConclusion: ");
    if (winning_percentage > 50.0) {
        printf("Candidate %c is the winner!\n", candidates[winner_index]);
    } else {
        printf("No candidate received over 50%%. A runoff will be held between Candidate %c and Candidate %c.\n", 
               candidates[winner_index], candidates[second_index]);
    }
    printf("======================================================================\n\n");
}

int main() {
    // Initial data
    int votes_scenario_1[5][4] = {
        {192, 48, 206, 37},
        {147, 90, 312, 21},
        {186, 12, 121, 38},
        {114, 21, 408, 39},
        {267, 13, 382, 29}
    };

    // Data with Candidate C receiving 108 votes in Precinct 4
    int votes_scenario_2[5][4] = {
        {192, 48, 206, 37},
        {147, 90, 312, 21},
        {186, 12, 121, 38},
        {114, 21, 108, 39}, // Changed from 408 to 108
        {267, 13, 382, 29}
    };

    // e. Run program for both scenarios
    printf("SCENARIO 1 (Original Data):\n");
    runElection(votes_scenario_1);

    printf("SCENARIO 2 (Modified Data - Candidate C gets 108 in Precinct 4):\n");
    runElection(votes_scenario_2);

    return 0;
}