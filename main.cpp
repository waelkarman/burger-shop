
#include "book.hpp"
#include "shop.hpp"
#include "dbhelper.hpp"

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
    Book m_book_d;
    Book m_book_e;
    Book m_book_f;
    Book m_book_g;
    Book m_book_h;
    Book m_book_i;


    m_book_a.setIsdn("987255324");
    m_book_a.setTitle("Il piccolo principe.");
    m_book_a.setPrice(55);


    // TEST DBHELPER
    // Dbhelper db;
    // QueryResult vp;
    // db.dropTable(vp);

    // try {
    //     db.createDatabase(vp);
    // } catch (exception& e) {
    //     cout << e.what() << endl;
    // }

    // cout << "-------------------------insert" << endl;
    // db.insertBook(m_book_a,vp);
    // db.insertBook(m_book_a,vp);
    // cout << "-------------------------fetch" << endl;
    // QueryResult result;
    // db.fetchAllBooks(result);
    // for (const auto& record : result.records) {
    //     for (const auto& column : record.columns) {
    //         printf("%s ", column.c_str());
    //     }
    //     printf("\n");
    // }


    Shop m_shop;
    m_shop.insertBook(m_book_a);
    m_shop.insertBook(m_book_a);
    m_shop.insertBook(m_book_a);
    m_shop.fetchAllBooks();
    cout << "---------------" << endl;
    m_shop.removeBook(m_book_a);
    m_shop.removeBook(m_book_a);
    m_shop.fetchAllBooks();
    //m_shop.insertBook(m_book_a);
    //m_shop.fetchAllBooks();




    // m_book_b.setIsdn("982355324");
    // m_book_b.setTitle("La guerra di piero.");
    // m_book_b.setPrice(23);

    // m_book_c.setIsdn("987267524");
    // m_book_c.setTitle("Le mille e una notte.");
    // m_book_c.setPrice(15);

    // m_book_d.setIsdn("987877524");
    // m_book_d.setTitle("ewtr ytuetu");
    // m_book_d.setPrice(15);

    // m_book_e.setIsdn("987254324");
    // m_book_e.setTitle("qerwrt wreya notte.");
    // m_book_e.setPrice(15);

    // m_book_f.setIsdn("923267524");
    // m_book_f.setTitle("Lq yqeyqrey.");
    // m_book_f.setPrice(15);

    // m_book_g.setIsdn("987276473");
    // m_book_g.setTitle("Leqr tqotte.");
    // m_book_g.setPrice(15);

    // m_book_h.setIsdn("987287654");
    // m_book_h.setTitle("Le wetetwe.");
    // m_book_h.setPrice(15);

    // m_book_i.setIsdn("341267524");
    // m_book_i.setTitle("wrwe twtewte.");
    // m_book_i.setPrice(15);

    // Test Shop and Dbhelper class
    //Shop m_shop;
    //m_shop.insertISDN(m_book_a);
    //m_shop.insertISDN(m_book_b);

    //m_shop.countAll();
    //m_shop.fetchAll();

    // m_shop.insertISDN(m_book_a);
    // m_shop.fetchAll();
    // m_shop.insertISDN(m_book_b);
    // m_shop.fetchAll();
    // m_shop.insertISDN(m_book_c);
    // m_shop.fetchAll();
    // m_shop.insertISDN(m_book_d);
    // m_shop.insertISDN(m_book_e);
    // m_shop.insertISDN(m_book_f);
    // m_shop.insertISDN(m_book_g);
    // m_shop.insertISDN(m_book_h);
    // m_shop.insertISDN(m_book_i);


    // m_shop.fetchAll();
    // m_shop.countAll();
    // m_shop.fetchNum(2);


    // QCoreApplication::setApplicationName("Library");

    // QGuiApplication app(argv, args);

    // QQuickView view;
    // view.connect(view.engine(), &QQmlEngine::quit, &app, &QCoreApplication::quit);

    // view.rootContext()->setContextProperty("m_shop", &m_shop);

    // view.setSource(QUrl("qrc:/main.qml"));

    // if (view.status() == QQuickView::Error)
    //     return -1;

    // //view.setResizeMode(QQuickView::SizeRootObjectToView);
    // view.show();

    // return app.exec();
}
