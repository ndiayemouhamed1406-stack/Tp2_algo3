#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Client {
    int num;
    char nom[20];
    char prenom[20];
    float solde;
    struct Client* suivant;
} Client;

typedef struct FileC {
    Client* sommet;
    Client* queue;
} FileC;


FileC* initFileC() {
    FileC* f = malloc(sizeof(FileC));
    f->sommet = NULL;
    f->queue = NULL;
    return f;
}


void ajouterClient(FileC* f, int num, char* nom, char* prenom, float solde) {
    Client* c = malloc(sizeof(Client));
    c->num = num;
    c->solde = solde;
    c->suivant = NULL;

    if (f->sommet == NULL)
        f->sommet = f->queue = c;
    else {
        f->queue->suivant = c;
        f->queue = c;
    }
}


Client* servir(FileC* f) {
    if (f->sommet == NULL) return NULL;

    Client* c = f->sommet;
    f->sommet = c->suivant;

    if (f->sommet == NULL)
        f->queue = NULL;

    return c;
}


void afficherClients(FileC* f) {
    Client* c = f->sommet;
    while (c != NULL) {
        printf("[%d] %s %s - %.2f\n", c->num, c->nom, c->prenom, c->solde);
        c = c->suivant;
    }
}


int main() {
    FileC* f = initFileC();

    ajouterClient(f, 1, "Diallo", "Moussa", 150000);
    ajouterClient(f, 2, "Ndiaye", "Awa", 90000);
    ajouterClient(f, 3, "Sarr", "Fatou", 120000);

    printf("Clients en attente : ");
    afficherClients(f);

    Client* servi = servir(f);
    printf("Client servis : %s %s", servi->nom, servi->prenom);

    printf("Clients restants : ");
    afficherClients(f);

    return 0;
}
