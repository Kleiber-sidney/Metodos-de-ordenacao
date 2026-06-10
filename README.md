## Comparador de Algoritmos de Ordenação em C++

Este projeto é uma aplicação desenvolvida em C++ que visa analisar, medir e comparar visualmente o desempenho de diferentes algoritmos de ordenação (Sorting Algorithms). O programa mede o tempo de execução e a quantidade de trocas de cada método, gerando um gráfico de barras diretamente no terminal para comparação.

## Funcionalidades

O programa conta com um menu interativo que permite:
1. Preenchimento Manual: Inserir valores um a um no vetor.
2. Preenchimento Aleatório: Gerar um vetor de tamanho customizado com números gerados aleatoriamente (suporta grande quantidade de dados).
3. Algoritmos de Ordenação Implementados:
    Bubble Sort
    Selection Sort
    Insertion Sort
    Quick Sort
4. Contador de tempo e trocas: Exibe o tempo exato gasto na ordenação (em segundos) e a quantidade total de trocas de posições realizadas.
5. Gráfico de Tempo: Gera um gráfico de barras comparativo com base nos tempos registrados por cada algoritmo.
6. Embaralhar vetor: Embaralha o vetor sem a necessidade de criar um novo vetor.

## Exemplo de Saída do Gráfico

Quando a opção de gerar o gráfico é selecionada, o terminal exibe uma comparação proporcional parecida com esta:

## Tecnologias Utilizadas

Linguagem: C++
Bibliotecas Padrão: <stdio.h>, <stdlib.h>, <time.h>, <conio.h>
