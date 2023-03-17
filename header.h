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
#include <stdio.h>

typedef struct carteira
{
    int id;
    float saldo;
}carteira;


typedef struct cliente
{
    int nif; //id do cliente
    char nome [50]; //nome do cliente
    carteira carteira; //saldo do cliente
    char morada [100];
    char password[50];
    struct cliente *next; //permite obter uma lista ligada atraves dos * que guardam o endereço de memória de outra variável. 

}cliente;



typedef struct gestor
{
    int id; //id do gestor
    char nome[50]; // nome de usuário do gestor
    char password[50]; // senha do gestor
    struct gestor *next; //aponta para o proximo nó da lista
}gestor;



typedef struct veiculo
{
    int codigo; //codigo do meio de mobilidade eletrica
    char tipo[20]; // tipo de veiculo (ex: bicicleta, scooter, patinete)
    float bateria; // bateria (em %)
    float autonomia; // autonomia do veiculo
    float custo; // custo por minuto reservado
    char geocodigo[20]; // localização do meio de mobilidade (utilizando o what3words.com)
    int reservado; // 1 - Reservado | 0 - Disponivel
    struct veiculo *next;//ao armazenar num * o próximo nó permite-nos percorrer a lista.
}veiculo;

typedef struct reserva
{
    int idReserva; //Id da Reserva
    cliente cliente; //Dados do cliente
    veiculo veiculo; //Dados do veiculo
    float custoPorMinuto; //para copiar do custo do veiculo
    int estado; //1 - Em Andamento | 0 - Acabada
    struct reserva *next;
} reserva;



/**
 * @brief Funções para o gerenciamento de Clientes
 * 
 * @return 
 */

// Inserção de um novo registo de cliente na `listaCliente´
cliente* inserirCliente(cliente *listaClientes, int nif, char nome[], char morada[], float saldo);

//Faz o load dos dados do ficheiro listaClientes.txt para a ´listaCliente´.
cliente* loadDadosCliente(cliente *listaClientes);

// Salva os dados da ´listaClientes´ em ficheiro txt.
void salvarDadosCliente(cliente *listaClientes);

// Mostra Dados do cliente na consola.
void showDadosCliente(cliente *listaClientes);

// Determinar existência do 'cliente' na lista ligada 'listaClientes'
int existeCliente(cliente *listaClientes, int nif);

// Remover um Cliente a partir do seu Nif
cliente* removerCliente(cliente *listaClientes, int nif);

// Alterar dados de um Cliente
cliente* alterarCliente(cliente *listaClientes, int nif, char nome[], char morada[], float saldo);


/**
 * @brief Funções para o gerenciamento de Gestores
 * 
 * @return 
 */

// Inserção de um novo registo de gestor na `listaGestores´
gestor* inserirGestor(gestor *listaGestores, int id, char nome[]);

//Faz o load dos dados do ficheiro listaGestores.txt para a ´listaGestores´.
gestor* loadDadosGestor(gestor *listaGestores);

// Salva os dados da ´listaGestores´ em ficheiro txt.
void salvarDadosGestor(gestor *listaGestores);

// Mostra Dados do gestor na consola.
void showDadosGestor(gestor *listaGestores);

// Determinar existência do 'gestor' na lista ligada 'listaGestor'
int existeGestor(gestor *listaGestores, int id);

// Remover um Gestor a partir do seu id
gestor* removerGestor(gestor *listaGestores, int id);

// Alterar dados de um Gestor
gestor* alterarGestor(gestor *listaGestores, int id, char nome[]);




/**
 * @brief Funções para o gerenciamento de Veiculos
 * 
 * @return 
 */

// Inserção de um novo registo de veiculo na lista ligada `listaVeiculos´
veiculo* inserirVeiculo(veiculo *listaVeiculos, int codigo, char tipo[], float bateria,  float autonomia,  float custo);

//Faz o load dos dados do ficheiro listaVeiculos.txt para a lista ligada.
veiculo* loadDadosVeiculo(veiculo *listaVeiculos);

//Salva os  Dados  da lista ligada `listaVeiculos´ em ficheiro.
void salvarDadosVeiculo(veiculo *listaVeiculos);

// Mostrar Dados  da lista ligada `listaVeiculos´ em consola.
void showDadosVeiculo(veiculo *listaVeiculos);

// Determinar existência do 'veiculo' na lista ligada 'listaVeiculos'
int existeVeiculo(veiculo *listaVeiculos, int codigo);

// Remover um Veiculo a partir do seu codigo
veiculo* removerVeiculo(veiculo *listaVeiculos, int codigo);

// Alterar dados de um Veiculo
veiculo* alterarVeiculo(veiculo *listaVeiculos, int codigo, float bateria,  float autonomia,  float custo);

//Organiza os dados da lista pela autonomia
void organizarPorAutonomia(veiculo *listaVeiculos);

// Mostrar Dados da lista ligada ´listaVeiculos´ ordem decrescente de autonomia.
void showDadosIteractiveVeiculos(veiculo *listaVeiculos);



/**
 * @brief Funções para o gerenciamento de Reservas
 * 
 * @return 
 */

//Inserção de um novo registo de Reserva na lista ligada ´listaReserva´
reserva *inserirReserva(cliente* listaClientes, veiculo* listaVeiculos, reserva* listaReservas, int idReserva, int nif, int codigo, int estado);

//Faz o load dos dados do ficheiro listaReservas.txt para a lista ligada.
reserva* loadDadosReserva(reserva *listaReservas);

//Salva os  Dados  da lista ligada `listaReservas´ em ficheiro.
void salvarDadosReserva(reserva *listaReservas);

// Mostrar Dados  da lista ligada `listaReservas´ em consola.
void showDadosReserva(reserva *listaReservas);

// Determinar existência da 'reserva' na lista ligada 'listaReservas'
int existeReserva(reserva *listaReservas, int idReserva);

// Remover uma Reserva a partir do seu IdReserva.
reserva* removerReserva(reserva *listaReservas, int IdReserva);



#endif