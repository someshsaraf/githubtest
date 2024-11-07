#ifndef NVRAM_H
#define NVRAM_H

// Initialize the NVRAM system
int nvram_init(void);

// Set a value in NVRAM by key
int nvram_set(const char* key, const char* value);

// Get a value from NVRAM by key
int nvram_get(const char* key, char* value, size_t max_len);

// Deinitialize the NVRAM system
int nvram_deinit(void);

#endif // NVRAM_H

