#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <stdio.h>

typedef struct pessoa{
    char nome[51];
    char sobrenome[51];
    int brasileiro;
    char cpf[12];
    char sigla[3];
    char passaporte[21];
    char pais_origem[51];
    char data_nasc[11];
    int PcD;
    char laudo[11];
    char CEP[9];
    int aluno;
    char matricula[12];
    char PIS[12];
}pessoa;

typedef struct disciplina{
    char codigo[9];
    char nome[51];
    char carga_hor[3];
    char professor[12];
    char alunos[10][6];
    int qtde_alu;
}disciplina;

typedef struct escola{
    pessoa alunos[50];
    int qtd_alu;
    pessoa professor[5];
    int qtd_prof;
    disciplina disciplinas[5];
    int qtd_dis;
}escola;

#endif