#include <QApplication>
#include "Game.h"

 Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game(); // create the game(view).
    game->show(); // show the view.
    return a.exec();
}
