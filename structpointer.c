#include<time.h>
#include<stdio.h>
#include<stdlib.h>

struct file {
	
    char firstName[50];
    char lastName[50];
    char studentGrade[5]; // 1 LETTER GRADE PER STUDENT
    int  testGrades[4];   // 5 TESTS GIVEN
    time_t timeStamp;
	
};

time_t getTime();
void printTime(time_t dateEntered);
void enterNewStudent(struct file *fPtr, int count);
void printStudents(struct file *fPtr,int count);    //ENTER/PRINT RECIEVES A STRUCT *POINTER PARAMETER
 
int main (void)
{
        int menuChoice;
        int studentArrayCount = 0; // KEEP TRACK OF CORRECT CELL IN ARRAY FOR STUDENTS ADDED(Start at 0)
        
	struct file students[19];  // ARRAY OF STRUCTS FOR UP TO 20 STUDENTS
	struct file *fPtr = malloc(19 * sizeof(struct file) ); // CREATE POINTER TO PASS TO FUNCTIONS
        
	fPtr = students; // POINTS TO STRUCT ARRAY OF STUDENTS
        
        printf("0 End Program\n1 Enter New Student\n2 Print Students ");
        scanf("%d", &menuChoice);
        
        while(menuChoice != 0){
            
            if(menuChoice == 1){
                              
                enterNewStudent( fPtr, studentArrayCount );
                studentArrayCount++; //STUDENT ADDED - INCREMENT COUNT FOR NEXT CELL IN STUDENT ARRAY
            }               
            else if(menuChoice == 2){
                
                printStudents(fPtr, studentArrayCount);
            }
  
            printf("\n0 End Program\n1 Enter New Student\n2 Print Students:");
            scanf(" %d", &menuChoice);
        }
		
}// END OF MAIN

void printStudents(struct file *fPtr,int count )
{
    int i;
    for(i = 0 ; i < count ; i++){
        	
        printf("\nSTUDENT NAME: %s %s\n", fPtr->firstName, fPtr->lastName);
        
        printf("Test Grades:\n");
        int i; // FOR LOOP
        int testCount = 1; // COUNTER FOR TEST #
        for(i = 0 ; i < 5 ; i++){
            
            printf("TEST #%d[%d Points]\n",testCount ,fPtr->testGrades[i]);
            testCount++;
        }
	    printf("Final Grade is [%s]\n", fPtr->studentGrade);

        printTime(fPtr->timeStamp);
        fPtr++; //INCREMENT TO NEXT STUDENT IN ARRAY
    }

    return;

}

void enterNewStudent(struct file *fPtr, int count ){
    
                fPtr += count;
    
                printf("Enter the Student First Name:");
                scanf("%s", fPtr->firstName);

                printf("Enter the Student Last Name:");
                scanf("%s", fPtr->lastName);

                printf("Enter Student Letter Grade For Semester:");
                scanf("%s", fPtr->studentGrade); 
                
                printf("Enter the Score For The 5 Tests Given: ");              
                int i;
                for(i = 0 ; i < 5 ; i++){

                        printf("Enter Score For Test[%d]:",++i);
                        i--;
                        scanf("%d", &fPtr->testGrades[i]);
                }      
                
                fPtr->timeStamp = getTime();
                
                return;
}

time_t getTime(){
    
    time_t timeEntered; // DATA TYPE TO STORE SYSTEM TIMES
    timeEntered = time(NULL); // GET THE CURRENT TIME
    
    return timeEntered;
}

void printTime(time_t dateEntered ){
    
    struct tm *timeStruct; // tm STRUCTURE INCLUDED IN THE <time.h> HEADER
    char buf[80];  // TO PRINT OUT 

    timeStruct = localtime(&dateEntered); //FORMAT
    strftime(buf, sizeof(buf), "%a %m-%d-%y %H:%M", timeStruct);
    puts(buf);

    return;
}