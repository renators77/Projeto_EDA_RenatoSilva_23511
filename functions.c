#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <header.h>

/**
 * @brief Função para criar o ficheiro txt 
 * 
 * @return 
 */
void informacaocliente(cliente *clientes, int nif, char nome, char morada)
{
    char* nome_ficheiro = "clientesLista.txt";
    FILE *ficheiro;
    //abre o arquivo de texto para leitura
    ficheiro = fopen(nome_ficheiro, "r");
    //verificação do ficheiro
    if (ficheiro == NULL) 
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    fscanf(ficheiro, "%d %d", &nif,&nome, &morada);
    // fecha o arquivo
    fclose(ficheiro);
    printf("Dados armazenados no arquivo com sucesso.");
    return 0;
}