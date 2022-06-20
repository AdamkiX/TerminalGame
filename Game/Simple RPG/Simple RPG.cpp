#include "LoadGame.h"
#include "Movement.h"
#include "LevelGen.h"
#include "FightSystem.h"
#include "Item.h"
#include "Inventory.h"
#include "Commands.h"

#include "Player.h"
#include "Warior.h"
#include "Mage.h"
#include "Rogue.h"

#include "Enemy.h"

#include <iostream>
#include <string>
#include <locale.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <vector>

int Item::id = 0;
int Enemy::id = 0;
bool Commands::devMode = 0;
int Movement::bossRoom = 0;

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Polish");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    Shop shop(1);
    Commands cms;
    Inventory inv;
    LevelGen gen;
    Player* wsk = 0;
    Movement move;
    FightSystem fight;
    Item* wskI = 0;
    SmallHpPotion sHp;
    MedHpPotion mHp;
    LargeHpPotion lHp;
    vector<Item*> temp;

    string p_name = "";
    char choice = 0;
    bool choosen = false, finished = false, gameover = false;
    bool chosen = false, loadingGame = false;
    int menuChoice = 0;



    std::cout << "PROSTA GRA RPG" << endl << endl;
    std::cout << "1. NOWA GRA" << endl;
    std::cout << "2. WCZYTAJ GRĘ" << endl;
    std::cout << "3. WYJŚCIE" << endl;
    do
    {
        menuChoice = _getch();

        switch (menuChoice)
        {
        case '1':
        {
            chosen = true; 
            break;
        }
        case '2':
        {
            loadingGame = true;
            LoadGame load;
            gen = load.LoadLevel();
            // cout << "Poziom wczytany" << endl;
            // system("pause");
            wsk = load.LoadPlayerStats();
            //cout << "Gracz wczytany" << endl;
            //system("pause");
            inv = load.LoadInventory();
            temp = load.LoadItems();
            for (int i = 0; i < load.temp.size(); i++)
            {
                inv.AddItem(temp[i]);
            }
            load.temp.clear(); load.temp.shrink_to_fit();
            inv.ShowInv();
            // cout << "Inwentarz wczytany" << endl;
            // system("pause");
            shop = load.LoadShop();
            for (int i = 0; i < load.temp.size(); i++)
            {
                shop.AddItem(load.temp[i]);
            }
            load.temp.clear(); load.temp.shrink_to_fit();
            // cout << "Sklep wczytany" << endl;
            // system("pause");
            load.~LoadGame();
            chosen = true;
            break;
        }
        case '3':
        {
            system("exit");
            break;
        }
        default:
        {
            break;
        }
        }
    } while (chosen == false);

    system("cls");

    if (loadingGame == false)
    {
        std::cout << "Witaj w prostej grze RPG. Twoim celem jest dotarcie do samej czeluści lochu "
            << "i pokonanie tam Władcy Potworów. " << endl;

        std::cout << "Zanim zaczniesz musisz wybrać klasę postaci poprzez wpisane odpowiadającej klasie liczby:" << endl
            << "1.    Wojownik" << endl << "2.    Mag" << endl << "3.    Złodziej" << endl;

        wskI = &sHp;
        inv.AddPotHolder(wskI);
        wskI = &mHp;
        inv.AddPotHolder(wskI);
        wskI = &lHp;
        inv.AddPotHolder(wskI);

        inv.AddStartPots();

        do
        {

            cin >> choice;

            switch (choice)
            {
            case '1':
            {
                Warior player(1);
                wsk = &player;
                choosen = true;
                break;
            }
            case '2':
            {
                Mage player(1);
                wsk = &player;
                choosen = true;
                break;
            }
            case '3':
            {
                Rogue player(1);
                wsk = &player;
                choosen = true;
                break;
            }
            default:
            {
                std::cout << "Wybrano nie poprawną klasę. Istnieją 3 klasy do wyboru:" << endl
                    << "1.    Wojownik" << endl << "2.    Mag" << endl << "3.    Złodziej" << endl;
                break;
            }
            }

        } while (choosen == false);


        std::cout << "Jak chcesz się nazywać?" << endl;

        wsk->Naming(choice);

        std::cout << "Oto twoja postać: " << endl;
        wsk->Stats();
    }


    int zone = 1;
    do
    {
        finished = false;
        Shop shopNew(gen.GetZone());
        if (loadingGame == false)
        {
            gen.Generate();
            zone = gen.GetZone();
            fight.zone = zone;
            system("cls");
        }
        else
        {
            shopNew = shop;
        }
        loadingGame = false;
        do
        {
            move.MovementCheck(gen);
            gen.DrawMap();
            move.Action(fight, gen, wsk, inv, cms, shopNew);
            if (move.room == 5)
            {
                finished = move.ExitAsk();
            }
            move.RoomCheck(gen.tilesY,gen.GetZone(),move.room, fight, inv, wskI, wsk, shopNew);
            gameover = !fight.FightCheck(wsk,inv,gen.GetZone());
            if (gameover == true)
            {
                finished = gameover;
            }
            if(gameover == 0)
            system("cls");
        } while (finished == false);

        gen.Destroy();
        shop.~Shop();
        if (gen.GetZone() == 6)
        {
            gameover = true;
            std::cout << "Gratuluję! Udało Ci się zajść na samo dno lochów oraz pokonałeś"
                << "Przywódcę potworów" << endl;
        }
    } while (gameover == false);
    
    std::cout << "Koniec gry" << endl << endl << endl;

    cms.~Commands();
    inv.~Inventory();
    wsk->DestroyPlayer();
    move.~Movement();
    fight.~FightSystem();
    sHp.~SmallHpPotion();
    mHp.~MedHpPotion();
    lHp.~LargeHpPotion();
    temp.~vector();
}

