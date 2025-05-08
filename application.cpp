#include<iostream>
#include<locale.h>
#include<stdlib.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>

using namespace std;

struct node{
	int pass;
	char urgency; //a = Alto; m = Medio; b = Baixa
	struct node *next;
};

int quantNode = 0;
node *firstNode;

void Insert(int pass, char type){
	// Usando new para que a vari�vel seja alaocada no heap
	node *newNode = new struct node; // Alocando novo n� na mem�ria
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
				// No caso da primeira n�o ser um chamado de urg�ncia alta
				// E no caso j� teria que ir na frente
				if((*nodeCheck).urgency != 'a'){
					(*newNode).next = nodeCheck;
					firstNode = newNode;
					break;
				}
				
	
				
				// Se a urg�ncia do pr�ximo n� do n� da checagem for m�dia ou baixa ou null ele ir� se encaixar ap�s o n� de checagem
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
				// No caso da primeira ser um chamada de n�vel baixo
				// E no caso j� teria que ir na frente
				if((*nodeCheck).urgency == 'b'){
					(*newNode).next = nodeCheck;
					firstNode = newNode;
					break;
				}
				
					// OBTENDO N�S EM IFS DE FORMA ERRADA, CORRIGITR
					cout << (*(*nodeCheck).next).urgency;
				system("pause");
				// Se o pr�ximo for baixa ou null ele se encaixa ap�s o n� de checagem
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
				// Os chamdos de n�vel baico sempre ser�o colocados como �ltimos na lista, logo ser� colocado entre o �ltimo n� e o null
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


int menu(char title [100], int size, char options[10][100]){
	int ch;
	int select = 0;
	
	while(true){
		cout << "========== " << title << "==========" << endl;
		for(int i = 0; i < size; i++){
			if(select == i){
				printf("> %s\n", options[i]);
				continue;
			}
			printf("%s\n", options[i]);
		}
		cout << "=============================================";
		
		ch = _getch(); // Pegar dados de teclado

		switch(ch){
			case 27:
				// Tecla ESC
				return -1;
				break;

			case 224: //Prefixo de tecla de setas
				ch = _getch();

				switch(ch){
					case 72: // Seta pra cima
						if(select > 0){
							select -= 1;
						} 
						break;

					case 80: // Seta pra baixo
						if(select < size - 1){
							select += 1;
						}
						break;
				}
			break;
			

			case 13: // Enter
				return select;
				break;
		}
		
		// Sempre que uma tecla � pressionada ele limpa a tela dando a impress�o de que estamos movimentando seta
		system("cls");
	}
	
}


bool ExistPass(int pass){
	node *checkNode = firstNode;
	for(int i = 0; i < quantNode; i++){
		if((*checkNode).pass == pass){
			return true;
		}
		
		checkNode = (*checkNode).next;
	}
	
	return false;
}


void app(){
	char options[10][100] = {"Abrir Chamado", "Listar chamados", "Sair"}, optionsUrgency[10][100] = {"Alta", "M�dia", "Baixa", "Voltar"}; // Op��es de menus
	int select, selectUrgency; // Selecionadores de op��es
	node *nodeView; // Ponteiro para referencia de listagem
	
	// Inicializando srand
	srand(time(NULL));	
	
	while(true){
	
		select = menu("Selecione a op��o desejada", 3, options);
		
		switch(select){
			case 0:
				system("cls");
				
				selectUrgency = menu("Selecione a urg�ncia do chamado", 4, optionsUrgency);
				
				int key;
				
				do{
					key = rand() % 1000 + 1;
				} while(ExistPass(key));
				
				switch(selectUrgency){
					case 0:
						Insert(key, 'a');
						break;
					case 1:
						Insert(key, 'm');
						break;
					case 2:
						Insert(key, 'b');
						break;
					case 3:
						system("cls");
						continue;
						break;
				}
				
				system("cls");
				cout << "Chamado com a senha " << key << " aberto com sucesso!" << endl;
				system("pause");
				system("cls");
				continue;
				break;
				
			case 1:
				system("cls");
				if(quantNode <= 0){
					cout << "Nenhum chamado cadastrado" << endl;
					system("pause");
					system("cls");
					continue;
					break;
				}
				
				nodeView = firstNode;
				for(int i = 0; i < quantNode; i++){
					cout << "=======================" << endl;
					
					if((*nodeView).urgency == 'a'){
						cout << "|Senha: " << (*nodeView).pass  << endl << "|Urg�ncia: Alta" << endl;
					}
					
					if((*nodeView).urgency == 'm'){
						cout << "|Senha: " << (*nodeView).pass  << endl << "|Urg�ncia: M�dia" << endl;
					}
					
					if((*nodeView).urgency == 'b'){
						cout << "|Senha: " << (*nodeView).pass  << endl << "|Urg�ncia: Baixa" << endl;
					}
					
					cout << "=======================" << endl;
					cout << "          |" << endl;
					cout << "          |" << endl;
					cout << "          V" << endl;
			
					nodeView = (*nodeView).next;
				}
				
				cout << "         NULL" << endl;
				
				system("pause");
				system("cls");
				
				continue;
				
				break;
				
			case 3:
				break;
		}
		break;
	}
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	app();
}


