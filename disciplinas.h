#ifndef DISCIPLINAS_H
#define DISCIPLINAS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estruturas.h"

void cadastro_disciplina(disciplina disciplinas[], char entrada[], int index);
void alterar_prof(disciplina disciplinas[]);
void adicionar_aluno(disciplina disciplinas[]);
void remover_aluno(disciplina disciplinas[]);
void exibir_disciplina(disciplina disciplinas[], pessoa p[]);

#endif