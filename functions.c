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
    char line[100];
    int nif; char nome; char morada;
    ficheiro = fopen("listaClientes.txt", "r");

    while (!feof(ficheiro))
    {
        fgets(line, 100,ficheiro);
        sscanf(line, "%d,%d,%d", &nif, &nome, &morada);
        listaClientes = inserirCliente(listaClientes, int nif, char nome, char morada);
    }

    fclose(ficheiro);
    return ficheiro;


// /**
//  * @brief salva dados do ficheiro txt
//  * 
//  * @param listaClientes 
//  * @return  
//  */
// void saveData(cliente *listaClientes)
// {
//     FILE *ficheiro;
//     ficheiro = fopen("saveddata.txt", "w+");

//     for (; list; list = list->next)
//     {
//         prod *ptr = list->first;
//         for (; ptr;)
//         {
//             fprintf(fp, "%d,%d,%d\n", list->opID, ptr->machine, ptr->time);
//             ptr = ptr->next;
//         }
//     }
//     fclose(fp);
// }


/**
 * @brief  inserçao de clientes.
 * 
 * @param listaClientes
 * @param nif
 * @param nome
 * @param morada 
 * @return novo
 */
cliente *inserirCliente(cliente *listaClientes, int nif, char nome, char morada)
{
    cliente *novo = (cliente *)malloc(sizeof(cliente)); //aloca dinamicamente um novo bloco de memória de tamanho da estrutura cliente esse bloco memoria atribuido como novo
    novo->nif = nif;
    novo->nome = nome;
    novo->morada = morada;
    novo->next = listaClientes;//faz com que o novo elemento aponte para o antigo início da lista, fica o novo início da lista.

    return novo; //função retorna o * para o novo início da lista listaClientes.
}
}