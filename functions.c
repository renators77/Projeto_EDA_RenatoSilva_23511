#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"

//--------------------------------------------------------------FUNÇÕES PARA O CLIENTE-------------------------------------------------------------------------------------------------------------------------------------//

/// @brief Função Load dados do ficheiro
/// @param listaClientes * para o inicio da listaClientes
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

while (fgets(linha, 200, ficheiro) != NULL) 
{
    sscanf(linha, "Nif -> %d | Nome -> %[^|]| Morada -> %[^|]| Saldo -> %f\n", &opNif, opNome, opMorada, &opSaldo);

    listaClientes = inserirCliente(listaClientes, opNif, opNome, opMorada, opSaldo);
}
    fclose(ficheiro);//fecha o ficheiro
    return listaClientes; //devolve o inicio da lista ligada
}

/// @brief Função Salvar dados da lista cliente em Ficheiro.
/// @param listaClientes * para o inicio da listaClientes
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

/// @brief Função Mostrar dados do cliente
/// @param listaClientes * para o inicio da listaClientes
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
 * @param listaClientes * para o inicio da listaClientes
 * @param nif do cliente a ser verificado
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
 * @return novo que aponta para o inicio da listaClientes
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


/// @brief Função Remover Cliente por Nif
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

/// @brief Função alterar Cliente por Nif
/// @param listaClientes * para o inicio da listaClientes
/// @param nif do cliente a ser removido
/// @param nome nome a ser alterado
/// @param morada morada a ser alterada
/// @param saldo saldo a ser alterado
/// @return * atualizado para o inicio da listaClientes 
cliente* alterarCliente(cliente *listaClientes, int nif, char nome[], char morada[], float saldo)
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
            atual->carteira.saldo = saldo;
        }
        return listaClientes; //* atualizado para o inicio da listaClientes 
        
    } else return (listaClientes);
}

//--------------------------------------------------------------FUNÇÕES PARA O CLIENTE-------------------------------------------------------------------------------------------------------------------------------------//


//--------------------------------------------------------------FUNÇÕES PARA OS VEICULOS-----------------------------------------------------------------------------------------------------------------------------------//


/// @brief Função Load dados do ficheiro
/// @param listaVeiculos * para o inicio da listaClientes
/// @return listaVeiculos devolve inicio da lista
veiculo* loadDadosVeiculo(veiculo *listaVeiculos)
{
    FILE *ficheiro; //declara um * para um ficheiro

    char linha[200]; //string para ler cada linha do ficheiro.
    int opCodigo; 
    char opTipo[50];
    float opBateria, opAutonomia, opCusto;
    
    if ((ficheiro = fopen("listaVeiculos.txt", "r")) == NULL) // abre o arquivo "listaVeiculo.txt" em modo de leitura "r"
    {
        printf("Erro ao abrir o arquivo listaVeiculos.txt\n");
        return listaVeiculos;
    }

    while (fgets(linha, 200, ficheiro) != NULL) 
    {
     sscanf(linha, "Codigo -> %d | Tipo -> %[^|]| Bateria -> %f | Autonomia -> %f | Custo -> %f\n", &opCodigo, opTipo, &opBateria, &opAutonomia, &opCusto);

     listaVeiculos = inserirVeiculo(listaVeiculos, opCodigo, opTipo, opBateria, opAutonomia, opCusto);
    }
    fclose(ficheiro);//fecha o ficheiro
    return listaVeiculos; //devolve o inicio da lista ligada
}


/// @brief Função Salvar dados da lista Veiculos em ficheiro.
/// @param listaVeiculos * para o inicio da lista ligada
void salvarDadosVeiculo(veiculo *listaVeiculos)
{
    FILE *ficheiro; //declara um * para um ficheiro
     ficheiro = fopen("listaVeiculos.txt", "w"); // abre o arquivo "listaVeiculo.txt" em modo de ... "w"
     
     // Verifica se o arquivo foi aberto com sucesso
     if (ficheiro != NULL)
     {
        for (veiculo *atual = listaVeiculos; atual != NULL; atual = atual->next) //percorrer a listaClientes
        {
            fprintf(ficheiro, "Codigo -> %d | Tipo -> %s | Bateria -> %.2f | Autonomia -> %.2f | Custo -> %.2f\n", atual->codigo, atual->tipo, atual->bateria, atual->autonomia, atual->custo); //escreve os dados de cada cliente no ficheiro
        }
     }
    fclose(ficheiro); //fecha o ficheiro
}


/// @brief Função Mostrar Dados Veiculos
/// @param listaVeiculos * para o inicio da listaVeiculos
void showDadosVeiculo(veiculo *listaVeiculos)
{
    while (listaVeiculos != NULL)
    {
        printf("Codigo -> %d | Tipo -> %s | Bateria -> %.2f | Autonomia -> %.2f | Custo -> %.2f\n", listaVeiculos->codigo, listaVeiculos->tipo, listaVeiculos->bateria, listaVeiculos->autonomia, listaVeiculos->custo);
        listaVeiculos = listaVeiculos->next; //Avança para o próximo nó da lista.
    }
    
}

/// @brief Existe Veiculos
/// @param listaVeiculos * para o inicio da listaVeiculos
/// @param codigo do veiculo a ser verificado
/// @return 1 se existir ou 0 caso não exista
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



/// @brief Função Inserir Veiculo
/// @param listaVeiculos * para o inicio da listaVeiculos
/// @param codigo identificação do veiculo
/// @param tipo do veiculo associado
/// @param bateria do veiculo associado
/// @param autonomia do veiculo associado
/// @param custo do veiculo associado
/// @return novo que aponta para o inicio da listaVeiculos
veiculo *inserirVeiculo(veiculo *listaVeiculos, int codigo, char tipo[], float bateria,  float autonomia,  float custo)
{
    //Verifica se já existe um Veiculo com o mesmo Codigo
    if (!existeVeiculo(listaVeiculos, codigo))
    {

        veiculo *novo = malloc(sizeof(struct veiculo)); //aloca dinamicamente um novo bloco de memoria do tamanho da struct Veiculo esse bloco de memoria é atribuido como novo
        if (novo != NULL)//verifica
        {
            novo->codigo = codigo;
            strcpy(novo->tipo,tipo);
            novo->bateria = bateria;
            novo->autonomia = autonomia;
            novo->custo = custo;
            novo->next=listaVeiculos; //faz com que o novo veiculo aponte para o antigo inicio da lista ligada, fica o novo inicio da lista.
            return(novo); //retur do *

        }

    } else return(listaVeiculos); //função retorna o * para o inicio da listaVeiculos caso o codigo exista.
    
}


/// @brief Função Remover Veiculo por Codigo
/// @param listaVeiculos * para o inicio da listaVeiculos
/// @param codigo codigo do veiculo
/// @return * atualizado para o inicio da listaVeiculos
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

/// @brief Função alterar Veiculo por Codigo
/// @param listaVeiculos * para o inicio da listaVeiculos
/// @param codigo do veiculo a ser alterado
/// @param tipo do veiculo a ser alterado
/// @param bateria do veiculo a ser alterado
/// @param autonomia do veiculo a ser alterado
/// @param custo do veiculo a ser alterado
/// @return * atualizado para o inicio da listaVeiculos 
veiculo* alterarVeiculo(veiculo *listaVeiculos, int codigo, float bateria,  float autonomia,  float custo)
{
    // verifica se o veiculo a ser alterado existe na lista ligada listaVeiculos
    if (existeVeiculo(listaVeiculos, codigo))
    {
        veiculo *atual = listaVeiculos; //cria-se *atual para percorrer a lista ligada listaVeiculos

        //percorre a lista até encontrar o cliente a ser alterado
        while ((atual != NULL) && (atual->codigo != codigo))
        {
            atual = atual->next;
        }
        //verificação casp seja diferente de NULL
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

//--------------------------------------------------------------FUNÇÕES PARA OS VEICULOS-----------------------------------------------------------------------------------------------------------------------------------//


//--------------------------------------------------------------FUNÇÕES PARA OS GESTORES-----------------------------------------------------------------------------------------------------------------------------------//

/// @brief Função Load Dados do ficheiro
/// @param listaGestores * para o inicio da listaGestores
/// @return * para inicio da listaGestores
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


void salvarDadosGestor(gestor *listaGestores)
{
    FILE *ficheiro; //declara um * para um ficheiro
     ficheiro = fopen("listaGestores.txt", "w"); // abre o arquivo "listaGestores.txt" em modo de  "w"
     
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


/// @brief Função Mostrar Dados Gestor
/// @param listaGestores * para inicio da listaGestores
void showDadosGestor(gestor *listaGestores)
{
    while (listaGestores != NULL)
    {
        printf("Id -> %d | nome -> %s\n", listaGestores->id, listaGestores->nome);
        listaGestores = listaGestores->next; // Avança para o próximo nó da lista
    }   
}

/// @brief Função  Existe Gestor
/// @param listaGestores * para o inicio da listaGestores
/// @param id do cliente a ser removido
/// @return 1 se existir ou 0 caso não exista
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


/// @brief Função Inserir Gestor
/// @param listaGestores * para o inicio da listaGestores
/// @param id do Gestor
/// @param nome do Gestor
/// @return * novo para o inicio da listaGestores
gestor* inserirGestor(gestor *listaGestores, int id, char nome[])
{
 //verifica se já existe um Gestor com o mesmo id
 if (!existeCliente(listaGestores, id))
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