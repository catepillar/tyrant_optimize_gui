#define VERSION "0.0.1"

#include "simgui.h"

SimGui::SimGui()
{
	version = new QString(VERSION);

	window = new QWidget;
	
	mainLayout = new QVBoxLayout;

	
	resultsBox = new QGroupBox(tr("Results"));
	QVBoxLayout *resultsVBox = new QVBoxLayout;
	QGridLayout *results = new QGridLayout;
	QLabel *deckLabel = new QLabel(tr("Deck: "));
	deck = new QLabel;
	deck->setText(tr("Please simulate a deck first!"));
	QLabel *deckHashLabel = new QLabel(tr("Deck Hash: "));
	deck->setTextInteractionFlags(Qt::TextSelectableByMouse);
	deckHash = new QLabel;
	deckHash->setTextInteractionFlags(Qt::TextSelectableByMouse);
	progress = new QLabel;
	results->addWidget(deckLabel,0,0);
	results->addWidget(deck,0,1);
	results->addWidget(deckHashLabel,1,0);
	results->addWidget(deckHash,1,1);
	resultsVBox->addLayout(results);
	resultsVBox->addWidget(progress);
	resultsBox->setLayout(resultsVBox);
	resultsBox->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Maximum);

	optionsBox = new QGroupBox(tr("Options"));
	QGridLayout *options = new QGridLayout;
	s = new QCheckBox(tr("&Surge"));
	a = new QCheckBox(tr("&Average Net"));
	c = new QCheckBox(tr("Ignore &Commander"));
	o = new QCheckBox(tr("Use &Owned Cards"));
	q = new QCheckBox(tr("&Quest Mode"));
	r = new QCheckBox(tr("O&rdered"));
	options->addWidget(s,0,0);
	options->addWidget(a,0,1);
	options->addWidget(c,0,2);
	options->addWidget(o,1,0);
	options->addWidget(q,1,1);
	options->addWidget(r,1,2);
	optionsBox->setLayout(options);
	optionsBox->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Maximum);

	QPushButton *simButton = new QPushButton("  Start  ");
	simButton->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
	connect(simButton, SIGNAL(clicked()),this,SLOT(simStart()));

	decksBox = new QGroupBox(tr("Decks"));
	QGridLayout *decks = new QGridLayout;
	QFrame *lFrame = new QFrame;
	lFrame->setMidLineWidth(2);
	lFrame->setLineWidth(3);
	lFrame->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);

	QFrame *rFrame = new QFrame;
	rFrame->setLineWidth(3);
	rFrame->setMidLineWidth(2);
	rFrame->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);

	lDeck = new QVBoxLayout;
	rDeck = new QVBoxLayout;

	QLabel *left = new QLabel(tr("Changing Deck"));
	QRadioButton *lHash = new QRadioButton(tr("By &Hash"));
	connect(lHash, SIGNAL(clicked(bool)),this,SLOT(lHashClicked(bool)));
	QRadioButton *lDeckName = new QRadioButton(tr("By &Deck Name"));
	connect(lDeckName, SIGNAL(clicked(bool)),this,SLOT(lDeckClicked(bool)));
	QRadioButton *lCards = new QRadioButton(tr("By Card &List"));
	connect(lCards, SIGNAL(clicked(bool)),this,SLOT(lCardClicked(bool)));
	lDeck->addWidget(left);
	QGridLayout *lButtons = new QGridLayout;
	lButtons->addWidget(lHash, 0,0);
	lButtons->addWidget(lDeckName, 0,1);
	lButtons->addWidget(lCards, 0,2);
	lDeck->addLayout(lButtons);

	lHashBox = new QWidget;
	QGridLayout *lHashLayout = new QGridLayout;
	QLabel *lHashLabel = new QLabel(tr("Deck Hash"));
	QLineEdit *lHashText = new QLineEdit;
	lHashLayout->addWidget(lHashLabel,0,0);
	lHashLayout->addWidget(lHashText,0,1);
	lHashBox->setLayout(lHashLayout);
	lDeck->addWidget(lHashBox);

	lDeckBox = new QWidget;
	QGridLayout *lNameLayout = new QGridLayout;
	QLabel *lNameLabel = new QLabel(tr("Deck Name"));
	QLineEdit *lDeckNameText = new QLineEdit;
	lNameLayout->addWidget(lNameLabel,0,0);
	lNameLayout->addWidget(lDeckNameText,0,1);
	lDeckBox->setLayout(lNameLayout);
	lDeck->addWidget(lDeckBox);
	lDeckBox->hide();

	lCardBox = new QWidget;
	QGridLayout *lCardLayout = new QGridLayout;
	QLabel *lCardLabel = new QLabel(tr("Cards"));
	QLabel *lCardCommander = new QLabel(tr("Commander"));
	QLabel *lCardC1 = new QLabel(tr("Card 1"));
	QLabel *lCardC2 = new QLabel(tr("Card 2"));
	QLabel *lCardC3 = new QLabel(tr("Card 3"));
	QLabel *lCardC4 = new QLabel(tr("Card 4"));
	QLabel *lCardC5 = new QLabel(tr("Card 5"));
	QLabel *lCardC6 = new QLabel(tr("Card 6"));
	QLabel *lCardC7 = new QLabel(tr("Card 7"));
	QLabel *lCardC8 = new QLabel(tr("Card 8"));
	QLabel *lCardC9 = new QLabel(tr("Card 9"));
	QLabel *lCardC10 = new QLabel(tr("Card 10"));
	QLineEdit *lCardComText = new QLineEdit;
	QLineEdit *lCardC1Text = new QLineEdit;
	QLineEdit *lCardC2Text = new QLineEdit;
	QLineEdit *lCardC3Text = new QLineEdit;
	QLineEdit *lCardC4Text = new QLineEdit;
	QLineEdit *lCardC5Text = new QLineEdit;
	QLineEdit *lCardC6Text = new QLineEdit;
	QLineEdit *lCardC7Text = new QLineEdit;
	QLineEdit *lCardC8Text = new QLineEdit;
	QLineEdit *lCardC9Text = new QLineEdit;
	QLineEdit *lCardC10Text = new QLineEdit;
	lCardLayout->addWidget(lCardLabel,0,0);
	lCardLayout->addWidget(lCardCommander,1,0);
	lCardLayout->addWidget(lCardC1,2,0);
	lCardLayout->addWidget(lCardC2,3,0);
	lCardLayout->addWidget(lCardC3,4,0);
	lCardLayout->addWidget(lCardC4,5,0);
	lCardLayout->addWidget(lCardC5,6,0);
	lCardLayout->addWidget(lCardC6,7,0);
	lCardLayout->addWidget(lCardC7,8,0);
	lCardLayout->addWidget(lCardC8,9,0);
	lCardLayout->addWidget(lCardC9,10,0);
	lCardLayout->addWidget(lCardC10,11,0);
	lCardLayout->addWidget(lCardComText,1,1);
	lCardLayout->addWidget(lCardC1Text,2,1);
	lCardLayout->addWidget(lCardC2Text,3,1);
	lCardLayout->addWidget(lCardC3Text,4,1);
	lCardLayout->addWidget(lCardC4Text,5,1);
	lCardLayout->addWidget(lCardC5Text,6,1);
	lCardLayout->addWidget(lCardC6Text,7,1);
	lCardLayout->addWidget(lCardC7Text,8,1);
	lCardLayout->addWidget(lCardC8Text,9,1);
	lCardLayout->addWidget(lCardC9Text,10,1);
	lCardLayout->addWidget(lCardC10Text,11,1);
	lCardBox->setLayout(lCardLayout);
	lDeck->addWidget(lCardBox);
	QSpacerItem *lSpacerItem = new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::MinimumExpanding);
	lDeck->addItem(lSpacerItem);
	lCardBox->hide();
	
	lFrame->setLayout(lDeck);
	decks->addWidget(lFrame,0,0);


	QLabel *right = new QLabel(tr("Fixed Deck"));
	QRadioButton *rHash = new QRadioButton(tr("By &Hash"));
	connect(rHash, SIGNAL(clicked(bool)),this,SLOT(rHashClicked(bool)));
	QRadioButton *rDeckName = new QRadioButton(tr("By &Deck Name"));
	connect(rDeckName, SIGNAL(clicked(bool)),this,SLOT(rDeckClicked(bool)));
	QRadioButton *rCards = new QRadioButton(tr("By Card &List"));
	connect(rCards, SIGNAL(clicked(bool)),this,SLOT(rCardClicked(bool)));
	rDeck->addWidget(right);
	QGridLayout *rButtons = new QGridLayout;
	rButtons->addWidget(rHash, 0,0);
	rButtons->addWidget(rDeckName, 0,1);
	rButtons->addWidget(rCards, 0,2);
	rDeck->addLayout(rButtons);

	rHashBox = new QWidget;
	QGridLayout *rHashLayout = new QGridLayout;
	QLabel *rHashLabel = new QLabel(tr("Deck Hash"));
	QLineEdit *rHashText = new QLineEdit;
	rHashLayout->addWidget(rHashLabel,0,0);
	rHashLayout->addWidget(rHashText,0,1);
	rHashBox->setLayout(rHashLayout);
	rDeck->addWidget(rHashBox);

	rDeckBox = new QWidget;
	QGridLayout *rNameLayout = new QGridLayout;
	QLabel *rNameLabel = new QLabel(tr("Deck Name"));
	QLineEdit *rDeckNameText = new QLineEdit;
	rNameLayout->addWidget(rNameLabel,0,0);
	rNameLayout->addWidget(rDeckNameText,0,1);
	rDeckBox->setLayout(rNameLayout);
	rDeck->addWidget(rDeckBox);
	rDeckBox->hide();

	rCardBox = new QWidget;
	QGridLayout *rCardLayout = new QGridLayout;
	QLabel *rCardLabel = new QLabel(tr("Cards"));
	QLabel *rCardCommander = new QLabel(tr("Commander"));
	QLabel *rCardC1 = new QLabel(tr("Card 1"));
	QLabel *rCardC2 = new QLabel(tr("Card 2"));
	QLabel *rCardC3 = new QLabel(tr("Card 3"));
	QLabel *rCardC4 = new QLabel(tr("Card 4"));
	QLabel *rCardC5 = new QLabel(tr("Card 5"));
	QLabel *rCardC6 = new QLabel(tr("Card 6"));
	QLabel *rCardC7 = new QLabel(tr("Card 7"));
	QLabel *rCardC8 = new QLabel(tr("Card 8"));
	QLabel *rCardC9 = new QLabel(tr("Card 9"));
	QLabel *rCardC10 = new QLabel(tr("Card 10"));
	QLabel *rCardC11 = new QLabel(tr("Card 11"));
	QLabel *rCardC12 = new QLabel(tr("Card 12"));
	QLabel *rCardC13 = new QLabel(tr("Card 13"));
	QLabel *rCardC14 = new QLabel(tr("Card 14"));
	QLabel *rCardC15 = new QLabel(tr("Card 15"));
	QLineEdit *rCardComText = new QLineEdit;
	QLineEdit *rCardC1Text = new QLineEdit;
	QLineEdit *rCardC2Text = new QLineEdit;
	QLineEdit *rCardC3Text = new QLineEdit;
	QLineEdit *rCardC4Text = new QLineEdit;
	QLineEdit *rCardC5Text = new QLineEdit;
	QLineEdit *rCardC6Text = new QLineEdit;
	QLineEdit *rCardC7Text = new QLineEdit;
	QLineEdit *rCardC8Text = new QLineEdit;
	QLineEdit *rCardC9Text = new QLineEdit;
	QLineEdit *rCardC10Text = new QLineEdit;
	QLineEdit *rCardC11Text = new QLineEdit;
	QLineEdit *rCardC12Text = new QLineEdit;
	QLineEdit *rCardC13Text = new QLineEdit;
	QLineEdit *rCardC14Text = new QLineEdit;
	QLineEdit *rCardC15Text = new QLineEdit;
	rCardLayout->addWidget(rCardLabel,0,0);
	rCardLayout->addWidget(rCardCommander,1,0);
	rCardLayout->addWidget(rCardC1,2,0);
	rCardLayout->addWidget(rCardC2,3,0);
	rCardLayout->addWidget(rCardC3,4,0);
	rCardLayout->addWidget(rCardC4,5,0);
	rCardLayout->addWidget(rCardC5,6,0);
	rCardLayout->addWidget(rCardC6,7,0);
	rCardLayout->addWidget(rCardC7,8,0);
	rCardLayout->addWidget(rCardC8,9,0);
	rCardLayout->addWidget(rCardC9,10,0);
	rCardLayout->addWidget(rCardC10,11,0);
	rCardLayout->addWidget(rCardC11,12,0);
	rCardLayout->addWidget(rCardC12,13,0);
	rCardLayout->addWidget(rCardC13,14,0);
	rCardLayout->addWidget(rCardC14,15,0);
	rCardLayout->addWidget(rCardC15,16,0);
	rCardLayout->addWidget(rCardComText,1,1);
	rCardLayout->addWidget(rCardC1Text,2,1);
	rCardLayout->addWidget(rCardC2Text,3,1);
	rCardLayout->addWidget(rCardC3Text,4,1);
	rCardLayout->addWidget(rCardC4Text,5,1);
	rCardLayout->addWidget(rCardC5Text,6,1);
	rCardLayout->addWidget(rCardC6Text,7,1);
	rCardLayout->addWidget(rCardC7Text,8,1);
	rCardLayout->addWidget(rCardC8Text,9,1);
	rCardLayout->addWidget(rCardC9Text,10,1);
	rCardLayout->addWidget(rCardC10Text,11,1);
	rCardLayout->addWidget(rCardC11Text,12,1);
	rCardLayout->addWidget(rCardC12Text,13,1);
	rCardLayout->addWidget(rCardC13Text,14,1);
	rCardLayout->addWidget(rCardC14Text,15,1);
	rCardLayout->addWidget(rCardC15Text,16,1);
	rCardBox->setLayout(rCardLayout);
	rDeck->addWidget(rCardBox);
	QSpacerItem *rSpacerItem = new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::MinimumExpanding);
	rDeck->addItem(rSpacerItem);
	rCardBox->hide();
	
	rFrame->setLayout(rDeck);
	decks->addWidget(rFrame,0,1);
	decksBox->setLayout(decks);

	mainLayout->addWidget(resultsBox);
	mainLayout->addWidget(optionsBox);
	mainLayout->addWidget(simButton,0,Qt::AlignHCenter);
	mainLayout->addWidget(decksBox);

	window->setLayout(mainLayout);
	
	setCentralWidget(window);

	setWindowTitle(tr("Tyrant Optimize ") + VERSION);
	resize(minimumWidth(),minimumHeight());
}

void SimGui::setHash(const char *text)
{
	deckHash->setText(text);
}

void SimGui::setDeck(const char *text)
{
	deckHash->setText(text);
}

void SimGui::lHashClicked(bool checked)
{
	if(checked)
	{
		lHashBox->show();
		lDeckBox->hide();
		lCardBox->hide();
	}
}
void SimGui::lDeckClicked(bool checked)
{
	if(checked)
	{
		lHashBox->hide();
		lDeckBox->show();
		lCardBox->hide();
	}
}
void SimGui::lCardClicked(bool checked)
{
	if(checked)
	{
		lHashBox->hide();
		lDeckBox->hide();
		lCardBox->show();
	}
}
void SimGui::rHashClicked(bool checked)
{
	if(checked)
	{
		rHashBox->show();
		rDeckBox->hide();
		rCardBox->hide();
	}
}
void SimGui::rDeckClicked(bool checked)
{
	if(checked)
	{
		rHashBox->hide();
		rDeckBox->show();
		rCardBox->hide();
	}
}
void SimGui::rCardClicked(bool checked)
{
	if(checked)
	{
		rHashBox->hide();
		rDeckBox->hide();
		rCardBox->show();
	}
}

void SimGui::simStart()
{
	QMessageBox::information(0, QString("Information"), QString("You've pressed the button \"Press Me!\""), QMessageBox::Ok);
}