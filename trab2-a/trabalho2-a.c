#include <stdio.h>
#include <fcntl.h>
#define MAX_LEN 100 // Define o tamanho max (MAX_LEN) para o nome de cada arquivo de entrada

int main()
{

    int arquivo1, arquivo2, arquivoSaida; // O texto concatenado do arquivo1 com o arquivo2 eh gerado no arquivoSaida
    char nome_arquivo1[MAX_LEN];
    char nome_arquivo2[MAX_LEN];
    char *outFileName = "texto-concatenado.txt"; // O nome do arquivo de saida sera texto-concatenado.txt
    int estado; // Armazena o estado da leitura de arquivo (read), enquanto houver algo para ser lido, read retornará 1
    char c; // Buffer para a leitura (read) e escrita (write), o tamanho do buffer é o de um char, então a leitura e escrita
            // será feita UM caractere por vez.

    printf("Digite o nome do primeiro arquivo: ");
    scanf("%[^\n]%*c", nome_arquivo1); // Lê tudo (%[]) menos (^) a nova linha (\n) gerada por um enter, depois lê
                                       // a nova linha gerada e descarta (%*c)  
    printf("Digite o nome do segundo arquivo: ");
    scanf("%[^\n]%*c", nome_arquivo2);

    // Os arquivos escolhidos são abertos
    arquivo1 = open(nome_arquivo1, O_RDONLY);
    arquivo2 = open(nome_arquivo2, O_RDONLY);

    // Se não houver um arquivo chamado texto-concatenado.txt no diretório, ele cria um (O_CREAT).
    arquivoSaida = open(outFileName, O_CREAT | O_WRONLY, 0666); //0666 define as permissões de acesso ao arquivo.

    // Enquanto houver um caractere a ser lido (estado > 0), ele será lido no buffer (&c) e então
    // este caractere será escrito no arquivo de saida
    while ((estado = read(arquivo1, &c, 1)) > 0) //1 é o tamanho do buffer, no caso 1 byte.
        write(arquivoSaida, &c, 1);

    while ((estado = read(arquivo2, &c, 1)) > 0)
        write(arquivoSaida, &c, 1);

    // Tudo que foi aberto precisa ser fechado.
    close(arquivo1);
    close(arquivo2);
    close(arquivoSaida);
}