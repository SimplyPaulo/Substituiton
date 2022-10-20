#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //verifica se foi preenchido a chave
    if (argc != 2)
    {
        printf("Usage: ./substituiton key\n");
        return 1;
    }

    int keyLenght = strlen(argv[1]);
    const char keyBase[] = "abcdefghijklmnopqrstuvwxyz";
    string keyCheck = argv[1];

    //verifica se tem 26 caracteres
    if (keyLenght != 26)
    {
        printf("Utilize uma chave válida.\n");
        return 1;
    }
    //verifica se nao é numerica
    for (int i= 0; i < keyLenght; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Apenas letras.\n");
            return 1;
        }

        keyCheck[i] = tolower(keyCheck[i]);

        for (int j = i + 1; keyCheck[j] != '\0'; j++)
        {
            if (tolower(keyCheck[j]) == keyCheck[i])
            {
                printf("Proibido letras repetidas.\n");
                return 1;
            }

        }
    }
    //coleta a frase pra criptografar
    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext;

    //função q criptografa
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        const char ch = plaintext[i];

        if (islower(plaintext[i]))
        {
            // busca a posição da letra na chave base e usa para determinar a letra cifrada
            char *letterPosition = memchr(keyBase, ch, 26);
            ciphertext[i] = keyCheck[letterPosition - keyBase];
        }

        else if (isupper(plaintext[i]))
        {
            char *letterPosition = memchr(keyBase, tolower(ch), 26);
            ciphertext[i] = toupper(keyCheck[letterPosition - keyBase]);
        }

        else
        {
            //adiciona outros caracteres que não são letras na cifra
            ciphertext[i] = plaintext[i];
        }
    }

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}