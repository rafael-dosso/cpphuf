#include <iostream>
#include "Nodo.h"
#include "Item.h"
#include "Fila.h"
#include "Compactador.h"
#include "Descompactador.h"

using namespace std;

int main()
{
    Descompactador* desc = new Descompactador();

    desc->Descompactar();

    return 0;
}
