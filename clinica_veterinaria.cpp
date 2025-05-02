#include <iostream>
#include <clocale>
#include <conio.h>
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

void leituraCidades(struct cidade cidades[], int &contCidadeS);
void leituraRacas(struct raca r[], int &contRacaS);
void leituraAnimais(struct animal a[], int &contAnimalS,
                    struct raca r[], int &contRacaS,
                    struct tutor t[], int &contTutorS,
                    struct  cidade c[], int &contCidadeS);
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
void impressaoTutores(struct tutor a[], int contTutorS);
void impressaoVeterinarios(struct veterinario a[], int contVeterinarioS);
void impressaoConsultas(struct consulta a[], int contConsultaS);

bool codigoCidadeExiste(struct cidade c[], int contCidadeS, int cod);
bool codigoRacaExiste(struct raca r[], int contRacaS, int cod);
bool codigoTutorExiste(struct tutor t[], int contTutorS, int cod);
bool codigoAnimalExiste(struct animal a[], int contAnimalS, int cod);
bool codigoVeterinarioExiste(struct veterinario v[], int contVeterinarioS, int cod);
bool codigoConsultaExiste(struct consulta cons[], int contConsultaS, int cod);
bool buscaBinaria (struct cidade c[],int contCidadeS, int cod);

char menu();

void inserir(struct cidade cidades[], int &contCidadeS, struct raca racas[], int &contRacaS,
             struct animal animais[], int &contAnimalS, struct tutor tutores[], int &contTutorS,
             struct veterinario veterinarios[], int &contVeterinarioS, struct consulta consultas[],
             int &contConsultaS);

char sair();

int main() {
    setlocale(LC_ALL, "Portuguese");

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

    // leituraCidades(cidades, contCidadeS);
    // leituraRacas(racas, contRacaS);
    // leituraTutores(tutores, contTutorS, cidades, contCidadeS);
    // leituraVeterinarios(veterinarios, contVeterinarioS, cidades, contCidadeS);
    // leituraAnimais(animais, contAnimalS, racas, contRacaS, tutores, contTutorS, cidades, contCidadeS);
    // leituraConsultas(consultas, contConsultaS, animais, contAnimalS, veterinarios, contVeterinarioS, racas, contRacaS, cidades, contCidadeS, tutores, contTutorS);
    // impressaoCidades(cidades, contCidadeS);
    // impressaoRacas(racas, contRacaS);
    // impressaoTutores(tutores, contTutorS);
    // impressaoVeterinarios(veterinarios, contVeterinarioS);
    // impressaoAnimais(animais, contAnimalS);
    // impressaoConsultas(consultas, contConsultaS);

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
            //		  case '2' : { inserirFim(); break; }
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
    cout << "\t\tOpc�es:\n\n";
    cout << "\t\t\t1 - Inserir dados\n\n";
    cout << "\t\t\t2 - Incluir novos dados\n\n";
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
        cout << "\tDeseja Realizar a Leitura de qual lista?\n\n";
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
                        leituraAnimais(animais, contAnimalS, racas, contRacaS, tutores, contTutorS, cidades, contCidadeS);
                    } else {
                        cout << "A tabela de animais j� foi preenchida!";
                        impressaoAnimais(animais, contAnimalS);
                    }
                    break;
                }
                case '4': {
                    if (contCidadeS == 0) {
                        leituraTutores(tutores, contTutorS, cidades, contCidadeS);
                    } else {
                        cout << "A tabela de tutores j� foi preenchida!";
                        impressaoTutores(tutores, contTutorS);
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
                        leituraConsultas(consultas, contConsultaS, animais, contAnimalS, veterinarios, contVeterinarioS, racas, contRacaS, cidades, contCidadeS, tutores, contTutorS);
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

void leituraAnimais(struct animal a[], int &contAnimalS,
                    struct raca r[], int &contRacaS,
                    struct tutor t[], int &contTutorS,
                    struct  cidade c[], int &contCidadeS) {
    if (contRacaS == 0) {
        cout << "\nPara inserir um animal � necess�rio informar as ra�as primeiro!" << endl;
        cout << "Voc� ser� redirecionado para a tela de leitura das ra�as!";
        getch();
        leituraRacas(r, contRacaS);
    }
    if (contTutorS == 0) {
        cout << "\nPara inserir um animal � necess�rio informar os tutores primeiro!" << endl;
        cout << "Voc� ser� redirecionado para a tela de leitura dos tutores!";
        getch();
        leituraTutores(t, contTutorS, c, contCidadeS);
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
                getline(cin, c[i].nome);
                cout << "Codigo da Raca: ";
                cin >> a[i].codigoRaca;
                cout << "Idade: ";
                cin >> a[i].idade;
                cout << "Peso: ";
                cin >> a[i].peso;
                cout << "C�digo do Tutor: ";
                cin >> a[i].codigoTutor;
                i++;
            }
        }
    }
    contAnimalS = i - 1;
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
                cout << "Codigo do Cidade: ";
                cin >> t[i].codigoCidade;
                i++;
            }
        }
    }
    contTutorS = i - 1;
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
                cout << "C�digo da Cidade: ";
                cin >> v[i].codigoCidade;
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

    int i = 0;
    int saida = 1;
    while (i < T && saida != 0) {
        int cod;
        cout << "\nDigite as informa��es da " << (i + 1) << "� Consulta" << endl;
        cout << "Codigo: ";
        cin >> cod;

        if (cod <= 0) {
            saida = 0;
        } else if (codigoConsultaExiste(cons, i, cod)) {
            cout << "O c�digo " << cod << " j� foi inserido, por favor, insira um c�digo v�lido!";
        } else {
            cons[i].codigo = cod;
            if (cons[i].codigo > 0) {
                cout << "C�digo do Animal: ";
                cin >> cons[i].codigoAnimal;
                cout << "C�digo do Veterinario: ";
                cin >> cons[i].codigoVeterinario;
                cout << "Data da Consulta: ";
                cin >> cons[i].dataConsulta;
                cout << "Valor da Consulta: ";
                cin >> cons[i].valorConsulta;
                i++;
            }
        }
    }
    contConsultaS = i - 1;
}

// Definir as Impress�es das tabelas

void impressaoCidades(struct cidade c[], int contCidadeS) {
    cout << "\n\nLista dos Registros da tabela Cidades" << endl;
    for (int i = 0; i < contCidadeS; i++) {
        cout << "\nInforma��es da " << (i+1) << "� Cidade\n";
        cout << "\nC�digo: " << c[i].codigo << endl;
        cout << "\tCidade: " << c[i].nome << endl;
        cout << "\tUF: " << c[i].uf << endl;
    }
}

void impressaoRacas(struct raca r[], int contRacaS) {
    cout << "\n\nLista dos Registros da tabela Ra�as" << endl;
    for (int i = 0; i < contRacaS; i++) {
        cout << "\nInforma��es da " << (i+1) << "� Ra�a\n";
        cout << "\nC�digo: " << r[i].codigo << endl;
        cout << "\nDescri��o: " << r[i].descricao << endl;
    }
}

void impressaoTutores(struct tutor a[], int contTutorS) {
    cout << "\n\nLista dos Registros da tabela Tutores" << endl;
    for (int i = 0; i < contTutorS; i++) {
        cout << "\nInforma��es do " << (i+1) << "� tutor\n";
        cout << "\nC�digo: " << a[i].codigo << endl;
        cout << "\nNome: " << a[i].nome << endl;
        cout << "\nCPF: " << a[i].cpf << endl;
        cout << "\nEndere�o: " << a[i].endereco << endl;
        cout << "\nC�digo da Cidade: " << a[i].codigoCidade << endl;
    }
}

void impressaoAnimais(struct animal a[], int contAnimalS) {
    cout << "\n\nLista dos Registros da tabela Animais" << endl;
    for (int i = 0; i < contAnimalS; i++) {
        cout << "\nInforma��es do " << (i+1) << "� Animal\n";
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
        cout << "\nInforma��es do " << (i+1) << "� Veterin�rio\n";
        cout << "\nC�digo: " << a[i].codigo << endl;
        cout << "\nNome: " << a[i].nome << endl;
        cout << "\nEndere�o: " << a[i].endereco << endl;
        cout << "\nC�digo da Cidade: " << a[i].codigoCidade << endl;
    }
}

void impressaoConsultas(struct consulta a[], int contConsultaS) {
    cout << "\n\nLista dos Registros da tabela Consultas" << endl;
    for (int i = 0; i < contConsultaS; i++) {
        cout << "\nInforma��es da " << (i+1) << "� Consulta\n";
        cout << "\nC�digo: " << a[i].codigo << endl;
        cout << "\nC�digo do Animal: " << a[i].codigoAnimal << endl;
        cout << "\nC�digo do Veterin�rio: " << a[i].codigoVeterinario << endl;
        cout << "\nData da Consulta: " << a[i].dataConsulta << endl;
        cout << "\nValor da Consulta: " << a[i].valorConsulta << endl;
    }
}

//Busca se os c�digos (PK) ja existem

bool codigoCidadeExiste(struct cidade c[], int contCidadeS, int cod) {
    for (int i = 0; i < contCidadeS; i++) {
        if (c[i].codigo == cod) {
            return true;
        }
    }
    return false;
}

bool codigoRacaExiste(struct raca r[], int contRacaS, int cod) {
    for (int i = 0; i < contRacaS; i++) {
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
    for (int i = 0; i < contAnimalS; i++) {
        if (a[i].codigo == cod) {
            return true;
        }
    }
    return false;
}

bool codigoVeterinarioExiste(struct veterinario v[], int contVeterinarioS, int cod) {
    for (int i = 0; i < contVeterinarioS; i++) {
        if (v[i].codigo == cod) {
            return true;
        }
    }
    return false;
}

bool codigoConsultaExiste(struct consulta cons[], int contConsultaS, int cod) {
    for (int i = 0; i < contConsultaS; i++) {
        if (cons[i].codigo == cod) {
            return true;
        }
    }
    return false;
}

// Busca Binaria

bool buscaBinaria (struct cidade c[],int contCidadeS, int cod){
    int i = 0, f = contCidadeS;
    int m = (i + f) / 2;
    bool encontrado = false;
    for (; f > i && cod != c[m].codigo; m = (i + f) / 2){
        if (cod > c[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == c[m].codigo){
        return true;
    }
    else {
        return false;
    }
}
