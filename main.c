#include <stdio.h>
#include <string.h>
#include <stdbool.h> // Para usar booleanos em C

// Modelo de aluno
// Utilizando typedef para tirar a necessidade de usar 'struct' toda vez
typedef struct{
    char nome[100];
    int idade;
    char sala[10];
    int presenca;
    float nota_1, nota_2, nota_3;
    char situacao[30];
} Aluno;

/*  
    limparTela

    Função para limpar tela. Irá printar várias linhas em branco.
    ---
    Desde: 03/11/2025
    Autor: Nicolas - Arthur
    Versão: 1.0
*/
void limparTela(){
    for(int i = 0; i < 100; i++){
        printf("\n");
    }
}

/*
    calcularMedia

    Função para calcular a média ponderada das notas do aluno e Frequencia.
    Irá retornar a situação do aluno (Aprovado, Recuperação ou Reprovado).
    ---
    Desde: 03/11/2025
    Autor: Nicolas - Arthur 
    Versão: 1.0
*/
char calcularMediaFrequencia(int frequencia, float nota1, float nota2, float nota3){
    char situacao[30];
    float media = ((nota1 * 2) + (nota2 * 3) + (nota3 * 5)) / 10;
    if (frequencia < 75){
        strcpy(situacao, "Reprovado");
    } else{
        if (media >= 60.0){
            strcpy(situacao, "Aprovado");
            return situacao[0];
        } else if (media >= 50.0){
            strcpy(situacao, "Recuperação");
            return situacao[0];
        } else {
            strcpy(situacao, "Reprovado");
            return situacao[0];
        }
    }
}

/*
    pegarNota

    Função para pegar nota do aluno.
    Irá validar se a nota está entre 0 e 10.
    ---
    Desde: 03/11/2025
    Autor: Nicolas - Arthur
    Versão: 1.0
*/
int pegarNota(int numeroNota){
    float nota;
    while (true){
        printf("Digite a nota %d (0 a 100): ", numeroNota);
        scanf("%f", &nota);
        getchar();
        if (nota >= 0 && nota <= 100){
            return nota;
        } else {
            printf("Nota inválida! Tente novamente.\n");
        }
    }
}

/*
    armazenarAluno

    Função para armazenar aluno em um arquivo de texto.
    Utiliza Fopen para abrir o arquivo e fputs para escrever no arquivo.
    ---
    Desde: 03/11/2025
    Autor: Nicolas - Arthur
    Versão: 1.0
*/
void armazenarAluno(Aluno aluno){
    FILE *arquivo = fopen("alunos.txt", "w");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    fprintf(arquivo, "%s - %d - %s - %d - [ %f | %f | %f ] - %s",
        aluno.nome, aluno.idade, aluno.sala, aluno.presenca, 
        aluno.nota_1, aluno.nota_2, aluno.nota_3, aluno.situacao); // Escreve o aluno no arquivo

    fclose(arquivo);
}

/*
    cadastrarAluno

    Função para cadastrar aluno.
    Irá pedir os dados do aluno e armazenar em uma variável do tipo Aluno.
    ---
    Desde: 03/11/2025
    Autor: Nicolas - Arthur
    Versão: 1.0
*/
void cadastrarAluno(){
    limparTela();
    Aluno novoAluno;

    printf("------Cadastro de Aluno------\n\n");
    printf("Digite o nome do aluno: ");
    fgets(novoAluno.nome, sizeof(novoAluno.nome), stdin);

    printf("\nDigite a idade do aluno: ");
    scanf("%d", &novoAluno.idade);
    getchar();

    printf("\nDigite a sala do aluno: ");
    fgets(novoAluno.sala, sizeof(novoAluno.sala), stdin);

    printf("\nDigite a presença do aluno (em porcentagem e apenas o numero): ");
    scanf("%d", &novoAluno.presenca);
    getchar();

    novoAluno.nota_1 = pegarNota(1);
    novoAluno.nota_2 = pegarNota(2);
    novoAluno.nota_3 = pegarNota(3);

    //strcpy(novoAluno.situacao, calcularMedia(novoAluno.nota_1, novoAluno.nota_2, novoAluno.nota_3));
    calcularMedia(novoAluno.presenca, novoAluno.nota_1, novoAluno.nota_2, novoAluno.nota_3);
    armazenarAluno(novoAluno);
    printf("\nAluno %s cadastrado com sucesso!\n", novoAluno.nome);
}

void listarAlunos(){
    printf("------Lista de Alunos------\n\n");
    printf("Funcionalidade em desenvolvimento...\n");
}

/*
    main

    Função principal para pegar funcionalidade desejada.
    Menu com as opções cadastrar e listar alunos.
    ---
    Desde: 03/11/2025
    Autor: Nicolas - Arthur
    Versão: 1.0
*/
int main() {
    printf("------Bem-Vindo(a) ao Gestão Escolar Virtual------\n\n");

    while(true){
        limparTela();

        int opcao;
        
        printf("Escolha uma das opções abaixo:\n");
        printf("1 - Cadastrar Aluno e nota\n");
        printf("2 - Listar Alunos\n");
        printf("3 - Sair\n");
        
        scanf("%d", &opcao);
        getchar();
        switch(opcao) {
            case 1:
                cadastrarAluno();
                continue;
            case 2:
                listarAlunos();
                continue;
            case 3:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
        
        break;
    }

    return 0;
}