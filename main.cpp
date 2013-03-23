/*
 * baseTeX
 * 2013 - alex205 (Alexis GIRARDI),
 *
 * baseTeX is a free software released under the GNU/GPL License
 * http://www.gnu.org/licenses/gpl.html
 *
 * https://etud.insa-toulouse.fr/~girardi/basetex
 */

#include "fenetre.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Fenetre w;
    w.show();
    
    return a.exec();
}
