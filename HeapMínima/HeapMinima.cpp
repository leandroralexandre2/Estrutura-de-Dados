#include <iostream>
#include <vector>
#include <algorithm>
#include <locale.h>
using namespace std;
// cria minimo heapify
void minimoHeapify(vector<int>& heap, int i) {
    int esquerdo = 2*i+1;
    int direita = 2*i+2;
    int menor = i;

    if (esquerdo < heap.size() && heap[esquerdo] < heap[menor]) {
        menor = esquerdo;
    }

    if (direita < heap.size() && heap[direita] < heap[menor]) {
        menor = direita;
    }

    if (menor != i) {
        swap(heap[i], heap[menor]);
        minimoHeapify(heap, menor);
    }
}
// cria minimo heap
void minimoHeap(vector<int>& heap) {
    for (int i = heap.size() / 2-1; i>=0; i--) {
        minimoHeapify(heap, i);
    }
}
// inclui valor ao vetor

// obtem o valor minimo do vetor
int obterMinimo(vector<int>& heap) {
    return heap[0];
}
void incluirValor(vector<int>& heap, int chave) {
    heap.push_back(chave);
    int i = heap.size() - 1;

    while (i > 0 && heap[(i-1) /2] > heap[i]) {
        swap(heap[(i-1) / 2], heap[i]);
        i = (i-1) / 2;
    }
}

// tira o valor do veto
void tirarValor(vector<int>& heap, int i) {
    heap[i] = heap.back();
    heap.pop_back();
    minimoHeapify(heap, i);
}

// mostra o heap
void heapMostrar(vector<int>& heap) {
    int level =1;
    int cont =0;

    for (int i = 0; i < heap.size(); i++) {
        cout<< heap[i]<< " ";
        cont++;

        if (cont == level) {
            cout<< endl;
            cont =0;
            level *= 2;
        }
    }
    cout<<endl;
}
// extracao do minimo
int extrairMinimo(vector<int>& heap) {
    int min = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    minimoHeapify(heap, 0);
    return min;
}


int main() 
{
setlocale(LC_ALL, "Portuguese");	
vector<int> heap;
int qtde, chave;

cout<<"Informe a quantidade de valores: ";
cin>>qtde;
cout<<"Informe os valores: ";
  for (int i = 0; i < qtde; i++) {
   cin>>chave;
   heap.push_back(chave);}

minimoHeap(heap);

  int escolha;
    do {
    cout <<"Informe a escolha de opera��o:\n\n "
         <<"| 1- INSER��O DE VALOR\n"
         <<"| 2- RECUPERAR M�NIMO\n"
         <<"| 3- EXTRAIR M�NIMO\n"
         <<"| 4- REMO��O DE VALOR\n"
         <<"| 5- EXIBI��O DOS VALORES DA HEAP\n\n"
         <<"| 6- SAIR\n";
        
		cin>>escolha;

        switch (escolha) {
         case 1:
        cout<<"[ESCOLHA 1]"<<endl;
        cout<<"Informe o valor para inser��o: "<<endl;
        cin>>chave;
        incluirValor(heap, chave);
        break;
        
        case 2:
       	cout<<"[ESCOLHA 2]"<<endl;
        cout<<"O M�nimo �: "<<obterMinimo(heap)<<endl;
        break;
        
        case 3:
		cout<<"[ESCOLHA 3]"<<endl;
        cout<<"Extra��o do M�nimo: "<<extrairMinimo(heap)<<endl;
        break;
        
        case 4:
       	cout<<"[ESCOLHA 4]"<<endl;
        cout<<"Informe o �ndice do valor para remova��o: "<<endl;
        cin>>chave;
        tirarValor(heap, chave);
        break;
        
        case 5:
       	cout<<"[ESCOLHA 5]"<<endl;
        heapMostrar(heap);
        break;
        
        case 6:
       	cout<<"[ESCOLHA 6]"<<endl;
        break;
            default:
                cout<<"Escolha inv�lida!"<<endl;
            break;
        }
    } while (escolha != 6);
    cout<<"Fim da Opera��o!!!";
   
 return 0;
}
