#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node {
    int data;
    struct Node* next;
};

// Kuyruk yap�s�n�n tan�mlanmas�
struct Queue {
    struct Node *front, *rear;
};

// Yeni bir d���m olu�turma(Eleman eklemek i�in)
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));//Gerekli  alan a��l�r.
    node->data = data;
    node->next = NULL;
    return node;
}

// Yeni bir kuyruk olu�turulur.(Eleman eklemek i�in)
struct Queue* yenikuyruk() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));//Gerekli alan a��l�r.
    q->front = q->rear = NULL;
    return q;
}

// Kuyru�a eleman ekler
void enqueue(struct Queue* q, int data) {
    struct Node* node = newNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = node;
        return;
    }
    q->rear->next = node;
    q->rear = node;
}

// Kuyruktan eleman ��kar�r
void dequeue(struct Queue* q) {
    if (q->front == NULL) {//Kuyru�un bo� olma durumu kontrol edilir.
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

// Kuyruktaki t�m elemanlar� g�r�nt�ler
void goruntuleme(struct Queue* q) {
    if (q->front == NULL) {
        printf("Kuyruk bos\n"); // kuyrukta eleman yoksa bu mesaj ekrana yaz�l�r.
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
	struct Queue* q = yenikuyruk();// Fonkisyon �al��t�r�l�r.
    int data;
	int secim;
	
	
	printf("Lutfen asag�daki islemlerden birini seciniz.\n ");
	printf("1. Ekleme\n ");
	printf("2. Silme\n ");
	printf("3. Goruntuleme\n ");
	printf("4. Cikis\n ");
	
	scanf("%d",&secim);
		
		switch(secim) {
			
			case 1://Eleman ekleme i�leminin yap�ld�p� case.
			printf("Ekleme islemi secildi\n");
			printf("Eklenecek elemani secin");
			scanf("%d",&data);
			enqueue(q,data);//enqueue ile kullan�c�dan al�nm�� olan eleman kuyru�a eklenir.
			break;
			
			case 2://Eleman silme i�leminin yap�ld��� case.
			printf("Silme islemi secildi\n");
			dequeue(q);//dequeue ile kuyruktan silme i�lemi yap�l�r.
			break;
			
			case 3://Kuyru�un g�r�nt�leme i�leminin yap�ld��� case.
			printf("Goruntuleme islemi secildi\n");
			goruntuleme(q);
			break;
			
			case 4://Programdan ��k���n yap�ld��� case.
			printf("cikis yapildi");	
			exit(0);
			
			default:// Belirtilen 4 i�lem d���nda herhangi bir i�lem se�ilirse a�a��da bir hata mesaj� yaz�l�r.
			
			printf("Boyle bir islem bulunmamaktadir.");
			
		}
			
			
			
			
			
		
		
		
		
		
		
		
	
	return 0;
}
