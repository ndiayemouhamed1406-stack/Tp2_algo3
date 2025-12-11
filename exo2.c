#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


Pile* inverserPile(Pile* p) {
    Pile* q = initPile();
    while (p->sommet != NULL) {
        empiler(q, depiler(p));
    }
    return q;
}


int verifParentheses(char* ch) {
    Pile* p = initPile();

    for (int i = 0; ch[i] != '\0'; i++) {
        char c = ch[i];

        if (c=='(' || c=='[' || c=='{')
            empiler(p, c);

        else if (c==')' || c==']' || c=='}') {
            if (p->sommet == NULL) return 0;
            char o = depiler(p);

            if ((o=='(' && c!=')') ||
                (o=='[' && c!=']') ||
                (o=='{' && c!='}'))
                return 0;
        }
    }
    return (p->sommet == NULL);
}


void enBinaire(int n) {
    Pile* p = initPile();

    while (n > 0) {
        empiler(p, n % 2);
        n /= 2;
    }
    while (p->sommet != NULL)
        printf("%d", depiler(p));
    printf("\n");
}
void inverserChaine(char* ch) {
    Pile* p = initPile();
    for (int i = 0; ch[i] != '\0'; i++)
        empiler(p, ch[i]);

    while (p->sommet != NULL)
        printf("%c", depiler(p));
    printf("\n");
}


int main() {
    printf("Inverser une pile ");
    Pile* p = initPile();
    empiler(p, 1);
    empiler(p, 2);
    empiler(p, 3);
    Pile* inv = inverserPile(p);

    while (inv->sommet != NULL)
        printf("%d ", depiler(inv));
    printf("\n");

    printf(" Parentheses");
    printf("%d\n", verifParentheses("{( [])}"));



    return 0;
}
