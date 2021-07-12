#pragma once
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qmovie.h>
#include <qlineedit.h>

class Coinflip: public QWidget
{
private:
	QPushButton* flipBtn = new QPushButton{ "Flip coin" };
	QLabel* flipAnim = new QLabel;
	QMovie* flipGif = new QMovie{"resources/flip.gif"};
	QLabel* faceCoin = new QLabel;
	QLineEdit* info = new QLineEdit;

	// Function that initializes the GUI layout
	void initGui();

	// Function that connects the signals of GUI components
	void connectSignals();

	// Function that sets the initial state of the application
	void setInitialState();

	// Function that delays the execution for 2 seconds
	void delay();
public:
	Coinflip() {
		initGui();
		connectSignals();
		setInitialState();
	}
};

