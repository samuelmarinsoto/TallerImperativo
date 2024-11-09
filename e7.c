#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define MAX_EXCLUDED_WORDS 10

// Lista de palabras a excluir (como "el", "la", "los", etc.)
const char *excluded_words[MAX_EXCLUDED_WORDS] = {
    "el", "la", "los", "las", "y", "de", "que", "en", "a", "un"
};

// Estructura para almacenar una palabra y las líneas en las que aparece
typedef struct {
    char word[MAX_WORD_LENGTH];
    int lines[MAX_WORDS];  // Almacenará los números de línea
    int line_count;        // Cuántas veces la palabra aparece en distintas líneas
} WordInfo;

// Función para verificar si una palabra debe ser excluida
int is_excluded(const char *word) {
    for (int i = 0; i < MAX_EXCLUDED_WORDS; i++) {
        if (strcmp(word, excluded_words[i]) == 0) {
            return 1;  // La palabra está en la lista de exclusión
        }
    }
    return 0;  // La palabra no está en la lista de exclusión
}

// Función para comparar palabras en minúsculas (case-insensitive)
int compare_words(const char *a, const char *b) {
    return strcasecmp(a, b);  // Compara sin distinguir mayúsculas/minúsculas
}

int main() {
    FILE *file = fopen("documento.txt", "r");  // Abrir el archivo para lectura
    if (!file) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    int c, line = 1, i = 0, j = 0;
    char current_word[MAX_WORD_LENGTH];
    WordInfo words[MAX_WORDS];  // Array para almacenar palabras encontradas

    while ((c = fgetc(file)) != EOF) {  // Leer el archivo con fgetc()
        static int word_len = 0;

        if (!isspace(c) && c != '.' && c != ',' && c != ';' && c != '!' && c != '?') {
            // Si el carácter no es un delimitador, lo añadimos al buffer de la palabra
            current_word[word_len++] = tolower(c);
        } else if (word_len > 0) {
            current_word[word_len] = '\0';  // Terminamos la palabra con un '\0'

            if (!is_excluded(current_word)) {
                // Comprobamos si la palabra ya está registrada
                int found = 0;
                for (i = 0; i < j; i++) {
                    if (compare_words(words[i].word, current_word) == 0) {
                        // Si la palabra ya existe, agregamos la línea
                        words[i].lines[words[i].line_count++] = line;
                        found = 1;
                        break;
                    }
                }

                // Si la palabra no fue encontrada, la añadimos
                if (!found) {
                    strcpy(words[j].word, current_word);
                    words[j].lines[0] = line;
                    words[j].line_count = 1;
                    j++;
                }
            }

            word_len = 0;  // Resetear el tamaño de la palabra
        }

        if (c == '\n') {
            line++;  // Incrementar el contador de líneas cuando encontramos un salto de línea
        }
    }

    fclose(file);  // Cerramos el archivo

    // Imprimir las palabras y las líneas en las que aparecen
    for (i = 0; i < j; i++) {
        printf("%s: ", words[i].word);
        for (int k = 0; k < words[i].line_count; k++) {
            printf("%d", words[i].lines[k]);
            if (k < words[i].line_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    return 0;
}
