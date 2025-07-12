#include "pessoas.h"

void cadastro_pessoa(pessoa pessoas[], char entrada[], int indice, int *count_mat){
    char entrada_copia[250];
    strcpy(entrada_copia, entrada);
    
    char *parts = strtok(entrada_copia, ";");
    
    //Seguindo a ordem de entrada nome;sobrenome;Brasileiro;CPF/passaporte;sigla_estado/pais;DD/MM/AAAA;0;Laudo;CEP;0:PIS
    //Armazenando o nome
    if(parts != NULL){
        strcpy(pessoas[indice].nome, parts);

    }
    
    parts = strtok(NULL, ";");

    //Armazenando o sobrenome
    if(parts != NULL){
        strcpy(pessoas[indice].sobrenome, parts);

    }

    parts = strtok(NULL, ";");

    //Armazenando o brasileiro
    if(parts != NULL){
        char str[2];
        strcpy(str, parts);
        int brasil = atoi(str);
        pessoas[indice].brasileiro = brasil;

    }

    parts = strtok(NULL, ";");

    //Confere se brasileiro e armazena cpf ou passaporte
    if(parts != NULL){
        if(pessoas[indice].brasileiro == 0){
            if(strlen(parts) == 11){
            strcpy(pessoas[indice].cpf, parts);
            }
        else{
            printf("Cpf invalido\n");
            }
        }
        else{
            strcpy(pessoas[indice].passaporte, parts);
        }
    }

    parts = strtok(NULL, ";");

    //Confere se brasileiro e armazena sigla ou pais
    if(parts != NULL){
        if(pessoas[indice].brasileiro == 0){
            strcpy(pessoas[indice].sigla, parts);
        }
        else{
            strcpy(pessoas[indice].pais_origem, parts);
        }
    }

    parts = strtok(NULL, ";");

    //Armazena a data de nascimento
    if(parts != NULL){
       strcpy(pessoas[indice].data_nasc, parts);
    }

    parts = strtok(NULL, ";");

    //Confere se Pcd 
    if(parts != NULL){
        char str[2];
        strcpy(str, parts);
        int pcd = atoi(str);
        pessoas[indice].PcD = pcd;
    }

    parts = strtok(NULL, ";");

    //Confere se pcd e armazena o laudo
    if(parts != NULL){
        if(pessoas[indice].PcD == 1){
            strcpy(pessoas[indice].laudo, parts);
            parts = strtok(NULL, ";");
        }
    }

    //Armazena o cep
    if(parts != NULL){
        strcpy(pessoas[indice].CEP, parts);
    
    }

    parts = strtok(NULL, ";");

    //Confere se aluno ou professor
    if(parts != NULL){
        char str[2];
        strcpy(str, parts);
        int alu = atoi(str);
        pessoas[indice].aluno = alu;
    }

    if(pessoas[indice].aluno == 0){
        int matricula = 25000 + (*count_mat);
        sprintf(pessoas[indice].matricula, "%d", matricula);
        (*count_mat)++;
    }

    if(pessoas[indice].aluno == 1){
        parts = strtok(NULL, ";");
        strcpy(pessoas[indice].PIS, parts);
    }

}

void exibir_dados(pessoa p[], int index){
    printf("=====================================\n");
    printf("Nome: %s\n", p[index].nome);
    printf("Sobrenome: %s\n", p[index].sobrenome);
    
    printf("Brasileiro: %s\n", p[index].brasileiro == 0 ? "Sim" : "Não");
    
    if (p[index].brasileiro == 0) { // brasileiro
        printf("CPF: %s\n", p[index].cpf);
        printf("Estado (UF): %s\n", p[index].sigla);
    } else { // estrangeiro
        printf("Passaporte: %s\n", p[index].passaporte);
        printf("País de origem: %s\n", p[index].pais_origem);
    }
    
    printf("Data de Nascimento: %s\n", p[index].data_nasc);
    printf("PcD: %s\n", p[index].PcD == 1 ? "Sim" : "Não");
    
    if (p[index].PcD == 1) {
        printf("Laudo: %s\n", p[index].laudo);
    }
    
    printf("CEP: %s\n", p[index].CEP);
    printf("Tipo: %s\n", p[index].aluno == 0 ? "Aluno" : "Professor");
    
    if (p[index].aluno == 0) {
        printf("Matricula: %s\n", p[index].matricula);
    } else {
        printf("PIS: %s\n", p[index].PIS);
    }
    
    printf("=====================================\n");
}

void exibir_pessoa(pessoa pessoas[]){
    int opc, index; 
    int encontrado = 0;
    char str[12];
    printf("Para buscar digite :\n 1- Professor;\n 2- Aluno; \n");
    getchar();
    scanf("%d", &opc);

    if(opc == 1){
        printf("Digite o PIS do professor:\n");
        getchar();
        scanf("%[^\n]s", str);

        for(int i = 0; i < 55; i++){
            if(!strcmp(str, pessoas[i].PIS)){
                index = i;
                encontrado = 1;
                exibir_dados(pessoas, index);
                break;
            }
        }
        if(encontrado == 0){
            printf("Professor não encontrado!\n");
        }
    }
    else{
        printf("Digite a matricula do aluno:\n");
        getchar();
        scanf("%[^\n]s", str);

        for(int i = 0; i < 55; i++){
            if(!strcmp(str, pessoas[i].matricula)){
                index = i;
                encontrado = 1;
                exibir_dados(pessoas, index);
            }
        }
        if(encontrado == 0){
            printf("Aluno não encontrado!\n");
        }
    }
}

void remover_pessoa(pessoa pessoas[], disciplina disciplinas[], int qtd_pes){
    int pessoa_vinculada = 0;
    int opc;
    char mat[6];
    char pis[12];
    printf("Para remover dados de um ... digite :\n 1- Professor;\n 2- Aluno; \n");
    getchar();
    scanf("%d", &opc);

    // Verifica se está matriculada em alguma disciplina
    if(opc == 2){
    printf("Digite a matricula do aluno:\n");
    getchar();
    scanf("%[^\n]s", mat);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (!strcmp(disciplinas[i].alunos[j], mat)) {
                printf("Pessoa matriculada como aluno em uma disciplina, não pode ser removida!\n");
                pessoa_vinculada = 1;
                break;
            }
        }
    }
    }
    // Verifica se é professor de alguma disciplina
    else{
        printf("Digite o PIS do professor(a):\n");
        getchar();
        scanf("%[^\n]s", pis);
        for (int i = 0; i < 5; i++) {
            if (!strcmp(disciplinas[i].professor, pis)) {
                printf("Pessoa matriculada como Professor em uma disciplina, não pode ser removida!\n");
                pessoa_vinculada = 1;
                break;
            }
        
        }   
    }  
    if(pessoa_vinculada){
        return;
    } 
    else{
        if(opc == 2){
            for (int i = 0; i < qtd_pes; i++) {
                if (strcmp(pessoas[i].matricula, mat) == 0) {
                // Move todos os seguintes pra esquerda
                strcpy(pessoas[i].matricula, "0"); 
                    for (int j = i; j < qtd_pes - 1; j++) {
                        pessoas[j] = pessoas[j + 1];
                    }
                qtd_pes--;  
                return;
                }
            }
        }
        else{
            for (int i = 0; i < qtd_pes; i++) {
                if (strcmp(pessoas[i].PIS, pis) == 0) {
                // Move todos os seguintes pra esquerda
                strcpy(pessoas[i].PIS, "0");
                    for (int j = i; j < qtd_pes - 1; j++) {
                        pessoas[j] = pessoas[j + 1];
                    }
                qtd_pes--;
                return;
                }
            }
        }
    }

}

void alterar_dados(pessoa pessoas[]){
    int index; 
    int encontrado = 0;
    int opc, opc2;
    char str[12];
    printf("Para alterar dados de um ... digite :\n 1- Professor;\n 2- Aluno; \n");
    getchar();
    scanf("%d", &opc);

    if(opc == 1){
        printf("Digite o PIS do professor:\n");
        getchar();
        scanf("%[^\n]s", str);

        for(int i = 0; i < 55; i++){
            if(!strcmp(str, pessoas[i].PIS)){
                index = i;
                encontrado = 1;
                break;
            }
        }
        if(encontrado == 0){
            printf("Professor não encontrado!\n");
        }
    }
    else{
        printf("Digite a matricula do aluno:\n");
        getchar();
        scanf("%[^\n]s", str);

        for(int i = 0; i < 55; i++){
            if(!strcmp(str, pessoas[i].matricula)){
                index = i;
                encontrado = 1;
                exibir_dados(pessoas, index);
            }
        }
        if(encontrado == 0){
            printf("Aluno não encontrado!\n");
        }
    }

    if(encontrado == 1){
        printf("Digite a opção para o dado que deseja alterar:\n 1- Pessoa com deficiência(Pcd); \n 2- Laudo;\n 3- CEP\n");
        getchar();
        scanf("%d", &opc2);
        switch(opc2) {
            case 1:{
                int aux;
                char laudo[11];
                printf("Pessoa com deficiência? Digite:\n 0- Não;\n 1- Sim;\n");
                getchar();
                scanf("%d", &aux);
                pessoas[index].PcD = aux; 
                printf("Insira o novo código do laudo:\n");
                getchar();
                scanf("%[^\n]s", laudo);
                strcpy(pessoas[index].laudo, laudo);
                break;
            }

            case 2:{
                char aux[11];
                printf("Insira o novo código do laudo:\n");
                getchar();
                scanf("%[^\n]s", aux);
                strcpy(pessoas[index].laudo, aux);
                break;
            }
            
            case 3:{
                char aux[9];
                printf("Insira o novo CEP:\n");
                getchar();
                scanf("%[^\n]s", aux);
                strcpy(pessoas[index].CEP, aux);
                break;
            }
        }
    }
}
