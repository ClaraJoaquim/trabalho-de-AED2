#include <iostream>
#include <clocale>
#include <conio.h>
#include <thread>
#include <vector>
#include <cstring>
#include <regex>
#define Y 10

using namespace std;

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
void textoInicial();


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

void impressaoCidades(struct cidade c[], int contCidadeS);

void impressaoRacas(struct raca r[], int contRacaS);

void impressaoAnimais(struct animal a[], int contAnimalS);

void impressaoTutores(struct tutor t[], int contTutorS, struct cidade c[], int contCidadeS);

void impressaoVeterinarios(struct veterinario a[], int contVeterinarioS);

void impressaoConsultas(struct consulta a[], int contConsultaS);

bool codigoCidadeExiste(struct cidade c[], int contCidadeS, int cod);

bool codigoRacaExiste(struct raca r[], int contRacaS, int cod);

bool codigoTutorExiste(struct tutor t[], int contTutorS, int cod);

bool codigoAnimalExiste(struct animal a[], int contAnimalS, int cod);

bool codigoVeterinarioExiste(struct veterinario v[], int contVeterinarioS, int cod);

bool codigoConsultaExiste(struct consulta cons[], int contConsultaS, int cod);

void buscaBinariaCidade(struct cidade c[], int contCidadeS, int cod);

void buscaBinariaRaca(struct raca r[], int contRacaS, int cod);

int buscaBinariaTutor(struct tutor t[], int contTutorS, int codTutor);

void buscaBinariaAnimal(struct animal a[], int contAnimalS, int codAnimal, int &codRaca, int &codTutor);

int buscaBinariaVeterinario(struct veterinario v[], int contVeterinarioS, int codVeterinario);

string limparCPF(const string& cpf);

string formatarCPF(const string& cpfEntrada);

bool validarCPF(const string& cpfEntrada);

bool cpfExiste(struct tutor t[], int contTutorS, string cpf);

char menu();

void inserir(struct cidade cidades[], int &contCidadeS, struct raca racas[], int &contRacaS,
             struct animal animais[], int &contAnimalS, struct tutor tutores[], int &contTutorS,
             struct veterinario veterinarios[], int &contVeterinarioS, struct consulta consultas[],
             int &contConsultaS);

void imprimir(struct cidade cidades[], int &contCidadeS, struct raca racas[], int &contRacaS,
              struct animal animais[], int &contAnimalS, struct tutor tutores[], int &contTutorA,
              struct veterinario veterinarios[], int &contVeterinarioS, struct consulta consultas[],
              int &contConsultaS);

void incluir(struct animal animais[], int &contAnimalS, struct animal animaisT[], int contAnimalT,
             struct animal animaisA[], int &contAnimalA, struct tutor tutores[], int &contTutorS,
             struct tutor tutoresT[], int contTutorT, struct tutor tutoresA[], int &contTutorA,
             struct cidade cidades[], int &contCidadeS, struct raca racas[], int &contRacaS);

void inclusaoTutor (struct tutor S[], int contS, struct tutor T[], int contT, struct tutor A[], int &contA);

void inclusaoAnimal (struct animal S[], int contS, struct animal T[], int contT, struct animal A[], int &contA);

char sair();

int main() {
    setlocale(LC_ALL, "Portuguese");

    textoInicial();

    // Defini��o dos vetores
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

    //Defini��o dos Contadores
    int contCidadeS = 0;
    int contRacaS = 0;
    int contAnimalS = 0, contAnimalT, contAnimalA;
    int contTutorS = 0, contTutorT, contTutorA;
    int contVeterinarioS = 0;
    int contConsultaS = 0;

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
                imprimir(cidades, contCidadeS, racas, contRacaS, animaisA, contAnimalA, tutoresA, contTutorA,
         veterinarios, contVeterinarioS, consultas, contConsultaS);
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

//Fun��es do Menu

char menu() {
    char opcao;
    // system("cls");
    cout << "\n\t\tOp��es:\n\n";
    cout << "\t\t\t1 - Inserir dados\n\n";
    cout << "\t\t\t2 - Incluir Novos Dados\n\n";
    cout << "\t\t\t3 - Imprimir dados\n\n";
    cout << "\t\t\t4 - Sair do programa\n\n";
    cout << "\t\tEscolha a Op��o: ";
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
        cout << "\n\t2 - Ra�a" << endl;
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
            cout << "\n\t. Confirma a opera��o? (S/N): ";
            cin >> conf;
        }

        if (conf == 'S' || conf == 's') {
            switch (opcao) {
                case '1': {
                    if (contCidadeS == 0) {
                        leituraCidades(cidades, contCidadeS);
                    } else {
                        cout << "A tabela de cidades j� foi preenchida!";
                        impressaoCidades(cidades, contCidadeS);
                    }
                    break;
                }
                case '2': {
                    if (contRacaS == 0) {
                        leituraRacas(racas, contRacaS);
                    } else {
                        cout << "A tabela de ra�as j� foi preenchida!";
                        impressaoRacas(racas, contRacaS);
                    }
                    break;
                }
                case '3': {
                    if (contTutorS == 0) {
                        leituraTutores(tutores, contTutorS, cidades, contCidadeS);
                    } else {
                        cout << "A tabela de tutores j� foi preenchida!";
                        impressaoTutores(tutores, contTutorS, cidades, contCidadeS);
                    }
                    break;
                }
                case '4': {
                    if (contAnimalS == 0) {
                        leituraAnimais(animais, contAnimalS, racas, contRacaS, tutores, contTutorS, cidades,
                                       contCidadeS);
                    } else {
                        cout << "A tabela de animais j� foi preenchida!";
                        impressaoAnimais(animais, contAnimalS);
                    }
                    break;
                }
                case '5': {
                    if (contVeterinarioS == 0) {
                        leituraVeterinarios(veterinarios, contVeterinarioS, cidades, contCidadeS);
                    } else {
                        cout << "A tabela de veterin�rios j� foi preenchida!";
                        impressaoVeterinarios(veterinarios, contVeterinarioS);
                    }
                    break;
                }
                case '6': {
                    if (contConsultaS == 0) {
                        leituraConsultas(consultas, contConsultaS, animais, contAnimalS, veterinarios, contVeterinarioS,
                                         racas, contRacaS, cidades, contCidadeS, tutores, contTutorS);
                    } else {
                        cout << "A tabela de consultas j� foi preenchida!";
                        impressaoConsultas(consultas, contConsultaS);
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
            cout << "\n\nOpera��o cancelada! Voltando para o menu de inserir dados...";
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
        cout << "\n\tDeseja Realizar a Inclus�o de qual lista?\n\n";
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
            cout << "\n\t. Confirma a opera��o? (S/N): ";
            cin >> conf;
        }

        if (conf == 'S' || conf == 's') {
            switch (opcao) {

                case '1': {
                    if (contTutorS == 0) {
                        cout << "\nA tabela de tutores ainda n�o foi preenchida!\nVco� ser� direcionado para o cadastro da tabela de Tutores!\n";
                        leituraTutores(tutores, contTutorS, cidades, contCidadeS);
                        cout << "\nTabela de tutores foi preenchida!\nPor favor preencha a lista com as novas inclus�es\n";
                        leituraTutores(tutoresT, contTutorT, cidades, contCidadeS);
                        inclusaoTutor(tutores, contTutorS, tutoresT, contTutorT, tutoresA, contTutorA);
                    } else {
                        cout << "\nPreencha a tabela com os novos registros de tutores\n";
                        leituraTutores(tutoresT, contTutorT, cidades, contCidadeS);
                        inclusaoTutor(tutores, contTutorS, tutoresT, contTutorT, tutoresA, contTutorA);
                    }
                    break;
                }
                case '2': {
                    if (contAnimalS == 0) {
                        cout << "\nA tabela de animais ainda n�o foi preenchida!\nVoc� ser� direcionado para a leitura da tabela de Animais!\n";
                        leituraAnimais(animais, contAnimalS, racas, contRacaS, tutores, contTutorS, cidades, contCidadeS);
                        cout << "\nTabela de animais foi preenchida!\nPor favor preencha a lista com as novas inclus�es\n";
                        leituraAnimais(animaisT, contAnimalT, racas, contRacaS, tutores, contTutorS, cidades, contCidadeS);
                        inclusaoAnimal(animais, contAnimalS, animaisT, contAnimalT, animaisA, contAnimalA);
                    } else {
                        cout << "\nPreencha a tabela com os novos registros de animais\n";
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
            cout << "\n\nOpera��o cancelada! Voltando para o menu de inserir dados...";
            getch();
        }
    }
}

void imprimir(struct cidade cidades[], int &contCidadeS, struct raca racas[], int &contRacaS,
              struct animal animais[], int &contAnimalS, struct tutor tutoresA[], int &contTutorA,
              struct veterinario veterinarios[], int &contVeterinarioS, struct consulta consultas[],
              int &contConsultaS) {
    char conf;

    char opcao;
    bool loop = true;

    while (loop) {
        // system("cls");
        cout << "\n\tDeseja Realizar a Impress�o de qual lista?\n\n";
        cout << "\n\t1 - Cidade" << endl;
        cout << "\n\t2 - Ra�a" << endl;
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
            cout << "\n\t. Confirma a opera��o? (S/N): ";
            cin >> conf;
        }

        if (conf == 'S' || conf == 's') {
            switch (opcao) {
                case '1': {
                    if (contCidadeS != 0) {
                        impressaoCidades(cidades, contCidadeS);
                    } else {
                        cout << "\nA leitura das cidades ainda n�o foi realizada!\n Voc� ser� redirecionado para a tela de leitura de cidades!\n";
                        leituraCidades(cidades, contCidadeS);
                    }
                    break;
                }
                case '2': {
                    if (contRacaS != 0) {
                        impressaoRacas(racas, contRacaS);
                    } else {
                        cout << "\nA leitura das ra�as ainda n�o foi realizada!\n Voc� ser� redirecionado para a tela de leitura de ra�as!\n";
                        leituraRacas(racas, contRacaS);
                    }
                    break;
                }
                case '3': {
                    if (contTutorA != 0) {
                        impressaoTutores(tutoresA, contTutorA, cidades, contCidadeS);
                    } else {
                        cout << "\nA leitura de tutores ainda n�o foi realizada!\n Voc� ser� redirecionado para a tela de leitura de tutores!\n";
                        leituraAnimais(animais, contAnimalS, racas, contRacaS, tutoresA, contTutorA, cidades, contCidadeS);
                    }
                    break;
                }
                case '4': {
                    if (contAnimalS != 0) {
                        impressaoAnimais(animais, contAnimalS);
                    } else {
                        cout << "\nA leitura de animais ainda n�o foi realizada!\n Voc� ser� redirecionado para a tela de leitura de animais!\n";
                        leituraAnimais(animais, contAnimalS, racas, contRacaS, tutoresA, contTutorA, cidades, contCidadeS);
                    }
                    break;
                }
                case '5': {
                    if (contVeterinarioS != 0) {
                        impressaoVeterinarios(veterinarios, contVeterinarioS);
                    } else {
                        cout << "\nA leitura de veterin�rios ainda n�o foi realizada!\n Voc� ser� redirecionado para a tela de leitura de veterinarios!\n";
                        leituraVeterinarios(veterinarios, contVeterinarioS, cidades, contCidadeS);
                    }
                    break;
                }
                case '6': {
                    if (contConsultaS != 0) {
                        impressaoConsultas(consultas, contConsultaS);
                    } else {
                        cout << "\nA leitura de consultas ainda n�o foi realizada!\n Voc� ser� redirecionado para a tela de leitura de consultas!\n";
                        leituraAnimais(animais, contAnimalS, racas, contRacaS, tutoresA, contTutorA, cidades, contCidadeS);
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
            cout << "\n\nOpera��o cancelada! Voltando para o menu de inserir dados...";
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
        system("cls");
    }
    return sair;
}

//Exercicio 1 (Definir as leituras das tabelas)

void leituraCidades(struct cidade c[], int &contCidadeS) {
    int i = 0;
    for (int saida = 1; i < Y && saida != 0; i++) {
        int cod;
        cout << "\n\tDigite as informa��es da Cidade" << endl;
        cout << "\t\tCodigo: ";
        cin >> cod;

        if (cod <= 0) {
            saida = 0;
        } else if (codigoCidadeExiste(c, i, cod)) {
            cout << "\tO c�digo " << cod << " j� foi inserido, por favor, insira um c�digo v�lido!";
        } else {
            c[i].codigo = cod;
            if (c[i].codigo > 0) {
                cout << "\t\tNome: ";
                cin.ignore();
                getline(cin, c[i].nome);
                cout << "\t\tUnidade Federal [UF]: ";
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
        cout << "\nDigite as informa��es da Ra�a" << endl;
        cout << "Codigo: ";
        cin >> cod;

        if (cod <= 0) {
            saida = 0;
        } else if (codigoRacaExiste(r, i, cod)) {
            cout << "O c�digo " << cod << " j� foi inserido, por favor, insira um c�digo v�lido!";
        } else {
            r[i].codigo = cod;
            if (r[i].codigo > 0) {
                cout << "Descricao: ";
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
        cout << "\n\tPara inserir um tutor � necess�rio informar as cidades primeiro!" << endl;
        cout << "\tVoc� ser� redirecionado para a tela de leitura das cidades!" << endl;
        cout <<"\n====================================================================================="<< endl;
        getch();
        leituraCidades(c, contCidadeS);
        cout <<"\n====================================================================================="<< endl;
        cout << "\n\tN�o h� dados cadastrados na tabela tutor";
        cout << "\n\tVoc� ser� redirecionado para a tela de leitura de tutores!";
        cout <<"\n====================================================================================="<< endl;
    }

    int i = 0;
    for (int saida = 1; i < Y && saida != 0; i++) {
        int cod;
        cout << "\n\tDigite as informa��es do Tutor" << endl;
        cout << "\t\tCodigo: ";
        cin >> cod;

        if (cod <= 0) {
            saida = 0;
        } else if (codigoTutorExiste(t, i, cod)) {
            cout << "O c�digo " << cod << " j� foi inserido, por favor, insira um c�digo v�lido!";
        } else {
            t[i].codigo = cod;
            if (t[i].codigo > 0) {
                cin.ignore();
                cout << "Nome: ";
                getline(cin, t[i].nome);
                cout << "CPF: ";
                getline(cin, t[i].cpf);
                while (!validarCPF(t[i].cpf)) {
                    cout << "\nO CPF que voc� digitou n�o � v�lido!\nPor favor digite um cpf v�lido";
                    cout << "\nCPF: ";
                    getline(cin, t[i].cpf);
                }
                while (cpfExiste(t, i, t[i].cpf)) {
                    cout << "\nEste CPF j� existe!\nPor favor digite um cpf v�lido";
                    cout << "\nCPF: ";
                    getline(cin, t[i].cpf);
                }
                cout << "Endereco: ";
                getline(cin, t[i].endereco);

                int codCidade;
                cout << "Codigo da Cidade: ";
                cin >> codCidade;
                while (!codigoCidadeExiste(c, contCidadeS, codCidade)) {
                    cout << "\nC�digo Inv�lido! Por favor digite uma cidade v�lida!";
                    cout << "\nCodigo da Cidade: ";
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
        cout << "\nPara inserir um animal � necess�rio informar as ra�as primeiro!" << endl;
        cout << "Voc� ser� redirecionado para a tela de leitura das ra�as!";
        getch();
        leituraRacas(r, contRacaS);
        cout << "\nN�o h� dados cadastrados na tabela animal";
        cout << "\nVoc� ser� redirecionado para a tela de leitura de animais!";
        getch();
    }
    if (contTutorS == 0) {
        cout << "\nPara inserir um animal � necess�rio informar os tutores primeiro!" << endl;
        cout << "Voc� ser� redirecionado para a tela de leitura dos tutores!";
        getch();
        leituraTutores(t, contTutorS, c, contCidadeS);
        cout << "\nN�o h� dados cadastrados na tabela animal";
        cout << "\nVoc� ser� redirecionado para a tela de leitura de animais!";
        getch();
    }

    int i = 0;
    for (int saida = 1; i < Y && saida != 0; i++) {
        int cod;
        cout << "\nDigite as informa��es do Animal" << endl;
        cout << "Codigo: ";
        cin >> cod;

        if (cod <= 0) {
            saida = 0;
        } else if (codigoAnimalExiste(a, i, cod)) {
            cout << "O c�digo " << cod << " j� foi inserido, por favor, insira um c�digo v�lido!";
        } else {
            a[i].codigo = cod;
            if (a[i].codigo > 0) {
                cin.ignore();
                cout << "Nome: ";
                getline(cin, a[i].nome);
                int codRaca;
                cout << "Codigo da Raca: ";
                cin >> codRaca;
                while (!codigoRacaExiste(r, contRacaS, codRaca)) {
                    cout << "\nC�digo Inv�lido! Por favor digite uma cidade v�lida!";
                    cin >> codRaca;
                }
                buscaBinariaRaca(r,contRacaS, codRaca);
                a[i].codigoRaca = codRaca;
                cout << "Idade: ";
                cin >> a[i].idade;
                cout << "Peso: ";
                cin >> a[i].peso;
                int codTutor;
                cout << "C�digo do Tutor: ";
                cin >> codTutor;
                while (!codigoTutorExiste(t, contTutorS, codTutor)) {
                    cout << "\nC�digo Inv�lido! Por favor digite o c�digo de um tutor v�lido!";
                    cout << "\nCodigo do Tutor: ";
                    cin >> codTutor;
                }
                int abu = buscaBinariaTutor(t, contTutorS, codTutor);
                buscaBinariaCidade(c, contCidadeS, abu);
                a[i].codigoTutor = codTutor;
            }
        }
    }
    contAnimalS = i - 1;
}

void leituraVeterinarios(struct veterinario v[], int &contVeterinarioS,
                         struct cidade c[], int &contCidadeS) {
    if (contCidadeS == 0) {
        cout << "\nPara inserir um tutor � necess�rio informar as cidades primeiro!" << endl;
        cout << "Voc� ser� redirecionado para a tela de leitura das cidades!";
        getch();
        leituraCidades(c, contCidadeS);
        cout << "\nN�o h� dados cadastrados na tabela veterinarios";
        cout << "\nVoc� ser� redirecionado para a tela de leitura de veterinarios!";
    }

    int i = 0;
    for (int saida = 1; i < Y && saida != 0; i++) {
        int cod;
        cout << "\nDigite as informa��es do Veterin�rio" << endl;
        cout << "Codigo: ";
        cin >> cod;

        if (cod <= 0) {
            saida = 0;
        } else if (codigoVeterinarioExiste(v, i, cod)) {
            cout << "O c�digo " << cod << " j� foi inserido, por favor, insira um c�digo v�lido!";
        } else {
            v[i].codigo = cod;
            if (v[i].codigo > 0) {
                cin.ignore();
                cout << "Nome: ";
                getline(cin, v[i].nome);
                cout << "Endere�o: ";
                getline(cin, v[i].endereco);
                int codCidade;
                cout << "Codigo da Cidade: ";
                cin >> codCidade;
                while (!codigoCidadeExiste(c, contCidadeS, codCidade)) {
                    cout << "\nC�digo Inv�lido! Por favor digite uma cidade v�lida!";
                    cout << "\nCodigo da Cidade: ";
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
        cout << "\nPara inserir uma consulta � necess�rio informar os animais primeiro!" << endl;
        cout << "Voc� ser� redirecionado para a tela de leitura dos animais!";
        getch();
        leituraAnimais(a, contAnimalS, r, contRacaS, t, contTutoreS, c, contCidadeS);
    }
    if (contVeterinarioS == 0) {
        cout << "\nPara inserir uma consulta � necess�rio informar os veterin�rios primeiro!" << endl;
        cout << "Voc� ser� redirecionado para a tela de leitura dos veterin�rios!";
        getch();
        leituraVeterinarios(v, contVeterinarioS, c, contCidadeS);
    }

    char conf;
    int i = 0;
    int codRaca;
    int codTutor;

    for (int saida = 1; i < Y && saida != 0; i++) {
        int cod;
        cout << "\nDigite as informa��es da Consulta" << endl;
        cout << "Codigo: " << (i + 1)<< endl;
        cod = i + 1;

        cons[i].codigo = cod;
        int codAnimal;
        cout << "C�digo do Animal: ";
        cin >> codAnimal;
        while (!codigoAnimalExiste(a, contAnimalS, codAnimal)) {
            cout << "\nC�digo Inv�lido! Por favor digite um animal v�lido!";
            cout << "\nCodigo do Animal: ";
            cin >> codAnimal;
        }
        buscaBinariaAnimal(a, contAnimalS, codAnimal, codRaca, codTutor);
        buscaBinariaRaca(r, contRacaS, codRaca);
        buscaBinariaTutor(t, contTutoreS, codTutor);
        cons[i].codigoAnimal = codAnimal;
        int codVeterinario;
        cout << "C�digo do Veterinario: ";
        cin >> codVeterinario;
        while (!codigoVeterinarioExiste(v, contVeterinarioS, codVeterinario)) {
            cout << "\nC�digo Inv�lido! Por favor digite um veterin�rio v�lido!";
            cout << "\nCodigo do Veterinario: ";
            cin >> codVeterinario;
        }
        int codCidade = buscaBinariaVeterinario(v, contVeterinarioS, codVeterinario);
        buscaBinariaCidade(c, contCidadeS, codCidade);
        cons[i].codigoVeterinario = codVeterinario;
        cout << "Data da Consulta: ";
        cin >> cons[i].dataConsulta;
        cout << "Valor da Consulta: ";
        cin >> cons[i].valorConsulta;
        cout << "Deseja finalizar a leitura de consultas? (S/N)";
        cin >> conf;
        if (conf == 'S' || conf == 's') {
            cout << "Os dados da consulta digitados at� aqui foram salvos!";
            saida = 0;
        }
    }
    contConsultaS = i - 1;
}

// Definir as Impress�es das tabelas

void impressaoCidades(struct cidade c[], int contCidadeS) {
    cout << "\n\nLista dos Registros da tabela Cidades" << endl;
    for (int i = 0; i < contCidadeS; i++) {
        cout << "\nInforma��es da " << (i + 1) << "� Cidade\n";
        cout << "\nC�digo: " << c[i].codigo << endl;
        cout << "\nCidade: " << c[i].nome << endl;
        cout << "\nUF: " << c[i].uf << endl;
    }
}

void impressaoRacas(struct raca r[], int contRacaS) {
    cout << "\n\nLista dos Registros da tabela Ra�as" << endl;
    for (int i = 0; i < contRacaS; i++) {
        cout << "\nInforma��es da " << (i + 1) << "� Ra�a\n";
        cout << "\nC�digo: " << r[i].codigo << endl;
        cout << "\nDescri��o: " << r[i].descricao << endl;
    }
}

void impressaoTutores(struct tutor t[], int contTutorS, struct cidade c[], int contCidadeS) {
    cout << "\n\nLista dos Registros da tabela Tutores" << endl;
    for (int i = 0; i < contTutorS; i++) {
        cout << "\nInforma��es do " << (i + 1) << "� tutor\n";
        cout << "\nC�digo: " << t[i].codigo << endl;
        cout << "\nNome: " << t[i].nome << endl;
        cout << "\nCPF: " << t[i].cpf << endl;
        cout << "\nEndere�o: " << t[i].endereco << endl;
        cout << "\nC�digo da Cidade: " << t[i].codigoCidade << endl;
        buscaBinariaCidade(c, contCidadeS, t[i].codigoCidade);
    }
}

void impressaoAnimais(struct animal a[], int contAnimalS) {
    cout << "\n\nLista dos Registros da tabela Animais" << endl;
    for (int i = 0; i < contAnimalS; i++) {
        cout << "\nInforma��es do " << (i + 1) << "� Animal\n";
        cout << "\nC�digo: " << a[i].codigo << endl;
        cout << "\nNome: " << a[i].nome << endl;
        cout << "\nC�digo da Ra�a: " << a[i].codigoRaca << endl;
        cout << "\nIdade: " << a[i].idade << endl;
        cout << "\nPeso: " << a[i].peso << endl;
        cout << "\nC�digo do Tutor: " << a[i].codigoTutor << endl;
    }
}


void impressaoVeterinarios(struct veterinario a[], int contVeterinarioS) {
    cout << "\n\nLista dos Registros da tabela Veterin�rios" << endl;
    for (int i = 0; i < contVeterinarioS; i++) {
        cout << "\nInforma��es do " << (i + 1) << "� Veterin�rio\n";
        cout << "\nC�digo: " << a[i].codigo << endl;
        cout << "\nNome: " << a[i].nome << endl;
        cout << "\nEndere�o: " << a[i].endereco << endl;
        cout << "\nC�digo da Cidade: " << a[i].codigoCidade << endl;
    }
}

void impressaoConsultas(struct consulta a[], int contConsultaS) {
    cout << "\n\nLista dos Registros da tabela Consultas" << endl;
    for (int i = 0; i < contConsultaS; i++) {
        cout << "\nInforma��es da " << (i + 1) << "� Consulta\n";
        cout << "\nC�digo: " << a[i].codigo << endl;
        cout << "\nC�digo do Animal: " << a[i].codigoAnimal << endl;
        cout << "\nC�digo do Veterin�rio: " << a[i].codigoVeterinario << endl;
        cout << "\nData da Consulta: " << a[i].dataConsulta << endl;
        cout << "\nValor da Consulta: " << a[i].valorConsulta << endl;
    }
}

//Busca se os c�digos (PK) ja existem

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
        cout << "\t----- Dados da Cidade -----";
        cout << "\n\tNome: " << c[m].nome;
        cout << "\n\tEstado: " << c[m].uf << endl;
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
        cout << "\t----- Dados da Ra�a -----";
        cout << "\n\tDescri��o: " << r[m].descricao << endl;
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
        cout << "\t----- Dados do Tutor -----";
        cout << "\n\tNome: " << t[m].nome << endl;
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
        cout << "\t----- Dados do Animal -----";
        cout << "\n\tNome: " << a[m].nome << endl;
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
        cout << "\t----- Dados do Veterin�rio -----";
        cout << "\n\tNome: " << v[m].nome << endl;
    }
    return v[m].codigoCidade;
}

// M�todos de Inclus�o

void inclusaoTutor (struct tutor S[], int contS, struct tutor T[], int contT, struct tutor A[], int &contA) {
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
}

void inclusaoAnimal (struct animal S[], int contS, struct animal T[], int contT, struct animal A[], int &contA) {
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
}

void textoInicial() {
    std::vector<char> textoBemVindo = {
        '=', '=', '=', '=', '[',
        'B', 'e', 'm', ' ', 'V', 'i', 'n', 'd', 'o', ' ', '�', ' ',
        'C', 'l', '�', 'n', 'i', 'c', 'a', ' ',
        'V', 'e', 't', 'e', 'r', 'i', 'n', '�', 'r', 'i', 'a',
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