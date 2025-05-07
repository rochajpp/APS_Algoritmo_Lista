#include<iostream>
#include<locale.h>

using namespace std;

// Classe de Nós
struct node {
	// Valor do nó
	int value;
	
	// Ponteiro que irá apontar para o próximo da lista
	// O * quer dizer que essa variável irá apontar para o local de memória que passarmos, ou seja literalmente apontar
	struct node *next;
};

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	node n1;
	n1.value = 10;
	n1.next = NULL;
	
	node n2;
	n2.value = 20;
	n2.next = &n1;  
	
		
	// next armazena a localização da memória de n1 no caso
	// Quando escrevemso n2.next estamos com essa localização, mas caso quisermos ver dentro da localização ou seja ter acesso ao nó dessa localização
	// Usamos * antes da expressão pra definir que queremos o valor dentro desta localização
	// n2.next mostra a localização de memória
	// *n2.next mostra o nó
	// Agora que estamos no com o nó usando o *n2.next, se quisermos acessar seu valor, escrevemos .value
	// O parentese é importante para ele separar a obtenção do nó da captura do valor desse nó
	// Dentro do parentese temos um nó e agora damos .value para pegar o valor
	
	// Quando ele ler o parentese ele irá interpretar queremos o conteúdo de n2.next, que é o nó n1
	// e quando ler resto que no caso é o .value ele vai entender e quer o value desse conteúdo
	
	// O parentese representa o nó que n2.next está apontando
	
	cout << "Localização na memória: " << n2.next << endl;
	cout << "Valor do nó: " << (*n2.next).next << endl;
	
	if((*n1.next).value == NULL){
		cout << "É null" << endl;
	}
}
