#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct{
    char login[30];
    char password[30];
} person; person p[1];

char name[SIZE][50];
char email[SIZE][50];
char sex[SIZE];
long long int cpf[SIZE];
int age[SIZE];
int option;

void patientRecord();
void searchPatient();
void menuChooseUnity();
void listPatient();
void deletePatient();

int main(void){
    login();
}

int login(){
    system("cls");
    system("color 2");

    char login[30]; // armazenar o login inserida pelo usuário
    char password[30]; // armazenar a senha inserida pelo usuário
    printf("\n----CLINICA MEDICA----\n\n");
    strcpy(p[0].login, "Clinica"); // Definindo o login "clinica" na struct
    strcpy(p[0].password, "123"); // Definindo a senha "123"  na struct

    printf("\nlogin:");
    scanf("%s", login); // armazenando os dados inseridos pelo usuário para o vetor login que está dentro da função main

    printf("\nsenha:");
    scanf("%s", password); // armazenando os dados inseridos pelo usuário para o vetor senha que está dentro da função main

    if ((strcmp(login,p[0].login)==0) && (strcmp(password,p[0].password)==0)){ // A função strcmp é responsável por comparar string com string
        printf("\nUsuario logado \n"); // se os vetores de dentro da struct tiver os mesmos dados do vetor interno da função main, usuário será logado.
        menuChooseUnity();
    }else{
        printf("Login e/ou senha incorretos\n"); // senão, login ou senha incorreta.
        
    }
    return 0;
}

void menuChooseUnity(){
    char santo_amaro[] = "\n----UNIDADE SANTO AMARO----\n";
    char moema[] = "\n----UNIDADE MOEMA----\n";
    char chacara[] = "\n----UNIDADE CHACARAA----\n";
    system("cls");
    printf("\n----ESCOLHA UMA UNIDADE----\n");
    printf("\n1- Unidade Santo Amaro \n");
    printf("\n2- Unidade Moema \n");
    printf("\n3- Unidade Chacara \n");
    printf("\n\nDigite a unidade desejada: ");
    scanf("%d", &option); 
    if(option==1)
    { 
        menu(option, santo_amaro);
    }
    if(option==2)
    { 
        menu(option, moema);
    }
    if(option==3)
    { 
        menu(option, chacara);
    }
}

void menu(int numberUnidade, char unidade[]){
    system("cls");
    printf(unidade);
    printf("\n\nDIGITE O NUMERO REFERENTE A OPCAO DESEJADA: \n");
    printf("\nCadastrar Cliente(1) \nPesquisar(2) \nExibir Lista de Clientes(3) \nDeletar Cadastro de Cliente(4)\n\n \nMenu Geral(8) \nSair(9)\nInsira a opção desejada: ");
    scanf("%d", &option);
    if(option==1)
    { 
        patientRecord(numberUnidade, unidade);
    }
    if(option==2)
    {
        searchPatient(numberUnidade, unidade);
    }
    if(option==3)
    {
        listPatient(numberUnidade, unidade);
    }
    if(option==4)
    {
        deletePatient(numberUnidade, unidade);
    }
    if(option==9)
    {
        exit(0);
    }
    if (option==8)
    {
        menuChooseUnity();
        system("cls");
    }
    exit(0);
}

void insertNewNumberOfPatients(char fileNumberPatients[], int counter) {
    int resultado;

    FILE* fileNumberOfPatients;
    
    fileNumberOfPatients = fopen(fileNumberPatients, "r");
    fscanf(fileNumberOfPatients, "%d", &counter);
    fclose(fileNumberOfPatients);

    resultado = counter + 1;

    fileNumberOfPatients = fopen(fileNumberPatients, "w");
    fprintf(fileNumberOfPatients, "%d", resultado);
    fclose(fileNumberOfPatients);
}

void patientRecord(int numberUnidade, char unidade[]){
    system("cls");
    static int indice;
    int counter;

    do{
        printf("---- Cadastrando Paciente----\n");
        printf("\nDigite o nome do paciente: ");
        scanf("%s", &name[indice]);
        printf("\nDigite o e-mail do paciente: ");
        scanf("%s", &email[indice]);
        printf("\nDigite a idade do paciente: ");
        scanf("%d", &age[indice]);
        printf("\nDigite o CPF do paciente: ");
        scanf("%lld", &cpf[indice]);
        printf("\nDigite o gênero do paciente [F ou M]: ");
        scanf("%s", &sex[indice]);

        FILE* filePatients;
        switch (numberUnidade)
        {
            case 1:
                filePatients = fopen("PatientsSantoAmaro.txt", "a");
                insertNewNumberOfPatients("NumberOfPatientsSantoAmaro.txt", counter);
                break;
            case 2:
                filePatients = fopen("PatientsMoema.txt", "a");
                insertNewNumberOfPatients("NumberOfPatientsMoema.txt", counter);
                break;
            case 3:
                filePatients = fopen("PatientsChacara.txt", "a");
                insertNewNumberOfPatients("NumberOfPatientsChacara.txt", counter);
                break;
        }
        fprintf(filePatients, "%s %s %d %lld %s\n", &name[indice], &email[indice], age[indice], cpf[indice], &sex[indice]);
        fclose(filePatients);

        printf("\nDigite 1 para continuar cadastrando, 8 para voltar ao menu ou 9 para sair: ");
        scanf("%d", &option);
        indice++;
        if(option==8){
            menu(numberUnidade, unidade);
        }
        if(option==9){
            exit(0);
        }
    }while(option==1);
}

void searchPatient(int numberUnidade, char unidade[]){
    system("cls");
    long long int searchCPF;
    int counterpesquisa;
    static int i;
    static int indice;

    FILE* filePatients;
    FILE* fileNumberPatients;
    switch (numberUnidade)
        {
            case 1:
                filePatients = fopen("PatientsSantoAmaro.txt", "r");
                fileNumberPatients = fopen("NumberOfPatientsSantoAmaro.txt", "r");
                break;
            case 2:
                filePatients = fopen("PatientsMoema.txt", "a");
                fileNumberPatients = fopen("NumberOfPatientsMoema.txt", "r");
                break;
            case 3:
                filePatients = fopen("PatientsChacara.txt", "a");
                fileNumberPatients = fopen("NumberOfPatientsChacara.txt", "r");
                break;
        }

    fscanf(fileNumberPatients, "%d", &counterpesquisa);
    fclose(fileNumberPatients);

    printf("\nDigite o CPF: ");
    scanf("%lld", &searchCPF);

    if (counterpesquisa == 0) {
        printf("Nenhum Paciente Cadastrado ate o momento");
    }

    for(i = 0; i <= counterpesquisa; i++)
    {
        fscanf(filePatients, "%s %s %d %lld %s", &name[indice], &email[indice], &age[indice], &cpf[indice], &sex[indice]);

        if(searchCPF == cpf[indice])
        {
            printf("\nNome: %s \nE-mail: %s \nIdade: %d \nCPF: %lld \nGênero: %s\n", &name[indice], &email[indice], age[indice], cpf[indice], &sex[indice]);
        }
    }

    fclose(filePatients);

    printf("\nDigite 1 para continuar pesquisando, 8 para voltar ao menu ou 9 para sair: ");
    scanf("%d", &option);
    if(option==1)
    {
        searchPatient(numberUnidade, unidade);
    }
    if(option==8 || option!=8,9)
    {
        menu(numberUnidade, unidade);
    }
    if(option==9)
    {
        exit(0);
    }
}

void listPatient(int numberUnidade, char unidade[]){
    system("cls");
    static int indice;
    int i;
    int counter;

    FILE* filePatients;
    FILE* fileNumberPatients;
    switch (numberUnidade)
    {
        case 1:
            filePatients = fopen("PatientsSantoAmaro.txt", "r");
            fileNumberPatients = fopen("NumberOfPatientsSantoAmaro.txt", "r");
            break;
        case 2:
            filePatients = fopen("PatientsMoema.txt", "a");
            fileNumberPatients = fopen("NumberOfPatientsMoema.txt", "r");
            break;
        case 3:
            filePatients = fopen("PatientsChacara.txt", "a");
            fileNumberPatients = fopen("NumberOfPatientsChacara.txt", "r");
            break;
    }

    fscanf(fileNumberPatients, "%d", &counter);
    fclose(fileNumberPatients);

    printf("\n----Lista de Pacientes Cadastrados----\n");
    for(i = 0; i < counter; i++){
        fscanf(filePatients, "%s %s %d %lld %s \n", &name[indice], &email[indice], &age[indice], &cpf[indice], &sex[indice]);
        printf("\nNome: %s \nE-mail: %s \nIdade: %d \nCPF: %lld \nGênero: %s\n", &name[indice], &email[indice], age[indice], cpf[indice], &sex[indice]);
        indice++;
    }
    fclose(filePatients);

    printf("\nDigite 8 para voltar ao Menu ou 9 para Sair: ");
    scanf("%d", &option);
    if(option==8){
        menu(numberUnidade, unidade);
    }
    if(option==9){
        exit(0);
    }
    if(option!=8,9)
    {
        menu(numberUnidade, unidade);
    }
    exit(0);
}

void deletePatient(int numberUnidade, char unidade[]){
    long long int cfp_for_delete;
    int counter;
    static int indice;

    printf("\nDigite o CPF do cliente: ");
    scanf("%lld", &cfp_for_delete);

    FILE* filePatients;
    FILE* fileNumberPatients;
    switch (numberUnidade)
    {
        case 1:
            filePatients = fopen("PatientsSantoAmaro.txt", "r");
            fileNumberPatients = fopen("NumberOfPatientsSantoAmaro.txt", "r");
            break;
        case 2:
            filePatients = fopen("PatientsMoema.txt", "a");
            fileNumberPatients = fopen("NumberOfPatientsMoema.txt", "r");
            break;
        case 3:
            filePatients = fopen("PatientsChacara.txt", "a");
            fileNumberPatients = fopen("NumberOfPatientsChacara.txt", "r");
            break;
    }

    fscanf(fileNumberPatients, "%d", &counter);
    fclose(fileNumberPatients);

    for(int i = 0; i < counter; i++)
    {
        fscanf(filePatients, "%s %s %d %lld %s", &name[indice], &email[indice], &age[indice], &cpf[indice], &sex[indice]);

        if(cfp_for_delete == cpf[indice])
        {
            fclose(filePatients);

            printf("\nDados de %s\n", &name[indice]);
            printf("\nNome: %s \nEmail: %s \nIdade: %d \nCPF: %lld \nGenêro: %s\n", &name[indice], &email[indice], age[indice], cpf[indice], &sex[indice]);

            printf("\nDeseja deletar o cadastro de %s? Digite 1 para SIM e 2 para NÃO: ", &name[indice]);
            scanf("%d", &option);

            if(option==1)
            {
                FILE* filenew = fopen("new.txt", "a");

                switch (numberUnidade)
                {
                    case 1:
                        filePatients = fopen("PatientsSantoAmaro.txt", "r");
                        fileNumberPatients = fopen("NumberOfPatientsSantoAmaro.txt", "r");
                        break;
                    case 2:
                        filePatients = fopen("PatientsMoema.txt", "a");
                        fileNumberPatients = fopen("NumberOfPatientsMoema.txt", "r");
                        break;
                    case 3:
                        filePatients = fopen("PatientsChacara.txt", "a");
                        fileNumberPatients = fopen("NumberOfPatientsChacara.txt", "r");
                        break;
                }

                fscanf(fileNumberPatients, "%d", &counter);
                fclose(fileNumberPatients);

                switch (numberUnidade)
                {
                    case 1:
                        fileNumberPatients = fopen("NumberOfPatientsSantoAmaro.txt", "r");
                        break;
                    case 2:
                        fileNumberPatients = fopen("NumberOfPatientsMoema.txt", "r");
                        break;
                    case 3:
                        fileNumberPatients = fopen("NumberOfPatientsChacara.txt", "r");
                        break;
                }

                fprintf(fileNumberPatients, "%d", counter - 1);
                fclose(fileNumberPatients);

                for(int i = 0; i < counter; i++)
                {
                    fscanf(filePatients, "%s %s %d %lld %s", &name[indice], &email[indice], &age[indice], &cpf[indice], &sex[indice]);

                    if(cpf[indice] != cfp_for_delete)
                    {
                        fprintf(filenew, "%s %s %d %lld %s\n", &name[indice], &email[indice], &age[indice], &cpf[indice], &sex[indice]);
                    }
                }

                fclose(filePatients);
                fclose(filenew);

                switch (numberUnidade)
                {
                    case 1:
                        remove("PatientsSantoAmaro.txt");
                        rename("new.txt", "PatientsSantoAmaro.txt");
                        break;
                    case 2:
                        remove("PatientsMoema.txt");
                        rename("new.txt", "PatientsMoema.txt");
                        break;
                    case 3:
                        remove("PatientsChacara.txt");
                        rename("new.txt", "PatientsChacara.txt");
                        break;
                }

                printf("\nDigite 8 para retornar ao menu ou 9 para sair: ");
                scanf("%d", &option);
                if(option==8 || option!=8,9)
                {
                    menu(numberUnidade, unidade);
                }
                if(option==9)
                {
                    exit(0);
                }
            } 
            if(option!=1)
            {
                menu(numberUnidade, unidade);
            }    
        }
        indice++;
    }
    fclose(filePatients);  
    menu(numberUnidade, unidade);  
}