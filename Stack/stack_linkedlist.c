#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;  // düğüm yapısını oluşturduk
};
 
struct node* top = NULL;
struct node * tmp = NULL;

void push(struct node*head, int x){
    struct node * yeni = (struct node *)malloc(sizeof(struct node)); // yeni bir node oluşturduk
    yeni->data=x;
    
    
    if (top== NULL) { // Eleman yok demek
        
        top=yeni;
        top->next=NULL;
        
    }
    else{
        yeni->next=top; // eleman varsa yeni elemanı top ın üstüne ekledik  
        top = yeni; // yeni top ımız son eklediğimiz yani en üstteki eleman oldu
    }

}

void pop(struct node* head){
    if(top==NULL)
        printf("cikartilacak eleman yok");
    else{
        tmp=top;
        top=tmp->next;
        free(tmp);
    }
}


int main(){

struct node* s= top; // top nodunu yeni bir noda atıyoruz. böylece s nodunda bir stack yapısı oluşturacağız. 
/*struct node* s1 = NULL;  Farklı bir stack oluşturup s1 stack inin içine pushlama yapabiliriz. 
 Bunun için var olan top ı geçici bir değişkene atayıp top ı NULL yaptıktan sonra push veya pop işlemi yeni stackte yapılabilir.
 mesela tmp1=top; tmp1 düğümünü kullanarak s stackini yazdırabiliriz.*/


for(int i=0;i<10;i++){
    push(s,i*10);
}

tmp=top;
while(tmp->next!=NULL){
    printf("%d  ",tmp->data);
    tmp=tmp->next;
}
printf("%d",tmp->data);

}