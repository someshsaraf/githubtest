#include <stdio.h>
#include <string.h>
#include "nvram.h"

int main(void) {
    // Initialize the NVRAM system
    if (nvram_init() != 0) {
        return -1; // Initialization failed
    }

    // Set some key-value pairs
    if (nvram_set("username", "john_doe") != 0) {
        return -1; // Setting value failed
    }

    if (nvram_set("password", "1234abcd") != 0) {
        return -1; // Setting value failed
    }

    // Get the values back
    char value[50];
    if (nvram_get("username", value, sizeof(value)) == 0) {
        printf("Retrieved username: %s\n", value);
    }

    if (nvram_get("password", value, sizeof(value)) == 0) {
        printf("Retrieved password: %s\n", value);
    }

    // Deinitialize NVRAM
    if (nvram_deinit() != 0) {
        return -1; // Deinitialization failed
    }

    return 0;
}

