#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h> // __fpurge(stdin);

#define NAME_MAX_LEN    100
#define LINE_MAX_LEN    1000

struct st_data {
    int id;
    char name[NAME_MAX_LEN];
    char gender;
};
typedef struct st_data DATA;

struct st_node {
    DATA data;
    struct st_node *next;
};
typedef struct st_node NODE;

void insert_top(NODE **, DATA *);
void print_list(NODE *);
int sizeof_node(NODE *);
int is_empty(NODE *);
NODE* find_by_id(NODE *current, int id);
NODE* delete_by_id(NODE **TOP, int id);
void save(NODE *ptr);
void insert_ordered(NODE **TOP, DATA *data);
void reverse(NODE **TOP);
void save(NODE *);
void load (NODE **);
int load_csv (NODE **TOP, char *file, char *delimiter);
void remove_newline_ch(char *line);
void swap(NODE *a, NODE *b);
void bubble_sort(NODE *start);
void fake (NODE **);

int main(void) {
    NODE *TOP = NULL;
    char opcion;
    int n;
    char filename[100];
    int id;

    load(&TOP);
    
    do
    {
        printf( "\n   1. Agregar elementos de prueba a la lista (fake)");
        printf( "\n   2. Agregar elementos desde un archivo .csv" );
        printf( "\n   3. Guardar");
        printf( "\n   4. Imprimir la lista");
        printf( "\n   5. Ordenar la lista");
        printf( "\n   6. Invertir la lista");
        printf( "\n   7. Buscar por ID");
        printf( "\n   8. Eliminar por ID");
        printf( "\n   9. Salir." );

        do
        {
            printf( "\n   Introduzca opcion (1-9): ");
            scanf( "%c", &opcion );
            __fpurge(stdin);

        } while ( opcion < '1' || opcion > '9' );

        switch ( opcion )
        {
            case '1': fake(&TOP);
                      break;

            case '2': load_csv(&TOP, "data.csv", ",");
                      break;

            case '3': save(TOP);
                      break;
            
            case '4': print_list(TOP);
                      break;  
            
            case '5': bubble_sort(TOP);
                      break;  
            
            case '6': reverse(&TOP);
                      break;  
            
            case '7':   printf("Ingrese el ID:");
                        scanf("%d", &id);
                         __fpurge(stdin);
                        NODE *foundLink = find_by_id(TOP, id);
                        if(foundLink != NULL) {
                            printf("Element found: ");
                            printf("\t(%d,%s,%c)\n",foundLink->data.id,foundLink->data.name, foundLink->data.gender);
                            printf("\n");  
                        } else {
                            printf("Element not found\n");
                        }
                        break;  

            case '8':   printf("Ingrese el ID:");
                        scanf("%d", &id);
                         __fpurge(stdin);
                        delete_by_id(&TOP, id);
                        break;  


         }

    } while ( opcion != '9' );

    save(TOP);

    return 0;  
  
}


//display the list
void print_list(NODE *ptr) {
   printf("[\n");
	
   while(ptr != NULL) {
      printf("\t(%d,%s,%c)\n",ptr->data.id,ptr->data.name, ptr->data.gender);
      ptr = ptr->next;
   }
	
   printf("]\n");
}

//insert link at the first location (top)
void insert_top(NODE **TOP, DATA *data) {
   //create a node
   NODE *n = (NODE*) malloc(sizeof(NODE));
	
   // asign data
   n->data = *data;
	
   //point it to old first node
   n->next = *TOP;
	
   //point first to new first node
   *TOP = n;
}

// devuelve el tamaño en nodos de la lista
int sizeof_node(NODE *TOP) {
   int length = 0;
   NODE *current;
	
   for(current = TOP; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}


//is list empty
int is_empty(NODE *TOP) {
   return TOP == NULL;
}

//find a link by id
NODE* find_by_id(NODE *current, int id) {

   //if list is empty
   if(is_empty(current)) {
      return NULL;
   }

   while(current->data.id != id) {
	
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return current;
}

//delete a node by id
//si id's hay duplicados, borro solo uno!
NODE* delete_by_id(NODE **TOP, int id) {
   NODE* current = *TOP;
   NODE* previous = NULL;
	
   //if list is empty
   if(*TOP == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->data.id != id) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == *TOP) {
      //change first to point to next link
      *TOP = (*TOP)->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
	
   return current;
}

// guarda la base de datos en el archivo
void save(NODE *ptr){
    FILE *fp;

    if(is_empty(ptr)) {
        return;
    }

    fp = fopen("database.dat", "w");
    if ( fp == NULL){
        printf("Error open database.dat\n");
        return;
    }

    while(ptr != NULL) {
        fwrite( &(ptr->data), sizeof(DATA), 1, fp);
        ptr = ptr->next;
    }
    fclose(fp);
}      

// carga la base de datos desde el archivo
void load(NODE **TOP){
    FILE *fp;
    DATA data;

    fp = fopen("database.dat", "r");
    if ( fp == NULL){
        printf("Error open database.dat\n");
        return;
    }

    while (fread( &data, sizeof(data), 1, fp) == 1){
        insert_top(TOP, &data);
    }
    
    fclose(fp);
}      



// insert ordered by id
// suppose the list is pre-sorted
void insert_ordered(NODE **TOP, DATA *data) {
    NODE *current = *TOP;
    NODE *before = NULL;

    //create a node
    NODE *n = (NODE*) malloc(sizeof(NODE));
    // asign data
    n->data = *data;
    n->next = NULL;

    //if is the first node (empty)
    if ( *TOP == NULL){
        *TOP = n;
        return;
    }

    while(current != NULL) {
        if ( n->data.id <= current->data.id){
            // firts
            if (current == *TOP){
                //point it to old first node
                n->next = *TOP;
	            //point first to new first node
                *TOP = n;
                return ;
            }
            else {
                n->next = current;
                before->next = n;
                return;
            }
        }
        before = current;
        current = current->next;
    }
    // if is last one
    before->next = n;
    return;
}


// invierte la lista
void reverse(NODE **TOP) {
   NODE* prev   = NULL;
   NODE* current = *TOP;
   NODE* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *TOP = prev;
}


// carga la lista desde un archivos csv
int load_csv (NODE **TOP, char *file, char *delimiter){
    FILE *fp;
    char buff[LINE_MAX_LEN];
    char *token;
    DATA data;
   
    fp = fopen(file, "r");
    if (fp == NULL){
        printf("Error al abrir csv\n");
        return -1;
    }

    while(fgets(buff, sizeof(buff), fp) != NULL){
        // limpiar el \n si existe
        remove_newline_ch(buff);
        
        // primer llamada...primer tocken (campo del csv)
        token = strtok(buff, delimiter);
        if (token == NULL)
            continue;
        // si es la primer linea la salteo, es el encabezado del csv
        if (strcmp(token,"id") == 0){
            continue;
        }
        data.id = atoi(token);
      
        // siguentes llamadas...siguientes token (campos del csv), se llama con NULL
        token = strtok(NULL, delimiter);
        if (token == NULL)
            continue;
        strcpy(data.name, token);

        token = strtok(NULL, delimiter);
        if (token == NULL)
            continue;
        data.gender = token[0];

        //printf("debug::data=(%d,%s,%c)\n", data.id, data.name, data.gender);

        // aseguro que la lista este ordenada
        bubble_sort(*TOP);

        // add to list 
        insert_ordered(TOP, &data);

    }
    return 0;
}


void remove_newline_ch(char *line){
    int new_line = strlen(line) -1;
    
    if (line[new_line] == '\n')
        line[new_line] = '\0';
}


/* function to swap data of two nodes a and b*/
void swap(NODE *a, NODE *b){ 
    DATA temp;
    
    temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 


/* bubble sort the given linked list */
void bubble_sort(NODE *start){ 
    int swapped, i; 
    NODE *ptr1; 
    NODE *lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data.id > ptr1->next->data.id) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

void fake(NODE **TOP){
    DATA d1 = {3,"Nadia Eyers",'F'};
    DATA d2 = {1,"Cully Poundsford",'M'};
    DATA d3 = {2,"Hortense Voaden",'F'};
    DATA d4 = {20,"Juana Perez",'F'};
    DATA d5 = {7,"Juan Rodriguez",'M'};
    DATA d6 = {0,"Alberto Martinez",'M'};

    insert_top(TOP, &d1);
    insert_top(TOP, &d2);
    insert_top(TOP, &d3);
    insert_top(TOP, &d4);
    insert_top(TOP, &d5);
    insert_top(TOP, &d6);

    // insert_ordered(TOP, &d1);
    // insert_ordered(TOP, &d2);
    // insert_ordered(TOP, &d3);
    // insert_ordered(TOP, &d4);
    // insert_ordered(TOP, &d5);
    // insert_ordered(TOP, &d6);

}