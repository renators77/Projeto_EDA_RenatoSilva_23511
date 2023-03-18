 /**
 * @file main.c
 * @author Renato Silva (a23511@alunos.ipca.cpt)
 * @brief 
 * @version 0.1
 * @date 2023-02-26
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
  printf("|--------------------------------------------------||--------------------------------------------------|\n");
  printf("|          Zona Perfil do Cliente                  ||               Suas Reservas                      |\n");
  printf("|--------------------------------------------------||--------------------------------------------------|\n");
  printf("| 1 - Salvar Dados Clientes                        || 4 - Salvar Dados Reservas                        |\n");
  printf("| 2 - Inserir Novo Cliente                         || 5 - Inserir Reserva                              |\n");
  printf("| 3 - Mostrar Dados Clientes Existentes            || 6 - Mostrar Dados Reservas Existentes            |\n");
  printf("|                                                  || 7 - Remover Reserva                              |\n");
  printf("|                                                  || 8 - Alterar Reserva                              |\n");
  printf("|--------------------------------------------------||--------------------------------------------------|\n");
  printf("|                                        Selecione 0 para sair                                         |\n");
  printf("|--------------------------------------------------||--------------------------------------------------|\n");
  printf("Indique qual a opcao:\n");
  scanf("%d", &opcaoC);
  system("cls");
	return(opcaoC);
}

int menuGestor()
{
  int opcaoG;
  printf("|--------------------------------------------------||--------------------------------------------------||--------------------------------------------------|\n");
  printf("|   Zona De Gerenciamento do Gestor                ||     Zona De Gerenciamento do Cliente             ||      Zona De Gerenciamento de Veiculos           |\n");
  printf("|--------------------------------------------------||--------------------------------------------------||--------------------------------------------------|\n");
  printf("| 1 - Salvar Dados Gestores                        || 6 - Mostrar Dados Cliente Existentes             || 9 - Salvar Dados Veiculos                        |\n");
  printf("| 2 - Inserir Novo Gestor                          || 7 - Remover Cliente                              || 10 - Inserir Novo Veiculo                        |\n");
  printf("| 3 - Mostrar Dados Gestores Existentes            || 8 - Alterar Cliente                              || 11 - Mostrar Dados Veiculos Existentes           |\n");
  printf("| 4 - Remover Gestor                               ||                                                  || 12 - Remover Veiculo                             |\n");
  printf("| 5 - Alterar Gestor                               ||                                                  || 13 - Alterar Veiculo                             |\n");
  printf("|                                                  ||                                                  || 14 - Mostrar Veiculo por Maior Autonomia         |\n");
  printf("|--------------------------------------------------||--------------------------------------------------||--------------------------------------------------|\n");
  printf("|                                                                Selecione 0 para sair                                                                     |\n");
  printf("|----------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
 
  printf("Indique qual a opcao:\n"); 
  scanf("%d", &opcaoG);
  system("cls");
	return(opcaoG);
}



/**
 * @brief Main com o menu de interaçao com o utilizador
 * 
 * @return 
 */
int main()
{

  //MENUS
  int opcao = 0, opcaoC = 0, opcaoG = 0;

  //Clientes
   int opNif = 0;
  char opNome[50], opMorada[100];
  float opSaldo;

  //Gestores
  int opId = 0;
  char opNomeG[50];


  //Veiculos
  int opCodigo = 0;
  char opTipo[50];
  float opBateria, opAutonomia, opCusto;

  //Reservas
  int opIdReserva = 0;
  int opEstado = 0;

  
  //Lista ligada vazia clientes
  cliente *listaClientes = NULL;

  //Lista ligada vazia Veiculos
  veiculo *listaVeiculos = NULL;

  //Lista ligada vazia Gestores
  gestor *listaGestores = NULL;

  //Lista ligada vazia Reservas
  reserva *listaReservas = NULL;

  //Load dos dados da listaCliente
  listaClientes = loadDadosCliente(listaClientes);

  //Load dos dados da listaVeiculos
  listaVeiculos = loadDadosVeiculo(listaVeiculos);

  //Load dos dados da listaGestores
  listaGestores = loadDadosGestor(listaGestores);

//Load dos dados da listaReservas
  listaReservas = loadDadosReserva(listaClientes, listaVeiculos, listaReservas);

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
           system("cls");
           break;

         case 4:
           system("cls");
           salvarDadosReserva(listaReservas); 
           system("pause");
           break;

         case 5:
           system("cls");
            do {
                 printf("id da nova reserva -> "); 
                 scanf("%d", &opIdReserva);
                 getchar(); 
                 if (existeReserva(listaReservas, opIdReserva)) // Verifica se o id da reserva ja existe
                 {
                   printf("Ja existe uma Reserva com esse Id! Insira um Id diferente.\n");
                   continue; // Reinicia o loop para pedir um novo Id
                 }
                 break; // Sai do loop quando o Id for valido e nao existir na lista
             } while (1); 
            do {
                 printf("nif do cliente que vai reservar (9 digitos) -> "); 
                 scanf("%d", &opNif);
                 getchar(); 
                 if (opNif < 100000000 || opNif > 999999999) // Verifica se o NIF tem 9 digitos
                 { 
                   printf("NIF invalido! Insira um NIF valido com 9 digitos.\n");
                   continue; // Reinicia o loop para pedir um novo NIF
                 }  
                 else if (!existeCliente(listaClientes, opNif)) // Verifica se o Id Nao existe
                 {
                   printf("Não existe um cliente com esse NIF! Insira um NIF diferente.\n");
                   continue; // Reinicia o loop para pedir um novo NIF
                 }
                 break; // Sai do loop quando o NIF for valido e existir na lista
             } while (1); 
            do {
                 printf("Codigo do veiculo que deseja Reservar -> "); 
                 scanf("%d", &opCodigo);
                 getchar(); 
                 if (!existeVeiculo(listaVeiculos, opCodigo)) // Verifica se o codigo não existe
                 {
                   printf("Nao existe um veiculo com esse codigo! Insira um codigo existente.\n");
                   continue; // Reinicia o loop para pedir um novo codigo
                 }
                 break; // Sai do loop quando o codigo for valido e nao existir na lista
             } while (1);
            
           listaReservas = inserirReserva(listaClientes, listaVeiculos, listaReservas, opIdReserva, opNif, opCodigo, opEstado);

           system("pause");
           break;
         case 6:
           system("cls");
           showDadosReserva(listaReservas);
           system("pause");
           break;
         case 7:
           system("cls");
           do {
               printf("Id da Reserva do que deseja remover -> "); 
               scanf("%d", &opIdReserva);
               getchar(); 
               if (!existeReserva(listaReservas, opIdReserva)) // Verifica se o Id Reserva não existe
               {
                 printf("Nao existe uma Reserva com esse Id! Insira um Id existente.\n");
                 continue; // Reinicia o loop para pedir um novo id
               }
               break; // Sai do loop quando o id for valido e nao existir na lista
           }  while (1);

           listaReservas = removerReserva(listaReservas, opIdReserva);
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
         case 1:
           system("cls");
           salvarDadosGestor(listaGestores); 
           system("pause");
           break;

         case 2:
           system("cls");
           do {
               printf("Id do novo Gestor -> "); 
               scanf("%d", &opId);
               getchar(); 
               if (existeGestor(listaGestores, opId)) // Verifica se o id ja existe
               {
                 printf("Ja existe um gestor com esse id! Insira um id diferente.\n");
                 continue; // Reinicia o loop para pedir um novo id
               }
               break; // Sai do loop quando o id for valido e nao existir na lista
           }  while (1); 
           do {
               printf("Nome do novo Gestor -> ");
               scanf(" %[^\n]s", opNomeG);
               getchar(); 
               break;
           } while (1);
            
           listaGestores = inserirGestor(listaGestores, opId, opNomeG);

           system("pause");
           break;

         case 3:
           system("cls");
           showDadosGestor(listaGestores);
           system("pause");
           system("cls");
           break;
         
         case 4:
           system("cls");
           do {
               printf("id do Gestor que deseja remover -> "); 
               scanf("%d", &opId);
               getchar(); 
               if (!existeGestor(listaGestores, opId)) // Verifica se o id não existe
               {
                 printf("Nao existe um gestor com esse id! Insira um id existente.\n");
                 continue; // Reinicia o loop para pedir um novo id
               }
               break; // Sai do loop quando o id for valido e nao existir na lista
           }  while (1);

         listaGestores = removerGestor(listaGestores, opId);
         system("pause");
         break;

         case 5:
           system("cls");
           do {
               printf("id do gestor que deseja alterar -> "); 
               scanf("%d", &opId);
               getchar(); 
               if (!existeGestor(listaGestores, opId)) // Verifica se o Id não existe
               {
                 printf("Nao existe um Gestor com esse id! Insira um id existente.\n");
                 continue; // Reinicia o loop para pedir um novo id
               }
               break; // Sai do loop quando o id for valido e nao existir na lista
           }  while (1);
           do {
               printf("Novo Nome do Gestor -> ");
               scanf(" %[^\n]s", opNomeG);
               getchar(); 
               break;
            }  while (1);
            
         listaGestores = alterarGestor(listaGestores, opId, opNomeG);

         system("pause");
         break;

         case 6:
           system("cls");
           showDadosCliente(listaClientes);
           system("pause");
           break;

         case 7:
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

         case 8:
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

         case 9:
           system("cls");
           salvarDadosVeiculo(listaVeiculos); 
           system("pause");
           break;

         case 10:
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

         case 11:
           system("cls");
           showDadosVeiculo(listaVeiculos);
           system("pause");
           break;

         case 12:
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

         case 13:
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

         case 14:
            system("cls");
            showDadosIteractiveVeiculos(listaVeiculos);
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
