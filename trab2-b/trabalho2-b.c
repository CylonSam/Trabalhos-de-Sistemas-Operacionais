#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int  main() {
    char cwd[PATH_MAX];
    DIR* dir;
    struct dirent *dirEntry;
    struct stat filestat;
    char *filename;
    char *name;
    char *date;

    getcwd(cwd, PATH_MAX); // Armazeno o path no diretório atual na variavel cwd.

    dir = opendir(cwd);  // O diretório é aberto.
    if (dir == 0) { // Checa se o diretório foi aberto com sucesso.
        perror ("Error: could not open directory.");
        exit(1);
    }

    while ((dirEntry = readdir(dir)) != NULL) { // Enquanto houver um arquivo a ser lido no diretorio...
        stat(dirEntry ->d_name, &filestat); // Armazena dados de estado (Ex.: Data da ultima modificação) do arquivo 
                                            // para a struct filestat
        filename =  dirEntry -> d_name; // O nome (d_name) do arquivo lido (dirEntry) é armazenado em filename.

        date = ctime(&filestat.st_mtime); // &filestat.st_mtime -> retorna data da ultima modificação, ctime() -> transforma
                                          // a data em string.
        date[strlen(date) - 1] = 0; // ctime() gera uma string com um \n no final, nesta linha o \n é substituido por 0 (null).
                                    // Ou seja, ele é removido. Pura questão de estética.
        
        printf("%s %s\n", date, filename);
            
    }
    closedir(dir);  // O diretório é fechado

}



