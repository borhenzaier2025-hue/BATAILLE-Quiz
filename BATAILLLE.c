#include <stdio.h>
#include <string.h>


// Définition de la structure pour une question de quiz
typedef struct{
    char question[256];
    char option1[128];
    char option2[128];
    char option3[128];
    char option4[128];
    char correctAnswer; // La réponse correcte est le caractère '1', '2', '3' ou '4'
} question;

// Définition de la structure pour un score élevé
typedef struct {
    char name[30];
    long score;
} score;

// Déclaration des variables globales
question Quizquestion[20]; // Tableau de 20 questions
score hightscore[5]; // Tableau des 5 meilleurs scores
long current_money = 0; // Argent (score) actuel du joueur
char player_name[30] = "unknown"; // Nom du joueur actuel

// Variable temporaire utilisée pour le tri des scores
score temp;


// Fonction pour initialiser le tableau des meilleurs scores
void initializeHighScore()
{
    int i;
    for(i = 0; i < 5; i++) {
        strcpy(hightscore[i].name, "---");
        hightscore[i].score = 0;
    }
}

// Fonction pour initialiser toutes les questions du quiz
void initializeQuestions()
{
    // Initialisation Question 1
    strcpy(Quizquestion[0].question, "What is the capital of France?");
    strcpy(Quizquestion[0].option1, "Paris");
    strcpy(Quizquestion[0].option2, "Berlin");
    strcpy(Quizquestion[0].option3, "Madrid");
    strcpy(Quizquestion[0].option4, "Rome");
    Quizquestion[0].correctAnswer = '1';

    // Initialisation Question 2
    strcpy(Quizquestion[1].question, "Which planet is known as the Red Planet?");
    strcpy(Quizquestion[1].option1, "Venus");
    strcpy(Quizquestion[1].option2, "Mars");
    strcpy(Quizquestion[1].option3, "Jupiter");
    strcpy(Quizquestion[1].option4, "Saturn");
    Quizquestion[1].correctAnswer = '2';

    // Initialisation Question 3
    strcpy(Quizquestion[2].question, "H2O is commonly known as?");
    strcpy(Quizquestion[2].option1, "Salt");
    strcpy(Quizquestion[2].option2, "Water");
    strcpy(Quizquestion[2].option3, "Oxygen");
    strcpy(Quizquestion[2].option4, "Hydrogen");
    Quizquestion[2].correctAnswer = '2';

    // Initialisation Question 4
    strcpy(Quizquestion[3].question, "Who wrote 'Romeo and Juliet'?");
    strcpy(Quizquestion[3].option1, "William Shakespeare");
    strcpy(Quizquestion[3].option2, "Charles Dickens");
    strcpy(Quizquestion[3].option3, "Mark Twain");
    strcpy(Quizquestion[3].option4, "Leo Tolstoy");
    Quizquestion[3].correctAnswer = '1';

    // Initialisation Question 5
    strcpy(Quizquestion[4].question, "Which element has the symbol 'Au'?");
    strcpy(Quizquestion[4].option1, "Silver");
    strcpy(Quizquestion[4].option2, "Gold");
    strcpy(Quizquestion[4].option3, "Iron");
    strcpy(Quizquestion[4].option4, "Copper");
    Quizquestion[4].correctAnswer = '2';

    // Initialisation Question 6
    strcpy(Quizquestion[5].question, "How many continents are on Earth?");
    strcpy(Quizquestion[5].option1, "Five");
    strcpy(Quizquestion[5].option2, "Six");
    strcpy(Quizquestion[5].option3, "Seven");
    strcpy(Quizquestion[5].option4, "Eight");
    Quizquestion[5].correctAnswer = '3';

    // Initialisation Question 7
    strcpy(Quizquestion[6].question, "What is the largest mammal?");
    strcpy(Quizquestion[6].option1, "Elephant");
    strcpy(Quizquestion[6].option2, "Blue whale");
    strcpy(Quizquestion[6].option3, "Giraffe");
    strcpy(Quizquestion[6].option4, "Hippopotamus");
    Quizquestion[6].correctAnswer = '2';

    // Initialisation Question 8
    strcpy(Quizquestion[7].question, "Which ocean is the largest?");
    strcpy(Quizquestion[7].option1, "Atlantic");
    strcpy(Quizquestion[7].option2, "Indian");
    strcpy(Quizquestion[7].option3, "Pacific");
    strcpy(Quizquestion[7].option4, "Arctic");
    Quizquestion[7].correctAnswer = '3';

    // Initialisation Question 9
    strcpy(Quizquestion[8].question, "Square root of 64?");
    strcpy(Quizquestion[8].option1, "6");
    strcpy(Quizquestion[8].option2, "7");
    strcpy(Quizquestion[8].option3, "8");
    strcpy(Quizquestion[8].option4, "9");
    Quizquestion[8].correctAnswer = '3';

    // Initialisation Question 10
    strcpy(Quizquestion[9].question, "Who painted the Mona Lisa?");
    strcpy(Quizquestion[9].option1, "Vincent Van Gogh");
    strcpy(Quizquestion[9].option2, "Pablo Picasso");
    strcpy(Quizquestion[9].option3, "Leonardo da Vinci");
    strcpy(Quizquestion[9].option4, "Claude Monet");
    Quizquestion[9].correctAnswer = '3';

    // Initialisation Question 11
    strcpy(Quizquestion[10].question, "Which country is 'Land of Rising Sun'?");
    strcpy(Quizquestion[10].option1, "China");
    strcpy(Quizquestion[10].option2, "Japan");
    strcpy(Quizquestion[10].option3, "Thailand");
    strcpy(Quizquestion[10].option4, "South Korea");
    Quizquestion[10].correctAnswer = '2';

    // Initialisation Question 12
    strcpy(Quizquestion[11].question, "Which gas do plants absorb?");
    strcpy(Quizquestion[11].option1, "Oxygen");
    strcpy(Quizquestion[11].option2, "Nitrogen");
    strcpy(Quizquestion[11].option3, "Carbon Dioxide");
    strcpy(Quizquestion[11].option4, "Hydrogen");
    Quizquestion[11].correctAnswer = '3';

    // Initialisation Question 13
    strcpy(Quizquestion[12].question, "Instrument to measure temperature?");
    strcpy(Quizquestion[12].option1, "Thermometer");
    strcpy(Quizquestion[12].option2, "Barometer");
    strcpy(Quizquestion[12].option3, "Anemometer");
    strcpy(Quizquestion[12].option4, "Hygrometer");
    Quizquestion[12].correctAnswer = '1';

    // Initialisation Question 14
    strcpy(Quizquestion[13].question, "Chemical formula for table salt?");
    strcpy(Quizquestion[13].option1, "H2O");
    strcpy(Quizquestion[13].option2, "NaCl");
    strcpy(Quizquestion[13].option3, "CO2");
    strcpy(Quizquestion[13].option4, "C6H12O6");
    Quizquestion[13].correctAnswer = '2';

    // Initialisation Question 15
    strcpy(Quizquestion[14].question, "Who discovered gravity (apple)?");
    strcpy(Quizquestion[14].option1, "Albert Einstein");
    strcpy(Quizquestion[14].option2, "Isaac Newton");
    strcpy(Quizquestion[14].option3, "Galileo Galilei");
    strcpy(Quizquestion[14].option4, "Nikola Tesla");
    Quizquestion[14].correctAnswer = '2';

    // Initialisation Question 16
    strcpy(Quizquestion[15].question, "Largest desert in the world?");
    strcpy(Quizquestion[15].option1, "Sahara");
    strcpy(Quizquestion[15].option2, "Gobi");
    strcpy(Quizquestion[15].option3, "Kalahari");
    strcpy(Quizquestion[15].option4, "Antarctica");
    Quizquestion[15].correctAnswer = '4';

    // Initialisation Question 17
    strcpy(Quizquestion[16].question, "Who invented the telephone?");
    strcpy(Quizquestion[16].option1, "Alexander Graham Bell");
    strcpy(Quizquestion[16].option2, "Thomas Edison");
    strcpy(Quizquestion[16].option3, "Nikola Tesla");
    strcpy(Quizquestion[16].option4, "Guglielmo Marconi");
    Quizquestion[16].correctAnswer = '1';

    // Initialisation Question 18
    strcpy(Quizquestion[17].question, "Smallest prime number?");
    strcpy(Quizquestion[17].option1, "0");
    strcpy(Quizquestion[17].option2, "1");
    strcpy(Quizquestion[17].option3, "2");
    strcpy(Quizquestion[17].option4, "3");
    Quizquestion[17].correctAnswer = '3';

    // Initialisation Question 19
    strcpy(Quizquestion[18].question, "Fastest land animal?");
    strcpy(Quizquestion[18].option1, "Cheetah");
    strcpy(Quizquestion[18].option2, "Lion");
    strcpy(Quizquestion[18].option3, "Tiger");
    strcpy(Quizquestion[18].option4, "Horse");
    Quizquestion[18].correctAnswer = '1';

    // Initialisation Question 20
    strcpy(Quizquestion[19].question, "Which is the largest planet?");
    strcpy(Quizquestion[19].option1, "Earth");
    strcpy(Quizquestion[19].option2, "Jupiter");
    strcpy(Quizquestion[19].option3, "Saturn");
    strcpy(Quizquestion[19].option4, "Neptune");
    Quizquestion[19].correctAnswer = '2';
}

// Fonction pour trier le tableau des meilleurs scores (du plus grand au plus petit)
void hightScoreSort()
{
    for(int i = 0; i < 5 - 1; i++)
    {
        int MaxIndex = i;
        for(int j = i + 1; j < 5; j++)
        {
            // Critère de tri : score décroissant, puis nom croissant si scores égaux
            if(hightscore[j].score > hightscore[MaxIndex].score ||
               (hightscore[j].score == hightscore[MaxIndex].score &&
                strcmp(hightscore[j].name, hightscore[MaxIndex].name) < 0))
            {

                MaxIndex = j;
            }
        }
        // Échanger l'élément actuel avec le maximum trouvé
        if(MaxIndex != i)
        {
            temp = hightscore[i];
            hightscore[i] = hightscore[MaxIndex];
            hightscore[MaxIndex] = temp;
        }
    }
}

// Fonction pour mettre à jour le tableau des meilleurs scores
void updateHighScores()
{
    hightScoreSort(); // S'assurer que le tableau est trié

    // Si le score actuel est supérieur au score le plus bas du Top 5 (indice 4)
    if(current_money > hightscore[4].score)
    {
        strcpy(hightscore[4].name, player_name);
        hightscore[4].score = current_money;
        hightScoreSort(); // Trier à nouveau pour placer le nouveau score correctement

        printf("\nCongratulations %s! New score: %ld$\n", player_name, current_money);
    }
}

// Fonction pour afficher les 5 meilleurs scores
void ShowScore()
{
    int i;
    hightScoreSort();
    printf("============TOP5==============\n");
    for(i = 0; i < 5; i++)
    {
        // Affichage formaté du rang, du nom et du score
        printf("%d. %-30s: %ld$\n", i + 1, hightscore[i].name, hightscore[i].score);
    }
    printf("==============================\n");
}

// Fonction pour afficher une question spécifique
void printQuestion(int index)
{
    printf("\nQuestion.%d: %s\n", index + 1, Quizquestion[index].question);
    // Affichage des 4 options
    printf("1) %s\n2) %s\n3) %s\n4) %s\n",
           Quizquestion[index].option1,
           Quizquestion[index].option2,
           Quizquestion[index].option3,
           Quizquestion[index].option4);
}

// Fonction pour vérifier si la réponse de l'utilisateur est correcte
int checkAnswer(int index , char answer)
{
    return (answer == Quizquestion[index].correctAnswer);
}

// Fonction pour afficher l'introduction de la partie principale
void printTourIntro()
{
    printf("\n=== MAIN TOUR ===\n");
    printf("Each correct answer: +100000$\n");
    printf("Wrong answer ends the game.\n");
    printf("Press X to quit and keep your prize.\n");
}

// Fonction pour démarrer la manche d'échauffement (Warmup Tour)
int startWarmupTour()
{
    int correctCount = 0;
    char userAnswer;
    int i;

    // Vider le buffer d'entrée avant de lire l'entrée de l'utilisateur
    while ((getchar()) != '\n');

    printf("\n=== Warmup Round (2/3 correct to qualify) ===\n");
    for(i = 0; i < 3; i++){
        printQuestion(i);
        printf("Your answer (1-4): ");
        // Lire un caractère en ignorant les espaces blancs précédents
        if (scanf(" %c", &userAnswer) != 1) {
            // Gérer l'erreur de lecture
            while ((getchar()) != '\n');
            continue;
        }

        if(checkAnswer(i, userAnswer)){
            printf("Correct!\n");
            correctCount++;
        }else{
            printf("Incorrect. Correct answer: %c\n", Quizquestion[i].correctAnswer);
        }
    }

    printf("\nResult: %d / 3\n", correctCount);
    // Retourne vrai si 2 réponses ou plus sont correctes
    return (correctCount >= 2);
}

// Fonction pour démarrer la partie principale (Main Tour)
void MainTOUR()
{
    current_money = 0;
    int QuestionIndex = 3; // Commence à la quatrième question (indice 3)
    char userAnswer;

    // Vider le buffer d'entrée
    while ((getchar()) != '\n');

    printTourIntro();
    // Boucle principale : continue jusqu'à 1,000,000$ ou jusqu'à la fin des 20 questions
    while(current_money < 1000000 && QuestionIndex < 20 )
    {
        printQuestion(QuestionIndex);
        printf("Your answer (1-4) or X to quit: ");

        if (scanf(" %c", &userAnswer) != 1) {
            while ((getchar()) != '\n');
            continue;
        }

        // Option pour quitter
        if(userAnswer == 'x' || userAnswer == 'X' ){
            printf("You quit. Prize: %ld $\n", current_money);
            break;
        }

        if(checkAnswer(QuestionIndex, userAnswer)){
            current_money += 100000;
            printf("Correct! Total: %ld $\n", current_money);
            QuestionIndex++;
        }
        else
        {
            printf("Incorrect. Game Over. Final prize: %ld $\n", current_money);
            break; // Le jeu se termine en cas de mauvaise réponse
        }
    }

    printf("\nYou answered %d questions correctly in the Main Tour.\n", QuestionIndex - 3);
    if (current_money >= 1000000) {
        printf("\n CONGRATULATIONS! You reached 1,000,000$ and became a MILLIONAIRE! \n");
    }
    updateHighScores(); // Mettre à jour les meilleurs scores
}

// Fonction d'aide
void help()
{
    printf("\n=== HELP ===\n");
    printf("1) Enter your name.\n");
    printf("2) Start game with 'T'. Warmup: 3 questions, need 2 correct.\n");
    printf("3) Main Tour: up to 17 questions (from question 4 to 20). Each correct +100000$. Wrong ends game.\n");
    printf("4) Press 'X' to quit Main Tour.\n");
    printf("5) Top 5 scores recorded in memory.\n");
    printf("6) Enjoy the game and learn!\n");
    printf("================\n");
}

// Fonction pour confirmer la sortie
int confirmQuit()
{
    char ch;
    printf("Are you sure you want to quit? (Y/N): ");
    scanf(" %c", &ch);
    return (ch == 'Y' || ch == 'y');
}

// Fonction pour demander si le joueur veut rejouer (non utilisée dans la boucle main actuelle, mais incluse)
int playAgainPrompt()
{
    char ch;
    printf("Do you want to play again? (Y/N): ");
    scanf(" %c", &ch);
    return (ch == 'Y' || ch == 'y');
}

// Fonction principale
int main()
{
    char choice;

    initializeQuestions(); // Charger les questions
    initializeHighScore(); // Initialiser le tableau des scores

    printf("Enter your name (max 29 chars): ");
    scanf("%29s", player_name);
    // Vider le buffer après la lecture du nom
    while ((getchar()) != '\n');

    printf("Welcome, %s!\n", player_name);

    do {
        printf("\n--- MENU ---\nT: Play\nH: Help\nS: Scores\nQ: Quit\nChoice: ");
        // Lire le choix en ignorant les espaces blancs
        if (scanf(" %c", &choice) != 1) {
            while ((getchar()) != '\n');
            continue;
        }

        switch (choice) {
            case 'T': case 't':
                // Démarrer la manche d'echufement, si qualifié, démarrer la manche principale
                if (startWarmupTour()) MainTOUR();
                break;
            case 'H': case 'h':
                help();
                break;
            case 'S': case 's':
                ShowScore();
                break;
            case 'Q': case 'q':
                if (confirmQuit()) {
                    printf("Goodbye, %s!\n", player_name);
                    return 0; // Quitter le programme
                }
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (1); // Boucle infinie, le programme se termine uniquement si 'Q' est choisi et confirmé

    return 0;
}
