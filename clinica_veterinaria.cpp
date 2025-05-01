#include <iostream>
#define T 3

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
    char cpf[14];
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

int main () {

    // Definição dos vetores
    cidade cidades[T];
    raca racas[T];
    animal animais[T];
    tutor tutores[T];
    veterinario veterinarios[T];
    consulta consultas[T];

    //Definição dos Contadores
    int contCidadeS;
    int contRacaS;
    int contAnimalS, contAnimalT, contAnimalA;
    int contTutorS, contTutorT, contTutorA;
    int contVeterinarioS;
    int contConsultaS;
}

//Exercicio 1 (Leituras)

void leituraCidades(struct cidade c[], int &contCidadeS) {
    int i = 0;
    for (int saida = 1; i < T && saida != 0; i++) {
        cout << "\nDigite as informações da " << (i + 1) << "º cidade" << endl;
        cout << "Codigo: ";
        cin >> c[i].codigo;
        cin.ignore();
        if (c[i].codigo > 0) {
            cout << "Nome: ";
            cin >> c[i].nome;
            cin.ignore();
            cout << "Unidade Federal [UF]: ";
            gets(c[i].uf);
        } else {
            saida = 0;
        }
    }
    contCidadeS = i - 1;
}

void leituraRacas(struct raca r[], int &contRacaS) {
    int i = 0;
    for (int saida = 1; i < T && saida != 0; i++) {
        cout << "\nDigite as informações da " << (i + 1) << "º raça" << endl;
        cout << "Codigo: ";
        cin >> r[i].codigo;
        cin.ignore();
        if (r[i].codigo > 0) {
            cout << "Descricao: ";
            cin >> r[i].descricao;
            cin.ignore();
        } else {
            saida = 0;
        }
    }
    contRacaS = i - 1;
}

void leituraAnimais(struct animal a[], int &contAnimalS) {
    int i = 0;
    for (int saida = 1; i < T && saida != 0; i++) {
        cout << "\nDigite as informações do " << (i + 1) << "º animal" << endl;
        cout << "Codigo: ";
        cin >> a[i].codigo;
        cin.ignore();
        if (a[i].codigo > 0) {
            cout << "Nome: ";
            cin >> a[i].nome;
            cin.ignore();
            cout << "Codigo da Raca: ";
            cin >> a[i].codigoRaca;
            cin.ignore();
            cout << "Idade: ";
            cin >> a[i].idade;
            cin.ignore();
            cout << "Peso: ";
            cin >> a[i].peso;
            cin.ignore();
            cout << "Código do Tutor: ";
            cin >> a[i].codigoTutor;
            cin.ignore();
        } else {
            saida = 0;
        }
    }
    contAnimalS = i - 1;
}

void leituraTutores(struct tutor t[], int &contTutorS) {
    int i = 0;
    for (int saida = 1; i < T && saida != 0; i++) {
        cout << "\nDigite as informações do " << (i + 1) << "º tutor" << endl;
        cout << "Codigo: ";
        cin >> t[i].codigo;
        if (t[i].codigo > 0) {
            cout << "Nome: ";
            cin >> t[i].nome;
            cin.ignore();
            cout << "CPF: ";
            gets(t[i].cpf);
            cin.ignore();
            cout << "Endereco: ";
            cin >> t[i].endereco;
            cin.ignore();
            cout << "Codigo do Cidade: ";
            cin >> t[i].codigoCidade;
            cin.ignore();
        } else {
            saida = 0;
        }
    }
    contTutorS = i - 1;
}

void leituraVeterinarios(struct veterinario v[], int &contVeterinarioS) {
    int i = 0;
    for (int saida = 1; i < T && saida != 0; i++) {
        cout << "\nDigite as informações do " << (i + 1) << "º veterinario" << endl;
        cout << "Codigo: ";
        cin >> v[i].codigo;
        cin.ignore();
        if (v[i].codigo > 0) {
            cout << "Nome: ";
            cin >> v[i].nome;
            cin.ignore();
            cout << "Endereço: ";
            cin >> v[i].endereco;
            cin.ignore();
            cout << "Código da Cidade: ";
            cin >> v[i].codigoCidade;
            cin.ignore();
        } else {
            saida = 0;
        }
    }
    contVeterinarioS = i - 1;
}

void leituraConsultas(struct consulta c[], int &contConsultaS) {
    int i = 0;
    for (int saida = 1; i < T && saida != 0; i++) {
        cout << "\nDigite as informações da " << (i + 1) << "º consulta" << endl;
        cout << "Codigo: ";
        cin >> c[i].codigo;
        cin.ignore();
        if (c[i].codigo > 0) {
            cout << "Código do Animal: ";
            cin >> c[i].codigoAnimal;
            cin.ignore();
            cout << "Código do Veterinario: ";
            cin >> c[i].codigoVeterinario;
            cin.ignore();
            cout << "Data da Consulta: ";
            cin >> c[i].dataConsulta;
            cin.ignore();
            cout << "Valor da Consulta: ";
            cin >> c[i].valorConsulta;
            cin.ignore();
        } else {
            saida = 0;
        }
    }
    contConsultaS = i - 1;
}