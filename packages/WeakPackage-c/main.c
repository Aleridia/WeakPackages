#include <stdio.h>
#include <string.h>
#include "database.h"

int main() {
    printf("Welcome to the vulnerable project!\n");

    //Buffer overflow
    char buffer[30];
    printf("Enter something (max 30 characters): ");
    gets(buffer); // Unsafe function
    printf("You entered: %s\n", buffer);

    // Demonstrate SQL injection vulnerability
    printf("\nDemonstrating SQL Injection...\n");
    // runQuery("'; DROP TABLE users; --");
    initDatabase();
    runQuery(buffer);
    closeDatabase();

    return 0;
}
