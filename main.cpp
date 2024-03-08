
#include "burger.hpp"
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
    Burger m_burger_a;
    Burger m_burger_b;
    Burger m_burger_c;
    Burger m_burger_d;
    Burger m_burger_e;
    Burger m_burger_f;
    Burger m_burger_g;
    Burger m_burger_h;
    Burger m_burger_i;


    m_burger_a.setIsdn("987255324");
    m_burger_a.setTitle("Hot Dog");
    m_burger_a.setPrice(55);
    m_burger_a.setBackground("./media/a1.jpg");

    m_burger_b.setIsdn("982355324");
    m_burger_b.setTitle("Chicken Burger");
    m_burger_b.setPrice(23);
    m_burger_b.setBackground("./media/a2.jpg");

    m_burger_c.setIsdn("987267524");
    m_burger_c.setTitle("Cheeseburger");
    m_burger_c.setPrice(15);
    m_burger_c.setBackground("./media/a3.jpg");

    m_burger_d.setIsdn("987877524");
    m_burger_d.setTitle("Chicken Little");
    m_burger_d.setPrice(14);
    m_burger_d.setBackground("./media/a4.jpg");

    m_burger_e.setIsdn("987254324");
    m_burger_e.setTitle("Vegan Burger");
    m_burger_e.setPrice(5);
    m_burger_e.setBackground("./media/a5.jpg");

    m_burger_f.setIsdn("923267524");
    m_burger_f.setTitle("Quentin Tarallino");
    m_burger_f.setPrice(45);
    m_burger_f.setBackground("./media/a6.jpg");

    m_burger_g.setIsdn("987276473");
    m_burger_g.setTitle("Central Park");
    m_burger_g.setPrice(95);
    m_burger_g.setBackground("./media/a7.jpg");

    m_burger_h.setIsdn("987287654");
    m_burger_h.setTitle("Santana Burger");
    m_burger_h.setPrice(2);
    m_burger_h.setBackground("./media/a8.jpg");

    m_burger_i.setIsdn("341267524");
    m_burger_i.setTitle("Beyonce Burger");
    m_burger_i.setPrice(8);
    m_burger_i.setBackground("./media/a9.jpg");


    Shop m_shop;
    m_shop.insertBurger(m_burger_a);
    m_shop.insertBurger(m_burger_a);
    m_shop.insertBurger(m_burger_a);
    m_shop.fetchAllBurgers();
    cout << "---------------" << endl;
    m_shop.removeBurger(m_burger_a);
    m_shop.removeBurger(m_burger_a);
    m_shop.fetchAllBurgers();
    m_shop.insertBurger(m_burger_a);
    m_shop.insertBurger(m_burger_b);
    m_shop.insertBurger(m_burger_c);
    m_shop.insertBurger(m_burger_d);
    m_shop.insertBurger(m_burger_e);
    m_shop.insertBurger(m_burger_e);
    m_shop.insertBurger(m_burger_e);
    m_shop.insertBurger(m_burger_f);
    m_shop.insertBurger(m_burger_g);
    m_shop.insertBurger(m_burger_h);
    m_shop.insertBurger(m_burger_i);

    m_shop.fetchAllBurgers();
    m_shop.countAllBurgers();
    m_shop.fetchById(2);








    QCoreApplication::setApplicationName("Burger Shop");

    QGuiApplication app(argv, args);

    QQuickView view;
    view.connect(view.engine(), &QQmlEngine::quit, &app, &QCoreApplication::quit);

    view.rootContext()->setContextProperty("m_shop", &m_shop);

    view.setSource(QUrl("qrc:/qml/main.qml"));

    if (view.status() == QQuickView::Error)
        return -1;

    //view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}
