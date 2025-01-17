#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include "database.h"

sqlite3 *db;

void initDatabase() {
    int rc = sqlite3_open("test.db", &db); // Open database
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(1);
    }

    char *errMsg = 0;
    const char *sql =
        "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT);"
        "INSERT OR IGNORE INTO users (id, name) VALUES (1, 'Alice');"
        "INSERT OR IGNORE INTO users (id, name) VALUES (2, 'Bob');"
        "INSERT OR IGNORE INTO users (id, name) VALUES (3, 'Charlie');";

    rc = sqlite3_exec(db, sql, 0, 0, &errMsg); // Execute SQL
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg); // Log error
        sqlite3_free(errMsg);
    } else {
        printf("Database initialized successfully.\n");
    }
}

void runQuery(const char *userInput) {
    // Ensure the database is open
    if (db == NULL) {
        fprintf(stderr, "Database is not initialized.\n");
        return;
    }

    // Construct the SQL query
    char query[256];
    snprintf(query, sizeof(query), "SELECT * FROM users WHERE name='%s';", userInput);

    printf("Executing query: %s\n", query);

    // Prepare the SQL statement
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    // Step through the results and print them
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);                       // Column 0: id
        const unsigned char *name = sqlite3_column_text(stmt, 1);   // Column 1: name

        printf("Result: ID = %d, Name = %s\n", id, name);
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error stepping through results: %s\n", sqlite3_errmsg(db));
    }

    // Finalize the statement
    sqlite3_finalize(stmt);

}

void closeDatabase() {
    sqlite3_close(db);
}
