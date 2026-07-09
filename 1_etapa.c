#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void initscreen(void);
void check (void);
long long cpf_login;
char senha_login[50];
struct funcionarios
{
    long long cpf;
    char nome [50];
    char senha[30];
    int nivel;
};
struct funcionarios team[4] = {
{12938302673, "Miguel", "amo67", 2},
{87609864901, "Bulado", "adoro42", 3},
{14263849028, "Julia", "odeio67", 1},
{19203847304, "Joao", "seissete", 3}
};
int main(void)
{
    
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    initscreen();
    check();
}

void initscreen(void)
{
    printf("//////          /////\\\\\\\\\\          ||||||||\\\\   \n");
    printf("//////         /////  \\\\\\\\\\         |||||    \\\\  \n");
    printf("              /////    \\\\\\\\\\        |||||    |||   \n");
    printf("||||||       /////      \\\\\\\\\\       |||||    //    \n");
    printf("||||||      /////        \\\\\\\\\\      |||||||||      \n");
    printf("||||||     /////||||||||||\\\\\\\\\\     |||||    \\\\  \n");
    printf("||||||    /////            \\\\\\\\\\    |||||     \\\\ \n");
    printf("||||||   /////              \\\\\\\\\\   |||||     //   \n");
    printf("||||||  /////                \\\\\\\\\\  |||||||||//  \n\n");                                                                             
    printf("     SEJA BEM VINDO AO PROJETO NÊMESIS! \n\n");                                                                                          
    printf("===================================================== \n\n");
    printf("             DIGITE SEU CPF:  ");
    scanf(" %lld", &cpf_login);
    printf("\n\n");
    printf("===================================================== \n\n");
    printf("             DIGITE A SENHA: ");
    scanf(" %30s", senha_login);
    printf("\n\n");
    printf("===================================================== \n\n");
}
void check (void)
{
    for(int i = 0; i < 4; i++)
    {
       if((team[i].cpf == cpf_login)&& strcmp(team[i].senha, senha_login) == 0)
       {
            printf("Acesso LIBERADO");
            return;
       }
    }
    printf("CPF ou senha incorretos");
}