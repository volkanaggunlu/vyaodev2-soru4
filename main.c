#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node {
    int data;
    struct Node* next;
};

// Kuyruk yapýsýnýn tanýmlanmasý
struct Queue {
    struct Node *front, *rear;
};

// Yeni bir düðüm oluþturma(Eleman eklemek için)
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));//Gerekli  alan açýlýr.
    node->data = data;
    node->next = NULL;
    return node;
}

// Yeni bir kuyruk oluþturulur.(Eleman eklemek için)
struct Queue* yenikuyruk() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));//Gerekli alan açýlýr.
    q->front = q->rear = NULL;
    return q;
}

// Kuyruða eleman ekler
void enqueue(struct Queue* q, int data) {
    struct Node* node = newNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = node;
        return;
    }
    q->rear->next = node;
    q->rear = node;
}

// Kuyruktan eleman çýkarýr
void dequeue(struct Queue* q) {
    if (q->front == NULL) {//Kuyruðun boþ olma durumu kontrol edilir.
        printf("Kuyruk bos\n");
        return;
    }
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

// Kuyruktaki tüm elemanlarý görüntüler
void goruntuleme(struct Queue* q) {
    if (q->front == NULL) {
        printf("Kuyruk bos\n"); // kuyrukta eleman yoksa bu mesaj ekrana yazýlýr.
        return;
    }
    struct Node* current = q->front;
    printf("Kuyruk elemanlari: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


int main(int argc, char *argv[]) {
	struct Queue* q = yenikuyruk();// Fonkisyon çalýþtýrýlýr.
    int data;
	int secim;
	
	
	printf("Lutfen asagýdaki islemlerden birini seciniz.\n ");
	printf("1. Ekleme\n ");
	printf("2. Silme\n ");
	printf("3. Goruntuleme\n ");
	printf("4. Cikis\n ");
	
	scanf("%d",&secim);
		
		switch(secim) {
			
			case 1://Eleman ekleme iþleminin yapýldýpý case.
			printf("Ekleme islemi secildi\n");
			printf("Eklenecek elemani secin");
			scanf("%d",&data);
			enqueue(q,data);//enqueue ile kullanýcýdan alýnmýþ olan eleman kuyruða eklenir.
			break;
			
			case 2://Eleman silme iþleminin yapýldýðý case.
			printf("Silme islemi secildi\n");
			dequeue(q);//dequeue ile kuyruktan silme iþlemi yapýlýr.
			break;
			
			case 3://Kuyruðun görüntüleme iþleminin yapýldýðý case.
			printf("Goruntuleme islemi secildi\n");
			goruntuleme(q);
			break;
			
			case 4://Programdan çýkýþýn yapýldýðý case.
			printf("cikis yapildi");	
			exit(0);
			
			default:// Belirtilen 4 iþlem dýþýnda herhangi bir iþlem seçilirse aþaðýda bir hata mesajý yazýlýr.
			
			printf("Boyle bir islem bulunmamaktadir.");
			
		}
			
			
			
			
			
		
		
		
		
		
		
		
	
	return 0;
}
