#include <iostream>

using namespace std;
main() {
	setlocale(LC_ALL, "portuguese");


int opcao;
int n;
int const maxtam = 15;
int lista[maxtam];
int tras = -1;
int frente = 0;
int valor;
int i;
int posi;
int auxiliar;
int j;
int tam;

//opcao=0;

	for(i=0;i<=tras;i++){
		cout<<" ["<<lista[i]<<"]"<<endl;}
	while((opcao!=8)){
	
cout<<"ESCOLHA NO MENU A BAIXO A OP��O DA A��O DESEJADA: "<<endl;
//menu
cout<<"----------------| MENU |-------------------"<<endl;
cout<<"| DIGITE 0 PARA INSERIR NO INICIO         |"<<endl;
cout<<"| DIGITE 1 PARA INSERIR NO MEIO           |"<<endl;
cout<<"| DIGITE 2 PARA INSERIR NO FIM     	  | "<<endl;
cout<<"| DIGITE 3 PARA REMOVER DO INICIO  	  | "<<endl;
cout<<"| DIGITE 4 PARA REMOVER DO FIM            | "<<endl;
cout<<"| DIGITE 5 PARA ORDENAR A LISTA           |"<<endl;
cout<<"| DIGITE 6 PARA BUSCAR UM ELEMENTO A LISTA|"<<endl;
cout<<"| DIGITE 7 PARA MOSTRAR A LISTA COMPLETA  |"<<endl;
cout<<"| DIGITE 8 PARA SAIR			  |"<<endl;
cout<<"--------------------------------------------"<<endl;
cin>>opcao;


// INSERIR NO INICIO
if(opcao == 0) {

	cout<<"DIGITE O VALOR PARA INSERIR: "<<endl;
	cin>>valor;

    for (int i = tras+1; i > frente; i--) {
			lista[i] = lista[i-1];}
			lista[frente] = valor;
			tras++;
			}
	cout<<"RESULTADO: "<<endl;
	n=i;
	 for(int i=0;i<=tras;i++){
		cout<<lista[i];
		cout<<endl;
	}

// INSERIR NO MEIO
if(opcao == 1){
	int posi;

	posi = 0;
	cout<<"DIGITE O VALOR PARA INSERIR NO MEIO: "<<endl;
	cin>>valor;
   if ((posi>frente)&&(posi<tras)) {
   	for (int i = tras+1; i>posi; i--){
   		lista[i] = lista[i-1];}
   		lista[posi]=valor;
   		tras++;
	   }
   }

// INSERIR NO FIM
if(opcao == 2){
  
	posi = 0;
	cout<<"DIGITE O VALOR PARA INSERIR NO FIM: "<<endl;
	cin>>valor;
	tras++;
	lista[tras]=valor;
   }
	


// REMOVER DO INICIO
if(opcao == 3){
valor=lista[frente];
for (int i=frente; i < tras; i++){
	lista[i]=lista[i+1];
}
tras--;
	
}

// REMOVER DO FIM
if(opcao == 4){
	valor = lista[tras];
	tras--;
	
}

// ORDENAR
if (opcao == 5){

             tam = (tras-frente)+1;
			for( i=0; i<tam;i++){
				for( j=i+1; j<tam; j++){
					if(lista[i]>lista[j]){
						auxiliar = lista[i];
						lista[i] = lista[j];
						lista[j] = auxiliar;
					}
				}
				
			}
			cout<<"Vetor Ordenado!\n";
			
}
// BUSCAR UM ELEMENTO A LISTA
if(opcao == 6){
	cout<<"DIGITE O VALOR BUSCAR: "<<endl;
	cin>>valor;
	
	int achou=0;
	tras = lista[-1];
	frente = lista[0];
	posi=(frente+tras)/2;
  int elementosexcluidos;
	
	while((frente<tras)&&(achou==0)){
		if(lista[posi]==valor){
			achou=1;
			
		}
		else if(lista[posi]<valor){
				elementosexcluidos = (posi+1) - frente;
				frente=posi+1;
				posi=(frente+tras)/2;
				cout<<"Exclu�dos: "<<elementosexcluidos<<endl;
				
			}
			else{
				elementosexcluidos =tras - (posi-1);
				tras=posi-1;
				posi=(frente+tras)/2;
				cout<<"Exclu�dos: "<<elementosexcluidos<<endl;
			}
			
		}
	if(achou==0){
		cout<<"N�mero "<<valor<<" n�o encontrado"<<endl;
	}	
	else{
		cout<<"N�mero "<<valor<<" encontrado com sucesso, na posi��o: "<<posi<<endl;
	}
	
}
// MOSTRAR A LISTA COMPLETA
if(opcao == 7){
		cout<<"Lista:";
	for(int i=0;i<=tras;i++){
		cout<<" ["<<lista[i]<<"]";
	}	
}


}
}


