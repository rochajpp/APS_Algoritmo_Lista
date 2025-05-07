#include<iostream>
#include<locale.h>

using namespace std;

// Classe de N�s
struct node {
	// Valor do n�
	int value;
	
	// Ponteiro que ir� apontar para o pr�ximo da lista
	// O * quer dizer que essa vari�vel ir� apontar para o local de mem�ria que passarmos, ou seja literalmente apontar
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
	
		
	// next armazena a localiza��o da mem�ria de n1 no caso
	// Quando escrevemso n2.next estamos com essa localiza��o, mas caso quisermos ver dentro da localiza��o ou seja ter acesso ao n� dessa localiza��o
	// Usamos * antes da express�o pra definir que queremos o valor dentro desta localiza��o
	// n2.next mostra a localiza��o de mem�ria
	// *n2.next mostra o n�
	// Agora que estamos no com o n� usando o *n2.next, se quisermos acessar seu valor, escrevemos .value
	// O parentese � importante para ele separar a obten��o do n� da captura do valor desse n�
	// Dentro do parentese temos um n� e agora damos .value para pegar o valor
	
	// Quando ele ler o parentese ele ir� interpretar queremos o conte�do de n2.next, que � o n� n1
	// e quando ler resto que no caso � o .value ele vai entender e quer o value desse conte�do
	
	// O parentese representa o n� que n2.next est� apontando
	
	cout << "Localiza��o na mem�ria: " << n2.next << endl;
	cout << "Valor do n�: " << (*n2.next).next << endl;
	
	if((*n1.next).value == NULL){
		cout << "� null" << endl;
	}
}
