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
    if(vertex_source == NULL || vertex_destination == NULL){
        printf("ERRO: origem ou destino do vertice não encontrado(s)!\n");
    } else{
        int after_source = vertex_source->n;
        vertex_source->edges[after_source] = vertex_destination;
        vertex_source->n++;

        int after_destination = vertex_destination->n;
        vertex_destination->edges[after_destination] = vertex_source;
        vertex destination->n++;
    }
}

void print(fork *f){
    printf("GRAFO DE VERTICES\n");
    for(int i = 0; i < f->n; i++){
        if(g->vertexes[i]->identifier != NULL){
            printf("[%s]", f->vertexes[i]->identifier);
            for(int i = 0; i < f->vertexes[i]->n; i++){
                printf("-> (%s)", f->vertexes[i]->edges[i]->identifier);
            }
            printf("->[NULL]\n");
        }
    }
}

int main(){
    Fork f;
    initialize(&f);

    insert(&f, "Ana");
    insert(&f, "Pedro");
    insert(&f, "Marta");
    insert(&f, "Bento");
    
    createEdge(&f, "Pedro", "Ana");
    createEdge(&f, "Ana", "Marta");
    createEdge(&f, "Bento", "Ana");

    print(&f);
    return 0;
}