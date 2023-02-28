#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"

/**
 * @brief Função para Ler os dados do ficheiro listaClientes.txt
 * 
 * @return 
 */
cliente* dadosCliente(cliente *listaClientes)
{
    FILE *ficheiro;
    char line[20];
    int nif; char nome; char morada;
    ficheiro = fopen("listaClientes.txt", "r");

    while (!feof(ficheiro))
    {
        fgets(line, 20,ficheiro);
        sscanf(line, "%d,%d,%d", &nif, &nome, &morada);
        listaClientes = headops_insert(listaClientes, nif);
        listaClientes = insert(listaClientes, nif, nome, morada);
    }

    fclose(ficheiro);
    return ficheiro;
}