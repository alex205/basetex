/*
 * fenetreSlot.cpp
 * contient l'implémentation de tous les slots personnalisés
 */

#include "fenetre.h"

//active ou désactive les champs pour générer la première page
void Fenetre::setPremierePage(QString type)
{
    if(type == "report" || type == "book")
    {
        m_titre->setEnabled(true);
        m_auteur->setEnabled(true);
        m_date->setEnabled(true);
    }
    else
    {
        m_titre->setEnabled(false);
        m_auteur->setEnabled(false);
        m_date->setEnabled(false);
    }
}

//désactive les champs pour le header
void Fenetre::disableHeader(bool checked)
{
    if(checked)
    {
        m_lHead->setEnabled(false);
        m_cHead->setEnabled(false);
        m_rHead->setEnabled(false);
    }
}

//active les champs pour le header
void Fenetre::enableHeader(bool checked)
{
    if(checked)
    {
        m_lHead->setEnabled(true);
        m_cHead->setEnabled(true);
        m_rHead->setEnabled(true);
    }
}

//désactive les champs pour le footer
void Fenetre::disableFooter(bool checked)
{
    if(checked)
    {
            m_lFoot->setEnabled(false);
            m_cFoot->setEnabled(false);
            m_rFoot->setEnabled(false);
    }
}

//active les champs pour le footer
void Fenetre::enableFooter(bool checked)
{
    if(checked)
    {
            m_lFoot->setEnabled(true);
            m_cFoot->setEnabled(true);
            m_rFoot->setEnabled(true);
    }
}

//donne l'endroit où enregistrer le fichier
void Fenetre::emplacementFichier()
{
    QString path = QFileDialog::getExistingDirectory(this);
    m_file->setText(path);
}

//s'occupe de changer le titre de la fenetre en fonction du tire de fichier
void Fenetre::changerTitre(QString titre)
{
    setWindowTitle("baseTeX - " + titre + ".tex");
    if(m_nomFichier->text().isEmpty())
    {
        setWindowTitle("baseTeX");
    }
}

//charge la préconfiguration
void Fenetre::chargerPreconf()
{
    QString path_preconf = QFileDialog::getOpenFileName(this, tr("Charger préconfiguration"), QString(), tr("Fichier de préconfiguration (*.bt)"));

    QFile preconf(path_preconf);
    preconf.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&preconf);

    unsigned int i(1);
    QString ligne;
    while(! flux.atEnd())
    {
        ligne = flux.readLine();
        traitementLigne(i, ligne); // parse le fichier de préconf
        i++;


    }

}

/*
 * sauve la préconfiguration
 * créer un simple fichier avec infos ligne par ligne
 */
void Fenetre::sauverPreconf()
{
    QString path_preconf = QFileDialog::getSaveFileName(this, tr("Sauver préconfiguration"), QString(), tr("Fichier de préconfiguration (*.bt)"));
    path_preconf += ".bt";

    QFile preconf(path_preconf);
    if (!preconf.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible d'écrire le fichier de préconfiguration"));
    }

    QTextStream flux(&preconf);
    flux.setCodec("UTF-8");

    flux << m_type->currentIndex() << endl;
    flux << QString::number(m_police->value()) << endl;
    flux << m_encodage->currentIndex() << endl;
    flux << m_papier->currentIndex() << endl;
    flux << m_titre->text() << endl;
    flux << m_auteur->text() << endl;
    flux << m_date->text() << endl;
    if(m_ouiH->isChecked())
    {
        flux << "true" << endl;
    }
    else
    {
        flux << "false" << endl;
    }
    flux << m_lHead->text() << endl;
    flux << m_cHead->text() << endl;
    flux << m_rHead->text() << endl;
    if(m_ouiF->isChecked())
    {
        flux << "true" << endl;
    }
    else
    {
        flux << "false" << endl;
    }
    flux << m_lFoot->text() << endl;
    flux << m_cFoot->text() << endl;
    flux << m_rFoot->text() << endl;
    // la case à cocher "Packages Maths" est à la fin
    if(m_maths->isChecked())
    {
        flux << "true" << endl;
    }
    else
    {
        flux << "false" << endl;
    }

}
