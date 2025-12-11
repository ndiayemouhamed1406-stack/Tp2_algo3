#include <stdio.h>
#include <stdlib.h>


typedef struct Element {
    int valeur;
    struct Element* suivant;
} Element;

typedef struct File {
    Element* sommet;
    Element* queue;
} File;


File* initFile() {
    File* f = malloc(sizeof(File));
    f->sommet = NULL;
    f->queue = NULL;
    return f;
}


void enfiler(File* f, int x) {
    Element* e = malloc(sizeof(Element));
    e->valeur = x;
    e->suivant = NULL;

    if (f->sommet == NULL) {
        f->sommet = e;
        f->queue = e;
    } else {
        f->queue->suivant = e;
        f->queue = e;
    }
}


int defiler(File* f) {
    if (f->sommet == NULL) return -1;

    Element* tmp = f->sommet;
    int v = tmp->valeur;

    f->sommet = tmp->suivant;
    if (f->sommet == NULL)
        f->queue = NULL;

    free(tmp);
    return v;
}


void afficherFile(File* f) {
    Element* e = f->sommet;
    while (e != NULL) {
        printf("%d ", e->valeur);
        e = e->suivant;
    }
    printf("\n");
}

int tailleFile(File* f) {
    int c = 0;
    Element* e = f->sommet;
    while (e != NULL) {
        c++;
        e = e->suivant;
    }
    return c;
}


int filesIdentiques(File* f1, File* f2) {
    Element* a = f1->sommet;
    Element* b = f2->sommet;

    while (a != NULL && b != NULL) {
        if (a->valeur != b->valeur) return 0;
        a = a->suivant;
        b = b->suivant;
    }

    return (a == NULL && b == NULL);
}
int main() {
    File* f = initFile();

    enfiler(f, 10);
    enfiler(f, 20);
    enfiler(f, 30);

    printf("File : ");
    afficherFile(f);

    printf("Defile : %d", defiler(f));
    printf("File : ");
    afficherFile(f);

    printf("Taille : %d", tailleFile(f));

    File* f2 = initFile();
    enfiler(f2, 20);
    enfiler(f2, 30);

    printf("Files identiques  %d", filesIdentiques(f, f2));

    return 0;
}
