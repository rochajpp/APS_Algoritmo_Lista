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
	// Usando new para que a variável seja alaocada no heap
	node *newNode = new struct node; // Alocando novo nó na memória
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
				
					// OBTENDO NÓS EM IFS DE FORMA ERRADA, CORRIGITR
					cout << (*(*nodeCheck).next).urgency;
				system("pause");
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
		
		// Sempre que uma tecla é pressionada ele limpa a tela dando a impressão de que estamos movimentando seta
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
	char options[10][100] = {"Abrir Chamado", "Listar chamados", "Sair"}, optionsUrgency[10][100] = {"Alta", "Média", "Baixa", "Voltar"}; // Opções de menus
	int select, selectUrgency; // Selecionadores de opções
	node *nodeView; // Ponteiro para referencia de listagem
	
	// Inicializando srand
	srand(time(NULL));	
	
	while(true){
	
		select = menu("Selecione a opção desejada", 3, options);
		
		switch(select){
			case 0:
				system("cls");
				
				selectUrgency = menu("Selecione a urgência do chamado", 4, optionsUrgency);
				
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
						cout << "|Senha: " << (*nodeView).pass  << endl << "|Urgência: Alta" << endl;
					}
					
					if((*nodeView).urgency == 'm'){
						cout << "|Senha: " << (*nodeView).pass  << endl << "|Urgência: Média" << endl;
					}
					
					if((*nodeView).urgency == 'b'){
						cout << "|Senha: " << (*nodeView).pass  << endl << "|Urgência: Baixa" << endl;
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


