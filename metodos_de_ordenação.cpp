#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

float vetor[100000];
int Qtd = 0;
int trocas = 0;

double tempoBubble = 0;
double tempoSelection = 0;
double tempoInsertion = 0;
double tempoQuick = 0;

int imprimeMenu() {
  system("cls");
  printf("\n ======= EXERCICIO DE ORDENACAO ======== ");
  printf("\n =  1: Preencher o Vetor               = ");
  printf("\n =  2: Limpar o Vetor                  = ");
  printf("\n =  3: Imprimir o Vetor                = ");
  printf("\n =  4: Ordenar Buble Sort              = ");
  printf("\n =  5: Ordenar Selection Sort          = ");
  printf("\n =  6: Ordenar Insertion Sort          = ");
  printf("\n =  7: Ordenar Quick Sort              = ");
  printf("\n =  8: Preencher Vetor Aleatoriamente  = ");
  printf("\n =  9: Gerar Grafico                   = ");
  printf("\n = 10: Embaralhar Vetor                = ");
  printf("\n = 11: Sair                            = ");
  printf("\n Informe a opcao desejada: ");
  int resposta;
  scanf("%i", &resposta);
  return(resposta);
}

void vetorAleatorio(int Tamanho){
  for (int i=0; i<Tamanho; i++)
    vetor[i] = (rand() %100000);                            
  printf("\n %i numeros gerados",Tamanho); 
  Qtd = Tamanho;                                         
}

void EmbaralharVetor() {
  for (int i = Qtd - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
  }
  printf("\n Vetor embaralhado");
  getch();
}

void bubbleSort() {
  trocas = 0;
  clock_t inicio = clock();
  float aux;
  for (int i=0; i<Qtd-1; i++)
    for (int j=0; j<Qtd-1 -i; j++)
      if (vetor[j] > vetor[j+1]) {
        aux = vetor[j];
        vetor[j] = vetor[j+1];
        vetor[j+1] = aux;
        trocas++;
      }
  clock_t fim = clock();
  
  tempoBubble = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
  printf("tempo gasto: %f segundos\n", tempoBubble);
  printf("trocas: %i\n", trocas);
  getch();
}

void selectionSort() {
  trocas = 0;
  clock_t inicio = clock();
  float aux;
  for (int i=0; i<Qtd-1; i++)
    for (int j=i+1; j<Qtd; j++)
      if (vetor[j] < vetor[i]) {
        aux = vetor[j];
        vetor[j] = vetor[i];
        vetor[i] = aux;
        trocas++;
      }
  clock_t fim = clock();
  
  tempoSelection = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
  printf("tempo gasto: %f segundos\n", tempoSelection);
  printf("trocas: %i\n", trocas);
  getch();
}

void insertionSort() {
  trocas = 0;
  clock_t inicio = clock();
  int i, j;
  float aux;
    for (i=1; i<Qtd; i++) {
        aux = vetor[i];
        j = i-1;
        while (j>=0 && vetor[j]>aux) {
            vetor[j+1] = vetor[j];
            j=j-1;
            trocas++;
        }
        vetor[j+1] = aux;
    }
  clock_t fim = clock();
  
  tempoInsertion = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
  printf("tempo gasto: %f segundos\n", tempoInsertion);
  printf("trocas: %i\n", trocas);
  getch();
}

void quicksort_ord (int inicio, int final) {
    if (inicio < final) {
        float pivo = vetor[final];
        int i = (inicio - 1);
        float aux;
        for (int j = inicio; j < final; j++) {
            if (vetor[j] < pivo) {
            i++;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            trocas++;
            }
        }
    aux = vetor[i +  1];
    vetor[i + 1] = vetor[final];
    vetor[final] = aux;
    trocas++;
    
    quicksort_ord(inicio, i);
    quicksort_ord(i + 2, final);
    }
}

void quickSort() {
  trocas = 0;
  clock_t inicio = clock();
  
  quicksort_ord(0, Qtd - 1);
  
  clock_t fim = clock();
  
  tempoQuick = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
  printf("tempo gasto: %f segundos\n", tempoQuick);
  printf("trocas: %i\n", trocas);
  getch();
}

void limparVetor() {
  for (int i=0; i<Qtd; i++)
    vetor[i] = 0;
  printf("Vetor zerado\n");
}

void imprimirVetor() {
  printf("\n Dados do Vetor: \n");
  for (int i=0; i<Qtd; i++)
    if (i==Qtd-1)
      printf("%.2f ", vetor[i]);
    else
      printf("%.2f, ", vetor[i]);
  getch();
}

void gerarGrafico() {
  printf("\n ======= GRAFICO DE TEMPO DE ORDENACAO ======== \n");

  double tempos[4] = {tempoBubble, tempoSelection, tempoInsertion, tempoQuick};
  char nomes[4][20] = {"Bubble Sort   ", "Selection Sort", "Insertion Sort", "Quick Sort    "};
  double maiorTempo = 0;

  for(int i=0; i<4; i++) {
    if(tempos[i] > maiorTempo) {
      maiorTempo = tempos[i];
    }
  }

  if (maiorTempo == 0) {
    printf("Nenhum tempo registrado");
    getch();
    return;
  }

  int maxBarras = 50; 
  for(int i=0; i<4; i++) {
    printf(" %s | ", nomes[i]);
    
    int qtdBarras = (int)((tempos[i] / maiorTempo) * maxBarras);
    if(tempos[i] > 0 && qtdBarras == 0) {
        qtdBarras = 1;
    }
    for(int b = 0; b < qtdBarras; b++) {
        printf("%c", 219); 
    }
    printf(" %.4f s\n", tempos[i]);
  }
  getch();
}

int main() {
  char menu;
  int resposta;
  do {
    resposta = imprimeMenu();
    
    if (resposta == 1) {
      do {
        printf("Insira o %i. valor no vetor: ", Qtd+1);
        scanf("%f", &vetor[Qtd]);
        Qtd+=1;
        printf("Deseja inserir mais um valor? (S/N): ");
        scanf("%s", &menu);
       } while (menu == 'S' || menu == 's'); 
    }
    else if (resposta == 2)
      limparVetor();
    else if (resposta == 3)
      imprimirVetor();
    else if (resposta == 4)
      bubbleSort();
    else if (resposta == 5)
      selectionSort();
    else if (resposta == 6)
      insertionSort();
    else if (resposta == 7)
      quickSort();
    else if (resposta == 8) {
      printf("Informe o tamanho do vetor que deseja criar: ");
      int Tamanho;
      scanf("%i", &Tamanho);
      vetorAleatorio(Tamanho);
    }
    else if (resposta == 9) 
      gerarGrafico();
    else if (resposta == 10) 
      EmbaralharVetor();
  } while (resposta < 11);
  
  return 0;
}
