#include<iostream>
#include<locale.h>
#include<stdlib.h>

using namespace std;

struct node{
	int pass;
	char urgency; //a = Alto; m = M�dio; b = Baixa
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
				if((*nodeCheck).next == NULL){
					(*nodeCheck).next = newNode;
					(*newNode).next = NULL;
					break;	
				} else{
					if((*nodeCheck).urgency == 'm'){
						(*newNode).next = nodeCheck;
						firstNode = newNode;
						break;
					}
					if((*nodeCheck).urgency == 'a' && (*(*nodeCheck).next).urgency != 'a'){
						(*newNode).next = (*nodeCheck).next;
						(*nodeCheck).next = newNode;
						break;
					}
				}
				nodeCheck = (*nodeCheck).next;
			}
			
			break;
			
		case 'm':
			while(true){
				if((*nodeCheck).next == NULL){
					(*nodeCheck).next = newNode;
					(*newNode).next = NULL;
					break;	
				} else{
					if((*nodeCheck).urgency == 'm' && (*(*nodeCheck).next).urgency != 'm'){
						(*newNode).next = (*nodeCheck).next;
						(*nodeCheck).next = newNode;
						break;
					}
				}
				nodeCheck= (*nodeCheck).next;
			}
			
			break;
			
		case 'b':
			while(true){
				if((*nodeCheck).next == NULL){
					(*nodeCheck).next = newNode;
					(*newNode).next = NULL;
					break;	
				} else{
					if((*nodeCheck).urgency == 'b' && (*(*nodeCheck).next).urgency != 'b'){
						(*newNode).next = (*nodeCheck).next;
						(*nodeCheck).next = newNode;
						break;
					}
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
	Insert(20, 'a');
	
	node *nodeView = firstNode;
	
	for(int i = 0; i < quantNode; i++){
		cout << "|Senha: " << (*nodeView).pass << " " << "Tipo: " << (*nodeView).urgency << "| --> ";
		nodeView = (*nodeView).next;
	}
	
	cout << "NULL" << endl;
	
}
