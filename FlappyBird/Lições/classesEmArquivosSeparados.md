# Lição: Como Chamar Funções Membro em C++

Neste guia, vamos esclarecer a diferença entre **instanciar** um objeto e **chamar** uma função membro (ou método) em C++, um conceito fundamental para a programação orientada a objetos.

## A Diferença: Instanciar vs. Chamar

É fácil confundir os termos, mas a ideia é simples:

- **Instanciar**: É o ato de **criar um objeto** a partir de uma "planta" (a `class`). Quando você cria uma variável do tipo da sua classe, você está instanciando um objeto.

- **Chamar**: É o ato de **executar uma função** que pertence a um objeto que já foi criado.

A regra é: **Primeiro você instancia, depois você chama.**

---

## Método 1: Acesso Direto com o Operador Ponto (`.`)

Use o operador ponto (`.`) quando você tem o objeto diretamente. Esta é a forma mais comum.

### Sintaxe

```cpp
NomeDaClasse nomeDoObjeto; // 1. Instanciação do objeto

nomeDoObjeto.nomeDaFuncao(); // 2. Chamada da função membro
```

### Exemplo

```cpp
#include "FBird.hpp"

int main() {
    // 1. Instanciamos um objeto 'jogo' da classe 'FBird'
    FBird jogo;

    // 2. Usamos o operador '.' para chamar a função 'run' do objeto 'jogo'
    jogo.run();

    return 0;
}
```

---

## Método 2: Acesso por Ponteiro com o Operador Seta (`->`)

Use o operador seta (`->`) quando você tem um **ponteiro** para um objeto. Isso é comum quando você aloca memória dinamicamente com `new`.

### Sintaxe

```cpp
NomeDaClasse* ponteiroParaObjeto = new NomeDaClasse(); // 1. Instanciação e obtenção de um ponteiro

ponteiroParaObjeto->nomeDaFuncao(); // 2. Chamada da função membro através do ponteiro

delete ponteiroParaObjeto; // IMPORTANTE: Sempre libere a memória alocada com 'new'!
```

### Exemplo

```cpp
#include "FBird.hpp"

int main() {
    // 1. Instanciamos um objeto 'FBird' na memória heap e guardamos seu endereço no ponteiro 'jogoPtr'
    FBird* jogoPtr = new FBird();

    // 2. Usamos o operador '->' para chamar a função 'run' do objeto apontado por 'jogoPtr'
    jogoPtr->run();

    // 3. Liberamos a memória para evitar memory leaks
    delete jogoPtr;

    return 0;
}
```

---

## Resumo

| Situação | Operador | Exemplo |
| :--- | :---: | :--- |
| Você tem o objeto | Ponto (`.`) | `meuObjeto.minhaFuncao();` |
| Você tem um ponteiro para o objeto | Seta (`->`) | `meuPonteiro->minhaFuncao();` |

Lembrar dessa diferença vai te ajudar a escrever um código C++ mais limpo e correto