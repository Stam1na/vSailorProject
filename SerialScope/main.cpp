﻿#include "mainwindow.h"
#include <QApplication>
const QString SerialScopeVersion = "Sailor";
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
  QFile file(":/qss/vQss/vQss.css");
//    QFile file(":/qss/vQss/vQss_black.css");
    if (file.open(QFile::ReadOnly))
    {
        QTextStream filetext(&file);
        QString stylesheet = filetext.readAll();
        qApp->setStyleSheet(stylesheet);
    }
    a.setWindowIcon(QIcon(":/image/image/favicon.ico"));
    w.setWindowTitle(SerialScopeVersion);
    w.show();
    return a.exec();
}
