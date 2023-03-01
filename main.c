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
  int opcao = 0, opNif=0;
  char nome, morada;
// listaClientes = loadDadosCliente(listaClientes); // preenche a lista a partir do arquivo


  system("pause");
  system("cls");
 do
   {
    printf("|-------------------------------------------|\n");
    printf("|   Escolha uma das seguintes opcoes:   	  |\n");     
    printf("|-------------------------------------------|\n");
    printf("| 1-     Dados Clientes                     |\n");          
    printf("| 2-             	                          |\n");  
    printf("|--                                     	  |\n");		
    printf("| 3-                 	                      |\n"); 
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
      // case 2:
      //       system("cls"); 
      //       printf("nif do cliente -> "); 
      //       scanf("%d",&opNif);
      //       printf("Nome do cliente -> "); 
      //       scanf("%s",&nome);
      //       printf("Morada do cliente -> "); 
      //       scanf("%s",&morada);

      //       listaClientes = inserirCliente(listaClientes, opNif, nome, morada);
      //       system("pause");
      //       break;
      default:
        break;
      }

    } while (opcao != 0);
    system("cls");
    return 0;
}