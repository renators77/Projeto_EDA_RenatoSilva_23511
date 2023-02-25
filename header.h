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


//Estrutura de dados para os clientes
typedef struct cliente
{
    char id [3]; //id do cliente
    char nome [20]; //nome do cliente
    float saldo; //saldo do cliente

}cliente;

typedef struct gestor
{
    char nome[50]; // nome de usuário do gestor
    char password[50]; // senha do gestor
}gestor;

typedef struct veiculo
{
    char tipo[20]; // tipo de veiculo (ex: bicicleta, scooter, patinete)
    int battery; // bateria (em %)
    float custo; // custo por minuto reservado
    char localizacao[20]; // localização do meio de mobilidade (utilizando o what3words.com)
}veiculo;



#endif