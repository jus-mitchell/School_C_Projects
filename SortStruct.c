/*****************************************************************************
 * Justice Mitchell
 *****************************************************************************/
#include <stdio.h>
#include <string.h>
// Structure Definitions
typedef struct _Team
{
    char city[256];
    char name[256];
} Team;

typedef struct _Player
{
	char firstName[256];
    char lastName[256];
    long salary;
    Team team;
} Player;

// Function Prototypes
void sortByFirstName(Player * players);
void sortByLastName(Player * players);
void sortBySalary(Player * players);
void printPlayerArray(Player * array);
// Main Function calls all the other functions
 int main(void)
 {
	// Array of type Player
	Player players[] = 
    {
		{"Corey","Seager",32500000,{"Texas","Rangers"}},
		{"Stephen","Strasburg",35000000,{"Washington","Nationals"}},
		{"Gerrit","Cole",36000000, {"New York","Yankees"}},
		{"Mike","Trout",35500000, {"Los Angeles","Angels"}},
		{"Carlos","Correa",35100000,{"Minnesota","Twins"}},
		{"Anthony","Rendon",35000000,{"Los Angeles","Angels"}},
		{"Francisco","Lindor",34100000,{"New York","Mets"}},
		{"Trevor","Bauer",34000000,{"Los Angeles","Dodgers"}},
		{"Nolan","Arenado",32500000,{"St. Louis","Cardinals"}},
		{"Max","Scherzer",43300000,{"New York","Mets"}},
    };

	//Prints the original array
	printf("Players:\n");
	printPlayerArray(players);
	printf("\n");
	//prints the array after being sorted by lastname
	printf("Players by Lastname:\n");
	sortByLastName(players);
	printPlayerArray(players);
	printf("\n");
	//prints the array after being sorted by firstname
	printf("Players by Firstname:\n");
	sortByFirstName(players);
	printPlayerArray(players);
	printf("\n");
	//prints the array after being sorted by salary
	printf("Players by Salary:\n");
	sortBySalary(players);
	printPlayerArray(players);
	printf("\n");

 }
//Function sorts a Player array by first name
 void sortByFirstName(Player * players) {
	for(int i = 0; i < 10; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
        if(strcmp(players[j].firstName, players[j+1].firstName) > 0){
            Player temp = players[j];
            players[j] = players[j+1];
            players[j+1] = temp;
        }
        }
    }
 }
//Function sorts a Player array by last name
 void sortByLastName(Player * players) {
	for(int i = 0; i < 10; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
        if(strcmp(players[j].lastName, players[j+1].lastName) > 0){
            Player temp = players[j];
            players[j] = players[j+1];
            players[j+1] = temp;
        }
        }
    }
 }
//Function sorts a Player array by salary
void sortBySalary(Player * players) {
	for(int i = 0; i < 10; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
        if(players[j].salary > players[j+1].salary){
            Player temp = players[j];
            players[j] = players[j+1];
            players[j+1] = temp;
        }
        }
    }
}
//Function prints a Player array
void printPlayerArray(Player * players) {
	printf("%16s %16s %16s %16s %16s\n", "First Name", "Last Name", "Salary", "Team City", "Team Name");
	for(int i = 0; i < 10; i++) {
		printf("%16s %16s %16ld %16s %16s\n", players[i].firstName, players[i].lastName, players[i].salary, players[i].team.city, players[i].team.name);
	}
}
