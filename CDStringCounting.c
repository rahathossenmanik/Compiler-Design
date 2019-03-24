#include<stdio.h>
#define MAX 60
int main(){
    char str[MAX];
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    fgets(str, MAX, input_file);
    fprintf(output_file, "String: %s\n",str);
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int word = 0;
    int letter = 0;
    int digit = 0;
    int otherchar = 0;
    char letters[30] = "";
    char digits[20] = "";
    char otherchars[10] = "";
    int check[200];
    for(i=0; str[i]!='\0'; i++){
        if(str[i]==' ')word++;
        if((str[i]>=65 && str[i]<=90)||(str[i]>=97 && str[i]<=122)){
            letter++;
            letters[j] = str[i];
            j++;
        }
        else if((str[i]>=48 && str[i]<=57)){
            digit++;
            digits[k] = str[i];
            k++;
        }
        else{
            otherchar++;
            otherchars[l] = str[i];
            l++;
        }
    }
    word++;
    fprintf(output_file, "The Number of Words is: %d\n", word);
    fprintf(output_file, "The Number of Letters is: %d\n", letter);
    fprintf(output_file, "The Number of Digits is: %d\n", digit);
    fprintf(output_file, "The Number of Other Characters is: %d\n", otherchar);
    fprintf(output_file, "Letters: ");
    for(i=0; i<200; i++){
        check[i]=0;
    }
    for(i=0;i<j; i++){
        if(check[letters[i]]==0){
            fprintf(output_file, "%c ", letters[i]);
            check[letters[i]]=1;
        }
    }
    fprintf(output_file, "\nDigits: ");
    for(i=0; i<k; i++){
        fprintf(output_file, "%c ", digits[i]);
    }
    fprintf(output_file, "\nOther Characters: ");
    for(i=0; i<l; i++){
        fprintf(output_file, "%c ", otherchars[i]);
    }
    fprintf(output_file, "\n");
    fclose(input_file);
    fclose(output_file);
    return 0;
}
