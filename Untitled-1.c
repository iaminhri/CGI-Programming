#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {

    char array[200];
    int l = 0;
    int n = atoi(getenv("CONTENT_LENGTH"));
    char k;

    fgets(array, n+1, stdin);

    char parse[200];

    int count = 0;

    bool reachedEqualSign = false;

    for(int i = 0; i <= 200; i++){
        if(array[i] == '='){
            reachedEqualSign = true;
            continue;
        }
        else if(array[i] == '&'){
            reachedEqualSign = false;
            parse[count] = ' ';
            count++;
        }
        if(reachedEqualSign == true){
            parse[count] = array[i];
            count++;
        }
    }

    char *arr[2] = {0};
    int c = 0;
	int init_size = strlen(parse);
	char delim[] = " ";

	char *ptr = strtok(parse, delim);

	while(ptr != NULL)
	{
        arr[c] = ptr;
		ptr = strtok(NULL, delim);
        c++;
	}

    if(arr[0] == NULL || arr[1] == NULL){
        printf("Content-Type:text/html\n\n");
        printf("<html>");
        printf("<head><title>ERROR</title></head>");
        printf("<body><h1>No Input !!!</h1></body>");
        printf("</html>");
        exit(1);
    }

    int doesUsrExists;
    int doesPwdExists;
    int bothExists;

    FILE *fptr;
    char row[200];
    char usr[200][200];
    char pwd[200][200];

    fptr = fopen("../A4/lcA2Wg/users.csv", "r");

    if ( fptr == NULL ){
        printf("Content-Type:text/html\n\n");
        printf("<html>");
        printf("<head><title>ERROR</title></head>");
        printf("<body><h1>Unable to open file!</h1></body>");
        printf("</html>");
        exit(1);
    }

    int lineCounter = 0;

    while( fgets(row, 200, fptr) ){
        char *token;
        token = strtok(row, ",");
        strcpy(usr[lineCounter], token);
        token = strtok(NULL, ",");
        while(token != NULL){
            strcpy(pwd[lineCounter], token);
            token = strtok(NULL, ",");
        }
        lineCounter++;
    }
    fclose(fptr);
    for(int k = 0; k < lineCounter; k++){
        char *trimmed = strtok(pwd[k], "\n ");
        doesUsrExists = strcmp(arr[0], usr[k]);
        doesPwdExists = strcmp(arr[1], trimmed);
        if(doesPwdExists == 0 && doesUsrExists == 0){
            bothExists = 0;
            break;
        }
        else
            bothExists = 1;
    }

    printf("Content-Type:text/html\n\n");
    printf("<html><body>");

    if(bothExists == 0){
        printf("<h1>Your Password Matches</h1>");
    }
    else{
        printf("<h1>Wrong username or password</h1>");
    }
    printf("</body></html>");

    return 0;
}
