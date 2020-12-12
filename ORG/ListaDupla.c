#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>



typedef struct{
	int cod;
	char nome[20];
	float preco;
}Produto;
typedef struct _nodo{
	Produto info;
	struct _nodo *prox;
	struct _nodo *ant;
}Nodo;
typedef struct lista{
	int nItens;
	Nodo *pri;
	Nodo *ult;
}Lista;

Lista *push(Lista *lista){
	Nodo *v=(Nodo *)malloc(sizeof(Nodo));
	v->prox=lista->pri;
	v->ant=lista->ult;
	printf("Digite o nome do produto:\n");
    __fpurge(stdin);
    fgets(v->info.nome,20,stdin);
    printf("Digite o codigo do produto:\n");
    scanf("%d",&v->info.cod);
    printf("Digite o preço do produto:\n");
    scanf("%f",&v->info.preco);
    if(lista->nItens==0){
    	lista->ult=v;
    	lista->pri=v;
    }else{
    	lista->pri->ant=v;
  		lista->pri=v;
    }
    lista->nItens++;
    return lista;
}
Lista *pop(Lista *lista){
    int cod;
    Nodo *a;
    printf("Digite o codigo do produto que deseja extrair\n");
    scanf("%d",&cod);
    for(a=lista->pri;a!=NULL;a=a->prox){
        if(a->info.cod==cod){
            break;
        }
    }if(a==NULL){
    	printf("Não encontrado\n");

    }else if(lista->nItens==1){
    	lista->pri=NULL;
    	lista->ult=NULL;

    }else if(a==lista->pri){
        lista->pri=a->prox;
        printf("Produto extraido.\n");
    
    }else if(a==lista->ult){
    		lista->ult=a->ant;
    
    }else{

       	a->prox->ant=a->ant;
       	a->ant->prox=a->prox;
        printf("Produto extraido.\n");

    }
   
    lista->nItens--;	
    return lista;
}

void imprime(Lista *lista){
	Nodo *p;

    if(lista->pri==NULL){
    	printf("Lista vazia\n");
    }
    else{
        for(p=lista->pri;p!= NULL;p=p->prox){

            printf("Produto: %s",p->info.nome);
            printf("Codigo:%d\n", p->info.cod);
            printf("Preço: %.2f\n",p->info.preco);
            printf("------------------------------------\n");
        }
    }
}






int main(){
	Lista *lista=(Lista*)malloc(sizeof(Lista));
	lista->pri=NULL;
	lista->ult=NULL;
	lista->nItens=0;
	int finalizador=0,num;


	for(;;){
        if(finalizador==1)
            break;
        printf("======================================================\n");
		printf("Digite 1 para inserir um produto na lista\n");
		printf("Digite 2 para extrair um produto da lista\n");
        printf("Digite 3 para mostrar os produtos da lista\n");
        printf("Digite 0 para sair.\n");
        printf("======================================================\n");
        scanf("%d", &num);


        switch(num){
          
            case 1:
            	system("clear");
                lista=push(lista);
            	break;
            case 2:
            	system("clear");
                lista=pop(lista);

                break;
            case 3:
            	system("clear");
     			imprime(lista);       	
				break;
            case 0:
                finalizador++;
                free(lista);
                break;

        }
    }
}    