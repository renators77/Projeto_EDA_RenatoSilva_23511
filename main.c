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
  char nome[50], morada[50];

  do
  {
    system("cls");
    printf("|-------------------------------------------|\n");
    printf("|   Escolha uma das seguintes opcoes:       |\n");
    printf("|-------------------------------------------|\n");
    printf("| 1-      Dados Clientes                    |\n");
    printf("| 2-      Inserir Cliente                   |\n");
    printf("|--                                         |\n");
    printf("| 3-        Mostrar Dados                   |\n");
    printf("|--                                         |\n");
    printf("|        Selecione 0 para sair              |\n");
    printf("|-------------------------------------------|\n");

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
             break;; // Sai do loop quando o NIF for valido e nao existir na lista
           }  while (1); 
        do
        {
          printf("Nome do novo cliente -> ");
          fgets(nome, sizeof(nome), stdin);
          if (nome[0] == '\n') //Verifica se o nome está vazio
          {
            printf("Nome invalido! Insira um Nome valido com pelo menos 1 caracter.\n");
            continue;// Reinicia o loop para pedir um novo Nome
          }
          break;;
          
        } while (1);
        do
        {
          printf("Morada do novo cliente -> ");
          fgets(morada, sizeof(morada), stdin);
          if (morada[0] == '\n') //Verifica se a morada está vazia
          {
            printf("Morada invalida! Insira um Nome valido com pelo menos 1 caracter.\n");
            continue;// Reinicia o loop para pedir uma nova Morada
          }
          break;;
        } while (1);
        
        
        listaClientes = inserirCliente(listaClientes, opNif, nome, morada);

  system("pause");
  break;
      case 3:
        system("cls");
        showDadosCliente(listaClientes);
        system("pause");
        
      // Adicionar casos para opções 4 a ..
      default:
        break;
    }

  } while (opcao != 0);

  system("cls");
  return 0;




}



  //       system("cls");
  //       do {
  //            printf("nif do novo cliente (9 digitos) -> "); 
  //            scanf("%d", &opNif);
  //            getchar(); 
  //            if (opNif < 100000000 || opNif > 999999999) // Verifica se o NIF tem 9 digitos
  //            { 
  //              printf("NIF invalido! Insira um NIF valido com 9 digitos.\n");
  //              continue; // Reinicia o loop para pedir um novo NIF
  //            } 
  //            else if (existeCliente(listaClientes, opNif)) // Verifica se o NIF ja existe
  //            {
  //              printf("Ja existe um cliente com esse NIF! Insira um NIF diferente.\n");
  //              continue; // Reinicia o loop para pedir um novo NIF
  //            }
  //            break;; // Sai do loop quando o NIF for valido e nao existir na lista
  //          }  while (1); 
  //           printf("Nome do novo cliente -> "); 
  //           fgets(nome, sizeof(nome), stdin);
  //           printf("Morada do novo cliente -> "); 
  //           fgets(morada, sizeof(morada), stdin);

  //           if (strlen(nome) <= 1 || strlen(morada) <= 1) 
  //           {
  //            printf("Nome ou morada invalidos. Volte a Inserir um cliente\n");
  //           } 
  //           else 
  //           {
  //             listaClientes = inserirCliente(listaClientes, opNif, nome, morada);
  //           }
  // system("pause");
  // break;

        //   system("cls");

        // // Ler o nif e verificar se tem 9 dígitos
        // do 
        // {
        //   printf("nif do novo cliente (9 digitos) -> ");
        //   scanf("%d", &opNif);
        //   getchar(); // Consumir o caractere \n restante no buffer de entrada
        // } while (opNif < 100000000 || opNif > 999999999);

        // // Ler o nome e verificar se não está vazio
        // do 
        // {
        //   printf("Nome do novo cliente -> ");
        //   fgets(nome, sizeof(nome), stdin);
        // } while (nome[0] == '\n');

        // // Ler a morada e verificar se não está vazia
        // do 
        // {
        //   printf("Morada do novo cliente -> ");
        //   fgets(morada, sizeof(morada), stdin);
        // } while (morada[0] == '\n');

        // // Verificar se o nif já existe na lista de clientes
        // if (existeCliente(listaClientes, opNif)) 
        // {
        //   printf("O nif inserido ja existe. Por favor insira outro nif.\n");
        // } 
        // else 
        // {
        //   listaClientes = inserirCliente(listaClientes, opNif, nome, morada);
        // }
        // system("pause");
        // break;