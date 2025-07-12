#ifndef PESSOAS_H
#define PESSOAS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estruturas.h"

void cadastro_pessoa(pessoa pessoas[], char entrada[], int indice, int *count_mat);
void exibir_dados(pessoa p[], int index);
void exibir_pessoa(pessoa pessoas[]);
void remover_pessoa(pessoa pessoas[], disciplina disciplinas[], int qtd_pes);
void alterar_dados(pessoa pessoas[]);

#endif