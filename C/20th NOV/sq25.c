/*Sports Tournament Performance Management System: 
A college organizes a sports tournament involving 10 players.
Each player has Player ID, Name, Number of Matches Played, 
Total Points and Number of Wins. Develop a C program using 
structures and arrays to read and display player information, 
identify the player with the highest points and count players who 
won more than five matches using user-defined functions, and calculate 
the total points scored by all players using recursion.*/
#include <stdio.h>

struct Player {
    char id[20], name[50];
    int matches, points, wins;
};

int highest(struct Player p[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].points > p[max].points)
            max = i;
    }
    return max;
}

int countWinners(struct Player p[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].wins > 5)
            count++;
    }
    return count;
}

int totalPoints(struct Player p[], int n) {
    if (n == 0)
        return 0;
    return p[n - 1].points + totalPoints(p, n - 1);
}

int main() {
    struct Player p[10];
    int i, max;

    for (i = 0; i < 10; i++) {
        printf("\nPlayer %d\n", i + 1);
        printf("Player ID: ");
        scanf(" %19[^\n]", p[i].id);
        printf("Name: ");
        scanf(" %49[^\n]", p[i].name);
        printf("Number of matches played: ");
        scanf("%d", &p[i].matches);
        printf("Total points: ");
        scanf("%d", &p[i].points);
        printf("Number of wins: ");
        scanf("%d", &p[i].wins);
    }

    printf("\nPlayer ID | Name | Matches | Points | Wins\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %d | %d | %d\n",
               p[i].id, p[i].name, p[i].matches,
               p[i].points, p[i].wins);

    max = highest(p, 10);
    printf("\nHighest points: %s (%s), %d\n",
           p[max].name, p[max].id, p[max].points);
    printf("Players with more than 5 wins: %d\n",
           countWinners(p, 10));
    printf("Total points: %d\n", totalPoints(p, 10));

    return 0;
}
