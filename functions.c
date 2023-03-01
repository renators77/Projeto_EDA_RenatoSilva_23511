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
        listaClientes = inserirCliente(listaClientes, nif, nome, morada);
    }

    fclose(ficheiro);

}
/**
 * @brief  inserçao de clientes.
 * 
 * @param listaClientes
 * @param nif
 * @param nome
 * @param morada 
 * @return novo
 */
cliente* inserirCliente(cliente *listaClientes, int nif, char nome[], char morada[])
{
 if (!existeCliente(listaClientes, nif))
 { 
    cliente* novo = malloc(sizeof(struct cliente));//aloca dinamicamente um novo bloco de memória de tamanho da estrutura cliente esse bloco memoria atribuido como novo
    if (novo != NULL)
    {
        novo->nif = nif;
        strcpy(novo->nome,nome);
        strcpy(novo->morada,morada);
        novo->next=listaClientes;//faz com que o novo elemento aponte para o antigo início da lista, fica o novo início da lista.
        return(novo);
    }
    
 } else return(listaClientes); //função retorna o * para o novo início da lista listaClientes.
 
}

// Determinar existência do 'codigo' na lista ligada 'listaClientes'
// devolve 1 se existir ou 0 caso contrário
int existeCliente(cliente* listaClientes, int nif)
{
    while (listaClientes != NULL)
    {
      if (listaClientes->nif == nif)
      {
        return(1);
        listaClientes = listaClientes->next;
      }
     return(0);   
    }
    
}


