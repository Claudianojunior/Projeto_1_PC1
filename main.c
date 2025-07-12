#include "pessoas.h"
#include "disciplinas.h"
//Menu exclusivo para pessoas

void menu_pessoas(pessoa pessoas[], int indice, int *cont, disciplina disciplinas[]){
    int opcao_pessoa = 0;
    while(opcao_pessoa != 5){
        printf("Escolha uma opção: \n 1- Cadastrar Pessoas; \n 2- Exibir dados de uma pessoa; \n 3- Alterar dados de uma pessoa;");
        printf("\n 4- Remover pessoa; \n 5- voltar ao menu principal\n");
        getchar();
        scanf("%d", &opcao_pessoa);
        
        switch(opcao_pessoa){
        case 1: {
            if(indice <= 54){
                char entrada[250];
                printf("Digite as informaçoes\n");
                getchar();
                scanf("%[^\n]s", entrada);
                cadastro_pessoa(pessoas, entrada, indice, cont);
                printf("Matricula: %s\n", pessoas[indice].matricula);
                indice ++;
                break;
            }
            else{
                printf("Número máximo de pessoas cadastradas!");
                break;
            }
        }

        case 2:{
            exibir_pessoa(pessoas);
            break;

        }

        case 3:{
            alterar_dados(pessoas);
            break;

        }

        case 4:{
            remover_pessoa(pessoas, disciplinas, indice);
        }

        case 5: {
            break;
            }

        default:{
            break;
            }
        }
    }
}

void menu_disciplinas(disciplina disciplinas[], int qtd_dis, pessoa pessoas[]){ int opcao_pessoa;
    int opcao_dis = 0;
    while(opcao_dis != 6){
        printf("Escolha uma opção: \n 1- Cadastrar Disciplina; \n 2- Alterar Professor de uma disciplina; \n 3- Adicionar um aluno a uma disciplina;\n");
        printf(" 4- Remover aluno de uma disciplina; \n 5- Exibir dados de uma disciplina; \n 6- voltar ao menu principal\n");
        getchar();
        scanf("%d", &opcao_dis);

        switch(opcao_dis){
        case 1:{
            char entrada[250];
            printf("Digite as informaçoes\n");
            getchar();
            scanf("%[^\n]s", entrada);
            cadastro_disciplina(disciplinas, entrada, qtd_dis);
            qtd_dis ++;
            break;
        }

        case 2:{
            alterar_prof(disciplinas);
            break;

        }

        case 3:{
            adicionar_aluno(disciplinas);
            break;

        }

        case 4:{
            remover_aluno(disciplinas);
            break;

        }
        case 5:{
            exibir_disciplina(disciplinas, pessoas);
            break;

        }
        case 6:{
            break;
        }
            
        default:{
            break;
        }    
            }
    
        }
    }
int main(){
    int opcao_main = 0;
    
    int qtd_pes = 0;

    int qtd_dis = 0;

    int cont = 0;

    pessoa pessoas[54];

    disciplina disciplinas[5];

    while(opcao_main != 3){
        printf("Escolha uma opção: \n 1- Sistemas de pessoas; \n 2- Sistema de Disciplinas; \n 3- Sair;\n");
        scanf("%d", &opcao_main);

        switch(opcao_main){
        case 1: {
            menu_pessoas(pessoas, qtd_pes, &cont, disciplinas);
            break;
            }
        case 2:{
            menu_disciplinas(disciplinas, qtd_dis, pessoas);
            break;
            }
        case 3: {
            break;
            }

        defaut:{
            printf("Opção invalida! Digite uma opção válida.\n");
            break;
            }
        }
    } 
    return 0;
}