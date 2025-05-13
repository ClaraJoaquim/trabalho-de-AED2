# 🐾 Clínica Veterinária - Arquivos Sequenciais (C++)

Este projeto foi desenvolvido como parte da disciplina de **Algoritmos e Estruturas de Dados II** do curso de Análise e Desenvolvimento de Sistemas - FEMA, com o objetivo de simular uma aplicação de controle de uma Clínica Veterinária utilizando **estruturas que representam arquivos sequenciais**.

---

## 📘 Descrição do Projeto

O programa implementa estruturas de dados e funcionalidades necessárias para gerenciar uma clínica veterinária, utilizando **arrays simulando arquivos sequenciais**, com suporte para:

- Cidades
- Raças
- Animais
- Tutores
- Veterinários
- Consultas

As informações são manipuladas por meio de menus e armazenadas em tempo de execução, com foco na lógica e organização de dados sequenciais.

---

## 📂 Estruturas Criadas

| Tabela       | Atributos                                                                 |
|--------------|---------------------------------------------------------------------------|
| Cidades      | `código (PK)`, `nome`, `UF`                                               |
| Raças        | `código (PK)`, `descrição`                                                |
| Animais      | `código (PK)`, `nome`, `código da raça`, `idade`, `peso`, `código tutor`  |
| Tutores      | `código (PK)`, `nome`, `CPF`, `endereço`, `código da cidade`              |
| Veterinários | `código (PK)`, `nome`, `endereço`, `código da cidade`                     |
| Consultas    | `código (PK)`, `código animal`, `código veterinário`, `data`, `valor`     |

---

## 🔧 Funcionalidades

### 1. Leitura de Dados
- Leitura e cadastro para todas as entidades da aplicação.

### 2. Inclusão de Novos Tutores
- Validação automática do CPF.
- Busca e exibição de nome e UF da cidade vinculada.

### 3. Inclusão de Novos Animais
- Busca e exibição da raça.
- Busca e exibição do nome do tutor e da cidade correspondente.

### 4. Consultas
- Código gerado automaticamente de forma sequencial.
- Exibição completa de dados do animal, tutor, raça, veterinário e cidade.
- Entrada da data da consulta (com validação) e valor.

### 5. Consultas por Intervalo de Datas

- Exibe todas as consultas realizadas dentro de um intervalo.
- Exibe: nome do animal, nome do veterinário, data e valor da consulta.
- Soma e exibe o valor total das consultas no período.
- Validação completa da data, incluindo **formato** e **verificação de ano bissexto**.

### 6. Consultas por Intervalo de Datas e Veterinário

- Filtra as consultas por veterinário e período.
- Exibe os mesmos dados da funcionalidade anterior.
- Soma e exibe o valor total das consultas no período.
- Validação completa da data, incluindo **formato** e **verificação de ano bissexto**.

---

## 📋 Menu Principal

Todas as funcionalidades podem ser acessadas através de um menu interativo exibido na função `main()`.  
O código **não utiliza variáveis globais**.

---

## 📎 Observações

- Toda a lógica foi implementada utilizando **arrays como arquivos sequenciais**.
- Validção de CPF.
- A manipulação de datas foi feita utilizando `time_t` e `strftime()` com entrada no formato `dd/MM/yyyy`.
- Validação completa da data, incluindo **formato** e **verificação de ano bissexto**.
- Menus simples e intuitivos com tratamento de erros.

---

## 👩‍💻 Desenvolvido por

👥 GitHub:
- [Clara Joaquim](https://github.com/ClaraJoaquim)
- [Yann Garcia](https://github.com/YannPG)
