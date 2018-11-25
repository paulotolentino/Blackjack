#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>

using namespace std;

void INSTRUCOES() {
     
    ("INSTRUÇÕES:\n\n");
    cout<<"\t\t\tBem vindo ao Jogo de 21\n\n";
    cout<<"O Jogo de 21 ou Blackjack é jogado com um baralho comum com 52 cartas\n(sem os curingas)";
    cout<<"em que o objetivo é ter mais pontos do que o adversário,mas sem ultrapassar os 21 (caso em que se perde).\n\n";
    cout<<"Lembrando que:\n";
    cout<<" - As cartas de 2 a 10 têm o número de pontos de acordo com seu valor facial.\n";
    cout<<" - Todas as cartas de figuras valem 10 pontos.\n";
    cout<<" - Os ases podem valer 1 ou 11 pontos.\n";
    cout<<" - O naipe das cartas não interferem em seu valor.\n";
    cout<<"\n\nPara começar a jogar pressione qualquer tecla.";
    cout<<"\n\n\t\t\t...... START .......";
}

int JOGADOR(int soma, int i, int j, int numGer){
	//If usado por causa do As,que pode valer 1 ou 11,se a soma for menor ou igual a 10 o As vale 11,e se a soma for maior que 10 o As vale 1
    if(numGer == 1) {
        if(soma <= 10) {
            numGer = 11;
        }
        if(soma > 10) {
            numGer = 1;
        }
    }     
    
    cout<<"\n\n\n";
    cout<<"A carta sorteada foi:" << numGer;
    return numGer;
}
char NOVAMENTE(){
	char resp;
    cout<<"\nDeseja outra carta: [S/N]";
    do{
           resp = getch();
       }while(isdigit(resp)!=0); 
    resp = toupper(resp);
    cout<<"\nResposta: " << resp; 
	getch();   
 	return resp;
}

int main () {
     
    setlocale(LC_ALL,"PORTUGUESE");
    srand(time(NULL));  
    
    char nome1[50],nome2[50],resp;
    int num,i,j,numGer,soma1,soma2,aux;
    soma1 = soma2 = aux = i = j = 0;
//Matriz com os possiveis numeros que podem aparecer em cada carta:
    int m[4][14] = {{1,2,3,4,5,6,7,8,9,10,10,10,10},
                    {1,2,3,4,5,6,7,8,9,10,10,10,10},
                    {1,2,3,4,5,6,7,8,9,10,10,10,10},
                    {1,2,3,4,5,6,7,8,9,10,10,10,10}};
    INSTRUCOES();
        
    getch();
    system("CLS");
    system("CLS");
	cout<<"====================== .: Jogo de 21 :. =======================\n\n";
	cout<<("\n\nÉ a sua vez, Jogador 1!");
    resp = 83;
    do{    	
    	if(resp == 83){
    		i = rand()%3+0;
		    j = rand()%13+0;
		    numGer = m[i][j];
    		soma1 += JOGADOR(soma1, i, j, numGer);  
    		cout<<"\nA soma de suas cartas é:" << soma1;
			resp = NOVAMENTE();  		
		}
		if(resp == 78){
			aux = soma1;
			soma1 = 100;
		}		
	}while(soma1 < 22 && resp == 83);
	
	if (soma1 == 100) soma1 = aux;
	
	if(resp == 78 || soma1 > 21){
		system("CLS");
    	cout<<"====================== .: Jogo de 21 :. =======================\n\n";
   		cout<<("\n\nÉ a sua vez, Jogador 2!");
		resp = 83;
		do{
	    	if(resp == 83){
	    		i = rand()%3+0;
			    j = rand()%13+0;
			    numGer = m[i][j];
	    		soma2 += JOGADOR(soma2, i, j, numGer); 	    		
    			cout<<"\nA soma de suas cartas é:" << soma2;
				resp = NOVAMENTE();  		
			}
			if (resp == 78){
				aux = soma2;
				soma2 = 100;
			}
		}while(soma2 <= 21 && resp == 83);
		
		if (soma2 == 100) soma2 = aux;
		system("CLS");
	    cout<< ("====================== .: Jogo de 21 :. =======================\n\n");
	    
	    if((soma1 <= 21) && (soma2 > 21)) {
	         cout<<"\a\aJogador 2 você perdeu!!Você marcou mais que 21 pontos";
	         cout<<"\n\nParabéns Jogador 1, você ganhou!!\nVocê marcou: " << soma1 << " pontos";
	         cout<<"\n\nEnquanto o jogador Jogador 2 marcou: " << soma2 <<" pontos";
	    }
	    if((soma2 <= 21) && (soma1 > 21)) {
	         cout<<"\a\aJogador 1 você perdeu!!Você marcou mais que 21 pontos";
	         cout<<"\n\nParabéns Jogador 2, você ganhou!!\nVocê marcou: " << soma2 << " pontos";
	         cout<<"\n\nEnquanto o jogador Jogador 1 marcou: " << soma1 <<" pontos";
	    }
	    if(soma2 == soma1 && soma1 <= 21){
	         cout<<"\n\nO jogo terminou empatadado.\nAmbos jogadores marcaram: " << soma1 << " pontos";
	    }
	    if((soma1 > soma2) && (soma1 <= 21)) {
	         cout<<"\a\a\n\nJogador 2 você perdeu!!";
	         cout<<"\n\nParabéns Jogador 1, você ganhou!!\nVocê marcou "<< soma1 <<" pontos";
	         cout<<"\n\nEnquanto o jogador Jogador 2 marcou: "<< soma2 << " pontos";
	    }
	    if((soma2 > soma1) && (soma2 <= 21)) {
	         cout<<"\a\a\n\nJogador 1 você perdeu!!";
	         cout<<"\n\nParabéns Jogador 2, você ganhou!!\nVocê marcou "<< soma2 <<" pontos";
	         cout<<"\n\nEnquanto o jogador Jogador 1 marcou: "<< soma1 << " pontos";
	    }
	    if((soma1 > 21) && (soma2 > 21)) {
	             cout<< "\n\nO jogo não teve ganhadores! \nAmbos jogadores marcaram mais que 21 pontos.";
	    } 
	}
    
    getch();
}
