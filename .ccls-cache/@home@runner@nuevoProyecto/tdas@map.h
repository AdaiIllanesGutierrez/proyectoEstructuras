// map.h
#ifndef MAP_H
#define MAP_H

typedef struct MapNode {
    char *key;
    void *data;
    struct MapNode *next;
} MapNode;

typedef struct {
    MapNode **buckets;
    int capacity;
    int (*hash_function)(void *);
    int (*is_equal_function)(void *, void *);
} Map;

Map *map_create(int (*is_equal_function)(void *, void *));
void map_insert(Map *map, char *key, void *data);
void *map_search(Map *map, char *key);
void map_clean(Map *map);

#endif // MAP_H
