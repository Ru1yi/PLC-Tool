#include "Snap7Tool.h"

Snap7Tool::Snap7Tool(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	GlobalPlc = new PlcControl();
	GlobalPlc->PlcConnectInit();
}

Snap7Tool::~Snap7Tool()
{}

void Snap7Tool::on_pushButton_ReadInt_clicked()
{
	int readInt = -1;
	QString dbNumber;
	QString start;
	try {
		dbNumber = ui.lineEdit_ReadIntDBnumber->text();
		start = ui.lineEdit_ReadIntStart->text();

		readInt = GlobalPlc->DBRead_Int(dbNumber.toInt(), start.toInt());
	}
	catch (...) {
		QMessageBox::warning(this, "Read int failed", "Please try again!");
	}
	QString time = QTime::currentTime().toString("[hh:mm:ss]->");
	QString text = "Read int from DB[" + dbNumber + "] " + "start[" + start + "]: " + QString::number(readInt);

	ui.plainTextEdit->appendPlainText(time + text);
}

void Snap7Tool::on_pushButton_ReadString_clicked()
{
	std::string readString = "default";
	QString dbNumber;
	QString start;
	try {
		dbNumber = ui.lineEdit_ReadIntDBnumber->text();
		start = ui.lineEdit_ReadIntStart->text();

		readString = GlobalPlc->DBRead_String(dbNumber.toInt(), start.toInt());
	}
	catch (...) {
		QMessageBox::warning(this, "Read string failed", "Please try again!");
	}
	QString time = QTime::currentTime().toString("[hh:mm:ss]->");
	QString text = "Read string from DB[" + dbNumber + "] " + "start[" + start + "]: " + QString::fromStdString(readString);

	ui.plainTextEdit->appendPlainText(time + text);
}

void Snap7Tool::on_pushButton_WriteInt_clicked()
{
	int writeInt = -1;
	QString dbNumber;
	QString start;
	try {
		dbNumber = ui.lineEdit_ReadIntDBnumber->text();
		start = ui.lineEdit_ReadIntStart->text();
		writeInt = ui.lineEdit_WriteIntValue->text().toInt();

		GlobalPlc->DBWrite_Int(dbNumber.toInt(), start.toInt(), writeInt);
	}
	catch (...) {
		QMessageBox::warning(this, "Write int failed", "Please try again!");
	}
	QString time = QTime::currentTime().toString("[hh:mm:ss]->");
	QString text = "Write int to DB[" + dbNumber + "] " + "start[" + start + "]: " + QString::number(writeInt);

	ui.plainTextEdit->appendPlainText(time + text);
}

void Snap7Tool::on_pushButton_WriteString_clicked()
{
	QString writeString = "default";
	QString dbNumber;
	QString start;
	QString maxLength;
	try {
		dbNumber = ui.lineEdit_ReadIntDBnumber->text();
		start = ui.lineEdit_ReadIntStart->text();
		writeString = ui.lineEdit_WriteStringValue->text();
		maxLength = ui.lineEdit_MaxLength->text();

		GlobalPlc->DBWrite_String(dbNumber.toInt(), start.toInt(), writeString.toStdString(), maxLength.toInt());
	}
	catch (...) {
		QMessageBox::warning(this, "Write string failed", "Please try again!");
	}
	QString time = QTime::currentTime().toString("[hh:mm:ss]->");
	QString text = "Write string to DB[" + dbNumber + "] " + "start[" + start + "]: " + writeString;

	ui.plainTextEdit->appendPlainText(time + text);
}