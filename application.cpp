#include<iostream>
#include<locale.h>
#include<stdlib.h>

using namespace std;

struct node{
	int pass;
	char urgency; //a = Alto; m = Medio; b = Baixa
	struct node *next;
};

int quantNode = 0;
node *firstNode;

void Insert(int pass, char type){
	node *newNode = new struct node;
	(*newNode).pass = pass;
	(*newNode).urgency = type;
	
	if(quantNode <= 0){
		(*newNode).next = NULL;
		firstNode = newNode;
		quantNode++;
		return;
	}
	
	node *nodeCheck = firstNode;
	
	switch(type){
		case 'a':
			while(true){
				// No caso da primeira não ser um chamado de urgência alta
				// E no caso já teria que ir na frente
				if((*nodeCheck).urgency != 'a'){
					(*newNode).next = nodeCheck;
					firstNode = newNode;
					break;
				}
				
				// Se a urgência do próximo nó do nó da checagem for média ou baixa ou null ele irá se encaixar após o nó de checagem
				if((*(*nodeCheck).next).urgency == 'm' || (*(*nodeCheck).next).urgency == 'b' || (*nodeCheck).next == NULL){
					(*newNode).next = (*nodeCheck).next;
					(*nodeCheck).next = newNode;
					break;
				}
				
				nodeCheck = (*nodeCheck).next;
			}
			
			break;
			
		case 'm':
			while(true){
				// No caso da primeira ser um chamada de nível baixo
				// E no caso já teria que ir na frente
				if((*nodeCheck).urgency == 'b'){
					(*newNode).next = nodeCheck;
					firstNode = newNode;
					break;
				}
				
				
				// Se o próximo for baixa ou null ele se encaixa após o nó de checagem
				if((*(*nodeCheck).next).urgency == 'b' || (*nodeCheck).next == NULL){
					(*newNode).next = (*nodeCheck).next;
					(*nodeCheck).next = newNode;
					break;
				}
				
				nodeCheck = (*nodeCheck).next;

			}
			
			break;
			
		case 'b':
			while(true){	
				// Os chamdos de nível baico sempre serão colocados como últimos na lista, logo será colocado entre o último nó e o null
				if((*nodeCheck).next == NULL){
					(*newNode).next = (*nodeCheck).next;
					(*nodeCheck).next = newNode;
					break;
				}
				nodeCheck = (*nodeCheck).next;

			}
			
			break;
	}
	
	
	quantNode++;	

}


int main(){
	Insert(22, 'm');
	Insert(18, 'a');
	Insert(10, 'b');
	Insert(20, 'm');
	Insert(40, 'm');
	Insert(80, 'a');
	Insert(82, 'a');
	Insert(88, 'a');
	Insert(92, 'b');
	
	node *nodeView = firstNode;
	
	for(int i = 0; i < quantNode; i++){
		cout << "|Senha: " << (*nodeView).pass << " " << "Tipo: " << (*nodeView).urgency << "| --> ";
		nodeView = (*nodeView).next;
	}
	
	cout << "NULL" << endl;
	
	system("pause");
}

