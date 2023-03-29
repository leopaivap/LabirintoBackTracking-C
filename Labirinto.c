#include <stdio.h>
#include "bibliotecaPilhaEncadeada.h"
#include <stdlib.h>
#define MAX 20

void criaLabirinto(char labirinto[MAX][MAX]){
     int i,j,x,y;
     srand(time(NULL));
     for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++){
          if((rand()%5)==1)
             labirinto[i][j]='|';
             else
              labirinto[i][j]='.';
          }
     for(i=0;i<MAX;i++){
           labirinto[0][i]='*';
           labirinto[MAX-1][i]='*';
           labirinto[i][0]='*';
           labirinto[i][MAX-1]='*';
           }// fim for
        x=  (rand() % MAX-2) +1;
        labirinto[x][19]='S';
     }// fim funcao cria
//-------------------------------------------     
void printLabirinto(char labirinto[MAX][MAX]){
    int i,j;
     for ( i = 0; i < MAX; i++)
    {
     printf("\n");
          for ( j = 0; j < MAX; j++)
			printf (" %c ",labirinto[i][j] );
     	}

} // fim funcao
//-------------------------------------------
     
 int buscaSaida(char lab[MAX][MAX],int i, int j){
        tPilha p1;
        inicializa(&p1);
        tdado atual;
        int saida = 1;
        
        while(1){

        	//trocar de carinhas
        	if(lab[i][j] != 2)
        		lab[i][j] = 1;
        	else if(lab[i][j] == 1)
        		lab[i][j] = 2;
        		
        	//verificar saida
        	if(lab[i][j+1] == 'S'){
				atual.x = i;
				atual.y = j+1;
				break;
			}
			else if(lab[i+1][j] == 'S'){
				atual.x = i+1;
				atual.y = j;
				break;
			}
			else if(lab[i][j-1] == 'S'){
				atual.x = i;
				atual.y = j+1;
				break;
			}
			else if(lab[i-1][j] == 'S'){
				atual.x = i-1;
				atual.y = j;
				break;
			}
			
			//andar
        	if(lab[i][j+1] == '.'){
        		atual.x = i;
        		atual.y = j;
        		push(&p1, atual);
        		j++;
			}
			else if(lab[i+1][j] == '.'){
				atual.x = i;
        		atual.y = j;
        		push(&p1, atual);
        		i++;
			}
			else if(lab[i][j-1] == '.'){
				atual.x = i;
        		atual.y = j;
        		push(&p1, atual);
        		j--;
			}
			else if(lab[i-1][j] == '.'){
				atual.x = i;
        		atual.y = j;
        		push(&p1, atual);
        		i--;
			}
			
			//voltar casa
			else if(!isEmpty(p1)){
			    lab[i][j] = 2;
			    atual = pop(&p1); 
			    lab[i][j] = 2;
			    i = atual.x;
			    j = atual.y;
			}

			
			//impossivel
			else {
				printf("** Impossivel achar a saida! :(**");
				saida = 0;
				break;
			}
			Sleep(200);
			system("cls");
			//mostraPilha(p1); usado para debug na fase de testes
			printLabirinto(lab);
		}
		if(saida){
			system("cls");
			printf("Saida Encontrada! :)\nPosicao: [%d, %d]", atual.x, atual.y);
			printLabirinto(lab);
		}

        return 1;
 }// fim funcao

//-------------------------------------------
int main(){
    char meuLabirinto[MAX][MAX];
    int x,y;
    criaLabirinto(meuLabirinto);
    printLabirinto(meuLabirinto);
    printf("\nEntre com a posicao inicial do robo:");
    scanf("%d %d",&x,&y);
    buscaSaida(meuLabirinto,x,y);
    getch();
    return 0;
    }
