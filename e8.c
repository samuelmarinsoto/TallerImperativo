#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Estructura para almacenar una palabra y su frecuencia
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordInfo;

// Función para comparar dos elementos por su frecuencia en orden descendente
int compare(const void *a, const void *b) {
    WordInfo *wordA = (WordInfo *)a;
    WordInfo *wordB = (WordInfo *)b;
    return wordB->count - wordA->count;  // Orden descendente
}

// Función para verificar si una palabra ya está en la lista
int word_exists(WordInfo words[], int word_count, const char *word) {
    for (int i = 0; i < word_count; i++) {
        if (strcasecmp(words[i].word, word) == 0) {
            return i;  // La palabra ya existe en la lista
        }
    }
    return -1;  // La palabra no se encuentra en la lista
}

int main() {
    FILE *file = fopen("documento.txt", "r");  // Abrir el archivo para lectura
    if (!file) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    int c, word_len = 0, word_count = 0;
    char current_word[MAX_WORD_LENGTH];
    WordInfo words[MAX_WORDS];

    // Leer archivo carácter por carácter
    while ((c = fgetc(file)) != EOF) {
        if (!isspace(c) && c != '.' && c != ',' && c != ';' && c != '!' && c != '?') {
            // Si el carácter no es un delimitador, lo añadimos a la palabra
            current_word[word_len++] = tolower(c);
        } else if (word_len > 0) {
            // Si hemos formado una palabra, la guardamos
            current_word[word_len] = '\0';  // Terminar la palabra con un '\0'

            int index = word_exists(words, word_count, current_word);
            if (index == -1) {
                // Si la palabra no existe en la lista, la agregamos
                strcpy(words[word_count].word, current_word);
                words[word_count].count = 1;
                word_count++;
            } else {
                // Si la palabra ya existe, incrementamos su contador
                words[index].count++;
            }

            word_len = 0;  // Resetear el tamaño de la palabra
        }
    }

    fclose(file);  // Cerramos el archivo

    // Ordenar las palabras por su frecuencia de aparición
    qsort(words, word_count, sizeof(WordInfo), compare);

    // Imprimir las palabras y sus frecuencias en orden descendente
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
