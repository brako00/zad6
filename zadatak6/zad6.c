#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct lista* poz;
struct lista {
	int el;
	poz next;
};

int ispis(poz);
int push(poz);
int popRED(poz);
int popSTOG(poz);

int main()
{
	struct lista head;
	head.next = NULL;
	char c, k;

	printf("Unesi:\n r za simulaciju reda\n s za simulaciju stoga\n");
	scanf("%c", &c);
	if (c == 'r' || c == 'R')
	{
		while (1)
		{
			printf("Unesi:\n a za push\n b za pop\n x za kraj programa\n\n");
			scanf(" %c", &k);
			switch (k)
			{
			case 'a':
				push(&head);
				ispis(&head);
				break;
			case 'b':
				popRED(&head);
				ispis(&head);
				break;
			case'x':
				ispis(&head);
				return EXIT_SUCCESS;
				break;
			}
		}
	}
	else if (c == 's' || c == 'S')
	{
		while (1)
		{
			printf("Unesi:\n a za push\n b za pop\n x za kraj programa\n\n");
			scanf(" %c", &k);
			switch (k)
			{
			case 'a':
				push(&head);
				ispis(&head);
				break;
			case 'b':
				popSTOG(&head);
				ispis(&head);
				break;
			case'x':
				ispis(&head);
				return EXIT_SUCCESS;
				break;
			}
		}
	}
	else
		printf("Greska pri unosu!");

	return 0;
}

int popRED(poz p)
{
	if (p->next != NULL)
	{
		poz prev = p;
		p = p->next;
		while (p->next != NULL)
		{
			prev = p;
			p = p->next;
		}
		free(p);
		prev->next = NULL;
	}
	return 0;
}

int popSTOG(poz p)
{
	poz q;
	if (p->next != NULL)
	{
		q = p->next;
		p->next = q->next;
		free(q);
	}
	
	return 0;
}

int push(poz p)
{
	poz q = (poz)malloc(sizeof(struct lista));
	srand((unsigned)time(NULL));
	
	q->el = (rand() % 91) + 10;

	q->next = p->next;
	p->next = q;

	return 0;
}
int ispis(poz p)
{
	p = p->next;
	if (p == NULL)
		printf("Lista je prazna!\n");
	else 
	{
		printf("Lista glasi: \n");
		while (p != NULL)
		{
			printf("  %d", p->el);
			p = p->next;
		}
		printf("\n");
	}
	return 0;
}