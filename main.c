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
  listaClientes = loadDadosCliente(listaClientes);

  do
  {
    system("cls");
    printf("|-------------------------------------------|\n");
    printf("|   Escolha uma das seguintes opcoes:   	  |\n");
    printf("|-------------------------------------------|\n");
    printf("| 1-      Dados Clientes                    |\n");
    printf("| 2-      Inserir Cliente       	          |\n");
    printf("|--                                     	  |\n");
    printf("| 3-        Mostrar Dados         	        |\n");
    printf("| 4-                    	                  |\n");
    printf("| 5-                    	                  |\n");
    printf("|--                                     	  |\n");
    printf("| 6-                                        |\n");
    printf("| 7-                                        |\n");
    printf("| 8-                                        |\n");
    printf("|--                                         |\n");
    printf("|        Selecione 0 para sair          	  |\n");
    printf("|-------------------------------------------|\n");

    printf("Indique qual a opcao:\n");
    scanf("%d", &opcao);
    system("cls");
    switch (opcao)
    {
      case 1:
        system("cls");
        criarDadosCliente(listaClientes); 
        system("pause");
        break;
      case 2:
        system("cls");
        printf("nif do novo cliente -> "); 
        scanf("%d", &opNif);
        printf("Nome do novo cliente -> "); 
        scanf("%s", nome);
        printf("Morada do novo cliente -> "); 
        scanf("%s", morada);

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