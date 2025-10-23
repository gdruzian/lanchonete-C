# 🍔 Sistema de Gerenciamento de Lanchonete em C

Este é um projeto simples de um sistema de gerenciamento de pedidos para uma lanchonete, desenvolvido inteiramente em linguagem C como parte de um curso de programação. O objetivo é aplicar conceitos fundamentais da linguagem, incluindo structs, vetores, funções e manipulação de arquivos para persistência de dados.

## 📝 Descrição

O programa simula o gerenciamento básico de uma lanchonete, permitindo:

* Cadastrar os produtos oferecidos.
* Cadastrar os clientes.
* Registrar os pedidos realizados pelos clientes.
* Listar todos os produtos, clientes e pedidos.
* Salvar e carregar todas as informações em arquivos de texto (`.txt`), garantindo que os dados persistam entre as execuções do programa.

## ✨ Funcionalidades

* **Cadastro de Produtos:** Permite adicionar novos produtos ao cardápio (Código, Nome, Preço).
* **Cadastro de Clientes:** Permite registrar novos clientes (Código, Nome).
* **Realizar Pedido:** Permite registrar um novo pedido, vinculando um cliente a um produto e especificando a quantidade. O sistema valida se o cliente e o produto existem.
* **Listagem de Produtos:** Exibe todos os produtos cadastrados.
* **Listagem de Clientes:** Exibe todos os clientes cadastrados.
* **Listagem de Pedidos:** Exibe todos os pedidos registrados.
* **Persistência de Dados:** Salva automaticamente os dados de produtos, clientes e pedidos nos arquivos `produtos.txt`, `clientes.txt` e `pedidos.txt`. Os dados são carregados automaticamente ao iniciar o programa.

## ⚙️ Como Compilar e Executar

1.  **Pré-requisitos:** Você precisa ter um compilador C instalado no seu sistema (como o GCC, que é o mais comum em Linux e pode ser instalado no Windows via MinGW ou WSL).
2.  **Compilação:** Abra o terminal na pasta onde você salvou o arquivo `.c` (vamos supor que ele se chame `lanchonete.c`) e execute o comando:
    ```bash
    gcc lanchonete.c -o lanchonete 
    ```
    Isso criará um arquivo executável chamado `lanchonete` (ou `lanchonete.exe` no Windows).
3.  **Execução:**
    * No Linux/Mac:
        ```bash
        ./lanchonete
        ```
    * No Windows:
        ```bash
        lanchonete.exe 
        ```
    Ou simplesmente:
        ```bash
        lanchonete
        ```
4.  **Uso:** Siga as opções apresentadas no menu do programa.

## 📁 Estrutura de Arquivos

O programa utiliza os seguintes arquivos de texto para armazenar os dados (eles são criados/atualizados automaticamente na mesma pasta do executável):

* `produtos.txt`: Contém os dados dos produtos, separados por ponto e vírgula (`;`).
* `clientes.txt`: Contém os dados dos clientes, separados por ponto e vírgula (`;`).
* `pedidos.txt`: Contém os dados dos pedidos, separados por ponto e vírgula (`;`).

## 👨‍💻 Autor

Gustavo Druzian

## 🎓 Contexto

Este projeto foi desenvolvido como exercício final do curso Lógica de Programação e Algoritmos com C ministrado por Gustavo Caetano.

---
