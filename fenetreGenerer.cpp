/*
 * fenetreGenerer.cpp
 * contient l'implémentation de la fonction qui va générer le fichier .tex
 */

#include "fenetre.h"

void Fenetre::generer()
{
    //On ouvre le fichier et on regarde si on peut écrire dedans
     QString const pathFile = m_file->text() + "/" + m_nomFichier->text() + ".tex";
     QFile file(pathFile);

     if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
     {
          QMessageBox::critical(this, "Erreur", "Impossible d'écrire le fichier à l'endroit indiqué !");
          return;
     }

     //On délcare des QStrings dans lesquelles on va écrire le code
     QString documentClass;
     QString packages;
     QString macros;
     QString fancy;
     QString titlePage;
     QString body;

     QString police = QString::number(m_police->value()); //on caste la taille de police (int) en QString

     //On écrit le code

     documentClass += "\\documentclass[" + m_papier->currentText() + "," + police + "pt]{" + m_type->currentText() + "}\n";
     packages += "\\usepackage[" + m_encodage->currentText() + "]{inputenc}\n";

     packages += "\\usepackage[top=2cm, bottom=2cm, left=2cm, right=2cm]{geometry}\n";

     if(m_maths->isChecked())
     {
         packages += "\\usepackage{amsmaths}\n\\usepackage{amssymb}\n\\usepackage{mathrsfs}\n";
     }

     body += "\\begin{document}\n";

     if(m_ouiH->isChecked() || m_ouiF->isChecked())
     {
         packages += "\\usepackage{fancyhdr}\n";
         macros += "\\renewcommand{\\footrulewidth}{0.5pt}\n";
         fancy += "\\pagestyle{fancy}\n\\lhead{" + m_lHead->text() + "}\n\\chead{" + m_cHead->text() + "}\n\\rhead{" + m_rHead->text() + "}\n";
         fancy += "\\lfoot{" + m_lFoot->text() + "}\n\\cfoot{" + m_cFoot->text() + "}\n\\rfoot{" + m_rFoot->text() + "}\n";

         body += fancy;
     }

     if(m_type->currentText() == "book" || m_type->currentText() == "report")
     {
         titlePage += "\\title{" + m_titre->text() + "}\n \\author{" + m_auteur->text() + "}\n \\date{" + m_date->text() + "}\n";
         body += "\\maketitle \\clearpage  \n";
     }

     body += "\n\n\\end{document}";


     //On ouvre un flux pour placer le tout dans le fichier
     QTextStream write(&file);

     write << "% base code generated with baseTeX\n" << documentClass << packages << "\n" << macros << "\n" << titlePage << "\n" << body << endl;

     QMessageBox::information(this, "Réussite", "Fichier généré avec succès !");
}


