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
    ficheiro = fopen(nome_ficheiro, "w");
    if (ficheiro == NULL) 
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    fprintf(ficheiro, "Este é um exemplo de texto que será escrito no arquivo.\n");
    fclose(ficheiro);
    printf("Dados armazenados no arquivo com sucesso.");
    return 0;
}