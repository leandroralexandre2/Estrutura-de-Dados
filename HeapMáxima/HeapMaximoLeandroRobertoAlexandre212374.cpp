   #include <iostream>
   #include <vector>
   #include <algorithm>

    using namespace std;
// Fun��o que organiza o heap, garantindo que o n� pai tenha valor maior ou igual aos filhos

        void heapify(vector<int>& heap, int i, int n) {
            int esq = 2 * i + 1;
            int dir = 2 * i + 2;
            int largest = i;
            if (esq < n && heap[esq] > heap[largest]) {
             largest = esq;
           }
            if (dir < n && heap[dir] > heap[largest]) {
             largest = dir;
   }
            // Se o maior elemento n�o for o n� pai, faz a troca e continua a recurs�o para o filho trocado

            if (largest != i) {
              swap(heap[i], heap[largest]);
             heapify(heap, largest, n);
        }
            }
// Fun��o que constroi o heap a partir de um vetor, organizando todos os n�s pais

            void build_heap(vector<int>& heap) {
            int n = heap.size();
            for (int i = n / 2 - 1; i >= 0; i--) {
             heapify(heap, i, n);
 }
        }
// Fun��o que insere um elemento no heap e garante que ele mantenha a propriedade de m�ximo

            void heap_push(vector<int>& heap, int x) {
             heap.push_back(x);
            int i = heap.size() - 1;
            int parent = (i - 1) / 2;
            while (i > 0 && heap[parent] < heap[i]) {
               swap(heap[i], heap[parent]);
              i = parent;
             parent = (i - 1) / 2;
            }
 }
// Fun��o que retorna o maior elemento do heap

            int heap_topo(vector<int>& heap) {
            return heap[0];
        }
// Fun��o que extrai o maior elemento do heap e mant�m a propriedade de m�ximo

            void heap_pop(vector<int>& heap) {
            int n = heap.size() - 1;
               heap[0] = heap[n];
              heap.pop_back();
             heapify(heap, 0, n);
            }
// Fun��o que remove um elemento espec�fico do heap e mant�m a propriedade de m�ximo

            void heap_remove(vector<int>& heap, int x) {
            int n = heap.size();
            int i = find(heap.begin(), heap.end(), x) - heap.begin();
              heap[i] = heap[n - 1];
             heap.pop_back();
            if (i < n - 1) {
             heapify(heap, i, n - 1);
   }
            while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
              swap(heap[i], heap[(i - 1) / 2]);
             i = (i - 1) / 2;
        }
            }
// Fun��o que exibe os elementos do heap em n�veis

            void display_heap(vector<int>& heap) {
            int n = heap.size();
            int level = 0;
            int i = 0;
            while (i < n) {
            int end = min(i + (1 << level), n);
            for (int j = i; j < end; j++) {
             cout << heap[j] << " ";
   }
               cout << endl;
              i = end;
             level++;
        }
            }

            int main() {
             vector<int> heap;
            int n;
               cout << "Infome a quantidade de elementos? ";
              cin >> n;
             cout << "Informe a quantidade " << n << " de elementos escolhido:" << endl;
            for (int i = 0; i < n; i++) {
            int x;
              cin >> x;
             heap.push_back(x);
           }
             build_heap(heap);
            while (true) {
            cout << endl;
            cout << "Escolha uma opcao:" << endl;
            cout << "1- Inserir valor" << endl;
            cout << "2- Recuperar m�ximo" << endl;
            cout << "3- Extrair m�ximo" << endl;
            cout << "4- Remover valor" << endl;
            cout << "5- Exibir valores da heap:" << endl;
            cout << "6- SAIR" << endl;
            int op;
                 cin >> op;
            if (op == 1) {
            int x;
            cout << "Informe um valor: ";
            cin >> x;
               heap_push(heap, x);
            cout << "Valor inserido." << endl;
           } 
            else if (op == 2) {
            if (heap.empty()) {
                 cout << "Heap est� vazia." << endl;
    } 
            else {
                 cout << "Maximo: " << heap_topo(heap) << endl;
       }
           } 
            else if (op == 3) {
            if (heap.empty()) {
                 cout << "Heap est� vazia." << endl;
    } 
            else {
                  heap_pop(heap);
                 cout << "M�ximo extraido." << endl;
       }
           }
            else if (op == 4) {
            if (heap.empty()) {
                 cout << "Heap est� vazia." << endl;
    }
            else {
            int x;
                    cout << "Informe o valor a ser removido: ";
                   cin >> x;
                  heap_remove(heap, x);
                 cout << "Valor removido." << endl;
       }
           }
            else if (op == 5) {
                 display_heap(heap);
                              }
            else if (op == 6) {
            break;
    }
       }
           }

