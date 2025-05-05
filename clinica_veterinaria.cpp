#include <iostream>
#include <clocale>
#include <conio.h>
#include <thread>
#include <vector>
#define T 5

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
    char cpf[12];
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
                      struct tutor t[], int contTutoreS);

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

void buscaBinariaTutor(struct tutor t[], int contTutorS, int codTutor);

void buscaBinariaAnimal(struct animal a[], int contAnimalS, int codAnimal);

void buscaBinariaVeterinario(struct veterinario v[], int contVeterinarioS, int codVeterinario);

char menu();

void inserir(struct cidade cidades[], int &contCidadeS, struct raca racas[], int &contRacaS,
             struct animal animais[], int &contAnimalS, struct tutor tutores[], int &contTutorS,
             struct veterinario veterinarios[], int &contVeterinarioS, struct consulta consultas[],
             int &contConsultaS);

void imprimir(struct cidade cidades[], int &contCidadeS, struct raca racas[], int &contRacaS,
              struct animal animais[], int &contAnimalS, struct tutor tutores[], int &contTutorS,
              struct veterinario veterinarios[], int &contVeterinarioS, struct consulta consultas[],
              int &contConsultaS);

char sair();

int main() {
    setlocale(LC_ALL, "Portuguese");

    textoInicial();

    // Defini��o dos vetores
    cidade cidades[T];
    raca racas[T];
    animal animais[T];
    tutor tutores[T];
    veterinario veterinarios[T];
    consulta consultas[T];

    //Defini��o dos Contadores
    int contCidadeS = 0;
    int contRacaS = 0;
    int contAnimalS = 0, contAnimalT = 0, contAnimalA = 0;
    int contTutorS = 0, contTutorT = 0, contTutorA = 0;
    int contVeterinarioS = 0;
    int contConsultaS = 0;

    //Menu
    char opcao = 'N';
    while (opcao != 'S') {
        opcao = menu();
        switch (opcao) {
            case '1': {
                inserir(cidades, contCidadeS, racas, contRacaS, animais, contAnimalS, tutores, contTutorS,
                        veterinarios, contVeterinarioS, consultas, contConsultaS);
                break;
            }
            case '2': {
                imprimir(cidades, contCidadeS, racas, contRacaS, animais, contAnimalS, tutores, contTutorS,
                         veterinarios, contVeterinarioS, consultas, contConsultaS);
                break;
            }
            //		  case '3' : { removerK(); break; }
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
    cout << "\n\t\tOpc�es:\n\n";
    cout << "\t\t\t1 - Inserir dados\n\n";
    cout << "\t\t\t2 - Imprimir dados\n\n";
    cout << "\t\t\t3 - Consultar dados\n\n";
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
        cout << "\n\t3 - Animal" << endl;
        cout << "\n\t4 - Tutor" << endl;
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

        if (conf == 'S') {
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
                    if (contAnimalS == 0) {
                        leituraAnimais(animais, contAnimalS, racas, contRacaS, tutores, contTutorS, cidades,
                                       contCidadeS);
                    } else {
                        cout << "A tabela de animais j� foi preenchida!";
                        impressaoAnimais(animais, contAnimalS);
                    }
                    break;
                }
                case '4': {
                    if (contTutorS == 0) {
                        leituraTutores(tutores, contTutorS, cidades, contCidadeS);
                    } else {
                        cout << "A tabela de tutores j� foi preenchida!";
                        impressaoTutores(tutores, contTutorS, cidades, contCidadeS);
                    }
                    break;
                }
                case '5': {
                    if (contCidadeS == 0) {
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

void imprimir(struct cidade cidades[], int &contCidadeS, struct raca racas[], int &contRacaS,
              struct animal animais[], int &contAnimalS, struct tutor tutores[], int &contTutorS,
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
        cout << "\n\t3 - Animal" << endl;
        cout << "\n\t4 - Tutor" << endl;
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

        if (conf == 'S') {
            switch (opcao) {
                case '1': {
                    if (contCidadeS != 0) {
                        impressaoCidades(cidades, contCidadeS);
                    } else {
                        cout <<
                                "A leitura das cidades ainda n�o foi realizada!\n Voc� ser� redirecionado para a tela de leitura de cidades!";
                        leituraCidades(cidades, contCidadeS);
                    }

                    break;
                }
                case '2': {
                    impressaoRacas(racas, contRacaS);
                    break;
                }
                case '3': {
                    impressaoAnimais(animais, contAnimalS);
                    break;
                }
                case '4': {
                    impressaoTutores(tutores, contTutorS, cidades, contCidadeS);
                    break;
                }
                case '5': {
                    impressaoVeterinarios(veterinarios, contVeterinarioS);
                    break;
                }
                case '6': {
                    impressaoConsultas(consultas, contConsultaS);
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
    if (sair == 'S') {
        cout << "\n\nSaindo do programa...";
        getch();
        system("cls");
    }
    return sair;
}

void leituraCidades(struct cidade c[], int &contCidadeS) {
    int i = 0;
    int saida = 1;
    while (i < T && saida != 0) {
        int cod;
        cout << "\nDigite as informa��es da " << (i + 1) << "� Cidade" << endl;
        cout << "Codigo: ";
        cin >> cod;

        if (cod <= 0) {
            saida = 0;
        } else if (codigoCidadeExiste(c, i, cod)) {
            cout << "O c�digo " << cod << " j� foi inserido, por favor, insira um c�digo v�lido!";
        } else {
            c[i].codigo = cod;
            if (c[i].codigo > 0) {
                cout << "Nome: ";
                cin.ignore();
                getline(cin, c[i].nome);
                cout << "Unidade Federal [UF]: ";
                cin.getline(c[i].uf, 3);
                i++;
            }
        }
    }
    contCidadeS = i - 1;
}

void leituraRacas(struct raca r[], int &contRacaS) {
    int i = 0;
    int saida = 1;
    while (i < T && saida != 0) {
        int cod;
        cout << "\nDigite as informa��es da " << (i + 1) << "� Ra�a" << endl;
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
                i++;
            }
        }
    }
    contRacaS = i - 1;
}

void leituraTutores(struct tutor t[], int &contTutorS,
                    struct cidade c[], int &contCidadeS) {
    if (contCidadeS == 0) {
        cout << "\nPara inserir um tutor � necess�rio informar as cidades primeiro!" << endl;
        cout << "Voc� ser� redirecionado para a tela de leitura das cidades!";
        getch();
        leituraCidades(c, contCidadeS);
    }

    int i = 0;
    int saida = 1;
    while (i < T && saida != 0) {
        int cod;
        cout << "\nDigite as informa��es do " << (i + 1) << "� Tutor" << endl;
        cout << "Codigo: ";
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
                cin.getline(t[i].cpf, 14);
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
                i++;
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
        cout << "Voc� ser� redirecionado para a tela de leitura de animais!";
        getch();
    }
    if (contTutorS == 0) {
        cout << "\nPara inserir um animal � necess�rio informar os tutores primeiro!" << endl;
        cout << "Voc� ser� redirecionado para a tela de leitura dos tutores!";
        getch();
        leituraTutores(t, contTutorS, c, contCidadeS);
        cout << "Voc� ser� redirecionado para a tela de leitura de animais!";
        getch();
    }

    int i = 0;
    int saida = 1;
    while (i < T && saida != 0) {
        int cod;
        cout << "\nDigite as informa��es do " << (i + 1) << "� Animal" << endl;
        cout << "Codigo: ";
        cin >> cod;

        if (cod <= 0) {
            saida = 0;
        } else if (codigoAnimalExiste(a, i, cod)) {
            cout << "O c�digo " << cod << " j� foi inserido, por favor, insira um c�digo v�lido!";
        } else {
            a[i].codigo = cod;
            if (r[i].codigo > 0) {
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
                buscaBinariaTutor(t, contTutorS, codTutor);
                a[i].codigoTutor = codTutor;
                i++;
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
    }

    int i = 0;
    int saida = 1;
    while (i < T && saida != 0) {
        int cod;
        cout << "\nDigite as informa��es do " << (i + 1) << "� Veterin�rio" << endl;
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
                i++;
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
                      struct tutor t[], int contTutoreS) {
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
    int i = 0, saida = 1;
    while (i < T && saida != 0) {
        int cod;
        cout << "\nDigite as informa��es da " << (i + 1) << "� Consulta" << endl;
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
        buscaBinariaAnimal(a, contAnimalS, codAnimal);
        cons[i].codigoAnimal = codAnimal;
        int codVeterinario;
        cout << "C�digo do Veterinario: ";
        cin >> codVeterinario;
        while (!codigoVeterinarioExiste(v, contVeterinarioS, codVeterinario)) {
            cout << "\nC�digo Inv�lido! Por favor digite um veterin�rio v�lido!";
            cout << "\nCodigo do Veterinario: ";
            cin >> codVeterinario;
        }
        buscaBinariaVeterinario(v, contVeterinarioS, codVeterinario);
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
        i++;
    }
    contConsultaS = i - 1;
}

// Definir as Impress�es das tabelas

void impressaoCidades(struct cidade c[], int contCidadeS) {
    cout << "\n\nLista dos Registros da tabela Cidades" << endl;
    for (int i = 0; i <= contCidadeS; i++) {
        cout << "\nInforma��es da " << (i + 1) << "� Cidade\n";
        cout << "\nC�digo: " << c[i].codigo << endl;
        cout << "\tCidade: " << c[i].nome << endl;
        cout << "\tUF: " << c[i].uf << endl;
    }
}

void impressaoRacas(struct raca r[], int contRacaS) {
    cout << "\n\nLista dos Registros da tabela Ra�as" << endl;
    for (int i = 0; i <= contRacaS; i++) {
        cout << "\nInforma��es da " << (i + 1) << "� Ra�a\n";
        cout << "\nC�digo: " << r[i].codigo << endl;
        cout << "\nDescri��o: " << r[i].descricao << endl;
    }
}

void impressaoTutores(struct tutor t[], int contTutorS, struct cidade c[], int contCidadeS) {
    cout << "\n\nLista dos Registros da tabela Tutores" << endl;
    for (int i = 0; i <= contTutorS; i++) {
        cout << "\nInforma��es do " << (i + 1) << "� tutor\n";
        cout << "\nC�digo: " << t[i].codigo << endl;
        cout << "\nNome: " << t[i].nome << endl;
        cout << "\nCPF: " << t[i].cpf << endl;
        cout << "\nEndere�o: " << t[i].endereco << endl;
        cout << "\n\tC�digo da Cidade: " << t[i].codigoCidade << endl;
        buscaBinariaCidade(c, contCidadeS, t[i].codigoCidade);
    }
}

void impressaoAnimais(struct animal a[], int contAnimalS) {
    cout << "\n\nLista dos Registros da tabela Animais" << endl;
    for (int i = 0; i <= contAnimalS; i++) {
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
    for (int i = 0; i <= contVeterinarioS; i++) {
        cout << "\nInforma��es do " << (i + 1) << "� Veterin�rio\n";
        cout << "\nC�digo: " << a[i].codigo << endl;
        cout << "\nNome: " << a[i].nome << endl;
        cout << "\nEndere�o: " << a[i].endereco << endl;
        cout << "\nC�digo da Cidade: " << a[i].codigoCidade << endl;
    }
}

void impressaoConsultas(struct consulta a[], int contConsultaS) {
    cout << "\n\nLista dos Registros da tabela Consultas" << endl;
    for (int i = 0; i <= contConsultaS; i++) {
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
    for (int i = 0; i <= contTutorS; i++) {
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

void buscaBinariaTutor(struct tutor t[], int contTutorS, int codTutor) {
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
}

void buscaBinariaAnimal(struct animal a[], int contAnimalS, int codAnimal) {
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
}

void buscaBinariaVeterinario(struct veterinario v[], int contVeterinarioS, int codVeterinario) {
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
}


//Exercicio 1 (Definir as leituras das tabelas)

// void leituraCidades(struct cidade c[], int &contCidadeS) {
//     // Dados predefinidos para as cidades
//     struct cidade cidades[] = {
//         {1, "S�o Paulo", "SP"},
//         {2, "Rio de Janeiro", "RJ"},
//         {3, "Belo Horizonte", "MG"}
//     };
//
//     // Copiar dados para o array de cidades
//     for (int i = 0; i < 3; i++) {
//         c[i] = cidades[i];
//     }
//
//     contCidadeS = 3;  // N�mero total de cidades inseridas
// }
//
// void leituraRacas(struct raca r[], int &contRacaS) {
//     // Dados predefinidos para as ra�as
//     struct raca racas[] = {
//         {1, "Labrador"},
//         {2, "Poodle"},
//         {3, "Bulldog"}
//     };
//
//     // Copiar dados para o array de ra�as
//     for (int i = 0; i < 3; i++) {
//         r[i] = racas[i];
//     }
//
//     contRacaS = 3;  // N�mero total de ra�as inseridas
// }
//
// void leituraAnimais(struct animal a[], int &contAnimalS,
//                     struct raca r[], int &contRacaS,
//                     struct tutor t[], int &contTutorS,
//                     struct cidade c[], int &contCidadeS) {
//     // Dados predefinidos para os animais
//     struct animal animais[] = {
//         {1, "Rex", 1, 5, 10.5, 101},
//         {2, "Bella", 2, 3, 8.0, 102}
//     };
//
//     // Copiar dados para o array de animais
//     for (int i = 0; i < 2; i++) {
//         a[i] = animais[i];
//     }
//
//     contAnimalS = 2;  // N�mero total de animais inseridos
// }
//
// void leituraTutores(struct tutor t[], int &contTutorS,
//                     struct cidade c[], int &contCidadeS) {
//     // Dados predefinidos para os tutores
//     struct tutor tutores[] = {
//         {101, "Carlos", "12345678900", "Rua A", 1},
//         {102, "Maria", "98765432100", "Rua B", 2}
//     };
//
//     // Copiar dados para o array de tutores
//     for (int i = 0; i < 2; i++) {
//         t[i] = tutores[i];
//     }
//
//     contTutorS = 2;  // N�mero total de tutores inseridos
// }
//
// void leituraVeterinarios(struct veterinario v[], int &contVeterinarioS,
//                         struct cidade c[], int &contCidadeS) {
//     // Dados predefinidos para os veterin�rios
//     struct veterinario veterinarios[] = {
//         {201, "Dr. Jo�o", "Rua X", 1},
//         {202, "Dra. Ana", "Rua Y", 2}
//     };
//
//     // Copiar dados para o array de veterin�rios
//     for (int i = 0; i < 2; i++) {
//         v[i] = veterinarios[i];
//     }
//
//     contVeterinarioS = 2;  // N�mero total de veterin�rios inseridos
// }
//
// void leituraConsultas(struct consulta cons[], int &contConsultaS,
//                     struct animal a[], int &contAnimalS,
//                     struct veterinario v[], int &contVeterinarioS,
//                     struct raca r[], int &contRacaS,
//                     struct cidade c[], int &contCidadeS,
//                     struct tutor t[], int contTutorS) {
//     // Dados predefinidos para as consultas
//     struct consulta consultas[] = {
//         {1, 1, 201, 1682821800, 150.0},  // Exemplo de data em formato time_t
//         {2, 2, 202, 1682908200, 200.0}
//     };
//
//     // Copiar dados para o array de consultas
//     for (int i = 0; i < 2; i++) {
//         cons[i] = consultas[i];
//     }
//
//     contConsultaS = 2;  // N�mero total de consultas inseridas
// }


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