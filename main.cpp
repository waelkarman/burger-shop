
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
    Burger m_burger_a("987","Hot Dog",23,"./media/a1.jpg");
    Burger m_burger_b("678","Chicken Burger",12,"./media/a2.jpg");
    Burger m_burger_c("846","Cheeseburger",18,"./media/a3.jpg");
    Burger m_burger_d("264","Chicken Little",16,"./media/a4.jpg");
    Burger m_burger_e("864","Vegan Burger",8,"./media/a5.jpg");
    Burger m_burger_f("236","Quentin Tarallino",10,"./media/a6.jpg");
    Burger m_burger_g("123","Central Park",11,"./media/a7.jpg");
    Burger m_burger_h("421","Santana Burger",12,"./media/a8.jpg");
    Burger m_burger_i("321","Beyonce Burger",14,"./media/a9.jpg");
    Burger m_burger_l("784","Algo Burger",12,"./media/a10.jpg");
    Burger m_burger_m("946","Safari Burger",11,"./media/a11.jpg");


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
    m_shop.insertBurger(m_burger_l);
    m_shop.insertBurger(m_burger_m);

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

    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}
