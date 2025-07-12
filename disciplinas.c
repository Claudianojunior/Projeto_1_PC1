#include "disciplinas.h"

void cadastro_disciplina(disciplina disciplinas[], char entrada[], int index){
    char entrada_copia[250];
    strcpy(entrada_copia, entrada);

    char *parts = strtok(entrada_copia, ";");

    if(parts != NULL){
        strcpy(disciplinas[index].codigo, parts);

    }

    parts = strtok(NULL, ";");

    if(parts != NULL){
        strcpy(disciplinas[index].nome, parts);

    }

    parts = strtok(NULL, ";");

    if(parts != NULL){
        strcpy(disciplinas[index].carga_hor, parts);
    }

    parts = strtok(NULL, ";");

    if(parts != NULL){
        strcpy(disciplinas[index].professor, parts);
    }

}

void alterar_prof(disciplina disciplinas[]){
    char codigo[6];
    printf("Digite o código da disciplina:\n");
    getchar();
    scanf("%[^\n]s", codigo);

    for(int i = 0; i < 5; i++){
        if(!strcmp(disciplinas[i].codigo, codigo)){
            printf("Digite o PIS do novo professor:\n");
            getchar();
            char pis[12];
            scanf("%[^\n]s", pis);
            strcpy(disciplinas[i].professor, pis);
        }
    }


}

void adicionar_aluno(disciplina disciplinas[]){
    char codigo[6];
    printf("Digite o código da disciplina:\n");
    getchar();
    scanf("%[^\n]s", codigo);

    for(int i = 0; i < 5; i++){
        if(!strcmp(disciplinas[i].codigo, codigo)){
            printf("Digite a matricula do aluno: \n");
            char mat[6];
            getchar();
            scanf("%[^\n]s", mat);
            strcpy(disciplinas[i].alunos[disciplinas[i].qtde_alu], mat);
            disciplinas[i].qtde_alu ++;
            break;
        }
    }
}

void remover_aluno(disciplina disciplinas[]){
    char codigo[6];
    printf("Digite o código da disciplina:\n");
    getchar();
    scanf("%[^\n]s", codigo);

    for(int i = 0; i < 5; i++){
        if(!strcmp(disciplinas[i].codigo, codigo)){
            printf("Digite a matricula do aluno:\n");
            char mat[6];
            getchar();
            scanf("%[^\n]s", mat);

            for (int j = 0; j < disciplinas[i].qtde_alu; j++) {
                if (!strcmp(disciplinas[i].alunos[j], mat)){
                    for (int k = j; k < disciplinas[i].qtde_alu - 1; k++) {
                        strcpy(disciplinas[i].alunos[k], disciplinas[i].alunos[k + 1]);
                    }
                    strcpy(disciplinas[i].alunos[disciplinas->qtde_alu], "0");
                    disciplinas[i].qtde_alu--;
                } 
            }
        }
    }
}

void exibir_disciplina(disciplina disciplinas[], pessoa p[]){
    char codigo[6];
    printf("Digite o código da disciplina:\n");
    getchar();
    scanf("%[^\n]s", codigo);

    for(int i = 0; i < 5; i++){
        if(!strcmp(disciplinas[i].codigo, codigo)){
            printf("=====================================\n");
            printf("Codigo: %s\n", disciplinas[i].codigo);
            printf("Nome: %s\n", disciplinas[i].nome);
    
            for(int j = 0; j < 55; j++){
                if(!strcmp(p[j].PIS, disciplinas[i].professor)){
                    printf("Nome do professor(a): %s\n", p[j].nome);
                }
            }
    
            for (int j = 0; j < disciplinas[i].qtde_alu; j++) {  // Alterado para qtde_alu
                int matricula_encontrada = 0;  // Flag para verificar se a matrícula foi encontrada
                    for (int k = 0; k < 55; k++) {
                        // Comparando a matrícula do aluno da disciplina com a matrícula na lista de pessoas
                        if (!strcmp(p[k].matricula, disciplinas[i].alunos[j])) {
                            printf("Nome do aluno(a): %s - Matrícula: %s\n", p[k].nome, p[k].matricula);
                        }
                    }
                }
    
            printf("=====================================\n");
        }
    }
}
