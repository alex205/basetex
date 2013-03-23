/*
 * fenetreMethod.cpp
 * contient les méthodes de classe
 */

#include"fenetre.h"

//fonction (très basique ..) qui parse le fichier de préconf et lance les actions correspondantes
void Fenetre::traitementLigne(unsigned int i, QString ligne)
{
    switch(i)
    {

    case 1:
        m_type->setCurrentIndex(ligne.toInt());
        break;

    case 2:
        m_police->setValue(ligne.toInt());
        break;

    case 3:
        m_encodage->setCurrentIndex(ligne.toInt());
        break;

    case 4:
        m_papier->setCurrentIndex(ligne.toInt());
        break;

    case 5:
        m_titre->setText(ligne);
        break;

    case 6:
        m_auteur->setText(ligne);
        break;

    case 7:
        m_date->setText(ligne);
        break;

    case 8:
        if(ligne == "true")
        {
            m_ouiH->setChecked(true);
            m_nonH->setChecked(false);
            enableHeader(true);
        }
        else
        {
            m_ouiH->setChecked(false);
            m_nonH->setChecked(true);
            disableHeader(true);
        }
        break;

    case 9:
        m_lHead->setText(ligne);
        break;

    case 10:
        m_cHead->setText(ligne);
        break;

    case 11:
        m_rHead->setText(ligne);
        break;

    case 12:
        if(ligne == "true")
        {
            m_ouiF->setChecked(true);
            m_nonF->setChecked(false);
            enableFooter(true);
        }
        else
        {
            m_ouiF->setChecked(false);
            m_nonF->setChecked(true);
            disableFooter(true);
        }
        break;

    case 13:
        m_lFoot->setText(ligne);
        break;

    case 14:
        m_cFoot->setText(ligne);
        break;

    case 15:
        m_rFoot->setText(ligne);
        break;

    case 16:
        if(ligne == "true")
        {
            m_maths->setChecked(true);
        }
        else
        {
            m_maths->setChecked(false);
        }
        break;

    default:
        QMessageBox::critical(this, tr("Erreur"), tr("Une erreur s'est produite lors de la lecture du fichier de préconfiguration."));
        return;
    }
}
