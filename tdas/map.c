
// map.c
#include "map.h"
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 101

static int hash_function(void *key) {
    char *str = (char *)key;
    int hash = 0;
    while (*str) {
        hash = (hash * 31) + *str++;
    }
    return hash;
}

Map *map_create(int (*is_equal_function)(void *, void *)) {
    Map *map = (Map *)malloc(sizeof(Map));
    map->capacity = INITIAL_CAPACITY;
    map->buckets = (MapNode **)calloc(map->capacity, sizeof(MapNode *));
    map->hash_function = hash_function;
    map->is_equal_function = is_equal_function;
    return map;
}

void map_insert(Map *map, char *key, void *data) {
    int bucket_index = map->hash_function(key) % map->capacity;
    MapNode *new_node = (MapNode *)malloc(sizeof(MapNode));
    new_node->key = strdup(key);
    new_node->data = data;
    new_node->next = map->buckets[bucket_index];
    map->buckets[bucket_index] = new_node;
}

void *map_search(Map *map, char *key) {
    int bucket_index = map->hash_function(key) % map->capacity;
    MapNode *current = map->buckets[bucket_index];
    while (current) {
        if (map->is_equal_function(current->key, key)) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

void map_clean(Map *map) {
    for (int i = 0; i < map->capacity; i++) {
        MapNode *current = map->buckets[i];
        while (current) {
            MapNode *to_free = current;
            current = current->next;
            free(to_free->key);
            free(to_free);
        }
    }
    free(map->buckets);
    free(map);
}