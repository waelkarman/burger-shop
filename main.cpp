
#include "book.hpp"
#include "shop.hpp"

#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQuickView>
#include <QDebug>
#include <QQmlContext>


using namespace std;

int main(int argv, char** args){

    // Test Book class
    Book m_book_a;
    Book m_book_b;
    Book m_book_c;
    m_book_a.setIsdn("987255324");
    m_book_a.setTitle("Il piccolo principe.");
    m_book_a.setPrice(55);

    m_book_b.setIsdn("982355324");
    m_book_b.setTitle("La guerra di piero.");
    m_book_b.setPrice(23);

    m_book_c.setIsdn("987267524");
    m_book_c.setTitle("Le mille e una notte.");
    m_book_c.setPrice(15);

    // Test Shop and Dbhelper class
    Shop m_shop;
    m_shop.insertISDN(m_book_a);
    m_shop.insertISDN(m_book_a);
    m_shop.insertISDN(m_book_a);
    m_shop.fetchAll();
    m_shop.insertISDN(m_book_b);
    m_shop.fetchAll();
    m_shop.insertISDN(m_book_c);
    m_shop.fetchAll();

    m_shop.removeISDN("982355324");
    m_shop.removeISDN("987267524");
    m_shop.fetchAll();



    QCoreApplication::setApplicationName("Library");

    QGuiApplication app(argv, args);

    QQuickView view;
    view.connect(view.engine(), &QQmlEngine::quit, &app, &QCoreApplication::quit);

    view.rootContext()->setContextProperty("m_shop", &m_shop);

    view.setSource(QUrl("qrc:/main.qml"));

    if (view.status() == QQuickView::Error)
        return -1;

    //view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}
