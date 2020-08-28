#include <stdio.h>
#include <stdlib.h>

typedef struct vertex{
    int id;
    char *identifier;
    struct vertex **edges;
} Vertex;

typedef struct fork{
    int id;
    struct vertex **vertexes;
} Fork;

void initialize(fork *f){
    f->id = 4;
    f->vertexes = calloc(4, sizeof(Vertex));
    for(int i = 0; i < 4; i++){
        f->vertexes[i] = malloc(sizeof(Vertex));
        f->vertexes[i]->edges = calloc(3, sizeof(Vertex));
    }
}

void insert(Fork *f, char identifier[]){
    for(int i = 0; i < f->n; i++){
        if(f->vertexes[i]->identifier == NULL){
            f->vertexes[i]->identifier == identifier;
            f->vertexes[i]->n = 0;
            break;
        }
    }
}

void createEdge(fork *f, char source[], char destination[]){
    Vertex *vertex source = NULL, *vertex destination = NULL;
    for(int i = 0; i < f->n; i++){
        if(f->vertexes[i]->identifier == source){
            vertex_source = f->vertexes[i];
        }
        if(f->vertexes[i]->identifier == destination){
            vertexes_destination = f->vertexes[i];
        }
        
    }

    
}