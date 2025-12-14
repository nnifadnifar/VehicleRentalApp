#include "views/mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ========== QSTYLEFACTORY IMPLEMENTATION ==========
    // Set modern application style
    // Available styles: "Fusion", "Windows", "WindowsVista", "Macintosh"
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    // Set modern color palette (Dark/Light theme)
    QPalette darkPalette;

    // ===== OPTION 1: Dark Theme (Modern) =====
    /*
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    QApplication::setPalette(darkPalette);
    */

    // ===== OPTION 2: Light Theme (Clean) ===== (ACTIVE)
    QPalette lightPalette;
    lightPalette.setColor(QPalette::Window, QColor(240, 240, 240));
    lightPalette.setColor(QPalette::WindowText, Qt::black);
    lightPalette.setColor(QPalette::Base, Qt::white);
    lightPalette.setColor(QPalette::AlternateBase, QColor(245, 245, 245));
    lightPalette.setColor(QPalette::ToolTipBase, Qt::white);
    lightPalette.setColor(QPalette::ToolTipText, Qt::black);
    lightPalette.setColor(QPalette::Text, Qt::black);
    lightPalette.setColor(QPalette::Button, QColor(240, 240, 240));
    lightPalette.setColor(QPalette::ButtonText, Qt::black);
    lightPalette.setColor(QPalette::Link, QColor(33, 150, 243));
    lightPalette.setColor(QPalette::Highlight, QColor(33, 150, 243));
    lightPalette.setColor(QPalette::HighlightedText, Qt::white);
    QApplication::setPalette(lightPalette);


    // Set application info
    QApplication::setApplicationName("Vehicle Rental System");
    QApplication::setApplicationVersion("1.0");
    QApplication::setOrganizationName("TransGo");

    MainWindow w;
    w.show();
    return a.exec();
}


