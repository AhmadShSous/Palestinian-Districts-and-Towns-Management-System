//Name :Ahmad Shaher Ahmad Sous
//Number :1221371     .......        section:4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 51  // The size is 50 and the last for '\0'

/*Abstract for project:- My project, I will make empty node without data (Head) to point to The first district
and each District is (Head) for its Towns
and  there are pointer in each district to point previous district (but the first District its previous point to Head)
and  there are pointer in each town to point previous town (but the first town its previous point to Null)
*/



//.......................................................................................
int count=0;                     //to check if districts sorted
int count2=0;                    //to check if towns sorted
struct node1 {                     //node for each District
    char Data[SIZE];
    int allPopulation;             // To store all populations for all towns in each district
    struct node1* nextDistrict;    //pointer to point to next district
    struct node2* nextTown;        //pointer to point first town in each district to make each district head for its towns
    struct node1* prevDistrict;    //pointer to point previous District
};


struct node2 {                      // node for each town
    char Data[SIZE];
    int population;
    struct node2* prevTown;         //pointer to point previous town
    struct node2* nextTown;         //pointer to point to next town
};
//...............................................................................................
void deleteFirstAndLastSpaces(char str[]);
struct node2* findTown(char x[],struct node1* L);
struct node1* findDistrict(char x[],struct node1* L);
void readStringWithSpace(char str[]);
int isLastTown(struct node2* L);
struct node2* findLastTown(struct node1* L);
struct node1* findLastDistrict(struct node1* L);
void insertDistrict(char x[], struct node1* L) ;
void insertTown(char x[],int population , struct node1* L);
void loadTheInputFile(struct node1* Head);
void printList(struct node1* L);
void insertNewDistrict(struct node1* Head);
void insertNewTown(struct node1* Head);
struct node2* findTownFromAllDistrict(char town[],struct node1* Head);
struct node1* findDistrictFromTown(struct node2* Town, struct node1* Head);
int isThereAreAnytown(struct node1* Head);
void deleteTown(struct node1* Head);
void deleteDistrictAndAllTowns(struct node1* Head);
void PrintDistrictsAndTheirTotalPopulation(struct node1* Head);
void changePopulation(struct node1* Head);
int getMaxLength(struct node1* Head);
void reverseData(struct node1* Head, struct node1* a[]);
void sortDistrict(struct node1* Head);
void sortTowns(struct node1* District);
void sortAllTowns(struct node1* Head);
void printinglistwithallpopulation(struct node1* L);
void calculatePopulation(struct node1* Head);
void printOutput (struct node1* L);
void selectOpition(struct node1* Head);
void deleteAllLinkedList(struct node1* Head);
//......................................................................................
int main() {
    struct node1* Head = (struct node1*)malloc(sizeof(struct node1));
    Head->nextDistrict = NULL;
    Head->nextTown = NULL;
     selectOpition(Head);
    return 0;
}

//.........................................................................


//..........................................................................
void deleteFirstAndLastSpaces(char str[]) {
    int len = strlen(str);
    int i = 0;

    // Find the index of the first character that without space
    while (isspace(str[i])) {  //to check if space or not
        i++;
    }

    if (i > 0) {
        for (int j = 0; j < len - i + 1; j++) {//shifting character in left and the first space delete
            str[j] = str[j + i];
        }
    }

    len = strlen(str);
    while (isspace(str[len - 1])) {// to remove all spaces in last of string
        str[len - 1] = '\0';
        len--;
    }
}


//.....................................................................................
// to check if district find or not if find return district node for it if not return Null

struct node1* findDistrict(char x[],struct node1* L){  //L is Haed to point to first district and x is district name(linkedlist)
struct node1* temp = L->nextDistrict;    //temp is district node that function return and it is first district
while(temp!=NULL){                       //to check all districts to know if find or not
 if(strcmp(temp->Data,x)== 0) return temp;
 temp = temp->nextDistrict;
}
return NULL;                            //if district not found return NULL
}

//............................................................................................
// to check if Town find or not for one district if find return town node for it if not return Null

struct node2* findTown(char x[],struct node1* L){  //L is District that want check if contain town
struct node2* temp1 = L->nextTown;                 //temp1 is town node that function return and it is first town
while(temp1!= NULL ){                              //to check all Town in one District to know if town find or not
    if(strcmp(temp1->Data,x)==0) return temp1;
    temp1= temp1->nextTown;
}

return NULL;                                         //if town not found return NULL
}

//................................................................................................
// to check if this town last town or not in one district

int isLastTown(struct node2* L){                //L  is town that you want check
return L->nextTown==NULL;                       //if last return 1 if not return 0
}

//.......................................................................................................
//to to check if this town last town or not in one district but if found return its node if not return NULL

struct node2* findLastTown(struct node1* L){     //L  is district that contain town
struct node2* temp= L->nextTown;                 //temp is town node that function return and it is first town
while(temp!=NULL){                               //to reach to last town to check it one by one
        if(temp->nextTown==NULL) return temp;    //to check if it is last town or not if last return it
       temp= temp->nextTown;                     //increase one by one linear
}
return NULL;                                     //if town is not last or not found return NULL
}

//.....................................................................................................
//to to check if this District last district or not  but if found return its node if not return NULL

struct node1* findLastDistrict(struct node1* L){  //L  is Head to point to first district
struct node1* temp= L->nextDistrict;              //temp is first district
while(temp!=NULL){                                //to check all districts  one by one linear
        if(temp->nextDistrict==NULL) return temp; //to check if temp is last district or not
       temp= temp->nextDistrict;                  //change district one by one
}
return NULL;                                      //if district is not last or not found return NULL
}

//....................................................................................................
//to  insert District in last in linked list
void insertDistrict(char x[], struct node1* L) { //x is string district and L is Head to point to first district (Linketlist)
if(findDistrict(x,L)== NULL){                    //if District is not found before
struct node1* temp = (struct node1*)malloc(sizeof(struct node1));  //reversed in memory node to insert it in linkedlist
    strcpy(temp->Data, x);
    temp->allPopulation = 0;                                       //all populations for all towns in each district
    temp->nextDistrict = NULL;
    temp->nextTown = NULL;
                                   // Find the last district and insert the new district
    struct node1* lastDistrict = findLastDistrict(L);
    if (lastDistrict == NULL) {            // insert first district in linked list
        temp->prevDistrict=L;
        L->nextDistrict = temp;
    } else {                              //insert in last and Head doesn't point to NULL
        temp->prevDistrict=lastDistrict;
        lastDistrict->nextDistrict = temp;
    }
}

}


//................................................................................................
//to  insert Town in last in linked list for each district
void insertTown(char x[],int population , struct node1* L) { //x is string town and L is Head (each district)
    struct node2* temp = (struct node2*)malloc(sizeof(struct node2));
    struct node2* lastTown = findLastTown(L);
    strcpy(temp->Data, x);
    temp->population= population;
    temp->nextTown = NULL;
    if(lastTown==NULL) {   //insert first town if Head(each district) point to NULL
     temp->prevTown=NULL;
     L->nextTown = temp;
    }
    else{                 //insert in last and Head doesn't point to NULL
    temp->prevTown=lastTown;
    lastTown->nextTown = temp;
 }
    L->allPopulation+= population; //increase population of each district by add population town

}


//.................................................................................................
//to load data from file to linkedlist  then separate words and store word to linkedlist option 1

void loadTheInputFile(struct node1* Head) {
    FILE* input;
    input = fopen("districts.txt", "r");
    char line[200];
    char district[SIZE];
    char town[SIZE];
    char pop[50];
    int population;
    int flag =0;
    while (fgets(line, sizeof(line), input)) { //read line line from file
            flag =1;
        strcpy(district, strtok(line, "|"));    //separate district from line
        deleteFirstAndLastSpaces(district);     // delete space from first and end if it found
       if(findDistrict(district,Head)== NULL) insertDistrict(district, Head);  //if district not found before store it
          strcpy(town, strtok(NULL, "|"));      //separate town from file
         deleteFirstAndLastSpaces(town);        // delete space from first and end if it found
          strcpy(pop, strtok(NULL, "|"));      // separate population from file
        population = atoi(pop);                 // convert string population to integer by atoi
         //if town not found in district before store it
        if(findTown(town,findDistrict(district,Head))==NULL)      insertTown(town,population,findDistrict(district,Head));
    }

    fclose(input); // Close the file after reading
  if(flag)  printf("we loaded data successfuly");
  else printf("There are not any districts in file if you want add choose 6");

    printf("\n\n");
}


//................................................................................................
//to print data as input file option 2
void printList(struct node1* L) {
    FILE* input;
    input = fopen("districts.txt", "r");
    char line[200];
    char district[SIZE];
    char town[SIZE];
    char pop[50];
    int flag =0;
    while (fgets(line, sizeof(line), input)) {
            flag =1;
    strcpy(district, strtok(line, "|"));
        printf("%s|", district);
    strcpy(town, strtok(NULL, "|"));
        printf("%s|", town);
    strcpy(pop, strtok(NULL, "|"));
        printf("%s", pop);
    }

if (flag==0) printf("There are not any districts to print it if you want add choose 6");
    fclose(input); // Close the file after reading
    printf("\n\n");

}


//.............................................................................................................
// to insert new district to linked list option 6
void insertNewDistrict(struct node1* Head){
char district[SIZE];
 getchar();                                                  // wait until user enter character if I don't put it then don't scan in first operation and delete new line is scanning it
printf("please enter new district:- ");
readStringWithSpace(district);
deleteFirstAndLastSpaces(district);     // delete space from first and end if it found
struct node1* foundDistrict = findDistrict(district, Head);
 if(foundDistrict!=NULL){  //to check if district that you enter found or not
 do{
    printf("please enter the new district ,this district %s is really found:- ",district);
      readStringWithSpace(district);
      deleteFirstAndLastSpaces(district);     // delete space from first and end if it found

    foundDistrict = findDistrict(district, Head);
 }while(foundDistrict!=NULL);
}
insertDistrict(district,Head);
sortDistrict(Head);
 printf("we insert the %s district, and if you  want insert towns for it choose option 7", district);
 printf("\n\n");
}

//..............................................................................
void readStringWithSpace(char str[]){  //to read string from user with spaces
    int i = 0;
    char ch ;
    scanf("%c", &ch);
    while ((int)ch != 10 && i < SIZE ) {//to check if you insert new line 10 in ascci table and if less than size
        str[i++] = ch;                     //to store each character in string
        scanf("%c", &ch);
    }

    str[i] = '\0';                        //the end of string

}
//.....................................................................................................
// to insert new town to district option 7
void insertNewTown(struct node1* Head){
 if(Head->nextDistrict!=NULL){//to check if there are any district in linkedlist
 char district[SIZE];
 char town[SIZE];
 getchar();                                                  // wait until user enter character if I don't put it then don't scan in first operation and delete new line is scanning it

 printf("please enter the district which the town located:- ");
   readStringWithSpace(district);
    deleteFirstAndLastSpaces(district);     // delete space from first and end if it found
 struct node1* foundDistrict = findDistrict(district, Head);
 if(foundDistrict==NULL){    //to check if district not found
 do{
    printf("\nplease enter the new district ,this district %s is not found:- ",district);
   readStringWithSpace(district);
   foundDistrict = findDistrict(district, Head);
   deleteFirstAndLastSpaces(district);     // delete space from first and end if it found
 }while(foundDistrict==NULL);
 }
 printf("\nplease enter new town:- ");
   readStringWithSpace(town);
    deleteFirstAndLastSpaces(town);     // delete space from first and end if it found
 struct node2* foundtown= findTown(town,findDistrict(district,Head));
 if(foundtown!=NULL){     //to check if town found
 do{
 printf("please enter another town, this town %s is really found:- ", town);
   readStringWithSpace(town);
    deleteFirstAndLastSpaces(town);     // delete space from first and end if it found
 foundtown= findTown(town,findDistrict(district,Head));
 }while(foundtown !=NULL);
 }
 int population=0;
 printf("please enter the population of %s town:- ", town);
   scanf("%d", &population);
 insertTown(town,population,foundDistrict); //insert new town to old found district
  printf("\nwe insert the town %s in %s district",town, district);
 }
 else printf("There isn't any district to inserts town please choose 6 to insert district");
 printf("\n\n");
}


//...................................................................................................................
//to find town from all districts in linkedlist
struct node2* findTownFromAllDistrict(char town[],struct node1* Head){ //Head to point first district(Linkedlist) and x is town that you want found
struct node1* currentDistrict= Head->nextDistrict;                 //first district
struct node2* currentTown= currentDistrict->nextTown;              //first town in first district current district(Head for its towns)
while(currentDistrict!=NULL){                                      //increase district one by one linear and then increase town for each district one by one
 while(currentTown!=NULL){                                         //increase town one by one linear in each current district to find town
        if(strcmp(currentTown->Data,town)==0) return currentTown;  // if town find return its node
    currentTown= currentTown->nextTown;                            //increase town one by one linear
 }
currentDistrict= currentDistrict->nextDistrict;                     //increase district one by one linear
if(currentDistrict!=NULL)currentTown= currentDistrict->nextTown;    //to select first town in each district
}
return NULL;                                                       //if town not found return NULL
}

//..................................................................................................................
//TO find district from its town
struct node1* findDistrictFromTown(struct node2* Town, struct node1* Head){ //Town is the town that belong to district and Head point to first district(linkedlist)
struct node2* firstTown = Town;
struct node1* theDistrict=Head->nextDistrict; //first district
while(firstTown->prevTown!=NULL){// to select first town in linked list for town that you want search to its district
    firstTown = firstTown->prevTown;
 }
 while(theDistrict!=NULL){ //to select district that point to first town that you selected it before
    if(theDistrict->nextTown==firstTown) return theDistrict;
    theDistrict= theDistrict->nextDistrict;
 }
 return NULL;        //don't need it because each town belong to district
}


//..................................................................................................................
int isThereAreAnytown(struct node1* Head){       //to check if there are any town
struct node1* currentDistrict =Head->nextDistrict;
while(currentDistrict!=NULL){
 if (currentDistrict->nextTown !=NULL) return 1;      //if there are any town return 1
 currentDistrict= currentDistrict->nextDistrict;
}
return 0;                                             //if there are not any town return 0

}


//.............................................................................................................
//to delete town from district linkedlist option 8
void deleteTown(struct node1* Head){        //Head to point first district (linkedlist)
char town[SIZE];
struct node1* district;
if(Head->nextDistrict!=NULL){                            //to check if there are any districts
if(isThereAreAnytown(Head)==1){                             //to check if there are any town
 getchar();                                                  // wait until user enter character if I don't put it then don't scan in first operation and delete new line is scanning it
printf("please enter the town that you want delete:- ");
readStringWithSpace(town);
deleteFirstAndLastSpaces(town);     // delete space from first and end if it found
struct node2* Town =findTownFromAllDistrict(town,Head);  //to find node for town from all districts
while( Town ==NULL){                                     //to check if town that you entered found or not
 printf("The town is not found, please enter another town:- ");
    readStringWithSpace(town);
    deleteFirstAndLastSpaces(town);     // delete space from first and end if it found
Town =findTownFromAllDistrict(town,Head);

}
 district= findDistrictFromTown(Town ,Head);   //after we check town is found we select the district that town belong it
 district->allPopulation -= Town->population;   //we decrease the value of all population by value of town population(the town is:the town you want delete)

 if(Town->prevTown==NULL){                    //delete first town from district
    district->nextTown =Town->nextTown;
    if(Town->nextTown!=NULL) Town->nextTown->prevTown=NULL;  //to select if there are town after first town
    free(Town);                                              //to delete node from memory
 }
else {                                                  //delete town but not first town
    if(isLastTown(Town)==0) Town->nextTown->prevTown = Town->prevTown; //if town not last
    Town->prevTown->nextTown = Town->nextTown;  //if town last
    free(Town);
 }
printf("we delete the town %s from %s district",town,district->Data);
}
else printf("There are not any towns if you want insert one choose 7");
}
else printf("there are not any districts if you want insert choose 6");
 printf("\n\n");
}


//....................................................................................................
// to delete district and all towns belong it option 9
void deleteDistrictAndAllTowns(struct node1* Head){   //Head to point first district (linkedlist)
char district[SIZE];
if(Head->nextDistrict!=NULL){
 getchar();                                                  // wait until user enter character if I don't put it then don't scan in first operation and delete new line is scanning it
printf("please enter district that you want delete:- ");
readStringWithSpace(district);
deleteFirstAndLastSpaces(district);     // delete space from first and end if it found
struct node1* District = findDistrict(district, Head);
while(District==NULL){      // to check if district found
    printf("please enter another district this district %s not found:- ", district);
   readStringWithSpace(district);
    deleteFirstAndLastSpaces(district);     // delete space from first and end if it found
    District = findDistrict(district,Head);
}
struct node2* Town = District->nextTown;   //Town is first town in district linkedlist
struct node2* current;
while(Town!=NULL){       //to pass in all towns in district increase one by one and delete all town in  district
   current =Town;
   free(Town);
   Town = current;
   Town = Town->nextTown;
}
District->nextTown = NULL;
//To delete district to next pointer
District->prevDistrict->nextDistrict=District->nextDistrict;
if(District->nextDistrict!=NULL)     //if district is not in last and it is to prev pointer
District->nextDistrict->prevDistrict= District->prevDistrict;
printf("we Delete the %s district", district);
 free(District);
}
else printf("there are not any districts if you want insert choose 6");
 printf("\n\n");
}


//..........................................................................................
//to print district and their all population option 5
void PrintDistrictsAndTheirTotalPopulation(struct node1* Head){  //Head to point first (linkedlist)
struct node1* currentDistrict= Head->nextDistrict;          //currentDistrict is first district
int i= 1;
while(currentDistrict!=NULL){                 // to pass on all districts
printf("The District#%d is %s with population %d\n",i,currentDistrict->Data,currentDistrict->allPopulation);
i++;
currentDistrict = currentDistrict->nextDistrict;
}
printf("\n\n");
}


//..........................................................................................
// to change population for each districts
void changePopulation(struct node1* Head){    //Head to point first district (linkedlist)
char district[SIZE];
char town[SIZE];
if(Head->nextDistrict!=NULL){                   //to check if there are any districts
  if(isThereAreAnytown(Head)){                  //to check if there are any towns
 getchar();                                                  // wait until user enter character if I don't put it then don't scan in first operation and delete new line is scanning it
  printf("Please enter the district that town located:- ");
   readStringWithSpace(district);
    deleteFirstAndLastSpaces(district);     // delete space from first and end if it found
  findDistrict(district,Head);
  while(findDistrict(district,Head)== NULL){                                            //to check if district found before or not
  printf("Please enter another district that town located:- ");
 readStringWithSpace(district);
 deleteFirstAndLastSpaces(district);     // delete space from first and end if it found

  }
if(findDistrict(district,Head)->nextTown!=NULL){
do{                                             //to check if town found before or not
 printf("please enter the town that you want change population:- ");
 readStringWithSpace(town);
 deleteFirstAndLastSpaces(town);     // delete space from first and end if it found

}while(findTown(town,findDistrict(district,Head))== NULL);

struct node2* Town = findTown(town,findDistrict(district,Head));   //to reverse town node that you want change
findDistrict(district,Head)->allPopulation -= Town->population;    //to change population of district that contain town
printf("please enter the new population for %s town:- ", Town->Data);
scanf("%d", &Town->population);                                     //enter the new population
findDistrict(district,Head)->allPopulation += Town->population;     //add new population for district that contain town
}
else printf("There are not any town in this district if you want again choose 12");
}
else printf("There are not any towns if you want insert choose 7");
}
else printf("There are not any districts if you want insert choose 6");

printf("\n\n");
}



//..........................................................................................
// to get max length for all districts
int getMaxLength(struct node1* Head){ //Head to point first district linkedlist
struct node1* currentDistrect= Head->nextDistrict;
int max=strlen(currentDistrect->Data);
while(currentDistrect!=NULL){
 if(max<strlen(currentDistrect->Data))
 max =strlen(currentDistrect->Data);
 currentDistrect= currentDistrect->nextDistrict;
 }
return max;
}


//........................................................................................................................
//to store data that finding on array of linked list (that store district node in each sort)
void reverseData(struct node1* Head, struct node1* a[]) {
struct node1* district;  // to point on first district in each a[i]
struct node1* currentDistrict= Head->nextDistrict;  // to point on first district in  linked list that you want sort it

 for(int i=0;i<26;i++){                     //moving data from array of linked list (that store district node in each sort) to linked list that you want sort it then ترتيب  النود للمدن يختلف
        district= a[i]->nextDistrict;       //to point in first district in each a[i]
    while(district!=NULL){                  //to passes in all districts in each a[i]
        strcpy(currentDistrict->Data,district->Data);      // to move data from each linked list a[i] to linked list that you want sort it(Head)
        currentDistrict->allPopulation= district->allPopulation;
        currentDistrict->nextTown= district->nextTown;     //للحفاظ على تاشير المدن كما هو
        district=district->nextDistrict;
        currentDistrict=currentDistrict->nextDistrict;
    }
 }
//to delete all nodes for all a[i] that each a[i] points for them(delete all node districts in all a[i] from memory)
 struct node1* temp;
 for(int i=0;i<26;i++){
 district= a[i]->nextDistrict;
 a[i]->nextDistrict=NULL;
    while(district!=NULL){
     temp= district;
     temp=temp->nextDistrict;
     free(district);
      district= temp;
    }

}

}


//..................................................................................................
//Radix sort to sort districts option 3
void sortDistrict(struct node1* Head){  //Head to point first district linked list
if(Head->nextDistrict!=NULL){           //to check if there are districts
struct node1* a[26];                    //array of linked list to sort district nodes (sorting it by districts name)
for(int i= 0;i<26;i++){                 //the size is 26 because there are 26 latter if capital -97 if small -60 to be index in array and store district nodes in a[i](Head for district nodes)
    a[i]= (struct node1*)malloc(sizeof(struct node1));
    a[i]->nextDistrict=NULL;
}
 char x=' ';                            //to store each latter in each district
 int j=1;                               //help to select any latter from each district
 int lengthX=0;                         //to select index for each district
 char districtt[SIZE]=" ";
 int length=0;                          //to select length of each district
 int maxLength= getMaxLength(Head);     //store the max length of all districts
 int changeMaxLength= maxLength;        // store the max length but decrease one in each sort

 for(int i=0;i<maxLength;i++){           //to passes in all a[i] to point to the district in each sort
    struct node1* currentDistrict= Head->nextDistrict;
   while(currentDistrict!=NULL){         //to passes in all district in linked list
        strcpy(districtt,currentDistrict->Data);
        length= strlen(districtt);                //length of each district
      if(maxLength-j>=0 && length>=changeMaxLength){    //if length of each district more than or equal (طول المدينة يلي بتغير عشان كل مرة بفحص حرف)
            x= districtt[maxLength-j];                  //x equal latter with position max length - j(increase one in each sort)
      }
      else {
      if(maxLength-j>=0 && length<=changeMaxLength) lengthX=0;  //if length of district smaller than maxlength index is 0 Jenin Hebron(طولها 5 بالتالي اول ترتيب بعتبر موقع جنين صفر Hebronاذا كان اطول كلمة )
      if(x==' ') lengthX=0;                                       //if character is NULL then position 0 by ascci table
      }

      if((int)x>=65 && (int)x<=90){ // if latter is small then position is -65
        lengthX= (int)x-65;
      }
      else if((int)x>=97 && (int)x<=122){ //if latter is capital then position is -97
        lengthX= (int)x-97;
      }
        insertDistrict(districtt,a[lengthX]);    //to insert district in a[i]
        findLastDistrict(a[lengthX])->nextTown=currentDistrict->nextTown;
        findLastDistrict(a[lengthX])->allPopulation = currentDistrict->allPopulation;

    currentDistrict= currentDistrict->nextDistrict;
   }
    changeMaxLength--;
    j++;
    reverseData(Head,a);       //to store data that finding on array of linked list (that store district node in each sort)
 }

for(int i= 0;i<26;i++){   //to delete all a[i] from memory all of array of linked list
  free(a[i]);
}
}
else printf("There are not any districts if you wants insert one choose 6");
 printf("\n\n");
}


//.................................................................................................
//sort town by bubble sort for each district
void sortTowns(struct node1* District){
if(District->nextTown!=NULL){
struct node2* temp;
temp =(struct node2*)malloc(sizeof(struct node2));
struct node2* town;
struct node2* Town= District->nextTown;
 while(Town!=NULL){
town= Town->nextTown;
 while(town!=NULL){
   if(Town->population > town->population){ //to replace data
   strcpy(temp->Data,town->Data);
   strcpy(town->Data,Town->Data);
   strcpy(Town->Data,temp->Data);
   temp->population=town->population;
   town->population=Town->population;
   Town->population=temp->population;

    }
   town= town->nextTown;
  }
   Town=Town->nextTown;
 }
 free(temp);
}
}


//...........................................................................................................
//to sorting all town for all districts option 4
void sortAllTowns(struct node1* Head){
 if(Head->nextDistrict!=NULL){
struct node1* District = Head->nextDistrict;
while(District != NULL){
 sortTowns(District);
 District= District->nextDistrict;
 }
 }
 else printf("there are not any districts");
 printf("\n\n");
}


//................................................................................................................
//to print list with all towns with all population
 void printinglistwithallpopulation(struct node1* L){
     if(L->nextDistrict!= NULL){
            if(count==0)sortDistrict(L);
            if(count2==0)sortAllTowns(L);
  struct node1* currentDistrict = L->nextDistrict;
        while (currentDistrict != NULL) {
        printf("%s District, Population = %d", currentDistrict->Data, currentDistrict->allPopulation);
        struct node2* currentTown = currentDistrict->nextTown;
        while (currentTown != NULL) {
            printf("\n%s, %d", currentTown->Data, currentTown->population);
            currentTown = currentTown->nextTown;
        }
        printf("\n");
        currentDistrict = currentDistrict->nextDistrict;
    }
     }
     else printf("There are not any district");
}


//................................................................................................................
//to calculate all population for all towns and max population of town and min population of town
void calculatePopulation(struct node1* Head){
if(Head->nextDistrict!=NULL){
sortAllTowns(Head);  //we sort towns until the all max become in last town in each district and the min become in first town in each district
int allPopulationForAllTowns= 0;
struct node1* currentDistrict= Head->nextDistrict;
int min = currentDistrict->nextTown->population;
int max =findLastTown(currentDistrict)->population;
char maxTownPopulation[SIZE];
char minTownPopulation[SIZE];
char maxDistrictOfTown[SIZE];
char minDistrictOfTown[SIZE];
struct node2* lastTown;
while(currentDistrict!=NULL){
 lastTown= findLastTown(currentDistrict);     //to find last town in each district
 allPopulationForAllTowns += currentDistrict->allPopulation;

 if(min > (currentDistrict->nextTown->population)){
    min = currentDistrict->nextTown->population;
    strcpy(minDistrictOfTown,currentDistrict->Data);
    strcpy(minTownPopulation,currentDistrict->nextTown->Data);
  }
 if(max < lastTown->population){
     max = lastTown->population;
     strcpy(maxTownPopulation,lastTown->Data);
     strcpy(maxDistrictOfTown,currentDistrict->Data);
 }
currentDistrict= currentDistrict->nextDistrict;
}
printf("The all population of all towns is %d\nthe max population is %d in %s town in %s district\nthe min population is %d in %s town in %s district ",allPopulationForAllTowns,max,maxTownPopulation,maxDistrictOfTown,min,minTownPopulation,minDistrictOfTown );
}
else printf("There are not any districts");
printf("\n\n");

}

//.........................................................................................................
// to save out put in out put file
void printOutput (struct node1* L) {
    // check if the doubly linked list passed
    if (L->nextDistrict== NULL) {
        printf("!Linked List does not exist!\n");
        return;
    }
    sortDistrict(L);
    sortAllTowns(L);
    FILE *output = fopen("sorted_districts.txt", "w");
    // iterate over the given doubly linked list and print the data inside every node to the given output file
    struct node1* currentDistrict = L->nextDistrict;
        while (currentDistrict != NULL) {
        fprintf(output,"%s District, Population = %d", currentDistrict->Data, currentDistrict->allPopulation);
        struct node2* currentTown = currentDistrict->nextTown;
        while (currentTown != NULL) {
            fprintf(output,"\n%s, %d", currentTown->Data, currentTown->population);
            currentTown = currentTown->nextTown;
        }
        fprintf(output,"\n");
        currentDistrict = currentDistrict->nextDistrict;
    }
    fclose(output);
    printf("saving output in file");
    printf("\n\n");
}


//.............................................................................................................
void selectOpition(struct node1* Head){
int selection=0;
do{
printf("please enter number between 1-14: ");
printf("\n\n1. Load the input file (Palestinian districts and their town with population.");
printf("\n2. Print the loaded information before sorting (as in the input file format).");
printf("\n3. Sort the districts alphabetically using Radix sort.");
printf("\n4. Sort the towns for each district based on population in ascending order.");
printf("\n5. Print the sorted information.");
printf("\n6. Add a new district to the list of sorted districts (and sort the list).");
printf("\n7. Add a new town to a certain district.");
printf("\n8. Delete a town from a specific district.");
printf("\n9. Delete a complete district; here, you must delete all towns belonging to that district before deleting it.");
printf("\n10.Calculate the population of Palestine, the max and min town population.");
printf("\n11.Print the districts and their total population (without towns details).");
printf("\n12.Change the population of a town, after prompting the user to enter the district name.");
printf("\n13.Save to output file.");
printf("\n14.Exit\n\n");
printf("The selection is:- ");
scanf("%d", &selection);
printf("\n");
if(selection == 1) loadTheInputFile(Head);
else if(selection == 2) printList(Head);
else if(selection==3){count++;  sortDistrict(Head);}
else if(selection == 4){count2++; sortAllTowns(Head);}
else if(selection == 5) printinglistwithallpopulation(Head);
else if(selection == 6) insertNewDistrict(Head);
else if(selection == 7){ count2=0; insertNewTown(Head);}
else if(selection == 8) deleteTown(Head);
else if(selection == 9) deleteDistrictAndAllTowns(Head);
else if(selection == 10) calculatePopulation(Head);
else if(selection == 11) PrintDistrictsAndTheirTotalPopulation(Head);
else if(selection == 12) changePopulation(Head);
else if (selection== 13)printOutput(Head);
else if (selection== 14){
    printf("\t!Thank you!");
deleteAllLinkedList(Head);
}
 }while(selection != 14);
}


//to delete all nodes from memory after close program
void deleteAllLinkedList(struct node1* Head){
    struct node1* current1;
    struct node2* current2;
if(Head->nextDistrict!= NULL){
  struct node1* currentDistrict = Head->nextDistrict;
        while (currentDistrict != NULL) {
        struct node2* currentTown = currentDistrict->nextTown;
        while (currentTown != NULL) {
                current2=currentTown->nextTown;
                 free(currentTown);
                 currentTown=current2;
        }
        current1=currentDistrict->nextDistrict;
        free(currentDistrict);
        currentDistrict=current1;
    }
     }
}












