
//DATA STRUCTURES IN C MINI PROJECT :


#include <stdio.h>
#include<stdlib.h>
#include<string.h>


//functions declaration:

void locscreen();

int forgotpassword();

void home();

int print();

struct contact *insert(char *nam, int n,struct contact *head);

void traverse(struct contact *head);

int display();

struct passwords *inserting(char *web,char *account,char *key,struct passwords *head1);

void traversal(struct passwords *head1);

void traversecontact(struct contact *head);

void deletecontact();

void traversepassword(struct passwords *head1);

void deleteaccount();

//structures for saving contacts:
struct contact{
char name[100];
int num;
struct contact *next;
}*tail,*head=NULL;


//structures for saving passwords:
struct passwords{
    char web_name[20];
    char account[100];
    char password[10];
    struct passwords *next;
}*tail1,*head1=NULL;


//locscreen funtion is created to open the screen lock with password:
void locscreen(){
    int lock,i=0,ans;
  
  printf("use your lock screen password:");
  while(1){
      scanf("%d",&lock);
  if(1234==lock){
       home();
  }
  else if(i<3){
          i++;
      printf("\nplease enter correct password:");
      }
      
      else{
          printf("\n Have you forgot your password: ");
          printf("yes=1 or no=0: ");
          scanf("%d",&ans);
          if(1==ans){
            forgotpassword();
          }
          else{
          printf("\ntry again after few seconds");
          }
      }
  
  }
 
}


//forgot function is created: if lock screen password is forgotten
int forgotpassword() {
   int i=0,y; 
    char owner[] = "Ridhi";
    char gender[] = "female";
    long long int mobile_number = 911234506789;

    char name[20];
    char Gender[10];
    char number_str[20];
    long long int number;

    printf("Make sure that your answers are correct:\n");

    printf("Enter the name: ");
    scanf("%s",name);
    printf("\nenter the gender:");
    scanf("%s",Gender);
    printf("\n enter mobile number:");
    scanf("%lld",&number);
    

    if (strcmp(owner, name) == 0 && strcmp(gender, Gender) == 0 && number == mobile_number) {
        printf("Congrats! You unlocked:\n");
        printf("Your lock screen password: 1234\n");
        printf("Use this password to unlock your home screen.\n");
    }
    else if(i<3){
        i++;
        printf("\n Do you want to try it again:");
        printf("yes =1 or no=0 : ");
        if(y==1){
            forgotpassword();
        }
        else 
        return 0;
        
    }
    else {
        printf("Incorrect information. Access denied.\n");
       printf("\nplease try again after few seconds");
       
    }

     return 0; 
}


//home function for selecting an option 
void home(){
    int option,p,i;
 printf("for contact saving click :1\n");
 printf("for saving any account ID's click :2\n");
 printf("select your option: ");
 
   scanf("%d",&option);
   switch(option){
       case 1:
         print();
         printf("do you want to save any account ID's password:");
         printf("yes=1 or no=0: ");
         scanf("%d",&i);
         if(i==1)
          display();
         break;
       case 2:
        display();
      printf("do you want to save any contact: ");
         printf("yes=1 or no=0: ");
         scanf("%d",&i);
         if(i==1)
         print();
        
        break;
        default :
        printf("please select a option:\n");
        break;
   }
   printf("to see your contacts click:1\n");
   printf("to check passwords click: 2");
   printf("\nto get a contact click : 3 ");
   printf("\nto delete a contact click : 4 ");
    printf("\nto get a ID's password click : 5 ");
    printf("\nto delete a account details click : 6 ");
    printf("\nselect your option: ");
   scanf("%d",&p);
   
   if(p==1){
   traverse(head);
   }
   
   else if(p==2){
       traversal(head1);
   }
 
   else if (p==3){
      traversecontact(head); 
   }
   else if (p==4){
       
       deletecontact();
   }
   else if (p==5){
       traversepassword(head1);
   }
   else if (p==6){
       deleteaccount();
   }

}


//function for displaying to save contact numbers: 
int print(){
    
    int number,choice;
    char namee[1000];
     printf("contact name: ");
    scanf("%s",namee);
    printf("\nmobile number:");
    scanf("%d",&number);
    head=insert(namee,number,head);
    printf("\ndo you want to add another contact?(1=yes/0=no):");
    scanf("%d",&choice);
    if(choice==1)
    print();
    else
    return 0;
    
}


//inserting the the data of contacts using linked list; 
struct contact *insert(char *nam, int n,struct contact *head){

    struct contact *nn=malloc(sizeof(struct contact));
    nn->next=NULL;
    strcpy(nn->name,nam);
    nn->num=n;
      
      if(head==NULL){
        head=nn;
        tail=nn;
      }
      else{
        tail->next=nn;
        tail=nn;
      }
      return head;
}


//to show the saved contacts:
void traverse(struct contact *head){
    struct contact *t=head;
    while(t!=NULL){
        printf("name  : %s\n",t->name);
        printf("number: %d\n",t->num);
        t=t->next;
    }
    
}


//function for displaying to save any social media account passwords:
int display(){
    int choice;
    char account[100],key[10],webname[20];
    printf("\nAccount ID:");
    scanf("%s",account);
    printf("\nwebsite name:");
    scanf("%s",webname);
    printf("\nyour password(don't use any special characters):");
    scanf("%s",key);
    head1=inserting(webname,account,key,head1);
    printf("\ndo you want to save other account?");
    printf("[yes=1 or no=0]:");
    scanf("%d",&choice);
    if(choice==1){
       display() ;
    }
    else 
    return 0;
}


//inserting the the data of passwords  using linked list; 
struct passwords *inserting(char *web,char *account,char *key,struct passwords *head1){
    struct passwords *nn=malloc(sizeof(struct passwords));
     strcpy(nn->web_name,web);
    strcpy(nn->account,account);
    strcpy(nn->password,key);
    nn->next=NULL;
    if(head1==NULL){
        head1=nn;
        tail1=nn;
    }else{
        tail1->next=nn;
        tail1=nn;
    }
    return head1;
}


//to show the saved passwords of respective accounts:
void traversal(struct passwords *head1){
    struct passwords *t=head1;
    while(t!=NULL){
        printf("website: %s",t->web_name);
        printf("\naccount ID: %s",t->account);
        printf("\npassword:%s\n",t->password);
        t=t->next;
    }
    
}


// searching for a contact in saved contacts:
void traversecontact(struct contact *head){
    struct contact *temp=head;
    char contact_name[100];
    int i=0;
    printf("\nenter contact name: ");
    scanf("%s",contact_name);
    while(temp!=NULL){
    if(strcmp(temp->name,contact_name)==0){
        i++;
        printf("contact : %s",temp->name);
        printf("\nnumber: %d",temp->num);
        break;
    }
    else{
        temp=temp->next;
    }
  }
    if(i==0){
        printf("\n contact not found");
    }
   
}


//function code to delete any contact :
void deletecontact() {
    struct contact *temp = head;
    struct contact *prev = NULL;
    char contact_name[100];
    int found = 0, yes;

    printf("\nEnter contact name to delete: ");
    scanf("%s", contact_name);

    while (temp != NULL) {
        if (strcmp(temp->name, contact_name) == 0) {
            found = 1;

            // Deleting head node
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);
            printf("%s Contact deleted successfully.\n",temp->name);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if (!found) {
        printf("Contact not found.\n");
    }
    printf("do you wat to check saved contact click(1): ");
    scanf("%d",&yes);
    if(yes==1){
    traverse(head);
    }
}


// searching for a ID's password  in saved details:
void traversepassword(struct passwords *head1){
    struct passwords *temp=head1;
    char account_id[100];
    int i=0,lock;
     printf("\nenter lock password: ");
    scanf("%d",&lock);
    if(lock==1234){
    printf("\nenter account ID: ");
    scanf("%s",account_id);
    while(temp!=NULL){
    if(strcmp(temp->account, account_id)==0){
        
        i++;
        printf("account's ID: %s",temp->account);
        printf("\npassword: %s",temp->password);
        break;
    }
    
    else{
        temp=temp->next;
    }
    
   }
   
    if(i==0){
        printf("\n results not found");
    }
  }
   
}


//function code to delete any account details:
void deleteaccount() {
    struct passwords *temp = head1;
    struct passwords *prev = NULL;
    char account_id[100];
    int found = 0, yes;

    printf("\nEnter account ID to delete: ");
    scanf("%s", account_id);

    while (temp != NULL) {
        if (strcmp(temp->account, account_id) == 0) {
            found = 1;

            // Deleting head node
            if (prev == NULL) {
                head1 = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);
            printf("%s deleted successfully.\n",temp->account);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if (!found) {
        printf("results not found.\n");
    }
    printf("do you want to check saved account details click(1): ");
    scanf("%d",&yes);
    if(yes==1){
    traversal(head1);
    }
}


int main() {
    
     locscreen();
     
     printf("\n THANK YOU");
    return 0;
}
