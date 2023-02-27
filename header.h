  /**
 * @file header.h
 * @author Renato Silva (a23511@alunos.ipca.cpt)
 * @brief 
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2023
 * https://github.com/renators77/Projeto_EDA_RenatoSilva_23511
 */

//permite que o código gerado entre o parametro #ifndef e #endif seja excluido durante o processo de compilação sendo compilado apenas 1 vez
#ifndef _HEADER
#define _HEADER
#define MAX_VEICULO 20
#define MAX_CLIENTE 10
#define MAX_GESTOR 5



typedef struct cliente
{
    int nif [10]; //id do cliente
    char nome [30]; //nome do cliente
    carteira carteira; //saldo do cliente
    char morada [100];
    struct cliente *next, *prev; //permite obter uma lista ligada atraves dos * que guardam o endereço de memória de outra variável. 

}cliente;


typedef struct carteira
{
    int id;
    float saldo;
}carteira;


typedef struct gestor
{
    int id; //id do gestor
    char nome[50]; // nome de usuário do gestor
    char password[50]; // senha do gestor
    struct gestor *next, *prev; //aponta para o proximo nó da lista e para o anterior nó da lista podendo assim percorre-la 
}gestor;


typedef struct veiculo
{
    int codigo; //codigo do meio de mobilidade eletrica
    char tipo[20]; // tipo de veiculo (ex: bicicleta, scooter, patinete)
    float bateria; // bateria (em %)
    float autonomia; // autonomia do veiculo
    float custo; // custo por minuto reservado
    char localizacao[20]; // localização do meio de mobilidade (utilizando o what3words.com)
    struct veiculo *next, *prev;//ao armazenar num * o próximo nó permite-nos percorrer a lista.
}veiculo;



#endif

/**
 * @brief Funções para o gerenciamento de Clientes
 * 
 * @return 
 */

// Inserção de um novo registo
cliente* registarCliente(cliente *clientes, int nif, char nome, char morada);

// listar na consola o conteúdo da lista ligada `clientes´
void informacaoCliente(cliente *clientes, int nif, char nome, char morada);

// Determinar existência do 'cliente' na lista ligada 'clientes'
int existeCliente(cliente *clientes, int nif);

// Remover um Cliente a partir do seu Nif
cliente* removerCliente(cliente *clientes, int nif);





/**
 * @brief Funções para o gerenciamento de Gestores
 * 
 * @return 
 */

// Inserção de um novo registo de gestor na lista ligada `gestores´
gestor* registarGestor(gestor *gestores, char nome, char password);

// listar na consola o conteúdo da lista ligada `gestores´
void informacaoGestor(gestor *gestores, int id, char nome);

// Determinar existência do 'gestor' na lista ligada 'gestores'
int existeGestor(gestor *gestores, int id);

// Remover um gestor a partir do seu id
gestor* removerGestor(gestor *gestores, int id);

/**
 * @brief Funções para o gerenciamento de Veiculos
 * 
 * @return 
 */

// Inserção de um novo registo de gestor na lista ligada `veiculos´
veiculo* registarVeiculo(veiculo *veiculos, int codigo, char tipo[], float bateria,  float autonomia,  float custo);

// listar na consola o conteúdo da lista ligada `veiculos´
void informacaoVeiculo(veiculo *veiculos, int codigo, char tipo[], float bateria,  float autonomia,  float custo);

// Determinar existência do 'veiculo' na lista ligada 'veiculos'
int existeVeiculo(veiculo *veiculos, int codigo);

// Remover um Cliente a partir do seu Nif
veiculo* removerVeiculo(veiculo *veiculos, int codigo);



