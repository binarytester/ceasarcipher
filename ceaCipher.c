#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// length of text
const int LENGTH_TXT = 100;

// clear buffer
void clearBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// encrypt message using a key
char *encrypt(char text[], int key)
{
  int textLength = strlen(text);
  char *newtxt = (char *)malloc((textLength + 1) * sizeof(char));
  for (int i = 0; i < textLength; i++)
  {
    // Check for valid characters and calculate
    if (isupper(text[i]))
    { // Uppercase letters
      newtxt[i] = (text[i] - 'A' + key) % 26 + 'A';
    }
    else if (islower(text[i]))
    { // Lowercase letters
      newtxt[i] = (text[i] - 'a' + key) % 26 + 'a';
    }
    else if (isdigit(text[i]))
    { // Digits
      newtxt[i] = (text[i] - '0' + key) % 26 + '0';
    }
    else
    {
      newtxt[i] = text[i]; // Space or other non-encryptable characters
    }
  }
  newtxt[textLength] = '\0';
  return newtxt;
}

// decrypt encrypted text using key
char *decrypt(char cipher[], int key)
{
  int textLength = strlen(cipher);
  char *plaintext = (char *)malloc(textLength * sizeof(char));
  for (int i = 0; i < textLength; i++)
  {
    // Check for valid characters and calculate
    // Subtract the key instead of adding
    if (isupper(cipher[i]))
    {
      plaintext[i] = (cipher[i] - 'A' - key + 26) % 26 + 'A';
    }
    else if (islower(cipher[i]))
    {
      plaintext[i] = (cipher[i] - 'a' - key + 26) % 26 + 'a';
    }
    else if (isdigit(cipher[i]))
    {
      plaintext[i] = (cipher[i] - '0' - key + 26) % 26 + '0';
    }
    else
    {
      plaintext[i] = cipher[i];
    }
  }
  plaintext[textLength] = '\0';
  return plaintext;
}

// function to decrypt an encrypted message
void decryptMessage()
{
  char ciphertext[LENGTH_TXT];
  int key;
  printf("Decrypting...\n");
  printf("\nEnter encrypted message: ");
  clearBuffer();
  scanf(" %[^\n]", ciphertext);
  printf("Enter key [0-26]: ");
  scanf(" %d", &key);
  char *plaintext = decrypt(ciphertext, key);
  printf("\n>> Decrypted message: %s\n", plaintext);
}

// function to encrypt a message
void encryptMessage()
{
  char plaintext[LENGTH_TXT];
  int key;
  printf("Encrypting...\n");
  printf("\nEnter a message to encrypt: ");
  clearBuffer();
  scanf(" %[^\n]", plaintext);
  fflush(stdin);
  printf("Enter the key [0-26]: ");
  scanf(" %d", &key);
  char *ciphertext = encrypt(plaintext, key);
  printf("\n>> Encrypted message: %s\n", ciphertext);
}

// options
void options()
{
  printf("=============================\n");
  printf("        CAESAR CIPHER         \n");
  printf("=============================\n");
  printf("\n1 - Encrypt\n2 - Decrypt\n\n0 - Cancel\n\n");
}

int main()
{
  options(); // menu of options
  int option;
  printf("Enter an option:  ");
  scanf(" %d", &option);

  // options to encrypt or decrypt
  while (option != 0)
  {
    system("cls");
    if (option == 1)
    {
      encryptMessage();
    }
    else if (option == 2)
    {
      decryptMessage();
    }
    else
    {
      printf("\nInvalid value. Please try again.\n");
    }
    system("pause");
    system("cls");
    options(); // menu of options
    printf("Enter an option:  ");
    scanf(" %d", &option);
  }
  return 0;
}
