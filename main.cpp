#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <conio.h>
#include "Compactador.h"
#include "Descompactador.h"

using namespace std;

int main()
{
    int opcao = 0;

    do
    {
        system("cls");
        cout << "Algoritmo de Huffman - Compactacao de arquivos\n"
             << "\n------------------------------\n"
             << "1 - Compactador de arquivos\n"
             << "2 - Descompactador de arquivos \n"
             << "3 - Sair \n"
             << "------------------------------\n"
             << "Escolha uma opcao: ";

        cin >> opcao;

        cout << "\n";

        Compactador     *compactador    = new Compactador();
        Descompactador  *descompactador = new Descompactador();

        switch (opcao)
        {
            case 1:
                (*compactador).Compactar();
                break;

            case 2:
                (*descompactador).Descompactar();
                break;
        }

        if (opcao != 3)
        {
            cout << "\n";
            cout << "\nPressione ENTER para continuar. ";
            char esperar;
            getch();
        }

    } while (opcao != 3);

    cout << "Programa finalizado com exito.\n";
    return 0;
}
