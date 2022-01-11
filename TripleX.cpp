#include <iostream>
#include <string>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "=====================\n";
    std::cout << "     A L I E N\n";
    std::cout << "C O D E B R E A K E R\n";
    std::cout << "=====================\n" << std::endl;

    // print two statements introducing the game premise
    std::cout << "You are a scientist working at Area 51, trying to decrypt a level " << Difficulty;
    std::cout << " encoded alien message...\nYou must enter the correct sequence of numbers to continue...\n\n";
}

bool bPlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    
    //print sum and product of 3 variables
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "- There are 3 numbers in the code";
    std::cout << "\n- The codes add-up to: " << CodeSum;
    std::cout << "\n- The codes multiply to give: " << CodeProduct << std::endl;

    //decrypted message pieces revealed by solving each level
    //"Don't forget to drink your Ovaltine"
    std::string LevelWord[5] = {"Don't'", "Don't Forget'", "Don't Forget To Drink'", "Don't Forget To Drink Your'", "Don't Forget To Drink Your Ovaltine'"};

    //store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    //print sum and product of 3 guess variables
    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    //check if player guesses are correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou've decrypted the message! It says..'" << LevelWord[Difficulty - 1] << std::endl;
        return true;    
    }
    else 
    {
        std::cout << "\nThat's the incorrect sequence, try again.\n";
        return false;
    }
}

int main() 
{
    srand(time(NULL)); //creates random time based on time of day

    int LevelDifficulty = 1;
    int const MaxLevel = 5;
    while (LevelDifficulty <= MaxLevel)
    {
        bool bLevelComplete = bPlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
            if (LevelDifficulty < MaxLevel)
            {
                std::cout << "...hmm keep going!\n";
            }
        }
        //else
        //{
        //    return false;
        //}
        
    }
    
    std::cout << "\nWelp, probably shouldn't tell anyone about this. But well done! You decrypted the whole message!\n";
    return 0;
}