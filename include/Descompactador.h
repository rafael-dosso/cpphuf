#ifndef DESCOMPACTADOR
#define DESCOMPACTADOR

#include "Nodo.h"
#include "Fila.h"
#include "Item.h"
#include <iostream>

using namespace std;

class Descompactador
{
    private:
        // Fila de prioridade
        Fila* fila;
        // Nodo raiz da �rvore de Huffman
        Nodo* raiz;
        // Vetor com as frequencias de cada byte
        unsigned int *frequencias;
        char** tabelaDeCaminhos;
        unsigned char bitsAIgnorar;

        void montarArvore();
        void alocaTabela();
        void gerarNovoArq(FILE*, FILE*);
        unsigned char getBit(unsigned char, int);

    public:
        Descompactador();
        ~Descompactador();
        void Descompactar();
};

#endif
