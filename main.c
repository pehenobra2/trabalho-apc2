#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define tam 1000

void menu();
void cadastra_estado(char estado[], FILE *f1);
void cadastra_curso(char curso[], FILE *f2);
void cadastra_pessoa(char nome[], char sexo[], int idade, FILE *f3);

int main (){

    setlocale(LC_ALL, "Portuguese");
    int opcoes;
    FILE *f1, *f2, *f3;


    struct dados{

        char nome[tam], estado[tam], curso[tam], sexo[tam];
        int idade;

    };

    struct dados pessoas;

    do{
        menu();

        printf("Escolha uma das opções: \n");

        scanf("%d", &opcoes);

        if(opcoes > 8 ){

            printf("Opção inválida!\n ");
            scanf("%d", &opcoes);
        }

        if(opcoes == 1){
                cadastra_estado(pessoas.estado, f1);

        }
        if(opcoes == 2){
                cadastra_curso(pessoas.curso, f2);

        }

        if(opcoes == 3){
                cadastra_pessoa(pessoas.nome, pessoas.sexo, pessoas.idade, f3);

        }
        if(opcoes == 4){


        }
        if(opcoes == 5){

        }
        if(opcoes == 6){

        }
        if(opcoes == 7){

        }

    }while(opcoes != 8);

}

void menu(){

    printf("Menu de opções: \n1) Cadastrar Estado\n2) Cadastrar curso\n3) Cadastrar Pessoa\n4) Listar pessoas por Estado\n5) Listar pessoas por Curso Desejado\n6) Consultar Pessoa por Nome\n7) Gerar relatório demográfico\n8) Finalizar Programa\n");

}

void cadastra_estado(char estado[], FILE *f1){

    printf("Digite o estado: ");
    getchar();
    scanf("%[^\n]s", estado);

    f1 = fopen("estados.txt", "a+t");

    if(f1 == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO!\n");
        system("pause");
        exit(1);
    }

    fprintf(f1, "%s", estado);

    fclose(f1);

    printf("__________________________\n");

}

void cadastra_curso(char curso[], FILE *f2){

    printf("Digite o curso: ");
    getchar();
    scanf("%[^\n]s", curso);


    f2 = fopen("cursos.txt", "a+t");

    if(f2 == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO!\n");
        system("pause");
        exit(1);
    }

    fprintf(f2, "%s", curso);

    fclose(f2);

    printf("__________________________\n");

}

void cadastra_pessoa(char nome[], char sexo[], int idade, FILE *f3){

    getchar();
    printf("Digite o nome: ");
    fgets(nome, tam, stdin);
    printf("Digite o sexo: ");
    fgets(sexo, tam, stdin);
    printf("Digite a idade: ");
    scanf("%d", &idade);

    if(idade <= 0){
        printf("Idade incorreta, digite novamente: ");
        scanf("%d", &idade);

    }


    f3 = fopen("pessoa.txt", "a+t");

    if(f3 == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO!\n");
        system("pause");
        exit(1);
    }

    fprintf(f3, "%s", nome);
    fprintf(f3, "%s", sexo);
    fprintf(f3, "%d\n", idade);
    fprintf(f3,"\n__________________________\n");

    fclose(f3);

    printf("__________________________\n");

}
