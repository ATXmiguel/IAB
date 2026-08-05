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
{12938302673, "Miguel Godinho",  "4tu9", 3},
{87609864901, "Bruno Bulado",    "1l6p", 3},
{13222926638, "João Pedro",      "0lh0", 3},
{19203847304, "Carlinhos Maia",  "60pr", 2},
{15347659019, "Francisco Assis", "P0l2", 2},
{90847836451, "Gabriel Guedes",  "m0l3", 1},
{14263849028, "Maycon William",  "68p4", 1},
{45673820957, "Mariana Vieira",  "4a7s", 1},
{67672093801, "Augusto Maia",    "6kd0", 1},
{35692840184, "Henrique Vieira", "1lj9", 1}
};

/*Função principal*/

int main(void)
{
    
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    buble();
    /*Loop de autenticação se o usuario não foi autenticado e ainda tem tentativas disponiveis roda a initscreen*/
    while(!autenticado && tentativas<4)
    {
    initscreen();
    }
    /*Caso mesmo depois das tres tentativas o usuario não autentique o programa roda a fail() que encerra o programa*/
    if(!autenticado)
    {
        fail();
    }
    else
    {
        system("pause");
    }
}

/*Inicia a tela, pede o input do usuario e chama as funções de autenticação (check, binario)*/

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

/*No caso dessa função, ela faz a verificação final, depois de saber que o usuario existe
(por conta da função binario(long long alvo)) ela 
checa se a senha inserida bate com a do funcionário registrado.*/

void check(void)
{
    int pos = binario(cpf_login);
    system("cls");
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
        printf("Que bom te ver de novo %s. Seu nivel de acesso atual é: %i/3\n\n", team[pos].nome, team[pos].nivel);
        autenticado = 1;
    }
    else if(strcmp(team[pos].senha, senha_login) != 0)
    {
        printf("CPF ou senha errados\n\n");
        tentativas++;
        printf("Você tem %i/3 tentativas restantes... PRESSIONE QUALQUER TECLA PARA CONTINUAR", 4 - tentativas);
        getch();
        printf("\n\n");
    }

}

/*Essa função basicamente busca o CPF informado na tela inicial se ele encontrar, devolve a posição
do funcionário, caso contrário retorna -1*/

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

/*Faz o ordenamento de todos os CPFs*/

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

/*Em caso de falha nas tentativas de autenticação*/

void fail (void)
{
    printf("Acabaram suas tentativas... Reinicie o programa para prosseguir\n\n\n");
    system("pause");
}
