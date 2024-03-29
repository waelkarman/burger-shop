#include <iostream>
#include "burger.hpp"
#include "shop.hpp"
#include "cart.hpp"
#include "KoDInput.hpp"

#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQuickView>
#include <QDebug>
#include <QQmlContext>

using namespace std;

int main(int argv, char** args){

    Burger m_burger_a("Burger","Hot Dog",23,"./media/a1.jpg", "descrizione");
    Burger m_burger_b("Burger","Chicken Burger",12,"./media/a2.jpg", "descrizione");
    Burger m_burger_c("Burger","Cheeseburger",18,"./media/a3.jpg", "descrizione");
    Burger m_burger_d("Burger","Chicken Little",16,"./media/a4.jpg", "descrizione");
    Burger m_burger_e("Burger","Vegan Burger",8,"./media/a5.jpg", "");
    Burger m_burger_f("Burger","Quentin Tarallino",10,"./media/a6.jpg", "descrizione");
    Burger m_burger_g("Burger","Central Park",11,"./media/a7.jpg", "descrizione");
    Burger m_burger_h("Burger","Santana Burger",12,"./media/a8.jpg", "descrizione");
    Burger m_burger_i("Burger","Beyonce Burger",14,"./media/a9.jpg", "descrizione");
    Burger m_burger_l("Burger","Algo Burger",12,"./media/a10.jpg", "descrizione");
    Burger m_burger_m("Burger","Safari Burger",11,"./media/a11.jpg", "descrizione");
    Burger m_burger_n("Burger","Latin Burger",17,"./media/a12.jpg", "descrizione");

    Shop m_shop;
    m_shop.insertBurger(m_burger_a);
    m_shop.insertBurger(m_burger_b);
    m_shop.insertBurger(m_burger_c);
    m_shop.insertBurger(m_burger_d);
    m_shop.insertBurger(m_burger_e);
    m_shop.insertBurger(m_burger_f);
    m_shop.insertBurger(m_burger_g);
    m_shop.insertBurger(m_burger_h);
    m_shop.insertBurger(m_burger_i);
    m_shop.insertBurger(m_burger_l);
    m_shop.insertBurger(m_burger_m);
    m_shop.insertBurger(m_burger_n);

    Cart m_cart;

    QueryResult result = m_shop.countAllBurgers();
    KoDInput m_kod(stoi(result.records[0].columns[0])-1);

    QCoreApplication::setApplicationName("Data Modul Shop");
    QGuiApplication app(argv, args);
    QQuickView view;
    view.connect(view.engine(), &QQmlEngine::quit, &app, &QCoreApplication::quit);
    view.rootContext()->setContextProperty("m_shop", &m_shop);
    view.rootContext()->setContextProperty("m_cart", &m_cart);
    view.rootContext()->setContextProperty("m_kod", &m_kod);
    //qmlRegisterType<Cart>("cart", 1, 0, "Cart");
    view.setSource(QUrl("qrc:/qml/main.qml"));
    
    if (view.status() == QQuickView::Error)
        return -1;

    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}






