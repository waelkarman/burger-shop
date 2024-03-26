import QtQuick
import QtQuick.Controls

Item{
    width: 1920
    height: 1080

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

