#include <stdio.h>
#include <stdlib.h>


typedef struct Stack
{
    int top; 
    int *array;
    unsigned capacity;
}stk;

stk* createStack(unsigned capacity){
    stk* yeni= (stk*) malloc(sizeof(stk));
    yeni->top=-1;
    yeni->capacity=capacity;
    yeni->array= (int*) malloc(sizeof(int)* yeni->capacity); 
    return yeni;
}

void push(stk * yeni,int x){
    if(yeni->top == yeni->capacity-1){
        return;
    }
    yeni->top++; // top ımız en başta -1 idi ondan dolayı arttırıp. 0.indexine ekledik.
    yeni->array[yeni->top]= x;
}

void pop(stk*yeni){
    if (yeni->top==-1)
        return;
    
    int item= yeni->array[yeni->top];
    yeni->top--;
    printf("\n %d Sayisi cikarildi",item);        
}


void yazdir(stk*yeni){
    int i=0;
   /* for(i; i < (yeni->top+1) ; i++)     <bu şekilde ilk verdiğimiz değerden ileriye doğru yazdırır>
        printf("%d \t",yeni->array[i]);  */
    for(int j= yeni->top;j>-1;j--) 
        printf("%d \t",yeni->array[j]);   
}


int main()
{
stk* y1 = createStack(10); // 10 kapasiteli bir stack oluşturduk

for(int i=0;i<10;i++){  //
    push(y1,i);
}
/*yazdir(y1);
pop(y1);
pop(y1);
yazdir(y1);*/
while (1){
    int secim;
    printf("Yapmak istediginiz islemi secin: \n1- eleman ekleme  \n2-eleman cikarma \n3-yazdirma\n4-cikis");
    scanf("%d",&secim);
    int a;
    switch (secim)
    {
    case 1:
    scanf("%d",&a);
    push(y1,a);
        break;
    case 2:
    pop(y1);
        break;
    case 3:
    yazdir(y1);
        break;
    case 4:
    printf("cikis yapiliyor");
    return 0;
    
            
    }

 


}

}
