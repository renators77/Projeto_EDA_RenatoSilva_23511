 /**
 * @file functions.c
 * @author Renato Silva (a23511@alunos.ipca.cpt)
 * @brief 
 * @version 0.1
 * @date 2023-02-26
 * 
 * @copyright Copyright (c) 2023
 * https://github.com/renators77/Projeto_EDA_RenatoSilva_23511
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"
#include <ctype.h>

//--------------------------------------------------------------FUNÇÕES PARA O CLIENTE-------------------------------------------------------------------------------------------------------------------------------------//

/**
* @brief Função que Carrega dados de clientes de um Ficheiro.txt ´listaClientes.txt´

* @param listaClientes * para o início da lista de clientes existente

* @return * para o início da listaClientes
*/
cliente* loadDadosCliente(cliente *listaClientes)
{
    FILE *ficheiro; //declara um * para um ficheiro

    char linha[200]; //string para ler cada linha do ficheiro.
    int opNif; 
    char opNome[50], opMorada[100], opLocalC[50];
    float opSaldo;
    
    if ((ficheiro = fopen("listaClientes.txt", "r")) == NULL) // abre o arquivo "listaClientes.txt" em modo de leitura "r"
    {
        printf("Erro ao abrir o arquivo listaClientes.txt\n");
        return listaClientes;
    }

    while (fgets(linha, 200, ficheiro) != NULL) 
    {
        sscanf(linha, "Nif -> %d | Nome -> %[^|]| Morada -> %[^|] | Localizacao -> %49s | Saldo -> %f\n", &opNif, opNome, opMorada, opLocalC, &opSaldo);

        listaClientes = inserirCliente(listaClientes, opNif, opNome, opMorada, opLocalC, opSaldo);
    }
    fclose(ficheiro);//fecha o ficheiro
    return listaClientes; //devolve o inicio da lista ligada
}

/**
 * @brief Função Salvar dados da lista cliente em Ficheiro.
 * 
 * @param listaClientes * para o inicio da listaClientes
 * @param listaClientes pointer to the beginning of the list
 */
void salvarDadosCliente(cliente *listaClientes)
{
    FILE *ficheiro; //declara um * para um ficheiro
     ficheiro = fopen("listaClientes.txt", "w"); // abre o arquivo "listaClientes.txt" em modo de reecrista "w"
     
     // Verifica se o ficheiro foi aberto com sucesso
     if (ficheiro != NULL)
     {
        for (cliente *atual = listaClientes; atual != NULL; atual = atual->next) //percorrer a listaClientes
        {
            fprintf(ficheiro, "Nif -> %d | Nome -> %s | Morada -> %s | Localizacao -> %s | Saldo -> %.2f \n", atual->nif, atual->nome, atual->morada, atual->localizacao, atual->carteira.saldo); //escreve os dados de cada cliente no ficheiro
        }
     }
    fclose(ficheiro); //fecha o ficheiro
    
}

/**
 * @brief Função Mostrar dados do cliente
 * 
 * @param listaClientes * para o inicio da listaClientes
 */
void showDadosCliente(cliente *listaClientes)
{
    while (listaClientes != NULL)
    {
        printf("nif -> %d | nome -> %s | Morada -> %s | Localizacao -> %s | Saldo -> %.2f \n", listaClientes->nif, listaClientes->nome, listaClientes->morada, listaClientes->localizacao ,listaClientes->carteira.saldo);
        listaClientes = listaClientes->next; // Avança para o próximo nó da lista
    }   
}

/**
 * @brief  Função Existe clientes.
 * 
 * @param listaClientes * para o inicio da listaClientes
 * @param nif do cliente a ser verificado
 * 
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
 * @brief  Função inserir clientes.
 * 
 * @param listaClientes * para o inicio da listaClientes
 * @param nif do cliente a ser inserido
 * @param nome do cliente a ser inserido
 * @param morada do cliente a ser inserido
 * @param localCliente do cliente a ser inserido
 * @param saldo do cliente a ser inserido
 * @return novo que aponta para o inicio da listaClientes
 */
cliente* inserirCliente(cliente *listaClientes, int nif, char nome[], char morada[], char localCliente[], float saldo)
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
        strcpy(novo->localizacao,localCliente);
        novo->next=listaClientes;//faz com que o novo cliente aponte para o antigo início da lista, fica o novo início da lista.
        return(novo); //return do *
    }
    
 } else return(listaClientes); //função retorna o * para o início da listaClientes caso o nif exista.

}


/**
 * @brief Função Remover Cliente por Nif
 * 
 * @param listaclientes * para o inicio da listaClientes
 * @param nif do cliente a ser removido
 * 
 * @return * atualizado para o inicio da listaClientes 
 */
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

/**
 * @brief Função alterar Cliente por Nif
 * 
 * @param listaClientes * para o inicio da listaClientes
 * @param nif do cliente a ser removido
 * @param nome nome a ser alterado
 * @param morada morada a ser alterada
 * @param localCliente localizacao a ser alterada
 * @param saldo saldo a ser alterado
 * 
 * @return * atualizado para o inicio da listaClientes 
 */
cliente* alterarCliente(cliente *listaClientes, int nif, char nome[], char morada[], char localCliente[],float saldo)
{
    // verifica se o cliente a ser alterado existe na lista ligada listaClientes
    if (existeCliente(listaClientes, nif))
    {
        cliente *atual = listaClientes; //cria-se *atual para percorrer lista

        // percorre a lista até encontrar o cliente a ser alterado
        while ((atual != NULL) && (atual->nif != nif))
        {
            atual = atual->next;
        }
        //verificação caso seja diferente de NULL modifica
        if (atual != NULL)
        {
            // atualiza os dados do cliente
            strcpy(atual->nome, nome);
            strcpy(atual->morada, morada);
            strcpy(atual->localizacao, localCliente);
            atual->carteira.saldo = saldo;
        }
        return listaClientes; //* atualizado para o inicio da listaClientes 
        
    } else return (listaClientes);
}


//--------------------------------------------------------------FUNÇÕES PARA O CLIENTE-------------------------------------------------------------------------------------------------------------------------------------//


//--------------------------------------------------------------FUNÇÕES PARA OS VEICULOS-----------------------------------------------------------------------------------------------------------------------------------//


/**
* @brief Função que Carrega dados de clientes de um Ficheiro.txt ´listaClientes.txt´

* @param listaClientes * para o início da lista de clientes existente

* @return * para o início da listaClientes
*/
veiculo* loadDadosVeiculo(veiculo *listaVeiculos)
{
    FILE *ficheiro;
    char linha[200];
    int opCodigo; 
    char opTipo[50], opLocalV[50];
    float opBateria, opAutonomia, opCusto;
    
    if ((ficheiro = fopen("listaVeiculos.txt", "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo listaVeiculos.txt\n");
        return listaVeiculos;
    }

    while (fgets(linha, 200, ficheiro) != NULL) 
    {
        sscanf(linha, "Codigo -> %d | Tipo -> %[^|] | Localizacao -> %49s | Bateria -> %f | Autonomia -> %f | Custo -> %f\n", &opCodigo, opTipo, opLocalV, &opBateria, &opAutonomia, &opCusto);

        listaVeiculos = inserirVeiculo(listaVeiculos, opCodigo, opTipo, opLocalV, opBateria, opAutonomia, opCusto);
    }
    
    fclose(ficheiro);
    return listaVeiculos;
}


/**
 * @brief Função Salvar dados da lista Veiculos em ficheiro.
 * 
 * @param listaVeiculos * para o inicio da lista ligada
 */
void salvarDadosVeiculo(veiculo *listaVeiculos)
{
    FILE *ficheiro; //declara um * para um ficheiro
     ficheiro = fopen("listaVeiculos.txt", "w"); // abre o arquivo "listaVeiculo.txt" em modo de ... "w"
     
     // Verifica se o arquivo foi aberto com sucesso
     if (ficheiro != NULL)
     {
        for (veiculo *atual = listaVeiculos; atual != NULL; atual = atual->next) //percorrer a listaClientes
        {
            fprintf(ficheiro, "Codigo -> %d | Tipo -> %s | Localizacao -> %s | Bateria -> %.2f | Autonomia -> %.2f | Custo -> %.2f\n", atual->codigo, atual->tipo, atual->localizacao, atual->bateria, atual->autonomia, atual->custo); //escreve os dados de cada veiculo no ficheiro
        }
     }
    fclose(ficheiro); //fecha o ficheiro
}



/**
 * @brief Função Mostrar Dados Veiculos
 * 
 * @param listaVeiculos * para o inicio da listaVeiculos
 */
void showDadosVeiculo(veiculo *listaVeiculos)
{
    while (listaVeiculos != NULL)
    {
        printf("Codigo -> %d | Tipo -> %s | Localizacao -> %s | Bateria -> %.2f | Autonomia -> %.2f | Custo -> %.2f\n", listaVeiculos->codigo, listaVeiculos->tipo, listaVeiculos->localizacao ,listaVeiculos->bateria, listaVeiculos->autonomia, listaVeiculos->custo);
        listaVeiculos = listaVeiculos->next; //Avança para o próximo nó da lista.
    }
    
}


/**
 * @brief Existe Veiculos
 * 
 * @param listaVeiculos * para o inicio da listaVeiculos
 * @param codigo do veiculo a ser verificado
 * 
 * @return 1 se existir ou 0 caso não exista
 */
int existeVeiculo(veiculo *listaVeiculos, int codigo)
{
    //percorre todos os elementos da lista ate o * apontar para NULL
    while (listaVeiculos != NULL)
    {
        //Compara o valor do campo codigo da lista ligada com o parametro do codigo atribuido.
        if(listaVeiculos->codigo == codigo) return(1); //se forem iguais afirma que veiculo foi encontrado
        listaVeiculos = listaVeiculos->next; //Caso contrário, a função avança para o próximo elemento da lista, apontado pelo campo next do elemento atual.
    }
     return(0);  //retorna 0, indicando que o veiculo não existe na lista.
}




/**
 * 
 * @brief Função Inserir Veiculo
 * 
 * @param listaVeiculos * para o inicio da listaVeiculos
 * @param codigo identificação do veiculo
 * @param tipo do veiculo associado
 * @param localVeiculo do veiculo a ser inserido
 * @param bateria do veiculo associado
 * @param autonomia do veiculo associado
 * @param custo do veiculo associado
 * 
 * @return novo que aponta para o inicio da listaVeiculos
 */
veiculo* inserirVeiculo(veiculo *listaVeiculos, int codigo, char tipo[], char localVeiculo[],float bateria,  float autonomia,  float custo)
{
    //Verifica se já existe um Veiculo com o mesmo Codigo
    if (!existeVeiculo(listaVeiculos, codigo))
    {

        veiculo *novo = malloc(sizeof(struct veiculo)); //aloca dinamicamente um novo bloco de memoria do tamanho da struct Veiculo esse bloco de memoria é atribuido como novo
        if (novo != NULL)//verifica
        {
            novo->codigo = codigo;
            strcpy(novo->tipo,tipo);
            strcpy(novo->localizacao,localVeiculo);
            novo->bateria = bateria;
            novo->autonomia = autonomia;
            novo->custo = custo;
            novo->next=listaVeiculos; //faz com que o novo veiculo aponte para o antigo inicio da lista ligada, fica o novo inicio da lista.
            return(novo); //retur do *

        }

    } else return(listaVeiculos); //função retorna o * para o inicio da listaVeiculos caso o codigo exista.
    
}



/**
 * @brief Função Remover Veiculo por Codigo
 * 
 * @param listaVeiculos * para o inicio da listaVeiculos
 * @param codigo codigo do veiculo
 * 
 * @return * atualizado para o inicio da listaVeiculos
 */
veiculo* removerVeiculo(veiculo *listaVeiculos, int codigo)
{
    //verifica se o veiculo a ser removido existe na lista ligada listaVeiculos
    if (existeVeiculo(listaVeiculos, codigo))
    {
        veiculo *anterior=listaVeiculos, *atual=listaVeiculos, *aux; //*anterior para manter a referencia do * anterior que se pretende remover| atual percorre a lista | * aux mantem temporariamente a referencia ao nó seguinte e ao nó a ser removido 

        if (atual == NULL) return (NULL); //verifica se a lista ligada listaVeiculos está vazia 
        else if (atual->codigo == codigo) //remoção do 1ºRegisto
        {
         aux = atual->next;
         free(atual); //Liberta a memoria que estava a ser ocupada
         return(aux); //atualiza para o endereço seguinte 
        }
        else
        {
         while ((atual != NULL) && (atual->codigo != codigo)) //percorre a listaVeiculos ate encontrar o codigo a ser removido ou até chegar ao final da listaVeiculos
           {
             anterior = atual;
             atual = atual->next;
            }
         if (atual == NULL) return(listaVeiculos); //percorre a lista ligada listaVeiculos caso não exista o veiculo, dá return inicio listaVeiculo
         else
           {
             anterior->next = atual->next; //* atual encontrar Codigo a ser removido | função atualiza os endereços dos * anterior e seguinte 
             free(atual); //Liberta a memoria que estava a ser ocupada
             return(listaVeiculos); //retorna o *lista ligada listaVeiculos para o seu inicio 
            }        
        }
    }  else return(listaVeiculos); //devolve o inicio da lista ligada listaClientes
    
}


/**
 * @brief Função alterar Veiculo por Codigo
 * 
 * @param listaVeiculos * para o inicio da listaVeiculos
 * @param codigo do veiculo a ser alterado
 * @param tipo do veiculo a ser alterado
 * @param bateria do veiculo a ser alterado
 * @param autonomia do veiculo a ser alterado
 * @param custo do veiculo a ser alterado
 * 
 * @return * atualizado para o inicio da listaVeiculos 
 */
veiculo* alterarVeiculo(veiculo *listaVeiculos, int codigo, float bateria,  float autonomia,  float custo)
{
    // verifica se o veiculo a ser alterado existe na lista ligada listaVeiculos
    if (existeVeiculo(listaVeiculos, codigo))
    {
        veiculo *atual = listaVeiculos; //cria-se *atual para percorrer a lista ligada listaVeiculos

        //percorre a lista até encontrar o veiculo a ser alterado
        while ((atual != NULL) && (atual->codigo != codigo))
        {
            atual = atual->next;
        }
        //verificação caso seja diferente de NULL
        if (atual != NULL)
        {
            //atualiza os dados do Veiculo
            atual->bateria = bateria;
            atual->autonomia = autonomia;
            atual->custo = custo;
        }
        return listaVeiculos; //* atualizado para o inicio da listaVeiculos
    
    }else return (listaVeiculos);    
}


/**
 * @brief Função que organiza a listaVeiculos pela autonomia em ordem decrescente. Atraves do Algoritmo de Ordenação Bubble Sort.
 * 
 * @param listaVeiculos *para o inicio da listaVeiculos
 */
void organizarPorAutonomia(veiculo *listaVeiculos) 
{
    veiculo *inicio = NULL, *seguinte = NULL; // *inicio percorre a lista encadeada a partir do início |  *Seguinte percorre a lista a partir do elemento seguinte ao *inicio
    float aux; // *aux para armazenar temporariamente os valores de autonomia.

    //Percorre a listaVeiculos até chegar ao Final da Mesma.
    for (inicio = listaVeiculos; inicio != NULL; inicio = inicio->next) 
    {
        //Percorre a listaVeiculos até chegar ao Final da Mesma mas com o nódulo seguinte ao inicio.
        for (seguinte = inicio->next; seguinte != NULL; seguinte = seguinte->next) 
        {
            //Comparação entre autonomia do nódulo do *seguinte com o do *inicio
            if (inicio->autonomia < seguinte->autonomia) 
            {
                // troca os valores de autonomia entre os dois nódulos da lista
                aux = inicio->autonomia;
                inicio->autonomia = seguinte->autonomia;
                seguinte->autonomia = aux;

                // troca os valores de bateria entre os dois nodulos da lista
                aux = inicio->bateria;
                inicio->bateria = seguinte->bateria;
                seguinte->bateria = aux;

                // troca os valores de custo entre os dois nódulos da lista
                aux = inicio->custo;
                inicio->custo = seguinte->custo;
                seguinte->custo = aux;

                // troca os valores de tipo entre os dois nódulos da lista
                char auxTipo[50];
                strcpy(auxTipo, inicio->tipo);
                strcpy(inicio->tipo, seguinte->tipo);
                strcpy(seguinte->tipo, auxTipo);

                // troca os valores de localizacao entre os dois nódulos da lista
                char auxTipo2[50];
                strcpy(auxTipo2, inicio->localizacao);
                strcpy(inicio->tipo, seguinte->localizacao);
                strcpy(seguinte->tipo, auxTipo2);
            }
        }
    }
}

/**
 * @brief Função que mostra os dados dos veículos da lista, ordenados por autonomia
 * 
 * @param listaVeiculos * para o primeiro elemento da listaVeiculos
 */
void showDadosIteractiveVeiculos(veiculo *listaVeiculos)
{
    organizarPorAutonomia(listaVeiculos);

    while (listaVeiculos != NULL)
    {
        printf("Codigo -> %d | Tipo -> %s | Localizacao -> %s | Bateria -> %.2f | Autonomia -> %.2f | Custo -> %.2f\n", listaVeiculos->codigo, listaVeiculos->tipo, listaVeiculos->localizacao, listaVeiculos->bateria, listaVeiculos->autonomia, listaVeiculos->custo);
        listaVeiculos = listaVeiculos->next; //Avança para o próximo elemento da lista.
    }   
}
//--------------------------------------------------------------FUNÇÕES PARA OS VEICULOS-----------------------------------------------------------------------------------------------------------------------------------//


//--------------------------------------------------------------FUNÇÕES PARA OS GESTORES-----------------------------------------------------------------------------------------------------------------------------------//


/**
 * @brief Função Load Dados do ficheiro
 * 
 * @param listaGestores * para o inicio da listaGestores
 * 
 * @return * para inicio da listaGestores
 */
gestor* loadDadosGestor(gestor *listaGestores)
{
     FILE *ficheiro; //declara um * para um ficheiro

     char linha[200]; //string para ler cada linha do ficheiro.
     int opId; 
     char opNomeG [50];
    
        if ((ficheiro = fopen("listaGestores.txt", "r")) == NULL) // abre o arquivo "listaGestores.txt" em modo de leitura "r"
        {
         printf("Erro ao abrir o arquivo listaClientes.txt\n");
         return listaGestores;
        }

        while (fgets(linha, 200, ficheiro) != NULL) 
       {
         sscanf(linha, "Id -> %d | Nome -> %[^\n]\n", &opId, opNomeG);

         listaGestores = inserirGestor(listaGestores, opId, opNomeG);
       }
       fclose(ficheiro);//fecha o ficheiro
       return listaGestores; //devolve o inicio da lista ligada   
}


/**
 * @brief  Função Salvar dados da listaGestores em ficheiro.
 * 
 * @param listaGestores is a pointer to the first element of the list
 */
void salvarDadosGestor(gestor *listaGestores)
{
    FILE *ficheiro; //declara um * para um ficheiro
     ficheiro = fopen("listaGestores.txt", "w"); // abre o arquivo "listaGestores.txt" em modo de reescrita  "w"
     
     // Verifica se o arquivo foi aberto com sucesso
     if (ficheiro != NULL)
     {
        for (gestor *atual = listaGestores; atual != NULL; atual = atual->next) //percorrer a listaGestores
        {
            fprintf(ficheiro, "Id -> %d | Nome -> %s\n", atual->id, atual->nome); //escreve os dados de cada Gestor no ficheiro
        }
     }
    fclose(ficheiro); //fecha o ficheiro 
}



/**
 * @brief Função Mostrar Dados listaGestores em consola
 * 
 * @param listaGestores * para inicio da listaGestores
 */
void showDadosGestor(gestor *listaGestores)
{
    while (listaGestores != NULL)
    {
        printf("Id -> %d | nome -> %s\n", listaGestores->id, listaGestores->nome);
        listaGestores = listaGestores->next; // Avança para o próximo elemento da lista
    }   
}


/**
 * @brief Função  Existe Gestor
 * 
 * @param listaGestores * para o inicio da listaGestores
 * @param id do gestor a ser removido
 * 
 * @return 1 se existir ou 0 caso não exista
 */
int existeGestor(gestor *listaGestores, int id)
{
    //percorre todos os elementos da lista ate o * apontar para NULL
    while (listaGestores != NULL)
    {
        //compara valor do campo id da lista com o parametro id atribuido
        if (listaGestores->id == id) return (1); //se forem iguais afirma que gestor foi encontrado
        listaGestores = listaGestores->next; //Caso contrário, a função avança para o próximo elemento da lista, apontado pelo campo next do elemento atual.
    }
     return(0); //retorna 0, indicando que o gestor não existe na lista.
}



/**
 * @brief Função Inserir Gestor na listaGestores
 * 
 * @param listaGestores * para o inicio da listaGestores
 * @param id do Gestor
 * @param nome do Gestor
 * 
 * @return * novo para o inicio da listaGestores
 */
gestor* inserirGestor(gestor *listaGestores, int id, char nome[])
{
 //verifica se já existe um Gestor com o mesmo id
 if (!existeGestor(listaGestores, id))
 { 
    gestor *novo = malloc(sizeof(struct gestor));//aloca dinamicamente um novo bloco de memória do tamanho da struct gestor esse bloco memoria atribuido como novo
    if (novo != NULL)//verificação 
    {   
        novo->id = id;
        strcpy(novo->nome,nome);
        novo->next=listaGestores;//faz com que o novo gestor aponte para o antigo início da lista, fica o novo início da lista.
        return(novo); //return do *
    }
    
 } else return(listaGestores); //função retorna o * para o início da listaGestores caso o id já exista.
}


/**
 * @brief Função Remover Gestor da listaGestores
 * 
 * @param listaGestores * para o inicio da listaGestores
 * @param id do gestor a ser removido
 * 
 * @return * atualizado para o inicio da listaGestores 
 */
gestor* removerGestor(gestor *listaGestores, int id)
{
    // verifica se o Gestor a ser removido existe na lista ligada listaGestores
    if (existeGestor(listaGestores, id)) 
    {
        gestor *anterior=listaGestores, *atual=listaGestores, *aux; //*anterior para manter a referencia do * anterior que se pretende remover| atual percorre a lista | * aux mantem temporariamente a referencia ao nó seguinte e ao nó a ser removido 

        if (atual== NULL) return (NULL); //verifica se a lista ligada listaGestores está vazia
        else if (atual->id == id) //remoção do 1º Registo
        {
         aux = atual->next;
         free(atual); //Liberta a memoria que estava a ser ocupada
         return(aux); //atualiza para o endereço seguinte 
        }
        else
        {
         while ((atual != NULL) && (atual->id != id)) //percorre a listaGestores ate encontrar o id a ser removido ou até chegar ao final da listaGestores
           {
             anterior = atual;
             atual = atual->next;
            }
         if (atual == NULL) return(listaGestores); //percorre a lista ligada listaGestores caso não exista o gestor return inicio listaGestores
         else
           {
             anterior->next = atual->next; //* atual encontra id a ser removido | função atualiza os endereços dos * anterior e seguinte 
             free(atual); //Liberta a memoria que estava a ser ocupada
             return(listaGestores); //retorna o *lista ligada listaGestores para o seu inicio 
            }        
        }
    }  else return(listaGestores); //devolve o inicio da lista ligada listaGestores
}


/**
 * @brief Função Alterar Gestor da listaGestores
 * 
 * @param listaGestores * para o inicio da listaGestores
 * @param id do Gestor a ser alterado
 * @param nome do gestor a ser alterado
 * 
 * @return * atualizado para o inicio da listaGestores 
 */
gestor* alterarGestor(gestor *listaGestores, int id, char nome[])
{
    // verifica se o gestor a ser alterado existe na lista ligada listaGestores
    if (existeGestor(listaGestores, id))
    {
        gestor *atual = listaGestores; //cria-se *atual para percorrer lista

        // percorre a lista até encontrar o gestor a ser alterado
        while ((atual != NULL) && (atual->id != id))
        {
            atual = atual->next;
        }
        //verificação caso seja diferente de NULL modifica
        if (atual != NULL)
        {
            // atualiza os dados do gestpr
            strcpy(atual->nome, nome);
        }
        return listaGestores; //* atualizado para o inicio da listaGestores
        
    } else return (listaGestores);
}

//--------------------------------------------------------------FUNÇÕES PARA OS GESTORES-----------------------------------------------------------------------------------------------------------------------------------//

//--------------------------------------------------------------FUNÇÕES PARA AS RESERVAS-----------------------------------------------------------------------------------------------------------------------------------//


/**
 * @brief Função que lê um ficheiro e insere os dados na listaReservas
 * 
 * @param listaClientes * para o inicio da listaClientes
 * @param listaVeiculos * para o inicio da listaVeiculos
 * @param listaReservas * para o inicio da listaReservas
 * 
 * @return * para o inicio da listaReservas
 */
reserva* loadDadosReserva(cliente* listaClientes, veiculo* listaVeiculos, reserva* listaReservas)
{
    FILE *ficheiro;

     char linha[200]; //string para ler cada linha do ficheiro.
    int opIdReserva = 0, opNif = 0, opCodigo = 0, opEstado = 0;
    float opCustoPorMinuto = 0;

    if ((ficheiro = fopen("listaReservas.txt", "r")) == NULL) //Abre o arquivo "listaReservas.txt" em modo de leitura "r"
    {
        printf("Erro ao abrir o arquivo listaReservas.txt\n");
        return listaReservas;
    }
    
    while (fgets(linha, 200, ficheiro) != NULL)
    {
        sscanf(linha, "Id da Reserva -> %d | Nif -> %d | Codigo Veiculo -> %d | Estado -> %d | Custo por (1m) %.2f\n", &opIdReserva, &opNif, &opCodigo, &opEstado, &opCustoPorMinuto);

         listaReservas = inserirReserva(listaClientes, listaVeiculos, listaReservas, opIdReserva, opNif, opCodigo, opEstado);
    }
    fclose(ficheiro);//fecha o ficheiro
    return listaReservas; //devolve o inicio da lista ligada
}



/**
 * @brief Função Salvar Dados Reserva em ficheiro.txt
 * 
 * @param listaReservas * para o inicio da lista ligada
 */
void salvarDadosReserva(reserva *listaReservas)
{
     FILE *ficheiro; //declara um * para um ficheiro
     ficheiro = fopen("listaReservas.txt", "w"); // abre o arquivo "listaClientes.txt" em modo de rescrita "w"
     
     // Verifica se o arquivo foi aberto com sucesso
     if (ficheiro != NULL)
     {
        for (reserva *atual = listaReservas; atual != NULL; atual = atual->next) //percorrer a listaReservas
        {
            fprintf(ficheiro, "Id da Reserva -> %d | Nif -> %d | Codigo Veiculo -> %d | Estado -> %d | Custo por (1m) %.2f\n", atual->idReserva, atual->cliente.nif, atual->veiculo.codigo, atual->estado, atual->custoPorMinuto); //escreve os dados de cada cliente no ficheiro
        }
     }
    fclose(ficheiro); //fecha o ficheiro  
}



/**
 * @brief Função Mostrar Dados Reserva
 * 
 * @param listaReserva * para o inicio da listaReserva
 */
void showDadosReserva(reserva *listaReservas)
{
    while (listaReservas != NULL)
    {
        printf("Id da Reserva -> %d | Nif -> %d | Codigo Veiculo -> %d | Estado -> %d | Custo por (1m) %.2f\n", listaReservas->idReserva, listaReservas->cliente.nif, listaReservas->veiculo.codigo, listaReservas->estado, listaReservas->custoPorMinuto);
        listaReservas = listaReservas->next; //Avança para o próximo elemento da lista.
    }
    
}


/**
 * @brief Função Verifica se Existe IdReserva
 * 
 * @param listaReservas * para o inicio da listaReservas
 * @param id da reserva a ser verificada
 * 
 * @return 1 se existir ou 0 caso não exista
 */
int existeReserva(reserva *listaReservas, int idReserva)
{
    while (listaReservas != NULL)
    {
        //compara valor do campo id da lista com o parametro id atribuido
        if (listaReservas->idReserva == idReserva) return (1); //se forem iguais afirma que a reserva foi encontrada
        listaReservas = listaReservas->next; //Caso contrário, a função avança para o próximo elemento da lista, apontado pelo campo next do elemento atual.
    }
    return 0; // retorna 0 se a reserva não for encontrada
}


/**
 * @brief Função Inserir Reserva na lista Ligada listaReservas
 * 
 * @param listaClientes  * para o inicio da listaClientes
 * @param listaVeiculos  * para o inicio da listaVeiculos
 * @param listaReservas  * para o inicio da listaReservas
 * @param idReserva da Reserva
 * @param nif do Cliente
 * @param codigo do veiculo
 * 
 * @return novaReserva * para o inicio da listaReservas
 */
reserva *inserirReserva(cliente* listaClientes, veiculo* listaVeiculos, reserva* listaReservas, int idReserva, int nif, int codigo, int estado) 
{
    // encontra o veículo com o código especificado
    veiculo *veiculoReserva = listaVeiculos;
    while (veiculoReserva != NULL && veiculoReserva->codigo != codigo)
    {
        veiculoReserva = veiculoReserva->next; //Percorre a lista de veiculos
    }

    //aloca dinamicamente um novo bloco de memória do tamanho da struct cliente esse bloco memoria atribuido como novo
    reserva* novaReserva = (reserva*) malloc(sizeof(reserva));
    novaReserva->idReserva = idReserva;
    novaReserva->cliente.nif = nif;
    novaReserva->veiculo.codigo = codigo;
    novaReserva->custoPorMinuto = veiculoReserva->custo; // copia o custo do veículo
    novaReserva->estado = 1;

    // insere a nova reserva no inicio da lista de reservas
    novaReserva->next = listaReservas;
    return(novaReserva);  //return do * 
}


/**
 * @brief Função remove uma reserva da lista ligada listaReservas.
 * 
 * @param listaReservas * para o inicio da listaReservas
 * @param IdReserva da reserva a ser removida
 * 
 * @return * para o inicio da listaReservas
 */
reserva* removerReserva(reserva *listaReservas, int IdReserva)
{
    // verifica se a Reserva a ser removido existe na lista ligada listaReserva
    if (existeReserva(listaReservas, IdReserva))
    {
        reserva *anterior = listaReservas, *atual = listaReservas, *aux; //*anterior para manter a referencia do * anterior que se pretende remover| atual percorre a lista | * aux mantem temporariamente a referencia ao nó seguinte e ao nó a ser removido 

        if (atual == NULL) return (NULL); //verifica se a lista ligada listaReservas está vazia
        else if (atual->idReserva == IdReserva) //remoção do 1º Registo
        {
         aux = atual->next;
         free(atual); //Liberta a memoria que estava a ser ocupada
         return(aux); //atualiza para o endereço seguinte   
        }
        else
        {
         while ((atual != NULL) && (atual->idReserva != IdReserva)) //percorre a listaReservas ate encontrar o idReservas a ser removido ou até chegar ao final da listaReservas
           {
             anterior = atual;
             atual = atual->next;
            }
         if (atual == NULL) return(listaReservas); //percorre a lista ligada listaReservas caso não exista a reserva return inicio listaReservas
         else
           {
             anterior->next = atual->next; //* atual encontra idReserva a ser removido | função atualiza os endereços dos * anterior e seguinte 
             free(atual); //Liberta a memoria que estava a ser ocupada
             return(listaReservas); //retorna o *lista ligada listaReservas para o seu inicio 
            }   
        }
        
    }
    
}


/**
 * @brief Função que Procura uma reserva com um determinado id e, caso a encontre, atualiza o cliente e a viatura da reserva
 * 
 * @param listaClientes * para a listaClientes
 * @param listaVeiculos * para a listaVeiculos
 * @param listaReservas * para a listaReservas
 * @param idReserva da reserva a ser alterada
 * @param nif cliente a ser alterado
 * @param codigo do veiculo
 * 
 * @return * da listaReservas
 */
reserva* alterarReserva(cliente* listaClientes, veiculo* listaVeiculos, reserva* listaReservas, int idReserva, int nif, int codigo)
{
    // verifica se a reserva a ser alterada existe na lista ligada listaReservas
    if (existeReserva(listaReservas, idReserva))
    {
        reserva *atual = listaReservas;//cria-se *atual para percorrer lista
        
        // percorre a lista até encontrar a reserva a ser alterada
        while ((atual != NULL) && (atual->idReserva != idReserva))
        {
            atual = atual->next;
        }
        
        // encontra o veículo com o código especificado
        veiculo *veiculoReserva = listaVeiculos;

        // percorre a lista até encontrar o veiculo a ser alterado
        while (veiculoReserva != NULL && veiculoReserva->codigo != codigo)
        {
         veiculoReserva = veiculoReserva->next; //Percorre a lista de veiculos
        }
        
        //verificação caso seja diferente de NULL modifica
        if (atual != NULL)
        {
            // atualiza os dados da reseerva
            atual->cliente.nif = nif;
            atual->veiculo.codigo = codigo;
            atual->custoPorMinuto = veiculoReserva->custo;
        }
        return listaReservas; //* atualizado para o inicio da listaReservas
        
         
    }else return (listaReservas);
    
}

//--------------------------------------------------------------FUNÇÕES PARA AS RESERVAS-----------------------------------------------------------------------------------------------------------------------------------//

//--------------------------------------------------------------FUNÇÕES PARA O GRAFO-----------------------------------------------------------------------------------------------------------------------------------//







local* loadDadosLocalizacao(cliente* listaClientes, veiculo* listaVeiculos, local *listaLocais)
{
    FILE *ficheiro;
    char linha[200];
    char opLocal[50];
    char opCodigo[50];
    char opNif[50];

    if ((ficheiro = fopen("listaLocais.txt", "r")) == NULL)
    {
        printf("Erro ao abrir o ficheiro listaLocais.txt\n");
        return listaLocais;
    }

    while (fgets(linha, 200, ficheiro) != NULL)
    {
        // Usamos o sscanf para extrair a localização da linha
        if (sscanf(linha, "%[^|]|%[^|]|%[^|\n]", opLocal, opCodigo, opNif) != 3)
        {
            printf("Erro ao ler linha do arquivo: %s\n", linha);
            continue;
        }

        // Chamamos a função inserirLocalizacao para adicionar a nova localização à lista
        listaLocais = inserirLocalizacao(listaClientes, listaVeiculos, listaLocais, opLocal);

    }

    fclose(ficheiro);
    return listaLocais;
}



/**
 * Função salva os dados dos locais, incluindo o nome do local, códigos de veículos associados,
  * e NIFs de cliente associados, para um ficheiro de texto.
 * 
 * @param listaLocais  * para o inicio da listaLocalizacao
 */
void salvarDadosLocalizacao(local* listaLocais)
{
    
    FILE *ficheiro;  //declara um * para um ficheiro
    ficheiro = fopen("listaLocais.txt", "w"); // abre o arquivo "listaClientes.txt" em modo de reescrita "w"

    // Verifica se o ficheiro foi aberto corretamente
    if (ficheiro != NULL) 
    {

        // Percorre a lista de locais e escreve cada localização no ficheiro
        for (local *localAtual = listaLocais; localAtual != NULL; localAtual = localAtual->next) //percorrer a listaLocais
        {
        {
            fprintf(ficheiro, "Localizacao-> %s ", localAtual->localizacao);

            
            fprintf(ficheiro, "| Codigo Veiculos ->  ");

            // Percorre a lista ligada de codigoVeiculos e escreve cada codigo existente no ficheiro
            for (codigoVeiculos *codigoAtual = localAtual->codigoVeiculo; codigoAtual != NULL; codigoAtual = codigoAtual->next) //percorrer a listaLocais
            {
                fprintf(ficheiro, "%d ", codigoAtual->codigo);
            }

            fprintf(ficheiro, "| Nif Clientes ->  ");

            // Percorre a lista ligada de nifClientes e escreve cada nif existente no ficheiro
            for (nifClientes *nifAtual = localAtual->nifCliente; nifAtual != NULL; nifAtual = nifAtual->next) 
            {
                fprintf(ficheiro, "%d ", nifAtual->nif);
            }

            fprintf(ficheiro, "\n"); // Pula para a próxima linha
        }
        
        fclose(ficheiro); // Fecha o arquivo
        }
    }
}



/**
 * A função verifica se um determinado local existe em uma lista vinculada de locais.
 * 
 * @param listaLocais * para o inicio da listaLocalizacao
 * @param localizacao da localizacao a ser verificada
 * 
 * @return 1 se existir ou 0 caso não exista
 */
int existeLocalizacao(local *listaLocais, char localizacao[])
{
    //percorre todos os elementos da lista ate o * apontar para NULL
    while (listaLocais != NULL)
    {
        //Compara o valor do campo localizacao da lista ligada com o parametro de localizacao atribuido.
        if(strcmp(listaLocais->localizacao, localizacao) == 0) return (1); 
        listaLocais = listaLocais->next; 
    }
    return (0); //retorna 0, indicando que a localizacao não existe na lista.
}




/**
 * Esta função insere um novo local na struct do grafo, caso ainda não exista.
 * 
 * @param listaClientes  * para o inicio da listaClientes
 * @param listaVeiculos  * para o inicio da listaVeiculos
 * @param listaLocais  * para o inicio da listaLocais
 * @param novoLocal a string que representa o nome do novo local a ser inserido no grafo.
 * 
 * @return novo * para o início da lista do (grafo) atualizado, com uma nova localização
 */
local* inserirLocalizacao(cliente* listaClientes, veiculo* listaVeiculos, local* listaLocais, char novoLocal[])
{

    //aloca dinamicamente um novo bloco de memória do tamanho da struct local esse bloco memoria atribuido como novo
    local* novo = malloc(sizeof(local));
    strcpy(novo->localizacao, novoLocal);
    novo->nifCliente = NULL;
    novo->codigoVeiculo = NULL;
    novo->next = NULL;

    // Encontrar os veiculos com a localizacao
    veiculo* veiculoLocal = listaVeiculos;
    while (veiculoLocal != NULL)
    {
        if (!strcmp(veiculoLocal->localizacao, novoLocal))
        {
            codigoVeiculos* codigoLocal = malloc(sizeof(codigoVeiculos));
            codigoLocal->codigo = veiculoLocal->codigo;
            codigoLocal->next = novo->codigoVeiculo;
            novo->codigoVeiculo = codigoLocal;
        }
        veiculoLocal = veiculoLocal->next; //Percorre a lista de Veiculos
    }

    //Encontrar os clientes com a localizacao
    cliente* clienteLocal = listaClientes;
    while (clienteLocal != NULL)
    {
        if (!strcmp(clienteLocal->localizacao, novoLocal))
        {
            nifClientes* nifLocal = malloc(sizeof(nifClientes));
            nifLocal->nif = clienteLocal->nif;
            nifLocal->next = novo->nifCliente;
            novo->nifCliente = nifLocal;
        }
        clienteLocal = clienteLocal->next;//Percorrer a listaClientes
    }
    
    novo->next = listaLocais;
    return(novo);
}



/**
 * The function prints the location, vehicle codes, and client NIFs associated with each element in a
 * linked list of locations.
 * 
 * @param listaLocais a pointer to the first node of a linked list of "local" structs, which contain
 * information about a location, including its name and the codes of vehicles and NIFs associated with
 * it.
 */
void showDadosLocalizacao(local *listaLocais)
{
    local *atual = listaLocais;

    while (atual != NULL) {
        printf("Localizacao -> %s | ", atual->localizacao);

        // Imprime os códigos dos veículos associados à localização
        codigoVeiculos *codigoAtual = atual->codigoVeiculo;
        printf("CodigoVeiculo -> ");
        while (codigoAtual != NULL) {
            printf("%d ", codigoAtual->codigo);
            codigoAtual = codigoAtual->next;
        }

        // Imprime os NIFs dos clientes associados à localização
        nifClientes *nifAtual = atual->nifCliente;
        printf("| Nif -> ");
        while (nifAtual != NULL) {
            printf("%d ", nifAtual->nif);
            nifAtual = nifAtual->next;
        }

        printf("\n");

        atual = atual->next;
    }
}