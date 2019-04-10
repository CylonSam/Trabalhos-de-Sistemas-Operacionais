#include <stdio.h>
#include <unistd.h>

int main(){
    char *args[4];

    args[0] = "sh"; // sh -> shell
    args[1] = "-c"; // Anuncia que o proximo argumento é um commando
    args[2] = "passwd"; // Commando bash que muda a senha do usuario atual
    args[3] = NULL; // execve() exige que o ultimo argumento seja o valor NULL

    printf("# Mudanca de senha iniciada...\n");
    execve("/bin/sh", args, NULL); // Inicia o programa sh (shell) com os argumentos armazenados na array args

    printf("Error"); // Se execve() for bem sucedido, ele nunca voltará para o programa que o chamou, logo se ele
		     // não for bem sucedido, ele executará o printf("Error")
    return 0;
}
