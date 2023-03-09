#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"

/// @brief Load dados do ficheiro
/// @param listaClientes //lista ligada
/// @return listaClientes devolve inicio da lista
cliente* loadDadosCliente(cliente *listaClientes)
{
    FILE *ficheiro; //declara um * para um ficheiro

    char linha[200]; //string para ler cada linha do ficheiro.
    int opNif; 
    char opNome[50], opMorada[100];
    float opSaldo;
    
    if ((ficheiro = fopen("listaClientes.txt", "r")) == NULL) // abre o arquivo "listaClientes.txt" em modo de leitura "r"
    {
        printf("Erro ao abrir o arquivo listaClientes.txt\n");
        return listaClientes;
    }

while (fgets(linha, 200, ficheiro) != NULL) {
    sscanf(linha, "Nif -> %d | Nome -> %[^|]| Morada -> %[^|]| Saldo -> %f\n", &opNif, opNome, opMorada, &opSaldo);

    listaClientes = inserirCliente(listaClientes, opNif, opNome, opMorada, opSaldo);
}
    fclose(ficheiro);//fecha o ficheiro
    return listaClientes; //devolve o inicio da lista ligada
}

/// @brief Salvar dados da lista cliente em Ficheiro.
/// @param listaClientes 
void salvarDadosCliente(cliente *listaClientes)
{
    FILE *ficheiro; //declara um * para um ficheiro
     ficheiro = fopen("listaClientes.txt", "w"); // abre o arquivo "listaClientes.txt" em modo de escrita "a"
     
     // Verifica se o arquivo foi aberto com sucesso
     if (ficheiro != NULL)
     {
        for (cliente *atual = listaClientes; atual != NULL; atual = atual->next) //percorrer a listaClientes
        {
            fprintf(ficheiro, "Nif -> %d | Nome -> %s | Morada -> %s | Saldo -> %.2f\n", atual->nif, atual->nome, atual->morada, atual->carteira.saldo); //escreve os dados de cada cliente no ficheiro
        }
     }
    fclose(ficheiro); //fecha o ficheiro
    
}

/// @brief Mostrar dados do cliente
/// @param listaClientes 
void showDadosCliente(cliente *listaClientes)
{
    while (listaClientes != NULL)
    {
        printf("nif -> %d | nome -> %s | Morada -> %s | Saldo -> %.2f\n", listaClientes->nif, listaClientes->nome, listaClientes->morada, listaClientes->carteira.saldo);
        listaClientes = listaClientes->next; // Avança para o próximo nó da lista
    }   
}

/**
 * @brief  Existe clientes.
 * 
 * @param listaClientes
 * @param nif
 * @return 1 se existir ou 0 caso não exista
 */
int existeCliente(cliente *listaClientes, int nif)
{
    //percorre todos os elementos da lista ate o * apontar para NULL
    while (listaClientes != NULL)
    {
        //compara valor do campo nif da lista com o parametro nif atribuido
        if (listaClientes->nif == nif) return (1); //se forem iguais afirma que cliente foi encontrado
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
cliente* inserirCliente(cliente *listaClientes, int nif, char nome[], char morada[], float saldo)
{
    //verifica se já existe um cliente com o mesmo nif
 if (!existeCliente(listaClientes, nif))
 { 
    cliente *novo = malloc(sizeof(struct cliente));//aloca dinamicamente um novo bloco de memória do tamanho da struct cliente esse bloco memoria atribuido como novo
    if (novo != NULL)//verifica
    {   
        novo->nif = nif;
        strcpy(novo->nome,nome);
        strcpy(novo->morada,morada);
        novo->carteira.saldo = saldo;
        novo->next=listaClientes;//faz com que o novo cliente aponte para o antigo início da lista, fica o novo início da lista.
        return(novo); //return do *
    }
    
 } else return(listaClientes); //função retorna o * para o início da listaClientes caso o nif exista.

}
/// @brief Remover Cliente por Nif
/// @param listaclientes * para o inicio da listaClientes
/// @param nif do cliente a ser removido
/// @return * atualizado para o inicio da listaClientes 
cliente *removerCliente(cliente *listaClientes, int nif)
{
    // verifica se o cliente a ser removido existe na lista ligada listaClientes
    if (existeCliente(listaClientes, nif)) 
    {
        cliente *anterior=listaClientes, *atual=listaClientes, *aux; //*anterior para manter a referencia do * anterior que se pretende remover| atual percorre a lista | * aux mantem temporariamente a referencia ao nó seguinte e ao nó a ser removido 

        if (atual== NULL) return (NULL); //verifica se a lista ligada listaClientes está vazia
        else if (atual->nif == nif) //remoção do 1º Registo
        {
         aux = atual->next;
         free(atual); //Liberta a memoria que estava a ser ocupada
         return(aux); //atualiza para o endereço seguinte 
        }
        else
        {
         while ((atual != NULL) && (atual->nif != nif)) //percorre a listaClientes ate encontrar o nif a ser removido ou até chegar ao final da listaClientes
           {
             anterior = atual;
             atual = atual->next;
            }
         if (atual == NULL) return(listaClientes); //percorre a lista ligada listaClientes caso não exista o cliente return inicio listaClientes
         else
           {
             anterior->next = atual->next; //* atual encontrar nif a ser removido | função atualiza os endereços dos * anterior e seguinte 
             free(atual); //Liberta a memoria que estava a ser ocupada
             return(listaClientes); //retorna o *lista ligada listaClientes para o seu inicio 
            }        
        }
    }  else return(listaClientes); //devolve o inicio da lista ligada listaClientes
}

cliente* alterarCliente(cliente *listaClientes, int nif, char nome[], char morada[])
{
    // verifica se o cliente a ser alterado existe na lista ligada listaClientes
    if (existeCliente(listaClientes, nif))
    {
        cliente *atual = listaClientes;

        // percorre a lista até encontrar o cliente a ser alterado
        while ((atual != NULL) && (atual->nif != nif))
        {
            atual = atual->next;
        }

        if (atual != NULL)
        {
            // atualiza os dados do cliente
            strcpy(atual->nome, nome);
            strcpy(atual->morada, morada);
        }
        return listaClientes;
        
    } else return (listaClientes);
}






