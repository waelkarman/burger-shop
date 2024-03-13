import QtQuick
import QtQuick.Controls

Item{
    width: 800
    height: 600

    SwipeView {
        id: view

        anchors.fill: parent

        Burgerslistpage{
            id: firstPage
        }

        Shoppingcartpage {
            id: secondPage
        }

    }
}

