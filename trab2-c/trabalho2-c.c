//AO RODAR ESSE PROGRAMA, OS ARQUIVOS NO DIRETÓRIO DO EXECUTAVEL SERÃO RENOMEADOS!

#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int  main() {
    char cwd[PATH_MAX];
    DIR* dir;
    struct dirent *dirEntry;
    char *filename;
    char *name;
    char l[PATH_MAX] = "L";

    getcwd(cwd, PATH_MAX); // Armazeno o path no diretório atual na variavel cwd.

    dir = opendir(cwd);  // O diretório é aberto.
    if (dir == 0) { // Checa se o diretório foi aberto com sucesso.
        perror ("Error: could not open directory.");
        exit(1);
    }

    while ((dirEntry = readdir(dir)) != NULL) { // Enquanto houver um arquivo a ser lido no diretorio...
        filename =  dirEntry -> d_name; // O nome (d_name) do arquivo lido (dirEntry) é armazenado em filename.

        char l[PATH_MAX] = "L";
        if (filename[0] != '.'){
            printf("|%s| changed to |L%s|\n", filename, filename);
            strcat(l, filename); //Adiciona L na frente ao contatenar a string l com a string filename.
            rename(filename, l);
            
        }
                    
    }
    closedir(dir);  // O diretório é fechado

}