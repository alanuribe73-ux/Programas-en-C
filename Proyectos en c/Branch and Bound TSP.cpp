#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int **matriz;
    int *marcas;
    int costo;
    int contador;
    int ciudad;
    int mc;
    struct Lista *sig;
};

void bloquear(struct Lista *p, int tam, int x, int y){
    int i;
    for(i=0;i<tam;i++){
        p->matriz[x][i]=999;
        p->matriz[i][y]=999;
    }
    p->matriz[y][x]=999;
}

void restar_fila(struct Lista *q, int tam, int min, int i){
    int k;
    for(k=0;k<tam;k++)
        if(q->matriz[i][k]!=999 && q->matriz[i][k]!=0)
            q->matriz[i][k]-=min;
}

//bloquea la hilera y fila, ademas A<j,i>
//Resta el minimo de cada fila
void restar_columna(struct Lista *q, int tam, int min, int i){
    int k;
    for(k=0;k<tam;k++)
        if(q->matriz[k][i]!=999 && q->matriz[k][i]!=0)
            q->matriz[k][i]-=min;
}

void costo(struct Lista *q, int tam){
    // restar_columna y restar_fila
    int i, j, min;
    for(i=0;i<tam;i++){
        min=q->matriz[i][0];
        for(j=1;j<tam;j++){
            if(min>q->matriz[i][j])
                min=q->matriz[i][j];
        }
        if(min!=999)
            q->costo+=min;
        if(min!=0 && min!=999)
            restar_fila(q,tam,min,i);
    }

    for(i=0;i<tam;i++){
        min=q->matriz[0][i];
        for(j=1;j<tam;j++){
            if(min>q->matriz[j][i])
                min=q->matriz[j][i];
        }
        if(min!=999)
            q->costo+=min;
        if(min!=0 && min!=999)
            restar_columna(q,tam,min,i);
    }
}

void generar(struct Lista *q, int tam){
    int i, j, cont=0, destino;
    for(i=0;i<tam;i++)
        for(j=0;j<tam;j++)
            q->matriz[i][j]=999;
    printf("Para dejar de intorducir una ciudad introduce 99");
    while(cont<tam){
        printf("\n       Ciudad %d       \n  ",cont+1);
        do{
            printf("De ciudad %d a: ",cont+1);
            scanf("%d",&destino);
            if(destino==99)
                printf("Termino ciudad %d",cont+1);
            else if(destino>tam || destino<=0)
                printf("Esa ciudad no existe\n");
            else if(cont==destino-1)
                printf("Te encuentras en esta ciudad\n");
            else{
                printf("Introduce el costo de %d a %d: ",cont+1,destino);
                scanf("%d",&q->matriz[cont][destino-1]);
            }
        }while(destino!=99);
        cont++;
    }
}

void *guardar(void *p, struct Lista *mmin, int tam, int num, int ciudad, int j){
    //Genera la lista de matrices con costo, caminos por recorrer, marcas y ciudad en la que se encuentra
    struct Lista *aux, *q;
    int i, k, min;
    q=(struct Lista *)malloc(sizeof(struct Lista));
    if(p==NULL){
        q->matriz=(int **)malloc(sizeof(int *)*tam);
        q->marcas=(int *)malloc(sizeof(int)*tam);
        for(i=0;i<tam;i++){
            q->matriz[i]=(int *)malloc(sizeof(int)*tam);
            q->marcas[i]=0;
        }
        q->contador=num;
        q->marcas[ciudad]=1;
        q->sig=NULL;
        q->ciudad=j;
        q->costo=0;
        q->mc=1;
        generar(q,tam);
        costo(q,tam);
        p=q;
    }
    else{
        q->matriz=(int **)malloc(sizeof(int *)*tam);
        q->marcas=(int *)malloc(sizeof(int)*tam);
        for(i=0;i<tam;i++){
            q->matriz[i]=(int *)malloc(sizeof(int)*tam);
            q->marcas[i]=mmin->marcas[i];
        }
        for(i=0;i<tam;i++)
            for(k=0;k<tam;k++)
                q->matriz[i][k]=mmin->matriz[i][k];
        q->contador=num;
        q->marcas[ciudad]=1;
        q->sig=NULL;
        q->ciudad=j;
        q->costo=0;
        q->mc=0;
        min=q->matriz[ciudad][j];
        if(min!=999)
            q->costo=mmin->costo+min;
        else
            q->costo=mmin->costo;
        bloquear(q,tam,ciudad,j);
        costo(q,tam);
        aux=(struct Lista *)p;
        while(aux->sig!=NULL)
            aux=aux->sig;
        aux->sig=q;
    }
    return p;
}

int main(){
    int tam, num=1, ciudad=0, min;
    struct Lista *mmin, *aux;
    void *p=NULL;
    mmin = NULL;

    printf("Introduce el numero de ciudades: ");
    scanf("%d",&tam);
    p=guardar(p,mmin,tam,num,0,0);
    mmin=(struct Lista *)p;
    do{
        //Mientras el num no sea igual al numero de ciudades el arbol no ha terminado, sigue recorriendo
        //los caminos que hacen falta y detectando los menores
        aux=(struct Lista *)p;
        num=num+1;
        {
            int i;
            for(i=0;i<tam;i++)
                if(mmin->marcas[i]!=1)
                    p=guardar(p,mmin,tam,num,ciudad,i);
        }
        min=999;
        while(aux!=NULL){
            if(aux->costo<min && aux->mc!=1){
                min=aux->costo;
                mmin=aux;
            }
            aux=aux->sig;
        }
        ciudad=mmin->ciudad;
        mmin->marcas[ciudad]=1;
        mmin->mc=1;
        num=mmin->contador;
    }while(num!=tam);

    printf("\n\n   Recorrido de costo minimo \n\nCosto minimo: %d\n",mmin->costo);
    system("pause");
    return 0;
}

