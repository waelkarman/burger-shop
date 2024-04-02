import QtQuick
import QtQuick.Controls

Item{
    width: 1920
    height: 1080

    Image {
        id: background
        anchors.fill: parent
        source: "./media/background.png"
        opacity: 0.4
    }

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

