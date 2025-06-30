#include <stdio.h>


char* longestCommonPrefix(char** strs, int strsSize) {
    char *str ='\0';
    char *sym = strs[0];
    int k = 0;
    for(int i = 0; i < strsSize; i++) { //листаеми слова
         if(sym != strs[i]) 
            return str;
         if(sym == strs[i] && i == strsSize - 1) {
            strs[k] = sym;
            k++;
            sym = strs[k];
            i = 0;
         }
        }
        return str;
    }



int main() {
char* strs[] = {"flower", "flow", "flight"};
printf("Longest common prefix: %s\n", longestCommonPrefix(strs, 3));

   

}