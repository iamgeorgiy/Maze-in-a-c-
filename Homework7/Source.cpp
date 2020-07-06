#include<iostream>
#include"string"
#include<ctime>
#include<conio.h>
using namespace std;
int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));

    const int sizeMap = 12;
    int currentX = 1;
    int currentY = 1;
    int point = 0;

    string pass;
    int chit_activate = 0;
    int save_prosto = 0;

    int point_count = 0;
    int point_got = 0;

    int key_got = 0;
    int key_count = 0;

    bool isGameOver = false;
    bool isWin = false;
    char maze[sizeMap][sizeMap] = {
 '#','#','#','#','#','#','#','#','#','#','#','#',
 '#','P',' ',' ',' ',' ','#','#','#','#','#','#',
 '#',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',
 '#',' ','#','.',' ','#','#','#','#','.','#','#',
 '#',' ','#',' ',' ',' ',' ',' ',' ',' ','#','#',
 '#',' ','#','#','#','#','#','#','#',' ','#','#',
 '#',' ',' ',' ','#',' ',' ',' ',' ',' ','.','#',
 '#','#','#',' ','#',' ','#','#','#','/','#','#',
 '#',' ',' ',' ','#',' ',' ',' ','#',' ',' ','#',
 '#',' ','#','#','#','#',' ',' ','#','#',' ','#',
 '#',' ',' ',' ',' ',' ',' ',' ','.','#','F','#',
 '#','#','#','#','#','#','#','#','#','#','#','#', };
    maze[currentX][currentY] = 'P'; //Вставляє нашого героя на потрібну позицію!
    for (int i = 0; i < sizeMap; i++) // вивiд матрицi
    {
        for (int j = 0; j < sizeMap; j++)
        {
            if (maze[i][j] == ' ') {
                point = rand() % 100;
                if (point % 11 == 0 && point_count < 7) {
                    maze[i][j] = '$';
                    point_count++;
                }
                else if (i > 8 && j < 5 && point % 3 == 0 && key_count == 0) {
                    maze[i][j] = 'D';
                    key_count++;
                }
            }
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Якщо у Вас э 4iт код - натиснiть y" << endl;
    do
    {
        int key = _getch();
        switch (key)
        {

        case 119: { //up
            if (maze[currentX - 1][currentY] == '.') { // чи програли ми?
                system("cls");
                isGameOver = true;
            }
            else if (maze[currentX - 1][currentY] == 'F' && point_got > 3 && key_got == 1) { // чи виграли ми? //  
                system("cls");
                isWin != true;
            }
            else if (maze[currentX - 1][currentY] != '#' || chit_activate == 1)
            {
                system("cls");
                if (maze[currentX - 1][currentY] == '#' && chit_activate == 1) { //йдемо крізь стіни
                    save_prosto++;
                    maze[currentX][currentY] = ' ';
                }
                else if (maze[currentX - 1][currentY] == '$') { // збираємо $
                    point_got++;
                    maze[currentX][currentY] = ' '; // забирає героя з попередньої клiтинки
                }
                else if (maze[currentX - 1][currentY] == 'D') { // збираємо D
                    key_got++;
                    maze[currentX][currentY] = ' '; // забирає героя з попередньої клiтинки
                }
                else if (maze[sizeMap][sizeMap] == 'P') { //якщо ми прийшли до фiнiшу без усiх ключiв та дверей
                    maze[currentX][currentY] = 'F';
                }
                else {
                    maze[currentX][currentY] = ' '; // забирає героя з попередньої клiтинки
                }
                if (save_prosto == 2 || save_prosto == 1 && maze[currentX - 1][currentY] != '#') { // ставимо стіну назад 
                    maze[currentX][currentY] = '#';
                    save_prosto--;
                }
                currentX--;
                maze[currentX][currentY] = 'P';// вставляє героя на потрiбну позицiю
                for (int i = 0; i < sizeMap; i++) // вивiд матрицi
                {
                    for (int j = 0; j < sizeMap; j++)
                    {
                        cout << maze[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl << "Зiбраних ключiв: " << key_got << " / 1" << endl << "Набрано балiв :" << point_got << " - з 4 необхiдних" << endl;
            }
        }break;

        case 100: { //right
            if (maze[currentX][currentY + 1] == '.') {// чи програли ми?
                system("cls");
                isGameOver = true;
            }
            else if (maze[currentX][currentY + 1] == 'F' && point_got > 3 && key_got == 1) { // чи виграли ми?
                system("cls");
                isWin != true;
            }
            else if (maze[currentX][currentY + 1] != '#' || chit_activate == 1)
            {

                system("cls");
                if (maze[currentX][currentY + 1] == '#' && chit_activate == 1) { //йдемо крізь стіни
                    save_prosto++;
                    maze[currentX][currentY] = ' ';
                }
                else if (maze[currentX][currentY + 1] == '$') {
                    point_got++;
                }
                else if (maze[currentX][currentY + 1] == 'D') {
                    key_got++;
                }
                maze[currentX][currentY] = ' '; // забирає героя з попередньої клiтинки
                if (save_prosto == 2 || save_prosto == 1 && maze[currentX][currentY + 1] != '#') { // ставимо стіну назад 
                    maze[currentX][currentY] = '#';
                    save_prosto--;
                }
                currentY++;
                maze[currentX][currentY] = 'P';// вставляє героя на потрiбну позицiю
                for (int i = 0; i < sizeMap; i++) // вивiд матрицi
                {
                    for (int j = 0; j < sizeMap; j++)
                    {
                        cout << maze[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl << "Зiбраних ключiв: " << key_got << " / 1" << endl << "Набрано балiв :" << point_got << " - з 4 необхiдних" << endl;
            }
        }break;

        case 115: { //down
            if (maze[currentX + 1][currentY] == '.') { // чи програли ми?
                system("cls");
                isGameOver = true;
            }
            else if (maze[currentX + 1][currentY] == 'F' && point_got > 3 && key_got == 1) { // чи виграли ми?
                system("cls");
                isWin = true;
            }
            else if (maze[currentX + 1][currentY] != '#' || chit_activate == 1) {
                system("cls");
                if (maze[currentX + 1][currentY] == '#' && chit_activate == 1) { //йдемо крізь стіни
                    save_prosto++;
                    maze[currentX][currentY] = ' ';
                }
                else if (maze[currentX + 1][currentY] == '$') {
                    point_got++;
                }
                else if (maze[currentX + 1][currentY] == 'D') {
                    key_got++;
                }
                maze[currentX][currentY] = ' '; // забирає героя з попередньої клiтинки
                if (save_prosto == 2 || save_prosto == 1 && maze[currentX + 1][currentY] != '#') { // ставимо стіну назад 
                    maze[currentX][currentY] = '#';
                    save_prosto--;
                }
                currentX++;
                maze[currentX][currentY] = 'P';// вставляє героя на потрiбну позицiю
                for (int i = 0; i < sizeMap; i++) // вивiд матрицi
                {
                    for (int j = 0; j < sizeMap; j++)
                    {
                        cout << maze[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl << "Зiбраних ключiв: " << key_got << " / 1" << endl << "Набрано балiв :" << point_got << " - з 4 необхiдних" << endl;
            }
        }break;

        case 97: { // left
            if (maze[currentX][currentY - 1] == '.') {// чи програли ми?
                system("cls");
                isGameOver = true;
            }
            else if (maze[currentX][currentY - 1] == 'F' && point_got > 3 && key_got == 1) { // чи виграли ми?
                system("cls");
                isWin = true;
            }
            else if (maze[currentX][currentY - 1] != '#' || chit_activate == 1)
            {
                system("cls");
                if (maze[currentX][currentY - 1] == '#' && chit_activate == 1) { //йдемо крізь стіни
                    save_prosto++;
                    maze[currentX][currentY] = ' ';
                }
                else if (maze[currentX][currentY - 1] == '$') {
                    point_got++;
                }
                else if (maze[currentX][currentY - 1] == 'D') {
                    key_got++;
                }
                maze[currentX][currentY] = ' '; // забирає героя з попередньої клiтинки
                if (save_prosto == 2 || save_prosto == 1 && maze[currentX][currentY - 1] != '#') { // ставимо стіну назад 
                    maze[currentX][currentY] = '#';
                    save_prosto--;
                }
                currentY--;
                maze[currentX][currentY] = 'P';// вставляє героя на потрiбну позицiю
                for (int i = 0; i < sizeMap; i++) // вивiд матрицi
                {
                    for (int j = 0; j < sizeMap; j++)
                    {
                        cout << maze[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl << "Зiбраних ключiв: " << key_got << " / 1" << endl << "Набрано балiв :" << point_got << " - з 4 необхiдних" << endl;
            }
        }break;
        case 121: {//чит код:
            cout << "Введiть чит код:" << endl;
            getline(cin, pass);
            if (pass == "BY021") {
                cout << "Чит код активовано!" << endl;
                chit_activate = 1;
            }
        }break;
        }



    } while (isGameOver != true && isWin != true);
    if (isWin == true) {


        cout << "                                                                                                          " << endl;
        cout << "                                                                                                          " << endl;
        cout << "     .             .                    .          .              .                                       " << endl;
        cout << "@@@      5@@@     @@@@@@@      @@@.     @@@        @@@    M@@@     @@@ r@@M  h@@@     @@@    @@@          " << endl;
        cout << " @@@s   B@@@    @@@@@@@@@@@    @@@      @@@        @@@    @@@@@   ,@@@ r@@M  9@@@@    @@@    @@@          " << endl;
        cout << "  @@@  .@@@  . @@@       @@@   @@@      @@@        M@@   #@@@@@   @@@. r@@M  9@@@@@   @@@    @@@          " << endl;
        cout << "   @@@s@@@    5@@@      .@@@3  @@@      @@@         @@@ .@@@S@@  .@@@  r@@M  9@@X@@@  @@@    @@@          " << endl;
        cout << "    @@@@X     B@@3       2@@@  @@@      @@@         @@@  @@2 @@@ A@@   r@@M  9@@. @@@ @@@    @@@          " << endl;
        cout << "     @@@      3@@#       #@@9  @@@      @@@         .@@#@@@  .@@ @@@   r@@M  9@@.  @@@@@@    M@#          " << endl;
        cout << "    .@@@       @@@       @@@   @@@      @@@          @@@@@h   @@@@@r   r@@M  9@@.  A@@@@@    9@9          " << endl;
        cout << "     @@@       @@@@B   &@@@@   @@@@    @@@M.         S@@@@    i@@@@    r@@M  9@@.   r@@@@    #M#          " << endl;
        cout << "     @@@       . @@@@@@@@@      ,@@@@@@@@.            @@@S     @@@@    r@@M  h@@.     @@@    @@@          " << endl;
        cout << "                                                                                                          " << endl;
        cout << "                                                                                                          " << endl;
        cout << "                                                                                                          " << endl;
        cout << "                                                                                                          " << endl;
        cout << "                                                                                                          " << endl;
        cout << "                                                                                                          " << endl;
        cout << "                                                                                                          " << endl;
        cout << "                                                                                                          " << endl;

    }
    else {
        cout << "You loose" << endl;
    }

    return 0;
}