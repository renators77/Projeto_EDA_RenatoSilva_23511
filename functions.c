#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"


/// @brief criar dados da lista cliente em Ficheiro.
/// @param listaClientes 
void criarDadosCliente(cliente *listaClientes)
{
    FILE *ficheiro;
     ficheiro = fopen("listaClientes.txt", "a");
     if (ficheiro != NULL)
     {
        for (cliente* atual = listaClientes; atual != NULL; atual = atual->next) 
        {
            fprintf(ficheiro, "%d,%s,%s\n", listaClientes->nif, listaClientes->nome, listaClientes->morada);
        }
     }
    fclose(ficheiro);
    
}

/// @brief Mostrar dados do cliente
/// @param listaClientes 
void showDadosCliente(cliente *listaClientes)
{
    for (; listaClientes; listaClientes = listaClientes->next)
    {
        printf("nif -> %d | nome -> %s | morada -> %s\n", listaClientes->nif, listaClientes->nome, listaClientes->morada);
    }
    
}

/**
 * @brief  Existe clientes.
 * 
 * @param listaClientes
 * @param nif
 * @return 1 se existir ou 0 caso não exista
 */
int existeCliente(cliente* listaClientes, int nif)
{
    //percorre todos os elementos da lista ate o * apontar para NULL
    while (listaClientes != NULL)
    {
        //compara valor do campo nif da lista com o parametro nif atribuido
        if (listaClientes->nif == nif)
        return (1); //se forem iguais afirma que cliente foi encontrado
        listaClientes = listaClientes->next; //Caso contrário, a função avança para o próximo elemento da lista, apontado pelo campo next do elemento atual.
    }
     return(0); //retorna 0, indicando que o cliente não existe na lista.
        
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
cliente* inserirCliente(cliente* listaClientes, int nif, char nome[], char morada[])
{
    //verifica se já existe um cliente com o mesmo nif
 if (!existeCliente(listaClientes, nif))
 { 
    cliente* novo = malloc(sizeof(struct cliente));//aloca dinamicamente um novo bloco de memória do tamanho da struct cliente esse bloco memoria atribuido como novo
    if (novo != NULL)
    {   
        novo->nif = nif;
        strcpy(novo->nome,nome);
        strcpy(novo->morada,morada);
        novo->next=listaClientes;//faz com que o novo cliente aponte para o antigo início da lista, fica o novo início da lista.
        return(novo);
    }
    
 } else return(listaClientes); //função retorna o * para o início da listaClientes.
 
}




