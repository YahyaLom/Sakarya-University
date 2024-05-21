#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fields.h"
#include "dllist.h"

int main(int argc, char **argv){
    IS input;
    IS sozluk;
    Dllist dll;
    Dllist tmp;
    FILE *fp;
    char ch;
    char *newInput;
    char *specialChars="~!#$^&*()-+,./|`_=<>?{}[]:;'";
    int i, j, exist=0, specialCh=0, toplamKelime=0, basariliKelime=0, basarisizKelime=0;

    if(argc != 4 || (strcmp(argv[1], "tr") && strcmp(argv[1], "eng")) || strcmp(argv[2], "txt/input.txt") || strcmp(argv[3], "txt/sozluk.txt")){
        fprintf(stderr, "Parametre hatasi!\n");
        exit(1);
    }

    input = new_inputstruct(argv[2]);
    sozluk = new_inputstruct(argv[3]);
    if (input == NULL || sozluk == NULL) {
        perror(argv[1]);
        exit(1);
    }
    dll = new_dllist();
    fp = fopen("txt/output.txt", "w");

    while(get_line(input) >= 0) {
        for (i = 0; i < input->NF; i++) {
            ch=input->fields[i][strlen(input->fields[i])-1];
            if(strchr(specialChars, ch)){
                newInput=input->fields[i];
                newInput[strlen(newInput)-1]='\0';
                specialCh=1;
            }
            else    newInput=input->fields[i];
            for(j = 0; j < strlen(newInput); j++)   newInput[j] = tolower(newInput[j]);
            while(get_line(sozluk) >= 0){
                if(!strcmp(argv[1], "tr")){
                    if(!strcmp(newInput, sozluk->fields[1])){
                        dll_append(dll, new_jval_s(strdup(sozluk->fields[2])));
                        basariliKelime+=1;
                        exist=1;
                        break;
                    }
                }
                else{
                    if(!strcmp(newInput, sozluk->fields[2])){
                        dll_append(dll, new_jval_s(strdup(sozluk->fields[1])));
                        basariliKelime+=1;
                        exist=1;
                        break;
                    }
                }
            }
            rewind(sozluk->f);
            if(exist==0){
                dll_append(dll, new_jval_s(strdup(input->fields[i])));
                basarisizKelime+=1;
            }
            if(specialCh==1)     dll->blink->val.s[strlen(dll->blink->val.s)]=ch;
            if(i!=input->NF-1)    dll->blink->val.s[strlen(dll->blink->val.s)]=' ';
            else    dll->blink->val.s[strlen(dll->blink->val.s)]='\n';
            exist=0;
            specialCh=0;
            toplamKelime+=1;
        }
    }
    dll->blink->val.s[strlen(dll->blink->val.s)-1]='\0';

    dll_traverse(tmp, dll){
        fputs(tmp->val.s, fp);
        free(tmp->val.s);
    }

    fclose(fp);
    free_dllist(dll);
    jettison_inputstruct(input);
    jettison_inputstruct(sozluk);

    printf("Özet Bilgi\n");
    printf("Karşılaştırılan Kelime Sayısı: %d\n", toplamKelime);
    printf("Çevirisi Başarılı Kelime Sayısı: %d\n", basariliKelime);
    printf("Çevirisi Yapılamamış Kelime Sayısı: %d\n", basarisizKelime);

    return 0;
}