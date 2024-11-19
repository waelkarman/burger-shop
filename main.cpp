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

    Burger m_burger_a("Burger","Hot Dog",23,"./media/burger.png", "descrizione");
    Burger m_burger_b("Burger","Chicken Burger",12,"./media/burger.png", "descrizione");
    Burger m_burger_c("Burger","Cheeseburger",18,"./media/burger.png", "descrizione");
    Burger m_burger_d("Burger","Chicken Little",16,"./media/burger.png", "descrizione");
    Burger m_burger_e("Burger","Vegan Burger",8,"./media/burger.png", "");
    Burger m_burger_g("Burger","Quentin Tarallino",11,"./media/burger.png", "descrizione");
    Burger m_burger_h("Burger","Central Park",12,"./media/burger.png", "descrizione");
    Burger m_burger_i("Burger","Santana Burger",14,"./media/burger.png", "descrizione");
    Burger m_burger_l("Burger","Beyonce Burger",12,"./media/burger.png", "descrizione");
    Burger m_burger_m("Burger","Algo Burger",11,"./media/burger.png", "descrizione");
    Burger m_burger_n("Burger","Safari Burger",17,"./media/burger.png", "descrizione");
    Burger m_burger_o("Burger","Bunny Burger",17,"./media/burger.png", "descrizione");
    Burger m_burger_p("Burger","Jack Nicolson",17,"./media/burger.png", "descrizione");
    Burger m_burger_q("Burger","Double fishburger",17,"./media/burger.png", "descrizione");
    Burger m_burger_r("Burger","Burger BBQ",17,"./media/burger.png", "descrizione");

    Shop m_shop;
    m_shop.insertBurger(m_burger_a);
    m_shop.insertBurger(m_burger_b);
    m_shop.insertBurger(m_burger_c);
    m_shop.insertBurger(m_burger_d);
    m_shop.insertBurger(m_burger_e);
    m_shop.insertBurger(m_burger_g);
    m_shop.insertBurger(m_burger_h);
    m_shop.insertBurger(m_burger_i);
    m_shop.insertBurger(m_burger_l);
    m_shop.insertBurger(m_burger_m);
    m_shop.insertBurger(m_burger_n);
    m_shop.insertBurger(m_burger_o);
    m_shop.insertBurger(m_burger_p);
    m_shop.insertBurger(m_burger_q);
    m_shop.insertBurger(m_burger_r);

    Cart m_cart;

    QueryResult result = m_shop.countAllBurgers();
    KoDInput m_kod(stoi(result.records[0].columns[0])-1);

    QCoreApplication::setApplicationName("Burger Shop");
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






