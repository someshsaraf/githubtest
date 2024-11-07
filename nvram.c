#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nvram.h"

#define MAX_NVRAM_SIZE 100
#define MAX_KEY_SIZE   50
#define MAX_VALUE_SIZE 50

// Simulating NVRAM as an in-memory key-value store
static struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} nvram_store[MAX_NVRAM_SIZE];

static int initialized = 0;

int nvram_init(void) {
    if (initialized) {
        printf("NVRAM already initialized.\n");
        return 0; // Already initialized
    }

    // Simulate initialization by clearing the store
    memset(nvram_store, 0, sizeof(nvram_store));
    initialized = 1;
    printf("NVRAM initialized.\n");
    return 0;
}

int nvram_set(const char* key, const char* value) {
    if (!initialized) {
        printf("Error: NVRAM is not initialized.\n");
        return -1; // Error: not initialized
    }

    // Simple check to prevent exceeding store size
    for (int i = 0; i < MAX_NVRAM_SIZE; i++) {
        if (strlen(nvram_store[i].key) == 0) {
            strncpy(nvram_store[i].key, key, MAX_KEY_SIZE);
            strncpy(nvram_store[i].value, value, MAX_VALUE_SIZE);
            printf("Set: %s = %s\n", key, value);
            return 0;
        }
    }

    printf("Error: NVRAM store full.\n");
    return -1; // Error: store full
}

int nvram_get(const char* key, char* value, size_t max_len) {
    if (!initialized) {
        printf("Error: NVRAM is not initialized.\n");
        return -1; // Error: not initialized
    }

    for (int i = 0; i < MAX_NVRAM_SIZE; i++) {
        if (strncmp(nvram_store[i].key, key, MAX_KEY_SIZE) == 0) {
            strncpy(value, nvram_store[i].value, max_len);
            value[max_len - 1] = '\0'; // Ensure null termination
            printf("Get: %s = %s\n", key, value);
            return 0;
        }
    }

    printf("Error: Key not found.\n");
    return -1; // Error: key not found
}

int nvram_deinit(void) {
    if (!initialized) {
        printf("Error: NVRAM not initialized.\n");
        return -1; // Error: not initialized
    }

    // Simulate deinitialization
    memset(nvram_store, 0, sizeof(nvram_store));
    initialized = 0;
    printf("NVRAM deinitialized.\n");
    return 0;
}

