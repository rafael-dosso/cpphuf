#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "Fila.h"

using namespace std;

Fila::Fila(): inicio(NULL)
{
}

Fila::Fila(unsigned int* frequencias) {

    this->inicio = NULL;
    for (int i = 0; i < 256; i++)
    {

        if (frequencias[i] != 0)
        {
            Nodo *novo = new Nodo(i, frequencias[i]);
            insira(novo);
        }
    }
}


Item* Fila::inserir(Item* item, Nodo *node){

    if (item == NULL)
    {
        // Inicializa um novo nodo
        item = new Item(node, NULL);

        return item;
    }

    // Se o  novo item da fila deve ficar no inicio
    if (node->getFrq() < (item->getNo()->getFrq()))
    {
        // Seta o primeiro da lista como o novo nodo
        item = new Item(node, item);

        return item;
    }

    else // A posição adequada para inserção é procurada na Fila de Prioridade
    {
        item->setProx(inserir(item->getProx(), node));

        return item;
    }
}

void Fila::insira(Nodo *node)
{
    this->inicio = Fila::inserir(this->inicio, node);
}

Nodo* Fila::desenfileirar() {

    if (this->inicio == NULL) {
        return NULL;
    }


    Nodo* result = this->inicio->getNo();
    this->inicio = this->inicio->getProx();

    return result;
}

int Fila::tamanho() {
    if (this->inicio == NULL)
        return 0;

    Item* aux = this->inicio;
    int retorno = 1;
    while (aux->getProx() != NULL)
    {
        retorno++;
        aux = aux->getProx();
    }

    return retorno;
}
