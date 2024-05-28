#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PARAGRAPH 10
#define MAX_CHARACTERS 9040
#define MAX_WORD_LEN 20
#define MAX_WORDS 100

char raw_text[MAX_PARAGRAPH][MAX_CHARACTERS];
char raw_positive_words[MAX_CHARACTERS];
char raw_negative_words[MAX_CHARACTERS];
char processed_positive_words[MAX_WORDS][MAX_WORD_LEN + 1];
char processed_negative_words[MAX_WORDS][MAX_WORD_LEN + 1];
int num_paragraph, index_posi, index_nega;

void reads();
void paragraph_reads();
void process_words();
void validate_paragraph(int paragraph_index);
void validate_text();
void validate_longest_sentence();
void validate_shortest_sentence();
void calculate_polarity(int positive_count, int negative_count);
void to_lower_case(char *str);

void reads()
{
    // Leitura do número de parágrafos
    scanf("%d\n", &num_paragraph);

    // Leitura dos parágrafos
    paragraph_reads();

    // Leitura das palavras positivas e negativas
    fgets(raw_positive_words, MAX_CHARACTERS, stdin);
    fgets(raw_negative_words, MAX_CHARACTERS, stdin);

    // Processamento das palavras positivas e negativas
    process_words();
}

void paragraph_reads()
{
    for (int i = 0; i < num_paragraph; i++)
    {
        fgets(raw_text[i], MAX_CHARACTERS, stdin);
    }
}

void process_words()
{
    int i, j, k;

    // Processamento das palavras positivas
    index_posi = 0;
    for (i = 0, j = 0, k = 0; i <= strlen(raw_positive_words); i++)
    {
        if (raw_positive_words[i] == ' ' || raw_positive_words[i] == '\0' || raw_positive_words[i] == '\n')
        {
            processed_positive_words[k][j] = '\0'; // Termina a palavra atual
            k++;                                   // Move para a próxima palavra
            j = 0;                                 // Reinicia o índice da palavra
            if (raw_positive_words[i] == '\0' || raw_positive_words[i] == '\n')
                break; // Se for o fim da string, sai do loop
        }
        else
        {
            processed_positive_words[k][j++] = tolower(raw_positive_words[i]);
        }
    }
    index_posi = k; // O total de palavras processadas

    // Processamento das palavras negativas
    index_nega = 0;
    for (i = 0, j = 0, k = 0; i <= strlen(raw_negative_words); i++)
    {
        if (raw_negative_words[i] == ' ' || raw_negative_words[i] == '\0' || raw_negative_words[i] == '\n')
        {
            processed_negative_words[k][j] = '\0'; // Termina a palavra atual
            k++;                                   // Move para a próxima palavra
            j = 0;                                 // Reinicia o índice da palavra
            if (raw_negative_words[i] == '\0' || raw_negative_words[i] == '\n')
                break; // Se for o fim da string, sai do loop
        }
        else
        {
            processed_negative_words[k][j++] = tolower(raw_negative_words[i]);
        }
    }
    index_nega = k; // O total de palavras processadas
}

void to_lower_case(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

void calculate_polarity(int positive_count, int negative_count)
{
    char *polaridade;
    if (positive_count - negative_count > 3)
    {
        polaridade = "positiva";
    }
    else if (positive_count > 0 && negative_count == 0)
    {
        polaridade = "positiva";
    }
    else if (negative_count - positive_count > 3)
    {
        polaridade = "negativa";
    }
    else if (positive_count == 0 && negative_count > 0)
    {
        polaridade = "negativa";
    }
    else if (positive_count > 0 && negative_count > 0 && abs(positive_count - negative_count) <= 3)
    {
        polaridade = "neutra";
    }
    else
    {
        polaridade = "neutra";
    }

    // Imprime o resultado
    printf("%d Palavras positivas, %d Palavras negativas: Polaridade %s\n", positive_count, negative_count, polaridade);
}

void validate_paragraph(int paragraph_index)
{
    
    char *word;
    int positive_count = 0, negative_count = 0;
    char paragraph[MAX_CHARACTERS];
    strcpy(paragraph, raw_text[paragraph_index]);

    // Converte o parágrafo para letras minúsculas
    to_lower_case(paragraph);

    // Tokeniza o parágrafo em palavras
    word = strtok(paragraph, " .,;:!?()[]\"'\n");
    while (word != NULL)
    {
        // Conta palavras positivas
        for (int j = 0; j < index_posi; j++)
        {
            if (strcmp(word, processed_positive_words[j]) == 0)
            {
                positive_count++;
                break;
            }
        }
        // Conta palavras negativas
        for (int j = 0; j < index_nega; j++)
        {
            if (strcmp(word, processed_negative_words[j]) == 0)
            {
                negative_count++;
                break;
            }
        }
        word = strtok(NULL, " .,;:!?()[]\"'\n");
    }

    // Calcula e imprime a polaridade do parágrafo
    calculate_polarity(positive_count, negative_count);
}

void validate_text()
{
    int positive_count = 0, negative_count = 0;

    for (int i = 0; i < num_paragraph; i++)
    {
        char *word;
        char paragraph[MAX_CHARACTERS];
        strcpy(paragraph, raw_text[i]);

        // Converte o parágrafo para letras minúsculas
        to_lower_case(paragraph);

        // Tokeniza o parágrafo em palavras
        word = strtok(paragraph, " .,;:!?()[]\"'\n");
        while (word != NULL)
        {
            // Conta palavras positivas
            for (int j = 0; j < index_posi; j++)
            {
                if (strcmp(word, processed_positive_words[j]) == 0)
                {
                    positive_count++;
                    break;
                }
            }
            // Conta palavras negativas
            for (int j = 0; j < index_nega; j++)
            {
                if (strcmp(word, processed_negative_words[j]) == 0)
                {
                    negative_count++;
                    break;
                }
            }
            word = strtok(NULL, " .,;:!?()[]\"'\n");
        }
    }

    // Calcula e imprime a polaridade do texto inteiro
    // printf("Texto completo:\n");
    calculate_polarity(positive_count, negative_count);
}

void validate_longest_sentence()
{
    char *ptr;
    int max_length = 0;
    char longest_sentence[MAX_CHARACTERS] = {0};
    int positive_count = 0, negative_count = 0;

    for (int i = 0; i < num_paragraph; i++)
    {
        char *sentence;
        char paragraph[MAX_CHARACTERS];
        strcpy(paragraph, raw_text[i]);

        // Tokeniza o parágrafo em sentenças
        sentence = strtok(paragraph, ".");
        while (sentence != NULL)
        {
            int length = strlen(sentence);
            if (length > max_length)
            {
                max_length = length;
                strcpy(longest_sentence, sentence);
                ptr = &longest_sentence;
            }
            sentence = strtok(NULL, ".");
        }
    }

    // Converte a sentença mais longa para letras minúsculas
    to_lower_case(ptr);

    // Tokeniza a sentença em palavras
    char *word = strtok(ptr, " .,;:!?()[]\"'\n");
    while (word != NULL)
    {
        // Conta palavras positivas
        for (int j = 0; j < index_posi; j++)
        {
            if (strcmp(word, processed_positive_words[j]) == 0)
            {
                positive_count++;
                break;
            }
        }
        // Conta palavras negativas
        for (int j = 0; j < index_nega; j++)
        {
            if (strcmp(word, processed_negative_words[j]) == 0)
            {
                negative_count++;
                break;
            }
        }
        word = strtok(NULL, " .,;:!?()[]\"'\n");
    }

    // Calcula e imprime a polaridade da sentença mais longa
    // printf("Sentença mais longa:\n");
    calculate_polarity(positive_count, negative_count);
}

void validate_shortest_sentence()
{
    int min_length = MAX_CHARACTERS;
    char shortest_sentence[MAX_CHARACTERS] = {0};
    int positive_count = 0, negative_count = 0;

    for (int i = 0; i < num_paragraph; i++)
    {
        char *sentence;
        char paragraph[MAX_CHARACTERS];
        strcpy(paragraph, raw_text[i]);

        // Tokeniza o parágrafo em sentenças
        sentence = strtok(paragraph, ".");
        while (sentence != NULL)
        {
            int length = strlen(sentence);
            if (length < min_length && length > 0)
            {
                min_length = length;
                strcpy(shortest_sentence, sentence);
            }
            sentence = strtok(NULL, ".");
        }
    }

    // Converte a sentença mais curta para letras minúsculas
    to_lower_case(shortest_sentence);
    // Tokeniza a sentença em palavras
    char *word = strtok(shortest_sentence, " .,;:!?()[]\"'\n");
    while (word != NULL)
    {
        // Conta palavras positivas
        for (int j = 0; j < index_posi; j++)
        {
            if (strcmp(word, processed_positive_words[j]) == 0)
            {
                positive_count++;
                // break;
            }
        }
        // Conta palavras negativas
        for (int j = 0; j < index_nega; j++)
        {
            if (strcmp(word, processed_negative_words[j]) == 0)
            {
                negative_count++;
                // break;
            }
        }
        word = strtok(NULL, " .,;:!?()[]\"'\n");
    }

    // Calcula e imprime a polaridade da sentença mais curta
    // printf("Sentença mais curta:\n");
    calculate_polarity(positive_count, negative_count);
}

int main()
{
    reads();

    int num_questions;
    scanf("%d", &num_questions);
    getchar(); // Consumir a nova linha após o número de questões

    for (int i = 0; i < num_questions; i++)
    {
        char question[50];
        fgets(question, sizeof(question), stdin);

        // Remove a nova linha no final da string
        size_t len = strlen(question);
        if (len > 0 && question[len - 1] == '\n')
        {
            question[len - 1] = '\0';
        }

        // Processa a questão
        if (strcmp(question, "1") == 0)
        {
            validate_text();
        }
        else if (strncmp(question, "2 ", 2) == 0)
        {
            int paragraph_index = atoi(question + 2);
            if (paragraph_index >= 0 && paragraph_index < num_paragraph)
            {
                // printf("Parágrafo %d:\n", paragraph_index);
                validate_paragraph(paragraph_index);
            }
            else
            {
                // printf("Parágrafo %d não existe.\n", paragraph_index);
            }
        }
        else if (strcmp(question, "3") == 0)
        {
            validate_longest_sentence();
        }
        else if (strcmp(question, "4") == 0)
        {
            validate_shortest_sentence();
        }
    }

    return 0;
}
