#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QFrame>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QCheckBox>

class Fenetre : public QMainWindow
{
    Q_OBJECT
    
public:
    Fenetre();
    ~Fenetre();
    void traitementLigne(unsigned int, QString);

public slots:
    void setPremierePage(QString type);
     void disableHeader(bool checked);
     void enableHeader(bool checked);
     void disableFooter(bool checked);
     void enableFooter(bool checked);
     void emplacementFichier();
     void generer();
     void changerTitre(QString titre);
     void chargerPreconf();
     void sauverPreconf();

private:
    QLineEdit *m_nomFichier;
    QLineEdit *m_titre;
    QLineEdit *m_auteur;
    QLineEdit *m_date;
    QLineEdit *m_lHead;
    QLineEdit *m_cHead;
    QLineEdit *m_rHead;
    QLineEdit *m_lFoot;
    QLineEdit *m_cFoot;
    QLineEdit *m_rFoot;
    QLineEdit *m_file;

    QSpinBox *m_police;

    QCheckBox *m_maths;

    QComboBox *m_type;
    QComboBox *m_papier;
    QComboBox *m_encodage;

    QPushButton *m_parcourir;
    QPushButton *m_generer;

    QGroupBox *m_header;
    QGroupBox *m_footer;

    QRadioButton *m_ouiH;
    QRadioButton *m_nonH;
    QRadioButton *m_ouiF;
    QRadioButton *m_nonF;

    QVBoxLayout *m_mainLayout;
    QVBoxLayout *m_layoutGlobal_header;
    QVBoxLayout *m_layoutGlobal_footer;

    QHBoxLayout *m_groupeHeader;
    QHBoxLayout *m_groupeFooter;
    QHBoxLayout *m_layoutFile;

    QFormLayout *m_layout_nomFichier;
    QFormLayout *m_layout_infosBase;
    QFormLayout *m_layout_premierePage;
    QFormLayout *m_layoutHeader;
    QFormLayout *m_layoutFooter;

    QLabel *m_empl;

};

#endif // FENETRE_H
