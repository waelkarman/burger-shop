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

    Burger m_burger_a("Burger","easyTOUCH-StarterKit_mXT2942TD-board",23,"./media/b1.png", "descrizione");
    Burger m_burger_b("Burger","kombi-monitore",12,"./media/b2.png", "descrizione");
    Burger m_burger_c("Burger","monitor_Samsung_OH55A",18,"./media/b3.png", "descrizione");
    Burger m_burger_d("Burger","TFT_18.5in_wide_right",16,"./media/b4.png", "descrizione");
    Burger m_burger_e("Burger","Touch_Komposing",8,"./media/b5.png", "");
    //Burger m_burger_f("Burger","teaser-easyanalyzer",10,"./media/b6.jpg", "descrizione");
    Burger m_burger_g("Burger","TFT_tianma-p-series",11,"./media/b7.png", "descrizione");
    Burger m_burger_h("Burger","Kundenterminal-Icons_VB_081020_001 ohne schatten",12,"./media/b8.png", "descrizione");
    Burger m_burger_i("Burger","eMotion NT1-3_persp",14,"./media/b9.png", "descrizione");
    Burger m_burger_l("Burger","eMotion NT2-3_persp",12,"./media/b10.png", "descrizione");
    Burger m_burger_m("Burger","emotion_USB_persp1_high",11,"./media/b11.png", "descrizione");
    Burger m_burger_n("Burger","LCDBoard_DATA-MODUL_eMotionUHD-II_1805_persp2",17,"./media/b12.png", "descrizione");
    Burger m_burger_o("Burger","ortustech_5-0in_12025084_COM50H5N01ULC_2402",17,"./media/b13.png", "descrizione");
    Burger m_burger_p("Burger","panelpc_DATA-MODUL_EP101WAD131-1-PCAP-U-DM",17,"./media/b14.png", "descrizione");
    Burger m_burger_q("Burger","SITO_10_6_pers_high",17,"./media/b15.png", "descrizione");
    Burger m_burger_r("Burger","touch_Metal Mesh",17,"./media/b16.png", "descrizione");

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






