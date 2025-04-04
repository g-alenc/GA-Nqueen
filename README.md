# Projeto de Algoritmo Genético para o Problema das N-Rainhas

## Introdução

Este projeto implementa um **Algoritmo Genético** para solucionar o famoso problema das n-rainhas, onde o objetivo é posicionar n rainhas em um tabuleiro de xadrez n × n de forma que nenhuma rainha ataque outra. O projeto é uma excelente introdução aos conceitos de algoritmos genéticos, aplicando técnicas de evolução para investigar soluções eficazes para problemas combinatórios clássicos.

O objetivo principal deste projeto é demonstrar como técnicas de inteligência computacional podem ser aplicadas para resolver problemas de otimização difíceis, destacando as capacidades de um algoritmo genético no equilibrar busca aleatória e sistemática.

## Prévias e Funcionalidades Principais

### Funcionalidades Principais

- **Inicialização Aleatória:** Geração de uma população inicial de soluções candidatas (indivíduos) de forma aleatória.
- **Avaliação do Fitness:** Cálculo da qualidade de cada solução com base no número de pares de rainhas em conflito.
- **Seleção por Torneio:** Escolha dos indivíduos mais bem-sucedidos para reprodução.
- **Crossover de Genes:** Combinação de pares de indivíduos para criar novos indivíduos que herdam características de ambos os pais.
- **Mutação:** Introdução de variações aleatórias nos indivíduos para manter a diversidade genética.
- **Elitismo:** Preservação dos melhores indivíduos para a próxima geração.

## Requisitos de Instalação

### Ambiente Necessário

- **Linguagem:** C++17 ou superior
- **Sistema Operacional:** Qualquer sistema com suporte ao compilador C++ (Windows, Linux, MacOS)

### Dependências

- **Compilador C++** (por exemplo, GCC ou Clang)
- **CMake** para a construção do projeto (opcional, se desejar construir o projeto de forma genérica e multiplataforma)

Para instalar as dependências no Ubuntu, você pode usar:

```bash
sudo apt update
sudo apt install g++ cmake
```

## Instruções de Uso

### Configuração e Execução

1. **Clone o repositório:**

   ```bash
   git clone https://github.com/g-alenc/GA-Nqueen.git
   cd GA-Nqueen
   ```

2. **Compile o projeto:**

   - Se usar apenas `g++`:

     ```bash
     g++ -o genetic_algorithm main.cpp src/*.cpp -I include
     ```

   - Se usar `CMake`:

     ```bash
     mkdir build
     cd build
     cmake ..
     make
     ```

3. **Execute o programa:**

   ```bash
   ./genetic_algorithm
   ```

### Exemplos de Uso

- Execute o programa e insira o tamanho desejado para o tabuleiro quando solicitado. As próximas gerações serão calculadas e exibidas diretamente no console.

## Hiperparâmetros do `GeneticAlgorithm`

### Configurações na `main`

- **`chromo_size` (Tamanho do Cromossomo):** 
  Representa o número de rainhas no tabuleiro e, simultaneamente, o tamanho do tabuleiro (N x N). Cada cromossomo do algoritmo genético é uma representação de uma solução potencial para o problema das n-rainhas.

- **`pop_size` (Tamanho da População):** 
  Define quantos indivíduos haverá em cada geração. Um tamanho maior de população pode aumentar a diversidade genética, potencialmente resultando em uma exploração mais ampla do espaço de solução, mas também exige mais recursos computacionais.

- **`mut_rate` (Taxa de Mutação):** 
  Determina a probabilidade com que uma mutação ocorre em um indivíduo. Mutação introduz variabilidade genética e pode ajudar a escapar de mínimos locais. Um valor de 0.9 indica que há uma alta probabilidade de mutar elementos dentro do cromossomo.

- **`gens` (Número de Gerações):**
  Especifica quantas vezes o algoritmo genético deve evoluir as gerações antes de parar. Um número maior de gerações pode oferecer uma oportunidade melhor para encontrar uma solução ótima, mas ao custo de tempo computacional.

- **`elite_rate` (Taxa de Elitismo):** 
  Define a proporção dos melhores indivíduos de cada geração que serão diretamente copiados para a próxima geração sem sofrerem crossover ou mutação. Isso assegura que as melhores soluções são preservadas ao longo das iterações. Um valor de 0.1 significa que 10% da população mais bem sucedida será automaticamente transferida para a próxima geração.

```cpp
int pop_size = 100;           // Tamanho da população
int chromo_size = 12;         // Tamanho do tabuleiro e do cromossomo
double mut_rate = 0.9;        // Taxa de mutação
int gens = 200;               // Número de gerações
double elite_rate = 0.1;      // Taxa de elitismo
```
