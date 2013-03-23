/*
 * fenetre.cpp
 * Contient les instanciations du constructeur et du destructeur de la classe Fenetre
 * Le contructeur génère l'inteface graphique
 */

#include "fenetre.h"


Fenetre::Fenetre() : QMainWindow()
{
    setWindowTitle("baseTeX");
    setWindowIcon(QIcon(":/ressources/images/ico"));

    QWidget *zoneCentrale = new QWidget;

    //Instanciation des widgets
    m_nomFichier = new QLineEdit;
    m_titre = new QLineEdit;
    m_auteur = new QLineEdit;
    m_date = new QLineEdit;
    m_lHead = new QLineEdit;
    m_cHead = new QLineEdit;
    m_rHead = new QLineEdit;
    m_lFoot = new QLineEdit;
    m_cFoot = new QLineEdit;
    m_rFoot = new QLineEdit;
    m_file = new QLineEdit;

    m_police = new QSpinBox;
    m_police->suffix();
    m_police->setSuffix(" pt");

    m_maths = new QCheckBox("Inclure les packages mathématiques");

    m_type = new QComboBox;
    m_type->addItem("article");
    m_type->addItem("book");
    m_type->addItem("letter");
    m_type->addItem("report");

    m_papier = new QComboBox;
    m_papier->addItem("a4paper");

    m_encodage = new QComboBox;
    m_encodage->addItem("utf8x");
    m_encodage->addItem("latin1");

    m_parcourir = new QPushButton(QObject::tr("Parcourir..."));
    m_generer = new QPushButton(QObject::tr("Générer"));

    m_header = new QGroupBox(QObject::tr("En-tête"));
    m_footer = new QGroupBox(QObject::tr("Pied de page"));

    m_ouiH = new QRadioButton(QObject::tr("Oui"));
    m_ouiH->setChecked(true);
    m_ouiF = new QRadioButton(QObject::tr("Oui"));
    m_ouiF->setChecked(true);
    m_nonH = new QRadioButton(QObject::tr("Non"));
    m_nonF = new QRadioButton(QObject::tr("Non"));

    m_empl = new QLabel(QObject::tr("Emplacement du fichier"));

    //NOM DE FICHIER

    //on génère le form layout pour le nom de fichier
    m_layout_nomFichier = new QFormLayout;
    m_layout_nomFichier->addRow(tr("Nom du fichier"), m_nomFichier);

    //INFOS DE BASE

    //on génère le form layout pour les infos de base

    m_layout_infosBase = new QFormLayout;
    m_layout_infosBase->addRow(tr("Type de document"), m_type);
    m_layout_infosBase->addRow(tr("Taille de police"), m_police);
    m_layout_infosBase->addRow(tr("Encodage"), m_encodage);
    m_layout_infosBase->addRow(tr("Type de papier"), m_papier);
    m_layout_infosBase->addRow(tr(""), m_maths);

    //TITRE etc

    //on génère le form layout

    m_layout_premierePage = new QFormLayout;
    m_layout_premierePage->addRow(tr("Titre"), m_titre);
    m_layout_premierePage->addRow(tr("Auteur"), m_auteur);
    m_layout_premierePage->addRow(tr("Date"), m_date);


    //EN TETE

    //on génère le layout pour les radios (header)

    m_groupeHeader = new QHBoxLayout;
    m_groupeHeader->addWidget(m_ouiH);
    m_groupeHeader->addWidget(m_nonH);
    //on met le tout dans le groupbox
    m_header->setLayout(m_groupeHeader);



    //on fait ensuite le formlayout
    m_layoutHeader = new QFormLayout;
    m_layoutHeader->addRow(tr("Gauche"), m_lHead);
    m_layoutHeader->addRow(tr("Centre"), m_cHead);
    m_layoutHeader->addRow(tr("Droite"), m_rHead);


    //on regroupe le tout dans un QV layout
    m_layoutGlobal_header = new QVBoxLayout;
    m_layoutGlobal_header->addWidget(m_header);
    m_layoutGlobal_header->addLayout(m_layoutHeader);



    //PIED DE PAGE

    //génération du layout pour les radios (footer)
    m_groupeFooter = new QHBoxLayout;
    m_groupeFooter->addWidget(m_ouiF);
    m_groupeFooter->addWidget(m_nonF);
    //on met le tout dans le groupbox
    m_footer->setLayout(m_groupeFooter);

    //on fait ensuite le formlayout
    m_layoutFooter = new QFormLayout;
    m_layoutFooter->addRow(tr("Gauche"), m_lFoot);
    m_layoutFooter->addRow(tr("Centre"), m_cFoot);
    m_layoutFooter->addRow(tr("Droite"), m_rFoot);


    //on regroupe
    m_layoutGlobal_footer = new QVBoxLayout;
    m_layoutGlobal_footer->addWidget(m_footer);
    m_layoutGlobal_footer->addLayout(m_layoutFooter);


    //EMPLACEMENT FICHIER
    m_layoutFile = new QHBoxLayout;
    m_layoutFile->addWidget(m_empl);
    m_layoutFile->addWidget(m_file);
    m_layoutFile->addWidget(m_parcourir);


    //LAYOUT GLOBAL
    //on peut maitenant générer le layout global

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addLayout(m_layout_nomFichier);
    m_mainLayout->addLayout(m_layout_infosBase);
    m_mainLayout->addLayout(m_layout_premierePage);
    m_mainLayout->addLayout(m_layoutGlobal_header);
    m_mainLayout->addLayout(m_layoutGlobal_footer);
    m_mainLayout->addLayout(m_layoutFile);

    m_mainLayout->addWidget(m_generer);

    zoneCentrale->setLayout(m_mainLayout);


    //Initialisation de la vue
    m_police->setValue(10);
    m_police->setAccelerated(true);
    m_police->setMinimum(5);
    m_date->setText("\\today");
    m_titre->setEnabled(false);
    m_auteur->setEnabled(false);
    m_date->setEnabled(false);
    m_cFoot->setText("--\\thepage--");
    m_rFoot->setText("\\today");


    //Connexions

    QObject::connect(m_type, SIGNAL(currentTextChanged(QString)), this, SLOT(setPremierePage(QString)));

    //Gestion en-tete
    QObject::connect(m_nonH, SIGNAL(clicked(bool)), this, SLOT(disableHeader(bool)));
    QObject::connect(m_ouiH, SIGNAL(clicked(bool)), this, SLOT(enableHeader(bool)));

    //Gestion footer
    QObject::connect(m_nonF, SIGNAL(clicked(bool)), this, SLOT(disableFooter(bool)));
    QObject::connect(m_ouiF, SIGNAL(clicked(bool)), this, SLOT(enableFooter(bool)));

    QObject::connect(m_parcourir, SIGNAL(clicked()), this, SLOT(emplacementFichier()));

    QObject::connect(m_generer, SIGNAL(clicked()), this, SLOT(generer()));

    QObject::connect(m_nomFichier, SIGNAL(textChanged(QString)), this, SLOT(changerTitre(QString)));

    /*
     *MENUS
     */

    // On instancie la barre de menu, et on ajoute des actions
    QMenu *menuFichier = menuBar()->addMenu(tr("&Fichier"));
    QAction *actionCharger = new QAction(tr("&Charger la préconfiguration"), this);
    menuFichier->addAction(actionCharger);
    actionCharger->setShortcut(QKeySequence("Ctrl+O"));
    actionCharger->setIcon(QIcon(":/ressources/images/charger"));
    QAction *actionSauvegarder = new QAction(tr("&Sauvegarder la préconfiguration"), this);
    menuFichier->addAction(actionSauvegarder);
    actionSauvegarder->setShortcut(QKeySequence("Ctrl+S"));
    actionSauvegarder->setIcon(QIcon(":/ressources/images/sauvegarder"));
    QAction *actionQuitter = new QAction(tr("&Quitter"), this);
    menuFichier->addAction(actionQuitter);
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    actionQuitter->setIcon(QIcon(":/ressources/images/quitter"));

    QMenu *menuAPropos = menuBar()->addMenu(tr("&À propos"));
    QAction *actionAProposQt = new QAction(tr("&À propos de Qt"), this);
    menuAPropos->addAction(actionAProposQt);

    //Barre d'outils
    QToolBar *toolBar = addToolBar("Tool");
    toolBar->addAction(actionCharger);
    toolBar->addAction(actionSauvegarder);


    /*
     * Connexions des menus
     */
    QObject::connect(actionCharger, SIGNAL(triggered()), this, SLOT(chargerPreconf()));
    QObject::connect(actionSauvegarder, SIGNAL(triggered()), this, SLOT(sauverPreconf()));
    QObject::connect(actionAProposQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));


    setCentralWidget(zoneCentrale);
}


Fenetre::~Fenetre()
{
    //Qt fait automatiquement un free sur chacun des widgets
}
