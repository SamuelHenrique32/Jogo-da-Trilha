#include <stdio.h>
#include <stdlib.h>

void desenhatabuleiro(int pos[23])
{
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", pos[0], 196, 196, 196, 196, 196, 196, 196, 196, pos[1], 196, 196, 196, 196, 196, 196, 196, 196, pos[2]);                      
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, 32, 32, 32, 32, 32, 32, 32, 32, 179, 32, 32, 32, 32, 32, 32, 32, 32, 179);                                                        
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, 32, 32, pos[3], 196, 196, 196, 196, 196, pos[4], 196, 196, 196, 196, 196, pos[5], 32, 32, 179);                          
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, 32, 32, 179, 32, 32, 32, 32, 32, 179, 32, 32, 32, 32, 32, 179, 32, 32, 179);                                                     
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, 32, 32, 179, 32, 32, pos[6], 196, 196, pos[7], 196, 196, pos[8], 32, 32, 179, 32, 32, 179);                                                
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, 32, 32, 179, 32, 32, 179, 32, 32, 32, 32, 32, 179, 32, 32, 179, 32, 32, 179);                                            
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", pos[9], 196, 196, pos[10], 196, 196, pos[11], 32, 32, 32, 32, 32, pos[12], 196, 196, pos[13], 196, 196, pos[14]);        
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, 32, 32, 179, 32, 32, 179, 32, 32, 32, 32, 32, 179, 32, 32, 179, 32, 32, 179);                                             
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, 32, 32, 179, 32, 32, pos[15], 196, 196, pos[16], 196, 196, pos[17], 32, 32, 179, 32, 32, 179);                             
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, 32, 32, 179, 32, 32, 32, 32, 32, 179, 32, 32, 32, 32, 32, 179, 32, 32, 179);                                                  
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, 32, 32, pos[18], 196, 196, 196, 196, 196, pos[19], 196, 196, 196, 196, 196, pos[20], 32, 32, 179);                       
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, 32, 32, 32, 32, 32, 32, 32, 32, 179, 32, 32, 32, 32, 32, 32, 32, 32, 179);                                          
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", pos[21], 196, 196, 196, 196, 196, 196, 196, 196, pos[22], 196, 196, 196, 196, 196, 196, 196, 196, pos[23]);                       
}

void movepeca(int pos[23], int peca, int posdest)
{
	int auxpos[24]={218,194,191,218,197,191,218,193,191,195,197,180,195,197,180,192,194,217,192,197,217,192,193,217};
	pos[posdest]=pos[peca];
	pos[peca]=auxpos[peca];
}

int trocajogador(int jogadoratual)
{
	if(jogadoratual==1)
	    return 2;
	else
	    return 1;    
}

void remove(int pos[24], int peca)
{
    int auxpos[24]={218,194,191,218,197,191,218,193,191,195,197,180,195,197,180,192,194,217,192,197,217,192,193,217};	
    pos[peca]=auxpos[peca];
}

int verificatrilha(int pos[24], int peca, int pecajogador)
{
    int trilhas[16][3]={{0,1,2}, {3,4,5}, {6,7,8}, {9,10,11}, {12,13,14}, {15,16,17}, {18,19,20}, {21,22,23}, {0,9,21}, {3,10,18}, {6,11,15}, 
    {1,4,7}, {16,19,22}, {8,12,17}, {5,13,20}, {2,14,23}};
    int pecaaux, peca2, pecaaux2, i, j, k, encontrou, removeu, trilhal, trilhacol, linha[2], vizinho[2];
    int auxpos[24]={218,194,191,218,197,191,218,193,191,195,197,180,195,197,180,192,194,217,192,197,217,192,193,217};	
	encontrou=0;
    k=0;
    removeu=0;
	trilhal=0;
	trilhacol=0;
	pecaaux=peca;
  	while(encontrou!=2)                                   //percorre o vetor para encontrar as linhas que possuem a peca
	{
	    for(i=0 ; i<=15 ; i++)
	        for(j=0 ; j<=2 ; j++)
	            if(trilhas[i][j]==peca)
				{
				    linha[k]=i;
					k++;
                    encontrou++;
				}      
	}
    k=0;
    for(j=0 ; j<=2 ; j++)                                   //verifica as peças vizinhas na primeira linha
	{
		if(trilhas[linha[0]][j]!=peca)
		{
			vizinho[k]=trilhas[linha[0]][j];
			k++;
		}
	}
	
   for(j=0 ; j<=2 ; j++)                                   //verifica as peças vizinhas na segunda linha
	{
		if(trilhas[linha[1]][j]!=peca)
		{
			vizinho[k]=trilhas[linha[1]][j];
			k++;
		}
	}
    if(pos[peca]==pecajogador && pos[vizinho[0]]==pecajogador && pos[vizinho[1]]==pecajogador)
    {
    	return 1;
	}    
    if(pos[peca]==pecajogador && pos[vizinho[2]]==pecajogador && pos[vizinho[3]]==pecajogador)	
    {
	    return 2;
    }
	else
        return 0;
}

int pecassemtrilha(int pos[23], int pecajogador)                 
{
	int i, aux, pecasemtrilha, pecasjogador[10];
	aux=0;
	pecasemtrilha=0;
	for(i=0 ; i<=23 ; i++)
    	if(pos[i]==pecajogador)
    	{
		    pecasjogador[aux]=i;
    	    aux++;
		}    
    for(i=0 ; i<aux ; i++)
		if (verificatrilha(pos, pecasjogador[i], pecajogador)==0)
			pecasemtrilha=pecasemtrilha+1;
	if(pecasemtrilha>=1)
	    return 1;
	else
	    return 0;    
}

int verificavizinholivre(int pos[24], int peca)               //se  encontrar ao menos um vizinho adjacente livre, há uma jogada válida para a peca
{
    int vizinhoadj[24][4]= {{1,9}, {0,2,4}, {1,14}, {4,10}, {3,5,1,7}, {4,13}, {7,11}, {6,8,4}, {7,12}, {10,0,21}, {9,11,3,18}, {10,6,15}, {13,8,17}, {12,14,5,20},
	{13,2,23}, {16,11}, {15,17,19}, {16,12}, {19,10}, {20,18,16,22}, {19,13}, {22,9}, {21,23,19}, {22,14}};
	int i, j, retorno, vizinho[4];
    int auxpos[24]={218,194,191,218,197,191,218,193,191,195,197,180,195,197,180,192,194,217,192,197,217,192,193,217};	
    retorno=0;
	if(peca==0 || peca==2 || peca==3 || peca==5 || peca==6 || peca==8 || peca==15 || peca==17 || peca==18 ||  peca==20 ||  peca==21 ||  peca==23)      //possui 2 vizinhos adjacentes
	{
	    for(i=0 ; i<=1 ; i++)
	        vizinho[i]=vizinhoadj[peca][i];
		for(i=0 ; i<=1 ; i++)    
			if(pos[vizinho[i]]==auxpos[vizinho[i]])
	            retorno=1;
	}
	if(peca==1 ||  peca==7 ||  peca==9 || peca==11 ||  peca==12 ||  peca==14 ||  peca==16 ||  peca==22)                                                //possui 3 vizinhos adjacentes
    {
	    for(i=0 ; i<=2 ; i++)
		    vizinho[i]=vizinhoadj[peca][i];
		for(i=0 ; i<=2 ; i++)    
			if(pos[vizinho[i]]==auxpos[vizinho[i]])
	            retorno=1;
	}        
    if(peca==4 ||  peca==10 ||  peca==13 ||  peca==19)                                                                                                 //possui 4 vizinhos adjacentes
	{
	    for(i=0 ; i<=3 ; i++)
	        vizinho[i]=vizinhoadj[peca][i];
	    for(i=0 ; i<=3 ; i++)    
			if(pos[vizinho[i]]==auxpos[vizinho[i]])
	            retorno=1;   
	}     
	return retorno;
}

int verificajogadavalida(int pos[24], int pecajogador)               
{
	int pecasjogador[10], aux, i, jogadavalida;
	aux=0;
	jogadavalida=0;
	for(i=0 ; i<=23 ; i++)                                            //coloca no vetor pecasjogador todas as posições de peças do jogador atual
	    if(pos[i]==pecajogador)
	    {   
		    pecasjogador[aux]=i;
	        aux++;
		} 
	for(i=0 ; i<aux ; i++)
	    if(verificavizinholivre(pos, pecasjogador[i])==1)             //se há ao menos 1 peça do jogador atual com um vizinho adjacente livre então há jogadas válidas para
		    jogadavalida=1;                                           //o jogador atual
	return jogadavalida;		  	   
}

int verificaadjacente(int peca, int posdest)
{
	int vizinhoadj[24][4]= {{1,9}, {0,2,4}, {1,14}, {4,10}, {3,5,1,7}, {4,13}, {7,11}, {6,8,4}, {7,12}, {10,0,21}, {9,11,3,18}, {10,6,15}, {13,8,17}, {12,14,5,20},
	{13,2,23}, {16,11}, {15,17,19}, {16,12}, {19,10}, {20,18,16,22}, {19,13}, {22,9}, {21,23,19}, {22,14}};
	int i, adjacente;
	adjacente=0;
	if(peca==0 || peca==2 || peca==3 || peca==5 || peca==6 || peca==8 || peca==15 || peca==17 || peca==18 ||  peca==20 ||  peca==21 ||  peca==23)
        for(i=0 ; i<=1 ; i++)
            if(vizinhoadj[peca][i]==posdest)
                adjacente=1;
    if(peca==1 ||  peca==7 ||  peca==9 || peca==11 ||  peca==12 ||  peca==14 ||  peca==16 ||  peca==22) 
        for(i=0 ; i<=2 ; i++)
            if(vizinhoadj[peca][i]==posdest)
                adjacente=1;
    if(peca==4 ||  peca==10 ||  peca==13 ||  peca==19)
        for(i=0 ; i<=3 ; i++)
            if(vizinhoadj[peca][i]==posdest)
                adjacente=1;
	return adjacente;            
}


int main ( )
{
	int i, peca, posdest, jogadoratual, trilha, removeu, jogadorcom3pecas, contpecas[2], pecajogador[3], pos[24], auxpos[24]={218,194,191,218,197,191,218,193,191,195,197,180,195,197,180,192,194,217,192,197,217,192,193,217};
	pecajogador[1]=207;
	pecajogador[2]=208;
	jogadoratual=1;
	contpecas[0]=0;
	contpecas[1]=0;
	contpecas[2]=0;	
	removeu=0;
	printf("Bem Vindo ao Jogo da Trilha!\n\n");
	printf("Desenvolvido por Samuel Henrique Dalmas");
	printf("\n\n");
	for(i=0 ; i<=23 ; i++)                                                         //zera o tabuleiro
	    pos[i]=auxpos[i];
    while((contpecas[1]<9) || (contpecas[2]<9))                                    //repetição até preencher todas as posições do tabuleiro
	{
	    printf("Jogador %d insira uma peca no tabuleiro:", jogadoratual);
		scanf("%d", &peca);
		while(pos[peca]!=auxpos[peca])                                              //repetição até ser informada uma posição vazia
		{
			printf("A posicao nao esta vazia! Informe uma posicao valida:");
			scanf("%d", &peca);	
		}
		if(pos[peca]==auxpos[peca])                                                //se a posição do tabuleiro estiver vazia a peça é colocada na mesma
		{
			pos[peca]=pecajogador[jogadoratual];
			trilha=verificatrilha(pos, peca, pecajogador[jogadoratual]);
			contpecas[jogadoratual]=contpecas[jogadoratual]+1;
		    jogadoratual=trocajogador(jogadoratual);
		    printf("\n");
			system("cls");
			desenhatabuleiro(pos);
			if(trilha==1 || trilha==2)
			{
			    removeu=0;
				printf("Voce formou uma trilha! Remova uma peca do jogador %d:", jogadoratual); 
		        scanf("%d", &peca);
				if(pecassemtrilha(pos, pecajogador[jogadoratual])==1)
				{
				    if(verificatrilha(pos, peca, pecajogador[jogadoratual])==0 && pos[peca]==pecajogador[jogadoratual])
		            {
		        	    remove(pos, peca);
		        	    system("cls");
					    desenhatabuleiro(pos);
		        	    removeu=1;
				    }    
				    else
				        while(removeu==0)
		                {
				            printf("Peca invalida! Informe outra:\n");
				            scanf("%d", &peca);
				            if(verificatrilha(pos, peca, pecajogador[jogadoratual])==0 && pos[peca]==pecajogador[jogadoratual])
		                    {
		        	            remove(pos, peca);
		        	            system("cls");
							    desenhatabuleiro(pos);
		        	            removeu=1;
				            }
				        }
				}
				else
				    if(pecassemtrilha(pos, pecajogador[jogadoratual])==0)
					{
					    if(pos[peca]==pecajogador[jogadoratual])
		                {
		        	        remove(pos, peca);
		        	        system("cls");
					        desenhatabuleiro(pos);
		        	        removeu=1;
				        }    
				        else
				            while(removeu==0)
		                    {
				                printf("Peca invalida! Informe outra:\n");
				                scanf("%d", &peca);
				                if(pos[peca]==pecajogador[jogadoratual])
		                        {
		        	                remove(pos, peca);
		        	                system("cls");
							        desenhatabuleiro(pos);
		        	                removeu=1;
				                }
				            }
					}           
			}    
		}    
    }
    contpecas[0]=0;                                                                                //zera o contador de pecas para cada jogador
	contpecas[1]=0;
	contpecas[2]=0;	
	for(i=0 ; i<=23 ; i++)                                                                         //conta a quantidade de pecas de cada jogador e armazena no vetor contepcas
    {
    	if(pos[i]==207)
    	    contpecas[1]=contpecas[1]+1;
	    if(pos[i]==208)
		    contpecas[2]=contpecas[2]+1;    
	}
	while((contpecas[1]>2) && (contpecas[2]>2))
	{
		if(contpecas[jogadoratual]==3)
	    {
	    	printf("Jogador %d, escolha uma peca para ser movida:", jogadoratual);
	        scanf("%d", &peca);
	        while(pos[peca]!=pecajogador[jogadoratual])                                               //verifica se a peça a ser movida pertence ao jogador atual
	        {                                                                                         //sem verificar se possui vizinho adjacente desocupado
	    	    printf("Peca invalida! Informe uma peca valida:");
	    	    scanf("%d", &peca);
		    }
		    printf("Informe uma posicao de destino:");
		    scanf("%d", &posdest);
		    while(pos[posdest]!=auxpos[posdest])                                                      //verifica se a posição de destino está vazia sem verificar se é 
		    {                                                                                         //adjacente à peça
			    printf("Posicao de destino invalida! Informe uma posicao valida:");
			    scanf("%d", &posdest);
		    }
	        system("cls");
		    movepeca(pos, peca, posdest);
		    desenhatabuleiro(pos);	
		    if((verificatrilha(pos, posdest, pecajogador[jogadoratual])==1) || (verificatrilha(pos, posdest, pecajogador[jogadoratual])==2))        //verifica se formou alguma nova trilha
		    {
		        removeu=0;
			    printf("Jogador %d formou uma trilha! Remova uma peca do adversario:", jogadoratual);
			    scanf("%d", &peca);
			    jogadoratual=trocajogador(jogadoratual);
			    if(pecassemtrilha(pos, pecajogador[jogadoratual])==1)                                                                               //há ao menos uma peca que não está em trilha, ou seja, antes de remover,
			    {                                                                                                                                   //é necessário verificar se a peça que será removida está em trilha
			        if(verificatrilha(pos, peca, pecajogador[jogadoratual])==0 && pos[peca]==pecajogador[jogadoratual])               //verifica se a peça está em trilha e se pertence ao jogador correto
		            {
		      	        remove(pos, peca);
		       	        system("cls");
				        desenhatabuleiro(pos);
		       	        removeu=1;
			        }    
			        else
			            while(removeu==0)
		                {
			                printf("Peca invalida! Informe outra:\n");
			                scanf("%d", &peca);
			                if(verificatrilha(pos, peca, pecajogador[jogadoratual])==0 && pos[peca]==pecajogador[jogadoratual])
		                    {
		       	                remove(pos, peca);
		       	                system("cls");
						        desenhatabuleiro(pos);
		       	                removeu=1;
			                }
			            }
			    }
			    else
			        if(pecassemtrilha(pos, pecajogador[jogadoratual])==0)                             //todas as peças do jogador estão em trilha, para remover não é necessário verificar se a peça está em trilha
				    {                                                                                 //tendo em vista que peças em trilha poderão ser removidas         
				        if(pos[peca]==pecajogador[jogadoratual])
		                {
		       	            remove(pos, peca);
		       	            system("cls");
				            desenhatabuleiro(pos);
		       	            removeu=1;
			            }    
			            else
			                while(removeu==0)
		                    {
			                    printf("Peca invalida! Informe outra:\n");
			                    scanf("%d", &peca);
			                    if(pos[peca]==pecajogador[jogadoratual])
		                        {
		       	                    remove(pos, peca);
		       	                    system("cls");
						            desenhatabuleiro(pos);
		       	                    removeu=1;
			                    }
			                }
				    }     
		        jogadoratual=trocajogador(jogadoratual);
			}
			jogadoratual=trocajogador(jogadoratual);
		    contpecas[0]=0;                                                                                //zera o contador de pecas para cada jogador
	        contpecas[1]=0;
	        contpecas[2]=0;	
		    for(i=0 ; i<=23 ; i++)                                                                         //conta a quantidade de pecas de cada jogador e armazena no vetor contepcas
            {
    	        if(pos[i]==207)
    	        contpecas[1]=contpecas[1]+1;
	            if(pos[i]==208)
		        contpecas[2]=contpecas[2]+1;    
	        }
		}
		else
		{
		    if(verificajogadavalida(pos, pecajogador[jogadoratual])==0)                                   //se não houver nenhuma jogada válida, o jagador atual perde a vez
	        {
		        printf("Nao ha jogadas validas para o jogador atual\n");
			    jogadoratual=trocajogador(jogadoratual);
		    }    
		    if(verificajogadavalida(pos, pecajogador[jogadoratual])==1)                                   //há pelo menos uma jogada válida para o jogador atual
	        {
	            printf("Jogador %d, escolha uma peca para ser movida:", jogadoratual);
	            scanf("%d", &peca);
	            while(pos[peca]!=pecajogador[jogadoratual] || verificavizinholivre(pos, peca)==0)         //verifica se a peça a ser movida pertence ao jogador atual e
	            {                                                                                         //se possui ao menos um vizinho adjacente desocupado
	    	        printf("Peca invalida! Informe uma peca valida:");
	    	        scanf("%d", &peca);
		        }
		        printf("Informe uma posicao de destino:");
		        scanf("%d", &posdest);
		        while(pos[posdest]!=auxpos[posdest] || verificaadjacente(peca, posdest)==0)               //verifica se a posição de destino está vazia e se é adjacente à peça
		        {
			        printf("Posicao de destino invalida! Informe uma posicao valida:");
			        scanf("%d", &posdest);
		        }
		        system("cls");
		        movepeca(pos, peca, posdest);
		        desenhatabuleiro(pos);
		        if((verificatrilha(pos, posdest, pecajogador[jogadoratual])==1) || (verificatrilha(pos, posdest, pecajogador[jogadoratual])==2))        //verifica se formou alguma nova trilha
		        {
		            removeu=0;
			        printf("Jogador %d formou uma trilha! Remova uma peca do adversario:", jogadoratual);
			        scanf("%d", &peca);
			        jogadoratual=trocajogador(jogadoratual);
			        if(pecassemtrilha(pos, pecajogador[jogadoratual])==1)
			        {
			            if(verificatrilha(pos, peca, pecajogador[jogadoratual])==0 && pos[peca]==pecajogador[jogadoratual])
		                {
		      	            remove(pos, peca);
		       	            system("cls");
				            desenhatabuleiro(pos);
		       	            removeu=1;
			            }    
			            else
			                while(removeu==0)
		                    {
			                    printf("Peca invalida! Informe outra:\n");
			                    scanf("%d", &peca);
			                    if(verificatrilha(pos, peca, pecajogador[jogadoratual])==0 && pos[peca]==pecajogador[jogadoratual])
		                        {
		       	                    remove(pos, peca);
		       	                    system("cls");
						            desenhatabuleiro(pos);
		       	                    removeu=1;
			                    }
			                }
			        }
			        else
			            if(pecassemtrilha(pos, pecajogador[jogadoratual])==0)
				        {
				            if(pos[peca]==pecajogador[jogadoratual])
		                    {
		       	                remove(pos, peca);
		       	                system("cls");
				                desenhatabuleiro(pos);
		       	                removeu=1;
			                }    
			                else
			                    while(removeu==0)
		                        {
			                        printf("Peca invalida! Informe outra:\n");
			                        scanf("%d", &peca);
			                        if(pos[peca]==pecajogador[jogadoratual])
		                            {
		       	                        remove(pos, peca);
		       	                        system("cls");
						                desenhatabuleiro(pos);
		       	                        removeu=1;
			                        }
			                    }
				        }     
			        jogadoratual=trocajogador(jogadoratual);
				}
			    jogadoratual=trocajogador(jogadoratual);
			    contpecas[0]=0;                                                                                //zera o contador de pecas para cada jogador
	            contpecas[1]=0;
	            contpecas[2]=0;	
			    for(i=0 ; i<=23 ; i++)                                                                         //conta a quantidade de pecas de cada jogador e armazena no vetor contepcas
                {
    	            if(pos[i]==207)
    	                contpecas[1]=contpecas[1]+1;
	                if(pos[i]==208)
		                contpecas[2]=contpecas[2]+1;    
	            }
	        }
		}  
    }
    jogadoratual=trocajogador(jogadoratual);
	printf("\n=============JOGADOR %d VENCEU!!!=============\n", jogadoratual);
	printf("\n\n");
	system("pause");
}

