#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<string.h>
#include<malloc.h>

//struct
struct record {
	char name[100];
	int age;
	float weight;
};

//linked list 
struct Node {
	struct record rec;
	struct Node* next;
};


//adds patients information to the list 

void addInformation(struct Node** head, struct record newRecord) {

	// new node
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->rec = newRecord;

	//if the list is empty
	if (*head == NULL) {
		newNode->next = NULL;
		*head = newNode; 
		return;
	}

	//only one
	if ((*head)->next == NULL) {
		if (strcmp((*head)->rec.name, newRecord.name) > 0) {
			newNode->next = *head;
			*head = newNode;
			return;
		}
		(*head)->next = newNode;
		newNode->next = NULL;
	}

	//remembering pointer.
	struct Node* curr = (*head)->next;
	struct Node* prev = *head;
	while (curr) {
		if (strcmp(curr->rec.name, newRecord.name) > 0) {
			newNode->next = curr;
			prev->next = newNode;
			return;
		}
		prev = curr;
		curr = curr->next;
	}

	//if new node added
	prev->next = newNode;
	newNode->next = NULL;
}


//displays patient information
void displayInformation(struct Node* head) {
	int i = 1;
	struct Node* curr = head;

	//display of all options
	while (curr) {
		printf("%d.\n", i);
		printf("Name: %s\n", curr->rec.name);
		printf("Age: %d\n", curr->rec.age);
		printf("Weight: %.2f\n\n", curr->rec.weight);
		i++;
		curr = curr->next;
	}
}

//main
int main() {
	//if null
	struct Node* head = NULL;
	int option = 1;
	

	while (option != 3) {
		struct record newRecord;
		//menu
		printf("\n Patient Information\n");
		printf("\n *******MENU*******\n");
		printf("\n ******************\n");
		printf("\n Selest an option\n");
		printf("1.Insert patient information\n");
		printf("2.Display patient information\n");
		printf("3. Quit\n");

		//scan for options
		scanf("%d", &option);
		switch (option) {

			//if option 1 is selected
		case 1:
			printf("Enter patients name:\n");
			//scan
			scanf("%s", newRecord.name);
			//age
			printf("Enter patients age:\n");
			//scan
			scanf("%d", &newRecord.age);
			//enter patient weight
			printf("Enter weight:\n");
			//scan
			scanf("%f", &newRecord.weight);
			addInformation(&head, newRecord);
			break;
		//if option 2 is selected
		case 2:
			displayInformation(head);
			break;
		//if option 3 is selects
		case 3:
			break;
		//default shown after selection displayed
		default:
			printf("Select another option\n");
			break;
		}
	}
	return 0;
}