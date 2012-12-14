#include <QtGui>

class SimGui : public QMainWindow
{
	Q_OBJECT

	public:
		SimGui();
		void setHash(const char *text);
		void setDeck(const char *text);
		
	protected:
		//void closeEvent(QCloseEvent *event);

	private slots:
		void lHashClicked(bool checked);
		void lDeckClicked(bool checked);
		void lCardClicked(bool checked);
		void rHashClicked(bool checked);
		void rDeckClicked(bool checked);
		void rCardClicked(bool checked);
		void simStart();

	private:
		QString		*version;
		QWidget		*window;
		QVBoxLayout	*mainLayout;
		QGroupBox		*resultsBox;
		QGroupBox		*optionsBox;
		QGroupBox		*decksBox;
		QLabel		*deck;
		QLabel		*deckHash;
		QLabel		*progress;
		
		QVBoxLayout *lDeck;
		QVBoxLayout *rDeck;

		QWidget *lHashBox;
		QWidget *rHashBox;
		QWidget *lDeckBox;
		QWidget *rDeckBox;
		QWidget *lCardBox;
		QWidget *rCardBox;
		
		QCheckBox *s;
		QCheckBox *a;
		QCheckBox *c;
		QCheckBox *o;
		QCheckBox *q;
		QCheckBox *r;
};

