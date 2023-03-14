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

int menu()
{
  int opcao;
  printf("|--------------------------------------------------|\n");
  printf("|   Escolha uma das seguintes opcoes:              |\n");
  printf("|--------------------------------------------------|\n");
  printf("| 1 - Entrar Como Cliente                          |\n");
  printf("| 2 - Entrar Como Gestor                           |\n");
  printf("|--------------------------------------------------|\n");
  printf("|        Selecione 0 para sair                     |\n");
  printf("|--------------------------------------------------|\n");
  
  printf("Indique qual a opcao:\n");
  scanf("%d", &opcao);
  system("cls");
	return(opcao);
}

int menuCliente()
{
  int opcaoC;
  printf("|--------------------------------------------------|\n");
  printf("|   Escolha uma das seguintes opcoes:              |\n");
  printf("|--------------------------------------------------|\n");
  printf("| 1 - Salvar Dados Clientes                        |\n");
  printf("| 2 - Inserir Novo Cliente                         |\n");
  printf("| 3 - Mostrar Dados Clientes Existentes            |\n");
  printf("|--------------------------------------------------|\n");
  printf("|        Selecione 0 para sair                     |\n");
  printf("|--------------------------------------------------|\n");
  printf("Indique qual a opcao:\n");
  scanf("%d", &opcaoC);
	return(opcaoC);
}

int menuGestor()
{
  int opcaoG;
  printf("|--------------------------------------------------|\n");
  printf("|   Escolha uma das seguintes opcoes:              |\n");
  printf("|--------------------------------------------------|\n");
  printf("|   Zona De Gerenciamento do Cliente               |\n");
  printf("|--------------------------------------------------|\n");
  printf("| 4 - Remover Cliente                              |\n");
  printf("| 5 - Alterar Cliente                              |\n");
  printf("|--------------------------------------------------|\n");
  printf("|   Zona De Gerenciamento de Veiculos              |\n");
  printf("|--------------------------------------------------|\n");
  printf("| 6 - Salvar Dados Veiculos                        |\n");
  printf("| 7 - Inserir Novo Veiculo                         |\n");
  printf("| 8 - Mostrar Dados Veiculos Existentes            |\n");
  printf("| 9 - Remover Veiculo                              |\n");
  printf("| 10 - Alterar Veiculo                             |\n");
  printf("|--------------------------------------------------|\n");
  printf("|        Selecione 0 para sair                     |\n");
  printf("|--------------------------------------------------|\n");
 
  printf("Indique qual a opcao:\n"); 
  scanf("%d", &opcaoG);
	return(opcaoG);
}



/**
 * @brief Main com o menu de interaçao com o utilizador
 * 
 * @return 
 */
int main()
{
  //Lista ligada vazia clientes
cliente *listaClientes = NULL;
  int opcao = 0, opcaoC = 0, opcaoG = 0;
  int opNif = 0;
  char opNome[50], opMorada[100];
  float opSaldo;

//Lista ligada vazia Veiculos
  veiculo *listaVeiculos = NULL;
  int opCodigo = 0;
  char opTipo[50];
  float opBateria, opAutonomia, opCusto;

  //Lista ligada vazia Gestores
  gestor *listaGestores = NULL;
  int opId = 0;
  char opNomeG[50];

  //Load dos dados da listaCliente
  listaClientes = loadDadosCliente(listaClientes);

  //Load dos dados da listaVeiculos
  listaVeiculos = loadDadosVeiculo(listaVeiculos);

  do
  {
    opcao = menu();

    switch (opcao)
    {
//--------------------------------------------------------------Inicio Menu Cliente-----------------------------------------------------------------------------------------------------------------------------------//
     case 1:
      system("cls");
      do
      {
        opcaoC = menuCliente();
        switch (opcaoC)
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
           do {
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
        }
      } while (opcaoC != 0);
      system("cls");
      break;
//--------------------------------------------------------------Fim Menu Cliente-------------------------------------------------------------------------------------------------------------------------------------//

//--------------------------------------------------------------Inicio Menu Gestor-----------------------------------------------------------------------------------------------------------------------------------//
     case 2:
       do
       {
        opcaoG = menuGestor();
        switch (opcaoG)
        {
         case 4:
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

         case 5:
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
            }  while (1);
           do {
               printf("Nova Morada do cliente -> ");
               scanf(" %[^\n]s", opMorada);
               getchar(); 
               break;
           }  while (1);
           do {
               printf("Saldo da carteira do novo cliente -> ");
               scanf("%f", &opSaldo);
               getchar(); 
               break;
           }  while (1);
            
         listaClientes = alterarCliente(listaClientes, opNif, opNome, opMorada, opSaldo);

         system("pause");
         break;

         case 6:
           system("cls");
           salvarDadosVeiculo(listaVeiculos); 
           system("pause");
           break;

         case 7:
           system("cls");
           do {
               printf("Codigo do novo Veiculo-> "); 
               scanf("%d", &opCodigo);
               getchar(); 
               if (existeVeiculo(listaVeiculos, opCodigo)) // Verifica se o codigo ja existe
               {
                 printf("Ja existe um veiculo com esse codigo! Insira um codigo diferente.\n");
                 continue; // Reinicia o loop para pedir um novo codigo
               }
               break; // Sai do loop quando o codigo for valido e nao existir na lista
           }  while (1); 
           do {
               printf("Tipo do novo veiculo(bicicleta, trotinete ou scooter) -> ");
               scanf(" %[^\n]s", opTipo);
               getchar(); 
               // Verifica se o tipo de veiculo e valido
               if (strcmp(opTipo, "bicicleta") != 0 && strcmp(opTipo, "trotinete") != 0 && strcmp(opTipo, "scooter") != 0)
               {
                 printf("Tipo de veiculo invalido! Insira um tipo de veiculo valido (bicicleta, trotinete ou scooter).\n");
                 continue; // Reinicia o loop para pedir um novo tipo de veiculo
               }
               break;
           }  while (1);
           do {
               printf("Bateria do novo veiculo (0-100) -> ");
               if (scanf("%f", &opBateria) != 1 || opBateria < 0 || opBateria > 100) 
               {
                 printf("Valor invalido! Insira um valor entre 0 e 100.\n");
                 continue; // Reinicia o loop para pedir um novo valor
               }
               getchar(); 
               break;
           }  while (1);
           do {
               printf("Autonomia do novo veiculo -> ");
               scanf("%f", &opAutonomia);
               getchar(); 
               break;
           }  while (1);
           do {
               printf("Custo associado ao novo veiculo -> ");
               scanf("%f", &opCusto);
               getchar(); 
               break;
           } while (1);
            
         listaVeiculos = inserirVeiculo(listaVeiculos, opCodigo, opTipo, opBateria, opAutonomia, opCusto);

         system("pause");
         break; 

         case 8:
           system("cls");
           showDadosVeiculo(listaVeiculos);
           system("pause");
           break;

         case 9:
           system("cls");
           do {
               printf("Codigo do veiculo que deseja remover -> "); 
               scanf("%d", &opCodigo);
               getchar(); 
               if (!existeVeiculo(listaVeiculos, opCodigo)) // Verifica se o codigo não existe
               {
                 printf("Nao existe um veiculo com esse codigo! Insira um codigo existente.\n");
                 continue; // Reinicia o loop para pedir um novo codigo
               }
               break; // Sai do loop quando o codigo for valido e nao existir na lista
           }  while (1);

         listaVeiculos = removerVeiculo(listaVeiculos, opCodigo);
         system("pause");
         break;

         case 10:
           system("cls");
           do {
               printf("Codigo do veiculo que deseja alterar -> "); 
               scanf("%d", &opCodigo);
               getchar(); 
               if (!existeVeiculo(listaVeiculos, opCodigo)) // Verifica se o codigo não existe
               {
                 printf("Nao existe um veiculo com esse codigo! Insira um codigo existente.\n");
                 continue; // Reinicia o loop para pedir um novo codigo
               }
               break; // Sai do loop quando o codigo for valido e nao existir na lista
           }  while (1);
           do {
               printf("Nova da bateria do veiculo -> ");
               scanf("%f", &opBateria);
               getchar(); 
               break;
           }  while (1);
           do {
               printf("Nova Autonomia do Veiculo -> ");
               scanf("%f", &opAutonomia);
               getchar(); 
               break;
          } while (1);
          do {
               printf("Novo Custo do veiculo -> ");
               scanf("%f", &opCusto);
               getchar(); 
               break;
           }  while (1);
            
         listaVeiculos = alterarVeiculo(listaVeiculos, opCodigo, opBateria, opAutonomia, opCusto); 

         system("pause");
         break; 
        }
       } while (opcaoG != 0);
       system("cls");
       break;

    }

  } while (opcao != 0);
  system("cls");
  return 0;
  
 }

 //--------------------------------------------------------------Fim Menu Gestor-----------------------------------------------------------------------------------------------------------------------------------//
