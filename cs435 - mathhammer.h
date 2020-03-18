#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // handle to screen for colors

int diceroll_generator();
int To_Wound_melee (int StrenghtVToughnessArray[][10]);
int To_Hit_weaponskill_Melee (int WSArray[][10]);
int To_Hit_shooting ();
int To_Wound_Vehicles (int diceRoll);
// scattering function needs dice roll
// function for rand number roll
void data_Output (bool toWoundMelee, bool WSToHitMelee, bool toHitShooting, bool toWoundVehicles, int diceRoll, double rollNeeded);

int main()
{
    bool toWoundMelee = false, WSToHitMelee = false, toHitShooting = false, toWoundVehicles = false;
    int userInput, diceRoll;
    double rollNeeded;
    int StrenghtVToughnessArray[10][10] ={  // array for strength v toughness on character models
 { 4, 5, 6, 6, 0, 0, 0, 0, 0, 0 },   //   _|Toughness 1-10
 { 3, 4, 5, 6, 6, 0, 0, 0, 0, 0 },   //   S
 { 2, 3, 4, 5, 6, 6, 0, 0, 0, 0 },   //   t
 { 2, 2, 3, 4, 5, 6, 6, 0, 0, 0 },   //   r
 { 2, 2, 2, 3, 4, 5, 6, 6, 0, 0 },   //   e
 { 2, 2, 2, 2, 3, 4, 5, 6, 6, 0 },   //   n
 { 2, 2, 2, 2, 2, 3, 4, 5, 6, 6 },   //   g
 { 2, 2, 2, 2, 2, 2, 3, 4, 5, 6 },   //   h
 { 2, 2, 2, 2, 2, 2, 2, 3, 4, 5 },   //   t
 { 2, 2, 2, 2, 2, 2, 2, 2, 3, 4 } }; //  1-10
     int WSArray[10][10] ={    // array for weapon skill on attacker and opponent character models
 { 4, 4, 5, 5, 5, 5, 5, 5, 5, 5 },   // WS_|Opponent 1-10
 { 3, 4, 4, 4, 5, 5, 5, 5, 5, 5 },   //   A
 { 3, 3, 4, 4, 4, 4, 5, 5, 5, 5 },   //   t
 { 3, 3, 3, 4, 4, 4, 4, 4, 5, 5 },   //   t
 { 3, 3, 3, 3, 4, 4, 4, 4, 4, 4 },   //   a
 { 3, 3, 3, 3, 3, 4, 4, 4, 4, 4 },   //   c
 { 3, 3, 3, 3, 3, 3, 4, 4, 4, 4 },   //   k
 { 3, 3, 3, 3, 3, 3, 3, 4, 4, 4 },   //   e
 { 3, 3, 3, 3, 3, 3, 3, 3, 4, 4 },   //   r
 { 3, 3, 3, 3, 3, 3, 3, 3, 3, 4 } }; //  1-10

 diceRoll = diceroll_generator(); // generates random number for the dice before the function decisions

    do // do-while loop for user input
    {
    cout << "to calculate the roll to wound(in melee) press 1,"<<endl;
    cout << "to calculate the roll to hit(in melee) pres 2" << endl;
    cout << "to calculate the roll to hit(in shooting) pres 3" << endl;
    cout << "to calculate the roll to wound Vehicles press 4,"<<endl;
    cout << "Enter a number : ";
    cin >> userInput;

        if (userInput < 1 || userInput > 4)
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color red
            cout << "input invalid" << endl;
            Sleep(1000);
            system("CLS");
            SetConsoleTextAttribute( hConsole, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)); // text color white
        }
        else
        {
            if(userInput == 1)
            {
                toWoundMelee = true;
                rollNeeded = To_Wound_melee(StrenghtVToughnessArray);
            }
            if(userInput == 2)
            {
                WSToHitMelee = true;
                rollNeeded = To_Hit_weaponskill_Melee (WSArray);
            }
            if(userInput == 3)
            {
                toHitShooting = true;
                rollNeeded = To_Hit_shooting ();
            }
            if(userInput == 4)
            {
                toWoundVehicles = true;
                rollNeeded = To_Wound_Vehicles (diceRoll);
            }
        }

    }while (userInput < 0 || userInput > 4);

    data_Output (toWoundMelee, WSToHitMelee, toHitShooting, toWoundVehicles, diceRoll, rollNeeded);

    Sleep(1000);

    return 0;
} // end of main

int To_Wound_melee (int StrenghtVToughnessArray[][10])
{
     int Toughness, Strenght, woundResult;

    do{
        cout << "Enter the strength of the attacking unit : ";
        cin >> Strenght;
        cout << "Enter the toughness of the defending unit : ";
        cin >> Toughness;

        if (Strenght < 1 || Strenght > 10)
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color red
            cout << "Invalid input: Attacker's strength must be between 1 and 10" << endl;
            Sleep(1000);
            system("CLS");
            SetConsoleTextAttribute( hConsole, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)); // text color white
        }
        if (Toughness < 1 || Toughness >10)
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color red
            cout << "Invalid input: Defender's toughness must be between 1 and 10" << endl;
            Sleep(1000);
            system("CLS");
            SetConsoleTextAttribute( hConsole, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)); // text color white
        }
    }while(Strenght < 0 || Strenght > 10 || Toughness < 0 || Toughness > 10);

    Strenght = (Strenght - 1);
    Toughness = (Toughness - 1);
    woundResult = StrenghtVToughnessArray[Strenght][Toughness];

    return(woundResult);
} // end of to wound melee function

int To_Hit_weaponskill_Melee (int WSArray[][10])
{
     int attackerWS, opponentWS, weaponHitResult;

    do{
        cout << "Enter the Weapon skill of the attacker : ";
        cin >> attackerWS;
        cout << "Enter the weapon skill of the opponent : ";
        cin >> opponentWS;

        if (attackerWS < 1 || attackerWS > 10)
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color red
            cout << "Invalid input: Attacker's weapon skill must be between 1 and 10" << endl;
            Sleep(1000);
            system("CLS");
            SetConsoleTextAttribute( hConsole, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)); // text color white
        }
        if (opponentWS < 1 || opponentWS > 10)
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color red
            cout << "Invalid input: Defender's weapon skill must be between 1 and 10" << endl;
            Sleep(1000);
            system("CLS");
            SetConsoleTextAttribute( hConsole, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)); // text color white
        }

    }while((attackerWS < 0 || attackerWS > 10) || (opponentWS < 0 || opponentWS > 10));

    attackerWS = (attackerWS - 1);
    opponentWS = (opponentWS -1);
    weaponHitResult = (WSArray[attackerWS][opponentWS]);

    return(weaponHitResult);
}// end of to hit weapon skill melee function

int To_Hit_shooting ()
{
    int ballisticSkill, ballisticResult;

    do{
        cout << "Enter the Ballistic skill of the shooter : ";
        cin >> ballisticSkill;

        if(ballisticSkill < 1 || ballisticSkill > 10)
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color red
            cout << "Invalid input: Shooter's weapon skill must be between 1 and 10" << endl;
            Sleep(1000);
            system("CLS");
            SetConsoleTextAttribute( hConsole, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)); // text color white
        }
    }while(ballisticSkill < 1 || ballisticSkill > 10);


    if (ballisticSkill > 5)
    {
        ballisticResult = 2;
    }
    if (ballisticSkill == 4)
    {
        ballisticResult = 3;
    }
    if (ballisticSkill == 3)
    {
        ballisticResult = 4;
    }
    if (ballisticSkill == 2)
    {
        ballisticResult = 5;
    }
    if (ballisticSkill <= 1)
    {
        ballisticResult = 6;
    }

    return (ballisticResult);
}//end of to hit shooting function

int To_Wound_Vehicles (int diceRoll)
{
    int armorValue, weaponStrenght, weaponArmorPierce,  vehicalWoundResult, validInputCheck;

do{
        validInputCheck = 0; // resets the sentinal verable to 0 when loop reiterates, meaning the input was invalid

        cout << "Enter the strength of the weapon from the shooter : ";
        cin >> weaponStrenght;
        cout << "Enter the Armor Value of the Vehicle : ";
        cin >> armorValue;
        cout << "Enter the Weapon Armor Piercing value : ";
        cin >> weaponArmorPierce;

        if((weaponStrenght < 4 || weaponStrenght > 10))
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color red
            cout << "Invalid input: Weapon strength must be between 4 and 10" << endl;
            Sleep(1000);
            system("CLS");
            SetConsoleTextAttribute( hConsole, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)); // text color white

        }
        else
        {
            validInputCheck++;
        }

        if ((armorValue < 10 || armorValue > 14))
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color red
            cout << "Invalid input: vehicle armor must be between 10 and 14" << endl;
            Sleep(1000);
            system("CLS");
            SetConsoleTextAttribute( hConsole, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)); // text color white
        }
        else
        {
            validInputCheck++;
        }

        if ((weaponArmorPierce < 1 ) || (weaponArmorPierce > 6))
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color red
            cout << "Invalid input: weapon AP must be between 1 and 6" << endl;
            Sleep(1000);
            system("CLS");
            SetConsoleTextAttribute( hConsole, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)); // text color white
        }
        else
        {
            validInputCheck++;
        }

    }while(validInputCheck < 3);

    vehicalWoundResult = (diceRoll + weaponStrenght);

    if (vehicalWoundResult > armorValue)
    {
        vehicalWoundResult = 3; // pen hit
    }
    else if (vehicalWoundResult == armorValue)
    {
        vehicalWoundResult = 2; // glancing hit
    }
    else
    {
        vehicalWoundResult = 1; // no effect of the hit
    }

    return (vehicalWoundResult);
}// end of to wound vehicles function

int diceroll_generator()
{
    int diceResult;

    srand(time(NULL));
    diceResult = (rand() % 6 + 1 );

    return (diceResult);
}// end of diceroll generator function

void data_Output (bool toWoundMelee, bool WSToHitMelee, bool toHitShooting, bool toWoundVehicles, int diceRoll, double rollNeeded)
{
    if (toWoundMelee == true)
    {
        if(rollNeeded == 0) // chance to hit above 6 on dice therefor unable to wound target
        {
            cout << " Not possible to wound";
        }
        else
        {
                if ((rollNeeded == 3))
                {
                    SetConsoleTextAttribute( hConsole, (FOREGROUND_GREEN | FOREGROUND_INTENSITY)); // text color green
                }
                else if ((rollNeeded == 6))
                {
                    SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY));// text color red
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color yellow
                }

            cout << rollNeeded << "+ on the roll to wound" << endl;
        }

        SetConsoleTextAttribute( hConsole, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)); // text color white
    }// end of to wound melee if true
    if (WSToHitMelee == true) // to hit in melee combat
    {
        if (rollNeeded == 3)
        {
            SetConsoleTextAttribute( hConsole, (FOREGROUND_GREEN | FOREGROUND_INTENSITY)); // text color green
        }
        else if (rollNeeded == 5)
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY));// text color red
        }
        else
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color yellow
        }

        cout << rollNeeded << "+ on the roll to Hit in melee" << endl;

        SetConsoleTextAttribute( hConsole, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)); // text color white
    }// end of WS to hit melee if true
    if(toHitShooting == true) // shooting to hit
    {
        if (rollNeeded <= 3)
        {
            SetConsoleTextAttribute( hConsole, (FOREGROUND_GREEN | FOREGROUND_INTENSITY)); // text color green
        }
        else if (rollNeeded >= 5)
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color red
        }
        else
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color yellow
        }

        cout << rollNeeded << "+ on the roll to Hit in shooting" << endl;

        SetConsoleTextAttribute( hConsole, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)); // text color white
    }// end of to hit shooting if true
    if(toWoundVehicles == true) // to wound vehicle after shooting has hit
    {

        if (rollNeeded = 3) // pen hit
        {
            SetConsoleTextAttribute( hConsole, (FOREGROUND_GREEN | FOREGROUND_INTENSITY)); // text color green
            cout << " Attack Penned vehicle armor" << endl;
        }
        else if (rollNeeded = 2)// glancing hit
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color yellow
            cout << " Attack glanced vehicle armor" << endl;
        }
        else if (rollNeeded = 1)// no effect of the hit
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color red
            cout << " Attack had no effect on vehicle armor" << endl;
        }

        if (diceRoll <= 2)//red color text for diceroll display
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color red
        }
        else if (diceRoll == 3 || diceRoll == 4)//yellow color text for dicetoll display
        {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY)); // text color yellow
        }
        else if (diceRoll >= 5)// green color text for diceroll display
        {
            SetConsoleTextAttribute( hConsole, (FOREGROUND_GREEN | FOREGROUND_INTENSITY)); // text color green
        }

    cout << " " << diceRoll << " was rolled" << endl;
    SetConsoleTextAttribute( hConsole, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)); // text color white
    }// end of to wound vehicles if true