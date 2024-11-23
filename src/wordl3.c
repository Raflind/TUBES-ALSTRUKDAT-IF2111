#include "wordl3.h"

boolean IsAnswerValid(Word *answer){
    // Cek panjang kata
    if (answer->length != 5) {
        return false;
    }
    for(int i = 0; i < answer->length; i++){
        if((answer->contents[i] < 'a') || (answer->contents[i] > 'z' && answer->contents[i] < 'A') || (answer->contents[i]) > 'Z'){
            return false;
        }
    }
    return true;
}

boolean IsWordValid(Word answer){
    return (answer.length == 5);
}

void MakeUppercase(Word *answer){
    for(int i = 0; i < answer->length;i++){
        if(answer->contents[i] >= 'a' && answer->contents[i] <= 'z'){
            answer->contents[i] -= 32;
        }
    }
}

void compareGuess(Word answer, Word secretWord, Word *marker) {
  marker->length = 0;
  for (int i = 0; i < answer.length; i++) {
      char guessChar = answer.contents[i];
      boolean found = false;
      boolean correctPosition = false;

      if (guessChar == secretWord.contents[i]) {
          correctPosition = true;
      } else {
          for (int j = 0; j < secretWord.length; j++) {
              if (guessChar == secretWord.contents[j]) {
                  found = true;
                  break;
              }
          }
      }

      if (correctPosition) {
          marker->contents[marker->length++] = guessChar;
      } else if (found) {
          marker->contents[marker->length++] = guessChar;
          marker->contents[marker->length++] = '*';
      } else {
          marker->contents[marker->length++] = guessChar;
          marker->contents[marker->length++] = '%';
      }
  }
}

void displayPreviousGuesses(Word results[], int attempts) {
  printf("Hasil:\n");
  for (int i = 0; i < attempts; i++) {
      for (int j = 0; j < results[i].length; j++) {
          printf("%c ", results[i].contents[j]);
      }
      printf("\n");
  }
  for (int i = attempts; i < MAX_ATTEMPTS; i++) {
      printf("_ _ _ _ _\n");
  }
}

void PlayWordl3(User *user) {
    if (user->money < 50) {
        printf("Maaf, saldo Anda tidak cukup untuk bermain. Biaya permainan: %d rupiah\n", 50);
        return;
    }

    user->money -= 50;

    // Pilih kata rahasia secara acak dari daftar kata yang sudah ditentukan
    const char* secretWordOptions[] = {
        "BOWEL", "BLOAT", "GLARE", "CLOAK", "TRULY", 
        "UNCLE", "SLATE", "DEMON", "ADIEU", "SLASH"
    };

    int numSecretWords = 10;
    
    int randomIndex = clock() % 10;
    Word secretWord;
    for (int i = 0; i < 5; i++) {
        secretWord.contents[i] = secretWordOptions[randomIndex][i];
        secretWord.length++;
    }

    Word results[MAX_ATTEMPTS];
    int attempts = 0;

    printf("\nWELCOME TO W0RDL3, YOU HAVE 5 CHANCES TO ANSWER BEFORE YOU LOSE!\n\n");
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        printf("_ _ _ _ _\n");
    }
    printf("\n");

    Word answer;

    while (attempts < MAX_ATTEMPTS && ( !IsSameWord(answer, secretWord))) {
        printf("Masukan kata tebakan Anda: ");
        StartWord();
        answer = currentWord;
        

        // Konversi kata ke huruf besar
        MakeUppercase(&answer);

        if (!IsWordValid(answer)) {
            printf("Kata tidak valid! Harus terdiri dari 5 huruf.\n\n");
            continue;
        }

        Word result;
        compareGuess(answer, secretWord, &result);
        results[attempts] = result;
        attempts++;

        displayPreviousGuesses(results, attempts);
        printf("\n");
}

    if (IsSameWord(answer, secretWord)) {
            printf("Selamat, Anda menang!\n");
            printf("+%d rupiah telah ditambahkan ke akun Anda.\n", 1000 -(200 *attempts));
            user->money += 1000 - (200*attempts);
        }

    else{
        printf("Boo! Anda kalah.\n");
        printf("Kata yang benar adalah: ");
        for (int i = 0; i < secretWord.length; i++) {
            printf("%c", secretWord.contents[i]);
        }
        printf("\n");
    }
}