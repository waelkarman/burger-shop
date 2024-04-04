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

    Burger m_burger_a("Burger","easyTOUCH StarterKit",23,"./media/b1.png", "descrizione");
    Burger m_burger_b("Burger","Kombi Monitore",12,"./media/b2.png", "descrizione");
    Burger m_burger_c("Burger","TFT Samsung 55.0 inch",18,"./media/b3.png", "descrizione");
    Burger m_burger_d("Burger","TFT AUO 18",16,"./media/b4.png", "descrizione");
    Burger m_burger_e("Burger","Touch Komposing",8,"./media/b5.png", "");
    //Burger m_burger_f("Burger","teaser-easyanalyzer",10,"./media/b6.jpg", "descrizione");
    Burger m_burger_g("Burger","TFT Tianma p series",11,"./media/b7.png", "descrizione");
    Burger m_burger_h("Burger","Kundenterminal",12,"./media/b8.png", "descrizione");
    Burger m_burger_i("Burger","eMotion NT1-3",14,"./media/b9.png", "descrizione");
    Burger m_burger_l("Burger","eMotion NT2-3",12,"./media/b10.png", "descrizione");
    Burger m_burger_m("Burger","emotion USB",11,"./media/b11.png", "descrizione");
    Burger m_burger_n("Burger","eMotionUHD II",17,"./media/b12.png", "descrizione");
    Burger m_burger_o("Burger","TFT Ortustech 5.0 inch",17,"./media/b13.png", "descrizione");
    Burger m_burger_p("Burger","PanelPc 13.1 inch",17,"./media/b14.png", "descrizione");
    Burger m_burger_q("Burger","SITO 10.6 inch",17,"./media/b15.png", "descrizione");
    Burger m_burger_r("Burger","Metal Mesh 13.3",17,"./media/b16.png", "descrizione");

    Shop m_shop;
    m_shop.insertBurger(m_burger_a);
    m_shop.insertBurger(m_burger_b);
    m_shop.insertBurger(m_burger_c);
    m_shop.insertBurger(m_burger_d);
    m_shop.insertBurger(m_burger_e);
    //m_shop.insertBurger(m_burger_f);
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






