/* Projeto: Controle de Clínica Veterinária
    Desenvolvido por:
    . Clara Joaquim Plantier Marques
    . Yann Pereira Garcia
    FEMA - Maio de 2025
*/

#include <iostream>
#include <clocale>
#include <conio.h>
#include <thread>
#include <vector>
#include <regex>
#define Y 10

using namespace std;

// Definição das Structs

struct cidade {
    int codigo;
    string nome;
    char uf[3];
};

struct raca {
    int codigo;
    string descricao;
};

struct animal {
    int codigo;
    string nome;
    int codigoRaca;
    int idade;
    float peso;
    int codigoTutor;
};

struct tutor {
    int codigo;
    string nome;
    string cpf;
    string endereco;
    int codigoCidade;
};

struct veterinario {
    int codigo;
    string nome;
    string endereco;
    int codigoCidade;
};

struct consulta {
    int codigo;
    int codigoAnimal;
    int codigoVeterinario;
    time_t dataConsulta;
    float valorConsulta;
};

// Função para exibir o texto inicial

void textoInicial();

// Funções para leitura das tabelas

void leituraCidades(struct cidade cidades[], int &contCidadeS);

void leituraRacas(struct raca r[], int &contRacaS);

void leituraAnimais(struct animal a[], int &contAnimalS,
                    struct raca r[], int &contRacaS,
                    struct tutor t[], int &contTutorS,
                    struct cidade c[], int &contCidadeS);

void leituraTutores(struct tutor t[], int &contTutorS,
                    struct cidade c[], int &contCidadeS);

void leituraVeterinarios(struct veterinario v[], int &contVeterinarioS,
                         struct cidade c[], int &contCidadeS);

void leituraConsultas(struct consulta cons[], int &contConsultaS,
                      struct animal a[], int &contAnimalS,
                      struct veterinario v[], int &contVeterinarioS,
                      struct raca r[], int &contRacaS,
                      struct cidade c[], int &contCidadeS,
                      struct tutor t[], int &contTutoreS);

// Funções para impressão das tabelas

void impressaoCidades(struct cidade c[], int contCidadeS);

void impressaoRacas(struct raca r[], int contRacaS);

void impressaoAnimais(struct animal a[], int &contAnimalS,
                    struct raca r[], int &contRacaS,
                    struct tutor t[], int &contTutorS,
                    struct cidade c[], int &contCidadeS);

void impressaoTutores(struct tutor t[], int contTutorS, struct cidade c[], int contCidadeS);

void impressaoVeterinarios(struct veterinario v[], int contVeterinarioS, struct cidade c[], int contCidadeS);

void impressaoConsultas(struct consulta cons[], int &contConsultaS,
                      struct animal a[], int &contAnimalS,
                      struct veterinario v[], int &contVeterinarioS,
                      struct raca r[], int &contRacaS,
                      struct cidade c[], int &contCidadeS,
                      struct tutor t[], int &contTutoreS);

// Funções para verificar se o código (pk) já existe

bool codigoCidadeExiste(struct cidade c[], int contCidadeS, int cod);

bool codigoRacaExiste(struct raca r[], int contRacaS, int cod);

bool codigoTutorExiste(struct tutor t[], int contTutorS, int cod);

bool codigoAnimalExiste(struct animal a[], int contAnimalS, int cod);

bool codigoVeterinarioExiste(struct veterinario v[], int contVeterinarioS, int cod);

bool codigoConsultaExiste(struct consulta cons[], int contConsultaS, int cod);

// Funções de Busca Binária

void buscaBinariaCidade(struct cidade c[], int contCidadeS, int cod);

void buscaBinariaRaca(struct raca r[], int contRacaS, int cod);

int buscaBinariaTutor(struct tutor t[], int contTutorS, int codTutor);

void buscaBinariaAnimal(struct animal a[], int contAnimalS, int codAnimal, int &codRaca, int &codTutor);

int buscaBinariaVeterinario(struct veterinario v[], int contVeterinarioS, int codVeterinario);

// Funções para validar o cpf

string limparCPF(const string& cpf);

string formatarCPF(const string& cpfEntrada);

bool validarCPF(const string& cpfEntrada);

bool cpfExiste(struct tutor t[], int contTutorS, string cpf);

// Funções do menu

char menu();

void inserir(struct cidade cidades[], int &contCidadeS, struct raca racas[], int &contRacaS,
             struct animal animais[], int &contAnimalS, struct tutor tutores[], int &contTutorS,
             struct veterinario veterinarios[], int &contVeterinarioS, struct consulta consultas[],
             int &contConsultaS);

void imprimir(struct cidade cidades[], int &contCidadeS,
              struct raca racas[], int &contRacaS,
              struct animal animalS[], int &contAnimalS,
              struct tutor tutoresS[], int &contTutorS,
              struct veterinario veterinarios[], int &contVeterinarioS,
              struct consulta consultas[], int &contConsultaS,
              int &contConsultaDataVerificadas);

void incluir(struct animal animais[], int &contAnimalS, struct animal animaisT[], int contAnimalT,
             struct animal animaisA[], int &contAnimalA, struct tutor tutores[], int &contTutorS,
             struct tutor tutoresT[], int contTutorT, struct tutor tutoresA[], int &contTutorA,
             struct cidade cidades[], int &contCidadeS, struct raca racas[], int &contRacaS);

char sair();

// Funções de Inclusão

void inclusaoTutor (struct tutor S[], int &contS, struct tutor T[], int contT, struct tutor A[], int &contA);

void inclusaoAnimal (struct animal S[], int &contS, struct animal T[], int contT, struct animal A[], int &contA);

// Validação de Data

// Validação de Data
void verificarData(std::string &dia);
bool diaValido(int dd, int mm, int yy);
time_t converterParaTimeT(std::string diaParaSerConvertido);

// Impressão
void imprimirBuscaPorConsultasEntreDatas(struct consulta consultaVerificada[], int &contConsultaDataVerificadas);

// Verificação entre datas (com e sem filtro por veterinário)
void verificarEntreDatas(struct consulta consulta[],
                         struct consulta consultaVerificada[],
                         int &contConsultaS,
                         time_t dataInicial,
                         time_t dataFinal,
                         int &contConsultaDataVerificadas,
                         struct animal a[], int &contAnimalS,
                         struct veterinario v[], int &contVeterinarioS,
                         struct raca r[], int &contRacaS,
                         struct cidade c[], int &contCidadeS,
                         struct tutor t[], int &contTutoreS);

void verificarEntreDatasEVeterinario(struct consulta consulta[],
                                     struct consulta consultaVerificada[],
                                     int &contConsultaS,
                                     time_t dataInicial,
                                     time_t dataFinal,
                                     int &contConsultaDataVerificadas,
                                     int codigoVet,
                                     struct animal a[], int &contAnimalS,
                                     struct veterinario v[], int &contVeterinarioS,
                                     struct raca r[], int &contRacaS,
                                     struct cidade c[], int &contCidadeS,
                                     struct tutor t[], int &contTutoreS);

// Busca de consultas entre datas
void buscarConsultaEntreDatas(struct consulta consulta[],
                               struct consulta consultaA[],
                               int &contConsultaS,
                               int &contConsultaDataVerificadas,
                               struct animal a[], int &contAnimalS,
                               struct veterinario v[], int &contVeterinarioS,
                               struct raca r[], int &contRacaS,
                               struct cidade c[], int &contCidadeS,
                               struct tutor t[], int &contTutoreS);

void buscarConsultaEntreDatasEVeterinario(struct consulta consulta[],
                                          struct consulta consultaA[],
                                          int &contConsultaS,
                                          int &contConsultaDataVerificadas,
                                          struct animal a[], int &contAnimalS,
                                          struct veterinario v[], int &contVeterinarioS,
                                          struct raca r[], int &contRacaS,
                                          struct cidade c[], int &contCidadeS,
                                          struct tutor t[], int &contTutoreS);


int main() {

    //Definir linguagem do programa
    setlocale(LC_ALL, "Portuguese");

    textoInicial();

    // Definição dos vetores

    cidade cidades[Y];
    raca racas[Y];
    animal animais[Y];
    animal animaisT[Y];
    animal animaisA[20];
    tutor tutores[Y];
    tutor tutoresT[Y];
    tutor tutoresA[20];
    veterinario veterinarios[Y];
    consulta consultas[Y];

    //Definição dos Contadores

    int contCidadeS = 0;
    int contRacaS = 0;
    int contAnimalS = 0, contAnimalT, contAnimalA;
    int contTutorS = 0, contTutorT, contTutorA;
    int contVeterinarioS = 0;
    int contConsultaS = 0, contConsultaDataVerificadas = 0;


    // Tutores
    tutores[0] = {1, "João Silva", "12345678909", "Rua A", 1};
    tutores[1] = {2, "Maria Oliveira", "98765432100", "Rua B", 2};
    contTutorS = 2;

    // Animais
    animais[0] = {1, "Rex", 1, 3, 20.5, 1};
    animais[1] = {2, "Mimi", 2, 2, 4.2, 2};
    contAnimalS = 2;

    // Veterinários
    veterinarios[0] = {1, "Dr. Carlos", "Av. Vet", 1};
    veterinarios[1] = {2, "Dra. Ana", "Rua Vet", 2};
    contVeterinarioS = 2;

    // Consultas
    consultas[0] = {1, 1, 1, converterParaTimeT("01/01/2022"), 150.00f};
    consultas[1] = {2, 2, 2, converterParaTimeT("05/01/2023"), 200.00f};
    consultas[2] = {2, 2, 2, converterParaTimeT("05/01/2024"), 200.00f};
    consultas[3] = {2, 2, 2, converterParaTimeT("05/01/2024"), 200.00f};
    consultas[4] = {2, 2, 2, converterParaTimeT("05/01/2025"), 200.00f};
    consultas[5] = {2, 2, 2, converterParaTimeT("05/01/2026"), 200.00f};
    contConsultaS = 6;

    //Menu

    char opcao = 'N';
    while (opcao != 'S' || opcao == 's') {
        opcao = menu();
        switch (opcao) {
            case '1': {
                inserir(cidades, contCidadeS, racas, contRacaS, animais, contAnimalS, tutores, contTutorS,
                        veterinarios, contVeterinarioS, consultas, contConsultaS);
                break;
            }
            case '2': {
                incluir(animais, contAnimalS, animaisT, contAnimalT, animaisA, contAnimalA, tutores, contTutorS,
    tutoresT, contTutorT, tutoresA, contTutorA, cidades, contCidadeS, racas, contRacaS);
                break;
            }
            case '3' : {
                imprimir(cidades, contCidadeS,
                         racas, contRacaS,
                         animais, contAnimalS,
                         tutores, contTutorS,
                         veterinarios, contVeterinarioS,
                         consultas, contConsultaS,
                         contConsultaDataVerificadas);
                break;
            }
            case '4': {
                opcao = sair();
                break;
            }
            default: {
                cout << "\n\nOpcao invalida. Tecle algo para continuar...";
                getch();
            }
        }
    }
}

//Funções do Menu

char menu() {
    char opcao;
    // system("cls");
    cout << "\n\t\tOpções:\n\n";
    cout << "\t\t\t1 - Inserir dados\n\n";
    cout << "\t\t\t2 - Incluir Novos Dados\n\n";
    cout << "\t\t\t3 - Imprimir dados\n\n";
    cout << "\t\t\t4 - Sair do programa\n\n";
    cout << "\t\tEscolha a Opção: ";
    cin >> opcao;

    return opcao;
}

void inserir(struct cidade cidades[], int &contCidadeS, struct raca racas[], int &contRacaS,
             struct animal animais[], int &contAnimalS, struct tutor tutores[], int &contTutorS,
             struct veterinario veterinarios[], int &contVeterinarioS, struct consulta consultas[],
             int &contConsultaS) {
    char conf;

    char opcao;
    bool loop = true;

    while (loop) {
        // system("cls");
        cout << "\n\tDeseja Realizar a Leitura de qual lista?\n\n";
        cout << "\n\t1 - Cidade" << endl;
        cout << "\n\t2 - Raça" << endl;
        cout << "\n\t3 - Tutor" << endl;
        cout << "\n\t4 - Animal" << endl;
        cout << "\n\t5 - Veterinario" << endl;
        cout << "\n\t6 - Consulta" << endl;
        cout << "\n\t7 - Voltar ao menu Principal" << endl;
        cout << "\n\t8 - Sair" << endl;
        cout << "\n\tEscolha a opcao: ";
        cin >> opcao;

        if (opcao == '8') {
            opcao = sair();
            loop = false;
        } else {
            cout << "\n\t. Confirma a operação? (S/N): ";
            cin >> conf;
        }

        if (conf == 'S' || conf == 's') {
            switch (opcao) {
                case '1': {
                    if (contCidadeS == 0) {
                        leituraCidades(cidades, contCidadeS);
                    } else {
                        cout << "\n\tA tabela de cidades já foi preenchida!\n";
                        impressaoCidades(cidades, contCidadeS);
                    }
                    break;
                }
                case '2': {
                    if (contRacaS == 0) {
                        leituraRacas(racas, contRacaS);
                    } else {
                        cout << "\n\tA tabela de raças já foi preenchida!\n";
                        impressaoRacas(racas, contRacaS);
                    }
                    break;
                }
                case '3': {
                    if (contTutorS == 0) {
                        leituraTutores(tutores, contTutorS, cidades, contCidadeS);
                    } else {
                        cout << "\n\tA tabela de tutores já foi preenchida!\n";
                        impressaoTutores(tutores, contTutorS, cidades, contCidadeS);
                    }
                    break;
                }
                case '4': {
                    if (contAnimalS == 0) {
                        leituraAnimais(animais, contAnimalS, racas, contRacaS, tutores, contTutorS, cidades,
                                       contCidadeS);
                    } else {
                        cout << "\n\tA tabela de animais já foi preenchida!\n";
                        impressaoAnimais(animais, contAnimalS, racas, contRacaS, tutores, contTutorS, cidades, contCidadeS);
                    }
                    break;
                }
                case '5': {
                    if (contVeterinarioS == 0) {
                        leituraVeterinarios(veterinarios, contVeterinarioS, cidades, contCidadeS);
                    } else {
                        cout << "\n\tA tabela de veterinários já foi preenchida!\n";
                        impressaoVeterinarios(veterinarios, contVeterinarioS, cidades, contCidadeS);
                    }
                    break;
                }
                case '6': {
                    if (contConsultaS == 0) {
                        leituraConsultas(consultas, contConsultaS, animais, contAnimalS, veterinarios, contVeterinarioS,
                                         racas, contRacaS, cidades, contCidadeS, tutores, contTutorS);
                    } else {
                        cout << "\n\tA tabela de consultas já foi preenchida!\n";
                        impressaoConsultas(consultas, contConsultaS, animais, contAnimalS, veterinarios, contVeterinarioS, racas, contRacaS, cidades, contCidadeS, tutores, contTutorS);
                    }
                    break;
                }
                case '7': {
                    loop = false;
                    break;
                }
                default: {
                    cout << "\n\nOpcao invalida. Tecle algo para continuar...";
                    getch();
                }
            }
        } else {
            cout << "\n\nOperação cancelada! Voltando para o menu de inserir dados...";
            getch();
        }
    }
}

void incluir(struct animal animais[], int &contAnimalS, struct animal animaisT[], int contAnimalT,
             struct animal animaisA[], int &contAnimalA, struct tutor tutores[], int &contTutorS,
             struct tutor tutoresT[], int contTutorT, struct tutor tutoresA[], int &contTutorA,
             struct cidade cidades[], int &contCidadeS, struct raca racas[], int &contRacaS) {
    char conf;

    char opcao;
    bool loop = true;

    while (loop) {
        // system("cls");
        cout << "\n\tDeseja Realizar a Inclusão de qual lista?\n\n";
        cout << "\n\t1 - Tutor" << endl;
        cout << "\n\t2 - Animal" << endl;
        cout << "\n\t3 - Voltar ao menu Principal" << endl;
        cout << "\n\t4 - Sair" << endl;
        cout << "\n\tEscolha a opcao: ";
        cin >> opcao;

        if (opcao == '4') {
            opcao = sair();
            loop = false;
        } else {
            cout << "\n\t. Confirma a operação? (S/N): ";
            cin >> conf;
        }

        if (conf == 'S' || conf == 's') {
            switch (opcao) {

                case '1': {
                    if (contTutorS == 0) {
                        cout << "\n\tA tabela de tutores ainda não foi preenchida!\n\tVocê será direcionado para o cadastro da tabela de Tutores!\n";
                        leituraTutores(tutores, contTutorS, cidades, contCidadeS);
                        cout << "\n\tTabela de tutores foi preenchida!\n\tPor favor preencha a lista com as novas inclusões\n";
                        leituraTutores(tutoresT, contTutorT, cidades, contCidadeS);
                        inclusaoTutor(tutores, contTutorS, tutoresT, contTutorT, tutoresA, contTutorA);
                    } else {
                        cout << "\n\tPreencha a tabela com os novos registros de tutores\n";
                        leituraTutores(tutoresT, contTutorT, cidades, contCidadeS);
                        inclusaoTutor(tutores, contTutorS, tutoresT, contTutorT, tutoresA, contTutorA);
                    }
                    break;
                }
                case '2': {
                    if (contAnimalS == 0) {
                        cout << "\n\tA tabela de animais ainda não foi preenchida!\n\tVocê será direcionado para a leitura da tabela de Animais!\n";
                        leituraAnimais(animais, contAnimalS, racas, contRacaS, tutores, contTutorS, cidades, contCidadeS);
                        cout << "\n\tTabela de animais foi preenchida!\n\tPor favor preencha a lista com as novas inclusões\n";
                        leituraAnimais(animaisT, contAnimalT, racas, contRacaS, tutores, contTutorS, cidades, contCidadeS);
                        inclusaoAnimal(animais, contAnimalS, animaisT, contAnimalT, animaisA, contAnimalA);
                    } else {
                        cout << "\n\tPreencha a tabela com os novos registros de animais\n";
                        leituraAnimais(animaisT, contAnimalT, racas, contRacaS, tutores, contTutorS, cidades, contCidadeS);
                        inclusaoAnimal(animais, contAnimalS, animaisT, contAnimalT, animaisA, contAnimalA);
                    }

                    break;
                }
                case '3': {
                    loop = false;
                    break;
                }
                default: {
                    cout << "\n\nOpcao invalida. Tecle algo para continuar...";
                    getch();
                }
            }
        } else {
            cout << "\n\nOperação cancelada! Voltando para o menu de inserir dados...";
            getch();
        }
    }
}

void imprimir(struct cidade cidades[], int &contCidadeS,
              struct raca racas[], int &contRacaS,
              struct animal animalS[], int &contAnimalS,
              struct tutor tutoresS[], int &contTutorS,
              struct veterinario veterinarios[], int &contVeterinarioS,
              struct consulta consultas[], int &contConsultaS,
              int &contConsultaDataVerificadas) {
    char conf;

    char opcao;
    bool loop = true;

    while (loop) {
        // system("cls");
        cout << "\n\tDeseja Realizar a Impressão de qual lista?\n\n";
        cout << "\n\t1 - Cidade" << endl;
        cout << "\n\t2 - Raça" << endl;
        cout << "\n\t3 - Tutor" << endl;
        cout << "\n\t4 - Animal" << endl;
        cout << "\n\t5 - Veterinario" << endl;
        cout << "\n\t6 - Consulta" << endl;
        cout << "\n\t7 - Consultar por datas" << endl;
        cout << "\n\t8 - Consultar por datas e veterinário" << endl;
        cout << "\n\t9 - Voltar ao menu Principal" << endl;
        cout << "\n\t10 - Sair" << endl;
        cout << "\n\tEscolha a opcao: ";
        cin >> opcao;

        if (opcao == 10) {
            opcao = sair();
            loop = false;
        } else {
            cout << "\n\t. Confirma a operação? (S/N): ";
            cin >> conf;
        }

        if (conf == 'S' || conf == 's') {
            switch (opcao) {
                case '1': {
                    if (contCidadeS != 0) {
                        cout << contCidadeS;
                        impressaoCidades(cidades, contCidadeS);
                    } else {
                        cout <<"\n====================================================================================="<< endl;
                        cout << "\n\tA leitura das cidades ainda não foi realizada!\n\tPor favor realize a leitura das cidades primeiro!\n";
                        cout <<"\n====================================================================================="<< endl;
                    }
                    break;
                }
                case '2': {
                    if (contRacaS != 0) {
                        impressaoRacas(racas, contRacaS);
                    } else {
                        cout <<"\n====================================================================================="<< endl;
                        cout << "\n\tA leitura das raças ainda não foi realizada!\n\tPor favor realize a leitura das raças primeiro!\n";
                        cout <<"\n====================================================================================="<< endl;
                    }
                    break;
                }
                case '3': {
                    if (contTutorS != 0) {
                         impressaoTutores(tutoresS, contTutorS, cidades, contCidadeS);
                    } else {
                        cout <<"\n====================================================================================="<< endl;
                        cout << "\n\tA leitura de tutores ainda não foi realizada!\n\tPor favor realize a leitura dos tutores primeiro!\n";
                        cout <<"\n====================================================================================="<< endl;
                    }
                    break;
                }
                case '4': {
                    if (contAnimalS != 0) {
                        impressaoAnimais(animalS, contAnimalS, racas, contRacaS, tutoresS, contTutorS, cidades, contCidadeS);
                    } else {
                        cout <<"\n====================================================================================="<< endl;
                        cout << "\n\tA leitura de animais ainda não foi realizada!\n\tPor favor realize a leitura dos animais primeiro!\n";
                        cout <<"\n====================================================================================="<< endl;
                    }
                    break;
                }
                case '5': {
                    if (contVeterinarioS != 0) {
                        impressaoVeterinarios(veterinarios, contVeterinarioS, cidades, contCidadeS);
                    } else {
                        cout <<"\n====================================================================================="<< endl;
                        cout << "\n\tA leitura de veterinários ainda não foi realizada!\n\tPor favor realize a leitura dos veterinarios primeiro!\n";
                        cout <<"\n====================================================================================="<< endl;
                    }
                    break;
                }
                case '6': {
                    if (contConsultaS != 0) {
                        impressaoConsultas(consultas, contConsultaS, animalS, contAnimalS, veterinarios, contVeterinarioS, racas, contRacaS, cidades, contCidadeS, tutoresS, contTutorS);
                    } else {
                        cout <<"\n====================================================================================="<< endl;
                        cout << "\n\tA leitura de consultas ainda não foi realizada!\n\tPor favor realize a leitura das consultas primeiro\n";
                        cout <<"\n====================================================================================="<< endl;
                    }
                    break;
                }
                case '7': {
                    if (contConsultaS != 0) {
                        buscarConsultaEntreDatas(consultas, consultas, contConsultaS, contConsultaDataVerificadas,
                          animalS, contAnimalS,
                          veterinarios, contVeterinarioS,
                          racas, contRacaS,
                          cidades, contCidadeS,
                          tutoresS, contTutorS);
                    } else {
                        cout <<"\n====================================================================================="<< endl;
                        cout << "\n\tA leitura de consultas ainda não foi realizada!"<<endl;
                        cout << "\tVocê será redirecionado para a tela de leitura de consultas!"<<endl;
                        leituraConsultas(consultas, contConsultaS, animalS, contAnimalS, veterinarios, contVeterinarioS, racas, contRacaS, cidades, contCidadeS, tutoresS, contTutorS);
                    }
                    break;
                }
                case '8': {
                    if (contConsultaS != 0) {
                        buscarConsultaEntreDatasEVeterinario(consultas, consultas, contConsultaS, contConsultaDataVerificadas,
                          animalS, contAnimalS,
                          veterinarios, contVeterinarioS,
                          racas, contRacaS,
                          cidades, contCidadeS,
                          tutoresS, contTutorS);
                    } else {
                        cout <<"\n====================================================================================="<< endl;
                        cout << "\n\tA leitura de consultas ainda n?o foi realizada!"<<endl;
                        cout << "\tVoc? ser? redirecionado para a tela de leitura de consultas!"<<endl;
                        leituraConsultas(consultas, contConsultaS, animalS, contAnimalS, veterinarios, contVeterinarioS, racas, contRacaS, cidades, contCidadeS, tutoresS, contTutorS);
                    }
                    break;
                }
                case '9': {
                    loop = false;
                    break;
                }
                case 10: {
                    opcao = sair();
                    loop = false;
                }
                default: {
                    cout << "\n\nOpcao invalida. Tecle algo para continuar...";
                    getch();
                }
            }
        } else {
            cout << "\n\nOperação cancelada! Voltando para o menu de inserir dados...";
            getch();
        }
    }
}

char sair() {
    char sair = 'N';
    cout << "\n\nDeseja encerrar o programa? (S/N) : ";
    cin >> sair;
    if (sair == 'S' || sair == 's') {
        cout << "\n\nSaindo do programa...";
        getch();
        // system("cls");
    }
    return sair;
}

//Exercicio 1 (Definir as leituras das tabelas)

void leituraCidades(struct cidade c[], int &contCidadeS) {
    int i = 0;
    for (int saida = 1; i < Y && saida != 0; i++) {
        int cod;
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tDigite as informações da Cidade" << endl;
        cout << "\tCodigo: ";
        cin >> cod;

        if (cod <= 0) {
            saida = 0;
        } else if (codigoCidadeExiste(c, i, cod)) {
            cout << "\tO código " << cod << " já foi inserido, por favor, insira um código válido!";
        } else {
            c[i].codigo = cod;
            if (c[i].codigo > 0) {
                cout << "\tNome: ";
                cin.ignore();
                getline(cin, c[i].nome);
                cout << "\tUnidade Federal [UF]: ";
                cin.getline(c[i].uf, 3);
            }
        }
    }
    contCidadeS = i - 1;
}

void leituraRacas(struct raca r[], int &contRacaS) {
    int i = 0;
    for (int saida = 1; i < Y && saida != 0; i++){
        int cod;
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tDigite as informações da Raça" << endl;
        cout << "\tCodigo: ";
        cin >> cod;

        if (cod <= 0) {
            saida = 0;
        } else if (codigoRacaExiste(r, i, cod)) {
            cout << "\tO código " << cod << " já foi inserido, por favor, insira um código válido!";
        } else {
            r[i].codigo = cod;
            if (r[i].codigo > 0) {
                cout << "\tDescricao: ";
                cin.ignore();
                getline(cin, r[i].descricao);
            }
        }
    }
    contRacaS = i - 1;
}

void leituraTutores(struct tutor t[], int &contTutorS,
                    struct cidade c[], int &contCidadeS) {
    if (contCidadeS == 0) {
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tPara inserir um tutor é necessário informar as cidades primeiro!" << endl;
        cout << "\n\tVocê será redirecionado para a tela de leitura das cidades!" << endl;
        getch();
        leituraCidades(c, contCidadeS);
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tNão há dados cadastrados na tabela tutor";
        cout << "\n\tVocê será redirecionado para a tela de leitura de tutores!\n";
    }

    int i = 0;
    for (int saida = 1; i < Y && saida != 0; i++) {
        int cod;
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tDigite as informações do Tutor" << endl;
        cout << "\tCodigo: ";
        cin >> cod;

        if (cod <= 0) {
            saida = 0;
        } else if (codigoTutorExiste(t, i, cod)) {
            cout << "\tO código " << cod << " já foi inserido, por favor, insira um código válido!\n";
        } else {
            t[i].codigo = cod;
            if (t[i].codigo > 0) {
                cin.ignore();
                cout << "\tNome: ";
                getline(cin, t[i].nome);
                cout << "\tCPF: ";
                getline(cin, t[i].cpf);
                while (!validarCPF(t[i].cpf)) {
                    cout << "\n\tO CPF que você digitou não é válido!\n\tPor favor digite um cpf válido";
                    cout << "\n\tCPF: ";
                    getline(cin, t[i].cpf);
                }
                while (cpfExiste(t, i, t[i].cpf)) {
                    cout << "\n\tEste CPF já existe!\n\tPor favor digite um cpf válido";
                    cout << "\n\tCPF: ";
                    getline(cin, t[i].cpf);
                }
                cout << "\tEndereco: ";
                getline(cin, t[i].endereco);

                int codCidade;
                cout << "\tCodigo da Cidade: ";
                cin >> codCidade;
                while (!codigoCidadeExiste(c, contCidadeS, codCidade)) {
                    cout << "\n\tCódigo Inválido! Por favor digite uma cidade válida!";
                    cout << "\n\tCodigo da Cidade: ";
                    cin >> codCidade;
                }
                t[i].codigoCidade = codCidade;
                buscaBinariaCidade(c, contCidadeS, codCidade);
            }
        }
    }
    contTutorS = i - 1;
}

void leituraAnimais(struct animal a[], int &contAnimalS,
                    struct raca r[], int &contRacaS,
                    struct tutor t[], int &contTutorS,
                    struct cidade c[], int &contCidadeS) {
    if (contRacaS == 0) {
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tPara inserir um animal é necessário informar as raças primeiro!" << endl;
        cout << "\n\tVocê será redirecionado para a tela de leitura das raças!" << endl;
        getch();
        leituraRacas(r, contRacaS);
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tNão há dados cadastrados na tabela animal" << endl;
        cout << "\n\tVocê será redirecionado para a tela de leitura de animais!" << endl;
        getch();
    }
    if (contTutorS == 0) {
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tPara inserir um animal é necessário informar os tutores primeiro!" << endl;
        cout << "\n\tVocê será redirecionado para a tela de leitura dos tutores!" << endl;
        getch();
        leituraTutores(t, contTutorS, c, contCidadeS);
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tNão há dados cadastrados na tabela animal" << endl;
        cout << "\n\tVocê será redirecionado para a tela de leitura de animais!" << endl;
        getch();
    }

    int i = 0;
    for (int saida = 1; i < Y && saida != 0; i++) {
        int cod;
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tDigite as informações do Animal" << endl;
        cout << "\tCodigo: ";
        cin >> cod;

        if (cod <= 0) {
            saida = 0;
        } else if (codigoAnimalExiste(a, i, cod)) {
            cout << "\tO código " << cod << " já foi inserido, por favor, insira um código válido!";
        } else {
            a[i].codigo = cod;
            if (a[i].codigo > 0) {
                cin.ignore();
                cout << "\tNome: ";
                getline(cin, a[i].nome);
                int codRaca;
                cout << "\tCódigo da Raca: ";
                cin >> codRaca;
                while (!codigoRacaExiste(r, contRacaS, codRaca)) {
                    cout << "\n\tCódigo Inválido! Por favor digite um código válido!";
                    cout << "\tCódigo da Raca: ";
                    cin >> codRaca;
                }
                buscaBinariaRaca(r,contRacaS, codRaca);
                a[i].codigoRaca = codRaca;
                cout << "\n\tIdade: ";
                cin >> a[i].idade;
                cout << "\tPeso: ";
                cin >> a[i].peso;
                int codTutor;
                cout << "\tCódigo do Tutor: ";
                cin >> codTutor;
                while (!codigoTutorExiste(t, contTutorS, codTutor)) {
                    cout << "\n\tCódigo Inválido! Por favor digite o código de um tutor válido!";
                    cout << "\n\tCodigo do Tutor: ";
                    cin >> codTutor;
                }
                int codigoCidade = buscaBinariaTutor(t, contTutorS, codTutor);
                buscaBinariaCidade(c, contCidadeS, codigoCidade);
                a[i].codigoTutor = codTutor;
            }
        }
    }
    contAnimalS = i - 1;
}

void leituraVeterinarios(struct veterinario v[], int &contVeterinarioS,
                         struct cidade c[], int &contCidadeS) {
    if (contCidadeS == 0) {
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tPara inserir um veterinario é necessário informar as cidades primeiro!" << endl;
        cout << "\n\tVocê será redirecionado para a tela de leitura das cidades!\n";
        getch();
        leituraCidades(c, contCidadeS);
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tNão há dados cadastrados na tabela veterinarios";
        cout << "\n\tVocê será redirecionado para a tela de leitura de veterinarios!\n";
    }

    int i = 0;
    for (int saida = 1; i < Y && saida != 0; i++) {
        int cod;
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tDigite as informações do Veterinário" << endl;
        cout << "\tCodigo: ";
        cin >> cod;

        if (cod <= 0) {
            saida = 0;
        } else if (codigoVeterinarioExiste(v, i, cod)) {
            cout << "\tO código " << cod << " já foi inserido, por favor, insira um código válido!\n";
        } else {
            v[i].codigo = cod;
            if (v[i].codigo > 0) {
                cin.ignore();
                cout << "\tNome: ";
                getline(cin, v[i].nome);
                cout << "\tEndereço: ";
                getline(cin, v[i].endereco);
                int codCidade;
                cout << "\tCodigo da Cidade: ";
                cin >> codCidade;
                while (!codigoCidadeExiste(c, contCidadeS, codCidade)) {
                    cout << "\n\tCódigo Inválido! Por favor digite uma cidade válida!";
                    cout << "\n\tCodigo da Cidade: ";
                    cin >> codCidade;
                }
                v[i].codigoCidade = codCidade;
                buscaBinariaCidade(c, contCidadeS, codCidade);
            }
        }
    }
    contVeterinarioS = i - 1;
}

void leituraConsultas(struct consulta cons[], int &contConsultaS,
                      struct animal a[], int &contAnimalS,
                      struct veterinario v[], int &contVeterinarioS,
                      struct raca r[], int &contRacaS,
                      struct cidade c[], int &contCidadeS,
                      struct tutor t[], int &contTutoreS) {
    if (contAnimalS == 0) {
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tPara inserir uma consulta é necessário informar os animais primeiro!" << endl;
        cout << "\n\tVocê será redirecionado para a tela de leitura dos animais!\n";
        getch();
        leituraAnimais(a, contAnimalS, r, contRacaS, t, contTutoreS, c, contCidadeS);
    }
    if (contVeterinarioS == 0) {
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tPara inserir uma consulta é necessário informar os veterinários primeiro!" << endl;
        cout << "\n\tVocê será redirecionado para a tela de leitura dos veterinários!\n";
        getch();
        leituraVeterinarios(v, contVeterinarioS, c, contCidadeS);
    }

    char conf;
    int i = 0, codRaca = 0, codTutor = 0, cod =0;

    for (int saida = 1; i < Y && saida != 0; i++) {

        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tDigite as informações da Consulta" << endl;
        cout << "\tCodigo: " << (i + 1) << endl;
        cons[i].codigo = i + 1;
        int codAnimal;
        cout << "\tCódigo do Animal: ";
        cin >> codAnimal;
        while (!codigoAnimalExiste(a, contAnimalS, codAnimal)) {
            cout << "\n\tCódigo Inválido! Por favor digite um animal válido!";
            cout << "\n\tCodigo do Animal: ";
            cin >> codAnimal;
        }
        buscaBinariaAnimal(a, contAnimalS, codAnimal, codRaca, codTutor);
        buscaBinariaRaca(r, contRacaS, codRaca);
        buscaBinariaTutor(t, contTutoreS, codTutor);
        cons[i].codigoAnimal = codAnimal;
        int codVeterinario;
        cout << "\n\tCódigo do Veterinario: ";
        cin >> codVeterinario;
        while (!codigoVeterinarioExiste(v, contVeterinarioS, codVeterinario)) {
            cout << "\n\tCódigo Inválido! Por favor digite um veterinário válido!";
            cout << "\n\tCodigo do Veterinario: ";
            cin >> codVeterinario;
        }
        int codCidade = buscaBinariaVeterinario(v, contVeterinarioS, codVeterinario);
        buscaBinariaCidade(c, contCidadeS, codCidade);
        cons[i].codigoVeterinario = codVeterinario;
        string dia;
        cout << "\n\tData da Consulta (FORMATO dd/MM/yyyy): "<<endl;
        cin >> dia;
        cin.ignore();
        verificarData(dia);
        cons[i].dataConsulta = converterParaTimeT(dia);
        cout << "\tValor da Consulta: ";
        cin >> cons[i].valorConsulta;
        cout << "\tDeseja adicionar mais consultas? (S/N)";
        cin >> conf;
        if (conf == 'N' || conf == 'n') {
            cout << "\n\tOs dados da consulta digitados até aqui foram salvos!\n";
            cout <<"\n====================================================================================="<< endl;
            saida = 0;
        }
    }
    contConsultaS = i;
}

// Definir as Impressões das tabelas

void impressaoCidades(struct cidade c[], int contCidadeS) {
    cout <<"\n====================================================================================="<< endl;
    cout << "\n\tLista dos Registros da tabela Cidades" << endl;
    for (int i = 0; i < contCidadeS; i++) {
        cout << "\n\tInformações da " << (i + 1) << "º Cidade\n";
        cout << "\n\tCódigo: " << c[i].codigo << endl;
        cout << "\n\tCidade: " << c[i].nome << endl;
        cout << "\n\tUF: " << c[i].uf << endl;
    }
    cout <<"\n====================================================================================="<< endl;
}

void impressaoRacas(struct raca r[], int contRacaS) {
    cout <<"\n====================================================================================="<< endl;
    cout << "\n\tLista dos Registros da tabela Raças" << endl;
    for (int i = 0; i < contRacaS; i++) {
        cout << "\n\tInformações da " << (i + 1) << "º Raça\n";
        cout << "\n\tCódigo: " << r[i].codigo << endl;
        cout << "\n\tDescrição: " << r[i].descricao << endl;
    }
    cout <<"\n====================================================================================="<< endl;
}

void impressaoTutores(struct tutor t[], int contTutorS, struct cidade c[], int contCidadeS) {
    cout <<"\n====================================================================================="<< endl;
    cout << "\n\tLista dos Registros da tabela Tutores" << endl;
    for (int i = 0; i < contTutorS; i++) {
        cout << "\n\tInformações do " << (i + 1) << "º tutor\n\n";
        cout << "\n\tCódigo: " << t[i].codigo << endl;
        cout << "\n\tNome: " << t[i].nome << endl;
        cout << "\n\tCPF: " << t[i].cpf << endl;
        cout << "\n\tEndereço: " << t[i].endereco << endl;
        cout << "\n\tCódigo da Cidade: " << t[i].codigoCidade << endl << endl;
        buscaBinariaCidade(c, contCidadeS, t[i].codigoCidade);
    }
    cout <<"\n====================================================================================="<< endl;
}

void impressaoAnimais(struct animal a[], int &contAnimalS,
                    struct raca r[], int &contRacaS,
                    struct tutor t[], int &contTutorS,
                    struct cidade c[], int &contCidadeS) {
    cout <<"\n====================================================================================="<< endl;
    cout << "\n\tLista dos Registros da tabela Animais" << endl;
    for (int i = 0; i < contAnimalS; i++) {
        cout << "\n\tInformações do " << (i + 1) << "º Animal\n";
        cout << "\n\tCódigo: " << a[i].codigo << endl;
        cout << "\n\tNome: " << a[i].nome << endl;
        cout << "\n\tCódigo da Raça: " << a[i].codigoRaca << endl;
        buscaBinariaRaca(r,contRacaS, a[i].codigoRaca);
        cout << "\n\tIdade: " << a[i].idade << endl;
        cout << "\n\tPeso: " << a[i].peso << endl;
        cout << "\n\tCódigo do Tutor: " << a[i].codigoTutor << endl;
        int codigoCidade = buscaBinariaTutor(t, contTutorS, a[i].codigoTutor);
        buscaBinariaCidade(c, contCidadeS, codigoCidade);
    }
    cout <<"\n====================================================================================="<< endl;
}


void impressaoVeterinarios(struct veterinario v[], int contVeterinarioS, struct cidade c[], int contCidadeS) {
    cout <<"\n====================================================================================="<< endl;
    cout << "\n\tLista dos Registros da tabela Veterinários" << endl;
    for (int i = 0; i < contVeterinarioS; i++) {
        cout << "\n\tInformações do " << (i + 1) << "º Veterinário\n";
        cout << "\n\tCódigo: " << v[i].codigo << endl;
        cout << "\n\tNome: " << v[i].nome << endl;
        cout << "\n\tEndereço: " << v[i].endereco << endl;
        cout << "\n\tCódigo da Cidade: " << v[i].codigoCidade << endl;
        buscaBinariaCidade(c, contCidadeS, v[i].codigoCidade);
    }
    cout <<"\n====================================================================================="<< endl;
}

void impressaoConsultas(struct consulta cons[], int &contConsultaS,
                      struct animal a[], int &contAnimalS,
                      struct veterinario v[], int &contVeterinarioS,
                      struct raca r[], int &contRacaS,
                      struct cidade c[], int &contCidadeS,
                      struct tutor t[], int &contTutoreS) {
    cout <<"\n====================================================================================="<< endl;
    cout << "\n\tLista dos Registros da tabela Consultas" << endl;
    for (int i = 0; i < contConsultaS; i++) {
        char dataFormatada[80];
        strftime(dataFormatada, sizeof(dataFormatada), "%d/%m/%Y", localtime(&cons[i].dataConsulta));
        int codRaca = 0, codTutor = 0;
        cout << "\n\tInformações da " << (i + 1) << "º Consulta\n";
        cout << "\n\tCódigo: " << cons[i].codigo << endl;
        cout << "\n\tCódigo do Animal: " << cons[i].codigoAnimal << endl;
        buscaBinariaAnimal(a, contAnimalS, cons[i].codigoAnimal, codRaca, codTutor);
        buscaBinariaRaca(r, contRacaS, codRaca);
        buscaBinariaTutor(t, contTutoreS, codTutor);
        cout << "\n\tCódigo do Veterinário: " << cons[i].codigoVeterinario << endl;
        int codCidade = buscaBinariaVeterinario(v, contVeterinarioS, cons[i].codigoVeterinario);
        buscaBinariaCidade(c, contCidadeS, codCidade);
        cout << "\n\tData da Consulta: " << dataFormatada << endl;
        cout << "\n\tValor da Consulta: " << cons[i].valorConsulta << endl;
    }
    cout <<"\n====================================================================================="<< endl;
}

// Funções para verificar se os códigos (PK) ja existem

bool codigoCidadeExiste(struct cidade c[], int contCidadeS, int cod) {
    for (int i = 0; i <= contCidadeS; i++) {
        if (c[i].codigo == cod) {
            return true;
        }
    }
    return false;
}

bool codigoRacaExiste(struct raca r[], int contRacaS, int cod) {
    for (int i = 0; i <= contRacaS; i++) {
        if (r[i].codigo == cod) {
            return true;
        }
    }
    return false;
}

bool codigoTutorExiste(struct tutor t[], int contTutorS, int cod) {
    for (int i = 0; i < contTutorS; i++) {
        if (t[i].codigo == cod) {
            return true;
        }
    }
    return false;
}

bool codigoAnimalExiste(struct animal a[], int contAnimalS, int cod) {
    for (int i = 0; i <= contAnimalS; i++) {
        if (a[i].codigo == cod) {
            return true;
        }
    }
    return false;
}

bool codigoVeterinarioExiste(struct veterinario v[], int contVeterinarioS, int cod) {
    for (int i = 0; i <= contVeterinarioS; i++) {
        if (v[i].codigo == cod) {
            return true;
        }
    }
    return false;
}

bool codigoConsultaExiste(struct consulta cons[], int contConsultaS, int cod) {
    for (int i = 0; i <= contConsultaS; i++) {
        if (cons[i].codigo == cod) {
            return true;
        }
    }
    return false;
}

bool cpfExiste(struct tutor t[], int contTutorS, string cpf) {
    cpf = limparCPF(cpf);
    for (int i = 0; i < contTutorS; i++) {
        if (t[i].cpf == cpf) {
            return true;
        }
    }
    return false;
}

// Busca Binaria

void buscaBinariaCidade(struct cidade c[], int contCidadeS, int cod) {
    int i = 0, f = contCidadeS;
    int m = (i + f) / 2;
    for (; f > i && cod != c[m].codigo; m = (i + f) / 2) {
        if (cod > c[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == c[m].codigo) {
        cout << "\n\t---------- Dados da Cidade ----------";
        cout << "\n\t\tNome: " << c[m].nome;
        cout << "\n\t\tEstado: " << c[m].uf << endl;
    }
}

void buscaBinariaRaca(struct raca r[], int contRacaS, int cod) {
    int i = 0, f = contRacaS;
    int m = (i + f) / 2;
    for (; f > i && cod != r[m].codigo; m = (i + f) / 2) {
        if (cod > r[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == r[m].codigo) {
        cout << "\n\t---------- Dados da Raça ----------";
        cout << "\n\t\tDescrição: " << r[m].descricao << endl;
    }
}

int buscaBinariaTutor(struct tutor t[], int contTutorS, int codTutor) {
    int i = 0, f = contTutorS;
    int m = (i + f) / 2;
    for (; f > i && codTutor != t[m].codigo; m = (i + f) / 2) {
        if (codTutor > t[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codTutor == t[m].codigo) {
        cout << "\n\t---------- Dados do Tutor ----------";
        cout << "\n\t\tNome: " << t[m].nome << endl;
    }
    return t[m].codigoCidade;
}

void buscaBinariaAnimal(struct animal a[], int contAnimalS, int codAnimal, int &codRaca, int &codTutor) {
    int i = 0, f = contAnimalS;
    int m = (i + f) / 2;
    for (; f > i && codAnimal != a[m].codigo; m = (i + f) / 2) {
        if (codAnimal > a[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codAnimal == a[m].codigo) {
        cout << "\n\t---------- Dados do Animal ----------";
        cout << "\n\t\tNome: " << a[m].nome << endl;
    }
    codRaca = a[m].codigoRaca;
    codTutor = a[i].codigoTutor;
}

int buscaBinariaVeterinario(struct veterinario v[], int contVeterinarioS, int codVeterinario) {
    int i = 0, f = contVeterinarioS;
    int m = (i + f) / 2;
    for (; f > i && codVeterinario != v[m].codigo; m = (i + f) / 2) {
        if (codVeterinario > v[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codVeterinario == v[m].codigo) {
        cout << "\n\t---------- Dados do Veterinário ----------";
        cout << "\n\t\tNome: " << v[m].nome << endl;
    }
    return v[m].codigoCidade;
}

// Funções para inclusão

void inclusaoTutor (struct tutor S[], int &contS, struct tutor T[], int contT, struct tutor A[], int &contA) {
    int i = 0, j = 0, k = 0;
    for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            A[k].nome = S[i].nome;
            A[k].codigoCidade = S[i].codigoCidade;
            A[k].cpf = S[i].cpf;
            A[k].endereco = S[i].endereco;
            i++;
        }
        else {
            A[k].codigo = T[j].codigo;
            A[k].nome = T[j].nome;
            A[k].codigoCidade = T[j].codigoCidade;
            A[k].cpf = T[j].cpf;
            A[k].endereco = T[j].endereco;
            j++;
        }
    }

    while (i < contS){
        A[k].codigo = S[i].codigo;
        A[k].nome = S[i].nome;
        A[k].codigoCidade = S[i].codigoCidade;
        A[k].cpf = S[i].cpf;
        A[k].endereco = S[i].endereco;
        i++;
        k++;
    }
    while (j < contT){
        A[k].codigo = T[j].codigo;
        A[k].nome = T[j].nome;
        A[k].codigoCidade = T[j].codigoCidade;
        A[k].cpf = T[j].cpf;
        A[k].endereco = T[j].endereco;
        j++;
        k++;
    }
    contA = k;
    contS = k;

    for (int a = 0; a < k; a++) {
        S[a].codigo = A[a].codigo;
        cout << S[a].codigo;
        S[a].nome = A[a].nome;
        cout << S[a].nome;
        S[a].codigoCidade = A[a].codigoCidade;
        cout << S[a].codigoCidade;
        S[a].cpf = A[a].cpf;
        cout << S[a].cpf;
        S[a].endereco = A[a].endereco;
        cout << S[a].endereco;
    }
}

void inclusaoAnimal (struct animal S[], int &contS, struct animal T[], int contT, struct animal A[], int &contA) {
    int i = 0, j = 0, k = 0;
    for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            A[k].nome = S[i].nome;
            A[k].codigoRaca = S[i].codigoRaca;
            A[k].codigoTutor = S[i].codigoTutor;
            A[k].idade = S[i].idade;
            A[k].peso = S[i].peso;
            i++;
        }
        else {
            A[k].codigo = T[j].codigo;
            A[k].nome = T[j].nome;
            A[k].codigoRaca = T[j].codigoRaca;
            A[k].codigoTutor = T[j].codigoTutor;
            A[k].idade = T[j].idade;
            A[k].peso = T[j].peso;
            j++;
        }
    }

    while (i < contS){
        A[k].codigo = S[i].codigo;
        A[k].nome = S[i].nome;
        A[k].codigoRaca = S[i].codigoRaca;
        A[k].codigoTutor = S[i].codigoTutor;
        A[k].idade = S[i].idade;
        A[k].peso = S[i].peso;
        i++;
        k++;
    }
    while (j < contT){
        A[k].codigo = T[j].codigo;
        A[k].nome = T[j].nome;
        A[k].codigoRaca = T[j].codigoRaca;
        A[k].codigoTutor = T[j].codigoTutor;
        A[k].idade = T[j].idade;
        A[k].peso = T[j].peso;
        j++;
        k++;
    }
    contA = k;
    contS = k;

    for (int a = 0; a < k; a++) {
        S[a].codigo = A[a].codigo;
        S[a].nome = A[a].nome;
        S[a].codigoRaca = A[a].codigoRaca;
        S[a].codigoTutor = A[a].codigoTutor;
        S[a].idade = A[a].idade;
        S[a].peso = A[a].peso;
    }
}

// Função de Mostar texto inicial no menu

void textoInicial() {
    std::vector<char> textoBemVindo = {
        '=', '=', '=', '=', '[',
        'B', 'e', 'm', ' ', 'V', 'i', 'n', 'd', 'o', ' ', 'à', ' ',
        'C', 'l', 'í', 'n', 'i', 'c', 'a', ' ',
        'V', 'e', 't', 'e', 'r', 'i', 'n', 'á', 'r', 'i', 'a',
        ']', '=', '=', '=', '='
    };

    for (int i = 0; i < textoBemVindo.size(); i++) {
        for (int j = 0; j <= i; j++) {
            if(j == 0) {
                std::cout << "\t\t\t\t" << textoBemVindo[j];
            } else {
                std::cout << textoBemVindo[j];
            }
            std::this_thread::sleep_for(std::chrono::nanoseconds(100000));
        }
        if (i < textoBemVindo.size() - 1) {
            system("cls");
        }
    }
}

// Funções para validar CPF

string limparCPF(const string& cpf) {
    string apenasNumeros;
    for (char c : cpf) {
        if (isdigit(c)) {
            apenasNumeros += c;
        }
    }
    return apenasNumeros;
}

string formatarCPF(const string& cpfEntrada) {
    string cpf = limparCPF(cpfEntrada);

    return cpf.substr(0, 3) + "." +
           cpf.substr(3, 3) + "." +
           cpf.substr(6, 3) + "-" +
           cpf.substr(9, 2);
}

bool validarCPF(const string& cpfEntrada) {
    string cpf = limparCPF(cpfEntrada);

    if (cpf.length() != 11 || regex_match(cpf, regex(R"((\d)\1{10})"))) {
        return false;
    }

    int digitos[11];
    for (int i = 0; i < 11; ++i) {
        digitos[i] = cpf[i] - '0';
    }

    // Primeiro verificador
    int soma = 0;
    for (int i = 0; i < 9; ++i) {
        soma += digitos[i] * (10 - i);
    }
    int resto = soma % 11;
    int digito1 = (resto < 2) ? 0 : 11 - resto;

    // Segundo verificador
    soma = 0;
    for (int i = 0; i < 10; ++i) {
        soma += digitos[i] * (11 - i);
    }
    resto = soma % 11;
    int digito2 = (resto < 2) ? 0 : 11 - resto;

    return (digito1 == digitos[9] && digito2 == digitos[10]);
}


time_t converterParaTimeT(string diaParaSerConvertido) {
    tm data = {};
    data.tm_mday = stoi(diaParaSerConvertido.substr(0, 2));
    data.tm_mon = stoi(diaParaSerConvertido.substr(3, 2)) - 1;
    data.tm_year = stoi(diaParaSerConvertido.substr(6, 4)) - 1900;
    return mktime(&data);
}

void verificarEntreDatas(struct consulta consulta[],
    struct consulta consultaVerificada[],
    int &contConsultaS,
    time_t dataInicial,
    time_t dataFinal,
    int &contConsultaDataVerificadas,
    struct animal a[], int &contAnimalS,
    struct veterinario v[], int &contVeterinarioS,
    struct raca r[], int &contRacaS,
    struct cidade c[], int &contCidadeS,
    struct tutor t[], int &contTutoreS) {
    float soma = 0;
    for (int i = 0; i < contConsultaS; i++) {
        if (consulta[i].dataConsulta>=dataInicial && consulta[i].dataConsulta<=dataFinal) {
            consultaVerificada[contConsultaDataVerificadas] = consulta[i];
            soma += consulta[i].valorConsulta;
            contConsultaDataVerificadas++;
        }
    }
    if (contConsultaDataVerificadas!=0) {
        impressaoConsultas(consultaVerificada, contConsultaDataVerificadas, a, contAnimalS, v, contVeterinarioS, r, contRacaS, c, contCidadeS, t, contTutoreS);
        cout<< "\n\tValor total das consultas: " << soma << endl;
        cout <<"\n====================================================================================="<< endl;
        contConsultaDataVerificadas = 0;
    } else {
        cout << "\n\tNão há registros de consulta entre estas datas.";
        cout <<"\n====================================================================================="<< endl;
    }
}

void verificarEntreDatasEVeterinario(struct consulta consulta[],
    struct consulta consultaVerificada[],
    int &contConsultaS,
    time_t dataInicial,
    time_t dataFinal,
    int &contConsultaDataVerificadas,
    int codigoVet,
    struct animal a[], int &contAnimalS,
    struct veterinario v[], int &contVeterinarioS,
    struct raca r[], int &contRacaS,
    struct cidade c[], int &contCidadeS,
    struct tutor t[], int &contTutoreS) {
    float soma = 0;
    contConsultaDataVerificadas = 0;
    for (int i = 0; i < contConsultaS; i++) {
        if (consulta[i].dataConsulta>=dataInicial && consulta[i].dataConsulta<=dataFinal && codigoVet == consulta[i].codigoVeterinario) {
            consultaVerificada[contConsultaDataVerificadas] = consulta[i];
            soma += consulta[i].valorConsulta;
            contConsultaDataVerificadas++;
        }
    }
    if (contConsultaDataVerificadas!=0) {
        impressaoConsultas(consultaVerificada, contConsultaDataVerificadas, a, contAnimalS, v, contVeterinarioS, r, contRacaS, c, contCidadeS, t, contTutoreS);
        cout<< "\n\tValor total das consultas: "<< soma <<endl;
        cout <<"\n====================================================================================="<< endl;
    } else {
        cout << "\n\tNão há registros de consulta entre estas datas.";
        cout <<"\n====================================================================================="<< endl;
    }
}

bool diaValido(int dd, int mm, int yy) {
    if (mm < 1 || mm > 12) return false;
    if (dd < 1) return false;

    int diasNoMes[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0))) diasNoMes[1] = 29;

    if (dd > diasNoMes[mm - 1]) return false;

    return true;
}


void verificarData(string &dia) {
    bool dataValida = false;
    while(dataValida!=true) {
        if (!regex_match(dia, regex(R"(\d{2}/\d{2}/\d{4})"))) {
            cout<<"\n\tData está inválido, digite novamente: ";
            cin>>dia;
            cin.ignore();
        } else {
            int dd = stoi(dia.substr(0, 2));
            int mm = stoi(dia.substr(3, 2));
            int yy= stoi(dia.substr(6, 4));
            if (!diaValido(dd,mm,yy)) {
                cout<<"\n\tData está inválido, digite novamente: ";
                cin>>dia;
                cin.ignore();
            }
            dataValida = true;
        }
    }
}

void buscarConsultaEntreDatas(struct consulta consulta[],
                               struct consulta consultaA[],
                               int &contConsultaS,
                               int &contConsultaDataVerificadas,
                               struct animal a[], int &contAnimalS,
                               struct veterinario v[], int &contVeterinarioS,
                               struct raca r[], int &contRacaS,
                               struct cidade c[], int &contCidadeS,
                               struct tutor t[], int &contTutoreS) {
    string diaI,diaF;
    time_t dataInicial,dataFinal;
    do{
        cout << "\n\tDigite a data incial para listar consultas: ";
        cin>>diaI;
        verificarData(diaI);
        cout << "\n\tDigite a data final para listar consultas: ";
        cin>>diaF;
        verificarData(diaF);
        dataInicial = converterParaTimeT(diaI);
        dataFinal = converterParaTimeT(diaF);
        if (dataInicial>dataFinal) cout << "\n\tData final menor que a inicial, digite novamente: ";
    } while (dataInicial>dataFinal);
    verificarEntreDatas(consulta, consultaA, contConsultaS,
                        dataInicial, dataFinal, contConsultaDataVerificadas,
                        a, contAnimalS, v, contVeterinarioS, r, contRacaS, c, contCidadeS, t, contTutoreS);
}

void buscarConsultaEntreDatasEVeterinario(struct consulta consulta[],
                                          struct consulta consultaA[],
                                          int &contConsultaS,
                                          int &contConsultaDataVerificadas,
                                          struct animal a[], int &contAnimalS,
                                          struct veterinario v[], int &contVeterinarioS,
                                          struct raca r[], int &contRacaS,
                                          struct cidade c[], int &contCidadeS,
                                          struct tutor t[], int &contTutoreS) {
    string diaI,diaF;
    time_t dataInicial,dataFinal;
    do{
        cout << "\n\tDigite a data incial para listar consultas: ";
        cin>>diaI;
        verificarData(diaI);
        cout << "\n\tDigite a data final para listar consultas: ";
        cin>>diaF;
        verificarData(diaF);
        dataInicial = converterParaTimeT(diaI);
        dataFinal = converterParaTimeT(diaF);
        if (dataInicial>dataFinal) cout << "\n\tData final menor que a inicial, digite novamente: ";
    } while (dataInicial>dataFinal);
    int codVet;
    cout<<"\n\tDigite o codigo do veterinario que deseja buscar: ";
    cin>>codVet;
    verificarEntreDatasEVeterinario(consulta, consultaA, contConsultaS,
                                        dataInicial, dataFinal, contConsultaDataVerificadas, codVet,
                                        a, contAnimalS, v, contVeterinarioS, r, contRacaS, c, contCidadeS, t, contTutoreS);
}