#include "Coinflip.h"
#include <qboxlayout.h>
#include <time.h>

void Coinflip::initGui() {
	QVBoxLayout* ly = new QVBoxLayout;
	setLayout(ly);
	ly->addWidget(faceCoin);
	ly->addWidget(flipAnim);
	ly->addWidget(flipBtn);
	ly->addWidget(info);
}

void Coinflip::connectSignals() {
	QObject::connect(flipBtn, &QPushButton::clicked, this, [=]() {
		info->setText("");
		flipGif->start();
		faceCoin->hide();
		flipAnim->show();
		delay();
		flipAnim->hide();
		faceCoin->show();
		flipGif->stop();

		srand(time(NULL));
		auto num = rand() % 2 + 1;
		if (num == 1) {
			faceCoin->setPixmap(QPixmap{ "resources/heads.png" });
			info->setText("heads");
		}
		else {
			faceCoin->setPixmap(QPixmap{ "resources/tails.png" });
			info->setText("tails");
		}
		});
}

void Coinflip::delay() {
	QTime waitAnim = QTime::currentTime().addSecs(2);
	while (QTime::currentTime() < waitAnim) {
		QCoreApplication::processEvents(QEventLoop::AllEvents,100);
	}
}

void Coinflip::setInitialState() {
	info->setDisabled(true);
	flipAnim->setMovie(flipGif);
	flipAnim->hide();
	faceCoin->hide();
	//faceCoin->setStyleSheet("QLabel{ display: block; margin: auto; }");
	QSize size{ 300,300 };
	flipGif->setScaledSize(size);
}