#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

/*Avisar o compilador que essas funções vão ser declaradas mais pra frente*/

void initscreen(void);
void check (void);
void buble(void);
int binario (long long alvo);
void fail (void);

/*Declaração de variáveis*/

long long cpf_login;
char senha_login[50];
int tentativas = 0;
int autenticado = 0;

/*Declaração do struct funcionários e de um vetor do tipo funcionários*/

struct funcionarios
{
    long long cpf;
    char nome [50];
    char senha[30];
    int nivel;
};
struct funcionarios team[10] = {
{12938302673, "Miguel Godinho", "amo67", 3},
{87609864901, "Bruno Bulado", "adoro42", 3},
{14263849028, "Maycon William", "odeio67", 1},
{19203847304, "Carlinhos Maia", "seissete", 2},
{15347659019, "Francisco Assis", "fourtwo", 2},
{90847836451, "Gabriel Guedes", "vavaS2", 1},
{98375640183, "João Pedro", "0000", 3},
{45673820957, "Mariana Vieira", "4242", 1},
{67672093801, "Augusto Maia", "6767", 1},
{35692840184, "Henrique Vieira", "nichememe", 1}
};

/*Função principal*/

int main(void)
{
    
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    buble();
    while(!autenticado && tentativas<4)
    {
    initscreen();
    }
    if(!autenticado)
    {
        fail();
    }
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
    check();
}
void check(void)
{
    int pos = binario(cpf_login);
    if(pos == -1)
    {
        printf("CPF ou senha errados\n\n");
        tentativas++;
        printf("Você tem %i/3 tentativas restantes... PRESSIONE QUALQUER TECLA PARA CONTINUAR", 4 - tentativas);
        getch();
        printf("\n\n");
    }
    else if(strcmp(team[pos].senha, senha_login) == 0)
    {
        printf("Que bom te ver de novo %s. Seu nivel de acesso atual é: %i/3", team[pos].nome, team[pos].nivel);
        autenticado = 1;
    }
    else if(strcmp(team[pos].senha, senha_login) != 0)
    {
        printf("CPF ou senha errados\n\n");
        printf("Você tem %i/3 tentativas restantes... PRESSIONE QUALQUER TECLA PARA CONTINUAR", 4 - tentativas);
        getch();
        printf("\n\n");
    }
}
int binario (long long alvo)
{
    int inicio = 0;
    int fim = 9;
    int meio = (inicio + fim) / 2;
    while(inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (alvo > team[meio].cpf)
        {
            inicio = meio + 1;
        }
        else if (alvo < team[meio].cpf)
        {
            fim = meio - 1;
        }
        else if(alvo == team[meio].cpf)
        {
            return meio;
        }   
    }
    return -1;
}
void buble (void)
{
    struct funcionarios temp;
    for (int j = 0; j < 9; j++)
    {
    for(int i = 0; i < 9;i++)
    {
        if (team[i].cpf > team[i+1].cpf)
        {
            temp = team[i];
            team[i] = team[i+1];
            team[i+1] = temp;
        }
    }
    }
}
void fail (void)
{
    printf("Acabaram suas tentativas... Reinicie o programa para prosseguir\n\n\n");
    system("pause");
}
