#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int valeur;
    struct Element* suivant;
} Element;

typedef struct Pile {
    Element* sommet;
} Pile;

Pile* initPile() {
    Pile* p = malloc(sizeof(Pile));
    p->sommet = NULL;
    return p;
}

void empiler(Pile* p, int x) {
    Element* e = malloc(sizeof(Element));
    e->valeur = x;
    e->suivant = p->sommet;
    p->sommet = e;
}

int depiler(Pile* p) {
    if (p->sommet == NULL) return -1;

    Element* tmp = p->sommet;
    int v = tmp->valeur;

    p->sommet = tmp->suivant;
    free(tmp);

    return v;
}


void afficherPile(Pile* p) {
    Element* e = p->sommet;
    while (e != NULL) {
        printf("%d ", e->valeur);
        e = e->suivant;
    }
    printf("\n");
}

int taillePile(Pile* p) {
    int c = 0;
    Element* e = p->sommet;

    while (e != NULL) {
        c++;
        e = e->suivant;
    }
    return c;
}


int pilesIdentiques(Pile* p1, Pile* p2) {
    Element* a = p1->sommet;
    Element* b = p2->sommet;

    while (a != NULL && b != NULL) {
        if (a->valeur != b->valeur)
            return 0;
        a = a->suivant;
        b = b->suivant;
    }

    return (a == NULL && b == NULL);
}


int main() {
    Pile* p = initPile();

    empiler(p, 10);
    empiler(p, 20);
    empiler(p, 30);

    printf("Pile : ");
    afficherPile(p);

    printf("Depile : %d\n", depiler(p));

    printf("Pile finale : ");
    afficherPile(p);

    printf("Taille = %d\n", taillePile(p));

    Pile* p2 = initPile();
    empiler(p2, 10);
    empiler(p2, 20);

    printf("Piles identiques ? %d\n", pilesIdentiques(p, p2));

    return 0;
}
