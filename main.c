  /**
 * @file main.c
 * @author Renato Silva (a23511@alunos.ipca.cpt)
 * @brief 
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2023
 * https://github.com/renators77/Projeto_EDA_RenatoSilva_23511
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "header.h"

/**
 * @brief Main com o menu de interaçao com o utilizador
 * 
 * @return 
 */
int main()
{
  //Lista ligada vazia
cliente *listaClientes = NULL;
  int opcao = 0, opNif = 0;
  char opNome[50], opMorada[100];
  float opSaldo;

  do
  {
    system("cls");
    printf("|--------------------------------------------------|\n");
    printf("|   Escolha uma das seguintes opcoes:              |\n");
    printf("|--------------------------------------------------|\n");
    printf("| 1 - Salvar Dados Clientes                        |\n");
    printf("| 2 - Inserir Novo Cliente                         |\n");
    printf("| 3 - Mostrar Dados Novos clientes inseridos       |\n");
    printf("| 4 - Consultar Dados Cliente Guardados em Ficheiro|\n");
    printf("| 5 - Remover Cliente                              |\n");
    printf("| 6 - Alterar Cliente                              |\n");
    printf("|--------------------------------------------------|\n");
    printf("|        Selecione 0 para sair                     |\n");
    printf("|--------------------------------------------------|\n");

    printf("Indique qual a opcao:\n");
    scanf("%d", &opcao);
    system("cls");
    switch (opcao)
    {
      case 1:
        system("cls");
        salvarDadosCliente(listaClientes); 
        system("pause");
        break;

      case 2:
        system("cls");
        do {
             printf("nif do novo cliente (9 digitos) -> "); 
             scanf("%d", &opNif);
             getchar(); 
             if (opNif < 100000000 || opNif > 999999999) // Verifica se o NIF tem 9 digitos
             { 
               printf("NIF invalido! Insira um NIF valido com 9 digitos.\n");
               continue; // Reinicia o loop para pedir um novo NIF
             } 
             else if (existeCliente(listaClientes, opNif)) // Verifica se o NIF ja existe
             {
               printf("Ja existe um cliente com esse NIF! Insira um NIF diferente.\n");
               continue; // Reinicia o loop para pedir um novo NIF
             }
             break; // Sai do loop quando o NIF for valido e nao existir na lista
        }  while (1); 
        do {
             printf("Nome do novo cliente -> ");
             scanf(" %[^\n]s", opNome);
             getchar(); 
             break;
          
        } while (1);
        do  {
             printf("Morada do novo cliente -> ");
             scanf(" %[^\n]s", opMorada);
             getchar(); 
             break;
        } while (1);
        do {
             printf("Saldo da carteira do novo cliente -> ");
             scanf("%f", &opSaldo);
             getchar(); 
             break;
        } while (1);
        
            
        listaClientes = inserirCliente(listaClientes, opNif, opNome, opMorada, opSaldo);

        system("pause");
        break;

      case 3:
        system("cls");
        showDadosCliente(listaClientes);
        system("pause");
        break;
      case 4:
        system("cls");
        listaClientes = loadDadosCliente(listaClientes);
        system("pause");
        break;
      case 5:
        system("cls");
        do {
             printf("nif do cliente que deseja remover (9 digitos) -> "); 
             scanf("%d", &opNif);
             getchar(); 
             if (opNif < 100000000 || opNif > 999999999) // Verifica se o NIF tem 9 digitos
             { 
               printf("NIF invalido! Insira um NIF valido com 9 digitos.\n");
               continue; // Reinicia o loop para pedir um novo NIF
             } 
             else if (!existeCliente(listaClientes, opNif)) // Verifica se o NIF não existe
             {
               printf("Nao existe um cliente com esse NIF! Insira um NIF existente.\n");
               continue; // Reinicia o loop para pedir um novo NIF
             }
             break; // Sai do loop quando o NIF for valido e nao existir na lista
        }  while (1);

        listaClientes = removerCliente(listaClientes, opNif);
        system("pause");
        break;
      case 6:
        system("cls");
        do {
             printf("nif do cliente que deseja alterar (9 digitos) -> "); 
             scanf("%d", &opNif);
             getchar(); 
             if (opNif < 100000000 || opNif > 999999999) // Verifica se o NIF tem 9 digitos
             { 
               printf("NIF invalido! Insira um NIF valido com 9 digitos.\n");
               continue; // Reinicia o loop para pedir um novo NIF
             } 
             else if (!existeCliente(listaClientes, opNif)) // Verifica se o NIF não existe
             {
               printf("Nao existe um cliente com esse NIF! Insira um NIF existente.\n");
               continue; // Reinicia o loop para pedir um novo NIF
             }
             break; // Sai do loop quando o NIF for valido e nao existir na lista
        }  while (1);
        do {
             printf("Novo Nome do cliente -> ");
             scanf(" %[^\n]s", opNome);
             getchar(); 
             break;
          
        } while (1);
        do  {
             printf("Nova Morada do cliente -> ");
             scanf(" %[^\n]s", opMorada);
             getchar(); 
             break;
        } while (1);
        do {
             printf("Saldo da carteira do novo cliente -> ");
             scanf("%f", &opSaldo);
             getchar(); 
             break;
        } while (1);
            
        listaClientes = alterarCliente(listaClientes, opNif, opNome, opMorada, opSaldo);

        system("pause");
        break;
    }


  } while (opcao != 0);
  system("cls");
  return 0;
}
