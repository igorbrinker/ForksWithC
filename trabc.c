#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vertex{
    int id;
    char *identifier;
    struct vertex **edges;
} Vertex;

typedef struct fork{
    int id;
    struct vertex **vertexes;
} Fork;

void initialize(Fork *f){
    printf("1");
    f->id = 4;
    f->vertexes = calloc(4, sizeof(Vertex));
    for(int i = 0; i < 4; i++){
        printf("2");
        f->vertexes[i] = malloc(sizeof(Vertex));
        f->vertexes[i]->edges = calloc(3, sizeof(Vertex));
    }
}

void insert(Fork *f, char identifier[]){
    printf("3");
    for(int i = 0; i < f->id; i++){
        printf("4");
        if(f->vertexes[i]->identifier == NULL){
            printf("5");
            f->vertexes[i]->identifier == identifier;
            f->vertexes[i]->id = 0;
            printf("6");
            break;
        }
    }
}

void createEdge(Fork *f, char source[], char destination[]){
    printf("7");
    Vertex *vertex_source = NULL, *vertex_destination = NULL;
    for(int i = 0; i < f->id; i++){
        printf("8");
        if(f->vertexes[i]->identifier == source){
            printf("9");
            vertex_source = f->vertexes[i];
        }
        if(f->vertexes[i]->identifier == destination){
            printf("10");
            vertex_destination = f->vertexes[i];
        }
    }
    if(vertex_source == NULL || vertex_destination == NULL){
        printf("11");
        printf("ERRO: origem ou destino do vertice não encontrado(s)!\n");
    } else{
        printf("12");
        int after_source = vertex_source->id;
        vertex_source->edges[after_source] = vertex_destination;
        vertex_source->id++;

        int after_destination = vertex_destination->id;
        vertex_destination->edges[after_destination] = vertex_source;
        vertex_destination->id++;
        printf("13");
    }
}

void print(Fork *f){
    printf("GRAFO DE VERTICES\n");
    for(int i = 0; i < f->id; i++){
        printf("15");
        if(f->vertexes[i]->identifier != NULL){
            printf("16");
            printf("[%s]", f->vertexes[i]->identifier);
            for(int i = 0; i < f->vertexes[i]->id; i++){
                printf("17");
                printf("-> (%s)", f->vertexes[i]->edges[i]->identifier);
            }
            printf("->[NULL]\n");
        }
    }
}

int main(void){
    printf("18");
    Fork f;
    printf("19");
    initialize(&f);
    printf("20");
    insert(&f, "Ana");
    insert(&f, "Pedro");
    insert(&f, "Marta");
    insert(&f, "Bento");
    printf("21");
    
    createEdge(&f, "Pedro", "Ana");
    createEdge(&f, "Ana", "Marta");
    createEdge(&f, "Bento", "Ana");
    printf("22");

    print(&f);
    printf("23");
    return 0;
}
